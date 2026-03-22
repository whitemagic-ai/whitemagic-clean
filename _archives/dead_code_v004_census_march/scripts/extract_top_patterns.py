#!/usr/bin/env python3
"""Extract Top 10 Ultra-High-Confidence Patterns

Cross-validates galaxy patterns and extracts the top 10 for analysis.
Since geneseed patterns are limited (new repo), focuses on galaxy archive patterns.
"""

import sys
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

print("="*80)
print("TOP 10 ULTRA-HIGH-CONFIDENCE PATTERN EXTRACTION")
print("="*80)

# Load galaxy mining results
galaxy_file = ROOT / "reports/comprehensive_galaxy_mining_results.json"
if not galaxy_file.exists():
    print("\n❌ Galaxy results not found")
    sys.exit(1)

with open(galaxy_file) as f:
    galaxy_results = json.load(f)

print("\n✅ Galaxy mining results loaded:")
print(f"   Memories: {galaxy_results['performance']['total_memories']:,}")
print(f"   Clusters: {galaxy_results['patterns']['semantic_clusters_count']}")
print(f"   Cross-validated tags: {len(galaxy_results['cross_validated_tags'])}")

# Score patterns using multi-factor confidence
print(f"\n{'='*80}")
print("PATTERN SCORING (Cross-Val 40% + Outcome 30% + Freq 20% + Long 10%)")
print(f"{'='*80}")

scored_patterns = []

for tag, data in galaxy_results['cross_validated_tags'].items():
    # Cross-validation score (multiple clusters = higher confidence)
    cv_score = min(data['cluster_count'] / 5.0, 1.0)
    
    # Outcome score (importance)
    outcome_score = min(data['avg_importance'] / 1.0, 1.0)
    
    # Frequency score (total memories)
    freq_score = min(data['total_size'] / 100.0, 1.0)
    
    # Longevity score (archive data = proven)
    longevity_score = 0.8
    
    # Final confidence (weighted)
    final_confidence = (
        0.4 * cv_score +
        0.3 * outcome_score +
        0.2 * freq_score +
        0.1 * longevity_score
    )
    
    scored_patterns.append({
        'tag': tag,
        'confidence': final_confidence,
        'cv_score': cv_score,
        'outcome_score': outcome_score,
        'freq_score': freq_score,
        'longevity_score': longevity_score,
        'cluster_count': data['cluster_count'],
        'total_size': data['total_size'],
        'avg_importance': data['avg_importance'],
    })

# Sort by confidence
scored_patterns.sort(key=lambda x: x['confidence'], reverse=True)

print(f"\nTotal scored patterns: {len(scored_patterns)}")
print(f"Patterns above 0.77 threshold: {len([p for p in scored_patterns if p['confidence'] >= 0.77])}")

# Extract top 10
top_10 = scored_patterns[:10]

print(f"\n{'='*80}")
print("TOP 10 ULTRA-HIGH-CONFIDENCE PATTERNS")
print(f"{'='*80}")

for i, pattern in enumerate(top_10, 1):
    print(f"\n{i}. {pattern['tag']}")
    print(f"   Final Confidence: {pattern['confidence']:.2%}")
    print(f"   ├─ Cross-Validation: {pattern['cv_score']:.2%} ({pattern['cluster_count']} clusters)")
    print(f"   ├─ Outcome (Importance): {pattern['outcome_score']:.2%} (avg {pattern['avg_importance']:.2f})")
    print(f"   ├─ Frequency: {pattern['freq_score']:.2%} ({pattern['total_size']} memories)")
    print(f"   └─ Longevity: {pattern['longevity_score']:.2%} (archive proven)")

# Analyze top patterns for insights
print(f"\n{'='*80}")
print("PATTERN ANALYSIS & INSIGHTS")
print(f"{'='*80}")

# Group by confidence tier
ultra_high = [p for p in scored_patterns if p['confidence'] >= 0.77]
high = [p for p in scored_patterns if 0.6 <= p['confidence'] < 0.77]
medium = [p for p in scored_patterns if 0.5 <= p['confidence'] < 0.6]

print("\nConfidence Distribution:")
print(f"  Ultra-High (≥0.77): {len(ultra_high)} patterns")
print(f"  High (0.60-0.77):   {len(high)} patterns")
print(f"  Medium (0.50-0.60): {len(medium)} patterns")

# Identify pattern categories
print("\nPattern Categories (Top 10):")

strategic = []
technical = []
meta = []
external = []

for p in top_10:
    tag_lower = p['tag'].lower()
    if any(x in tag_lower for x in ['sangha', 'intelligence', 'phase', 'plan', 'strategy']):
        strategic.append(p['tag'])
    elif any(x in tag_lower for x in ['windsurf', 'conversation', 'transcript', 'session']):
        meta.append(p['tag'])
    elif any(x in tag_lower for x in ['mcp', 'whitemagic', 'rust', 'python']):
        technical.append(p['tag'])
    else:
        external.append(p['tag'])

if strategic:
    print(f"  🎯 Strategic Planning ({len(strategic)}): {', '.join(strategic[:3])}")
if meta:
    print(f"  🔍 Meta-Analysis ({len(meta)}): {', '.join(meta[:3])}")
if technical:
    print(f"  🔧 Technical ({len(technical)}): {', '.join(technical[:3])}")
if external:
    print(f"  📦 External/Other ({len(external)}): {', '.join(external[:3])}")

# Recommendations
print(f"\n{'='*80}")
print("RECOMMENDATIONS FOR RECURSIVE EVOLUTION")
print(f"{'='*80}")

print(f"\n1. **Auto-Apply Patterns (Confidence ≥0.77)**: {len(ultra_high)} patterns")
print("   These have multi-source validation and high importance.")
print("   Safe for automatic application without review.")

print(f"\n2. **Manual Review Queue (0.60-0.77)**: {len(high)} patterns")
print("   High confidence but below auto-apply threshold.")
print("   Quick human review before application.")

print(f"\n3. **Pattern Library (0.50-0.60)**: {len(medium)} patterns")
print("   Store for reference and future cross-validation.")
print("   May gain confidence as more data arrives.")

# Specific insights from top patterns
print("\n4. **Key Insights from Top 10**:")

if any('windsurf' in p['tag'].lower() for p in top_10):
    print("   • Windsurf conversation patterns detected")
    print("     → Mine session transcripts for optimization insights")

if any('sangha' in p['tag'].lower() or 'intelligence' in p['tag'].lower() for p in top_10):
    print("   • Strategic planning patterns detected")
    print("     → Extract architectural decisions for pattern library")

if any('mcp' in p['tag'].lower() for p in top_10):
    print("   • MCP-related patterns detected")
    print("     → Analyze tool usage patterns for optimization")

# Save results
output = {
    'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
    'total_patterns': len(scored_patterns),
    'confidence_distribution': {
        'ultra_high': len(ultra_high),
        'high': len(high),
        'medium': len(medium),
    },
    'top_10': [
        {
            'rank': i+1,
            'tag': p['tag'],
            'confidence': p['confidence'],
            'components': {
                'cross_validation': p['cv_score'],
                'outcome': p['outcome_score'],
                'frequency': p['freq_score'],
                'longevity': p['longevity_score'],
            },
            'metrics': {
                'cluster_count': p['cluster_count'],
                'total_size': p['total_size'],
                'avg_importance': p['avg_importance'],
            }
        }
        for i, p in enumerate(top_10)
    ],
}

output_file = ROOT / "reports/top_10_patterns.json"
with open(output_file, 'w') as f:
    json.dump(output, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ TOP 10 PATTERN EXTRACTION COMPLETE")
print("Ready for integration with AdaptiveSystem")
print(f"{'='*80}")
