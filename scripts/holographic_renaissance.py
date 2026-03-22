#!/usr/bin/env python3
"""Holographic Memory Renaissance — Coordinate Fill Script.

Identifies memories missing holographic coordinates and generates them
using the CoordinateEncoder. Part of the v22 milestone.
"""

import asyncio
import logging

from whitemagic.core.memory.unified import UnifiedMemory
from whitemagic.core.intelligence.hologram.encoder import CoordinateEncoder

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

async def run_renaissance():
    logger.info("🌌 Starting Holographic Memory Renaissance...")
    
    unified = UnifiedMemory()
    backend = unified.backend
    encoder = CoordinateEncoder()
    
    # 1. Identify missing coordinates
    with backend.pool.connection() as conn:
        missing = conn.execute("""
            SELECT id, content, title, memory_type, created_at, access_count, importance 
            FROM memories 
            WHERE id NOT IN (SELECT memory_id FROM holographic_coords)
        """).fetchall()
    
    total_missing = len(missing)
    logger.info(f"🔍 Found {total_missing} memories missing holographic coordinates.")
    
    if total_missing == 0:
        logger.info("✅ All memories already have holographic coverage.")
        return

    # 2. Generate and store coordinates
    processed = 0
    for row in missing:
        mem_id, content, title, memory_type, created_at, access_count, importance = row
        
        # Build memory dict for encoder
        memory_data = {
            "id": mem_id,
            "content": content,
            "title": title,
            "memory_type": memory_type,
            "created_at": created_at,
            "access_count": access_count,
            "importance": importance
        }
        
        try:
            # Generate 5D coords
            coords = encoder.encode(memory_data)
            
            # Store in backend
            backend.store_coords(mem_id, coords.x, coords.y, coords.z, coords.w, coords.v)
            processed += 1
            
            if processed % 10 == 0:
                logger.info(f"🛰️ Progress: {processed}/{total_missing} coordinates restored.")
                
        except Exception as e:
            logger.error(f"❌ Failed to encode memory {mem_id}: {e}")

    logger.info(f"✅ Renaissance Complete: {processed} memories illuminated.")

if __name__ == "__main__":
    asyncio.run(run_renaissance())
