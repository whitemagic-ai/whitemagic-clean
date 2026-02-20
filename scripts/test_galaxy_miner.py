#!/usr/bin/env python3
"""Test Galaxy Pattern Miner - Phase 3 Recursive Evolution

Tests the GalaxyPatternMiner on hot archive, cold storage, and primary pre-merge DBs.
Mines patterns from 111K+ archived memories.
"""

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.evolution.galaxy_miner import get_galaxy_miner

print("="*80)
print("GALAXY PATTERN MINER TEST - Phase 3 Recursive Evolution")
print("="*80)

# Priority order: hot archive → cold storage → primary pre-merge
galaxy_paths = [
    str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_hot.db"),
    str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_cold.db"),
    str(Path.home() / "Desktop/wm_archive/phase6_dead_files/primary_db_pre_merge.db"),
]

print("\n[1/7] Initializing GalaxyPatternMiner...")
miner = get_galaxy_miner(galaxy_paths)
print("✓ Initialized")

print("\n[2/7] Connecting to galaxy databases...")
miner.connect()
print(f"✓ Connected to {len(miner.connections)} galaxies")

print("\n[3/7] Mining access patterns (min_frequency=5)...")
access_patterns = miner.mine_access_patterns(min_frequency=5)
print(f"✓ Found {len(access_patterns)} access patterns")

print("\n[4/7] Mining co-access patterns (min_co_occurrence=3)...")
co_access_patterns = miner.mine_co_access_patterns(min_co_occurrence=3)
print(f"✓ Found {len(co_access_patterns)} co-access patterns")

print("\n[5/7] Mining cache candidates (min_access=10, min_importance=0.7)...")
cache_patterns = miner.mine_cache_candidates(min_access=10, min_importance=0.7)
print(f"✓ Found {len(cache_patterns)} cache candidate patterns")

print("\n[6/7] Mining semantic clusters (min_cluster_size=3)...")
semantic_clusters = miner.mine_semantic_clusters(min_cluster_size=3)
print(f"✓ Found {len(semantic_clusters)} semantic clusters")

print("\n[7/7] Generating summary...")
summary = miner.get_summary()

print("\n" + "="*80)
print("GALAXY MINING RESULTS")
print("="*80)

print(f"\nGalaxies Analyzed: {summary['galaxies_analyzed']}")
print(f"Total Patterns: {summary['total_patterns']}")
print(f"Total Clusters: {summary['total_clusters']}")
print(f"Avg Pattern Confidence: {summary['avg_pattern_confidence']:.2%}")
print(f"Avg Cluster Size: {summary['avg_cluster_size']:.1f} memories")

print("\nPattern Types:")
for pattern_type, count in summary['pattern_types'].items():
    print(f"  {pattern_type}: {count}")

# Show top patterns
if access_patterns:
    print("\n📊 Top Access Patterns:")
    for i, pattern in enumerate(access_patterns[:3], 1):
        print(f"  {i}. {pattern.pattern_id}")
        print(f"     Frequency: {pattern.frequency}, Confidence: {pattern.confidence:.1%}")
        print(f"     Memories: {len(pattern.memory_ids)}")

if cache_patterns:
    print("\n💾 Top Cache Candidates:")
    for i, pattern in enumerate(cache_patterns[:3], 1):
        print(f"  {i}. {pattern.pattern_id}")
        print(f"     Candidates: {pattern.metadata['total_candidates']}")
        print(f"     Avg Access: {pattern.metadata['avg_access_count']:.1f}")
        print(f"     Avg Importance: {pattern.metadata['avg_importance']:.2f}")

if semantic_clusters:
    print("\n🌐 Top Semantic Clusters:")
    for i, cluster in enumerate(semantic_clusters[:5], 1):
        print(f"  {i}. {cluster.cluster_id}")
        print(f"     Size: {len(cluster.memory_ids)} memories")
        print(f"     Avg Importance: {cluster.avg_importance:.2f}")
        print(f"     Galaxies: {len(cluster.galaxy_sources)}")

print("\n" + "="*80)
print("DISCONNECTING")
print("="*80)
miner.disconnect()
print("✓ All connections closed")

print("\n✅ Galaxy mining test complete!")
print(f"\n🎯 Discovered {summary['total_patterns']} patterns from {summary['galaxies_analyzed']} galaxies")
print("These patterns will feed the recursive evolution engine!")
