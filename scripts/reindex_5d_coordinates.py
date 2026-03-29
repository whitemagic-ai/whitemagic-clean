"""5D Coordinate Re-indexer — Update coordinates for existing memories.

Iterates through all memories in the database and re-calculates their
5D holographic coordinates using the latest encoder logic. Updates
both the SQLite database and the Rust spatial index.

Usage:
    python scripts/reindex_5d_coordinates.py [--limit 100] [--all]
"""

import argparse
import logging
import time
from typing import Any

from whitemagic.core.memory.unified import get_unified_memory
from whitemagic.core.intelligence.hologram.encoder import CoordinateEncoder

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def reindex(limit: int | None = None, all_memories: bool = False):
    um = get_unified_memory()
    encoder = CoordinateEncoder()
    
    # 1. Get memory IDs to re-index
    with um.backend.pool.connection() as conn:
        if all_memories:
            rows = conn.execute("SELECT id FROM memories").fetchall()
        else:
            # Re-index those already in holographic_coords first, or a specific limit
            rows = conn.execute("SELECT memory_id FROM holographic_coords LIMIT ?", (limit or 1000,)).fetchall()
    
    mem_ids = [row[0] for row in rows]
    total = len(mem_ids)
    print(f"🔄 Re-indexing {total} memories with latest 5D logic...")
    
    count = 0
    start_time = time.time()
    
    for mid in mem_ids:
        mem = um.recall(mid)
        if not mem:
            continue
            
        # Re-encode
        coords = encoder.encode(mem.to_dict())
        
        # Update SQLite
        um.backend.store_coords(mid, coords.x, coords.y, coords.z, coords.w, coords.v)
        
        # Update Rust Index (if loaded)
        if um.holographic:
            um.holographic.add_memory_with_coords(mid, coords.x, coords.y, coords.z, coords.w, coords.v)
            
        count += 1
        if count % 100 == 0:
            elapsed = time.time() - start_time
            rate = count / elapsed if elapsed > 0 else 0
            print(f"  Progress: {count}/{total} ({count/total*100:.1f}%) - {rate:.1f} mem/s")

    elapsed = time.time() - start_time
    print(f"✅ Finished! Re-indexed {count} memories in {elapsed:.1f} seconds.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=100, help="Number of memories to re-index")
    parser.add_argument("--all", action="store_true", help="Re-index ALL memories in database")
    args = parser.parse_args()
    
    reindex(limit=args.limit, all_memories=args.all)
