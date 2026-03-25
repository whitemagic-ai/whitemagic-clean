#!/usr/bin/env python3
"""
Galactic Sweep - Tag all existing memories with retention scores + galactic distance.

This is a one-time (or periodic) migration script that:
  1. Loads every memory from the Data Sea (SQLite)
  2. Evaluates each with the multi-signal RetentionEngine
  3. Computes galactic distance (0.0=core, 1.0=edge)
  4. Persists scores back to DB
  5. Prints a detailed report

Usage:
    python scripts/galactic_sweep.py
    python scripts/galactic_sweep.py --dry-run   # Preview only, no DB writes
"""

import argparse
import sys
import os
import time

# Ensure repo root is on path
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

# Silence init noise
os.environ["WM_SILENT_INIT"] = "1"


def main():
    parser = argparse.ArgumentParser(description="Galactic Sweep: tag all memories with retention + distance")
    parser.add_argument("--dry-run", action="store_true", help="Preview only, no DB writes")
    parser.add_argument("--batch-size", type=int, default=500, help="Batch size for DB updates")
    args = parser.parse_args()

    print("🌌 Galactic Sweep — Mapping the Data Sea")
    print("=" * 60)

    from whitemagic.core.memory.galactic_map import get_galactic_map, classify_zone
    from whitemagic.core.memory.mindful_forgetting import get_retention_engine
    from whitemagic.core.memory.unified import get_unified_memory

    um = get_unified_memory()
    retention = get_retention_engine()
    gmap = get_galactic_map()

    stats = um.get_stats()
    print(f"📊 Database: {stats['total_memories']} memories, {stats.get('db_size_kb', '?')} KB")
    print(f"📊 Types: {stats.get('by_type', {})}")
    print()

    if args.dry_run:
        print("🔍 DRY RUN — no changes will be written to the database")
        print()

        # Load all memories
        all_mems = um.backend.list_recent(limit=50000)
        from whitemagic.core.memory.galactic_map import GalacticZone
        zone_counts = {z.value: 0 for z in GalacticZone}
        total_ret = 0.0
        total_dist = 0.0

        for mem in all_mems:
            verdict = retention.evaluate(mem)
            distance = gmap.compute_distance(mem, retention_score=verdict.score)
            zone = classify_zone(distance)
            zone_counts[zone.value] += 1
            total_ret += verdict.score
            total_dist += distance

            # Print first few
            if all_mems.index(mem) < 10:
                title = (mem.title or str(mem.content)[:40]).strip()
                print(
                    f"  [{zone.value:>10}] dist={distance:.3f} ret={verdict.score:.3f} "
                    f"neuro={mem.neuro_score:.2f} imp={mem.importance:.2f} "
                    f"| {title}"
                )

        n = max(len(all_mems), 1)
        print()
        print("📊 Zone Distribution (preview):")
        for zone_name, count in zone_counts.items():
            pct = count / n * 100
            bar = "█" * int(pct / 2)
            print(f"  {zone_name:>12}: {count:5d} ({pct:5.1f}%) {bar}")

        print(f"\n  avg_retention = {total_ret / n:.4f}")
        print(f"  avg_distance  = {total_dist / n:.4f}")
        print("\n✅ Dry run complete. Run without --dry-run to persist.")
        return

    # Full sweep
    start = time.perf_counter()
    report = gmap.full_sweep(batch_size=args.batch_size)
    elapsed = time.perf_counter() - start

    print("✅ Galactic Sweep Complete!")
    print(f"   Memories mapped: {report.memories_updated}/{report.total_memories}")
    print(f"   Duration: {elapsed:.2f}s")
    print()
    print("📊 Zone Distribution:")
    n = max(report.total_memories, 1)
    for zone_name, count in report.zone_counts.items():
        pct = count / n * 100
        bar = "█" * int(pct / 2)
        print(f"  {zone_name:>12}: {count:5d} ({pct:5.1f}%) {bar}")

    print()
    print(f"   🌟 Core (active spotlight): {report.core_count}")
    print(f"   🔭 Far Edge (deep archive): {report.edge_count}")
    print(f"   🛡️  Protected (pinned):      {report.protected_count}")
    print(f"   📈 Avg retention: {report.avg_retention:.4f}")
    print(f"   📐 Avg distance:  {report.avg_distance:.4f}")


if __name__ == "__main__":
    main()
