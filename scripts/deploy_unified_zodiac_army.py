#!/usr/bin/env python3
"""Deploy Unified Zodiac Army - Rust + Python Polyglot System

This script deploys the unified zodiac army system, synthesizing all 12 shadow clone
army types with the 12 zodiac signs for maximum adaptive intelligence.

Features:
- Rust core for massively parallel execution (534K clones/sec)
- Zodiac intelligence for adaptive strategy selection
- 12×12 mapping of army types to zodiac signs
- Auto-selection of best armies for each objective
- Python fallback if Rust unavailable

Usage:
    # Auto-select armies for objective
    python3 scripts/deploy_unified_zodiac_army.py --objective "optimize embeddings hot path"
    
    # Deploy specific armies
    python3 scripts/deploy_unified_zodiac_army.py --armies tokio,lieutenant --clones 100
    
    # Deploy all armies
    python3 scripts/deploy_unified_zodiac_army.py --all --clones 50
    
    # Show zodiac-army mappings
    python3 scripts/deploy_unified_zodiac_army.py --show-mappings
"""

import asyncio
import sys
import time
from pathlib import Path

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.unified_zodiac_army import (
    ZODIAC_ARMY_MAPPINGS,
    ArmyType,
    get_unified_commander,
)


def show_mappings():
    """Show the 12×12 zodiac-army mappings"""
    print("="*80)
    print("🌟 UNIFIED ZODIAC ARMY MAPPINGS")
    print("="*80)
    print()

    # Group by element
    elements = {
        'fire': [],
        'earth': [],
        'air': [],
        'water': []
    }

    for mapping in ZODIAC_ARMY_MAPPINGS:
        elements[mapping.element].append(mapping)

    for element, mappings in elements.items():
        print(f"🔥 {element.upper()} ELEMENT" if element == 'fire' else
              f"🌍 {element.upper()} ELEMENT" if element == 'earth' else
              f"💨 {element.upper()} ELEMENT" if element == 'air' else
              f"💧 {element.upper()} ELEMENT")
        print("-"*80)

        for mapping in mappings:
            # Get zodiac symbol
            symbols = {'aries': '♈', 'taurus': '♉', 'gemini': '♊', 'cancer': '♋',
                      'leo': '♌', 'virgo': '♍', 'libra': '♎', 'scorpio': '♏',
                      'sagittarius': '♐', 'capricorn': '♑', 'aquarius': '♒', 'pisces': '♓'}
            symbol = symbols.get(mapping.sign.value, '?')

            print(f"\n{symbol} {mapping.sign.value.upper()}")
            print(f"  Army: {mapping.army.value.upper()}")
            print(f"  Modality: {mapping.modality.title()}")
            print(f"  Synergy: {mapping.synergy_score:.0%}")
            print(f"  Specialties: {', '.join(mapping.specialties)}")

        print()

    print("="*80)
    print(f"Total: {len(ZODIAC_ARMY_MAPPINGS)} zodiac-army pairs")
    print("="*80)


async def deploy_all_armies(clones_per_army: int = 10):
    """Deploy all 12 armies"""
    commander = get_unified_commander()

    print("="*80)
    print("🎯 DEPLOYING ALL 12 ARMIES")
    print("="*80)
    print()

    all_armies = [ArmyType(a) for a in [
        "immortal", "tokio", "shadow", "grand", "war_room", "adaptive",
        "batch", "thought", "file_search", "elixir", "campaign", "lieutenant"
    ]]

    deployment = await commander.deploy_unified(
        objective="Test all 12 unified zodiac armies",
        auto_select=False,
        armies=all_armies,
        clones_per_army=clones_per_army
    )

    print("\n✅ Deployment Complete!")
    print(f"   Total Clones: {deployment.total_clones:,}")
    print(f"   Duration: {deployment.total_duration_ms}ms")
    print(f"   Throughput: {deployment.total_clones / (deployment.total_duration_ms / 1000):.1f} clones/sec" if deployment.total_duration_ms > 0 else "")
    print(f"   Victories: {deployment.victories}/{deployment.total_clones}")
    print(f"   Synergy Score: {deployment.synergy_score:.0%}")

    return deployment


async def deploy_objective(objective: str, clones_per_army: int = 10):
    """Deploy armies for a specific objective"""
    commander = get_unified_commander()

    print("="*80)
    print("🎯 UNIFIED ZODIAC ARMY DEPLOYMENT")
    print("="*80)
    print(f"Objective: {objective}")
    print(f"Clones per army: {clones_per_army}")
    print()

    # Show auto-selected armies
    selected = commander.select_armies_for_objective(objective)
    print(f"Auto-selected armies ({len(selected)}):")
    for army in selected:
        sign = next((m.sign for m in ZODIAC_ARMY_MAPPINGS if m.army == army), None)
        mapping = next((m for m in ZODIAC_ARMY_MAPPINGS if m.army == army), None)
        if sign and mapping:
            print(f"  • {army.value.upper():<15} → {sign.value.title():<12} ({mapping.element}/{mapping.modality}, synergy {mapping.synergy_score:.0%})")
    print()

    # Deploy
    deployment = await commander.deploy_unified(
        objective=objective,
        auto_select=True,
        clones_per_army=clones_per_army
    )

    print("\n✅ Deployment Complete!")
    print(f"   Armies Deployed: {', '.join(a.value for a in deployment.armies_deployed)}")
    print(f"   Total Clones: {deployment.total_clones:,}")
    print(f"   Duration: {deployment.total_duration_ms}ms")
    print(f"   Throughput: {deployment.total_clones / (deployment.total_duration_ms / 1000):.1f} clones/sec" if deployment.total_duration_ms > 0 else "")
    print(f"   Victories: {deployment.victories}/{deployment.total_clones}")
    print(f"   Synergy Score: {deployment.synergy_score:.0%}")

    # Show zodiac distribution
    print("\n📊 Zodiac Distribution:")
    zodiac_counts = {}
    for result in deployment.results:
        zodiac_counts[result.zodiac_sign] = zodiac_counts.get(result.zodiac_sign, 0) + 1

    for sign, count in sorted(zodiac_counts.items(), key=lambda x: x[1], reverse=True):
        mapping = next((m for m in ZODIAC_ARMY_MAPPINGS if m.sign == sign), None)
        if mapping:
            print(f"  {sign.value.title():<12} ({mapping.element:>5}/{mapping.modality:<8}): {count:>4} clones ({count/deployment.total_clones*100:>5.1f}%)")

    return deployment


async def deploy_specific_armies(army_names: list[str], clones_per_army: int = 10):
    """Deploy specific armies"""
    commander = get_unified_commander()

    armies = [ArmyType(name) for name in army_names]

    print("="*80)
    print("🎯 DEPLOYING SPECIFIC ARMIES")
    print("="*80)
    print(f"Armies: {', '.join(a.value for a in armies)}")
    print()

    deployment = await commander.deploy_unified(
        objective=f"Deploy {', '.join(army_names)}",
        auto_select=False,
        armies=armies,
        clones_per_army=clones_per_army
    )

    print("\n✅ Deployment Complete!")
    print(f"   Total Clones: {deployment.total_clones:,}")
    print(f"   Duration: {deployment.total_duration_ms}ms")
    print(f"   Victories: {deployment.victories}/{deployment.total_clones}")

    return deployment


async def main():
    """Main entry point"""
    import argparse

    parser = argparse.ArgumentParser(
        description="Deploy Unified Zodiac Army System",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog=__doc__
    )
    parser.add_argument('--objective', type=str, help="Objective for auto-selection")
    parser.add_argument('--armies', type=str, help="Comma-separated army types")
    parser.add_argument('--all', action='store_true', help="Deploy all 12 armies")
    parser.add_argument('--clones', type=int, default=10, help="Clones per army")
    parser.add_argument('--show-mappings', action='store_true', help="Show zodiac-army mappings")
    parser.add_argument('--report', action='store_true', help="Generate full report")

    args = parser.parse_args()

    if args.show_mappings:
        show_mappings()
        return 0

    commander = get_unified_commander()

    print("\n🌟 UNIFIED ZODIAC ARMY SYSTEM")
    print(f"Engine: {'🦀 Rust (534K clones/sec)' if commander.rust_available else '🐍 Python (50 clones/sec/core)'}")
    print()

    deployment = None

    if args.all:
        deployment = await deploy_all_armies(args.clones)
    elif args.objective:
        deployment = await deploy_objective(args.objective, args.clones)
    elif args.armies:
        army_names = [a.strip() for a in args.armies.split(',')]
        deployment = await deploy_specific_armies(army_names, args.clones)
    else:
        # Default: demo deployment
        print("Running demo deployment...")
        print("Use --help for options\n")
        deployment = await deploy_objective(
            "Optimize embeddings hot path for maximum throughput",
            clones_per_army=10
        )

    # Generate report if requested
    if args.report and deployment:
        print("\n" + "="*80)
        report = commander.generate_report()
        print(report)

        # Save report
        report_path = project_root / "reports" / f"unified_zodiac_deployment_{int(time.time())}.md"
        report_path.write_text(report)
        print(f"\n📄 Report saved: {report_path}")

    # Show stats
    stats = commander.get_stats()
    print("\n" + "="*80)
    print("📊 CUMULATIVE STATS")
    print("="*80)
    print(f"Total Deployments: {stats['total_deployments']}")
    print(f"Total Clones: {stats['total_clones']:,}")
    print(f"Total Victories: {stats['total_victories']:,}")
    print(f"Victory Rate: {stats['victory_rate']:.1%}")
    print(f"Avg Synergy Score: {stats['avg_synergy_score']:.1%}")
    print("="*80)

    return 0


if __name__ == '__main__':
    sys.exit(asyncio.run(main()))
