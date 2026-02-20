#!/usr/bin/env python3
"""Comprehensive Galaxy Mining - Phase 3 Recursive Evolution

Fine-tuned parameters for maximum pattern discovery across 114K+ memories.
Generates detailed analysis reports for top clusters and patterns.
"""

import sys
import json
import time
from pathlib import Path
from collections import defaultdict, Counter
from typing import Dict, List, Any

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.optimization.rust_accelerators import (
    mine_access_patterns,
    mine_cache_candidates,
    mine_semantic_clusters,
    get_galaxy_stats,
)

print("="*80)
print("COMPREHENSIVE GALAXY MINING - Phase 3 Recursive Evolution")
print("="*80)

# Galaxy paths (priority order)
galaxy_paths = {
    "hot_archive": str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_hot.db"),
    "cold_storage": str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_cold.db"),
    "primary_pre_merge": str(Path.home() / "Desktop/wm_archive/phase6_dead_files/primary_db_pre_merge.db"),
}

# Fine-tuned parameters for expansive discovery
MINING_PARAMS = {
    "access_patterns": {
        "min_frequency": 2,  # Lower from 5 to catch more patterns
    },
    "cache_candidates": {
        "min_access": 2,      # Lower from 10 for archives
        "min_importance": 0.3, # Lower from 0.7 to be more inclusive
    },
    "semantic_clusters": {
        "min_cluster_size": 2,  # Lower from 3 to catch smaller clusters
    }
}

print("\n📊 Mining Parameters (Fine-Tuned for Maximum Discovery):")
print(f"  Access Patterns: min_frequency={MINING_PARAMS['access_patterns']['min_frequency']}")
print(f"  Cache Candidates: min_access={MINING_PARAMS['cache_candidates']['min_access']}, min_importance={MINING_PARAMS['cache_candidates']['min_importance']}")
print(f"  Semantic Clusters: min_cluster_size={MINING_PARAMS['semantic_clusters']['min_cluster_size']}")

# Results storage
all_stats = {}
all_access_patterns = []
all_cache_patterns = []
all_clusters = []

print("\n" + "="*80)
print("PHASE 1: DATABASE STATISTICS")
print("="*80)

start = time.time()
for name, path in galaxy_paths.items():
    if Path(path).exists():
        stats = get_galaxy_stats(path)
        all_stats[name] = stats
        print(f"\n{name}:")
        print(f"  Total memories: {stats.get('total_memories', 0):,}")
        print(f"  High access: {stats.get('high_access_memories', 0):,}")
        print(f"  High importance: {stats.get('high_importance_memories', 0):,}")
        print(f"  Total tags: {stats.get('total_tags', 0):,}")
stats_time = time.time() - start
print(f"\n✓ Stats collected in {stats_time:.2f}s")

print("\n" + "="*80)
print("PHASE 2: ACCESS PATTERN MINING")
print("="*80)

start = time.time()
for name, path in galaxy_paths.items():
    if Path(path).exists():
        patterns = mine_access_patterns(path, MINING_PARAMS['access_patterns']['min_frequency'])
        # Store source galaxy separately since AccessPattern is immutable
        for p in patterns:
            all_access_patterns.append((name, p))
        print(f"  {name}: {len(patterns)} patterns")
access_time = time.time() - start
print(f"\n✓ Found {len(all_access_patterns)} access patterns in {access_time:.2f}s")

print("\n" + "="*80)
print("PHASE 3: CACHE CANDIDATE MINING")
print("="*80)

start = time.time()
for name, path in galaxy_paths.items():
    if Path(path).exists():
        patterns = mine_cache_candidates(
            path, 
            MINING_PARAMS['cache_candidates']['min_access'],
            MINING_PARAMS['cache_candidates']['min_importance']
        )
        # Store source galaxy separately since AccessPattern is immutable
        for p in patterns:
            all_cache_patterns.append((name, p))
        print(f"  {name}: {len(patterns)} patterns")
cache_time = time.time() - start
print(f"\n✓ Found {len(all_cache_patterns)} cache patterns in {cache_time:.2f}s")

print("\n" + "="*80)
print("PHASE 4: SEMANTIC CLUSTER MINING")
print("="*80)

start = time.time()
for name, path in galaxy_paths.items():
    if Path(path).exists():
        clusters = mine_semantic_clusters(path, MINING_PARAMS['semantic_clusters']['min_cluster_size'])
        all_clusters.extend(clusters)
        print(f"  {name}: {len(clusters)} clusters")
cluster_time = time.time() - start
print(f"\n✓ Found {len(all_clusters)} semantic clusters in {cluster_time:.2f}s")

# Analyze results
total_time = stats_time + access_time + cache_time + cluster_time
total_memories = sum(s.get('total_memories', 0) for s in all_stats.values())

print("\n" + "="*80)
print("COMPREHENSIVE MINING RESULTS")
print("="*80)

print(f"\n⚡ Performance:")
print(f"  Total time: {total_time:.2f}s")
print(f"  Memories processed: {total_memories:,}")
print(f"  Processing rate: {total_memories/total_time:,.0f} memories/sec")

print(f"\n📊 Patterns Discovered:")
print(f"  Access patterns: {len(all_access_patterns)}")
print(f"  Cache candidates: {len(all_cache_patterns)}")
print(f"  Semantic clusters: {len(all_clusters)}")

# Sort clusters by size and importance
clusters_by_size = sorted(all_clusters, key=lambda c: c.size, reverse=True)
clusters_by_importance = sorted(all_clusters, key=lambda c: c.avg_importance, reverse=True)

print(f"\n🏆 TOP 20 SEMANTIC CLUSTERS BY SIZE:")
for i, cluster in enumerate(clusters_by_size[:20], 1):
    tags_str = ", ".join(cluster.common_tags[:5])
    if len(cluster.common_tags) > 5:
        tags_str += f" (+{len(cluster.common_tags)-5} more)"
    print(f"  {i:2d}. {cluster.cluster_id:30s} | Size: {cluster.size:4d} | Importance: {cluster.avg_importance:.2f}")
    print(f"      Tags: {tags_str}")

print(f"\n⭐ TOP 20 SEMANTIC CLUSTERS BY IMPORTANCE:")
for i, cluster in enumerate(clusters_by_importance[:20], 1):
    tags_str = ", ".join(cluster.common_tags[:5])
    if len(cluster.common_tags) > 5:
        tags_str += f" (+{len(cluster.common_tags)-5} more)"
    print(f"  {i:2d}. {cluster.cluster_id:30s} | Importance: {cluster.avg_importance:.2f} | Size: {cluster.size:4d}")
    print(f"      Tags: {tags_str}")

if all_access_patterns:
    print(f"\n🔥 TOP 10 ACCESS PATTERNS:")
    sorted_access = sorted(all_access_patterns, key=lambda x: x[1].frequency, reverse=True)
    for i, (source, pattern) in enumerate(sorted_access[:10], 1):
        print(f"  {i:2d}. {pattern.pattern_id:40s} | Freq: {pattern.frequency:4d} | Confidence: {pattern.confidence:.1%} | Source: {source}")
        print(f"      Memories: {len(pattern.memory_ids)}")

if all_cache_patterns:
    print(f"\n💾 TOP 10 CACHE CANDIDATES:")
    sorted_cache = sorted(all_cache_patterns, key=lambda x: x[1].confidence, reverse=True)
    for i, (source, pattern) in enumerate(sorted_cache[:10], 1):
        print(f"  {i:2d}. {pattern.pattern_id:40s} | Confidence: {pattern.confidence:.1%} | Freq: {pattern.frequency:4d} | Source: {source}")
        print(f"      Memories: {len(pattern.memory_ids)}")

# Cross-validation analysis
print(f"\n🔍 CROSS-VALIDATION ANALYSIS:")

# Find clusters appearing in multiple galaxies
cluster_tags = defaultdict(list)
for cluster in all_clusters:
    for tag in cluster.common_tags:
        cluster_tags[tag].append(cluster)

multi_galaxy_tags = {}
for tag, clusters in cluster_tags.items():
    if len(clusters) > 1:
        multi_galaxy_tags[tag] = clusters

print(f"  Tags appearing in multiple clusters: {len(multi_galaxy_tags)}")
print(f"  Top cross-validated tags:")
sorted_tags = sorted(multi_galaxy_tags.items(), key=lambda x: len(x[1]), reverse=True)
for tag, clusters in sorted_tags[:10]:
    total_size = sum(c.size for c in clusters)
    avg_importance = sum(c.avg_importance for c in clusters) / len(clusters)
    print(f"    {tag:30s} | Clusters: {len(clusters):2d} | Total size: {total_size:4d} | Avg importance: {avg_importance:.2f}")

# Save detailed results
output_dir = ROOT / "reports"
output_dir.mkdir(exist_ok=True)

results = {
    "timestamp": time.strftime("%Y-%m-%d %H:%M:%S"),
    "parameters": MINING_PARAMS,
    "performance": {
        "total_time_seconds": total_time,
        "total_memories": total_memories,
        "processing_rate": total_memories / total_time,
    },
    "statistics": all_stats,
    "patterns": {
        "access_patterns_count": len(all_access_patterns),
        "cache_candidates_count": len(all_cache_patterns),
        "semantic_clusters_count": len(all_clusters),
    },
    "top_clusters_by_size": [
        {
            "id": c.cluster_id,
            "size": c.size,
            "importance": c.avg_importance,
            "tags": c.common_tags,
        }
        for c in clusters_by_size[:20]
    ],
    "top_clusters_by_importance": [
        {
            "id": c.cluster_id,
            "size": c.size,
            "importance": c.avg_importance,
            "tags": c.common_tags,
        }
        for c in clusters_by_importance[:20]
    ],
    "cross_validated_tags": {
        tag: {
            "cluster_count": len(clusters),
            "total_size": sum(c.size for c in clusters),
            "avg_importance": sum(c.avg_importance for c in clusters) / len(clusters),
        }
        for tag, clusters in sorted_tags[:20]
    }
}

output_file = output_dir / "comprehensive_galaxy_mining_results.json"
with open(output_file, 'w') as f:
    json.dump(results, f, indent=2)

print(f"\n💾 Detailed results saved to: {output_file}")

print("\n" + "="*80)
print("✅ COMPREHENSIVE GALAXY MINING COMPLETE!")
print(f"🚀 Processed {total_memories:,} memories in {total_time:.2f}s")
print(f"📊 Discovered {len(all_clusters)} semantic clusters")
print(f"🔍 Found {len(multi_galaxy_tags)} cross-validated tags")
print("="*80)
