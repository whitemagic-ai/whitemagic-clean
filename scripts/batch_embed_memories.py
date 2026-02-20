#!/usr/bin/env python3
"""Campaign 1: Batch Embed All Active Memories
================================================
Embeds all 8,498 active (non-quarantined) memories using
sentence-transformers (all-MiniLM-L6-v2, 384 dims).

Uses the existing EmbeddingEngine.index_memories() in batches,
with progress tracking and resume capability (skips already-cached).

Usage:
    scripts/wm scripts/batch_embed_memories.py              # Full run
    scripts/wm scripts/batch_embed_memories.py --batch 500  # Custom batch size
    scripts/wm scripts/batch_embed_memories.py --dry-run     # Count only
"""

import argparse
import os
import sqlite3
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")


def get_counts():
    """Get current embedding coverage stats."""
    conn = sqlite3.connect(DB_PATH)
    active = conn.execute(
        "SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'"
    ).fetchone()[0]
    total_embedded = conn.execute(
        "SELECT COUNT(*) FROM memory_embeddings"
    ).fetchone()[0]
    # Embeddings that belong to active memories
    active_embedded = conn.execute(
        """SELECT COUNT(*) FROM memory_embeddings
           WHERE memory_id IN (SELECT id FROM memories WHERE memory_type != 'quarantined')"""
    ).fetchone()[0]
    # Embeddings for quarantined memories (orphans we can skip)
    orphan_embedded = total_embedded - active_embedded
    remaining = active - active_embedded
    conn.close()
    return {
        "active_memories": active,
        "total_embedded": total_embedded,
        "active_embedded": active_embedded,
        "orphan_embedded": orphan_embedded,
        "remaining": remaining,
        "coverage_pct": round(active_embedded / max(active, 1) * 100, 1),
    }


def batch_embed(batch_size: int = 256, dry_run: bool = False):
    """Embed all active memories in batches."""
    counts = get_counts()
    print("=" * 60)
    print("  Campaign 1: Batch Embed All Active Memories")
    print("=" * 60)
    print(f"  Active memories:    {counts['active_memories']:,}")
    print(f"  Already embedded:   {counts['active_embedded']:,}")
    print(f"  Orphan embeddings:  {counts['orphan_embedded']:,}")
    print(f"  Remaining:          {counts['remaining']:,}")
    print(f"  Current coverage:   {counts['coverage_pct']}%")
    print(f"  Batch size:         {batch_size}")
    print()

    if counts["remaining"] == 0:
        print("✅ All active memories already embedded! Nothing to do.")
        return counts

    if dry_run:
        est_time = counts["remaining"] / 200  # ~200 embeds/sec on GPU
        print(f"  Estimated time: ~{est_time:.0f}s ({est_time/60:.1f} min)")
        print("  (dry run — pass without --dry-run to execute)")
        return counts

    # Load embedding engine
    print("Loading sentence-transformers model...")
    t0 = time.time()
    from whitemagic.core.memory.embeddings import get_embedding_engine
    engine = get_embedding_engine()

    if not engine.available():
        print("❌ sentence-transformers not available. Install with:")
        print("   make install-heavy")
        return counts

    model_load_time = time.time() - t0
    print(f"  Model loaded in {model_load_time:.1f}s")

    # Process in batches using index_memories with increasing limits
    total_embedded = 0
    batch_num = 0
    start_time = time.time()

    while True:
        batch_num += 1
        t_batch = time.time()

        result = engine.index_memories(
            memory_type=None,
            limit=batch_size,
            skip_cached=True,
        )

        indexed = result.get("indexed", 0)
        if indexed == 0:
            break

        total_embedded += indexed
        elapsed_batch = time.time() - t_batch
        elapsed_total = time.time() - start_time
        rate = total_embedded / elapsed_total if elapsed_total > 0 else 0

        # Progress
        current_counts = get_counts()
        pct = current_counts["coverage_pct"]
        remaining = current_counts["remaining"]

        print(
            f"  Batch {batch_num}: +{indexed} embedded "
            f"({elapsed_batch:.1f}s, {indexed/max(elapsed_batch,0.01):.0f}/s) | "
            f"Total: {total_embedded:,} | Coverage: {pct}% | "
            f"Remaining: {remaining:,} | Avg: {rate:.0f}/s"
        )

    elapsed = time.time() - start_time
    final = get_counts()

    print()
    print("=" * 60)
    print("  BATCH EMBEDDING COMPLETE")
    print("=" * 60)
    print(f"  Memories embedded:  {total_embedded:,}")
    print(f"  Total time:         {elapsed:.1f}s ({elapsed/60:.1f} min)")
    print(f"  Avg rate:           {total_embedded/max(elapsed,1):.0f} embeddings/sec")
    print(f"  Final coverage:     {final['coverage_pct']}%")
    print(f"  Active embedded:    {final['active_embedded']:,} / {final['active_memories']:,}")

    return final


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Batch embed all active memories")
    parser.add_argument("--batch", type=int, default=256, help="Batch size (default: 256)")
    parser.add_argument("--dry-run", action="store_true", help="Count only, don't embed")
    args = parser.parse_args()

    batch_embed(batch_size=args.batch, dry_run=args.dry_run)
