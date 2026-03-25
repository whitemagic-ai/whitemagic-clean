
import json
import sqlite3
import uuid
import datetime

DB_PATH = "staging/project_memory/whitemagic.db"
JSON_PATH = "staging/project_memory/docs/archive/Tools/WINDSURF_TRANSFER_KIT/test_wisdom.json"

def main():
    print(f"Loading wisdom from {JSON_PATH}...")
    with open(JSON_PATH, 'r') as f:
        data = json.load(f)
    
    collection = data.get("wisdom_collection", [])
    print(f"Found {len(collection)} items to ingest.")
    
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    
    ingested_count = 0
    skipped_count = 0
    
    for item in collection:
        content = item.get("content", "")
        filepath = item.get("file", "unknown")
        created_at = item.get("date")
        
        # Heuristics for title
        title = filepath
        if content.startswith("# "):
            title = content.split("\n")[0].replace("# ", "").strip()
        elif "title: " in content:
             for line in content.split("\n"):
                 if line.startswith("title: "):
                     title = line.replace("title: ", "").strip()
                     break
        
        # Tags to metadata
        tags = item.get("tags", [])
        metadata = {
            "source": item.get("source"),
            "original_file": filepath,
            "tags": tags,
            "ingested_from": "test_wisdom.json",
            "ingested_at": datetime.datetime.now().isoformat()
        }
        
        # Generate ID (deterministic if possible, or random)
        # Using hash of file path to avoid dupes if we run again
        mem_id = str(uuid.uuid5(uuid.NAMESPACE_DNS, filepath))
        
        # Determine type
        mem_type = "insight"
        if "session" in filepath.lower():
            mem_type = "session"
        elif "short_term" in filepath.lower():
            mem_type = "short_term"
        elif "long_term" in filepath.lower():
            mem_type = "long_term"
            
        try:
            cursor.execute("""
                INSERT OR IGNORE INTO memories (
                    id, content, memory_type, created_at, 
                    metadata, title, 
                    neuro_score, novelty_score, importance
                ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)
            """, (
                mem_id, 
                content, 
                mem_type, 
                created_at, 
                json.dumps(metadata), 
                title,
                1.5, # Boost neuro_score for recovered wisdom
                1.0, 
                2.0  # Importance
            ))
            
            if cursor.rowcount > 0:
                ingested_count += 1
            else:
                skipped_count += 1
                
        except Exception as e:
            print(f"Error inserting {filepath}: {e}")
            
    conn.commit()
    conn.close()
    
    print("-" * 30)
    print("Ingestion complete.")
    print(f"Ingested: {ingested_count}")
    print(f"Skipped (Duplicate): {skipped_count}")

if __name__ == "__main__":
    main()
