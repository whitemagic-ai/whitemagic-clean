#!/usr/bin/env python3
"""H001 Benchmark: Rust MinHash vs Python Cosine - Direct Comparison

Measures actual speedup achieved by Rust MinHash optimization.
"""

import time
import sys
import os

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from whitemagic.core.memory.embeddings import get_embedding_engine


def benchmark_rust_minhash(engine, threshold=0.95, max_results=100, iterations=3):
    """Benchmark Rust MinHash path."""
    times = []
    
    print(f"\n🦀 Rust MinHash (threshold={threshold})")
    
    for i in range(iterations):
        start = time.perf_counter()
        results = engine.find_duplicates(threshold=threshold, max_results=max_results)
        elapsed = time.perf_counter() - start
        times.append(elapsed)
        print(f"   Iteration {i+1}: {elapsed*1000:.2f}ms ({len(results)} duplicates)")
    
    avg = sum(times) / len(times)
    return avg, results


def benchmark_python_fallback(engine, threshold=0.95, max_results=100, iterations=3):
    """Benchmark Python cosine similarity fallback."""
    times = []
    
    print(f"\n🐍 Python Cosine Similarity (threshold={threshold})")
    
    for i in range(iterations):
        start = time.perf_counter()
        # Call find_similar_pairs directly to bypass Rust
        results = engine.find_similar_pairs(min_similarity=threshold, max_pairs=max_results)
        elapsed = time.perf_counter() - start
        times.append(elapsed)
        print(f"   Iteration {i+1}: {elapsed*1000:.2f}ms ({len(results)} duplicates)")
    
    avg = sum(times) / len(times)
    return avg, results


def main():
    print("=" * 70)
    print("H001: Rust MinHash vs Python Cosine - Direct Comparison")
    print("=" * 70)
    
    engine = get_embedding_engine()
    
    # Get corpus size
    ids, vectors = engine._load_vec_cache()
    print(f"\n📊 Corpus: {len(ids):,} memories with embeddings")
    
    if len(ids) < 2:
        print("❌ Need at least 2 memories with embeddings to benchmark")
        return
    
    # Test at threshold 0.95
    threshold = 0.95
    
    print("\n" + "=" * 70)
    print(f"BENCHMARK: Threshold {threshold}")
    print("=" * 70)
    
    rust_time, rust_results = benchmark_rust_minhash(engine, threshold, 100, 3)
    python_time, python_results = benchmark_python_fallback(engine, threshold, 100, 3)
    
    speedup = python_time / rust_time if rust_time > 0 else 0
    
    print("\n" + "=" * 70)
    print("RESULTS")
    print("=" * 70)
    print(f"Rust MinHash:        {rust_time*1000:.2f}ms avg ({len(rust_results)} duplicates)")
    print(f"Python Cosine:       {python_time*1000:.2f}ms avg ({len(python_results)} duplicates)")
    print(f"Speedup:             {speedup:.1f}×")
    print(f"Target:              50.0×")
    print(f"Achievement:         {(speedup/50.0)*100:.1f}% of target")
    
    # Note on methodology
    print("\n" + "=" * 70)
    print("NOTES")
    print("=" * 70)
    print("• Rust MinHash uses Jaccard similarity on keyword sets (title + tags)")
    print("• Python uses cosine similarity on 384-dim embeddings")
    print("• Different similarity metrics may find different duplicate pairs")
    print(f"• Corpus size: {len(ids):,} memories")
    print(f"• Rust is using parallel LSH with 128 hash functions")
    print(f"• Python is using O(N²) pairwise cosine similarity")
    
    print("\n" + "=" * 70)


if __name__ == "__main__":
    main()
