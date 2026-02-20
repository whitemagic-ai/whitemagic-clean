#!/usr/bin/env python3
"""Benchmark Polyglot Memory System vs Original unified.py

Measures:
- Query routing time (Zig target: <10μs)
- Hybrid search time (Rust target: 2-10ms)
- Cache hit rate (target: >80%)
- Overall speedup (target: 20-50×)
"""

import time
import statistics
from pathlib import Path

# Add project to path
import sys
sys.path.insert(0, str(Path(__file__).parent.parent))

def benchmark_unified_v1():
    """Benchmark original Python implementation."""
    from whitemagic.core.memory.unified import UnifiedMemory
    
    um = UnifiedMemory()
    queries = [
        "rust optimization",
        "python memory management",
        "cache implementation",
        "search algorithm",
        "database query",
    ]
    
    print("=" * 80)
    print("BENCHMARK: Original unified.py (Python)")
    print("=" * 80)
    
    times = []
    for query in queries:
        start = time.perf_counter()
        results = um.search_hybrid(query, limit=10)
        elapsed = time.perf_counter() - start
        times.append(elapsed * 1000)  # Convert to ms
        print(f"  {query:30s} → {len(results):2d} results in {elapsed*1000:6.2f}ms")
    
    avg_time = statistics.mean(times)
    print(f"\n  Average: {avg_time:.2f}ms")
    print(f"  Min:     {min(times):.2f}ms")
    print(f"  Max:     {max(times):.2f}ms")
    
    return avg_time


def benchmark_unified_v2():
    """Benchmark polyglot Rust+Zig implementation."""
    try:
        from whitemagic.core.memory.unified_v2 import UnifiedMemoryV2
    except ImportError:
        print("❌ unified_v2.py not found or Rust not compiled")
        return None
    
    um = UnifiedMemoryV2()
    queries = [
        "rust optimization",
        "python memory management",
        "cache implementation",
        "search algorithm",
        "database query",
    ]
    
    print("\n" + "=" * 80)
    print("BENCHMARK: Polyglot unified_v2.py (Rust + Zig)")
    print("=" * 80)
    
    # Warm up cache
    print("\n  Warming up cache...")
    for query in queries:
        um.search_hybrid(query, limit=10)
    
    # Cold run (clear cache)
    print("\n  Cold run (no cache):")
    um.clear_cache()
    cold_times = []
    for query in queries:
        start = time.perf_counter()
        results = um.search_hybrid(query, limit=10)
        elapsed = time.perf_counter() - start
        cold_times.append(elapsed * 1000)
        print(f"  {query:30s} → {len(results):2d} results in {elapsed*1000:6.2f}ms")
    
    # Warm run (with cache)
    print("\n  Warm run (with cache):")
    warm_times = []
    for query in queries:
        start = time.perf_counter()
        results = um.search_hybrid(query, limit=10)
        elapsed = time.perf_counter() - start
        warm_times.append(elapsed * 1000)
        print(f"  {query:30s} → {len(results):2d} results in {elapsed*1000:6.2f}ms")
    
    # Cache stats
    stats = um.cache_stats()
    print("\n  Cache Statistics:")
    print(f"    Hit rate:          {stats['hit_rate']*100:.1f}%")
    print(f"    Total hits:        {int(stats['total_hits'])}")
    print(f"    Total misses:      {int(stats['total_misses'])}")
    print(f"    Query entries:     {int(stats['query_entries'])}")
    print(f"    Embedding entries: {int(stats['embedding_entries'])}")
    
    avg_cold = statistics.mean(cold_times)
    avg_warm = statistics.mean(warm_times)
    
    print(f"\n  Cold average: {avg_cold:.2f}ms")
    print(f"  Warm average: {avg_warm:.2f}ms")
    print(f"  Speedup (warm): {avg_cold/avg_warm:.1f}×")
    
    return avg_cold, avg_warm, stats


def main():
    print("\n🚀 Polyglot Memory System Benchmark")
    print("=" * 80)
    
    # Benchmark V1 (Python)
    try:
        v1_time = benchmark_unified_v1()
    except Exception as e:
        print(f"❌ V1 benchmark failed: {e}")
        v1_time = None
    
    # Benchmark V2 (Rust + Zig)
    try:
        result = benchmark_unified_v2()
        if result:
            v2_cold, v2_warm, stats = result
        else:
            v2_cold = v2_warm = None
    except Exception as e:
        print(f"❌ V2 benchmark failed: {e}")
        import traceback
        traceback.print_exc()
        v2_cold = v2_warm = None
    
    # Comparison
    if v1_time and v2_cold:
        print("\n" + "=" * 80)
        print("COMPARISON")
        print("=" * 80)
        print(f"\n  Python (V1):        {v1_time:.2f}ms")
        print(f"  Rust cold (V2):     {v2_cold:.2f}ms")
        print(f"  Rust warm (V2):     {v2_warm:.2f}ms")
        print(f"\n  Speedup (cold):     {v1_time/v2_cold:.1f}×")
        print(f"  Speedup (warm):     {v1_time/v2_warm:.1f}×")
        
        # Victory conditions
        print("\n" + "=" * 80)
        print("VICTORY CONDITIONS")
        print("=" * 80)
        
        cold_speedup = v1_time / v2_cold
        warm_speedup = v1_time / v2_warm
        hit_rate = stats['hit_rate'] * 100 if stats else 0
        
        print(f"\n  H002: 20× speedup target")
        if cold_speedup >= 20:
            print(f"    ✅ ACHIEVED: {cold_speedup:.1f}× speedup (cold)")
        elif warm_speedup >= 20:
            print(f"    ✅ ACHIEVED: {warm_speedup:.1f}× speedup (warm)")
        else:
            print(f"    ⚠️  PARTIAL: {cold_speedup:.1f}× cold, {warm_speedup:.1f}× warm")
        
        print(f"\n  H002: 80%+ cache hit rate target")
        if hit_rate >= 80:
            print(f"    ✅ ACHIEVED: {hit_rate:.1f}% hit rate")
        else:
            print(f"    ⚠️  PARTIAL: {hit_rate:.1f}% hit rate")
        
        print(f"\n  Overall assessment:")
        if cold_speedup >= 20 and hit_rate >= 80:
            print("    ✅ H002 COMPLETE - All victory conditions met!")
        elif cold_speedup >= 10 or warm_speedup >= 20:
            print("    🎯 H002 PARTIAL - Significant speedup achieved")
        else:
            print("    ⚠️  H002 IN PROGRESS - More optimization needed")
    
    print("\n" + "=" * 80)


if __name__ == "__main__":
    main()
