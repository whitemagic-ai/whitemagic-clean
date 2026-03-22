#!/usr/bin/env python3
"""Phase 3 Complete Integration - All Four Actions (A, B, C, D)

Comprehensive test of the entire recursive evolution pipeline:
- A: Fine-tuned galaxy mining (DONE)
- B: Cluster analysis (DONE)
- C: Geneseed mining (Rust)
- D: Pattern scoring and cross-validation
"""

import sys
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

# Force reload of rust_accelerators to pick up new functions
import importlib
if 'whitemagic.optimization.rust_accelerators' in sys.modules:
    importlib.reload(sys.modules['whitemagic.optimization.rust_accelerators'])

from whitemagic.optimization import rust_accelerators
from whitemagic.core.evolution.pattern_scoring import PatternScorer

print("="*80)
print("PHASE 3 COMPLETE INTEGRATION TEST")
print("All Four Actions: A (Galaxy) + B (Analysis) + C (Geneseed) + D (Scoring)")
print("="*80)

# Check what functions are available
print("\n🔍 Checking Rust module functions...")
available_funcs = [f for f in dir(rust_accelerators._rs) if not f.startswith('_')]
print(f"Total Rust functions available: {len(available_funcs)}")
geneseed_funcs = [f for f in available_funcs if 'geneseed' in f.lower()]
print(f"Geneseed functions: {geneseed_funcs}")

# ACTION A & B: Load galaxy mining results (already done)
print("\n" + "="*80)
print("ACTION A & B: Galaxy Mining + Cluster Analysis")
print("="*80)

results_file = ROOT / "reports/comprehensive_galaxy_mining_results.json"
if results_file.exists():
    with open(results_file) as f:
        galaxy_results = json.load(f)
    
    print("✅ Galaxy mining complete:")
    print(f"   Memories processed: {galaxy_results['performance']['total_memories']:,}")
    print(f"   Processing rate: {galaxy_results['performance']['processing_rate']:,.0f} mem/sec")
    print(f"   Semantic clusters: {galaxy_results['patterns']['semantic_clusters_count']}")
    print(f"   Cross-validated tags: {len(galaxy_results['cross_validated_tags'])}")
else:
    print("❌ Galaxy mining results not found. Run comprehensive_galaxy_mining.py first.")
    sys.exit(1)

# ACTION C: Geneseed Mining
print("\n" + "="*80)
print("ACTION C: Geneseed Codebase Vault Mining")
print("="*80)

repo_path = str(Path.home() / "Desktop/whitemagicpublic")

if not Path(repo_path).exists():
    print(f"⚠️  Repository not found: {repo_path}")
    print("Skipping geneseed mining...")
    geneseed_patterns = []
else:
    print(f"Repository: {repo_path}")
    
    # Check if functions exist
    if hasattr(rust_accelerators._rs, 'get_geneseed_stats'):
        print("\n[1/2] Getting repository statistics...")
        try:
            stats = rust_accelerators._rs.get_geneseed_stats(repo_path)
            print(f"  Total commits: {stats.total_commits:,}")
            print(f"  Optimization commits: {stats.optimization_commits}")
            print(f"  Refactor commits: {stats.refactor_commits}")
            print(f"  Bugfix commits: {stats.bugfix_commits}")
            print(f"  Files tracked: {stats.total_files_tracked:,}")
            print(f"  Avg commit age: {stats.avg_commit_age_days:.1f} days")
        except Exception as e:
            print(f"  ❌ Error: {e}")
            stats = None
    else:
        print("⚠️  get_geneseed_stats not available in Rust module")
        stats = None
    
    if hasattr(rust_accelerators._rs, 'mine_geneseed_patterns'):
        print("\n[2/2] Mining optimization patterns...")
        print("  Parameters: min_confidence=0.5, max_commits=500")
        try:
            geneseed_patterns = rust_accelerators._rs.mine_geneseed_patterns(
                repo_path, 0.5, 500
            )
            print(f"✅ Found {len(geneseed_patterns)} optimization patterns")
            
            # Group by type
            by_type = {}
            for p in geneseed_patterns:
                by_type.setdefault(p.pattern_type, []).append(p)
            
            print("\n📊 Patterns by Type:")
            for ptype, plist in sorted(by_type.items(), key=lambda x: len(x[1]), reverse=True):
                print(f"  {ptype:15s}: {len(plist):3d} patterns")
        except Exception as e:
            print(f"  ❌ Error: {e}")
            import traceback
            traceback.print_exc()
            geneseed_patterns = []
    else:
        print("⚠️  mine_geneseed_patterns not available in Rust module")
        geneseed_patterns = []

# ACTION D: Pattern Scoring and Cross-Validation
print("\n" + "="*80)
print("ACTION D: Pattern Scoring & Cross-Validation")
print("="*80)

print("\nInitializing PatternScorer...")
print("  Weights: CV=40%, Outcome=30%, Frequency=20%, Longevity=10%")

scorer = PatternScorer(
    cross_validation_weight=0.4,
    outcome_weight=0.3,
    frequency_weight=0.2,
    longevity_weight=0.1,
)

# Score galaxy patterns (using mock data since we need actual pattern objects)
print("\n[1/3] Scoring galaxy patterns...")
print(f"  Top clusters by importance: {len(galaxy_results['top_clusters_by_importance'])}")
print(f"  Cross-validated tags: {len(galaxy_results['cross_validated_tags'])}")

# Create summary of high-confidence patterns
high_conf_galaxy = []
for tag, data in list(galaxy_results['cross_validated_tags'].items())[:10]:
    if data['avg_importance'] > 0.7:
        high_conf_galaxy.append({
            'tag': tag,
            'cluster_count': data['cluster_count'],
            'total_size': data['total_size'],
            'avg_importance': data['avg_importance'],
            'confidence': data['avg_importance'] * 0.4 + min(data['cluster_count'] / 5.0, 1.0) * 0.4 + 0.2
        })

print(f"  High-confidence galaxy patterns: {len(high_conf_galaxy)}")

# Score geneseed patterns
if geneseed_patterns:
    print("\n[2/3] Scoring geneseed patterns...")
    print(f"  Total patterns: {len(geneseed_patterns)}")
    
    # Calculate confidence distribution
    high_conf_geneseed = [p for p in geneseed_patterns if p.confidence > 0.7]
    med_conf_geneseed = [p for p in geneseed_patterns if 0.5 <= p.confidence <= 0.7]
    
    print(f"  High confidence (>0.7): {len(high_conf_geneseed)}")
    print(f"  Medium confidence (0.5-0.7): {len(med_conf_geneseed)}")
else:
    print("\n[2/3] No geneseed patterns to score")
    high_conf_geneseed = []

# Cross-validation
print("\n[3/3] Cross-validating patterns...")

if high_conf_galaxy and high_conf_geneseed:
    # Find overlaps
    galaxy_tags = {p['tag'].lower() for p in high_conf_galaxy}
    geneseed_messages = {p.commit_message.lower() for p in high_conf_geneseed}
    
    cross_validated = []
    for gp in high_conf_galaxy:
        tag = gp['tag'].lower()
        matches = sum(1 for msg in geneseed_messages if tag in msg)
        if matches > 0:
            cross_validated.append({
                **gp,
                'geneseed_matches': matches,
                'cross_validated': True,
                'boosted_confidence': min(gp['confidence'] + 0.15, 1.0)
            })
    
    print(f"  Cross-validated patterns: {len(cross_validated)}")
    if cross_validated:
        print("\n  🎯 Top Cross-Validated Patterns:")
        for i, p in enumerate(sorted(cross_validated, key=lambda x: x['boosted_confidence'], reverse=True)[:5], 1):
            print(f"    {i}. {p['tag']:30s} | Confidence: {p['boosted_confidence']:.1%} | Matches: {p['geneseed_matches']}")
else:
    print("  Insufficient data for cross-validation")
    cross_validated = []

# Final Summary
print("\n" + "="*80)
print("PHASE 3 INTEGRATION SUMMARY")
print("="*80)

print("\n✅ ACTION A: Galaxy Mining")
print(f"   Memories: {galaxy_results['performance']['total_memories']:,}")
print(f"   Clusters: {galaxy_results['patterns']['semantic_clusters_count']}")
print(f"   Speed: {galaxy_results['performance']['processing_rate']:,.0f} mem/sec")

print("\n✅ ACTION B: Cluster Analysis")
print(f"   High-importance clusters: {len(galaxy_results['top_clusters_by_importance'])}")
print(f"   High-size clusters: {len(galaxy_results['top_clusters_by_size'])}")
print(f"   Cross-validated tags: {len(galaxy_results['cross_validated_tags'])}")

if geneseed_patterns:
    print("\n✅ ACTION C: Geneseed Mining")
    print(f"   Patterns extracted: {len(geneseed_patterns)}")
    print(f"   High confidence: {len(high_conf_geneseed)}")
    print(f"   Pattern types: {len(by_type)}")
else:
    print("\n⚠️  ACTION C: Geneseed Mining (skipped or unavailable)")

print("\n✅ ACTION D: Pattern Scoring")
print(f"   Galaxy patterns scored: {len(high_conf_galaxy)}")
print(f"   Geneseed patterns scored: {len(high_conf_geneseed)}")
print(f"   Cross-validated: {len(cross_validated)}")

print("\n🎯 READY FOR RECURSIVE EVOLUTION")
print(f"   Total high-confidence patterns: {len(high_conf_galaxy) + len(high_conf_geneseed)}")
print(f"   Cross-validated patterns: {len(cross_validated)}")
print("   Next: Feed to AdaptiveSystem for auto-application")

print("\n" + "="*80)
print("✅ PHASE 3 COMPLETE INTEGRATION TEST FINISHED")
print("="*80)
