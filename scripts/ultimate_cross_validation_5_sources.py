#!/usr/bin/env python3
"""Ultimate Cross-Validation - All 5 Sources Combined

Combines patterns from ALL available sources:
1. Galaxy archives (114K memories)
2. Active MCP DB (112K memories)
3. Session handoffs (140 files)
4. Windsurf conversations (when available)
5. Aria archives (202 files, 70K lines)

Uses Rust accelerators for 30x speedup.
Identifies cross-source patterns for maximum confidence.
"""

import sys
import json
import time
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

import whitemagic_rs

print("="*80)
print("ULTIMATE CROSS-VALIDATION - All 5 Sources Combined")
print("="*80)

# Load all mining results
sources = {
    'galaxy': ROOT / "reports/comprehensive_galaxy_mining_results.json",
    'active_mcp': ROOT / "reports/active_mcp_mining_results.json",
    'sessions': ROOT / "reports/session_handoff_mining_results.json",
    'windsurf': ROOT / "reports/windsurf_conversation_mining_results.json",
    'aria': ROOT / "reports/aria_archive_mining_results.json",
}

loaded_sources = {}
for name, path in sources.items():
    if path.exists():
        with open(path) as f:
            loaded_sources[name] = json.load(f)

print(f"\n✅ Loaded {len(loaded_sources)} data sources:")
for name, data in loaded_sources.items():
    if name == 'galaxy':
        count = data['performance']['total_memories']
    elif name == 'active_mcp':
        count = data['stats']['total_memories']
    elif name == 'sessions':
        count = data['files_processed']
    elif name == 'windsurf':
        count = data.get('conversations_processed', 0)
    elif name == 'aria':
        count = data.get('md_files_processed', 0) + data.get('json_files_processed', 0)
    
    print(f"   {name:12s}: {count:,} items")

# Combine all cross-validated tags
print(f"\n{'='*80}")
print("COMBINING CROSS-VALIDATED TAGS FROM ALL SOURCES")
print(f"{'='*80}")

all_tags = {}

for source_name, data in loaded_sources.items():
    cv_tags = data.get('cross_validated_tags', {})
    
    for tag, tag_data in cv_tags.items():
        if tag in all_tags:
            all_tags[tag]['sources'].append(source_name)
            all_tags[tag]['cluster_count'] += tag_data['cluster_count']
            all_tags[tag]['total_size'] += tag_data['total_size']
            
            # Weighted average importance
            total = all_tags[tag]['total_size']
            all_tags[tag]['avg_importance'] = (
                all_tags[tag]['avg_importance'] * (total - tag_data['total_size']) +
                tag_data['avg_importance'] * tag_data['total_size']
            ) / total
        else:
            all_tags[tag] = {
                'sources': [source_name],
                'cluster_count': tag_data['cluster_count'],
                'total_size': tag_data['total_size'],
                'avg_importance': tag_data['avg_importance'],
            }

print(f"\nTotal unique tags: {len(all_tags)}")

# Analyze cross-source validation
source_counts = defaultdict(int)
for tag, data in all_tags.items():
    source_count = len(data['sources'])
    source_counts[source_count] += 1

print(f"\nCross-source validation distribution:")
for count in sorted(source_counts.keys(), reverse=True):
    print(f"  {count} sources: {source_counts[count]} patterns")

# Identify cross-source patterns (appearing in 2+ sources)
cross_source_patterns = {
    tag: data for tag, data in all_tags.items()
    if len(data['sources']) >= 2
}

print(f"\n🎯 Cross-source patterns (2+ sources): {len(cross_source_patterns)}")
if cross_source_patterns:
    print(f"\n   Top 10 cross-source patterns:")
    sorted_cross = sorted(
        cross_source_patterns.items(),
        key=lambda x: (len(x[1]['sources']), x[1]['total_size']),
        reverse=True
    )
    for i, (tag, data) in enumerate(sorted_cross[:10], 1):
        print(f"   {i:2d}. {tag:20s}: {len(data['sources'])} sources, "
              f"{data['total_size']:4d} mentions")
        print(f"       Sources: {', '.join(data['sources'])}")

# Prepare for Rust scoring
print(f"\n{'='*80}")
print("RUST PATTERN SCORING WITH CROSS-SOURCE BOOST")
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

# Apply cross-source boost to patterns appearing in multiple sources
multi_source_tags = [tag for tag, data in all_tags.items() if len(data['sources']) > 1]
if multi_source_tags:
    print(f"\nApplying cross-source boost to {len(multi_source_tags)} patterns...")
    scored = whitemagic_rs.apply_cross_source_boost(scored, multi_source_tags, None)

# Get statistics
stats_json = whitemagic_rs.get_scoring_stats(scored)
stats = json.loads(stats_json)

print(f"\n{'='*80}")
print("CONFIDENCE DISTRIBUTION")
print(f"{'='*80}")

print(f"\n  Ultra-high (≥0.77): {stats['ultra_high_confidence']}")
print(f"  High (0.60-0.77):   {stats['high_confidence']}")
print(f"  Medium (0.50-0.60): {stats['medium_confidence']}")
print(f"  Average: {stats['avg_confidence']:.2%}")
print(f"  Cross-validated: {stats['cross_validated']}")

# Extract top patterns
ultra_high = whitemagic_rs.filter_patterns(scored, 0.77, None)
high = whitemagic_rs.filter_patterns(scored, 0.60, None)

print(f"\n{'='*80}")
print(f"🎯 ULTRA-HIGH-CONFIDENCE PATTERNS (≥0.77)")
print(f"{'='*80}")

if ultra_high:
    print(f"\n✅ Found {len(ultra_high)} ultra-high-confidence patterns!")
    print(f"\nTop 15 patterns ready for automatic application:")
    
    for i, p in enumerate(ultra_high[:15], 1):
        tag = p.pattern_id.replace('galaxy_', '')
        sources = all_tags[tag]['sources']
        print(f"\n{i:2d}. **{tag}** ({p.final_confidence:.2%})")
        print(f"    Sources: {', '.join(sources)} ({len(sources)} sources)")
        print(f"    CV={p.cv_score:.2%}, Outcome={p.outcome_score:.2%}, "
              f"Freq={p.frequency_score:.2%}, Long={p.longevity_score:.2%}")

# Analyze by source combination
print(f"\n{'='*80}")
print("PATTERN ANALYSIS BY SOURCE COMBINATION")
print(f"{'='*80}")

source_combo_stats = defaultdict(lambda: {'count': 0, 'avg_confidence': 0.0, 'patterns': []})

for p in ultra_high:
    tag = p.pattern_id.replace('galaxy_', '')
    sources = tuple(sorted(all_tags[tag]['sources']))
    source_combo_stats[sources]['count'] += 1
    source_combo_stats[sources]['avg_confidence'] += p.final_confidence
    source_combo_stats[sources]['patterns'].append(tag)

for sources, stats_data in sorted(source_combo_stats.items(), key=lambda x: x[1]['count'], reverse=True):
    avg_conf = stats_data['avg_confidence'] / stats_data['count']
    print(f"\n{'+'.join(sources)} ({stats_data['count']} patterns, avg {avg_conf:.2%}):")
    for pattern in stats_data['patterns'][:5]:
        print(f"  - {pattern}")

# Save comprehensive results
output = {
    'timestamp': time.strftime("%Y-%m-%d %H:%M:%S"),
    'sources_loaded': list(loaded_sources.keys()),
    'total_patterns': len(scored),
    'ultra_high_confidence': len(ultra_high),
    'high_confidence': len(high),
    'cross_source_patterns': len(cross_source_patterns),
    'stats': stats,
    'ultra_high_patterns': [
        {
            'pattern_id': p.pattern_id,
            'tag': p.pattern_id.replace('galaxy_', ''),
            'confidence': p.final_confidence,
            'sources': all_tags[p.pattern_id.replace('galaxy_', '')]['sources'],
            'source_count': len(all_tags[p.pattern_id.replace('galaxy_', '')]['sources']),
            'cv_score': p.cv_score,
            'outcome_score': p.outcome_score,
            'frequency_score': p.frequency_score,
            'longevity_score': p.longevity_score,
            'cross_validated': p.cross_validated,
            'cluster_count': all_tags[p.pattern_id.replace('galaxy_', '')]['cluster_count'],
            'total_size': all_tags[p.pattern_id.replace('galaxy_', '')]['total_size'],
        }
        for p in ultra_high
    ],
    'cross_source_patterns': [
        {
            'tag': tag,
            'sources': data['sources'],
            'source_count': len(data['sources']),
            'total_size': data['total_size'],
        }
        for tag, data in sorted_cross[:20]
    ] if cross_source_patterns else [],
}

output_file = ROOT / "reports/ultimate_cross_validation_5_sources.json"
with open(output_file, 'w') as f:
    json.dump(output, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ ULTIMATE CROSS-VALIDATION COMPLETE")
print(f"🎉 {len(ultra_high)} ultra-high-confidence patterns from {len(loaded_sources)} sources!")
print(f"{'='*80}")
