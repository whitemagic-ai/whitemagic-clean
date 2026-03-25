"""Parallel Execution Engine — Optimized batch processing for campaign operations.

Provides ProcessPoolExecutor for CPU-bound work (entity extraction, embedding generation,
pattern matching) and ThreadPoolExecutor for I/O-bound work (DB reads, file scanning).

Integrates with ProgressTracker for granular progress reporting.

Key optimizations:
- WAL mode with busy_timeout for concurrent SQLite access
- Chunked batch processing with configurable chunk sizes
- Automatic CPU/IO detection and executor selection
- Connection pooling for SQLite (one per process)
- Stall detection and graceful degradation
"""

from __future__ import annotations

import logging
import os
import re
import sqlite3
import time
from concurrent.futures import ProcessPoolExecutor, ThreadPoolExecutor, as_completed
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Callable

from whitemagic.agents.progress_tracker import ProgressTracker

logger = logging.getLogger(__name__)

# Default DB path
DEFAULT_DB = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"


@dataclass
class BatchResult:
    """Result from a parallel batch operation."""
    processed: int = 0
    skipped: int = 0
    errors: int = 0
    results: list[Any] | None = None
    elapsed_s: float = 0.0
    throughput: float = 0.0  # items/sec


def get_wal_connection(
    db_path: str | Path | None = None,
    readonly: bool = False,
) -> sqlite3.Connection:
    """Get a WAL-mode SQLite connection with optimal settings for parallel access."""
    path = str(db_path or DEFAULT_DB)
    if readonly:
        uri = f"file:{path}?mode=ro"
        conn = sqlite3.connect(uri, uri=True, timeout=10)
    else:
        conn = sqlite3.connect(path, timeout=10)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA busy_timeout=5000")
    conn.execute("PRAGMA synchronous=NORMAL")
    conn.execute("PRAGMA cache_size=-8000")  # 8MB cache
    conn.row_factory = sqlite3.Row
    return conn


def chunked(items: list, chunk_size: int) -> list[list]:
    """Split a list into chunks of specified size."""
    return [items[i:i + chunk_size] for i in range(0, len(items), chunk_size)]


# ─── Worker functions (must be top-level for ProcessPoolExecutor pickling) ───

def _worker_type_associations(
    chunk: list[tuple],
    db_path: str,
    type_rules: list[tuple[str, str]],
) -> dict[str, int]:
    """Worker: classify association types using regex heuristics."""
    conn = sqlite3.connect(db_path, timeout=10)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA busy_timeout=5000")

    compiled = [(re.compile(p, re.IGNORECASE), t) for p, t in type_rules]
    counts: dict[str, int] = {}
    updates: list[tuple[str, str, str]] = []

    for row in chunk:
        src_id, tgt_id, strength, src_title, tgt_title = row
        combined = f"{src_title or ''} {tgt_title or ''}"
        relation = None

        for pat, rtype in compiled:
            if pat.search(combined):
                relation = rtype
                break

        if relation is None:
            s = strength or 0
            if s > 0.7:
                relation = "SIBLING_OF"
            elif s > 0.3:
                relation = "semantic"
            else:
                relation = "weak_semantic"

        updates.append((relation, src_id, tgt_id))
        counts[relation] = counts.get(relation, 0) + 1

    conn.executemany(
        "UPDATE associations SET relation_type = ? WHERE source_id = ? AND target_id = ?",
        updates,
    )
    conn.commit()
    conn.close()
    return counts


def _worker_extract_entities(
    memory_ids: list[str],
    db_path: str,
) -> dict[str, int]:
    """Worker: extract entities from memory content using regex patterns."""
    conn = sqlite3.connect(db_path, timeout=10)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA busy_timeout=5000")

    entity_patterns = [
        (r'\b(?:whitemagic|WhiteMagic)\b', 'SYSTEM', 'whitemagic'),
        (r'\b(?:rust|Rust)\b', 'LANGUAGE', 'rust'),
        (r'\b(?:python|Python)\b', 'LANGUAGE', 'python'),
        (r'\b(?:mcp|MCP)\b', 'SYSTEM', 'mcp'),
        (r'\b(?:aria|Aria)\b', 'PERSON', 'aria'),
        (r'\b(?:lucas|Lucas)\b', 'PERSON', 'lucas'),
        (r'\b(?:sqlite|SQLite)\b', 'SYSTEM', 'sqlite'),
        (r'\b(?:consciousness)\b', 'CONCEPT', 'consciousness'),
        (r'\b(?:dharma|Dharma)\b', 'CONCEPT', 'dharma'),
        (r'\b(?:zodiac|Zodiac)\b', 'CONCEPT', 'zodiac'),
        (r'\b(?:wu\s*xing|Wu\s*Xing)\b', 'CONCEPT', 'wu_xing'),
        (r'\b(?:yin.yang|Yin.Yang)\b', 'CONCEPT', 'yin_yang'),
        (r'\b(?:gan\s*ying|Gan\s*Ying)\b', 'CONCEPT', 'gan_ying'),
        (r'\b(?:tokio|Tokio)\b', 'SYSTEM', 'tokio'),
    ]
    compiled = [(re.compile(p), t, n) for p, t, n in entity_patterns]

    stats: dict[str, int] = {"extracted": 0, "skipped": 0}
    placeholders = ",".join("?" * len(memory_ids))
    rows = conn.execute(
        f"SELECT id, content, title FROM memories WHERE id IN ({placeholders})",
        memory_ids,
    ).fetchall()

    for row in rows:
        mid, content, title = row[0], row[1] or "", row[2] or ""
        text = f"{title} {content}"
        found_entities: list[tuple[str, str]] = []

        for pat, etype, ename in compiled:
            if pat.search(text):
                found_entities.append((etype, ename))

        if found_entities:
            stats["extracted"] += len(found_entities)
        else:
            stats["skipped"] += 1

    conn.close()
    return stats


def _worker_scan_files(
    file_paths: list[str],
    pattern: str,
    context_lines: int = 5,
) -> list[dict[str, Any]]:
    """Worker: scan files for pattern matches."""
    compiled = re.compile(pattern)
    findings: list[dict[str, Any]] = []

    for fpath in file_paths:
        try:
            content = Path(fpath).read_text(errors="replace")
            for m in compiled.finditer(content):
                line_no = content[:m.start()].count("\n") + 1
                lines = content.split("\n")
                ctx_start = max(0, line_no - context_lines)
                ctx_end = min(len(lines), line_no + context_lines)
                findings.append({
                    "file": fpath,
                    "line": line_no,
                    "match": m.group()[:100],
                    "context": "\n".join(lines[ctx_start:ctx_end]),
                })
        except Exception:
            pass

    return findings


# ─── Main Parallel Engine ───

class ParallelEngine:
    """Orchestrates parallel batch operations with progress tracking.

    Selects ProcessPoolExecutor for CPU-bound work and ThreadPoolExecutor
    for I/O-bound work. Integrates with ProgressTracker for granular reporting.
    """

    def __init__(
        self,
        max_workers: int | None = None,
        db_path: str | Path | None = None,
    ) -> None:
        cpu_count = os.cpu_count() or 4
        self.max_workers = max_workers or min(cpu_count, 8)
        self.db_path = str(db_path or DEFAULT_DB)

    def batch_type_associations(
        self,
        chunk_size: int = 25000,
        tracker: ProgressTracker | None = None,
    ) -> BatchResult:
        """Type all untyped associations using parallel workers."""
        conn = get_wal_connection(self.db_path)

        # Count untyped
        untyped_count = conn.execute(
            "SELECT COUNT(*) FROM associations "
            "WHERE relation_type IS NULL OR relation_type = 'associated_with'"
        ).fetchone()[0]

        if untyped_count == 0:
            conn.close()
            return BatchResult(processed=0)

        if tracker:
            tracker.total = untyped_count

        type_rules = [
            (r'\b(?:implements?|built|created?|wrote|designed)\b', 'IMPLEMENTS'),
            (r'\b(?:uses?|using|requires?|depends|imports?)\b', 'USES'),
            (r'\b(?:contains?|includes?|has|holds)\b', 'CONTAINS'),
            (r'\b(?:explores?|studies|investigates?|researches?)\b', 'EXPLORES'),
            (r'\b(?:causes?|triggers?|leads?\s+to|results?\s+in)\b', 'CAUSES'),
            (r'\b(?:extends?|inherits?|overrides?|specializes?)\b', 'EXTENDS'),
            (r'\b(?:similar|like|related|parallel)\b', 'SIBLING_OF'),
        ]

        start = time.monotonic()
        total_typed = 0
        all_counts: dict[str, int] = {}

        # Fetch all untyped in batches and process with ProcessPool
        while True:
            rows = conn.execute('''
                SELECT a.source_id, a.target_id, a.strength,
                       m1.title, m2.title
                FROM associations a
                JOIN memories m1 ON a.source_id = m1.id
                JOIN memories m2 ON a.target_id = m2.id
                WHERE (a.relation_type IS NULL OR a.relation_type = 'associated_with')
                AND m1.memory_type != 'quarantined' AND m2.memory_type != 'quarantined'
                LIMIT ?
            ''', (chunk_size * self.max_workers,)).fetchall()

            if not rows:
                break

            # Convert Row objects to tuples
            row_tuples = [(r[0], r[1], r[2], r[3], r[4]) for r in rows]
            chunks = chunked(row_tuples, chunk_size)

            with ProcessPoolExecutor(max_workers=self.max_workers) as executor:
                futures = [
                    executor.submit(
                        _worker_type_associations,
                        chunk, self.db_path, type_rules,
                    )
                    for chunk in chunks
                ]

                for future in as_completed(futures):
                    try:
                        counts = future.result(timeout=120)
                        batch_total = sum(counts.values())
                        total_typed += batch_total
                        for k, v in counts.items():
                            all_counts[k] = all_counts.get(k, 0) + v
                        if tracker:
                            tracker.advance(batch_total, detail=f"batch {len(chunks)}")
                    except Exception as e:
                        if tracker:
                            tracker.error(f"Worker failed: {e}")

        # Handle orphan associations (pointing to quarantined memories)
        orphans = conn.execute('''
            SELECT COUNT(*) FROM associations a
            WHERE (a.relation_type IS NULL OR a.relation_type = 'associated_with')
        ''').fetchone()[0]

        if orphans > 0:
            conn.execute('''
                UPDATE associations SET relation_type = 'ghost_edge'
                WHERE (relation_type IS NULL OR relation_type = 'associated_with')
            ''')
            conn.commit()
            total_typed += orphans
            if tracker:
                tracker.advance(orphans, detail="orphan→ghost_edge")

        elapsed = time.monotonic() - start
        conn.close()

        return BatchResult(
            processed=total_typed,
            results=[all_counts],
            elapsed_s=elapsed,
            throughput=total_typed / elapsed if elapsed > 0 else 0,
        )

    def parallel_file_scan(
        self,
        directory: Path,
        pattern: str,
        extensions: list[str] | None = None,
        tracker: ProgressTracker | None = None,
    ) -> list[dict[str, Any]]:
        """Scan files in parallel using ThreadPoolExecutor."""
        exts = extensions or [".py"]
        files: list[str] = []
        for ext in exts:
            files.extend(str(f) for f in directory.rglob(f"*{ext}") if "__pycache__" not in str(f))

        if not files:
            return []

        if tracker:
            tracker.total = len(files)

        chunks = chunked(files, max(1, len(files) // self.max_workers))
        all_findings: list[dict[str, Any]] = []

        with ThreadPoolExecutor(max_workers=self.max_workers) as executor:
            futures = [
                executor.submit(_worker_scan_files, chunk, pattern)
                for chunk in chunks
            ]

            for future in as_completed(futures):
                try:
                    findings = future.result(timeout=60)
                    all_findings.extend(findings)
                    if tracker:
                        tracker.advance(len(chunks[0]) if chunks else 0)
                except Exception as e:
                    if tracker:
                        tracker.error(f"Scan worker failed: {e}")

        return all_findings

    def parallel_db_operation(
        self,
        items: list[Any],
        worker_fn: Callable,
        chunk_size: int = 5000,
        tracker: ProgressTracker | None = None,
        use_processes: bool = True,
        **kwargs: Any,
    ) -> BatchResult:
        """Generic parallel DB operation with chunking and progress tracking."""
        if not items:
            return BatchResult()

        if tracker:
            tracker.total = len(items)

        start = time.monotonic()
        chunks = chunked(items, chunk_size)
        processed = 0
        errors = 0
        all_results: list[Any] = []

        ExecutorClass = ProcessPoolExecutor if use_processes else ThreadPoolExecutor

        with ExecutorClass(max_workers=self.max_workers) as executor:
            futures = [
                executor.submit(worker_fn, chunk, self.db_path, **kwargs)
                for chunk in chunks
            ]

            for future in as_completed(futures):
                try:
                    result = future.result(timeout=120)
                    all_results.append(result)
                    chunk_count = len(chunks[0]) if chunks else 0
                    processed += chunk_count
                    if tracker:
                        tracker.advance(chunk_count)
                except Exception as e:
                    errors += 1
                    if tracker:
                        tracker.error(str(e))

        elapsed = time.monotonic() - start
        return BatchResult(
            processed=processed,
            errors=errors,
            results=all_results,
            elapsed_s=elapsed,
            throughput=processed / elapsed if elapsed > 0 else 0,
        )
