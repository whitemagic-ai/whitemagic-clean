#!/usr/bin/env python3
"""
Kaizen Dedup — Remove exact-duplicate memories and auto-tag untagged entries.

Strategy:
  1. Stream all memories, hash (title + content) in Python, collect duplicate IDs.
     Keep the one with highest importance per group. Delete the rest in batches.
  2. Auto-tag remaining untagged memories by memory_type.
  3. Rebuild FTS5 index.
  4. VACUUM to reclaim space.
"""

import hashlib
import sqlite3
import time
from collections import defaultdict
from pathlib import Path

DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"


def run_dedup(db: sqlite3.Connection) -> int:
    """Remove exact duplicates (same title + content hash). Returns count removed."""
    cur = db.cursor()

    # Stream all memories and group by hash in Python (much faster than SQL GROUP BY on content)
    print("  Scanning memories...")
    t0 = time.time()
    groups = defaultdict(list)  # hash -> [(id, importance, created_at), ...]
    cur.execute("SELECT id, title, content, importance, created_at FROM memories")
    row_count = 0
    for mid, title, content, importance, created_at in cur:
        h = hashlib.md5(f"{title or ''}\x00{content or ''}".encode()).hexdigest()
        groups[h].append((mid, importance or 0, created_at or ""))
        row_count += 1
        if row_count % 50000 == 0:
            print(f"    ...scanned {row_count:,}")

    print(f"  Scanned {row_count:,} memories in {time.time()-t0:.1f}s")

    # Find groups with duplicates
    dup_groups = {h: entries for h, entries in groups.items() if len(entries) > 1}
    print(f"  Found {len(dup_groups):,} duplicate groups")
    del groups  # free memory

    # Collect IDs to delete (keep best per group)
    to_delete = []
    for entries in dup_groups.values():
        # Sort: highest importance first, then newest
        entries.sort(key=lambda e: (e[1], e[2]), reverse=True)
        # Keep first, delete rest
        for mid, _, _ in entries[1:]:
            to_delete.append(mid)

    print(f"  Marking {len(to_delete):,} memories for deletion")
    del dup_groups

    # Delete in batches
    BATCH = 5000
    for i in range(0, len(to_delete), BATCH):
        batch = to_delete[i:i+BATCH]
        placeholders = ",".join("?" * len(batch))
        cur.execute(f"DELETE FROM memories WHERE id IN ({placeholders})", batch)
        cur.execute(f"DELETE FROM tags WHERE memory_id IN ({placeholders})", batch)
        cur.execute(f"DELETE FROM holographic_coords WHERE memory_id IN ({placeholders})", batch)
        cur.execute(f"DELETE FROM associations WHERE source_id IN ({placeholders}) OR target_id IN ({placeholders})",
                    batch + batch)
        db.commit()
        if (i // BATCH) % 5 == 0:
            print(f"    ...deleted {min(i+BATCH, len(to_delete)):,}/{len(to_delete):,}")

    return len(to_delete)


def auto_tag(db: sqlite3.Connection) -> int:
    """Auto-tag untagged memories based on memory_type. Returns count tagged."""
    cur = db.cursor()

    type_tags = {
        "deep_archive": "archive",
        "scavenged": "scavenged",
        "LONG_TERM": "core",
        "SHORT_TERM": "ephemeral",
    }

    total_tagged = 0
    for mem_type, tag in type_tags.items():
        cur.execute("""
            SELECT m.id FROM memories m
            WHERE m.memory_type = ?
            AND m.id NOT IN (SELECT memory_id FROM tags)
        """, (mem_type,))
        ids = [r[0] for r in cur.fetchall()]

        if ids:
            cur.executemany("INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)",
                           [(mid, tag) for mid in ids])
            total_tagged += len(ids)
            print(f"  Tagged {len(ids):,} '{mem_type}' memories as '{tag}'")

    db.commit()
    return total_tagged


def rebuild_fts(db: sqlite3.Connection):
    """Rebuild the FTS5 index from scratch."""
    cur = db.cursor()
    cur.execute("DELETE FROM memories_fts")
    cur.execute("""
        INSERT INTO memories_fts (rowid, title, content)
        SELECT rowid, title, content FROM memories
    """)
    db.commit()


def main():
    print(f"Kaizen Dedup — {DB_PATH}")
    print(f"DB size: {DB_PATH.stat().st_size / 1024 / 1024:.1f} MB")

    db = sqlite3.connect(str(DB_PATH))
    db.execute("PRAGMA journal_mode=WAL")
    db.execute("PRAGMA synchronous=NORMAL")
    db.execute("PRAGMA cache_size=-64000")  # 64MB cache

    cur = db.cursor()
    cur.execute("SELECT COUNT(*) FROM memories")
    before = cur.fetchone()[0]
    print(f"Memories before: {before:,}")

    # Step 1: Dedup
    print("\n[1/4] Deduplicating exact duplicates...")
    t0 = time.time()
    removed = run_dedup(db)
    print(f"  Removed {removed:,} duplicates in {time.time()-t0:.1f}s")

    # Step 2: Auto-tag
    print("\n[2/4] Auto-tagging untagged memories...")
    t0 = time.time()
    tagged = auto_tag(db)
    print(f"  Tagged {tagged:,} memories in {time.time()-t0:.1f}s")

    # Step 3: Rebuild FTS
    print("\n[3/4] Rebuilding FTS5 index...")
    t0 = time.time()
    rebuild_fts(db)
    print(f"  FTS rebuilt in {time.time()-t0:.1f}s")

    # Step 4: VACUUM
    print("\n[4/4] Vacuuming database...")
    t0 = time.time()
    db.execute("VACUUM")
    print(f"  Vacuumed in {time.time()-t0:.1f}s")

    cur.execute("SELECT COUNT(*) FROM memories")
    after = cur.fetchone()[0]
    print(f"\nMemories after: {after:,} (removed {before - after:,})")
    print(f"DB size: {DB_PATH.stat().st_size / 1024 / 1024:.1f} MB")

    db.close()
    print("\nDone.")


if __name__ == "__main__":
    main()
