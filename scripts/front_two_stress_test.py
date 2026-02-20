#!/usr/bin/env python3
"""Front Two Stress Test - Deploy Unified Zodiac Armies on All Campaigns

Deploys unified zodiac armies sequentially on all 4 Front Two campaigns:
- H001: Embeddings Hot Path Optimization
- H002: Hybrid Recall Optimization
- H003: PolyglotRouter Core Optimization
- H004: Search Entry Point Optimization

Tracks results, analyzes effectiveness, and identifies improvements.
"""

import asyncio
import json
import sys
import time
from pathlib import Path

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.unified_zodiac_army import get_unified_commander


# Front Two Campaigns
FRONT_TWO_CAMPAIGNS = [
    {
        'id': 'H001',
        'name': 'Embeddings Hot Path Optimization',
        'objective': 'Optimize embeddings.py:find_duplicates() for 50× speedup using Rust MinHash LSH',
        'total_vcs': 19,
        'target_speedup': '50×',
        'suggested_clones': 140
    },
    {
        'id': 'H002',
        'name': 'Hybrid Recall Optimization',
        'objective': 'Optimize unified.py:hybrid_recall() for 20× speedup through Rust acceleration and caching',
        'total_vcs': 20,
        'target_speedup': '20×',
        'suggested_clones': 150
    },
    {
        'id': 'H003',
        'name': 'PolyglotRouter Core Optimization',
        'objective': 'Optimize polyglot_router.py:_route_operation() for 10× speedup with predictive routing',
        'total_vcs': 20,
        'target_speedup': '10×',
        'suggested_clones': 140
    },
    {
        'id': 'H004',
        'name': 'Search Entry Point Optimization',
        'objective': 'Optimize search.py:search_memories() for 15× speedup through batching and preprocessing',
        'total_vcs': 20,
        'target_speedup': '15×',
        'suggested_clones': 130
    }
]


async def deploy_on_campaign(campaign: dict, clones_per_army: int = 50) -> dict:
    """Deploy unified zodiac armies on a single campaign"""
    commander = get_unified_commander()
    
    print("\n" + "="*100)
    print(f"🎯 CAMPAIGN {campaign['id']}: {campaign['name']}")
    print("="*100)
    print(f"Objective: {campaign['objective']}")
    print(f"Target: {campaign['target_speedup']} speedup, {campaign['total_vcs']} VCs")
    print(f"Deploying: {clones_per_army} clones per army")
    print()
    
    start_time = time.time()
    
    # Deploy with auto-selection
    deployment = await commander.deploy_unified(
        objective=campaign['objective'],
        auto_select=True,
        clones_per_army=clones_per_army
    )
    
    elapsed = time.time() - start_time
    
    # Show results
    print(f"\n✅ DEPLOYMENT COMPLETE")
    print(f"   Armies: {', '.join(a.value for a in deployment.armies_deployed)}")
    print(f"   Total Clones: {deployment.total_clones:,}")
    print(f"   Duration: {deployment.total_duration_ms}ms ({elapsed:.2f}s total)")
    print(f"   Throughput: {deployment.total_clones / (deployment.total_duration_ms / 1000):.1f} clones/sec" if deployment.total_duration_ms > 0 else "")
    print(f"   Victories: {deployment.victories}/{deployment.total_clones} ({deployment.victories/deployment.total_clones*100:.1f}%)")
    print(f"   Synergy Score: {deployment.synergy_score:.1%}")
    
    # Zodiac distribution
    print(f"\n📊 Zodiac Distribution:")
    zodiac_counts = {}
    for result in deployment.results:
        zodiac_counts[result.zodiac_sign] = zodiac_counts.get(result.zodiac_sign, 0) + 1
    
    for sign, count in sorted(zodiac_counts.items(), key=lambda x: x[1], reverse=True):
        pct = count / deployment.total_clones * 100
        print(f"   {sign.value.title():<12}: {count:>4} clones ({pct:>5.1f}%)")
    
    return {
        'campaign_id': campaign['id'],
        'campaign_name': campaign['name'],
        'armies_deployed': [a.value for a in deployment.armies_deployed],
        'total_clones': deployment.total_clones,
        'duration_ms': deployment.total_duration_ms,
        'victories': deployment.victories,
        'synergy_score': deployment.synergy_score,
        'zodiac_distribution': {sign.value: count for sign, count in zodiac_counts.items()},
        'elapsed_seconds': elapsed
    }


async def run_stress_test(clones_per_army: int = 50):
    """Run full stress test on all Front Two campaigns"""
    print("\n" + "="*100)
    print("🌟 FRONT TWO STRESS TEST - UNIFIED ZODIAC ARMIES")
    print("="*100)
    print(f"Campaigns: {len(FRONT_TWO_CAMPAIGNS)}")
    print(f"Clones per army: {clones_per_army}")
    print(f"Total VCs: {sum(c['total_vcs'] for c in FRONT_TWO_CAMPAIGNS)}")
    print("="*100)
    
    commander = get_unified_commander()
    print(f"\nEngine: {'🦀 Rust (534K/sec)' if commander.rust_available else '🐍 Python (50/sec/core)'}")
    
    overall_start = time.time()
    results = []
    
    # Deploy on each campaign sequentially
    for i, campaign in enumerate(FRONT_TWO_CAMPAIGNS, 1):
        print(f"\n\n{'='*100}")
        print(f"CAMPAIGN {i}/{len(FRONT_TWO_CAMPAIGNS)}")
        print(f"{'='*100}")
        
        result = await deploy_on_campaign(campaign, clones_per_army)
        results.append(result)
        
        # Brief pause between campaigns
        if i < len(FRONT_TWO_CAMPAIGNS):
            await asyncio.sleep(0.5)
    
    overall_elapsed = time.time() - overall_start
    
    # Generate comprehensive report
    print("\n\n" + "="*100)
    print("📊 FRONT TWO STRESS TEST - FINAL REPORT")
    print("="*100)
    
    total_clones = sum(r['total_clones'] for r in results)
    total_victories = sum(r['victories'] for r in results)
    avg_synergy = sum(r['synergy_score'] for r in results) / len(results)
    total_vcs = sum(c['total_vcs'] for c in FRONT_TWO_CAMPAIGNS)
    
    print(f"\n🎯 OVERALL STATISTICS")
    print(f"   Total Campaigns: {len(results)}")
    print(f"   Total Clones Deployed: {total_clones:,}")
    print(f"   Total Victories: {total_victories:,}/{total_clones:,} ({total_victories/total_clones*100:.1f}%)")
    print(f"   Average Synergy Score: {avg_synergy:.1%}")
    print(f"   Total Duration: {overall_elapsed:.2f}s")
    print(f"   Overall Throughput: {total_clones / overall_elapsed:.1f} clones/sec")
    print(f"   Total VCs to Complete: {total_vcs}")
    
    # Per-campaign summary
    print(f"\n📋 PER-CAMPAIGN RESULTS")
    print(f"{'='*100}")
    for result in results:
        print(f"\n{result['campaign_id']}: {result['campaign_name']}")
        print(f"   Armies: {', '.join(result['armies_deployed'])}")
        print(f"   Clones: {result['total_clones']:,}")
        print(f"   Victories: {result['victories']:,}/{result['total_clones']:,} ({result['victories']/result['total_clones']*100:.1f}%)")
        print(f"   Synergy: {result['synergy_score']:.1%}")
        print(f"   Duration: {result['elapsed_seconds']:.2f}s")
    
    # Army effectiveness analysis
    print(f"\n🏆 ARMY EFFECTIVENESS ANALYSIS")
    print(f"{'='*100}")
    
    army_stats = {}
    for result in results:
        for army in result['armies_deployed']:
            if army not in army_stats:
                army_stats[army] = {'deployments': 0, 'total_clones': 0}
            army_stats[army]['deployments'] += 1
            # Estimate clones per army (total / num armies)
            army_stats[army]['total_clones'] += result['total_clones'] // len(result['armies_deployed'])
    
    print("\nMost Deployed Armies:")
    for army, stats in sorted(army_stats.items(), key=lambda x: x[1]['deployments'], reverse=True):
        print(f"   {army.upper():<15}: {stats['deployments']} campaigns, ~{stats['total_clones']:,} clones")
    
    # Zodiac distribution across all campaigns
    print(f"\n🌟 ZODIAC DISTRIBUTION (ALL CAMPAIGNS)")
    print(f"{'='*100}")
    
    all_zodiac_counts = {}
    for result in results:
        for sign, count in result['zodiac_distribution'].items():
            all_zodiac_counts[sign] = all_zodiac_counts.get(sign, 0) + count
    
    for sign, count in sorted(all_zodiac_counts.items(), key=lambda x: x[1], reverse=True):
        pct = count / total_clones * 100
        print(f"   {sign.title():<12}: {count:>5} clones ({pct:>5.1f}%)")
    
    # Recommendations
    print(f"\n💡 RECOMMENDATIONS")
    print(f"{'='*100}")
    
    if avg_synergy >= 0.90:
        print("   ✅ Excellent synergy scores! Zodiac-army alignment is working perfectly.")
    elif avg_synergy >= 0.85:
        print("   ✓ Good synergy scores. Minor tuning could improve alignment.")
    else:
        print("   ⚠ Synergy scores could be improved. Review zodiac-army mappings.")
    
    if total_victories / total_clones >= 0.95:
        print("   ✅ Outstanding victory rate! Armies are highly effective.")
    elif total_victories / total_clones >= 0.90:
        print("   ✓ Good victory rate. Armies are performing well.")
    else:
        print("   ⚠ Victory rate could be improved. Review army strategies.")
    
    # Save report
    report_data = {
        'timestamp': time.time(),
        'overall_stats': {
            'total_campaigns': len(results),
            'total_clones': total_clones,
            'total_victories': total_victories,
            'victory_rate': total_victories / total_clones,
            'avg_synergy': avg_synergy,
            'duration_seconds': overall_elapsed,
            'throughput': total_clones / overall_elapsed
        },
        'campaign_results': results,
        'army_stats': army_stats,
        'zodiac_distribution': all_zodiac_counts
    }
    
    report_path = project_root / "reports" / f"front_two_stress_test_{int(time.time())}.json"
    report_path.write_text(json.dumps(report_data, indent=2))
    print(f"\n📄 Full report saved: {report_path}")
    
    # Generate markdown report
    md_report = generate_markdown_report(report_data, results)
    md_path = project_root / "reports" / f"FRONT_TWO_STRESS_TEST_{int(time.time())}.md"
    md_path.write_text(md_report)
    print(f"📄 Markdown report saved: {md_path}")
    
    return report_data


def generate_markdown_report(data: dict, results: list) -> str:
    """Generate markdown report"""
    lines = [
        "# Front Two Stress Test - Unified Zodiac Armies\n",
        f"**Date**: {time.strftime('%Y-%m-%d %H:%M:%S')}",
        f"**Engine**: {'Rust (534K/sec)' if get_unified_commander().rust_available else 'Python (50/sec/core)'}\n",
        "---\n",
        "## 🎯 Overall Statistics\n",
        f"- **Total Campaigns**: {data['overall_stats']['total_campaigns']}",
        f"- **Total Clones**: {data['overall_stats']['total_clones']:,}",
        f"- **Total Victories**: {data['overall_stats']['total_victories']:,}/{data['overall_stats']['total_clones']:,} ({data['overall_stats']['victory_rate']*100:.1f}%)",
        f"- **Average Synergy**: {data['overall_stats']['avg_synergy']:.1%}",
        f"- **Duration**: {data['overall_stats']['duration_seconds']:.2f}s",
        f"- **Throughput**: {data['overall_stats']['throughput']:.1f} clones/sec\n",
        "---\n",
        "## 📋 Campaign Results\n"
    ]
    
    for result in results:
        lines.extend([
            f"### {result['campaign_id']}: {result['campaign_name']}\n",
            f"- **Armies**: {', '.join(result['armies_deployed'])}",
            f"- **Clones**: {result['total_clones']:,}",
            f"- **Victories**: {result['victories']:,}/{result['total_clones']:,} ({result['victories']/result['total_clones']*100:.1f}%)",
            f"- **Synergy**: {result['synergy_score']:.1%}",
            f"- **Duration**: {result['elapsed_seconds']:.2f}s\n"
        ])
    
    lines.extend([
        "---\n",
        "## 🏆 Army Effectiveness\n"
    ])
    
    for army, stats in sorted(data['army_stats'].items(), key=lambda x: x[1]['deployments'], reverse=True):
        lines.append(f"- **{army.upper()}**: {stats['deployments']} campaigns, ~{stats['total_clones']:,} clones")
    
    lines.extend([
        "\n---\n",
        "## 🌟 Zodiac Distribution\n"
    ])
    
    for sign, count in sorted(data['zodiac_distribution'].items(), key=lambda x: x[1], reverse=True):
        pct = count / data['overall_stats']['total_clones'] * 100
        lines.append(f"- **{sign.title()}**: {count:,} clones ({pct:.1f}%)")
    
    return "\n".join(lines)


async def main():
    """Main entry point"""
    import argparse
    
    parser = argparse.ArgumentParser(description="Front Two Stress Test")
    parser.add_argument('--clones', type=int, default=50, help="Clones per army (default: 50)")
    
    args = parser.parse_args()
    
    await run_stress_test(clones_per_army=args.clones)
    
    return 0


if __name__ == '__main__':
    sys.exit(asyncio.run(main()))
