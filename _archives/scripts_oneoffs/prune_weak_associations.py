#!/usr/bin/env python3
"""Prune weak and orphaned associations from the memory graph.

Usage:
    python scripts/prune_weak_associations.py                # default threshold 0.3
    python scripts/prune_weak_associations.py --threshold 0.2
    python scripts/prune_weak_associations.py --dry-run      # preview only
"""
from __future__ import annotations

import argparse
import sys
from pathlib import Path

# Ensure project root on path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))


def main() -> None:
    parser = argparse.ArgumentParser(description="Prune weak associations from the Data Sea")
    parser.add_argument(
        "--threshold", type=float, default=0.3,
        help="Minimum association strength to keep (default: 0.3)",
    )
    parser.add_argument(
        "--dry-run", action="store_true",
        help="Preview what would be pruned without making changes",
    )
    args = parser.parse_args()

    from whitemagic.core.memory.unified import get_unified_memory

    um = get_unified_memory()
    backend = um.backend

    if args.dry_run:
        print(f"\n🔍 Dry-run: previewing associations below {args.threshold} strength\n")
        with backend.pool.connection() as conn:
            total = conn.execute("SELECT COUNT(*) FROM associations").fetchone()[0]
            weak = conn.execute(
                "SELECT COUNT(*) FROM associations WHERE strength < ?",
                (args.threshold,),
            ).fetchone()[0]
            orphaned = conn.execute("""
                SELECT COUNT(*) FROM associations
                WHERE source_id NOT IN (SELECT id FROM memories)
                   OR target_id NOT IN (SELECT id FROM memories)
            """).fetchone()[0]

            # Strength distribution
            buckets = conn.execute("""
                SELECT
                    CASE
                        WHEN strength < 0.1 THEN '0.0-0.1'
                        WHEN strength < 0.2 THEN '0.1-0.2'
                        WHEN strength < 0.3 THEN '0.2-0.3'
                        WHEN strength < 0.5 THEN '0.3-0.5'
                        WHEN strength < 0.7 THEN '0.5-0.7'
                        ELSE '0.7-1.0'
                    END as bucket,
                    COUNT(*) as cnt
                FROM associations
                GROUP BY bucket
                ORDER BY bucket
            """).fetchall()

        print(f"  Total associations: {total:,}")
        print(f"  Orphaned (dead refs): {orphaned:,}")
        print(f"  Below threshold ({args.threshold}): {weak:,}")
        print(f"  Would remain: {total - weak - orphaned:,}")
        print("\n  Strength distribution:")
        for bucket, cnt in buckets:
            marker = " ← prune" if float(bucket.split("-")[0]) < args.threshold else ""
            print(f"    {bucket}: {cnt:>8,}{marker}")
        print("\n  (Use without --dry-run to execute)")
        return

    print(f"\n✂️  Pruning associations below {args.threshold} strength...\n")
    result = backend.prune_associations(min_strength=args.threshold)

    print(f"  Before:    {result['total_before']:,} associations")
    print(f"  Orphaned:  {result['orphaned_pruned']:,} removed")
    print(f"  Weak:      {result['weak_pruned']:,} removed")
    print(f"  After:     {result['remaining']:,} associations")
    print(f"  DB size:   {result['size_before_mb']:.1f} MB → {result['size_after_mb']:.1f} MB "
          f"(Δ {result['size_delta_mb']:.1f} MB)")
    print("\n✅ Done.\n")


if __name__ == "__main__":
    main()
