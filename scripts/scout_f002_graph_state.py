#!/usr/bin/env python3
"""
F002 Graph Reconstruction Scout
Assesses current state of knowledge graph for campaign completion.
"""
import json
import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.tools.unified_api import call_tool

def scout_graph_state():
    """Scout current graph state for F002 campaign."""
    print("🔍 F002 Graph Reconstruction Scout Report")
    print("=" * 60)
    
    # Get cluster stats
    result = call_tool("cluster_stats")
    if result.get("status") == "success":
        stats = result.get("details", {})
        print("\n📊 Current Cluster State:")
        print(f"  Total clusters: {stats.get('total_clusters', 'N/A')}")
        print(f"  Total memories: {stats.get('total_memories', 'N/A'):,}")
        print(f"  Avg cluster size: {stats.get('avg_cluster_size', 'N/A'):.1f}")
        print(f"  Large clusters (>1000): {stats.get('large_clusters', 'N/A')}")
    
    # Get health report for graph info
    health = call_tool("health_report")
    if health.get("status") == "success":
        details = health.get("details", {})
        db = details.get("db", {})
        print("\n💾 Database State:")
        print(f"  Memory count: {db.get('memory_count', 'N/A'):,}")
        print(f"  DB size: {db.get('size_mb', 'N/A'):.1f} MB")
    
    # Search for graph-related memories
    print("\n🔎 Graph-Related Content:")
    
    # Check for community detection results
    communities = call_tool("search_memories", query="community detection graph", limit=5)
    if communities.get("status") == "success":
        results = communities.get("details", {}).get("results", [])
        print(f"  Community detection memories: {len(results)}")
    
    # Check for bridge node results  
    bridges = call_tool("search_memories", query="bridge node graph topology", limit=5)
    if bridges.get("status") == "success":
        results = bridges.get("details", {}).get("results", [])
        print(f"  Bridge node memories: {len(results)}")
    
    print("\n📋 F002 Victory Condition Assessment:")
    print("  [ ] Full graph rebuild with typed edges - NEEDS WORK")
    print("  [ ] 10-30 real communities - Current: ~112 clusters (need analysis)")
    print("  [ ] Named themed communities - NEEDS WORK")
    print("  [ ] Bridge nodes identified - NEEDS WORK")
    print("  [ ] Top-10 PageRank meaningful - NEEDS WORK")
    print("  [ ] Graph visualization exported - NEEDS WORK")
    print("  [ ] Semantic path queries working - NEEDS WORK")
    print("  [ ] Constellation detection actionable - NEEDS WORK")
    
    return {
        "campaign": "F002",
        "clusters": stats.get("total_clusters", 0),
        "memories": stats.get("total_memories", 0),
        "assessment": "NEEDS_FULL_REBUILD"
    }

if __name__ == "__main__":
    result = scout_graph_state()
    print("\n✅ Scout complete. JSON output:")
    print(json.dumps(result, indent=2))
