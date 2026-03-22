#!/usr/bin/env python3
"""
Test Tactical Pipeline — Demonstrate Yin-Yang Cyclical Refinement

Runs a sample campaign through the 7-phase pipeline to show:
1. Scout → Discover → Clarify → Plan (YIN)
2. Execute → Verify (YANG)
3. Reflect (YIN) → back to Scout

This validates the pipeline architecture before full integration.
"""

import sys
from pathlib import Path

# Add whitemagic to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.agents.pipeline_integration import create_pipeline_integration


def main():
    """Run tactical pipeline test on V009 campaign"""

    print("=" * 70)
    print("TACTICAL PIPELINE TEST — V009 Windsurf Conversation Ingestion")
    print("=" * 70)
    print()

    # Create pipeline for V009 (high progress campaign, good test case)
    campaign_file = Path(__file__).parent.parent / "campaigns" / "V009_windsurf_conversation_ingestion.md"

    if not campaign_file.exists():
        print(f"❌ Campaign file not found: {campaign_file}")
        return 1

    print(f"📁 Campaign file: {campaign_file}")
    print()

    # Create pipeline integration
    integration = create_pipeline_integration("V009", campaign_file)

    # Run cycles until victory or max cycles
    max_cycles = 3
    cycle = 1

    while cycle <= max_cycles:
        print(f"\n{'=' * 70}")
        print(f"CYCLE {cycle}/{max_cycles}")
        print(f"{'=' * 70}\n")

        # Run full cycle
        result = integration.run_full_cycle()

        # Show progress
        print("\n" + result['progress_report'])
        print()

        # Check if we should continue
        if not result['should_continue']:
            if integration.pipeline.state.victory_achieved:
                print("\n🎉 VICTORY ACHIEVED!")
                print(f"Victory in cycle {integration.pipeline.state.victory_cycle}")
            else:
                print("\n⚠️ Stopping: Max cycles or stagnation reached")
            break

        cycle += 1

    # Final summary
    print("\n" + "=" * 70)
    print("FINAL SUMMARY")
    print("=" * 70)

    summary = integration.pipeline.get_cycle_summary()
    print(f"\nTotal cycles: {summary['cycle_number']}")
    print(f"Victory achieved: {summary['victory_achieved']}")
    print(f"Stagnation count: {summary['stagnation_count']}")
    print("\nIntelligence gathered:")
    print(f"  - Scout findings: {summary['findings']}")
    print(f"  - Patterns discovered: {summary['patterns']}")
    print(f"  - Objectives refined: {summary['refined_objectives']}")
    print(f"  - Strategies simulated: {summary['strategies']}")
    print("\nExecution:")
    print(f"  - Deployments: {summary['executions']}")
    print(f"  - Verifications: {summary['verifications']}")

    print("\n✅ Pipeline test complete!")
    return 0


if __name__ == "__main__":
    sys.exit(main())
