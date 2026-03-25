"""
The Great Realignment: Data Sea Re-Indexing Script
==================================================

Re-calculates 4D holographic coordinates for all memories in the SQLite DB
using the latest CoordinateEncoder and stores them in the holographic_coords 
table. Uses the Rust bridge for maximum performance.
"""

import sqlite3
import logging
import asyncio
import os
from pathlib import Path
from typing import List, Tuple
from datetime import datetime

from whitemagic.config.paths import DB_PATH
from whitemagic.core.memory.unified import get_unified_memory
from whitemagic.intelligence.hologram.encoder import CoordinateEncoder
from whitemagic.utils.rust_helper import is_rust_available, get_rust_module

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")
logger = logging.getLogger(__name__)

async def realign_data_sea():
    logger.info("🌌 STARTING THE GREAT REALIGNMENT...")
    start_time = datetime.now()

    um = get_unified_memory()
    encoder = CoordinateEncoder()
    db_path = Path(os.getenv("WM_DB_PATH", str(DB_PATH))).expanduser()
    
    if not db_path.exists():
        logger.error(f"Database not found at {db_path}")
        return

    # Initialize Rust Index if available
    rust_available = is_rust_available()
    rs = get_rust_module() if rust_available else None
    
    if rust_available:
        logger.info("🦀 Rust Acceleration Enabled.")
    else:
        logger.warning("🐌 Rust bridge not found. Proceeding with Python fallback (WARNING: Very slow).")

    conn = sqlite3.connect(db_path)
    
    # 1. Clear old coordinates
    logger.info("🧹 Clearing stale holographic coordinates...")
    conn.execute("DELETE FROM holographic_coords")
    conn.commit()
    
    # 2. Fetch all memories
    cursor = conn.execute("SELECT id, content, title, tags_text, importance FROM memories")
    
    batch_size = 5000
    updates: List[Tuple] = []
    processed = 0
    
    logger.info("📐 Calculating new 4D coordinates...")
    
    while True:
        rows = cursor.fetchmany(batch_size)
        if not rows:
            break
            
        for mem_id, content, title, tags_text, importance in rows:
            try:
                # Prepare data for encoder
                tags = set(tags_text.split()) if tags_text else set()
                
                # Re-encode
                coord = encoder.encode({
                    "title": title,
                    "content": str(content),
                    "tags": tags,
                    "importance": importance
                })
                
                updates.append((mem_id, coord.x, coord.y, coord.z, coord.w))
                
                # Also add to Rust in-memory index if available
                if rust_available and um.holographic and um.holographic._index:
                    um.holographic._index.add(mem_id, coord.x, coord.y, coord.z, coord.w)
                    
            except Exception as e:
                logger.error(f"Failed to encode {mem_id}: {e}")

        # Batch update SQLite
        if updates:
            conn.executemany(
                "INSERT INTO holographic_coords (memory_id, x, y, z, w) VALUES (?, ?, ?, ?, ?)",
                updates
            )
            conn.commit()
            processed += len(updates)
            updates = []
            
            elapsed = (datetime.now() - start_time).total_seconds()
            rate = processed / elapsed if elapsed > 0 else 0
            logger.info(f"Progress: {processed} memories realigned. Speed: {rate:.1f} mem/sec")

    conn.close()
    
    total_time = (datetime.now() - start_time).total_seconds()
    logger.info("="*40)
    logger.info("✨ THE GREAT REALIGNMENT COMPLETE")
    logger.info("="*40)
    logger.info(f"Total Memories: {processed}")
    logger.info(f"Elapsed Time:   {total_time:.2f} seconds")
    logger.info(f"Average Rate:   {processed/total_time:.1f} records/sec")
    logger.info("="*40)
    logger.info("✅ System resonance should now be able to cross 1.00.")

if __name__ == "__main__":
    asyncio.run(realign_data_sea())
