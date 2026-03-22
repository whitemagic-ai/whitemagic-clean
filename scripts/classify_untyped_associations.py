#!/usr/bin/env python3
"""Classify remaining untyped associations into semantic edge types.

Run: cd /home/lucas/Desktop/whitemagicdev && .venv/bin/python scripts/classify_untyped_associations.py --apply
"""

import re
import sqlite3
from pathlib import Path
from typing import Optional

PATTERNS = {
    r'\b(def|class|fn|impl|mod|struct|enum)\s+(\w+)\b': 'IMPLEMENTS',
    r'\bimport\s+(\w+)\b': 'IMPORTS',
    r'\bfrom\s+([\w.]+)\s+import\b': 'IMPORTS_FROM',
    r'([\w/]+\.(py|rs|zig|jl|ex|exs|go|mojo|hs|koka))': 'CONTAINS_FILE',
    r'\bREADME|CHANGELOG|LICENSE|VERSION\b': 'CONTAINS_DOC',
    r'\b(SELECT|INSERT|UPDATE|DELETE)\b.*\bFROM\s+(\w+)\b': 'QUERIES_TABLE',
    r'\bCREATE\s+TABLE\s+(\w+)\b': 'DEFINES_TABLE',
    r'\bmemory_id["\']?\s*[:=]\s*["\']?([a-f0-9]{8,})': 'REFERENCES_MEMORY',
    r'\b(VC\d+|campaigns?/V\d+)\b': 'PART_OF_CAMPAIGN',
    r'\b(gana_[\w_]+)\b': 'INVOKES_GANA',
    r'\b(test_|_test\.py|spec_|_spec\.rb)\b': 'HAS_TEST',
    r'\bpytest|unittest|test_\w+\b': 'TESTED_BY',
}


def get_untyped_count(db_path: str = "~/.whitemagic/memory/whitemagic.db") -> int:
    conn = sqlite3.connect(Path(db_path).expanduser())
    cursor = conn.cursor()
    cursor.execute("SELECT COUNT(*) FROM associations WHERE relation_type = 'associated_with'")
    count = cursor.fetchone()[0]
    conn.close()
    return count


def classify_by_pattern(content: str) -> Optional[str]:
    for pattern, edge_type in PATTERNS.items():
        if re.search(pattern, content, re.IGNORECASE):
            return edge_type
    return None


def classify_batch(batch_size: int = 1000, dry_run: bool = True) -> dict:
    db_path = Path("~/.whitemagic/memory/whitemagic.db").expanduser()
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    
    cursor.execute("""
        SELECT a.source_id, a.target_id, a.relation_type,
               m1.content as source_content, m2.content as target_content
        FROM associations a
        JOIN memories m1 ON a.source_id = m1.id
        JOIN memories m2 ON a.target_id = m2.id
        WHERE a.relation_type = 'associated_with'
        LIMIT ?
    """, (batch_size,))
    
    rows = cursor.fetchall()
    classifications = {'pattern_based': {}, 'untouched': []}
    updates = []
    
    for row in rows:
        source_id, target_id, relation_type, src_content, tgt_content = row
        
        src_pattern = classify_by_pattern(src_content or '')
        tgt_pattern = classify_by_pattern(tgt_content or '')
        
        if src_pattern or tgt_pattern:
            edge_type = tgt_pattern or src_pattern
            classifications['pattern_based'][edge_type] = classifications['pattern_based'].get(edge_type, 0) + 1
            updates.append((edge_type, source_id, target_id))
            continue
        
        classifications['untouched'].append((source_id, target_id))
    
    if not dry_run and updates:
        cursor.executemany(
            "UPDATE associations SET relation_type = ? WHERE source_id = ? AND target_id = ?",
            updates
        )
        conn.commit()
    
    conn.close()
    
    return {
        'processed': len(rows),
        'pattern_classified': len(updates),
        'pending_semantic': len(classifications['untouched']),
        'breakdown': classifications['pattern_based']
    }


def main():
    import argparse
    parser = argparse.ArgumentParser(description='Classify untyped associations')
    parser.add_argument('--batch-size', type=int, default=1000)
    parser.add_argument('--apply', action='store_true', help='Apply changes')
    args = parser.parse_args()
    
    untyped = get_untyped_count()
    print(f"Untyped associations remaining: {untyped:,}")
    
    if untyped == 0:
        print("All associations are already typed!")
        return
    
    print(f"\nProcessing batch of {args.batch_size:,}...")
    result = classify_batch(args.batch_size, dry_run=not args.apply)
    
    print("\nResults:")
    print(f"  Processed: {result['processed']:,}")
    print(f"  Pattern-classified: {result['pattern_classified']:,}")
    print(f"  Pending semantic: {result['pending_semantic']:,}")
    
    if result['breakdown']:
        print("\nPattern breakdown:")
        for edge_type, count in sorted(result['breakdown'].items(), key=lambda x: -x[1]):
            print(f"    {edge_type}: {count:,}")
    
    if not args.apply:
        print("\nDry run - no changes applied. Use --apply to commit.")
    else:
        remaining = untyped - result['pattern_classified']
        print(f"\nApplied! Remaining untyped: {remaining:,}")


if __name__ == "__main__":
    main()
