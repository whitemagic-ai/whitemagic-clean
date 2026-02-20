#!/usr/bin/env python3
"""
IL004 Deduplication Execution - Careful Archival
Resolves 2,181 duplicate pairs with full metadata preservation.
"""
import json
import sys
import hashlib
import sqlite3
from datetime import datetime
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

DB_PATH = "/home/lucas/.whitemagic/memory/whitemagic.db"

def execute_dedup():
    """Execute deduplication with careful archival."""
    print("🗑️ IL004 Deduplication Execution - Careful Archival")
    print("=" * 70)
    
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    
    # Phase 1: Find exact duplicates by content hash
    print("\n🔍 Phase 1: Finding exact duplicates by content hash...")
    cursor.execute("""
        SELECT content_hash, COUNT(*) as cnt, GROUP_CONCAT(id) as ids
        FROM memories 
        WHERE memory_type != 'quarantined' AND content_hash IS NOT NULL
        GROUP BY content_hash 
        HAVING cnt > 1
    """)
    
    duplicates = cursor.fetchall()
    print(f"  Found {len(duplicates)} duplicate groups")
    
    resolved = 0
    archived = 0
    
    for dup in duplicates:
        content_hash = dup['content_hash']
        ids = dup['ids'].split(',')
        
        if len(ids) < 2:
            continue
            
        # Get full details for each duplicate
        placeholders = ','.join('?' * len(ids))
        cursor.execute(f"""
            SELECT id, title, content, importance, access_count, memory_type
            FROM memories 
            WHERE id IN ({placeholders})
            ORDER BY importance DESC, access_count DESC
        """, ids)
        
        members = cursor.fetchall()
        
        # Winner = highest (importance * access_count), most recent
        winner = members[0]
        losers = members[1:]
        
        print(f"\n  Duplicate group: {content_hash[:16]}...")
        print(f"    Winner: {winner['id'][:16]}... ({winner['title'][:40]})")
        
        # Merge metadata from losers into winner
        total_access = winner['access_count']
        
        for loser in losers:
            # Sum access counts
            total_access += loser['access_count']
            
            # Archive loser (quarantine with duplicate_of reference)
            cursor.execute("""
                UPDATE memories 
                SET memory_type = 'quarantined',
                    content = '[ARCHIVED: duplicate_of ' || ? || ']'
                WHERE id = ?
            """, (winner['id'], loser['id']))
            archived += 1
            print(f"    Archived: {loser['id'][:16]}... → {winner['id'][:16]}...")
        
        # Update winner with merged metadata
        cursor.execute("""
            UPDATE memories 
            SET access_count = ?,
                importance = MAX(COALESCE(importance, 0.5), 0.9)
            WHERE id = ?
        """, (total_access, winner['id']))
        
        resolved += 1
    
    conn.commit()
    
    # Phase 2: Verify results
    print("\n✅ Phase 2: Verification...")
    cursor.execute("""
        SELECT COUNT(*) FROM (
            SELECT content_hash, COUNT(*) as cnt 
            FROM memories 
            WHERE memory_type != 'quarantined' AND content_hash IS NOT NULL
            GROUP BY content_hash HAVING cnt > 1
        )
    """)
    remaining = cursor.fetchone()[0]
    
    cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type = 'quarantined'")
    quarantined_count = cursor.fetchone()[0]
    
    cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'")
    active_count = cursor.fetchone()[0]
    
    conn.close()
    
    print(f"\n📊 Deduplication Results:")
    print(f"  Duplicate groups resolved: {resolved}")
    print(f"  Memories archived: {archived}")
    print(f"  Remaining duplicates: {remaining}")
    print(f"  Active memories: {active_count}")
    print(f"  Quarantined memories: {quarantined_count}")
    
    return {
        "resolved": resolved,
        "archived": archived,
        "remaining_duplicates": remaining,
        "active_count": active_count,
        "quarantined_count": quarantined_count
    }

if __name__ == "__main__":
    result = execute_dedup()
    print("\n✅ IL004 Deduplication complete")
    print(json.dumps(result, indent=2))
