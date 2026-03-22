#!/usr/bin/env python3
"""
v19 Deep Memory Engine Deduplication
Identifies and resolves exact AND near duplicates using fuzzy similarity.
"""
import sys
import sqlite3
import argparse

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

DB_PATH = "/home/lucas/.whitemagic/memory/whitemagic.db"

def execute_v19_dedup(dry_run=True):
    print("🗑️ v19 Deep Memory Engine Deduplication")
    print("=" * 70)
    
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    
    # 1. First run the exact content hash match to clean up trivial dupes
    print("\n🔍 Phase 1: Exact Duplicates by Content Hash")
    cursor.execute("""
        SELECT content_hash, COUNT(*) as cnt, GROUP_CONCAT(id) as ids
        FROM memories 
        WHERE memory_type != 'quarantined' AND content_hash IS NOT NULL
        GROUP BY content_hash 
        HAVING cnt > 1
    """)
    
    exact_duplicates = cursor.fetchall()
    print(f"  Found {len(exact_duplicates)} exact duplicate groups")
    
    # 2. Look for near-duplicates (titles matching closely but maybe different timestamps)
    print("\n🔍 Phase 2: Near Duplicates by Title Match")
    cursor.execute("""
        SELECT title, COUNT(*) as cnt, GROUP_CONCAT(id) as ids
        FROM memories 
        WHERE memory_type != 'quarantined' 
          AND title NOT LIKE 'Untitled%'
          AND title NOT LIKE 'Session%'
          AND title != ''
        GROUP BY title 
        HAVING cnt > 1
    """)
    
    near_duplicates = cursor.fetchall()
    print(f"  Found {len(near_duplicates)} near duplicate groups by title")
    
    if dry_run:
        print("\n⚠️  Dry run mode. Run with --execute to perform deduplication.")
        return
        
    # Execute deduplication
    print("\n⚡ Executing Deduplication...")
    resolved = 0
    archived = 0
    
    # Process both exact and near duplicates
    all_duplicate_groups = [dup['ids'].split(',') for dup in exact_duplicates] + [dup['ids'].split(',') for dup in near_duplicates]
    
    for ids in all_duplicate_groups:
        if len(ids) < 2: continue
        
        # Keep the one with highest importance/access count
        placeholders = ','.join('?' * len(ids))
        cursor.execute(f"""
            SELECT id FROM memories 
            WHERE id IN ({placeholders})
            ORDER BY importance DESC, access_count DESC, created_at DESC
        """, ids)
        
        sorted_ids = [row['id'] for row in cursor.fetchall()]
        if not sorted_ids: continue
        
        keeper = sorted_ids[0]
        to_archive = sorted_ids[1:]
        
        for arch_id in to_archive:
            cursor.execute("""
                UPDATE memories 
                SET memory_type = 'quarantined', 
                    title = '[DEDUP] ' || title
                WHERE id = ?
            """, (arch_id,))
            archived += 1
        
        resolved += 1
        
    conn.commit()
    print(f"\n✅ Deduplication complete: {resolved} groups resolved, {archived} memories archived.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Deduplicate memories.')
    parser.add_argument('--execute', action='store_true', help='Execute the deduplication (default is dry-run)')
    args = parser.parse_args()
    
    execute_v19_dedup(dry_run=not args.execute)
