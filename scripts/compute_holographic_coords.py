#!/usr/bin/env python3
"""Compute holographic coordinates for all memories."""
import json
import sqlite3
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

try:
    from whitemagic.config.paths import DB_PATH
    
    conn = sqlite3.connect(str(DB_PATH))
    cursor = conn.cursor()
    
    # Get memories without coordinates
    cursor.execute("""
        SELECT id, importance, emotional_valence, neuro_score, 
               novelty_score, galactic_distance 
        FROM memories 
        WHERE holographic_coords IS NULL
        LIMIT 1000
    """)
    
    memories = cursor.fetchall()
    print(f"Computing coordinates for {len(memories)} memories...")
    
    computed = 0
    for mem_id, importance, valence, neuro, novelty, distance in memories:
        try:
            # 5D holographic coordinates
            coords = {
                "importance": importance or 0.5,
                "valence": valence or 0.0,
                "neuro": neuro or 1.0,
                "novelty": novelty or 1.0,
                "distance": distance or 0.0,
            }
            
            coords_json = json.dumps(coords)
            
            cursor.execute(
                "UPDATE memories SET holographic_coords = ? WHERE id = ?",
                (coords_json, mem_id)
            )
            
            computed += 1
            if computed % 100 == 0:
                conn.commit()
                print(f"  Progress: {computed}/{len(memories)}")
                
        except Exception as e:
            print(f"  Error on {mem_id[:8]}: {e}")
            continue
    
    conn.commit()
    conn.close()
    
    print(f"✅ Computed coordinates for {computed} memories")
    
except Exception as e:
    print(f"⚠️  Coordinate computation: {e}")
