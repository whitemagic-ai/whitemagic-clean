#!/usr/bin/env python3
"""Resolve content hash duplicates - IL004 campaign"""

import sys
import sqlite3
from pathlib import Path

# Add whitemagic to path
sys.path.insert(0, str(Path(__file__).parent.parent))

def resolve_duplicates():
    """Find and resolve all content hash duplicates"""
    
    db_path = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
    if not db_path.exists():
        print(f"❌ DB not found: {db_path}")
        return
    
    conn = sqlite3.connect(str(db_path))
    cursor = conn.cursor()
    
    # Find duplicate content hashes
    cursor.execute("""
        SELECT content_hash, COUNT(*) as cnt 
        FROM memories 
        WHERE memory_type != 'quarantined' AND content_hash IS NOT NULL
        GROUP BY content_hash 
        HAVING cnt > 1
        ORDER BY cnt DESC
    """)
    
    duplicate_hashes = cursor.fetchall()
    print(f"📊 Found {len(duplicate_hashes)} duplicate content hashes")
    
    if not duplicate_hashes:
        print("✅ No duplicates to resolve")
        conn.close()
        return
    
    total_duplicates = sum(cnt - 1 for _, cnt in duplicate_hashes)
    print(f"🎯 Will quarantine {total_duplicates} duplicate memories")
    
    quarantined_count = 0
    
    for content_hash, cnt in duplicate_hashes:
        # Get all memories with this hash
        cursor.execute("""
            SELECT id, title, importance, access_count, created_at,
                   (SELECT COUNT(*) FROM associations WHERE source_id = memories.id OR target_id = memories.id) as assoc_count
            FROM memories
            WHERE content_hash = ? AND memory_type != 'quarantined'
            ORDER BY 
                importance DESC,
                assoc_count DESC,
                access_count DESC,
                created_at DESC
        """, (content_hash,))
        
        memories = cursor.fetchall()
        
        if len(memories) <= 1:
            continue
        
        # Winner is the first (highest scored)
        winner_id = memories[0][0]
        
        # Quarantine losers
        for mem in memories[1:]:
            loser_id = mem[0]
            
            # Merge tags from loser to winner
            cursor.execute("""
                INSERT OR IGNORE INTO tags (memory_id, tag)
                SELECT ?, tag FROM tags WHERE memory_id = ?
            """, (winner_id, loser_id))
            
            # Repoint associations to winner
            cursor.execute("""
                UPDATE associations SET source_id = ? 
                WHERE source_id = ? AND target_id != ?
            """, (winner_id, loser_id, winner_id))
            
            cursor.execute("""
                UPDATE associations SET target_id = ? 
                WHERE target_id = ? AND source_id != ?
            """, (winner_id, loser_id, winner_id))
            
            # Remove self-loops
            cursor.execute("""
                DELETE FROM associations 
                WHERE source_id = ? AND target_id = ?
            """, (winner_id, winner_id))
            
            # Quarantine loser
            cursor.execute("""
                UPDATE memories 
                SET memory_type = 'quarantined'
                WHERE id = ?
            """, (loser_id,))
            
            # Add duplicate_of tag
            cursor.execute("""
                INSERT OR IGNORE INTO tags (memory_id, tag)
                VALUES (?, ?)
            """, (loser_id, f"duplicate_of:{winner_id}"))
            
            quarantined_count += 1
            
            if quarantined_count % 100 == 0:
                print(f"   ⏳ Quarantined {quarantined_count}/{total_duplicates}...")
    
    conn.commit()
    
    # Verify
    cursor.execute("""
        SELECT COUNT(*) FROM (
            SELECT content_hash, COUNT(*) as cnt 
            FROM memories 
            WHERE memory_type != 'quarantined' AND content_hash IS NOT NULL
            GROUP BY content_hash 
            HAVING cnt > 1
        )
    """)
    remaining = cursor.fetchone()[0]
    
    cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'")
    active_count = cursor.fetchone()[0]
    
    conn.close()
    
    print("\n✅ Deduplication complete!")
    print(f"   📦 Quarantined: {quarantined_count} duplicates")
    print(f"   📊 Active memories: {active_count}")
    print(f"   🎯 Remaining duplicates: {remaining}")
    
    if remaining == 0:
        print("\n🎖️  IL004 Victory Condition Met: Zero exact content duplicates remain")

if __name__ == "__main__":
    resolve_duplicates()
