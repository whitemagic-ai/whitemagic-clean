import sqlite3
import os
import shutil
import logging
import glob
import json
from pathlib import Path
from datetime import datetime

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger("MemoryConsolidator")

# Paths (all overridable via env; defaults are safe for OSS clones)
REPO_ROOT = Path(__file__).resolve().parent.parent

# Optional: a "master" DB snapshot to seed the super DB from (legacy migration helper).
MASTER_DB_SRC = Path(os.getenv("WM_MASTER_DB_SRC", "")).expanduser() if os.getenv("WM_MASTER_DB_SRC") else None

# Active runtime DB (defaults to WM_STATE_ROOT location).
try:
    from whitemagic.config.paths import DB_PATH as ACTIVE_DB_SRC  # type: ignore
except Exception:
    ACTIVE_DB_SRC = Path(os.path.expanduser("~/.whitemagic/memory/whitemagic.db"))

AG_LOGS_DIR = Path(os.getenv("WM_AG_LOGS_DIR", str(REPO_ROOT / "extracted_conversations"))).expanduser()
WS_LOGS_DIR = Path(os.getenv("WM_WS_LOGS_DIR", str(REPO_ROOT / "windsurf_conversations"))).expanduser()
MAGIC_BACKUP_DIR = Path(os.getenv("WM_MAGIC_BACKUP_DIR", str(REPO_ROOT / "magicbackup"))).expanduser()
SUPER_DB_PATH = Path(os.getenv("WM_SUPER_DB_PATH", str(ACTIVE_DB_SRC.parent / "whitemagic_super.db"))).expanduser()

def init_super_db():
    if MASTER_DB_SRC is None:
        logger.error("WM_MASTER_DB_SRC not set; cannot seed super DB.")
        return False
    
    logger.info(f"Creating Super DB from {MASTER_DB_SRC}...")
    if not MASTER_DB_SRC.exists():
        logger.error(f"Master DB not found at {MASTER_DB_SRC}")
        return False
    SUPER_DB_PATH.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(str(MASTER_DB_SRC), str(SUPER_DB_PATH))
    return True

def merge_active_db(conn):
    if not Path(ACTIVE_DB_SRC).exists():
        logger.warning(f"Active DB not found at {ACTIVE_DB_SRC}. Skipping merge.")
        return

    logger.info("Merging Active DB...")
    # Attach active DB
    try:
        conn.execute(f"ATTACH DATABASE '{Path(ACTIVE_DB_SRC)}' AS active")
        
        # SECURITY & INTEGRITY: Actually perform the merge!
        # Assuming 'memories' table exists in both and has compatible schema.
        # Use INSERT OR IGNORE to prevent duplicate ID crashes.
        conn.execute("INSERT OR IGNORE INTO main.memories SELECT * FROM active.memories")
        
        conn.commit()
        logger.info("Active DB merged successfully.")
    except Exception as e:
        logger.error(f"Failed to merge active DB: {e}")
    finally:
        try:
            conn.execute("DETACH DATABASE active")
        except Exception:
            pass

def ingest_text_file(conn, file_path, source_type, tags):
    try:
        path_obj = Path(file_path)
        content = path_obj.read_text(errors='replace')
        
        # Clean/Normalize
        # title = path_obj.stem
        # cleaned_content = clean_markdown(content) # Store raw or clean? Let's store raw content, clean for indexing if needed.
        
        # Check if exists (simple de-dupe by source_id or content hash could be better, but we'll trust the process)
        # We need a valid ID. Generating one or letting DB auto-increment.
        # Assuming schema: id, type, content, metadata, created_at, ...
        
        # Let's inspect schema first in main, but for now we construct a specialized ingest query.
        # We'll use a generic "text" or "conversation" type.
        
        now = datetime.now().isoformat()
        # FIX: Use json.dumps for valid JSON metadata
        metadata_dict = {"source": file_path, "type": source_type, "tags": tags}
        metadata = json.dumps(metadata_dict)
        
        # We need to know the schema. Let's assume standard 'memories' table
        # id | type | content | metadata | created_at | ...
        
        # Generate a random ID or let it auto-inc if integer. 
        # WhiteMagic usually uses UUIDs.
        import uuid
        mem_id = str(uuid.uuid4())
        
        conn.execute(
            "INSERT INTO memories (id, memory_type, content, metadata, created_at) VALUES (?, ?, ?, ?, ?)",
            (mem_id, "conversation_log", content, metadata, now)
        )
        conn.commit()
        return True
    except Exception as e:
        logger.error(f"Error ingesting {file_path}: {e}")
        return False

def ingest_directory(conn, directory, pattern, source_type, tags):
    logger.info(f"Ingesting {source_type} from {directory}...")
    files = glob.glob(os.path.join(str(directory), pattern), recursive=True)
    count = 0
    for f in files:
        if ingest_text_file(conn, f, source_type, tags):
            count += 1
    logger.info(f"Ingested {count} files from {directory}")

def main():
    if not init_super_db():
        return

    conn = sqlite3.connect(SUPER_DB_PATH)
    
    # 1. Merge Active DB
    merge_active_db(conn)
    
    # 2. Ingest Antigravity Logs (Decoded .decoded files are pseudo-text, we might need the raw output of strings)
    # Using the .strings.txt files I generated earlier via `strings` command as they are text
    ingest_directory(conn, AG_LOGS_DIR, "*.strings.txt", "antigravity_log", ["log", "antigravity", "context"])
    
    # 3. Ingest Windsurf Logs
    ingest_directory(conn, WS_LOGS_DIR, "*.md", "windsurf_log", ["log", "windsurf", "history"])
    
    # 4. Ingest MagicBackup
    ingest_directory(conn, MAGIC_BACKUP_DIR, "**/*.md", "magic_backup", ["backup", "legacy"])

    # Final Count
    count = conn.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    logger.info(f"🎉 Grand Consolidation Complete. Total Memories: {count}")
    
    conn.commit()
    conn.close()
    
    # Swap DBs
    final_path = Path(os.getenv("WM_ACTIVE_DB_PATH", str(ACTIVE_DB_SRC))).expanduser()
    final_path.parent.mkdir(parents=True, exist_ok=True)
    shutil.move(str(SUPER_DB_PATH), str(final_path))
    logger.info(f"🚀 System upgraded to use Super-Memory at {final_path}")

if __name__ == "__main__":
    main()
