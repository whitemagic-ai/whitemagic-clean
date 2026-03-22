#!/usr/bin/env python3
"""
v19 Deep Memory Engine Typed Edges Verification
Examines the association database and upgrades generic edges using LLM inference
to typed relationships where possible.
"""
import argparse
import sqlite3
import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.config.paths import DB_PATH


def execute_v19_typed_edges(dry_run=True):
    print("🕸️ v19 Typed Edges Resolution")
    print("=" * 70)

    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()

    # 1. Check current typed edge landscape
    print("\n🔍 Phase 1: Landscape Scan")
    cursor.execute("""
        SELECT relation_type, COUNT(*) as cnt
        FROM associations
        GROUP BY relation_type
        ORDER BY cnt DESC
    """)

    types = cursor.fetchall()
    total_edges = 0
    generic_edges = 0
    typed_edges = 0

    print("  Edge Distribution:")
    for row in types:
        r_type = row['relation_type']
        cnt = row['cnt']
        total_edges += cnt
        if r_type is None or r_type == 'associated_with':
            generic_edges += cnt
        else:
            typed_edges += cnt
        print(f"    - {r_type or 'NULL'}: {cnt}")

    print(f"\n  Total: {total_edges}")
    print(f"  Generic: {generic_edges} ({(generic_edges/max(1, total_edges))*100:.1f}%)")
    print(f"  Typed: {typed_edges} ({(typed_edges/max(1, total_edges))*100:.1f}%)")

    if generic_edges == 0:
        print("\n✅ All edges are typed. Nothing to do.")
        return

    if dry_run:
        print("\n⚠️  Dry run mode. Run with --execute to perform edge typing.")
        return

    # Execute Edge Typing (Simple heuristical pass for now)
    print("\n⚡ Executing Heuristic Edge Typing...")

    cursor.execute("""
        UPDATE associations
        SET relation_type = 'references'
        WHERE relation_type = 'associated_with' OR relation_type IS NULL
        AND id IN (
            SELECT a.id FROM associations a
            JOIN memories m1 ON a.source_id = m1.id
            JOIN memories m2 ON a.target_id = m2.id
            WHERE m1.content LIKE '%' || m2.id || '%'
        )
    """)
    refs_updated = cursor.rowcount

    conn.commit()
    print(f"\n✅ Edge Typing complete: {refs_updated} generic edges upgraded to 'references'.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Deduplicate memories.')
    parser.add_argument('--execute', action='store_true', help='Execute the edge typing (default is dry-run)')
    args = parser.parse_args()

    execute_v19_typed_edges(dry_run=not args.execute)
