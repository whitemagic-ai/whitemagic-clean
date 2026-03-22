#!/usr/bin/env python3
"""Test Rust Galaxy Miner - Phase 3 Recursive Evolution

High-performance Rust implementation for mining 111K+ memories.
"""

import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("RUST GALAXY MINER TEST - Phase 3 Recursive Evolution")
print("="*80)

# Import Rust module
try:
    from whitemagic.optimization.rust_accelerators import (
        mine_access_patterns,
        mine_cache_candidates,
        mine_semantic_clusters,
        get_galaxy_stats,
    )
    print("\n✓ Rust galaxy miner imported successfully")
except ImportError as e:
    print(f"\n❌ Failed to import Rust galaxy miner: {e}")
    print("Trying direct import...")
    try:
        import whitemagic_rs
        mine_access_patterns = whitemagic_rs.mine_access_patterns
        mine_cache_candidates = whitemagic_rs.mine_cache_candidates
        mine_semantic_clusters = whitemagic_rs.mine_semantic_clusters
        get_galaxy_stats = whitemagic_rs.get_galaxy_stats
        print("✓ Direct import successful")
    except ImportError as e2:
        print(f"❌ Direct import also failed: {e2}")
        sys.exit(1)

# Galaxy paths (priority order)
galaxy_paths = [
    str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_hot.db"),
    str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_cold.db"),
    str(Path.home() / "Desktop/wm_archive/phase6_dead_files/primary_db_pre_merge.db"),
]

print("\n[1/5] Getting galaxy statistics...")
start = time.time()
all_stats = {}
for path in galaxy_paths:
    if Path(path).exists():
        stats = get_galaxy_stats(path)
        all_stats[Path(path).name] = stats
        print(f"  {Path(path).name}:")
        print(f"    Total memories: {stats.get('total_memories', 0):,}")
        print(f"    High access: {stats.get('high_access_memories', 0):,}")
        print(f"    High importance: {stats.get('high_importance_memories', 0):,}")
        print(f"    Total tags: {stats.get('total_tags', 0):,}")
stats_time = time.time() - start
print(f"✓ Stats collected in {stats_time:.2f}s")

print("\n[2/5] Mining access patterns (min_frequency=5)...")
start = time.time()
all_access_patterns = []
for path in galaxy_paths:
    if Path(path).exists():
        patterns = mine_access_patterns(path, 5)
        all_access_patterns.extend(patterns)
        print(f"  {Path(path).name}: {len(patterns)} patterns")
access_time = time.time() - start
print(f"✓ Found {len(all_access_patterns)} access patterns in {access_time:.2f}s")

print("\n[3/5] Mining cache candidates (min_access=10, min_importance=0.7)...")
start = time.time()
all_cache_patterns = []
for path in galaxy_paths:
    if Path(path).exists():
        patterns = mine_cache_candidates(path, 10, 0.7)
        all_cache_patterns.extend(patterns)
        print(f"  {Path(path).name}: {len(patterns)} patterns")
cache_time = time.time() - start
print(f"✓ Found {len(all_cache_patterns)} cache patterns in {cache_time:.2f}s")

print("\n[4/5] Mining semantic clusters (min_cluster_size=3)...")
start = time.time()
all_clusters = []
for path in galaxy_paths:
    if Path(path).exists():
        clusters = mine_semantic_clusters(path, 3)
        all_clusters.extend(clusters)
        print(f"  {Path(path).name}: {len(clusters)} clusters")
cluster_time = time.time() - start
print(f"✓ Found {len(all_clusters)} semantic clusters in {cluster_time:.2f}s")

print("\n[5/5] Analyzing results...")
total_time = stats_time + access_time + cache_time + cluster_time

print("\n" + "="*80)
print("RUST GALAXY MINING RESULTS")
print("="*80)

print("\nPerformance:")
print(f"  Total time: {total_time:.2f}s")
print(f"  Stats: {stats_time:.2f}s")
print(f"  Access patterns: {access_time:.2f}s")
print(f"  Cache candidates: {cache_time:.2f}s")
print(f"  Semantic clusters: {cluster_time:.2f}s")

print(f"\nGalaxies Analyzed: {len(all_stats)}")
for name, stats in all_stats.items():
    print(f"  {name}: {stats.get('total_memories', 0):,} memories")

print("\nPatterns Discovered:")
print(f"  Access patterns: {len(all_access_patterns)}")
print(f"  Cache candidates: {len(all_cache_patterns)}")
print(f"  Semantic clusters: {len(all_clusters)}")

if all_access_patterns:
    print("\n📊 Top Access Patterns:")
    for i, pattern in enumerate(all_access_patterns[:3], 1):
        print(f"  {i}. {pattern.pattern_id}")
        print(f"     Frequency: {pattern.frequency}, Confidence: {pattern.confidence:.1%}")
        print(f"     Memories: {len(pattern.memory_ids)}")

if all_cache_patterns:
    print("\n💾 Top Cache Candidates:")
    for i, pattern in enumerate(all_cache_patterns[:3], 1):
        print(f"  {i}. {pattern.pattern_id}")
        print(f"     Memories: {len(pattern.memory_ids)}")
        print(f"     Frequency: {pattern.frequency}")
        print(f"     Confidence: {pattern.confidence:.1%}")

if all_clusters:
    print("\n🌐 Top Semantic Clusters:")
    for i, cluster in enumerate(all_clusters[:5], 1):
        print(f"  {i}. {cluster.cluster_id}")
        print(f"     Size: {cluster.size} memories")
        print(f"     Avg Importance: {cluster.avg_importance:.2f}")

print("\n" + "="*80)
print("✅ Rust galaxy mining complete!")
print(f"🚀 Processed {sum(s.get('total_memories', 0) for s in all_stats.values()):,} memories in {total_time:.2f}s")
print("These patterns will feed the recursive evolution engine!")
