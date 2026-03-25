#!/usr/bin/env python3
"""Batch-assign holographic 5D coordinates for all uncoordinated memories.

Iterates through memories missing holographic_coords entries, encodes them
via the CoordinateEncoder (with Rust/Mojo acceleration when available),
and persists to the holographic_coords table.

Usage:
    python scripts/batch_holographic_coords.py                  # Full run
    python scripts/batch_holographic_coords.py --limit 10000    # Cap at 10K
    python scripts/batch_holographic_coords.py --batch-size 500 # Larger batches
    python scripts/batch_holographic_coords.py --dry-run        # Count only
"""

import argparse
import logging
import os
import sqlite3
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
log = logging.getLogger("batch_coords")


def main():
    parser = argparse.ArgumentParser(description="Batch assign holographic coordinates")
    parser.add_argument("--limit", type=int, default=0, help="Max memories to process (0=all)")
    parser.add_argument("--batch-size", type=int, default=200, help="Memories per batch")
    parser.add_argument("--dry-run", action="store_true", help="Count only, skip encoding")
    args = parser.parse_args()

    from whitemagic.config.paths import DB_PATH
    from whitemagic.core.intelligence.hologram.encoder import CoordinateEncoder

    db_path = DB_PATH
    if not db_path.exists():
        log.error(f"DB not found: {db_path}")
        sys.exit(1)

    conn = sqlite3.connect(str(db_path))
    conn.row_factory = sqlite3.Row
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA synchronous=NORMAL")

    # Count uncoordinated
    total_memories = conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    total_coords = conn.execute("SELECT COUNT(*) FROM holographic_coords").fetchone()[0]
    uncoordinated = total_memories - total_coords

    log.info(f"Corpus: {total_memories:,} memories, {total_coords:,} with coords, {uncoordinated:,} remaining")

    if args.dry_run:
        log.info("Dry run — exiting")
        conn.close()
        return

    if uncoordinated == 0:
        log.info("All memories already have holographic coordinates!")
        conn.close()
        return

    encoder = CoordinateEncoder()
    target = args.limit if args.limit > 0 else uncoordinated

    total_encoded = 0
    total_errors = 0
    offset = 0
    start = time.perf_counter()

    while total_encoded < target:
        remaining = target - total_encoded
        page_limit = min(args.batch_size, remaining)

        rows = conn.execute(
            """SELECT m.id, m.title, SUBSTR(m.content, 1, 2000) as content,
                      m.memory_type, m.importance, m.emotional_valence,
                      m.access_count, m.neuro_score, m.galactic_distance,
                      m.created_at, m.is_protected
               FROM memories m
               WHERE m.id NOT IN (SELECT memory_id FROM holographic_coords)
               ORDER BY m.importance DESC
               LIMIT ? OFFSET ?""",
            (page_limit, offset),
        ).fetchall()

        if not rows:
            break

        # Build memory dicts for encoder
        mem_dicts = []
        mem_ids = []
        for row in rows:
            tags_rows = conn.execute(
                "SELECT tag FROM tags WHERE memory_id = ?", (row["id"],)
            ).fetchall()
            tags = [r[0] if isinstance(r, tuple) else r["tag"] for r in tags_rows]

            mem_dicts.append({
                "id": row["id"],
                "title": row["title"] or "",
                "content": row["content"] or "",
                "memory_type": row["memory_type"] or "SHORT_TERM",
                "importance": row["importance"] or 0.5,
                "emotional_valence": row["emotional_valence"] or 0.0,
                "access_count": row["access_count"] or 0,
                "neuro_score": row["neuro_score"] or 0.5,
                "galactic_distance": row["galactic_distance"] or 0.5,
                "created_at": row["created_at"] or "",
                "is_protected": bool(row["is_protected"]),
                "tags": tags,
                "metadata": {},
            })
            mem_ids.append(row["id"])

        # Batch encode (uses Rust Rayon when available)
        try:
            coords = encoder.encode_batch(mem_dicts)

            for mid, coord in zip(mem_ids, coords):
                try:
                    conn.execute(
                        """INSERT OR REPLACE INTO holographic_coords
                           (memory_id, x, y, z, w, v)
                           VALUES (?, ?, ?, ?, ?, ?)""",
                        (mid, coord.x, coord.y, coord.z, coord.w, coord.v),
                    )
                    total_encoded += 1
                except Exception as e:
                    total_errors += 1
                    if total_errors <= 5:
                        log.warning(f"Store error for {mid[:8]}: {e}")

            conn.commit()

        except Exception as e:
            log.error(f"Batch encode error: {e}")
            total_errors += len(mem_dicts)

        elapsed = time.perf_counter() - start
        rate = total_encoded / elapsed if elapsed > 0 else 0
        pct = total_encoded / target * 100
        log.info(
            f"Progress: {total_encoded:,}/{target:,} ({pct:.1f}%) | "
            f"{rate:.1f} mem/s | {elapsed:.0f}s elapsed | {total_errors} errors"
        )

        offset += page_limit

    elapsed = time.perf_counter() - start
    final_coords = conn.execute("SELECT COUNT(*) FROM holographic_coords").fetchone()[0]

    log.info(f"\n{'='*60}")
    log.info("Batch holographic coordinate assignment complete")
    log.info(f"  Encoded: {total_encoded:,}")
    log.info(f"  Errors: {total_errors:,}")
    if elapsed > 0:
        log.info(f"  Duration: {elapsed:.1f}s ({total_encoded / elapsed:.1f} mem/s)")
    log.info(f"  Total coords: {final_coords:,} / {total_memories:,} ({final_coords/total_memories*100:.1f}%)")

    conn.close()


if __name__ == "__main__":
    main()
