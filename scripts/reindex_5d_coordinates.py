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

from whitemagic.core.memory.unified import get_unified_memory
from whitemagic.core.intelligence.hologram.encoder import CoordinateEncoder

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def reindex(limit: int | None = None, all_memories: bool = False, batch_size: int = 50, embeddings_only: bool = False):
    um = get_unified_memory()
    encoder = CoordinateEncoder()
    
    # 1. Get memory IDs to re-index
    with um.backend.pool.connection() as conn:
        if all_memories:
            rows = conn.execute("SELECT id FROM memories").fetchall()
        elif embeddings_only:
            from whitemagic.core.memory.embeddings import get_embedding_engine
            engine = get_embedding_engine()
            db = engine._get_db()
            if not db:
                print("❌ ERROR: Embedding database not available.")
                return
            rows = db.execute("SELECT memory_id FROM memory_embeddings").fetchall()
        else:
            # Re-index those already in holographic_coords first, or a specific limit
            rows = conn.execute("SELECT memory_id FROM holographic_coords LIMIT ?", (limit or 1000,)).fetchall()
    
    mem_ids = [row[0] for row in rows]
    if limit and len(mem_ids) > limit:
        mem_ids = mem_ids[:limit]
        
    total = len(mem_ids)
    print(f"🔄 Re-indexing {total} memories with latest 5D logic (batch_size={batch_size})...")
    
    count = 0
    start_time = time.time()
    
    # Process in batches
    for i in range(0, total, batch_size):
        batch_ids = mem_ids[i:i+batch_size]
        batch_memories = []
        
        for mid in batch_ids:
            mem = um.recall(mid)
            if mem:
                batch_memories.append(mem)
        
        if not batch_memories:
            continue
            
        # Batch encode
        # CoordinateEncoder.encode_batch uses Rust/Mojo if available
        coords_list = encoder.encode_batch([m.to_dict() for m in batch_memories])
        
        # Batch update SQLite
        with um.backend.pool.connection() as conn:
            for mem, coords in zip(batch_memories, coords_list):
                um.backend.store_coords(mem.id, coords.x, coords.y, coords.z, coords.w, coords.v)
                
                # Update Rust Index (if loaded)
                if um.holographic:
                    um.holographic.add_memory_with_coords(mem.id, coords.x, coords.y, coords.z, coords.w, coords.v)
            
        count += len(batch_memories)
        elapsed = time.time() - start_time
        rate = count / elapsed if elapsed > 0 else 0
        print(f"  Progress: {count}/{total} ({count/total*100:.1f}%) - {rate:.1f} mem/s")

    elapsed = time.time() - start_time
    print(f"✅ Finished! Re-indexed {count} memories in {elapsed:.1f} seconds.")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--limit", type=int, default=100, help="Number of memories to re-index")
    parser.add_argument("--all", action="store_true", help="Re-index ALL memories in database")
    parser.add_argument("--embeddings-only", action="store_true", help="Re-index ONLY memories with semantic embeddings")
    parser.add_argument("--batch-size", type=int, default=50, help="Batch size for processing")
    args = parser.parse_args()
    
    reindex(
        limit=args.limit if not (args.all or args.embeddings_only) else None,
        all_memories=args.all,
        batch_size=args.batch_size,
        embeddings_only=args.embeddings_only
    )
