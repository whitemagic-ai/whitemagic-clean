
import sqlite3
import sys
import json
import uuid
from datetime import datetime
from pathlib import Path

DB_PATH = Path("staging/project_memory/whitemagic.db")

def seed_db(jsonl_path):
    print(f"🌱 Seeding database from {jsonl_path}...")
    
    if not DB_PATH.exists():
        print(f"❌ Database not found at {DB_PATH}")
        return

    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    
    count = 0
    skipped = 0
    
    cursor.execute("SELECT content FROM memories")
    existing_patterns = {row[0] for row in cursor.fetchall()}
    print(f"   Loaded {len(existing_patterns)} existing patterns for deduplication.")
    
    batch = []
    
    with open(jsonl_path, 'r') as f:
        for line in f:
            try:
                data = json.loads(line)
                pattern = data.get('pattern')
                
                if not pattern or pattern in existing_patterns:
                    skipped += 1
                    continue
                
                existing_patterns.add(pattern)
                
                memory_id = str(uuid.uuid4())
                now = datetime.now().isoformat()
                
                batch.append((
                    memory_id, 
                    pattern, 
                    pattern, 
                    data.get('domain', 'unknown'),
                    now, 
                    now,
                    data.get('confidence', 1.0),
                    1.0, 
                    json.dumps(data)
                ))
                
                count += 1
                if len(batch) >= 1000:
                    cursor.executemany("""
                        INSERT INTO memories (
                            id, content, title, memory_type, 
                            created_at, accessed_at, 
                            neuro_score, novelty_score, 
                            metadata
                        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
                    """, batch)
                    batch = []
                    print(f"   Inserted {count} memories...", end='\r')
                    
            except Exception as e:
                print(f"❌ Error inserting line: {e}")
                
    if batch:
        cursor.executemany("""
            INSERT INTO memories (
                id, content, title, memory_type, 
                created_at, accessed_at, 
                neuro_score, novelty_score, 
                metadata
            ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
        """, batch)
        
    conn.commit()
    conn.close()
    
    print(f"\n✅ Seeding complete given {jsonl_path}.")
    print(f"   Inserted: {count}")
    print(f"   Skipped (Duplicate): {skipped}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: seed_memories.py <jsonl_file>")
        sys.exit(1)
        
    seed_db(sys.argv[1])
