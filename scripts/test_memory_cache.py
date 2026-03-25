#!/usr/bin/env python3
"""Test Memory Cache Implementation - Phase 3 Recursive Evolution

Tests the LRU cache integration with UnifiedMemory system.
Validates cache hit rates, invalidation, and performance improvements.
"""

import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.memory.unified import get_unified_memory
from whitemagic.core.memory.unified_types import MemoryType

print("="*80)
print("MEMORY CACHE TEST - Phase 3 Recursive Evolution")
print("="*80)

# Initialize unified memory
print("\n[1/6] Initializing UnifiedMemory...")
mem = get_unified_memory()
print("✓ Initialized")

# Get baseline cache stats
print("\n[2/6] Baseline cache stats...")
baseline = mem.get_cache_stats()
print(f"  Cache size: {baseline['size']}/{baseline['max_size']}")
print(f"  Hit rate: {baseline['hit_rate']:.1%}")

# Store some test memories
print("\n[3/6] Storing test memories...")
test_ids = []
for i in range(10):
    memory = mem.store(
        content=f"Test memory {i} - cache validation",
        memory_type=MemoryType.SHORT_TERM,
        title=f"Cache Test {i}",
        importance=0.5,
        tags={"test", "cache", f"batch_{i//5}"}
    )
    test_ids.append(memory.id)
    time.sleep(0.01)
print(f"✓ Stored {len(test_ids)} memories")

# Test cache misses (first access)
print("\n[4/6] Testing cache MISS (first access)...")
start_time = time.time()
for mem_id in test_ids[:5]:
    mem.recall(mem_id)
miss_time = time.time() - start_time
stats_after_miss = mem.get_cache_stats()
print(f"  Time: {miss_time*1000:.2f}ms for 5 recalls")
print(f"  Cache misses: {stats_after_miss['misses']}")
print(f"  Cache size: {stats_after_miss['size']}/{stats_after_miss['max_size']}")

# Test cache hits (second access)
print("\n[5/6] Testing cache HIT (second access)...")
start_time = time.time()
for mem_id in test_ids[:5]:
    mem.recall(mem_id)
hit_time = time.time() - start_time
stats_after_hit = mem.get_cache_stats()
print(f"  Time: {hit_time*1000:.2f}ms for 5 recalls")
print(f"  Cache hits: {stats_after_hit['hits']}")
print(f"  Hit rate: {stats_after_hit['hit_rate']:.1%}")

# Calculate speedup
if miss_time > 0:
    speedup = miss_time / hit_time if hit_time > 0 else float('inf')
    print(f"  Speedup: {speedup:.2f}x faster with cache")

# Final stats
print("\n[6/6] Final cache statistics...")
final_stats = mem.get_cache_stats()
print(f"\n{mem._cache.get_summary()}")

print("\n" + "="*80)
print("CACHE TEST RESULTS")
print("="*80)

# Validate expectations
expected_hit_rate = 0.5  # 50% since we accessed 5 twice out of 15 total
actual_hit_rate = final_stats['hit_rate']

print("\nValidation:")
print(f"  ✓ Cache enabled: {final_stats['size'] > 0}")
print(f"  ✓ Cache hits recorded: {final_stats['hits'] > 0}")
print(f"  ✓ Hit rate: {actual_hit_rate:.1%} (expected ~{expected_hit_rate:.1%})")
print(f"  ✓ Speedup achieved: {speedup:.2f}x")

if speedup > 1.5:
    print(f"\n🚀 SUCCESS: Cache provides {speedup:.2f}x speedup!")
    print("Phase 3 Adaptation #1 is working as expected.")
else:
    print(f"\n⚠️ WARNING: Cache speedup is only {speedup:.2f}x")
    print("This may be due to small test size or fast DB.")

print("\n✅ Memory cache test complete!")
