#!/usr/bin/env python3
"""Deep Cluster Analysis - Phase 3B

Investigates top semantic clusters to understand their content,
implications, and potential for pattern extraction.
"""

import sys
import json
import sqlite3
from pathlib import Path
from typing import Dict, List

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("DEEP CLUSTER ANALYSIS - Phase 3B")
print("="*80)

# Load mining results
results_file = ROOT / "reports/comprehensive_galaxy_mining_results.json"
with open(results_file) as f:
    results = json.load(f)

# Galaxy paths
galaxy_paths = {
    "hot_archive": str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_hot.db"),
    "cold_storage": str(Path.home() / "Desktop/whitemagic_memory_archive/whitemagic_cold.db"),
    "primary_pre_merge": str(Path.home() / "Desktop/wm_archive/phase6_dead_files/primary_db_pre_merge.db"),
}

def get_cluster_memories(db_path: str, tags: List[str], limit: int = 5) -> List[Dict]:
    """Fetch sample memories from a cluster."""
    conn = sqlite3.connect(db_path)
    conn.row_factory = sqlite3.Row
    
    # Build query for memories with these tags
    placeholders = ','.join('?' * len(tags))
    query = f"""
        SELECT DISTINCT m.id, m.title, m.content, m.importance, m.created_at
        FROM memories m
        JOIN tags t ON m.id = t.memory_id
        WHERE t.tag IN ({placeholders})
        AND m.memory_type != 'quarantined'
        ORDER BY m.importance DESC
        LIMIT ?
    """
    
    cursor = conn.execute(query, tags + [limit])
    memories = [dict(row) for row in cursor.fetchall()]
    conn.close()
    
    return memories

print("\n📊 ANALYZING TOP 20 CLUSTERS BY IMPORTANCE")
print("="*80)

top_by_importance = results['top_clusters_by_importance'][:20]

for i, cluster in enumerate(top_by_importance, 1):
    print(f"\n{'='*80}")
    print(f"CLUSTER #{i}: {cluster['id']}")
    print(f"{'='*80}")
    print(f"Size: {cluster['size']} memories")
    print(f"Importance: {cluster['importance']:.2f}")
    print(f"Tags: {', '.join(cluster['tags'][:10])}")
    
    # Try to find sample memories from each galaxy
    samples_found = False
    for galaxy_name, db_path in galaxy_paths.items():
        if not Path(db_path).exists():
            continue
            
        try:
            samples = get_cluster_memories(db_path, cluster['tags'], limit=3)
            if samples:
                samples_found = True
                print(f"\n📝 Sample memories from {galaxy_name}:")
                for j, mem in enumerate(samples, 1):
                    title = mem['title'] or '(Untitled)'
                    content_preview = mem['content'][:150].replace('\n', ' ') if mem['content'] else '(No content)'
                    print(f"  {j}. {title}")
                    print(f"     Importance: {mem['importance']:.2f}")
                    print(f"     Preview: {content_preview}...")
                break  # Only show from first galaxy that has samples
        except Exception as e:
            print(f"  Error fetching from {galaxy_name}: {e}")
    
    if not samples_found:
        print("\n⚠️  No sample memories found for this cluster")

print("\n" + "="*80)
print("📊 ANALYZING TOP 20 CLUSTERS BY SIZE")
print("="*80)

top_by_size = results['top_clusters_by_size'][:20]

for i, cluster in enumerate(top_by_size, 1):
    print(f"\n{'='*80}")
    print(f"CLUSTER #{i}: {cluster['id']}")
    print(f"{'='*80}")
    print(f"Size: {cluster['size']} memories")
    print(f"Importance: {cluster['importance']:.2f}")
    print(f"Tags: {', '.join(cluster['tags'][:10])}")
    
    # Analyze what this cluster represents
    cluster_type = "Unknown"
    implications = []
    
    tags_str = ' '.join(cluster['tags']).lower()
    
    if any(x in tags_str for x in ['windsurf', 'conversation', 'transcript']):
        cluster_type = "🎯 High-Value Session Data"
        implications = [
            "Contains Windsurf conversation transcripts",
            "High importance (0.86) indicates quality content",
            "Potential source for conversation pattern mining",
            "May contain optimization insights from past sessions"
        ]
    elif any(x in tags_str for x in ['sangha', 'intelligence', 'implementation']):
        cluster_type = "🧠 Strategic Planning"
        implications = [
            "Contains strategic planning documents",
            "Very high importance (0.96-1.08) = critical content",
            "Likely contains architectural decisions",
            "Prime candidate for pattern extraction"
        ]
    elif any(x in tags_str for x in ['golang', 'bitnet', 'llama', 'pion']):
        cluster_type = "📦 External Library Code"
        implications = [
            "Contains external library/dependency code",
            "Lower importance (0.20-0.24) = reference material",
            "Useful for understanding dependencies",
            "Not primary source for optimization patterns"
        ]
    elif any(x in tags_str for x in ['test', 'testdata', 'examples']):
        cluster_type = "🧪 Test & Example Code"
        implications = [
            "Contains test files and examples",
            "Medium importance (0.21-0.22)",
            "May contain usage patterns",
            "Good for understanding API evolution"
        ]
    elif any(x in tags_str for x in ['md', 'txt', 'marker']):
        cluster_type = "📄 Documentation Files"
        implications = [
            "Contains markdown/text documentation",
            "Medium-low importance (0.20-0.25)",
            "May contain design decisions",
            "Useful for context but not primary patterns"
        ]
    elif any(x in tags_str for x in ['antigravity', 'meta', 'archaeology']):
        cluster_type = "🔍 Meta-Analysis Content"
        implications = [
            "Contains self-referential analysis",
            "High importance (0.90-0.92)",
            "Recursive evolution insights",
            "Critical for understanding system evolution"
        ]
    
    print(f"\n🏷️  Type: {cluster_type}")
    print("💡 Implications:")
    for imp in implications:
        print(f"   • {imp}")

print("\n" + "="*80)
print("🎯 KEY INSIGHTS & RECOMMENDATIONS")
print("="*80)

print("""
1. **HIGH-VALUE CLUSTERS (Importance > 0.85)**:
   • Windsurf conversations (184 memories, 0.86 importance)
   • Sangha/Intelligence planning (2-37 memories, 0.96-1.08 importance)
   • Antigravity/Meta analysis (34-37 memories, 0.90-0.92 importance)
   
   → These should be PRIMARY sources for pattern mining
   → High confidence patterns from these clusters

2. **EXTERNAL CODE CLUSTERS (Importance 0.20-0.24)**:
   • Golang ecosystem (1,520 memories)
   • BitNet, llama.cpp, 3rdparty libraries
   
   → Filter these OUT of optimization pattern mining
   → Useful for dependency analysis only

3. **CROSS-VALIDATED TAGS (255 tags in multiple clusters)**:
   • mcp_fixes, whitemagic, reflection (appearing 2+ times)
   • These have HIGHER confidence due to multiple sources
   
   → Prioritize patterns from cross-validated tags
   → Build confidence scoring based on cluster count

4. **PATTERN EXTRACTION PRIORITIES**:
   Priority 1: Windsurf conversations + Sangha planning (strategic insights)
   Priority 2: Meta-analysis + Archaeology (evolution patterns)
   Priority 3: Cross-validated tags (high confidence)
   Priority 4: Test/example code (API usage patterns)
   Priority 5: External libraries (reference only, low priority)

5. **GENESEED SCANNER TARGETS**:
   • Focus on whitemagicpublic commits tagged with high-importance cluster tags
   • Cross-reference git history with Windsurf conversation timestamps
   • Track evolution of features mentioned in meta-analysis clusters
""")

print("\n" + "="*80)
print("✅ CLUSTER ANALYSIS COMPLETE")
print("="*80)
print(f"Analyzed: {len(top_by_importance)} high-importance + {len(top_by_size)} high-size clusters")
print("Next: Build geneseed scanner to mine git history patterns")
