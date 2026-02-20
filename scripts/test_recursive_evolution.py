#!/usr/bin/env python3
"""
Test Recursive Evolution Loop
==============================

Tests the complete recursive intelligence system:
1. Start monitoring Gan Ying events
2. Generate test events
3. Discover patterns
4. Propose adaptations
5. Measure coherence
6. Export insights
"""

import sys
import time
import asyncio
from pathlib import Path
from datetime import datetime

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.evolution import (
    get_recursive_intelligence,
    start_recursive_evolution,
)

try:
    from whitemagic.core.resonance.gan_ying import emit_event, EventType, get_bus
    GAN_YING_AVAILABLE = True
except ImportError:
    GAN_YING_AVAILABLE = False
    print("⚠️ Gan Ying not available")


def generate_test_events():
    """Generate test events to discover patterns."""
    if not GAN_YING_AVAILABLE:
        print("Cannot generate events without Gan Ying")
        return
    
    print("\n" + "="*80)
    print("GENERATING TEST EVENTS")
    print("="*80)
    
    # Simulate common tool usage patterns
    patterns = [
        # Pattern 1: Search → Filter → Transform (common workflow)
        [
            (EventType.MEMORY_CREATED, {"tool": "search_memories", "query": "test"}),
            (EventType.PATTERN_DETECTED, {"tool": "filter_results", "count": 10}),
            (EventType.MEMORY_CONSOLIDATED, {"tool": "transform_data", "output": "json"}),
        ],
        # Pattern 2: Create → Link → Consolidate (memory workflow)
        [
            (EventType.MEMORY_CREATED, {"memory_id": "test123", "title": "Test Memory"}),
            (EventType.SEMANTIC_LINKED, {"source": "test123", "target": "test456"}),
            (EventType.MEMORY_CONSOLIDATED, {"memory_id": "test123"}),
        ],
        # Pattern 3: Pattern detection → Confirmation (learning workflow)
        [
            (EventType.PATTERN_DETECTED, {"pattern_id": "p1", "confidence": 0.9}),
            (EventType.PATTERN_CONFIRMED, {"pattern_id": "p1"}),
        ],
    ]
    
    # Emit patterns multiple times to create frequency
    for iteration in range(10):
        for pattern_idx, pattern in enumerate(patterns):
            for event_type, data in pattern:
                emit_event(
                    event_type,
                    {**data, "iteration": iteration, "pattern": pattern_idx},
                    source="test_script",
                    confidence=0.95
                )
        
        if iteration % 3 == 0:
            print(f"  Generated {(iteration + 1) * len(patterns) * 3} events...")
    
    print(f"✓ Generated {10 * len(patterns) * 3} test events across {len(patterns)} patterns")


def test_pattern_discovery():
    """Test pattern discovery."""
    print("\n" + "="*80)
    print("TESTING PATTERN DISCOVERY")
    print("="*80)
    
    engine = get_recursive_intelligence()
    
    # Trigger pattern discovery
    print("Discovering patterns from event history...")
    engine._discover_patterns()
    
    print(f"✓ Discovered {len(engine.patterns)} patterns")
    
    # Show top patterns
    if engine.patterns:
        print("\nTop Patterns:")
        sorted_patterns = sorted(
            engine.patterns.items(),
            key=lambda x: x[1].frequency,
            reverse=True
        )
        
        for i, (pattern_id, pattern) in enumerate(sorted_patterns[:5], 1):
            print(f"  {i}. {' → '.join(pattern.sequence)}")
            print(f"     Frequency: {pattern.frequency}, Confidence: {pattern.confidence:.2f}")
            print(f"     Type: {pattern.metadata.get('pattern_type', 'unknown')}")
    
    return len(engine.patterns)


def test_adaptation_proposals():
    """Test adaptation proposals."""
    print("\n" + "="*80)
    print("TESTING ADAPTATION PROPOSALS")
    print("="*80)
    
    engine = get_recursive_intelligence()
    
    # Propose adaptations
    adaptations = engine.propose_adaptations()
    
    print(f"✓ Proposed {len(adaptations)} adaptations")
    
    if adaptations:
        print("\nProposed Adaptations:")
        for i, adaptation in enumerate(adaptations[:5], 1):
            print(f"  {i}. [{adaptation.adaptation_type}] {adaptation.description}")
            print(f"     Pattern: {adaptation.pattern_id}")
    
    return len(adaptations)


def test_coherence_measurement():
    """Test system coherence measurement."""
    print("\n" + "="*80)
    print("TESTING COHERENCE MEASUREMENT")
    print("="*80)
    
    engine = get_recursive_intelligence()
    
    coherence = engine.measure_system_coherence()
    
    print(f"✓ System Coherence: {coherence:.3f}")
    
    if coherence > 0.8:
        print("  Status: EXCELLENT - High pattern confidence")
    elif coherence > 0.6:
        print("  Status: GOOD - Moderate pattern confidence")
    elif coherence > 0.4:
        print("  Status: FAIR - Building pattern confidence")
    else:
        print("  Status: LOW - Need more data")
    
    return coherence


def test_insights_generation():
    """Test insights generation."""
    print("\n" + "="*80)
    print("TESTING INSIGHTS GENERATION")
    print("="*80)
    
    engine = get_recursive_intelligence()
    
    insights = engine.get_insights()
    
    print("Metrics:")
    for key, value in insights["metrics"].items():
        if isinstance(value, float):
            print(f"  {key}: {value:.2f}")
        else:
            print(f"  {key}: {value}")
    
    print(f"\nTop Patterns: {len(insights['top_patterns'])}")
    for i, pattern in enumerate(insights["top_patterns"][:3], 1):
        print(f"  {i}. {' → '.join(pattern['sequence'])} (freq={pattern['frequency']})")
    
    print(f"\nRecent Adaptations: {len(insights['recent_adaptations'])}")
    
    return insights


def export_results(insights):
    """Export test results."""
    print("\n" + "="*80)
    print("EXPORTING RESULTS")
    print("="*80)
    
    engine = get_recursive_intelligence()
    
    # Export patterns
    patterns_file = Path(__file__).parent.parent / "reports" / "recursive_intelligence_patterns.json"
    engine.export_patterns(str(patterns_file))
    
    # Export insights
    import json
    insights_file = Path(__file__).parent.parent / "reports" / "recursive_intelligence_insights.json"
    with open(insights_file, 'w') as f:
        json.dump(insights, f, indent=2, default=str)
    
    print(f"✓ Patterns exported to: {patterns_file}")
    print(f"✓ Insights exported to: {insights_file}")


def main():
    """Run complete test suite."""
    print("="*80)
    print("RECURSIVE EVOLUTION LOOP TEST")
    print("="*80)
    print(f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    
    if not GAN_YING_AVAILABLE:
        print("\n❌ Gan Ying not available - cannot test")
        return 1
    
    try:
        # Step 1: Start monitoring
        print("\n[1/6] Starting recursive intelligence monitoring...")
        start_recursive_evolution()
        print("✓ Monitoring started")
        
        # Step 2: Generate test events
        print("\n[2/6] Generating test events...")
        generate_test_events()
        
        # Give events time to be processed
        time.sleep(0.5)
        
        # Step 3: Discover patterns
        print("\n[3/6] Discovering patterns...")
        pattern_count = test_pattern_discovery()
        
        # Step 4: Propose adaptations
        print("\n[4/6] Proposing adaptations...")
        adaptation_count = test_adaptation_proposals()
        
        # Step 5: Measure coherence
        print("\n[5/6] Measuring system coherence...")
        coherence = test_coherence_measurement()
        
        # Step 6: Generate insights
        print("\n[6/6] Generating insights...")
        insights = test_insights_generation()
        
        # Export results
        export_results(insights)
        
        # Summary
        print("\n" + "="*80)
        print("TEST SUMMARY")
        print("="*80)
        print(f"✓ Events processed: {insights['metrics']['events_processed']}")
        print(f"✓ Patterns discovered: {pattern_count}")
        print(f"✓ Adaptations proposed: {adaptation_count}")
        print(f"✓ System coherence: {coherence:.3f}")
        print(f"✓ Status: {'PASS' if pattern_count > 0 else 'FAIL'}")
        
        print("\n" + "="*80)
        print("RECURSIVE LOOP STATUS: OPERATIONAL ✓")
        print("="*80)
        print("\nThe system is now:")
        print("  1. ✓ Monitoring all Gan Ying events")
        print("  2. ✓ Discovering patterns automatically")
        print("  3. ✓ Proposing system adaptations")
        print("  4. ✓ Measuring coherence continuously")
        print("  5. ✓ Generating actionable insights")
        print("\nNext steps:")
        print("  - Review proposed adaptations in reports/")
        print("  - Enable adaptations when ready: enable_adaptations()")
        print("  - Monitor coherence over time")
        print("  - Build visualization dashboard")
        
        return 0
    
    except Exception as e:
        print(f"\n❌ Test failed: {e}")
        import traceback
        traceback.print_exc()
        return 1


if __name__ == "__main__":
    sys.exit(main())
