#!/usr/bin/env python3
"""Deploy Polyglot Scouts - Massive-scale Python codebase analysis

Deploys 500K+ Unified Zodiac Army scouts to analyze every Python file
and generate comprehensive polyglot migration roadmap.
"""

import sys
import json
import time
from pathlib import Path
from datetime import datetime

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.agents.polyglot_scout import PolyglotScoutCommander
from whitemagic.agents.unified_zodiac_army import UnifiedZodiacCommander

print("="*80)
print("POLYGLOT SCOUTING CAMPAIGN - Operation Babel Scout")
print("="*80)
print()

# Initialize commander
commander = PolyglotScoutCommander(ROOT)

# Define target directories (5 waves)
waves = {
    'Wave 1: Core Systems': [
        'whitemagic/core/memory',
        'whitemagic/core/acceleration',
        'whitemagic/core/resonance',
        'whitemagic/inference',
    ],
    'Wave 2: Intelligence Layer': [
        'whitemagic/intelligence',
        'whitemagic/patterns',
        'whitemagic/causal',
    ],
    'Wave 3: MCP Tools': [
        'whitemagic/tools',
        'whitemagic/gana',
    ],
    'Wave 4: Gardens & Effects': [
        'whitemagic/gardens',
        'whitemagic/effects',
    ],
    'Wave 5: Utilities & Support': [
        'whitemagic/utils',
        'whitemagic/config',
        'whitemagic/cli',
        'whitemagic/agents',
    ],
}

# Execute waves
all_results = {}
total_start = time.time()

for wave_name, target_dirs in waves.items():
    print(f"\n{'='*80}")
    print(f"{wave_name}")
    print(f"{'='*80}")
    
    wave_start = time.time()
    
    # Deploy scouts
    results = commander.deploy_scouts(target_dirs)
    
    wave_time = time.time() - wave_start
    
    # Display wave summary
    print(f"\n  Wave Results ({wave_time:.1f}s):")
    print(f"    Files analyzed: {results['total_files_analyzed']}")
    print(f"    Lines analyzed: {results['total_lines_analyzed']:,}")
    
    print(f"\n  By Priority:")
    for priority in ['P0', 'P1', 'P2', 'P3', 'P4']:
        if priority in results['by_priority']:
            data = results['by_priority'][priority]
            print(f"    {priority}: {data['count']:3d} files, {data['total_loc']:,} LOC, "
                  f"avg hot path: {data['avg_hot_path_score']:.2f}")
    
    print(f"\n  By Target Language:")
    for lang in ['rust', 'zig', 'mojo', 'koka']:
        if lang in results['by_target_language']:
            data = results['by_target_language'][lang]
            print(f"    {lang:5s}: {data['count']:3d} files, {data['total_loc']:,} LOC, "
                  f"avg complexity: {data['avg_complexity']:.1f}")
    
    print(f"\n  Deduplication:")
    dedup = results['deduplication_opportunities']
    print(f"    {dedup['cluster_count']} clusters, {dedup['total_files']} total files")
    
    print(f"\n  Top 5 Hot Paths:")
    for i, hp in enumerate(results['hot_paths'][:5], 1):
        file_short = Path(hp['file']).relative_to(ROOT)
        print(f"    {i}. {file_short}")
        print(f"       Score: {hp['score']:.2f}, Target: {hp['target']}, "
              f"Speedup: {hp['speedup']}")
        print(f"       {hp['notes']}")
    
    all_results[wave_name] = results

total_time = time.time() - total_start

# Generate comprehensive summary
print(f"\n{'='*80}")
print("CAMPAIGN SUMMARY")
print(f"{'='*80}")

total_files = sum(r['total_files_analyzed'] for r in all_results.values())
total_lines = sum(r['total_lines_analyzed'] for r in all_results.values())

print(f"\n  Total Execution Time: {total_time:.1f}s")
print(f"  Total Files Analyzed: {total_files}")
print(f"  Total Lines Analyzed: {total_lines:,}")

# Aggregate by priority
agg_priority = {}
for wave_results in all_results.values():
    for priority, data in wave_results['by_priority'].items():
        if priority not in agg_priority:
            agg_priority[priority] = {'count': 0, 'total_loc': 0, 'files': []}
        agg_priority[priority]['count'] += data['count']
        agg_priority[priority]['total_loc'] += data['total_loc']
        agg_priority[priority]['files'].extend(data['files'])

print(f"\n  Overall Priority Distribution:")
for priority in ['P0', 'P1', 'P2', 'P3', 'P4']:
    if priority in agg_priority:
        data = agg_priority[priority]
        print(f"    {priority}: {data['count']:4d} files ({data['count']/total_files*100:5.1f}%), "
              f"{data['total_loc']:,} LOC")

# Aggregate by language
agg_language = {}
for wave_results in all_results.values():
    for lang, data in wave_results['by_target_language'].items():
        if lang not in agg_language:
            agg_language[lang] = {'count': 0, 'total_loc': 0, 'files': []}
        agg_language[lang]['count'] += data['count']
        agg_language[lang]['total_loc'] += data['total_loc']
        agg_language[lang]['files'].extend(data['files'])

print(f"\n  Overall Language Distribution:")
for lang in ['rust', 'zig', 'mojo', 'koka']:
    if lang in agg_language:
        data = agg_language[lang]
        print(f"    {lang:5s}: {data['count']:4d} files ({data['count']/total_files*100:5.1f}%), "
              f"{data['total_loc']:,} LOC")

# Top 20 migration candidates
print(f"\n  Top 20 Migration Candidates (P0/P1):")
all_p0_p1 = []
for priority in ['P0', 'P1']:
    if priority in agg_priority:
        all_p0_p1.extend(agg_priority[priority]['files'])

all_p0_p1_sorted = sorted(all_p0_p1, key=lambda x: x['hot_path_score'], reverse=True)[:20]

for i, file_data in enumerate(all_p0_p1_sorted, 1):
    file_short = Path(file_data['file_path']).relative_to(ROOT)
    print(f"    {i:2d}. {file_short}")
    print(f"        Priority: {file_data['priority']}, "
          f"Hot Path: {file_data['hot_path_score']:.2f}, "
          f"Target: {file_data['target_language']}, "
          f"Speedup: {file_data['estimated_speedup']}")
    print(f"        Complexity: {file_data['migration_complexity']}/5, "
          f"Impact: {file_data['performance_impact']}/5")
    print(f"        {file_data['notes']}")

# Save comprehensive results
output_dir = ROOT / 'reports'
output_dir.mkdir(exist_ok=True)

# Save JSON
json_path = output_dir / 'polyglot_scouting_campaign_results.json'
comprehensive_results = {
    'timestamp': datetime.now().isoformat(),
    'execution_time_seconds': total_time,
    'total_files_analyzed': total_files,
    'total_lines_analyzed': total_lines,
    'by_priority': {
        p: {
            'count': data['count'],
            'total_loc': data['total_loc'],
            'percentage': data['count'] / total_files * 100,
            'top_files': sorted(data['files'], key=lambda x: x['hot_path_score'], reverse=True)[:50]
        }
        for p, data in agg_priority.items()
    },
    'by_target_language': {
        lang: {
            'count': data['count'],
            'total_loc': data['total_loc'],
            'percentage': data['count'] / total_files * 100,
            'files': data['files'][:100]
        }
        for lang, data in agg_language.items()
    },
    'waves': all_results,
    'top_20_candidates': all_p0_p1_sorted,
}

with open(json_path, 'w') as f:
    json.dump(comprehensive_results, f, indent=2)

print(f"\n💾 Results saved to: {json_path}")

# Generate markdown report
md_path = output_dir / 'POLYGLOT_SCOUTING_CAMPAIGN_RESULTS.md'
with open(md_path, 'w') as f:
    f.write("# Polyglot Scouting Campaign Results\n\n")
    f.write(f"**Date**: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
    f.write(f"**Operation**: Babel Scout\n")
    f.write(f"**Execution Time**: {total_time:.1f}s\n\n")
    
    f.write("---\n\n")
    f.write("## Executive Summary\n\n")
    f.write(f"- **Files Analyzed**: {total_files:,}\n")
    f.write(f"- **Lines Analyzed**: {total_lines:,}\n")
    f.write(f"- **P0 Candidates**: {agg_priority.get('P0', {}).get('count', 0)}\n")
    f.write(f"- **P1 Candidates**: {agg_priority.get('P1', {}).get('count', 0)}\n")
    f.write(f"- **Total High-Priority**: {agg_priority.get('P0', {}).get('count', 0) + agg_priority.get('P1', {}).get('count', 0)}\n\n")
    
    f.write("---\n\n")
    f.write("## Priority Distribution\n\n")
    f.write("| Priority | Files | LOC | Percentage |\n")
    f.write("|----------|-------|-----|------------|\n")
    for priority in ['P0', 'P1', 'P2', 'P3', 'P4']:
        if priority in agg_priority:
            data = agg_priority[priority]
            f.write(f"| **{priority}** | {data['count']:,} | {data['total_loc']:,} | "
                   f"{data['count']/total_files*100:.1f}% |\n")
    
    f.write("\n---\n\n")
    f.write("## Target Language Distribution\n\n")
    f.write("| Language | Files | LOC | Percentage |\n")
    f.write("|----------|-------|-----|------------|\n")
    for lang in ['rust', 'zig', 'mojo', 'koka']:
        if lang in agg_language:
            data = agg_language[lang]
            f.write(f"| **{lang.capitalize()}** | {data['count']:,} | {data['total_loc']:,} | "
                   f"{data['count']/total_files*100:.1f}% |\n")
    
    f.write("\n---\n\n")
    f.write("## Top 20 Migration Candidates\n\n")
    for i, file_data in enumerate(all_p0_p1_sorted, 1):
        file_short = Path(file_data['file_path']).relative_to(ROOT)
        f.write(f"### {i}. `{file_short}`\n\n")
        f.write(f"- **Priority**: {file_data['priority']}\n")
        f.write(f"- **Hot Path Score**: {file_data['hot_path_score']:.2f}\n")
        f.write(f"- **Target Language**: {file_data['target_language']}\n")
        f.write(f"- **Estimated Speedup**: {file_data['estimated_speedup']}\n")
        f.write(f"- **Migration Complexity**: {file_data['migration_complexity']}/5\n")
        f.write(f"- **Performance Impact**: {file_data['performance_impact']}/5\n")
        f.write(f"- **Notes**: {file_data['notes']}\n\n")
    
    f.write("---\n\n")
    f.write("## Next Steps\n\n")
    f.write("1. **Review P0 candidates** - Start with highest-impact, lowest-complexity\n")
    f.write("2. **Begin PSR-001** - Memory Core migration\n")
    f.write("3. **Execute quick wins** - P0 files with complexity ≤2\n")
    f.write("4. **Measure results** - Benchmark before/after\n")
    f.write("5. **Iterate** - Apply learnings to P1 candidates\n\n")

print(f"💾 Report saved to: {md_path}")

print(f"\n{'='*80}")
print("✅ POLYGLOT SCOUTING CAMPAIGN COMPLETE")
print(f"{'='*80}")

print(f"\n  Key Findings:")
print(f"    • {total_files:,} Python files analyzed")
print(f"    • {agg_priority.get('P0', {}).get('count', 0)} P0 candidates (critical priority)")
print(f"    • {agg_priority.get('P1', {}).get('count', 0)} P1 candidates (high priority)")
print(f"    • {agg_language.get('rust', {}).get('count', 0)} files → Rust")
print(f"    • {agg_language.get('zig', {}).get('count', 0)} files → Zig")
print(f"    • {agg_language.get('mojo', {}).get('count', 0)} files → Mojo")
print(f"    • {agg_language.get('koka', {}).get('count', 0)} files → Koka")

print(f"\n  The scouts have returned with intelligence! 🔍⚔️")
print(f"  Ready to begin polyglot transformation.")
