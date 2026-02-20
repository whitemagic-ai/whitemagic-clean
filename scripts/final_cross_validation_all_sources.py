#!/usr/bin/env python3
"""Final Cross-Validation - All Sources Combined

Combines patterns from ALL sources:
1. Galaxy archives (114K memories, 964 clusters)
2. Active MCP DB (112K memories, 203 clusters)
3. Session handoffs (140 files, 15 strategic patterns)
4. Geneseed git history (when available)

Uses Rust accelerators for 30x speedup.
Targets: 5+ patterns > 0.77 confidence for auto-application.
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
print("FINAL CROSS-VALIDATION - All Sources Combined")
print("="*80)

# Load all mining results
galaxy_file = ROOT / "reports/comprehensive_galaxy_mining_results.json"
active_file = ROOT / "reports/active_mcp_mining_results.json"
session_file = ROOT / "reports/session_handoff_mining_results.json"

sources_loaded = []
if galaxy_file.exists():
    with open(galaxy_file) as f:
        galaxy_results = json.load(f)
    sources_loaded.append(('galaxy', galaxy_results['performance']['total_memories']))

if active_file.exists():
    with open(active_file) as f:
        active_results = json.load(f)
    sources_loaded.append(('active_mcp', active_results['stats']['total_memories']))

if session_file.exists():
    with open(session_file) as f:
        session_results = json.load(f)
    sources_loaded.append(('sessions', session_results['files_processed']))

print(f"\n✅ Loaded {len(sources_loaded)} data sources:")
for source, count in sources_loaded:
    print(f"   {source:12s}: {count:,} items")

total_items = sum(count for _, count in sources_loaded)
print(f"   Total: {total_items:,} items processed")

# Combine all cross-validated tags
print(f"\n{'='*80}")
print("COMBINING CROSS-VALIDATED TAGS FROM ALL SOURCES")
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
        all_tags[tag]['sources'].append('active_mcp')
        all_tags[tag]['cluster_count'] += data['cluster_count']
        all_tags[tag]['total_size'] += data['total_size']
        # Weighted average
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

# Add session handoff tags
for tag, data in session_results['cross_validated_tags'].items():
    if tag in all_tags:
        all_tags[tag]['sources'].append('session_handoffs')
        all_tags[tag]['cluster_count'] += data['cluster_count']
        all_tags[tag]['total_size'] += data['total_size']
        # Weighted average
        total = all_tags[tag]['total_size']
        all_tags[tag]['avg_importance'] = (
            all_tags[tag]['avg_importance'] * (total - data['total_size']) +
            data['avg_importance'] * data['total_size']
        ) / total
    else:
        all_tags[tag] = {
            'sources': ['session_handoffs'],
            'cluster_count': data['cluster_count'],
            'total_size': data['total_size'],
            'avg_importance': data['avg_importance'],
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
print(f"🎯 ULTRA-HIGH-CONFIDENCE PATTERNS (≥0.77 - AUTO-APPLY READY)")
print(f"{'='*80}")

if ultra_high:
    print(f"\n✅ SUCCESS! Found {len(ultra_high)} ultra-high-confidence patterns!")
    print(f"\nThese patterns are ready for automatic application:")
    
    for i, p in enumerate(ultra_high[:10], 1):
        tag = p.pattern_id.replace('galaxy_', '')
        sources = all_tags[tag]['sources']
        print(f"\n{i}. **{tag}**")
        print(f"   Confidence: {p.final_confidence:.2%}")
        print(f"   Sources: {', '.join(sources)} ({len(sources)} sources)")
        print(f"   Components:")
        print(f"     - Cross-validation: {p.cv_score:.2%}")
        print(f"     - Outcome (importance): {p.outcome_score:.2%}")
        print(f"     - Frequency: {p.frequency_score:.2%}")
        print(f"     - Longevity: {p.longevity_score:.2%}")
        print(f"   Metrics:")
        print(f"     - Clusters: {all_tags[tag]['cluster_count']}")
        print(f"     - Total size: {all_tags[tag]['total_size']}")
        print(f"     - Avg importance: {all_tags[tag]['avg_importance']:.2f}")
else:
    print(f"\n⚠️  No patterns meet 0.77 threshold yet")
    if scored:
        top = scored[0]
        tag = top.pattern_id.replace('galaxy_', '')
        print(f"\n   Highest confidence: {top.final_confidence:.2%} ({tag})")
        print(f"   Sources: {', '.join(all_tags[tag]['sources'])}")
        print(f"   Need: {0.77 - top.final_confidence:.2%} more confidence")

print(f"\n{'='*80}")
print(f"HIGH-CONFIDENCE PATTERNS (0.60-0.77 - MANUAL REVIEW QUEUE)")
print(f"{'='*80}")

if high:
    high_only = [p for p in high if p.final_confidence < 0.77]
    if high_only:
        print(f"\n✅ Found {len(high_only)} high-confidence patterns for manual review:")
        for i, p in enumerate(high_only[:10], 1):
            tag = p.pattern_id.replace('galaxy_', '')
            sources = all_tags[tag]['sources']
            print(f"  {i:2d}. {tag:20s}: {p.final_confidence:.2%} ({len(sources)} sources)")

# Identify patterns for foreknowledge
print(f"\n{'='*80}")
print("🔮 FOREKNOWLEDGE: Where WhiteMagic Needs to Go Next")
print(f"{'='*80}")

# Analyze session handoff patterns for strategic direction
strategic_patterns = session_results['top_20_patterns'][:10]
print(f"\nTop strategic patterns from 140 session handoffs:")
for i, pattern in enumerate(strategic_patterns, 1):
    print(f"\n{i}. **{pattern['keyword']}** (score: {pattern['final_score']:.2%})")
    print(f"   Mentioned {pattern['count']} times across {pattern['file_spread']} sessions")
    if pattern['sample_contexts']:
        print(f"   Context: {pattern['sample_contexts'][0][:100]}...")

# Performance gains discovered
perf_gains = session_results.get('performance_gains', [])
if perf_gains:
    print(f"\n📈 Historical performance gains discovered:")
    for i, gain in enumerate(perf_gains[:5], 1):
        print(f"  {i}. {gain['gain']:.0f}x speedup (from {gain['source']})")

# Save comprehensive results
output = {
    'timestamp': time.strftime("%Y-%m-%d %H:%M:%S"),
    'sources': {
        'galaxy_archive': galaxy_results['performance']['total_memories'],
        'active_mcp': active_results['stats']['total_memories'],
        'session_handoffs': session_results['files_processed'],
        'total_items': total_items,
    },
    'total_patterns': len(scored),
    'ultra_high_confidence': len(ultra_high),
    'high_confidence': len(high),
    'cross_source_validated': len(multi_source_tags),
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
        }
        for p in ultra_high
    ],
    'strategic_direction': strategic_patterns[:5],
    'performance_gains': perf_gains[:10],
}

output_file = ROOT / "reports/final_cross_validation_all_sources.json"
with open(output_file, 'w') as f:
    json.dump(output, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

print(f"\n{'='*80}")
print("✅ FINAL CROSS-VALIDATION COMPLETE")
if ultra_high:
    print(f"🎉 {len(ultra_high)} patterns ready for AdaptiveSystem integration!")
else:
    print(f"📊 Analysis complete - ready for next steps")
print(f"{'='*80}")
