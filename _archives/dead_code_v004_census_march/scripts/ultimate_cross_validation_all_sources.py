#!/usr/bin/env python3
"""Ultimate Cross-Validation - All 6 Data Sources

Combines patterns from:
1. Galaxy archives (114K memories)
2. Active MCP DB (112K memories)
3. Session handoffs (140 files)
4. Aria archives (389 files)
5. Windsurf conversations (0 - fallback)
6. Comprehensive codebase (507K lines markdown + 7M lines code)
"""

import sys
import json
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

import whitemagic_rs

print("="*80)
print("ULTIMATE CROSS-VALIDATION - All 6 Data Sources")
print("="*80)

reports_dir = ROOT / "reports"

sources = {
    'galaxy': 'galaxy_pattern_mining_results.json',
    'active_mcp': 'active_mcp_mining_results.json',
    'sessions': 'session_handoff_mining_results.json',
    'aria': 'aria_archive_mining_results.json',
    'windsurf': 'windsurf_mining_results.json',
    'codebase': 'comprehensive_codebase_mining_results.json',
}

all_patterns = {}
source_stats = {}

print("\nLoading patterns from 6 sources...")
for source_name, filename in sources.items():
    filepath = reports_dir / filename
    if not filepath.exists():
        print(f"  ⚠️  {source_name:12s}: not found")
        continue
    
    with open(filepath) as f:
        data = json.load(f)
    
    tags = data.get('cross_validated_tags', {})
    source_stats[source_name] = len(tags)
    print(f"  ✅ {source_name:12s}: {len(tags):3d} patterns")
    
    for tag, info in tags.items():
        if tag not in all_patterns:
            all_patterns[tag] = {
                'sources': [],
                'total_count': 0,
                'total_files': 0,
                'avg_importance': 0.0,
                'source_data': {},
            }
        
        all_patterns[tag]['sources'].append(source_name)
        all_patterns[tag]['total_count'] += info.get('total_size', 0)
        all_patterns[tag]['total_files'] += info.get('cluster_count', 0)
        all_patterns[tag]['avg_importance'] = max(
            all_patterns[tag]['avg_importance'],
            info.get('avg_importance', 0.0)
        )
        all_patterns[tag]['source_data'][source_name] = info

print(f"\n  Total unique patterns: {len(all_patterns)}")

# Prepare for Rust scoring
print(f"\n{'='*80}")
print("RUST PATTERN SCORING")
print(f"{'='*80}")

patterns_for_rust = []
for tag, data in all_patterns.items():
    patterns_for_rust.append({
        'tag': tag,
        'cluster_count': data['total_files'],
        'total_size': data['total_count'],
        'avg_importance': data['avg_importance'],
    })

patterns_json = json.dumps(patterns_for_rust)

print(f"\nScoring {len(patterns_for_rust)} patterns...")
start = time.perf_counter()
scored = whitemagic_rs.score_galaxy_patterns(patterns_json, None)
score_time = time.perf_counter() - start
print(f"  Scored in {score_time*1000:.2f}ms ({len(patterns_for_rust)/score_time:.0f} patterns/sec)")

# Apply cross-source boost
multi_source_tags = [tag for tag, data in all_patterns.items() if len(data['sources']) >= 2]
print(f"\nApplying cross-source boost to {len(multi_source_tags)} multi-source patterns...")

start = time.perf_counter()
boosted = whitemagic_rs.apply_cross_source_boost(scored, multi_source_tags, None)
boost_time = time.perf_counter() - start
print(f"  Boosted in {boost_time*1000:.2f}ms")

# Filter ultra-high confidence
ultra_high = whitemagic_rs.filter_patterns(boosted, 0.77, None)
print(f"\n  Ultra-high patterns (≥0.77): {len(ultra_high)}")

# Analyze by source count
source_count_dist = {}
for pattern in ultra_high:
    # Strip galaxy_ prefix added by Rust scorer
    tag = pattern.pattern_id.replace('galaxy_', '')
    if tag not in all_patterns:
        continue
    source_count = len(all_patterns[tag]['sources'])
    if source_count not in source_count_dist:
        source_count_dist[source_count] = []
    source_count_dist[source_count].append(pattern)

print("\n  Distribution by source count:")
for count in sorted(source_count_dist.keys(), reverse=True):
    patterns = source_count_dist[count]
    print(f"    {count} sources: {len(patterns):3d} patterns")

# Top patterns
print(f"\n{'='*80}")
print("TOP 30 ULTRA-HIGH-CONFIDENCE PATTERNS")
print(f"{'='*80}")

ultra_high_sorted = sorted(ultra_high, key=lambda x: x.final_confidence, reverse=True)

for i, pattern in enumerate(ultra_high_sorted[:30], 1):
    tag = pattern.pattern_id.replace('galaxy_', '')
    if tag not in all_patterns:
        continue
    sources = all_patterns[tag]['sources']
    source_str = '+'.join(sources[:3])
    if len(sources) > 3:
        source_str += f'+{len(sources)-3}more'
    
    print(f"{i:2d}. {tag:18s}: {pattern.final_confidence:.2%} "
          f"({len(sources)} sources: {source_str})")

# Save results
output = {
    'timestamp': time.strftime("%Y-%m-%d %H:%M:%S"),
    'sources_loaded': source_stats,
    'total_patterns': len(all_patterns),
    'multi_source_patterns': len(multi_source_tags),
    'ultra_high_patterns': len(ultra_high),
    'source_count_distribution': {k: len(v) for k, v in source_count_dist.items()},
    'ultra_high_list': [
        {
            'tag': (tag := p.pattern_id.replace('galaxy_', '')),
            'confidence': p.final_confidence,
            'source_count': len(all_patterns[tag]['sources']),
            'sources': all_patterns[tag]['sources'],
            'total_count': all_patterns[tag]['total_count'],
            'total_files': all_patterns[tag]['total_files'],
        }
        for p in ultra_high_sorted
        if (tag := p.pattern_id.replace('galaxy_', '')) in all_patterns
    ],
    'performance': {
        'scoring_time_ms': score_time * 1000,
        'boost_time_ms': boost_time * 1000,
        'patterns_per_sec': len(patterns_for_rust) / score_time,
    }
}

output_file = reports_dir / "ultimate_cross_validation_all_6_sources.json"
with open(output_file, 'w') as f:
    json.dump(output, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")
print(f"\n{'='*80}")
print("✅ ULTIMATE CROSS-VALIDATION COMPLETE")
print(f"{'='*80}")
