"""5D Coordinate Validation — Measure overlap between 5D spatial and semantic search.

This script validates the 5D coordinate system by:
1. Selecting a random sample of memories.
2. Finding "ground truth" neighbors using pure semantic embedding similarity.
3. Finding neighbors using fast 5D holographic spatial search.
4. Calculating the overlap (Recall@K) between the two methods.
5. Reporting performance and accuracy metrics.

Usage:
    python tests/benchmarks/validate_5d_coordinates.py [--samples 50] [--k 10]
"""

import argparse
import random
import time

from whitemagic.core.memory.holographic import get_holographic_memory
from whitemagic.core.memory.unified import get_unified_memory


def validate_5d(num_samples: int = 50, k: int = 10):
    print(f"🧪 Validating 5D Coordinate System ({num_samples} samples, k={k})")
    print("=" * 60)

    um = get_unified_memory()
    holo = get_holographic_memory()

    # 1. Check if embedding engine is available
    from whitemagic.core.memory.embeddings import get_embedding_engine
    engine = get_embedding_engine()
    if not engine or not engine.available():
        print("❌ ERROR: Embedding engine unavailable. Cannot establish semantic ground truth.")
        print("   Please install fastembed or sentence-transformers.")
        return

    # 2. Get all memories with coordinates
    with um.backend.pool.connection() as conn:
        all_ids = [row[0] for row in conn.execute("SELECT memory_id FROM holographic_coords").fetchall()]

    if not all_ids:
        print("❌ No memories with coordinates found in database.")
        return

    if len(all_ids) < num_samples:
        num_samples = len(all_ids)

    sample_ids = random.sample(all_ids, num_samples)
    
    total_overlap = 0
    total_semantic_time = 0.0
    total_spatial_time = 0.0

    print(f"Evaluating {num_samples} memories...")

    for mid in sample_ids:
        mem = um.recall(mid)
        if not mem:
            continue

        # --- Channel A: True Semantic Similarity (Ground Truth) ---
        start = time.time()
        # Use embedding engine directly for pure cosine similarity search
        semantic_hits = engine.search_similar(str(mem.content), limit=k+1)
        semantic_ids = [hit["memory_id"] for hit in semantic_hits if hit["memory_id"] != mid]
        total_semantic_time += (time.time() - start)

        # --- Channel B: Fast 5D Spatial Search ---
        start = time.time()
        # Use spatial index
        spatial_results = holo.query_nearest(mem.to_dict(), k=k+1)
        spatial_ids = [r.memory_id for r in spatial_results if r.memory_id != mid]
        total_spatial_time += (time.time() - start)

        # Calculate overlap
        overlap = len(set(semantic_ids) & set(spatial_ids))
        total_overlap += overlap

    # --- Results ---
    if num_samples == 0:
        print("No samples to evaluate.")
        return

    avg_overlap = (total_overlap / (num_samples * k)) * 100
    avg_semantic_ms = (total_semantic_time / num_samples) * 1000
    avg_spatial_ms = (total_spatial_time / num_samples) * 1000
    speedup = avg_semantic_ms / avg_spatial_ms if avg_spatial_ms > 0 else float('inf')

    print("-" * 60)
    print(f"📊 Accuracy (Overlap with Semantic Ground Truth): {avg_overlap:.2f}%")
    print(f"⏱️  Avg Semantic Search Time: {avg_semantic_ms:.2f} ms")
    print(f"⏱️  Avg 5D Spatial Search Time: {avg_spatial_ms:.2f} ms")
    print(f"🚀 Speedup Factor: {speedup:.1f}x")
    print("-" * 60)

    if avg_overlap >= 70:
        print("✅ SUCCESS: 5D system effectively predicts semantic relevance.")
    elif avg_overlap >= 40:
        print("⚠️  WARNING: Moderate overlap. Tuning of axis calculations recommended.")
    else:
        print("❌ FAILURE: Low overlap. 5D system is not predicting semantic relevance well.")


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--samples", type=int, default=50, help="Number of random memories to sample")
    parser.add_argument("--k", type=int, default=10, help="Number of neighbors to compare")
    args = parser.parse_args()

    validate_5d(num_samples=args.samples, k=args.k)
