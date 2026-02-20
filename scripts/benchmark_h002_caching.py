#!/usr/bin/env python3
"""H002 Benchmark: Hybrid Search Caching Performance

Measures cache hit rate and speedup from intelligent caching.
"""

import time
import sys
import os

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from whitemagic.core.memory.unified import get_memory_manager


def benchmark_caching(queries: list[str], iterations: int = 3):
    """Benchmark cache performance with repeated queries."""
    manager = get_memory_manager()
    
    print(f"\n🔬 Benchmarking {len(queries)} queries × {iterations} iterations")
    
    # First pass - populate cache
    print("\n📝 Pass 1: Populating cache (cold start)")
    cold_times = []
    for query in queries:
        start = time.perf_counter()
        results = manager.search_hybrid(query, limit=10, use_cache=True)
        elapsed = time.perf_counter() - start
        cold_times.append(elapsed)
        print(f"   {query[:40]:40s} {elapsed*1000:6.1f}ms ({len(results)} results)")
    
    # Second pass - should hit cache
    print("\n🎯 Pass 2: Cache hits (warm)")
    warm_times = []
    for query in queries:
        start = time.perf_counter()
        results = manager.search_hybrid(query, limit=10, use_cache=True)
        elapsed = time.perf_counter() - start
        warm_times.append(elapsed)
        print(f"   {query[:40]:40s} {elapsed*1000:6.1f}ms ({len(results)} results)")
    
    # Third pass - verify cache still working
    print("\n🎯 Pass 3: Cache hits (verify)")
    verify_times = []
    for query in queries:
        start = time.perf_counter()
        results = manager.search_hybrid(query, limit=10, use_cache=True)
        elapsed = time.perf_counter() - start
        verify_times.append(elapsed)
        print(f"   {query[:40]:40s} {elapsed*1000:6.1f}ms ({len(results)} results)")
    
    # Calculate statistics
    avg_cold = sum(cold_times) / len(cold_times)
    avg_warm = sum(warm_times) / len(warm_times)
    avg_verify = sum(verify_times) / len(verify_times)
    speedup = avg_cold / avg_warm if avg_warm > 0 else 0
    
    print("\n" + "=" * 70)
    print("RESULTS")
    print("=" * 70)
    print(f"Cold start (no cache):  {avg_cold*1000:.1f}ms avg")
    print(f"Warm (cached):          {avg_warm*1000:.1f}ms avg")
    print(f"Verify (cached):        {avg_verify*1000:.1f}ms avg")
    print(f"Speedup:                {speedup:.1f}×")
    print(f"Target:                 20.0×")
    print(f"Achievement:            {(speedup/20.0)*100:.1f}% of target")
    
    # Get cache stats
    try:
        from whitemagic.core.memory.hybrid_cache import get_hybrid_cache
        cache = get_hybrid_cache()
        stats = cache.stats()
        print("\n" + "=" * 70)
        print("CACHE STATISTICS")
        print("=" * 70)
        query_stats = stats["query_cache"]
        print(f"Cache size:    {query_stats['size']}/{query_stats['max_size']}")
        print(f"Hits:          {query_stats['hits']}")
        print(f"Misses:        {query_stats['misses']}")
        print(f"Hit rate:      {query_stats['hit_rate']*100:.1f}%")
        print(f"Target:        80.0%")
        print(f"Achievement:   {(query_stats['hit_rate']/0.8)*100:.1f}% of target")
    except Exception as e:
        print(f"\n⚠️  Cache stats unavailable: {e}")
    
    print("\n" + "=" * 70)
    
    return speedup


def main():
    print("=" * 70)
    print("H002: Hybrid Search Caching Benchmark")
    print("=" * 70)
    
    # Test queries - mix of common and specific
    queries = [
        "memory consolidation",
        "rust optimization",
        "embedding search",
        "campaign deployment",
        "zodiac armies",
        "holographic coordinates",
        "graph walker",
        "association mining",
    ]
    
    speedup = benchmark_caching(queries, iterations=3)
    
    if speedup >= 20.0:
        print("\n✅ H002 TARGET ACHIEVED: 20× speedup!")
    elif speedup >= 10.0:
        print(f"\n⚠️  H002 PARTIAL: {speedup:.1f}× speedup (target: 20×)")
    else:
        print(f"\n❌ H002 BELOW TARGET: {speedup:.1f}× speedup (target: 20×)")


if __name__ == "__main__":
    main()
