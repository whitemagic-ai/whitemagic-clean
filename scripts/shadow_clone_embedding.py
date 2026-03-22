#!/usr/bin/env python3
"""Shadow Clone Army Embedding - Phase 2
========================================
Multi-process parallel embedding using shadow clone workers.
Each clone processes its own batch of memories independently.

Expected: 4-8x speedup (2.5 → 10-20 embeddings/sec)
"""

import argparse
import os
import sqlite3
import sys
import time
from multiprocessing import Pool, cpu_count
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

DB_PATH = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")


def get_counts():
    """Get current embedding coverage stats."""
    conn = sqlite3.connect(DB_PATH)
    active = conn.execute(
        "SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'"
    ).fetchone()[0]
    active_embedded = conn.execute(
        """SELECT COUNT(*) FROM memory_embeddings
           WHERE memory_id IN (SELECT id FROM memories WHERE memory_type != 'quarantined')"""
    ).fetchone()[0]
    remaining = active - active_embedded
    conn.close()
    return {
        "active_memories": active,
        "active_embedded": active_embedded,
        "remaining": remaining,
        "coverage_pct": round(active_embedded / max(active, 1) * 100, 1),
    }


def get_unembedded_memory_ids(limit: int = None) -> list[str]:
    """Get list of memory IDs that need embedding."""
    conn = sqlite3.connect(DB_PATH)
    query = """
        SELECT id FROM memories
        WHERE memory_type != 'quarantined'
        AND id NOT IN (SELECT memory_id FROM memory_embeddings)
    """
    if limit:
        query += f" LIMIT {limit}"

    ids = [row[0] for row in conn.execute(query).fetchall()]
    conn.close()
    return ids


def embed_memory_batch_worker(args: tuple[list[str], int]) -> dict:
    """Worker function to embed a batch of memories.

    Each worker:
    1. Loads its own model instance
    2. Fetches memory content
    3. Generates embeddings
    4. Writes to database

    Args:
        args: Tuple of (memory_ids, worker_id)

    Returns:
        dict with results
    """
    memory_ids, worker_id = args

    if not memory_ids:
        return {"worker_id": worker_id, "embedded": 0, "time": 0}

    start_time = time.time()

    try:
        # Import here to avoid issues with multiprocessing
        sys.path.insert(0, str(ROOT))
        os.environ["WM_SILENT_INIT"] = "1"

        from whitemagic.core.memory.embeddings import get_embedding_engine

        # Each worker gets its own engine instance
        engine = get_embedding_engine()

        if not engine.available():
            return {"worker_id": worker_id, "embedded": 0, "time": 0, "error": "Engine unavailable"}

        # Fetch memory contents
        conn = sqlite3.connect(DB_PATH)
        conn.execute("PRAGMA journal_mode=WAL")

        placeholders = ','.join('?' * len(memory_ids))
        query = f"""
            SELECT id, title, content
            FROM memories
            WHERE id IN ({placeholders})
        """
        rows = conn.execute(query, memory_ids).fetchall()

        # Generate embeddings
        embedded_count = 0
        for memory_id, title, content in rows:
            # Combine title and content for embedding
            text = f"{title}\n\n{content}" if title else content
            if not text or len(text.strip()) == 0:
                continue

            # Generate embedding
            vec = engine.encode(text)
            if vec is None:
                continue

            # Store in database
            try:
                # Pack embedding as blob
                import struct
                blob = struct.pack(f'{len(vec)}f', *vec)

                conn.execute(
                    "INSERT OR REPLACE INTO memory_embeddings (memory_id, embedding) VALUES (?, ?)",
                    (memory_id, blob)
                )
                embedded_count += 1
            except Exception as e:
                print(f"Worker {worker_id}: Error storing embedding for {memory_id}: {e}")
                continue

        # Commit all at once
        conn.commit()
        conn.close()

        elapsed = time.time() - start_time

        return {
            "worker_id": worker_id,
            "embedded": embedded_count,
            "time": elapsed,
            "rate": embedded_count / elapsed if elapsed > 0 else 0,
        }

    except Exception as e:
        return {
            "worker_id": worker_id,
            "embedded": 0,
            "time": time.time() - start_time,
            "error": str(e),
        }


def shadow_clone_embed(max_minutes: int = 5, num_workers: int = None):
    """Deploy shadow clone army for parallel embedding.

    Args:
        max_minutes: Time limit in minutes
        num_workers: Number of parallel workers (default: CPU count / 2)
    """
    # Determine optimal worker count
    if num_workers is None:
        cpu_threads = cpu_count()
        # Use half of available threads to avoid overload
        num_workers = max(2, cpu_threads // 2)

    counts = get_counts()

    print("=" * 80)
    print("  🥷 SHADOW CLONE ARMY EMBEDDING (Phase 2)")
    print("=" * 80)
    print(f"  Active memories:    {counts['active_memories']:,}")
    print(f"  Already embedded:   {counts['active_embedded']:,}")
    print(f"  Remaining:          {counts['remaining']:,}")
    print(f"  Current coverage:   {counts['coverage_pct']}%")
    print(f"  Shadow clones:      {num_workers} workers")
    print(f"  Time limit:         {max_minutes} minutes")
    print()

    print("  🥷 Shadow Clone Strategy:")
    print(f"     • Deploy {num_workers} parallel workers")
    print("     • Each clone: own model instance")
    print("     • Distribute work evenly across clones")
    print("     • Expected: 4-8x speedup")
    print()

    if counts["remaining"] == 0:
        print("✅ All active memories already embedded!")
        return counts

    # Calculate batch size per worker for time limit
    # Assume ~2.5 embeddings/sec per worker
    embeddings_per_worker = int(2.5 * 60 * max_minutes)
    total_target = embeddings_per_worker * num_workers

    print("  📊 Work Distribution:")
    print(f"     Target per worker: ~{embeddings_per_worker} memories")
    print(f"     Total target: ~{total_target} memories")
    print()

    # Get unembedded memory IDs
    print("  🔍 Fetching unembedded memory IDs...")
    memory_ids = get_unembedded_memory_ids(limit=total_target)

    if not memory_ids:
        print("  ✅ No memories to embed!")
        return counts

    print(f"  ✅ Found {len(memory_ids)} memories to embed")

    # Distribute work across workers
    chunk_size = len(memory_ids) // num_workers
    worker_tasks = []

    for i in range(num_workers):
        start_idx = i * chunk_size
        if i == num_workers - 1:
            # Last worker gets remaining memories
            end_idx = len(memory_ids)
        else:
            end_idx = start_idx + chunk_size

        worker_ids = memory_ids[start_idx:end_idx]
        worker_tasks.append((worker_ids, i))
        print(f"     Clone {i}: {len(worker_ids)} memories")

    print()
    print(f"  🚀 Deploying {num_workers} shadow clones...")
    print()

    start_time = time.time()

    # Deploy shadow clone army
    with Pool(processes=num_workers) as pool:
        results = pool.map(embed_memory_batch_worker, worker_tasks)

    elapsed = time.time() - start_time

    # Aggregate results
    total_embedded = sum(r.get("embedded", 0) for r in results)
    total_rate = total_embedded / elapsed if elapsed > 0 else 0

    print()
    print("=" * 80)
    print("  ✅ SHADOW CLONE ARMY COMPLETE")
    print("=" * 80)

    # Show per-worker results
    print()
    print("  📊 Clone Performance:")
    for r in results:
        worker_id = r.get("worker_id", "?")
        embedded = r.get("embedded", 0)
        worker_time = r.get("time", 0)
        rate = r.get("rate", 0)
        error = r.get("error")

        if error:
            print(f"     Clone {worker_id}: ❌ Error - {error}")
        else:
            print(f"     Clone {worker_id}: {embedded} memories in {worker_time:.1f}s ({rate:.1f}/s)")

    print()
    print("  📊 Overall Performance:")
    print(f"     Total embedded:     {total_embedded:,}")
    print(f"     Total time:         {elapsed:.1f}s ({elapsed/60:.1f} min)")
    print(f"     Overall rate:       {total_rate:.1f} embeddings/sec")
    print(f"     Parallel speedup:   {total_rate / 2.5:.1f}x (vs 2.5/s baseline)")

    # Get final coverage
    final_counts = get_counts()
    print(f"     Final coverage:     {final_counts['coverage_pct']}%")

    print()

    return final_counts


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Shadow clone army parallel embedding")
    parser.add_argument("--minutes", type=int, default=5, help="Time limit in minutes (default: 5)")
    parser.add_argument("--workers", type=int, default=None, help="Number of workers (default: CPU count / 2)")
    args = parser.parse_args()

    shadow_clone_embed(max_minutes=args.minutes, num_workers=args.workers)
