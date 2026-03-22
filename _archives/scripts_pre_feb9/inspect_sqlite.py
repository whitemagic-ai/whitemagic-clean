
import sqlite3
import sys
import os

def inspect_db(db_path):
    print(f"--- Inspecting {os.path.basename(db_path)} ---")
    try:
        conn = sqlite3.connect(db_path)
        cursor = conn.cursor()
        
        # Get tables
        cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
        tables = cursor.fetchall()
        print(f"Tables: {[t[0] for t in tables]}")
        
        # Check ItemTable if present (VSCode/Windsurf usually stores state here)
        if ('ItemTable',) in tables:
            print("Scanning ItemTable keys for chat/history...")
            cursor.execute("SELECT key, value FROM ItemTable WHERE key LIKE '%chat%' OR key LIKE '%history%' OR key LIKE '%conversation%' LIMIT 20")
            rows = cursor.fetchall()
            for key, val in rows:
                print(f"Key: {key}")
                print(f"Value Preview: {str(val)[:100]}...")
                
        conn.close()
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 inspect_sqlite.py <db_path>")
        sys.exit(1)
    inspect_db(sys.argv[1])
