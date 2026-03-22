#!/usr/bin/env python3
"""
Ingest extracted_concepts.jsonl into the Whitemagic holographic memory.

Each JSONL line has: {"pattern": str, "domain": str, "confidence": float, "id": str}
Domains: technical (~84K), theme (~4K), entity (~1K)

Uses the existing bulk_ingest.py pattern: direct SQLite inserts with
content-hash dedup, then holographic coordinate encoding.
"""

import json
import hashlib
import sqlite3
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

MEM_DB = ROOT / "memory" / "whitemagic.db"
CONCEPTS_FILE = Path.home() / "Desktop" / "wm_archive" / "extracted_concepts.jsonl"


def content_hash(text: str) -> str:
    return hashlib.sha256(text.encode()).hexdigest()[:16]


def ensure_schema(conn: sqlite3.Connection) -> None:
    """Bootstrap the memory schema if it doesn't exist yet."""
    conn.execute("PRAGMA journal_mode = WAL")
    conn.execute("PRAGMA synchronous = NORMAL")
    conn.execute("PRAGMA foreign_keys = ON")
    conn.execute("PRAGMA busy_timeout = 5000")

    conn.execute("""
        CREATE TABLE IF NOT EXISTS memories (
            id TEXT PRIMARY KEY,
            content TEXT,
            memory_type TEXT,
            created_at TEXT,
            updated_at TEXT,
            accessed_at TEXT,
            access_count INTEGER DEFAULT 0,
            emotional_valence REAL DEFAULT 0.0,
            importance REAL DEFAULT 0.5,
            neuro_score REAL DEFAULT 1.0,
            novelty_score REAL DEFAULT 1.0,
            recall_count INTEGER DEFAULT 0,
            half_life_days REAL DEFAULT 30.0,
            is_protected INTEGER DEFAULT 0,
            metadata TEXT DEFAULT '{}',
            title TEXT
        )
    """)
    conn.execute("""
        CREATE TABLE IF NOT EXISTS tags (
            memory_id TEXT,
            tag TEXT,
            FOREIGN KEY (memory_id) REFERENCES memories(id) ON DELETE CASCADE,
            PRIMARY KEY (memory_id, tag)
        )
    """)
    conn.execute("CREATE INDEX IF NOT EXISTS idx_tags_tag ON tags(tag)")
    conn.execute("""
        CREATE TABLE IF NOT EXISTS holographic_coords (
            memory_id TEXT PRIMARY KEY,
            x REAL, y REAL, z REAL, w REAL,
            FOREIGN KEY (memory_id) REFERENCES memories(id) ON DELETE CASCADE
        )
    """)
    conn.execute("""
        CREATE VIRTUAL TABLE IF NOT EXISTS memories_fts USING fts5(
            id UNINDEXED, title, content, tags_text
        )
    """)
    conn.execute("""
        CREATE TABLE IF NOT EXISTS associations (
            source_id TEXT, target_id TEXT, strength REAL,
            FOREIGN KEY (source_id) REFERENCES memories(id) ON DELETE CASCADE,
            FOREIGN KEY (target_id) REFERENCES memories(id) ON DELETE CASCADE,
            PRIMARY KEY (source_id, target_id)
        )
    """)
    conn.execute("""
        CREATE TABLE IF NOT EXISTS akashic_seeds (
            id TEXT PRIMARY KEY, content TEXT, bloom_conditions TEXT,
            planted_at TEXT, times_bloomed INTEGER DEFAULT 0,
            last_bloomed TEXT, potency REAL DEFAULT 1.0, keywords TEXT
        )
    """)
    conn.execute("""
        CREATE TABLE IF NOT EXISTS dharma_audit (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp TEXT NOT NULL, action TEXT NOT NULL,
            ethical_score REAL, harmony_score REAL,
            consent_level TEXT, boundary_type TEXT,
            concerns TEXT, context TEXT, decision TEXT
        )
    """)
    conn.execute("CREATE INDEX IF NOT EXISTS idx_memories_importance ON memories(importance)")
    conn.execute("CREATE INDEX IF NOT EXISTS idx_memories_created_at ON memories(created_at)")
    conn.commit()


def load_existing(conn: sqlite3.Connection) -> tuple[set, set]:
    """Return (set of existing IDs, set of content-hashes) for dedup."""
    try:
        rows = conn.execute("SELECT id, content FROM memories").fetchall()
    except sqlite3.OperationalError:
        return set(), set()
    ids = {r[0] for r in rows}
    chashes = {content_hash(r[1]) for r in rows if r[1]}
    return ids, chashes


def importance_for_domain(domain: str, confidence: float) -> float:
    """Map domain + confidence to an importance score."""
    base = {"entity": 0.7, "theme": 0.5, "technical": 0.3}
    return min(1.0, base.get(domain, 0.3) * confidence + 0.1)


def main():
    start = time.time()
    print("=" * 62)
    print("  CONCEPT INGESTION — extracted_concepts.jsonl")
    print("=" * 62)

    if not CONCEPTS_FILE.exists():
        print(f"  ERROR: {CONCEPTS_FILE} not found")
        sys.exit(1)

    MEM_DB.parent.mkdir(parents=True, exist_ok=True)
    conn = sqlite3.connect(str(MEM_DB))
    ensure_schema(conn)

    existing_ids, existing_chashes = load_existing(conn)
    print(f"\n  Live DB baseline: {len(existing_ids)} memories")

    imported = 0
    skipped_dup = 0
    skipped_short = 0
    batch = []
    batch_tags = []
    batch_fts = []
    ts = time.strftime("%Y-%m-%dT%H:%M:%S")

    with open(CONCEPTS_FILE) as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            try:
                obj = json.loads(line)
            except json.JSONDecodeError:
                continue

            pattern = obj.get("pattern", "")
            domain = obj.get("domain", "technical")
            confidence = obj.get("confidence", 0.5)
            concept_id = obj.get("id", "")

            # Skip very short patterns (noise)
            if len(pattern) < 3:
                skipped_short += 1
                continue

            content = f"[concept:{domain}] {pattern}"
            mem_id = content_hash(content)

            if mem_id in existing_ids or mem_id in existing_chashes:
                skipped_dup += 1
                continue

            importance = importance_for_domain(domain, confidence)
            meta = json.dumps({
                "source": "extracted_concepts.jsonl",
                "domain": domain,
                "confidence": confidence,
                "concept_id": concept_id,
            })

            batch.append((
                mem_id, content, "SHORT_TERM", ts, ts, ts,
                0, 0.0, importance, 1.0, 1.0, 0, 30.0, 0,
                meta, pattern[:80]
            ))
            # Tags
            for tag in ["concept", domain, "archive_ingest"]:
                batch_tags.append((mem_id, tag))
            # FTS
            tags_text = f"concept {domain} archive_ingest"
            batch_fts.append((mem_id, pattern[:80], content, tags_text))

            existing_ids.add(mem_id)
            existing_chashes.add(mem_id)
            imported += 1

            # Flush in batches of 5000
            if len(batch) >= 5000:
                conn.executemany(
                    "INSERT OR IGNORE INTO memories "
                    "(id, content, memory_type, created_at, updated_at, accessed_at, "
                    " access_count, emotional_valence, importance, neuro_score, "
                    " novelty_score, recall_count, half_life_days, is_protected, metadata, title) "
                    "VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
                    batch
                )
                conn.executemany(
                    "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?,?)",
                    batch_tags
                )
                conn.executemany(
                    "INSERT OR IGNORE INTO memories_fts (id, title, content, tags_text) VALUES (?,?,?,?)",
                    batch_fts
                )
                conn.commit()
                print(f"    ... {imported} ingested so far", flush=True)
                batch.clear()
                batch_tags.clear()
                batch_fts.clear()

    # Final flush
    if batch:
        conn.executemany(
            "INSERT OR IGNORE INTO memories "
            "(id, content, memory_type, created_at, updated_at, accessed_at, "
            " access_count, emotional_valence, importance, neuro_score, "
            " novelty_score, recall_count, half_life_days, is_protected, metadata, title) "
            "VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)",
            batch
        )
        conn.executemany(
            "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?,?)",
            batch_tags
        )
        conn.executemany(
            "INSERT OR IGNORE INTO memories_fts (id, title, content, tags_text) VALUES (?,?,?,?)",
            batch_fts
        )
        conn.commit()

    # Optionally encode holographic coordinates
    try:
        from whitemagic.intelligence.hologram.encoder import CoordinateEncoder
        encoder = CoordinateEncoder()
        rows = conn.execute("""
            SELECT m.id, m.content, m.metadata, m.memory_type, m.title
            FROM memories m
            LEFT JOIN holographic_coords h ON m.id = h.memory_id
            WHERE h.memory_id IS NULL
            LIMIT 10000
        """).fetchall()
        encoded = 0
        for mem_id, content, meta_raw, mem_type, title in rows:
            try:
                meta = json.loads(meta_raw) if meta_raw else {}
                tag_rows = conn.execute(
                    "SELECT tag FROM tags WHERE memory_id=?", (mem_id,)
                ).fetchall()
                mem_dict = {
                    "content": content or "",
                    "type": mem_type or "",
                    "tags": [r[0] for r in tag_rows],
                    "title": title or "",
                    "metadata": meta,
                }
                coords = encoder.encode(mem_dict)
                conn.execute(
                    "INSERT OR IGNORE INTO holographic_coords (memory_id, x, y, z, w) "
                    "VALUES (?,?,?,?,?)",
                    (mem_id, coords.x, coords.y, coords.z, coords.w)
                )
                encoded += 1
            except Exception as e:
                print(f"    Coord-encode error: {e}")
                break
        conn.commit()
        print(f"\n  Holographic coords encoded: {encoded}")
    except ImportError:
        print("\n  (Holographic encoder not available — skipping coord encoding)")

    conn.close()
    elapsed = time.time() - start

    print(f"\n{'=' * 62}")
    print(f"  DONE — {imported} concepts ingested")
    print(f"  Skipped: {skipped_dup} duplicates, {skipped_short} too short")
    print(f"  Total time: {elapsed:.2f}s")
    print(f"{'=' * 62}")


if __name__ == "__main__":
    main()
