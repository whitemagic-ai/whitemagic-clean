#!/usr/bin/env python3
"""Quarantine Noise Memories — Operation Thousand Eyes, Objective 5.
Marks noise memories with memory_type='quarantined' and pushes
galactic_distance to 0.99 (far edge). No data is deleted.

Rescue phase protects WhiteMagic-authored content even if it was
mis-classified as deep_archive or scavenged.
"""
import os
import sqlite3
import sys

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")


def dry_run():
    """Show what would be quarantined without making changes."""
    conn = sqlite3.connect(DB_PATH)
    conn.execute("PRAGMA busy_timeout=5000")

    deep = conn.execute("SELECT COUNT(*) FROM memories WHERE memory_type = 'deep_archive'").fetchone()[0]
    scav_low = conn.execute("""
        SELECT COUNT(*) FROM memories
        WHERE memory_type = 'scavenged'
        AND (importance IS NULL OR importance < 0.5)
    """).fetchone()[0]
    bench = conn.execute("""
        SELECT COUNT(*) FROM memories
        WHERE title LIKE '%bench_t1%' OR title LIKE '%Benchmark test memory%'
    """).fetchone()[0]
    rescue_est = conn.execute("""
        SELECT COUNT(*) FROM memories
        WHERE memory_type IN ('deep_archive', 'scavenged')
        AND (importance > 0.7
             OR title LIKE '%WhiteMagic%'
             OR title LIKE '%Aria%'
             OR title LIKE '%strategy%'
             OR title LIKE '%roadmap%'
             OR title LIKE '%session%'
             OR title LIKE '%grimoire%')
    """).fetchone()[0]
    total = conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]

    print("=== DRY RUN — No changes will be made ===")
    print(f"  deep_archive to quarantine: {deep:,}")
    print(f"  low-importance scavenged:   {scav_low:,}")
    print(f"  benchmark junk:             {bench:,}")
    print(f"  estimated rescues:          ~{rescue_est:,}")
    print(f"  total memories:             {total:,}")
    print(f"\nNet quarantine estimate: ~{deep + scav_low + bench - rescue_est:,}")
    print("\nPass --apply to execute quarantine.")
    conn.close()


def quarantine():
    """Execute quarantine: mark noise, rescue valuable, push to far edge."""
    conn = sqlite3.connect(DB_PATH)
    conn.execute("PRAGMA journal_mode=WAL")
    conn.execute("PRAGMA busy_timeout=5000")

    # Phase 1: Quarantine deep_archive
    deep_count = conn.execute("""
        UPDATE memories
        SET memory_type = 'quarantined', galactic_distance = 0.99
        WHERE memory_type = 'deep_archive'
    """).rowcount
    print(f"  Phase 1: Quarantined {deep_count:,} deep_archive memories")

    # Phase 2: Quarantine low-importance scavenged
    scav_count = conn.execute("""
        UPDATE memories
        SET memory_type = 'quarantined', galactic_distance = 0.99
        WHERE memory_type = 'scavenged'
        AND (importance IS NULL OR importance < 0.5)
    """).rowcount
    print(f"  Phase 2: Quarantined {scav_count:,} low-importance scavenged memories")

    # Phase 3: Quarantine benchmark junk
    bench_count = conn.execute("""
        UPDATE memories
        SET memory_type = 'quarantined', galactic_distance = 0.99
        WHERE title LIKE '%bench_t1%' OR title LIKE '%Benchmark test memory%'
    """).rowcount
    print(f"  Phase 3: Quarantined {bench_count:,} benchmark junk memories")

    # Phase 4: Rescue valuable memories that were quarantined
    rescue_count = conn.execute("""
        UPDATE memories
        SET memory_type = 'LONG_TERM', galactic_distance = 0.3
        WHERE memory_type = 'quarantined'
        AND (importance > 0.7
             OR title LIKE '%WhiteMagic%'
             OR title LIKE '%Aria%'
             OR title LIKE '%strategy%'
             OR title LIKE '%roadmap%'
             OR title LIKE '%session%'
             OR title LIKE '%grimoire%'
             OR title LIKE '%consciousness%'
             OR title LIKE '%GAS%'
             OR title LIKE '%Phase%Implementation%')
    """).rowcount
    print(f"  Phase 4: Rescued {rescue_count:,} valuable memories from quarantine")

    conn.commit()

    # Stats
    total_q = conn.execute(
        "SELECT COUNT(*) FROM memories WHERE memory_type = 'quarantined'"
    ).fetchone()[0]
    total_active = conn.execute(
        "SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'"
    ).fetchone()[0]
    long_term = conn.execute(
        "SELECT COUNT(*) FROM memories WHERE memory_type = 'LONG_TERM'"
    ).fetchone()[0]
    print(f"\n  Final: {total_q:,} quarantined, {total_active:,} active ({long_term:,} LONG_TERM)")
    conn.close()


if __name__ == "__main__":
    if "--apply" in sys.argv:
        print("=== QUARANTINE NOISE — Applying ===")
        quarantine()
        print("\nDone. Noise memories marked as 'quarantined', galactic_distance=0.99.")
        print("Reverse with: UPDATE memories SET memory_type='deep_archive' WHERE memory_type='quarantined'")
    else:
        dry_run()
