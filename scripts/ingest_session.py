#!/usr/bin/env python3
"""
Ingest a conversation/session transcript into the WhiteMagic galactic memory core.

This is the universal session ingestion script — works with any source:
  - Windsurf (Cascade) conversations (via trajectory_search → file/stdin)
  - Antigravity sessions
  - ChatGPT/Claude/Gemini exports
  - Any markdown/text conversation log

Usage:
    # From file
    python scripts/ingest_session.py --file session_transcript.md --title "My Session" --tags "v15,bugfix"

    # From stdin (piped from another tool)
    cat transcript.md | python scripts/ingest_session.py --title "My Session" --source windsurf

    # From a JSON envelope (structured input)
    python scripts/ingest_session.py --json session_envelope.json

    # Dry run (preview what would be stored)
    python scripts/ingest_session.py --file transcript.md --title "Test" --dry-run

Environment:
    WM_STATE_ROOT    Override state directory (default: ~/.whitemagic)
    WM_GALAXY        Target galaxy name (default: active galaxy)
"""

import argparse
import hashlib
import json
import os
import sqlite3
import sys
import time
from datetime import datetime
from pathlib import Path
from uuid import uuid4

# ---------------------------------------------------------------------------
# Paths
# ---------------------------------------------------------------------------

HOME = Path.home()
DEFAULT_DB = HOME / ".whitemagic" / "memory" / "whitemagic.db"


def get_db_path(galaxy: str | None = None) -> Path:
    """Resolve the target DB path."""
    state_root = Path(os.environ.get("WM_STATE_ROOT", str(HOME / ".whitemagic")))
    if galaxy:
        return state_root / "memory" / "galaxies" / galaxy / "whitemagic.db"
    return state_root / "memory" / "whitemagic.db"


# ---------------------------------------------------------------------------
# Content hashing & dedup
# ---------------------------------------------------------------------------

def content_hash(text: str) -> str:
    """SHA-256 of normalized content for dedup."""
    normalized = " ".join(text.split()).strip().lower()
    return hashlib.sha256(normalized.encode()).hexdigest()


def title_exists(db_path: Path, title: str) -> bool:
    """Check if a memory with this exact title already exists."""
    if not db_path.exists():
        return False
    conn = sqlite3.connect(str(db_path))
    try:
        row = conn.execute(
            "SELECT COUNT(*) FROM memories WHERE title = ?", (title,)
        ).fetchone()
        return bool(row and row[0] > 0)
    except sqlite3.OperationalError:
        return False
    finally:
        conn.close()


def hash_exists(db_path: Path, h: str) -> bool:
    """Check if a memory with this content hash already exists."""
    if not db_path.exists():
        return False
    conn = sqlite3.connect(str(db_path))
    try:
        row = conn.execute(
            "SELECT COUNT(*) FROM memories WHERE content_hash = ?", (h,)
        ).fetchone()
        return bool(row and row[0] > 0)
    except sqlite3.OperationalError:
        return False
    finally:
        conn.close()


# ---------------------------------------------------------------------------
# Ingestion
# ---------------------------------------------------------------------------

def ingest_memory(
    db_path: Path,
    title: str,
    content: str,
    tags: list[str],
    source: str = "unknown",
    metadata: dict | None = None,
    dry_run: bool = False,
) -> dict:
    """Store a session transcript as a LONG_TERM memory."""
    memory_id = uuid4().hex[:16]
    now = datetime.now().isoformat()
    c_hash = content_hash(content)

    # Dedup checks
    if title_exists(db_path, title):
        return {"status": "skipped", "reason": "title_exists", "title": title}
    if hash_exists(db_path, c_hash):
        return {"status": "skipped", "reason": "content_hash_exists", "hash": c_hash[:16]}

    if dry_run:
        return {
            "status": "dry_run",
            "memory_id": memory_id,
            "title": title,
            "content_length": len(content),
            "content_hash": c_hash[:16],
            "tags": tags,
            "source": source,
        }

    # Ensure DB directory exists
    db_path.parent.mkdir(parents=True, exist_ok=True)

    conn = sqlite3.connect(str(db_path))
    conn.execute("PRAGMA journal_mode=WAL")

    # Ensure memories table exists (minimal schema)
    conn.execute("""
        CREATE TABLE IF NOT EXISTS memories (
            id TEXT PRIMARY KEY,
            content TEXT NOT NULL,
            memory_type TEXT DEFAULT 'LONG_TERM',
            title TEXT,
            created_at TEXT,
            accessed_at TEXT,
            access_count INTEGER DEFAULT 1,
            importance REAL DEFAULT 0.7,
            emotional_valence REAL DEFAULT 0.0,
            content_hash TEXT,
            metadata TEXT,
            neuro_score REAL DEFAULT 1.0,
            galaxy_zone TEXT DEFAULT 'mid_band',
            galactic_distance REAL DEFAULT 0.5
        )
    """)

    # Ensure tags table exists
    conn.execute("""
        CREATE TABLE IF NOT EXISTS tags (
            memory_id TEXT,
            tag TEXT,
            PRIMARY KEY (memory_id, tag)
        )
    """)

    # Build metadata
    mem_metadata = {
        "source": source,
        "ingested_at": now,
        "ingestion_method": "ingest_session.py",
    }
    if metadata:
        mem_metadata.update(metadata)

    # Insert memory
    conn.execute(
        """INSERT INTO memories (id, content, memory_type, title, created_at,
           accessed_at, access_count, importance, emotional_valence,
           content_hash, metadata, neuro_score, galactic_distance)
           VALUES (?, ?, 'LONG_TERM', ?, ?, ?, 1, 0.8, 0.0, ?, ?, 1.0, 0.5)""",
        (memory_id, content, title, now, now, c_hash, json.dumps(mem_metadata)),
    )

    # Insert tags
    all_tags = set(tags) | {"session_transcript", f"source:{source}"}
    for tag in all_tags:
        conn.execute(
            "INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)",
            (memory_id, tag),
        )

    conn.commit()

    # Rebuild FTS if table exists
    try:
        conn.execute("INSERT INTO memories_fts(memories_fts) VALUES('rebuild')")
        conn.commit()
    except sqlite3.OperationalError:
        pass

    conn.close()

    return {
        "status": "success",
        "memory_id": memory_id,
        "title": title,
        "content_length": len(content),
        "content_hash": c_hash[:16],
        "tags": sorted(all_tags),
        "db_path": str(db_path),
    }


# ---------------------------------------------------------------------------
# Input parsing
# ---------------------------------------------------------------------------

def read_json_envelope(path: str) -> dict:
    """Read a structured JSON envelope with title, content, tags, source."""
    with open(path, encoding="utf-8") as f:
        data = json.load(f)
    if not isinstance(data, dict):
        raise ValueError("JSON envelope must be a dict with 'title' and 'content' keys")
    if "content" not in data:
        raise ValueError("JSON envelope must contain 'content' key")
    return data


def summarize_for_display(content: str, max_chars: int = 200) -> str:
    """First N chars for preview."""
    if len(content) <= max_chars:
        return content
    return content[:max_chars] + "..."


# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------

def main() -> None:
    parser = argparse.ArgumentParser(
        description="Ingest a session transcript into WhiteMagic galactic memory core",
    )
    parser.add_argument("--file", "-f", help="Path to transcript file (markdown/text)")
    parser.add_argument("--json", "-j", help="Path to JSON envelope file")
    parser.add_argument("--title", "-t", help="Memory title")
    parser.add_argument("--tags", help="Comma-separated tags")
    parser.add_argument("--source", "-s", default="unknown", help="Source identifier (windsurf, antigravity, chatgpt, etc.)")
    parser.add_argument("--galaxy", "-g", help="Target galaxy name")
    parser.add_argument("--dry-run", action="store_true", help="Preview without storing")
    parser.add_argument("--quiet", "-q", action="store_true", help="Minimal output")
    args = parser.parse_args()

    # Determine input
    if args.json:
        envelope = read_json_envelope(args.json)
        content = envelope["content"]
        title = args.title or envelope.get("title", f"Session {datetime.now().strftime('%Y-%m-%d %H:%M')}")
        tags_str = args.tags or ",".join(envelope.get("tags", []))
        source = args.source if args.source != "unknown" else envelope.get("source", "unknown")
        metadata = envelope.get("metadata")
    elif args.file:
        content = Path(args.file).read_text(encoding="utf-8")
        title = args.title or Path(args.file).stem.replace("_", " ").title()
        tags_str = args.tags or ""
        source = args.source
        metadata = {"source_file": args.file}
    elif not sys.stdin.isatty():
        content = sys.stdin.read()
        title = args.title or f"Session {datetime.now().strftime('%Y-%m-%d %H:%M')}"
        tags_str = args.tags or ""
        source = args.source
        metadata = None
    else:
        parser.error("Provide --file, --json, or pipe content via stdin")
        return

    if not content.strip():
        print("Error: Empty content", file=sys.stderr)
        sys.exit(1)

    tags = [t.strip() for t in tags_str.split(",") if t.strip()] if tags_str else []

    db_path = get_db_path(args.galaxy)

    if not args.quiet:
        print(f"{'[DRY RUN] ' if args.dry_run else ''}Session Ingestion")
        print(f"  Title:   {title}")
        print(f"  Source:  {source}")
        print(f"  Tags:    {tags}")
        print(f"  Content: {len(content):,} chars")
        print(f"  DB:      {db_path}")
        print()

    t0 = time.perf_counter()
    result = ingest_memory(
        db_path=db_path,
        title=title,
        content=content,
        tags=tags,
        source=source,
        metadata=metadata,
        dry_run=args.dry_run,
    )
    dt = time.perf_counter() - t0

    if not args.quiet:
        if result["status"] == "success":
            print(f"  Ingested: {result['memory_id']}")
            print(f"  Hash:     {result['content_hash']}")
            print(f"  Tags:     {result['tags']}")
            print(f"  Time:     {dt*1000:.1f}ms")
        elif result["status"] == "skipped":
            print(f"  Skipped: {result['reason']}")
        elif result["status"] == "dry_run":
            print(f"  Would store: {result['memory_id']}")
            print(f"  Hash:        {result['content_hash']}")

    # Output JSON for programmatic use
    if args.quiet:
        print(json.dumps(result))


if __name__ == "__main__":
    main()
