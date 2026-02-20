#!/usr/bin/env python3
"""Deploy Geneseed Miner - Extract Optimization Patterns from Git History

Mines whitemagicpublic, whitemagicdev, and aria-crystallized repositories
for proven optimization patterns with confidence threshold 0.77.
"""

import sys
import json
from pathlib import Path
from collections import defaultdict

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

# Force reload to pick up new Rust functions
import importlib
if 'whitemagic.optimization.rust_accelerators' in sys.modules:
    importlib.reload(sys.modules['whitemagic.optimization.rust_accelerators'])

from whitemagic.optimization import rust_accelerators

print("="*80)
print("GENESEED MINER DEPLOYMENT - Phase 3C")
print("Confidence Threshold: 0.77 (High-Confidence Only)")
print("="*80)

# Repository paths in priority order
repos = [
    ("whitemagicpublic", Path.home() / "Desktop/whitemagicpublic"),
    ("whitemagicdev", Path.home() / "Desktop/whitemagicdev"),
    ("aria-crystallized", Path.home() / "Desktop/aria-crystallized"),
]

CONFIDENCE_THRESHOLD = 0.77
MAX_COMMITS = 1000  # Analyze last 1000 commits per repo

all_patterns = []
repo_stats = {}

for repo_name, repo_path in repos:
    print(f"\n{'='*80}")
    print(f"REPOSITORY: {repo_name}")
    print(f"Path: {repo_path}")
    print(f"{'='*80}")
    
    if not repo_path.exists():
        print(f"⚠️  Repository not found, skipping...")
        continue
    
    # Check if it's a git repo
    if not (repo_path / ".git").exists():
        print(f"⚠️  Not a git repository, skipping...")
        continue
    
    # Get repository statistics
    print(f"\n[1/2] Getting repository statistics...")
    try:
        if hasattr(rust_accelerators._rs, 'get_geneseed_stats'):
            stats = rust_accelerators._rs.get_geneseed_stats(str(repo_path))
            repo_stats[repo_name] = {
                'total_commits': stats.total_commits,
                'optimization_commits': stats.optimization_commits,
                'refactor_commits': stats.refactor_commits,
                'bugfix_commits': stats.bugfix_commits,
                'total_files': stats.total_files_tracked,
                'avg_age_days': stats.avg_commit_age_days,
            }
            print(f"  Total commits: {stats.total_commits:,}")
            print(f"  Optimization commits: {stats.optimization_commits}")
            print(f"  Refactor commits: {stats.refactor_commits}")
            print(f"  Bugfix commits: {stats.bugfix_commits}")
            print(f"  Files tracked: {stats.total_files_tracked:,}")
            print(f"  Avg commit age: {stats.avg_commit_age_days:.1f} days")
        else:
            print(f"  ⚠️  get_geneseed_stats not available")
            repo_stats[repo_name] = None
    except Exception as e:
        print(f"  ❌ Error: {e}")
        repo_stats[repo_name] = None
    
    # Mine optimization patterns
    print(f"\n[2/2] Mining optimization patterns...")
    print(f"  Confidence threshold: {CONFIDENCE_THRESHOLD:.2%}")
    print(f"  Max commits to analyze: {MAX_COMMITS:,}")
    
    try:
        if hasattr(rust_accelerators._rs, 'mine_geneseed_patterns'):
            patterns = rust_accelerators._rs.mine_geneseed_patterns(
                str(repo_path),
                CONFIDENCE_THRESHOLD,
                MAX_COMMITS
            )
            
            # Add source repo to each pattern
            for p in patterns:
                all_patterns.append({
                    'source_repo': repo_name,
                    'pattern': p,
                })
            
            print(f"  ✅ Found {len(patterns)} high-confidence patterns")
            
            # Group by type
            by_type = defaultdict(list)
            for p in patterns:
                by_type[p.pattern_type].append(p)
            
            if by_type:
                print(f"\n  📊 Patterns by Type:")
                for ptype, plist in sorted(by_type.items(), key=lambda x: len(x[1]), reverse=True):
                    avg_conf = sum(p.confidence for p in plist) / len(plist)
                    print(f"    {ptype:15s}: {len(plist):3d} patterns (avg confidence: {avg_conf:.2%})")
        else:
            print(f"  ⚠️  mine_geneseed_patterns not available")
    except Exception as e:
        print(f"  ❌ Error: {e}")
        import traceback
        traceback.print_exc()

# Summary
print(f"\n{'='*80}")
print("GENESEED MINING SUMMARY")
print(f"{'='*80}")

print(f"\nRepositories Analyzed: {len([r for r in repo_stats.values() if r is not None])}")
for repo_name, stats in repo_stats.items():
    if stats:
        print(f"  {repo_name:20s}: {stats['total_commits']:,} commits, {stats['optimization_commits']} optimizations")

print(f"\nTotal Patterns Discovered: {len(all_patterns)}")

if all_patterns:
    # Group by type across all repos
    all_by_type = defaultdict(list)
    for item in all_patterns:
        all_by_type[item['pattern'].pattern_type].append(item)
    
    print(f"\n📊 All Patterns by Type:")
    for ptype, plist in sorted(all_by_type.items(), key=lambda x: len(x[1]), reverse=True):
        avg_conf = sum(item['pattern'].confidence for item in plist) / len(plist)
        print(f"  {ptype:15s}: {len(plist):3d} patterns (avg confidence: {avg_conf:.2%})")
    
    # Top 20 by confidence
    print(f"\n🏆 TOP 20 PATTERNS BY CONFIDENCE:")
    sorted_patterns = sorted(all_patterns, key=lambda x: x['pattern'].confidence, reverse=True)
    for i, item in enumerate(sorted_patterns[:20], 1):
        p = item['pattern']
        repo = item['source_repo']
        print(f"\n  {i:2d}. [{repo}] {p.pattern_id}")
        print(f"      Type: {p.pattern_type} | Confidence: {p.confidence:.2%} | Age: {p.longevity_days}d")
        print(f"      Changes: +{p.lines_added}/-{p.lines_removed} in {len(p.files_changed)} files")
        print(f"      Message: {p.commit_message[:70]}...")
    
    # Oldest patterns (most proven)
    print(f"\n⏰ TOP 10 OLDEST PATTERNS (Most Proven):")
    sorted_by_age = sorted(all_patterns, key=lambda x: x['pattern'].longevity_days, reverse=True)
    for i, item in enumerate(sorted_by_age[:10], 1):
        p = item['pattern']
        repo = item['source_repo']
        age_years = p.longevity_days / 365.0
        print(f"\n  {i:2d}. [{repo}] {p.pattern_id}")
        print(f"      Age: {p.longevity_days}d ({age_years:.1f} years) | Confidence: {p.confidence:.2%}")
        print(f"      Type: {p.pattern_type}")
        print(f"      Message: {p.commit_message[:70]}...")
    
    # Cross-repo patterns (same file/author across repos)
    print(f"\n🔗 CROSS-REPO PATTERN ANALYSIS:")
    authors = defaultdict(list)
    for item in all_patterns:
        authors[item['pattern'].author].append(item)
    
    multi_repo_authors = {k: v for k, v in authors.items() if len(set(item['source_repo'] for item in v)) > 1}
    if multi_repo_authors:
        print(f"  Authors with patterns in multiple repos: {len(multi_repo_authors)}")
        for author, items in sorted(multi_repo_authors.items(), key=lambda x: len(x[1]), reverse=True)[:5]:
            repos_set = set(item['source_repo'] for item in items)
            print(f"    {author:30s}: {len(items)} patterns across {len(repos_set)} repos")
    
    # Save results
    output_dir = ROOT / "reports"
    output_dir.mkdir(exist_ok=True)
    
    results = {
        'timestamp': __import__('time').strftime("%Y-%m-%d %H:%M:%S"),
        'confidence_threshold': CONFIDENCE_THRESHOLD,
        'max_commits_per_repo': MAX_COMMITS,
        'repositories': repo_stats,
        'total_patterns': len(all_patterns),
        'patterns_by_type': {
            ptype: len(plist) for ptype, plist in all_by_type.items()
        },
        'top_20_patterns': [
            {
                'source_repo': item['source_repo'],
                'pattern_id': item['pattern'].pattern_id,
                'pattern_type': item['pattern'].pattern_type,
                'confidence': item['pattern'].confidence,
                'longevity_days': item['pattern'].longevity_days,
                'commit_hash': item['pattern'].commit_hash,
                'commit_message': item['pattern'].commit_message,
                'author': item['pattern'].author,
                'timestamp': item['pattern'].timestamp,
                'files_changed': item['pattern'].files_changed,
                'lines_added': item['pattern'].lines_added,
                'lines_removed': item['pattern'].lines_removed,
            }
            for item in sorted_patterns[:20]
        ],
    }
    
    output_file = output_dir / "geneseed_mining_results.json"
    with open(output_file, 'w') as f:
        json.dump(results, f, indent=2)
    
    print(f"\n💾 Results saved to: {output_file}")

else:
    print("\n⚠️  No patterns found meeting confidence threshold 0.77")

print(f"\n{'='*80}")
print("✅ GENESEED MINING COMPLETE")
print(f"🧬 Ready for cross-validation with galaxy patterns")
print(f"{'='*80}")
