#!/usr/bin/env python3
"""Test Geneseed Miner - Phase 3C

Tests Rust-based git history mining on whitemagicpublic repository.
"""

import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.optimization.rust_accelerators import (  # noqa: E402
    get_geneseed_stats,
    mine_geneseed_patterns,
)

print("="*80)
print("GENESEED MINER TEST - Phase 3C")
print("="*80)

# Test on whitemagicpublic first (priority 1)
repo_path = str(Path.home() / "Desktop/whitemagicpublic")

if not Path(repo_path).exists():
    print(f"\n❌ Repository not found: {repo_path}")
    sys.exit(1)

print(f"\n📊 Repository: {repo_path}")

# Get repository statistics
print("\n[1/2] Getting repository statistics...")
try:
    stats = get_geneseed_stats(repo_path)
    print(f"  Total commits: {stats.total_commits:,}")
    print(f"  Optimization commits: {stats.optimization_commits}")
    print(f"  Refactor commits: {stats.refactor_commits}")
    print(f"  Bugfix commits: {stats.bugfix_commits}")
    print(f"  Files tracked: {stats.total_files_tracked:,}")
    print(f"  Avg commit age: {stats.avg_commit_age_days:.1f} days")
except Exception as e:
    print(f"  ❌ Error: {e}")
    sys.exit(1)

# Mine optimization patterns
print("\n[2/2] Mining optimization patterns...")
print("  Parameters: min_confidence=0.5, max_commits=500")

try:
    patterns = mine_geneseed_patterns(repo_path, min_confidence=0.5, max_commits=500)
    print(f"\n✅ Found {len(patterns)} optimization patterns")

    # Group by type
    by_type = {}
    for p in patterns:
        by_type.setdefault(p.pattern_type, []).append(p)

    print("\n📊 Patterns by Type:")
    for ptype, plist in sorted(by_type.items(), key=lambda x: len(x[1]), reverse=True):
        print(f"  {ptype:15s}: {len(plist):3d} patterns")

    # Show top 10 by confidence
    print("\n🏆 TOP 10 PATTERNS BY CONFIDENCE:")
    sorted_patterns = sorted(patterns, key=lambda p: p.confidence, reverse=True)
    for i, p in enumerate(sorted_patterns[:10], 1):
        print(f"\n  {i}. {p.pattern_id}")
        print(f"     Type: {p.pattern_type}")
        print(f"     Confidence: {p.confidence:.2%}")
        print(f"     Longevity: {p.longevity_days} days")
        print(f"     Changes: +{p.lines_added}/-{p.lines_removed}")
        print(f"     Files: {len(p.files_changed)}")
        print(f"     Message: {p.commit_message[:80]}...")

    # Show oldest patterns (most proven)
    print("\n⏰ TOP 5 OLDEST PATTERNS (Most Proven):")
    sorted_by_age = sorted(patterns, key=lambda p: p.longevity_days, reverse=True)
    for i, p in enumerate(sorted_by_age[:5], 1):
        print(f"\n  {i}. {p.pattern_id}")
        print(f"     Age: {p.longevity_days} days ({p.longevity_days/365:.1f} years)")
        print(f"     Type: {p.pattern_type}")
        print(f"     Confidence: {p.confidence:.2%}")
        print(f"     Message: {p.commit_message[:80]}...")

except Exception as e:
    print(f"  ❌ Error: {e}")
    import traceback
    traceback.print_exc()
    sys.exit(1)

print("\n" + "="*80)
print("✅ GENESEED MINING COMPLETE")
print(f"🧬 Extracted {len(patterns)} optimization patterns from git history")
print("="*80)
