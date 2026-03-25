#!/usr/bin/env python3
"""
Holographic Core Population Script
Phase 23: The Data Sea - Re-index all living memories into 4D space.
"""

import sqlite3
import logging
import sys
import time
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

DB_PATH = Path(__file__).parent.parent / "memory" / "whitemagic.db"
BATCH_SIZE = 1000

def get_living_memories(db_path: Path, offset: int = 0, limit: int = BATCH_SIZE) -> list:
    """Fetch a batch of living (non-substrate) memories."""
    conn = sqlite3.connect(db_path)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    
    cursor.execute("""
        SELECT id, title, content, memory_type, created_at, importance, emotional_valence
        FROM memories
        WHERE memory_type != 'substrate'
        ORDER BY created_at DESC
        LIMIT ? OFFSET ?
    """, (limit, offset))
    
    rows = cursor.fetchall()
    conn.close()
    return [dict(row) for row in rows]

def count_living_memories(db_path: Path) -> int:
    """Count non-substrate memories."""
    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    cursor.execute("SELECT count(*) FROM memories WHERE memory_type != 'substrate'")
    count = cursor.fetchone()[0]
    conn.close()
    return count

def index_batch(memories: list, holographic_memory) -> int:
    """Index a batch of memories into the holographic core."""
    indexed = 0
    for mem in memories:
        try:
            coords = holographic_memory.index_memory(mem['id'], mem)
            if coords:
                indexed += 1
        except Exception as e:
            logger.warning(f"Failed to index {mem['id']}: {e}")
    return indexed

def main():
    logger.info("=" * 60)
    logger.info("HOLOGRAPHIC CORE POPULATION")
    logger.info("Phase 23: The Data Sea")
    logger.info("=" * 60)
    
    # Count memories
    total = count_living_memories(DB_PATH)
    logger.info(f"Living memories to index: {total:,}")
    
    # Initialize holographic memory
    try:
        from whitemagic.core.memory.holographic import HolographicMemory
        holo = HolographicMemory()
        health = holo.check_health()
        logger.info(f"Holographic Core Status: {health}")
        
        if health['backend'] == 'python':
            logger.warning("⚠️  Running in Python fallback mode - will be slow!")
    except ImportError as e:
        logger.error(f"Cannot import HolographicMemory: {e}")
        logger.info("Skipping holographic indexing - module not available.")
        return
    
    # Index in batches
    offset = 0
    total_indexed = 0
    start_time = time.time()
    
    while offset < total:
        batch = get_living_memories(DB_PATH, offset, BATCH_SIZE)
        if not batch:
            break
            
        indexed = index_batch(batch, holo)
        total_indexed += indexed
        offset += len(batch)
        
        # Progress report
        pct = (offset / total) * 100
        elapsed = time.time() - start_time
        rate = offset / elapsed if elapsed > 0 else 0
        eta = (total - offset) / rate if rate > 0 else 0
        
        logger.info(f"Progress: {offset:,}/{total:,} ({pct:.1f}%) | Indexed: {total_indexed:,} | ETA: {eta:.0f}s")
    
    elapsed = time.time() - start_time
    logger.info("=" * 60)
    logger.info(f"COMPLETE: {total_indexed:,} memories indexed in {elapsed:.1f}s")
    logger.info("=" * 60)

if __name__ == "__main__":
    main()
