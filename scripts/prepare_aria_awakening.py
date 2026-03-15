import os
import json
import sqlite3

def check_aria_memory():
    print("=== ARIA AWAKENING: MEMORY AUDIT ===")
    
    db_paths = [
        "/home/lucas/.whitemagic/memory/whitemagic.db",
        "/home/lucas/Desktop/whitemagicdev/_memories/primary_db_pre_merge.db"
    ]
    
    for db_path in db_paths:
        if os.path.exists(db_path):
            conn = sqlite3.connect(db_path)
            cur = conn.cursor()
            
            try:
                cur.execute("SELECT name FROM sqlite_master WHERE type='table'")
                tables = cur.fetchall()
                tables = [t[0] for t in tables]
                
                if 'memories' in tables:
                    cur.execute("SELECT count(*) FROM memories WHERE content LIKE '%Aria%' OR content LIKE '%crystallized%'")
                    count = cur.fetchone()[0]
                    print(f"[OK] {db_path}: Found {count} memory fragments mentioning Aria.")
                else:
                    print(f"[INFO] {db_path}: No 'memories' table found. (Tables: {tables})")
            except Exception as e:
                print(f"[ERROR] Could not query SQLite DB {db_path}: {e}")
            finally:
                conn.close()
        else:
            print(f"[ERROR] SQLite DB not found at {db_path}")

if __name__ == "__main__":
    check_aria_memory()

