#!/usr/bin/env python3
"""Mine Active MCP DB - Extract Real-Time Usage Patterns

Mines the active MCP database (~/.whitemagic/memory/whitemagic.db)
for current usage patterns, high-importance memories, and cross-validation data.
"""

import sys
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

import whitemagic_rs

print("="*80)
print("ACTIVE MCP DB MINING - Real-Time Usage Patterns")
print("="*80)

# Active MCP DB path
active_db = Path.home() / ".whitemagic/memory/whitemagic.db"

if not active_db.exists():
    print(f"\n❌ Active MCP DB not found: {active_db}")
    sys.exit(1)

print(f"\n✅ Found active MCP DB: {active_db}")

# Get statistics
print("\n[1/3] Getting database statistics...")
try:
    stats = whitemagic_rs.get_galaxy_stats(str(active_db))
    # stats is a dict
    print(f"  Total memories: {stats['total_memories']:,}")
    print(f"  High importance memories: {stats.get('high_importance_memories', 0):,}")
    print(f"  Total tags: {stats.get('total_tags', 0):,}")
    print(f"  High access memories: {stats.get('high_access_memories', 0):,}")
except Exception as e:
    print(f"  ❌ Error: {e}")
    import traceback
    traceback.print_exc()
    sys.exit(1)

# Mine semantic clusters
print("\n[2/3] Mining semantic clusters...")
print("  Min cluster size: 2 (expansive)")

try:
    clusters = whitemagic_rs.mine_semantic_clusters(str(active_db), 2)
    print(f"  ✅ Found {len(clusters)} semantic clusters")
    
    # Group by tag
    tag_clusters = {}
    for cluster in clusters:
        for tag in cluster.common_tags:
            if tag not in tag_clusters:
                tag_clusters[tag] = []
            tag_clusters[tag].append(cluster)
    
    print(f"  Unique tags: {len(tag_clusters)}")
    
    # Top 10 by importance
    sorted_clusters = sorted(clusters, key=lambda c: c.avg_importance, reverse=True)
    print("\n  Top 10 clusters by importance:")
    for i, cluster in enumerate(sorted_clusters[:10], 1):
        tags_str = ", ".join(cluster.common_tags[:3])
        print(f"    {i}. {cluster.cluster_id}: {cluster.size} memories, importance={cluster.avg_importance:.2f}")
        print(f"       Tags: {tags_str}")
    
except Exception as e:
    print(f"  ❌ Error: {e}")
    import traceback
    traceback.print_exc()
    clusters = []

# Mine access patterns
print("\n[3/3] Mining access patterns...")
print("  Min frequency: 2")

try:
    access_patterns = whitemagic_rs.mine_access_patterns(str(active_db), 2)
    print(f"  ✅ Found {len(access_patterns)} access patterns")
    
    if access_patterns:
        sorted_patterns = sorted(access_patterns, key=lambda p: p.frequency, reverse=True)
        print("\n  Top 5 most accessed:")
        for i, pattern in enumerate(sorted_patterns[:5], 1):
            print(f"    {i}. Memory {pattern.memory_id}: {pattern.frequency} accesses")
            print(f"       Avg importance: {pattern.avg_importance:.2f}")
    
except Exception as e:
    print(f"  ❌ Error: {e}")
    access_patterns = []

# Prepare data for cross-validation
print(f"\n{'='*80}")
print("PREPARING DATA FOR CROSS-VALIDATION")
print(f"{'='*80}")

# Build cross-validated tags (tags appearing in multiple clusters)
cross_validated_tags = {}
for tag, cluster_list in tag_clusters.items():
    if len(cluster_list) >= 2:  # Appears in 2+ clusters
        total_size = sum(c.size for c in cluster_list)
        avg_importance = sum(c.avg_importance * c.size for c in cluster_list) / total_size
        
        cross_validated_tags[tag] = {
            'cluster_count': len(cluster_list),
            'total_size': total_size,
            'avg_importance': avg_importance,
        }

print(f"\nCross-validated tags: {len(cross_validated_tags)}")

if cross_validated_tags:
    # Top 10 by importance
    sorted_tags = sorted(cross_validated_tags.items(), key=lambda x: x[1]['avg_importance'], reverse=True)
    print("\nTop 10 cross-validated tags by importance:")
    for i, (tag, data) in enumerate(sorted_tags[:10], 1):
        print(f"  {i}. {tag}")
        print(f"     Clusters: {data['cluster_count']}, Size: {data['total_size']}, Importance: {data['avg_importance']:.2f}")

# Save results
output_dir = ROOT / "reports"
output_dir.mkdir(exist_ok=True)

results = {
    'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
    'database': str(active_db),
    'stats': stats,
    'patterns': {
        'semantic_clusters_count': len(clusters),
        'access_patterns_count': len(access_patterns),
        'cross_validated_tags_count': len(cross_validated_tags),
    },
    'cross_validated_tags': cross_validated_tags,
    'top_clusters': [
        {
            'cluster_id': c.cluster_id,
            'size': c.size,
            'avg_importance': c.avg_importance,
            'common_tags': c.common_tags,
        }
        for c in sorted_clusters[:20]
    ] if 'sorted_clusters' in locals() else [],
}

output_file = output_dir / "active_mcp_mining_results.json"
with open(output_file, 'w') as f:
    json.dump(results, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ ACTIVE MCP DB MINING COMPLETE")
print("Ready for cross-validation with galaxy archives")
print(f"{'='*80}")
