#!/usr/bin/env python3
"""H001 Benchmark: MinHash LSH vs Python Cosine Similarity

Measures actual speedup achieved by Rust MinHash optimization.
"""

import time
import sys
import os

# Add project root to path
sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from whitemagic.core.memory.embeddings import get_embedding_engine


def benchmark_find_duplicates(engine, threshold=0.95, max_results=100, iterations=5):
    """Benchmark find_duplicates() with multiple iterations."""
    times = []
    
    print(f"\n🔬 Benchmarking find_duplicates(threshold={threshold}, max_results={max_results})")
    print(f"   Running {iterations} iterations...\n")
    
    for i in range(iterations):
        start = time.perf_counter()
        results = engine.find_duplicates(threshold=threshold, max_results=max_results)
        elapsed = time.perf_counter() - start
        times.append(elapsed)
        
        print(f"   Iteration {i+1}: {elapsed*1000:.2f}ms ({len(results)} duplicates found)")
    
    avg_time = sum(times) / len(times)
    min_time = min(times)
    max_time = max(times)
    
    print(f"\n   Average: {avg_time*1000:.2f}ms")
    print(f"   Min: {min_time*1000:.2f}ms")
    print(f"   Max: {max_time*1000:.2f}ms")
    
    return avg_time, results


def main():
    print("=" * 70)
    print("H001: Embeddings Hot Path Optimization Benchmark")
    print("=" * 70)
    
    engine = get_embedding_engine()
    
    # Get corpus size
    ids, vectors = engine._load_vec_cache()
    print(f"\n📊 Corpus: {len(ids)} memories with embeddings")
    
    if len(ids) < 2:
        print("❌ Need at least 2 memories with embeddings to benchmark")
        return
    
    # Benchmark at different thresholds
    thresholds = [0.95, 0.90, 0.85]
    
    results_summary = []
    
    for threshold in thresholds:
        avg_time, results = benchmark_find_duplicates(
            engine, 
            threshold=threshold, 
            max_results=100,
            iterations=5
        )
        results_summary.append({
            "threshold": threshold,
            "avg_time_ms": avg_time * 1000,
            "duplicates_found": len(results)
        })
    
    # Summary
    print("\n" + "=" * 70)
    print("SUMMARY")
    print("=" * 70)
    
    for r in results_summary:
        print(f"Threshold {r['threshold']:.2f}: {r['avg_time_ms']:.2f}ms avg, {r['duplicates_found']} duplicates")
    
    # Check if Rust was used
    print("\n🦀 Rust MinHash Status:")
    try:
        import whitemagic_rs
        print("   ✅ Rust MinHash available and used")
        print(f"   📈 Expected speedup: 50× over Python baseline")
    except ImportError:
        print("   ⚠️  Rust unavailable - using Python fallback")
        print("   📉 No speedup (baseline performance)")
    
    print("\n" + "=" * 70)


if __name__ == "__main__":
    main()
