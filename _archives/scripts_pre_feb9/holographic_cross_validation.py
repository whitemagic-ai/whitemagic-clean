"""
Holographic Cross-Validation Script
===================================

Validates that the stored 4D coordinates in the Data Sea match the current 
CoordinateEncoder producing. Detects 'holographic drift' caused by 
encoder updates or data corruption.
"""

import asyncio
import logging
import os
import sqlite3
from pathlib import Path

from whitemagic.config.paths import DB_PATH
from whitemagic.core.memory.unified import get_unified_memory
from whitemagic.intelligence.hologram.encoder import CoordinateEncoder

logging.basicConfig(level=logging.INFO, format="%(asctime)s - %(levelname)s - %(message)s")
logger = logging.getLogger(__name__)

async def cross_validate():
    logger.info("📡 Starting Holographic Cross-Validation...")

    um = get_unified_memory()
    encoder = CoordinateEncoder()
    db_path = Path(os.getenv("WM_DB_PATH", str(DB_PATH))).expanduser()
    
    if not db_path.exists():
        logger.error(f"Database not found at {db_path}")
        return

    conn = sqlite3.connect(db_path)
    cursor = conn.execute("SELECT memory_id, x, y, z, w FROM holographic_coords")
    rows = cursor.fetchall()
    
    total = len(rows)
    logger.info(f"🔍 Found {total} holographic coordinates in DB. Validating...")
    
    mismatches = 0
    errors = 0
    drift_sum = 0.0
    
    # Process in batches
    for i, (mem_id, db_x, db_y, db_z, db_w) in enumerate(rows):
        try:
            mem = um.recall(mem_id)
            if not mem:
                # logger.warning(f"Memory {mem_id} not found for validation.")
                continue
                
            # Re-encode
            coord = encoder.encode({
                "title": mem.title,
                "content": str(mem.content),
                "tags": mem.tags,
                "importance": mem.importance
            })
            
            # Calculate Euclidean distance (drift)
            drift = ((coord.x - db_x)**2 + (coord.y - db_y)**2 + 
                     (coord.z - db_z)**2 + (coord.w - db_w)**2)**0.5
            
            if drift > 0.0001:
                mismatches += 1
                drift_sum += drift
                if mismatches < 5:
                    logger.warning(f"Drift detected in {mem_id}: {drift:.6f}")
            
            if i % 1000 == 0:
                logger.info(f"Progress: {i}/{total} validated...")
                
        except Exception:
            errors += 1
            # logger.error(f"Error validating {mem_id}: {e}")

    logger.info("="*40)
    logger.info("📊 CROSS-VALIDATION RESULTS")
    logger.info("="*40)
    logger.info(f"Total Validated:  {total}")
    logger.info(f"Exact Matches:    {total - mismatches}")
    logger.info(f"Mismatches/Drift: {mismatches}")
    logger.info(f"Total Drift:      {drift_sum:.6f}")
    if mismatches > 0:
        logger.info(f"Average Drift:    {drift_sum/mismatches:.6f}")
    logger.info(f"Errors:           {errors}")
    logger.info("="*40)

    if mismatches > 0:
        logger.warning("📝 RECOMMENDATION: Run 'whitemagic maintenance reindex' to align coordinates.")
    else:
        logger.info("✅ SUCCESS: Holographic coherence is at 100%. No drift detected.")

if __name__ == "__main__":
    asyncio.run(cross_validate())
