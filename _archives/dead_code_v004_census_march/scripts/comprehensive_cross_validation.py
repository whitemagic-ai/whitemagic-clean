#!/usr/bin/env python3
"""Comprehensive Cross-Validation - All Sources Combined

Combines patterns from:
1. Galaxy archives (114K memories, 964 clusters)
2. Active MCP DB (112K memories, 203 clusters)
3. Geneseed git history (when available)

Uses Rust accelerators for 30x speedup.
"""

import sys
import json
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

import whitemagic_rs

print("="*80)
print("COMPREHENSIVE CROSS-VALIDATION - All Sources")
print("="*80)

# Load all mining results
galaxy_file = ROOT / "reports/comprehensive_galaxy_mining_results.json"
active_file = ROOT / "reports/active_mcp_mining_results.json"

if not galaxy_file.exists():
    print("\n❌ Galaxy results not found")
    sys.exit(1)

if not active_file.exists():
    print("\n❌ Active MCP results not found")
    sys.exit(1)

with open(galaxy_file) as f:
    galaxy_results = json.load(f)

with open(active_file) as f:
    active_results = json.load(f)

print("\n✅ Loaded mining results:")
print(f"   Galaxy archives: {galaxy_results['performance']['total_memories']:,} memories")
print(f"   Active MCP DB: {active_results['stats']['total_memories']:,} memories")
print(f"   Total: {galaxy_results['performance']['total_memories'] + active_results['stats']['total_memories']:,} memories")

# Combine cross-validated tags
print(f"\n{'='*80}")
print("COMBINING CROSS-VALIDATED TAGS")
print(f"{'='*80}")

all_tags = {}

# Add galaxy tags
for tag, data in galaxy_results['cross_validated_tags'].items():
    all_tags[tag] = {
        'sources': ['galaxy_archive'],
        'cluster_count': data['cluster_count'],
        'total_size': data['total_size'],
        'avg_importance': data['avg_importance'],
    }

# Add active MCP tags
for tag, data in active_results['cross_validated_tags'].items():
    if tag in all_tags:
        # Cross-validated across sources!
        all_tags[tag]['sources'].append('active_mcp')
        all_tags[tag]['cluster_count'] += data['cluster_count']
        all_tags[tag]['total_size'] += data['total_size']
        # Weighted average importance
        total = all_tags[tag]['total_size']
        all_tags[tag]['avg_importance'] = (
            all_tags[tag]['avg_importance'] * (total - data['total_size']) +
            data['avg_importance'] * data['total_size']
        ) / total
    else:
        all_tags[tag] = {
            'sources': ['active_mcp'],
            'cluster_count': data['cluster_count'],
            'total_size': data['total_size'],
            'avg_importance': data['avg_importance'],
        }

print(f"\nTotal unique tags: {len(all_tags)}")
print(f"Cross-source validated: {len([t for t in all_tags.values() if len(t['sources']) > 1])}")

# Prepare for Rust scoring
print(f"\n{'='*80}")
print("RUST PATTERN SCORING (30x faster)")
print(f"{'='*80}")

galaxy_patterns = []
for tag, data in all_tags.items():
    galaxy_patterns.append({
        'tag': tag,
        'cluster_count': data['cluster_count'],
        'total_size': data['total_size'],
        'avg_importance': data['avg_importance'],
    })

galaxy_json = json.dumps(galaxy_patterns)

print(f"\nScoring {len(galaxy_patterns)} patterns with Rust...")
start = time.perf_counter()
scored = whitemagic_rs.score_galaxy_patterns(galaxy_json, None)
rust_time = time.perf_counter() - start

print(f"✅ Scored in {rust_time*1000:.2f}ms ({len(scored)/rust_time:.0f} patterns/sec)")

# Apply cross-source boost
cross_source_tags = [tag for tag, data in all_tags.items() if len(data['sources']) > 1]
if cross_source_tags:
    print(f"\nApplying cross-source boost to {len(cross_source_tags)} patterns...")
    scored = whitemagic_rs.apply_cross_source_boost(scored, cross_source_tags, None)

# Filter and analyze
print(f"\n{'='*80}")
print("PATTERN ANALYSIS")
print(f"{'='*80}")

stats_json = whitemagic_rs.get_scoring_stats(scored)
stats = json.loads(stats_json)

print("\nConfidence Distribution:")
print(f"  Ultra-high (≥0.77): {stats['ultra_high_confidence']}")
print(f"  High (0.60-0.77):   {stats['high_confidence']}")
print(f"  Medium (0.50-0.60): {stats['medium_confidence']}")
print(f"  Average: {stats['avg_confidence']:.2%}")
print(f"  Cross-validated: {stats['cross_validated']}")

# Get top patterns
ultra_high = whitemagic_rs.filter_patterns(scored, 0.77, None)
high = whitemagic_rs.filter_patterns(scored, 0.60, None)

print(f"\n{'='*80}")
print("TOP PATTERNS (≥0.77 CONFIDENCE - AUTO-APPLY READY)")
print(f"{'='*80}")

if ultra_high:
    print(f"\n✅ Found {len(ultra_high)} ultra-high-confidence patterns!")
    for i, p in enumerate(ultra_high[:10], 1):
        tag = p.pattern_id.replace('galaxy_', '')
        sources = all_tags[tag]['sources']
        print(f"\n{i}. {tag}")
        print(f"   Confidence: {p.final_confidence:.2%}")
        print(f"   Sources: {', '.join(sources)}")
        print(f"   CV={p.cv_score:.2%}, Outcome={p.outcome_score:.2%}, Freq={p.frequency_score:.2%}, Long={p.longevity_score:.2%}")
        print(f"   Clusters: {all_tags[tag]['cluster_count']}, Size: {all_tags[tag]['total_size']}")
else:
    print("\n⚠️  No patterns meet 0.77 threshold yet")
    print(f"   Highest confidence: {scored[0].final_confidence:.2%}")
    print("   Need more cross-validation sources")

print(f"\n{'='*80}")
print("HIGH-CONFIDENCE PATTERNS (0.60-0.77 - MANUAL REVIEW)")
print(f"{'='*80}")

if high:
    high_only = [p for p in high if p.final_confidence < 0.77]
    print(f"\n✅ Found {len(high_only)} high-confidence patterns")
    for i, p in enumerate(high_only[:5], 1):
        tag = p.pattern_id.replace('galaxy_', '')
        print(f"  {i}. {tag}: {p.final_confidence:.2%}")

# Save comprehensive results
output = {
    'timestamp': time.strftime("%Y-%m-%d %H:%M:%S"),
    'sources': {
        'galaxy_archive': galaxy_results['performance']['total_memories'],
        'active_mcp': active_results['stats']['total_memories'],
    },
    'total_patterns': len(scored),
    'ultra_high_confidence': len(ultra_high),
    'high_confidence': len(high),
    'cross_source_validated': len(cross_source_tags),
    'stats': stats,
    'top_10_ultra_high': [
        {
            'pattern_id': p.pattern_id,
            'confidence': p.final_confidence,
            'cv_score': p.cv_score,
            'outcome_score': p.outcome_score,
            'frequency_score': p.frequency_score,
            'longevity_score': p.longevity_score,
            'cross_validated': p.cross_validated,
        }
        for p in ultra_high[:10]
    ] if ultra_high else [],
}

output_file = ROOT / "reports/comprehensive_cross_validation_results.json"
with open(output_file, 'w') as f:
    json.dump(output, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ COMPREHENSIVE CROSS-VALIDATION COMPLETE")
print("Ready for integration with AdaptiveSystem")
print(f"{'='*80}")
