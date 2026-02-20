#!/usr/bin/env python3
"""
Campaign C001: Quarantine Rehabilitation
========================================
Executes the mass rehabilitation of the 104,720 quarantined memories.
1. Loads all quarantined memories.
2. Checks against active memories for exact duplicates (hash).
3. Checks for noise patterns.
4. Purges duplicates and noise.
5. Rehabilitates the rest (Novelty/Lost) -> LONG_TERM.
"""

import sqlite3
import time
import logging
import sys
from pathlib import Path

# Add project root to python path
PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from whitemagic.core.memory.deduplication import is_noise

# Setup logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')
logger = logging.getLogger(__name__)

DB_PATH = Path.home() / ".whitemagic/memory/whitemagic.db"

def rehabilitate():
    if not DB_PATH.exists():
        logger.error(f"Database not found at {DB_PATH}")
        return

    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()

    logger.info("--- Phase 1: Snapshotting Active State ---")
    # Get active hashes for deduplication
    cursor.execute("SELECT content_hash FROM memories WHERE memory_type != 'quarantined' AND content_hash IS NOT NULL")
    active_hashes = set(row[0] for row in cursor.fetchall())
    logger.info(f"Loaded {len(active_hashes)} active content hashes.")

    logger.info("--- Phase 2: Scanning Quarantine ---")
    cursor.execute("SELECT count(*) FROM memories WHERE memory_type = 'quarantined'")
    total_quarantined = cursor.fetchone()[0]
    logger.info(f"Found {total_quarantined} quarantined memories.")

    batch_size = 5000
    cursor.execute("SELECT id, title, content, content_hash FROM memories WHERE memory_type = 'quarantined'")
    
    to_purge_dupe = []
    to_purge_noise = []
    to_rehab = []
    
    processed = 0
    start_time = time.time()

    while True:
        rows = cursor.fetchmany(batch_size)
        if not rows:
            break
            
        for row in rows:
            mid = row["id"]
            title = row["title"] or ""
            content = row["content"] or ""
            chash = row["content_hash"]
            
            # 1. Deduplication Check
            if chash in active_hashes:
                to_purge_dupe.append(mid)
                continue
                
            # 2. Noise Check
            if is_noise(content, title):
                to_purge_noise.append(mid)
                continue
                
            # 3. Rehabilitate
            to_rehab.append(mid)
            
        processed += len(rows)
        if processed % 10000 == 0:
            logger.info(f"Scanned {processed}/{total_quarantined}...")

    scan_time = time.time() - start_time
    logger.info(f"Scan complete in {scan_time:.2f}s.")
    logger.info("Stats:")
    logger.info(f"  Duplicates (Purge): {len(to_purge_dupe)}")
    logger.info(f"  Noise (Purge):      {len(to_purge_noise)}")
    logger.info(f"  Rehabilitate:       {len(to_rehab)}")

    # Confirmation
    if len(to_rehab) == 0 and len(to_purge_dupe) == 0 and len(to_purge_noise) == 0:
        logger.info("Nothing to do.")
        conn.close()
        return

    logger.info("--- Phase 3: Execution ---")
    
    # Batch delete
    total_purge = to_purge_dupe + to_purge_noise
    if total_purge:
        logger.info(f"Purging {len(total_purge)} memories...")
        # SQLite limit is usually 999 vars, need to chunk
        chunk_size = 900
        for i in range(0, len(total_purge), chunk_size):
            chunk = total_purge[i:i+chunk_size]
            placeholders = ",".join("?" * len(chunk))
            cursor.execute(f"DELETE FROM memories WHERE id IN ({placeholders})", chunk)
            conn.commit()
    
    # Batch update
    if to_rehab:
        logger.info(f"Rehabilitating {len(to_rehab)} memories...")
        for i in range(0, len(to_rehab), chunk_size):
            chunk = to_rehab[i:i+chunk_size]
            placeholders = ",".join("?" * len(chunk))
            # Set to LONG_TERM and tag as recovered
            cursor.execute(f"UPDATE memories SET memory_type = 'LONG_TERM' WHERE id IN ({placeholders})", chunk)
            
            # Add tags (need separate loop or smarter SQL? Simple loop for tags)
            # Actually, doing one massive tag insert is better.
            tag_values = [(mid, "recovered_from_quarantine") for mid in chunk]
            cursor.executemany("INSERT OR IGNORE INTO tags (memory_id, tag) VALUES (?, ?)", tag_values)
            conn.commit()

    # Vacuum to reclaim space
    logger.info("--- Phase 4: Vacuuming ---")
    # cursor.execute("VACUUM") # Optional, takes time
    
    conn.close()
    logger.info("Quarantine Rehabilitation Complete.")

if __name__ == "__main__":
    rehabilitate()
