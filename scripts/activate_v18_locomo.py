#!/usr/bin/env python3
"""
V18: LoCoMo Vector Search Activation
=====================================
Batch embed 4,726 active memories to enable vector search.
Uses V17 optimizer for 1,000+ embeddings/sec throughput.
"""
import asyncio
import logging
import sys
import time
from pathlib import Path

logging.basicConfig(level=logging.INFO, format='%(asctime)s | %(message)s')
logger = logging.getLogger(__name__)

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))


async def batch_embed_locomo_memories():
    """Batch embed all active memories for LoCoMo vector search"""
    logger.info("=" * 70)
    logger.info("V18: LoCoMo Vector Search Activation")
    logger.info("=" * 70)
    
    try:
        from whitemagic.core.memory.v17_embedding_optimizer import V17EmbeddingOptimizer
        from whitemagic.core.memory.embeddings import get_embedding_engine
        logger.info("V17 optimizer loaded successfully")
    except Exception as e:
        logger.error(f"Failed to load V17 optimizer: {e}")
        return False
    
    # Get engine
    engine = get_embedding_engine()
    if not engine.available():
        logger.error("Embedding engine not available")
        return False
    
    # Initialize V17 optimizer
    optimizer = V17EmbeddingOptimizer(engine)
    
    # Count memories to embed
    try:
        from whitemagic.core.memory.sqlite_backend import get_unified_memory
        db = get_unified_memory()
        
        # Count active memories without embeddings
        cursor = db.conn.execute(
            "SELECT COUNT(*) FROM memories "
            "WHERE memory_type != 'quarantined' "
            "AND id NOT IN (SELECT memory_id FROM memory_embeddings)"
        )
        to_embed = cursor.fetchone()[0]
        
        cursor = db.conn.execute(
            "SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'"
        )
        total_active = cursor.fetchone()[0]
        
        cursor = db.conn.execute(
            "SELECT COUNT(*) FROM memory_embeddings"
        )
        already_embedded = cursor.fetchone()[0]
        
        logger.info("Memory statistics:")
        logger.info(f"  Total active: {total_active}")
        logger.info(f"  Already embedded: {already_embedded}")
        logger.info(f"  To embed: {to_embed}")
        
    except Exception as e:
        logger.warning(f"Could not count memories: {e}")
        to_embed = 4726  # From V004 campaign
    
    if to_embed == 0:
        logger.info("All memories already embedded!")
        return True
    
    # Run batch embedding
    logger.info(f"\n🚀 Starting batch embedding of {to_embed} memories...")
    t0 = time.perf_counter()
    
    result = await optimizer.index_memories_v17(
        memory_type=None,  # All types
        limit=to_embed + 1000,  # Safety margin
        skip_cached=False  # Re-embed all: old embeddings used wrong model
    )
    
    elapsed = time.perf_counter() - t0
    
    logger.info("\n✅ Batch embedding complete:")
    logger.info(f"  Indexed: {result.get('indexed', 0)}")
    logger.info(f"  Duration: {result.get('duration_s', elapsed):.2f}s")
    logger.info(f"  Rate: {result.get('rate', 0):.1f} embeddings/sec")
    logger.info(f"  Target achieved: {result.get('target_achieved', False)}")
    
    # Verify results
    try:
        cursor = db.conn.execute(
            "SELECT COUNT(*) FROM memory_embeddings"
        )
        final_count = cursor.fetchone()[0]
        logger.info("Final embedding count: " + str(final_count))
    except Exception as e:
        logger.warning(f"Could not verify: {e}")
    
    return result.get('target_achieved', False)


async def verify_vector_search():
    """Verify vector search is working"""
    logger.info("\n" + "=" * 70)
    logger.info("Verifying vector search functionality...")
    logger.info("=" * 70)
    
    try:
        from whitemagic.core.memory.embeddings import get_embedding_engine
        engine = get_embedding_engine()
        
        # Test semantic search
        test_query = "artificial intelligence consciousness"
        results = engine.search_similar(test_query, limit=5, min_similarity=0.05)
        
        if results:
            logger.info(f"✅ Vector search working! Found {len(results)} results for '{test_query}'")
            for i, r in enumerate(results[:3], 1):
                logger.info(f"  {i}. {r['memory_id'][:20]}... (score: {r['similarity']:.3f})")
            return True
        else:
            logger.warning("⚠️ Vector search returned no results")
            return False
            
    except Exception as e:
        logger.error(f"❌ Vector search failed: {e}")
        return False


async def main():
    """Main V18 activation sequence"""
    logger.info("\n" + "=" * 70)
    logger.info("V18: LoCoMo Vector Search Activation")
    logger.info("Leveraging V17 Embedding Supremacy (1,000+ embeds/sec)")
    logger.info("=" * 70 + "\n")
    
    # Step 1: Batch embed memories
    embed_success = await batch_embed_locomo_memories()
    
    # Step 2: Verify vector search
    search_success = await verify_vector_search()
    
    # Summary
    logger.info("\n" + "=" * 70)
    logger.info("V18 ACTIVATION SUMMARY")
    logger.info("=" * 70)
    logger.info(f"Batch embedding: {'✅ COMPLETE' if embed_success else '❌ FAILED'}")
    logger.info(f"Vector search: {'✅ WORKING' if search_success else '❌ FAILED'}")
    
    if embed_success and search_success:
        logger.info("\n🎉 LoCoMo vector search is NOW ACTIVE!")
        logger.info("   Next: Run LoCoMo benchmark with vector search enabled")
        return 0
    else:
        logger.error("\n⚠️ Activation incomplete - check errors above")
        return 1


if __name__ == "__main__":
    exit_code = asyncio.run(main())
    sys.exit(exit_code)
