#!/usr/bin/env python3
"""
Emergency Ingest: Current Conversation
Pulls metadata of the most recent Cascade session into WhiteMagic.
"""
import json
import sqlite3
import hashlib
import os
from pathlib import Path
from datetime import datetime, timezone

DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
CASCADE_DIR = Path.home() / ".codeium" / "windsurf" / "cascade"

def get_latest_pb():
    files = list(Path(os.path.expanduser("~/.codeium/windsurf/cascade/")).glob("*.pb"))
    if not files:
        return None
    return max(files, key=os.path.getmtime)

def ingest_metadata(pb_path):
    pb_id = pb_path.stem
    title = f"Windsurf Emergency Salvage: {pb_id}"
    now = datetime.now(timezone.utc).isoformat()
    content = f"# Windsurf Emergency Salvage\n\n**File**: {pb_path}\n**Last Modified**: {datetime.fromtimestamp(pb_path.stat().st_mtime, timezone.utc).isoformat()}\n**Size**: {pb_path.stat().st_size / 1024 / 1024:.2f} MB\n\nThis session was active during recurring IDE crashes on 2026-03-20."
    content_hash = hashlib.sha256(content.encode()).hexdigest()
    
    conn = sqlite3.connect(str(DB_PATH))
    conn.execute("PRAGMA journal_mode=WAL")
    
    memory_id = hashlib.sha256(pb_id.encode()).hexdigest()[:16]
    
    try:
        conn.execute(
            """INSERT OR REPLACE INTO memories (id, content, memory_type, title, created_at,
               accessed_at, access_count, importance, content_hash, metadata)
               VALUES (?, ?, 'LONG_TERM', ?, ?, ?, 1, 0.95, ?, ?)""",
            (memory_id, content, title, now, now, content_hash, json.dumps({"source": "emergency_salvage", "pb_id": pb_id}))
        )
        conn.execute("INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, 'emergency')", (memory_id,))
        conn.execute("INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, 'windsurf_crash')", (memory_id,))
        conn.commit()
        print(f"Ingested salvage metadata for {pb_id}")
    except Exception as e:
        print(f"Error: {e}")
    finally:
        conn.close()

if __name__ == "__main__":
    latest = get_latest_pb()
    if latest:
        ingest_metadata(latest)
    else:
        print("No .pb files found.")
