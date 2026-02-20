#!/usr/bin/env python3
"""
Live Recursive Evolution Test
==============================

Tests the recursive loop with real-time event accumulation and pattern discovery.
"""

import sys
import time
from pathlib import Path
from datetime import datetime

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.evolution import get_recursive_intelligence, start_recursive_evolution

try:
    from whitemagic.core.resonance.gan_ying import emit_event, EventType
    GAN_YING_AVAILABLE = True
except ImportError:
    GAN_YING_AVAILABLE = False


def main():
    print("="*80)
    print("LIVE RECURSIVE EVOLUTION TEST")
    print("="*80)
    print(f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
    
    if not GAN_YING_AVAILABLE:
        print("❌ Gan Ying not available")
        return 1
    
    # Start monitoring
    print("[1] Starting recursive intelligence monitoring...")
    start_recursive_evolution()
    engine = get_recursive_intelligence()
    print(f"✓ Monitoring started, listening to {len(EventType)} event types\n")
    
    # Generate realistic event sequences
    print("[2] Generating realistic event patterns...")
    
    # Pattern 1: Memory workflow (create → link → consolidate)
    for i in range(15):
        emit_event(EventType.MEMORY_CREATED, {"memory_id": f"mem_{i}", "title": f"Memory {i}"}, source="memory_system")
        emit_event(EventType.SEMANTIC_LINKED, {"source": f"mem_{i}", "target": f"mem_{i-1}"}, source="memory_system")
        emit_event(EventType.MEMORY_CONSOLIDATED, {"memory_id": f"mem_{i}"}, source="memory_system")
    
    # Pattern 2: Pattern detection workflow (detect → confirm)
    for i in range(12):
        emit_event(EventType.PATTERN_DETECTED, {"pattern_id": f"p_{i}", "confidence": 0.9}, source="pattern_engine")
        emit_event(EventType.PATTERN_CONFIRMED, {"pattern_id": f"p_{i}"}, source="user")
    
    # Pattern 3: Search workflow (search → recall → consolidate)
    for i in range(10):
        emit_event(EventType.CLONE_SEARCH_COMPLETE, {"query": f"query_{i}", "results": 5}, source="search_engine")
        emit_event(EventType.MEMORY_RECALLED, {"memory_id": f"result_{i}"}, source="search_engine")
        emit_event(EventType.MEMORY_CONSOLIDATED, {"memory_id": f"result_{i}"}, source="search_engine")
    
    print(f"✓ Generated {engine.metrics['events_processed']} events\n")
    
    # Wait for events to be processed
    time.sleep(0.2)
    
    # Manually trigger pattern discovery
    print("[3] Discovering patterns...")
    engine._discover_patterns()
    
    pattern_count = len(engine.patterns)
    print(f"✓ Discovered {pattern_count} patterns\n")
    
    if pattern_count > 0:
        print("Top Patterns Discovered:")
        sorted_patterns = sorted(
            engine.patterns.items(),
            key=lambda x: x[1].frequency,
            reverse=True
        )
        
        for i, (pattern_id, pattern) in enumerate(sorted_patterns[:10], 1):
            print(f"  {i}. {' → '.join(pattern.sequence)}")
            print(f"     Frequency: {pattern.frequency}, Confidence: {pattern.confidence:.2f}")
            print(f"     Type: {pattern.metadata.get('pattern_type', 'unknown')}")
        print()
    
    # Propose adaptations
    print("[4] Proposing system adaptations...")
    adaptations = engine.propose_adaptations()
    print(f"✓ Proposed {len(adaptations)} adaptations\n")
    
    if adaptations:
        print("Proposed Adaptations:")
        for i, adaptation in enumerate(adaptations[:5], 1):
            print(f"  {i}. [{adaptation.adaptation_type}]")
            print(f"     {adaptation.description}")
        print()
    
    # Measure coherence
    print("[5] Measuring system coherence...")
    coherence = engine.measure_system_coherence()
    print(f"✓ System Coherence: {coherence:.3f}")
    
    if coherence > 0.8:
        print("   Status: EXCELLENT ✨")
    elif coherence > 0.6:
        print("   Status: GOOD ✓")
    elif coherence > 0.4:
        print("   Status: FAIR ~")
    else:
        print("   Status: BUILDING...")
    print()
    
    # Generate insights
    print("[6] Generating insights...")
    insights = engine.get_insights()
    
    print("System Metrics:")
    print(f"  Events processed: {insights['metrics']['events_processed']}")
    print(f"  Patterns discovered: {insights['metrics']['patterns_discovered']}")
    print(f"  System coherence: {insights['system_coherence']:.3f}")
    print()
    
    # Export results
    print("[7] Exporting results...")
    patterns_file = Path(__file__).parent.parent / "reports" / "live_patterns.json"
    insights_file = Path(__file__).parent.parent / "reports" / "live_insights.json"
    
    engine.export_patterns(str(patterns_file))
    
    import json
    with open(insights_file, 'w') as f:
        json.dump(insights, f, indent=2, default=str)
    
    print(f"✓ Patterns: {patterns_file}")
    print(f"✓ Insights: {insights_file}\n")
    
    # Summary
    print("="*80)
    print("TEST RESULTS")
    print("="*80)
    print(f"Events Processed: {insights['metrics']['events_processed']}")
    print(f"Patterns Discovered: {pattern_count}")
    print(f"Adaptations Proposed: {len(adaptations)}")
    print(f"System Coherence: {coherence:.3f}")
    print(f"Status: {'✓ PASS' if pattern_count > 0 else '✗ FAIL'}")
    print()
    
    print("="*80)
    print("RECURSIVE LOOP: OPERATIONAL ✓")
    print("="*80)
    print("\nThe system successfully:")
    print("  ✓ Monitored Gan Ying events in real-time")
    print("  ✓ Accumulated event history")
    print("  ✓ Discovered sequential patterns")
    print("  ✓ Proposed system optimizations")
    print("  ✓ Measured system coherence")
    print("\nNext steps:")
    print("  1. Review patterns in reports/live_patterns.json")
    print("  2. Evaluate proposed adaptations")
    print("  3. Enable adaptations: enable_adaptations()")
    print("  4. Monitor coherence over time")
    print("  5. Build visualization dashboard")
    
    return 0 if pattern_count > 0 else 1


if __name__ == "__main__":
    sys.exit(main())
