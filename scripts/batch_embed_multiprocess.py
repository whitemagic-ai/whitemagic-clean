#!/usr/bin/env python3
"""
F001 Batch Embeddings - Multi-Process Accelerated

Pragmatic solution: Use Python multiprocessing with FastEmbed
- 4 parallel workers (one per physical core)
- Each worker processes independent batches
- Expected: 4× speedup (16-20/s vs 4/s)
- Time for 100K: ~90-120 min (vs 7 hours)

Note: This bypasses Rust ONNX complexity while still delivering
significant speedup via parallelism.
"""

import sqlite3
import multiprocessing as mp
from pathlib import Path
import sys
import time
import logging

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.config.paths import DB_PATH

logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')
logger = logging.getLogger(__name__)


def worker_embed_batch(worker_id: int, batch_ids: list, batch_texts: list, result_queue: mp.Queue):
    """Worker process: embed a batch of texts"""
    try:
        # Import here to avoid multiprocessing issues
        from whitemagic.inference.local_embedder import LocalEmbedder
        
        embedder = LocalEmbedder()
        if not embedder.is_available:
            result_queue.put((worker_id, None, "embedder_unavailable"))
            return
        
        # Encode batch
        start = time.time()
        embeddings = embedder.embed(batch_texts, batch_size=256)
        elapsed = time.time() - start
        
        if embeddings is None or len(embeddings) == 0:
            result_queue.put((worker_id, None, "encoding_failed"))
            return
        
        # Convert to list of bytes
        embeddings_bytes = [emb.tobytes() for emb in embeddings]
        
        result_queue.put((worker_id, list(zip(batch_ids, embeddings_bytes)), None))
        
        rate = len(batch_texts) / elapsed if elapsed > 0 else 0
        logger.info(f"Worker {worker_id}: {len(batch_texts)} embedded in {elapsed:.1f}s ({rate:.1f}/s)")
        
    except Exception as e:
        logger.error(f"Worker {worker_id} error: {e}")
        result_queue.put((worker_id, None, str(e)))


def batch_embed_multiprocess(num_workers: int = 4, batch_size: int = 256, limit: int | None = None):
    """
    Embed all active memories using multiple worker processes
    
    Args:
        num_workers: Number of parallel workers (default: 4 for 4 physical cores)
        batch_size: Batch size per worker (default: 256)
        limit: Maximum number of embeddings to process (for testing, default: None = all)
    """
    logger.info("=" * 60)
    logger.info("  F001 Multi-Process Batch Embedding")
    logger.info("=" * 60)
    
    # Get status
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.execute("""
        SELECT COUNT(*) FROM memories 
        WHERE memory_type != 'quarantined'
    """)
    total_memories = cursor.fetchone()[0]
    
    cursor = conn.execute("""
        SELECT COUNT(DISTINCT memory_id) FROM memory_embeddings
    """)
    already_embedded = cursor.fetchone()[0]
    
    cursor = conn.execute("""
        SELECT COUNT(*) FROM memory_embeddings
        WHERE memory_id NOT IN (
            SELECT id FROM memories WHERE memory_type != 'quarantined'
        )
    """)
    orphan_embeddings = cursor.fetchone()[0]
    
    remaining = total_memories - already_embedded
    coverage = (already_embedded / total_memories * 100) if total_memories > 0 else 0
    
    logger.info(f"  Active memories:    {total_memories:,}")
    logger.info(f"  Already embedded:   {already_embedded:,}")
    logger.info(f"  Orphan embeddings:  {orphan_embeddings}")
    logger.info(f"  Remaining:          {remaining:,}")
    logger.info(f"  Current coverage:   {coverage:.1f}%")
    logger.info(f"  Workers:            {num_workers}")
    logger.info(f"  Batch size:         {batch_size}")
    logger.info("")
    
    if remaining == 0:
        logger.info("✅ All memories already embedded!")
        conn.close()
        return
    
    # Load all texts that need embedding
    logger.info("Loading texts...")
    if limit:
        cursor = conn.execute(f"""
            SELECT m.id, m.content
            FROM memories m
            WHERE m.memory_type != 'quarantined'
            AND m.id NOT IN (SELECT memory_id FROM memory_embeddings)
            ORDER BY m.id
            LIMIT {limit}
        """)
        logger.info(f"TEST MODE: Limiting to {limit} embeddings")
    else:
        cursor = conn.execute("""
            SELECT m.id, m.content
            FROM memories m
            WHERE m.memory_type != 'quarantined'
            AND m.id NOT IN (SELECT memory_id FROM memory_embeddings)
            ORDER BY m.id
        """)
    
    all_tasks = [(row[0], row[1][:512]) for row in cursor.fetchall()]
    logger.info(f"Loaded {len(all_tasks):,} texts to embed")
    
    # Split work among workers
    chunk_size = batch_size
    work_batches = []
    for i in range(0, len(all_tasks), chunk_size):
        chunk = all_tasks[i:i+chunk_size]
        batch_ids = [task[0] for task in chunk]
        batch_texts = [task[1] for task in chunk]
        work_batches.append((batch_ids, batch_texts))
    
    logger.info(f"Split into {len(work_batches)} batches of ~{chunk_size} each")
    logger.info("")
    
    # Process with worker pool
    start_time = time.time()
    total_embedded = 0
    failed_batches = 0
    
    result_queue = mp.Queue()
    
    # Process batches in rounds (num_workers at a time)
    for batch_idx in range(0, len(work_batches), num_workers):
        round_batches = work_batches[batch_idx:batch_idx+num_workers]
        
        # Start workers for this round
        processes = []
        for worker_id, (batch_ids, batch_texts) in enumerate(round_batches, start=batch_idx):
            p = mp.Process(
                target=worker_embed_batch,
                args=(worker_id, batch_ids, batch_texts, result_queue)
            )
            p.start()
            processes.append(p)
        
        # Collect results
        round_results = []
        for _ in range(len(processes)):
            result = result_queue.get(timeout=300)  # 5 min timeout per batch
            round_results.append(result)
        
        # Wait for processes to finish
        for p in processes:
            p.join(timeout=10)
            if p.is_alive():
                p.terminate()
        
        # Write results to DB
        for worker_id, result, error in round_results:
            if error:
                logger.error(f"Batch {worker_id} failed: {error}")
                failed_batches += 1
                continue
            
            if result:
                conn.executemany(
                    "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding) VALUES (?, ?)",
                    result
                )
                conn.commit()
                total_embedded += len(result)
        
        # Progress update
        elapsed = time.time() - start_time
        rate = total_embedded / elapsed if elapsed > 0 else 0
        new_coverage = ((already_embedded + total_embedded) / total_memories * 100) if total_memories > 0 else 0
        remaining_now = remaining - total_embedded
        eta = remaining_now / rate if rate > 0 else 0
        
        logger.info(f"Round {(batch_idx // num_workers) + 1}/{(len(work_batches) + num_workers - 1) // num_workers}: "
                   f"+{len(round_results)*chunk_size} embedded | "
                   f"Total: {total_embedded:,} | "
                   f"Coverage: {new_coverage:.1f}% | "
                   f"Rate: {rate:.1f}/s | "
                   f"Remaining: {remaining_now:,} | "
                   f"ETA: {eta/60:.1f} min")
    
    elapsed_total = time.time() - start_time
    
    logger.info("")
    logger.info("=" * 60)
    logger.info("✅ Embedding complete!")
    logger.info(f"  Embedded: {total_embedded:,}")
    logger.info(f"  Failed: {failed_batches}")
    logger.info(f"  Time: {elapsed_total/60:.1f} minutes")
    logger.info(f"  Average rate: {total_embedded/elapsed_total:.1f}/s")
    logger.info(f"  Final coverage: {((already_embedded + total_embedded) / total_memories * 100):.1f}%")
    logger.info("=" * 60)
    
    conn.close()


if __name__ == "__main__":
    import argparse
    parser = argparse.ArgumentParser(description="Multi-process batch embedding for F001")
    parser.add_argument("--workers", type=int, default=4, help="Number of parallel workers (default: 4)")
    parser.add_argument("--batch-size", type=int, default=256, help="Batch size per worker (default: 256)")
    parser.add_argument("--limit", type=int, default=None, help="Limit number of embeddings (for testing, default: None)")
    args = parser.parse_args()
    
    batch_embed_multiprocess(num_workers=args.workers, batch_size=args.batch_size, limit=args.limit)
