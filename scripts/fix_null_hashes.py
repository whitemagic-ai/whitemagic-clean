#!/usr/bin/env python3
"""
Fix for IL004: Calculate and populate missing content_hash values.
"""
import sqlite3
import hashlib
from pathlib import Path

DB_PATH = Path.home() / ".whitemagic/memory/whitemagic.db"

def fix_null_hashes():
    if not DB_PATH.exists():
        print(f"DB not found: {DB_PATH}")
        return

    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()

    # Find memories with NULL content_hash
    cursor.execute("SELECT id, content FROM memories WHERE content_hash IS NULL")
    rows = cursor.fetchall()
    
    print(f"Found {len(rows)} memories with NULL content_hash.")
    
    fixed = 0
    for row in rows:
        content = row["content"] or ""
        # Calculate hash
        chash = hashlib.sha256(content.encode("utf-8")).hexdigest()
        
        # Update
        cursor.execute("UPDATE memories SET content_hash = ? WHERE id = ?", (chash, row["id"]))
        fixed += 1
        
    conn.commit()
    conn.close()
    print(f"Fixed {fixed} memories.")

if __name__ == "__main__":
    fix_null_hashes()
