#!/usr/bin/env python3
"""Generate trimmed starter DB for v20 deployment."""

import sqlite3
import os

def generate_starter_db(source_path: str, target_path: str):
    """Create minimal starter DB with only core schema and essential data."""
    
    # Remove existing target
    if os.path.exists(target_path):
        os.remove(target_path)
    
    # Connect to source and create target
    source = sqlite3.connect(source_path)
    target = sqlite3.connect(target_path)
    
    # Get schema
    schema = source.execute(
        "SELECT sql FROM sqlite_master WHERE type='table' AND sql IS NOT NULL"
    ).fetchall()
    
    # Create tables in target
    for (sql,) in schema:
        target.execute(sql)
    
    # Copy essential core data only (not personal memories)
    # Only copy: core rules, architecture docs, system configs
    core_tags = ['core_rule', 'architecture', 'dharma', 'sutra', 'config', 'system_map']
    
    # Copy memories with core tags (limited to 1000)
    placeholders = ','.join('?' * len(core_tags))
    core_memories = source.execute(f"""
        SELECT DISTINCT m.* FROM memories m
        JOIN tags t ON m.id = t.memory_id
        WHERE t.tag IN ({placeholders})
        AND m.memory_type != 'quarantined'
        LIMIT 1000
    """, core_tags).fetchall()
    
    if core_memories:
        columns = [desc[0] for desc in source.execute(
            "SELECT * FROM memories LIMIT 1"
        ).description]
        cols_str = ','.join(columns)
        placeholders = ','.join('?' * len(columns))
        
        target.executemany(
            f"INSERT INTO memories ({cols_str}) VALUES ({placeholders})",
            core_memories
        )
    
    # Copy holographic coords for core memories
    mem_ids = [m[0] for m in core_memories]
    if mem_ids:
        placeholders = ','.join('?' * len(mem_ids))
        coords = source.execute(
            f"SELECT * FROM holographic_coords WHERE memory_id IN ({placeholders})",
            mem_ids
        ).fetchall()
        
        if coords:
            cols = [d[0] for d in source.execute(
                "SELECT * FROM holographic_coords LIMIT 1"
            ).description]
            target.executemany(
                f"INSERT INTO holographic_coords ({','.join(cols)}) VALUES ({','.join('?'*len(cols))})",
                coords
            )
    
    # Copy associations between core memories only
    if mem_ids:
        placeholders = ','.join('?' * len(mem_ids))
        assocs = source.execute(f"""
            SELECT * FROM associations 
            WHERE source_id IN ({placeholders}) AND target_id IN ({placeholders})
            AND relation_type != 'associated_with'
        """, mem_ids + mem_ids).fetchall()
        
        if assocs:
            cols = [d[0] for d in source.execute("SELECT * FROM associations LIMIT 1").description]
            target.executemany(
                f"INSERT INTO associations ({','.join(cols)}) VALUES ({','.join('?'*len(cols))})",
                assocs
            )
    
    # Copy tags for core memories
    if mem_ids:
        placeholders = ','.join('?' * len(mem_ids))
        tags = source.execute(
            f"SELECT * FROM tags WHERE memory_id IN ({placeholders})",
            mem_ids
        ).fetchall()
        
        if tags:
            cols = [d[0] for d in source.execute("SELECT * FROM tags LIMIT 1").description]
            target.executemany(
                f"INSERT INTO tags ({','.join(cols)}) VALUES ({','.join('?'*len(cols))})",
                tags
            )
    
    target.commit()
    source.close()
    target.close()
    
    # Report sizes
    orig_size = os.path.getsize(source_path) / (1024*1024)
    new_size = os.path.getsize(target_path) / (1024*1024)
    print("Starter DB generated:")
    print(f"  Original: {orig_size:.1f} MB")
    print(f"  Starter:  {new_size:.1f} MB ({new_size/orig_size*100:.1f}% of original)")
    print(f"  Memories: {len(core_memories)}")

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 3:
        print("Usage: generate_starter_db.py <source_db> <target_db>")
        sys.exit(1)
    generate_starter_db(sys.argv[1], sys.argv[2])
