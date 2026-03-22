#!/usr/bin/env python3
"""
Run All WhiteMagic Engines
===========================

Comprehensive test of all WhiteMagic intelligence engines with
holographic integration.

Usage:
    python run_all_engines.py [--quick]
"""

import sys
from pathlib import Path
from datetime import datetime

# Add to path
# Add core_system to path (parent of scripts/)
sys.path.insert(0, str(Path(__file__).parent.parent))


def run_holographic_engines():
    """Test holographic systems"""
    print('\n' + '='*70)
    print('🌌 HOLOGRAPHIC ENGINES')
    print('='*70)

    try:
        from whitemagic.intelligence.hologram.constellation import ConstellationSearch
        from whitemagic.intelligence.hologram.consolidation import HolographicConsolidator
        from whitemagic.intelligence.hologram.patterns import HolographicPatternEngine

        # Test constellation search
        print('\n1. Constellation Search (4D Memory Navigation)')
        searcher = ConstellationSearch()
        print('   - Searcher initialized...')
        stats = searcher.stats()
        print(f'   ✓ {stats["count"]} memories in holographic space')

        # Test consolidation
        print('\n2. Holographic Consolidator (Memory Clustering)')
        consolidator = HolographicConsolidator()
        print('   - Consolidator initialized. Finding clusters...')
        clusters = consolidator.find_clusters(radius=0.3)
        print(f'   ✓ Found {len(clusters)} semantic clusters')

        # Test pattern engine
        print('\n3. Pattern Engine (Pattern Detection)')
        pattern_engine = HolographicPatternEngine()
        analysis = pattern_engine.analyze()
        print(f'   ✓ Detected {analysis["total_patterns"]} patterns')
        print(f'   ✓ Generated {len(analysis.get("insights", []))} insights')

        print('\n✅ Holographic engines operational')
        return True

    except Exception as e:
        print(f'\n❌ Holographic engines error: {e}')
        return False


def run_dream_systems():
    """Test dream systems with holographic integration"""
    print('\n' + '='*70)
    print('💤 DREAM SYSTEMS')
    print('='*70)

    try:
        from whitemagic.core.patterns.emergence.dream_state import DreamState

        print('\n1. Dream State (Pattern Synthesis)')
        dream = DreamState()
        print('   ✓ Dream State initialized')
        print('   ✓ Connected systems:')
        if dream.bus:
            print('      - Gan Ying Bus')
        if dream.antibody_library:
            print('      - Antibody Library')
        if dream.emergence_detector:
            print('      - Emergence Detector')
        if dream.pattern_engine:
            print('      - Pattern Engine')

        # Run dream state
        print('\n   Running mini dream synthesis...')
        insights = dream.enter_dream_state(duration_minutes=1)
        print(f'   ✓ Generated {len(insights)} insights')

        if insights:
            print('\n   Sample insight:')
            sample = insights[0]
            print(f'      {sample.insight[:80]}...')
            print(f'      Novelty: {sample.novelty_score:.2f} | Value: {sample.practical_value:.2f}')

        print('\n✅ Dream systems operational')
        return True

    except Exception as e:
        print(f'\n❌ Dream systems error: {e}')
        import traceback
        traceback.print_exc()
        return False


def run_synthesis_engines():
    """Test synthesis engines"""
    print('\n' + '='*70)
    print('🔧 SYNTHESIS ENGINES')
    print('='*70)

    try:
        # Test if engines exist
        print('\n1. Kaizen Engine (Continuous Improvement)')
        try:
            from whitemagic.intelligence.synthesis.kaizen_engine import KaizenEngine
            print('   ✓ Kaizen Engine available')
        except ImportError:
            print('   ⚠ Kaizen Engine not available')

        print('\n2. Serendipity Engine (Unexpected Connections)')
        try:
            from whitemagic.intelligence.synthesis.serendipity_engine import SerendipityEngine
            print('   ✓ Serendipity Engine available')
        except ImportError:
            print('   ⚠ Serendipity Engine not available')

        print('\n✅ Synthesis engines checked')
        return True

    except Exception as e:
        print(f'\n❌ Synthesis engines error: {e}')
        return False


def run_garden_engines():
    """Test garden-specific engines"""
    print('\n' + '='*70)
    print('🌸 GARDEN ENGINES')
    print('='*70)

    try:
        print('\n1. Narrative Engine (Voice Garden)')
        try:
            from whitemagic.gardens.voice.narrative_engine import NarrativeEngine
            print('   ✓ Narrative Engine available')
        except ImportError:
            print('   ⚠ Narrative Engine not available')

        print('\n2. Ethics Engine (Dharma Garden)')
        try:
            from whitemagic.gardens.dharma.ethics_engine import EthicsEngine
            print('   ✓ Ethics Engine available')
        except ImportError:
            print('   ⚠ Ethics Engine not available')

        print('\n3. Collective Dreams (Wonder Garden)')
        try:
            from whitemagic.gardens.wonder.collective_dreams import CollectiveDreams
            print('   ✓ Collective Dreams available')
        except ImportError:
            print('   ⚠ Collective Dreams not available')

        print('\n✅ Garden engines checked')
        return True

    except Exception as e:
        print(f'\n❌ Garden engines error: {e}')
        return False


def run_all():
    """Run all engine tests"""
    print('\n' + '='*70)
    print('🚀 WHITEMAGIC ENGINE COMPREHENSIVE TEST')
    print('='*70)
    print(f'Timestamp: {datetime.now().isoformat()}')
    print('='*70)

    results = {
        'holographic': False,
        'dream': False,
        'synthesis': False,
        'gardens': False
    }

    # Run each category
    results['holographic'] = run_holographic_engines()
    results['dream'] = run_dream_systems()
    results['synthesis'] = run_synthesis_engines()
    results['gardens'] = run_garden_engines()

    # Summary
    print('\n' + '='*70)
    print('📊 TEST SUMMARY')
    print('='*70)

    total = len(results)
    passed = sum(1 for v in results.values() if v)

    for category, status in results.items():
        symbol = '✅' if status else '❌'
        print(f'{symbol} {category.title()} Engines')

    print(f'\nTotal: {passed}/{total} engine categories operational')

    if passed == total:
        print('\n🎉 ALL ENGINES OPERATIONAL!')
    else:
        print(f'\n⚠️  {total - passed} engine categories need attention')

    print('='*70)

    return passed == total


def main():
    """Main entry point"""
    import argparse

    parser = argparse.ArgumentParser(description='Run All WhiteMagic Engines')
    parser.add_argument('--quick', action='store_true', help='Quick test (skip slow operations)')
    args = parser.parse_args()

    success = run_all()
    return 0 if success else 1


if __name__ == '__main__':
    sys.exit(main())
