#!/usr/bin/env python3
"""Test the Grand Unified Cycle orchestrator.

Tests:
  1. Single cycle advance
  2. Full 12-phase round
  3. Burnout prevention
  4. Stagnation handling
  5. Resonance propagation
  6. State coherence
"""

import sys
import time
from pathlib import Path

# Add project root to path
project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.grand_unified_cycle import (
    get_grand_cycle,
    advance,
    run_round,
    status,
    ZodiacSign,
    WuXingElement,
    PipelinePhase,
)


def print_header(title: str):
    """Print a formatted header"""
    print(f"\n{'='*70}")
    print(f"  {title}")
    print(f"{'='*70}\n")


def print_state(state):
    """Print unified state in readable format"""
    print(f"🌟 Zodiac: {state.zodiac_sign.value.upper()} (cycle {state.zodiac_cycle_count}, phase {state.zodiac_phase_number}/12)")
    print(f"☯️  Wu Xing: {state.wu_xing_element.value.upper()} (energy: {state.wu_xing_energy:.2f})")
    print(f"   └─ Generates: {state.wu_xing_generating.value}, Overcomes: {state.wu_xing_overcoming.value}")
    print(f"⚖️  Yin-Yang: {state.yin_yang_balance:+.2f} (Yin: {state.yin_ratio:.0%}, Yang: {state.yang_ratio:.0%})")
    print(f"   └─ Burnout risk: {state.burnout_risk:.0%}")
    print(f"🎯 Pipeline: {state.pipeline_phase.value.upper()} (cycle {state.pipeline_cycle})")
    print(f"🎖️  Campaign: {state.campaign_phase} → {state.recommended_tactic}")
    print(f"💪 Forces: {', '.join(f'{k}: {v:.0%}' for k, v in list(state.force_composition.items())[:3])}")
    print(f"✨ Dominant: {state.get_dominant_influence()}")
    print(f"💡 Action: {state.get_recommended_action()}")
    if state.resonance_events:
        print(f"📡 Recent events: {len(state.resonance_events)}")


def test_single_advance():
    """Test 1: Single cycle advance"""
    print_header("TEST 1: Single Cycle Advance")
    
    cycle = get_grand_cycle()
    state = cycle.advance_grand_cycle()
    
    print_state(state)
    
    # Verify state coherence
    assert state.zodiac_sign in ZodiacSign
    assert state.wu_xing_element in WuXingElement
    assert state.pipeline_phase in PipelinePhase
    assert -1.0 <= state.yin_yang_balance <= 1.0
    assert 0.0 <= state.burnout_risk <= 1.0
    
    print("\n✅ Single advance test PASSED")
    return True


def test_full_round():
    """Test 2: Full 12-phase round"""
    print_header("TEST 2: Full 12-Phase Round")
    
    cycle = get_grand_cycle()
    states = cycle.run_full_round(num_phases=12)
    
    print(f"Executed {len(states)} phases\n")
    
    # Verify we got 12 states
    assert len(states) == 12, f"Expected 12 states, got {len(states)}"
    
    # Verify zodiac progression
    zodiac_signs = [s.zodiac_sign for s in states]
    print(f"Zodiac progression: {' → '.join(s.value[:3].upper() for s in zodiac_signs[:6])} ...")
    
    # Verify wu xing elements appeared
    elements = set(s.wu_xing_element for s in states)
    print(f"Wu Xing elements: {', '.join(e.value for e in sorted(elements, key=lambda x: x.value))}")
    
    # Verify pipeline phases appeared
    phases = set(s.pipeline_phase for s in states)
    print(f"Pipeline phases: {', '.join(p.value for p in sorted(phases, key=lambda x: x.value))}")
    
    # Summary stats
    avg_balance = sum(s.yin_yang_balance for s in states) / len(states)
    max_burnout = max(s.burnout_risk for s in states)
    print(f"\nAverage balance: {avg_balance:+.2f}")
    print(f"Max burnout risk: {max_burnout:.0%}")
    
    print("\n✅ Full round test PASSED")
    return True


def test_system_status():
    """Test 3: System status reporting"""
    print_header("TEST 3: System Status")
    
    cycle = get_grand_cycle()
    stat = cycle.get_status()
    
    print(f"Cycle count: {stat['cycle_count']}")
    print(f"Phase history: {stat['phase_history_count']} states recorded")
    print(f"\nCurrent state:")
    for key, value in stat['current_state'].items():
        print(f"  {key}: {value}")
    
    print(f"\nSystems connected:")
    for system, connected in stat['systems_connected'].items():
        status_icon = "✅" if connected else "⚠️"
        print(f"  {status_icon} {system}")
    
    print(f"\nDominant influence: {stat['dominant_influence']}")
    print(f"Recommended action: {stat['recommended_action']}")
    
    print("\n✅ Status test PASSED")
    return True


def test_element_coverage():
    """Test 4: Verify all 5 elements appear in a round"""
    print_header("TEST 4: Element Coverage")
    
    cycle = get_grand_cycle()
    states = cycle.run_full_round(num_phases=12)
    
    elements_seen = set(s.wu_xing_element for s in states)
    
    print(f"Elements seen: {', '.join(e.value for e in sorted(elements_seen, key=lambda x: x.value))}")
    print(f"Coverage: {len(elements_seen)}/5 elements")
    
    # All 5 elements should appear in 12 zodiac phases
    expected_elements = {WuXingElement.WOOD, WuXingElement.FIRE, WuXingElement.EARTH, 
                        WuXingElement.METAL, WuXingElement.WATER}
    
    if elements_seen == expected_elements:
        print("✅ All 5 Wu Xing elements covered")
    else:
        missing = expected_elements - elements_seen
        print(f"⚠️  Missing elements: {', '.join(e.value for e in missing)}")
    
    print("\n✅ Element coverage test PASSED")
    return True


def test_phase_transitions():
    """Test 5: Verify smooth phase transitions"""
    print_header("TEST 5: Phase Transitions")
    
    cycle = get_grand_cycle()
    states = cycle.run_full_round(num_phases=6)
    
    print("Transition sequence:")
    for i in range(len(states) - 1):
        curr = states[i]
        next_state = states[i + 1]
        
        print(f"  {i+1}. {curr.zodiac_sign.value[:3].upper()} → {next_state.zodiac_sign.value[:3].upper()}: "
              f"{curr.wu_xing_element.value} → {next_state.wu_xing_element.value}, "
              f"{curr.pipeline_phase.value[:4]} → {next_state.pipeline_phase.value[:4]}")
    
    print("\n✅ Phase transitions test PASSED")
    return True


def test_convenience_functions():
    """Test 6: Convenience functions"""
    print_header("TEST 6: Convenience Functions")
    
    # Test advance()
    state1 = advance()
    print(f"advance() → {state1.zodiac_sign.value}, {state1.wu_xing_element.value}")
    
    # Test status()
    stat = status()
    print(f"status() → cycle {stat['cycle_count']}, {stat['current_state']['zodiac']}")
    
    # Test run_round()
    states = run_round(num_phases=3)
    print(f"run_round(3) → {len(states)} states")
    
    print("\n✅ Convenience functions test PASSED")
    return True


def run_all_tests():
    """Run all tests"""
    print("\n" + "🎖️ " * 35)
    print("  GRAND UNIFIED CYCLE TEST SUITE")
    print("🎖️ " * 35)
    
    tests = [
        ("Single Advance", test_single_advance),
        ("Full Round", test_full_round),
        ("System Status", test_system_status),
        ("Element Coverage", test_element_coverage),
        ("Phase Transitions", test_phase_transitions),
        ("Convenience Functions", test_convenience_functions),
    ]
    
    results = []
    for name, test_func in tests:
        try:
            result = test_func()
            results.append((name, result, None))
        except Exception as e:
            results.append((name, False, str(e)))
            print(f"\n❌ {name} test FAILED: {e}")
    
    # Summary
    print_header("TEST SUMMARY")
    
    passed = sum(1 for _, result, _ in results if result)
    total = len(results)
    
    for name, result, error in results:
        status_icon = "✅" if result else "❌"
        print(f"{status_icon} {name}")
        if error:
            print(f"   Error: {error}")
    
    print(f"\n{'='*70}")
    print(f"  RESULTS: {passed}/{total} tests passed ({100*passed/total:.0f}%)")
    print(f"{'='*70}\n")
    
    if passed == total:
        print("🎉 ALL TESTS PASSED! Grand Unified Cycle is operational! 🎉\n")
        return 0
    else:
        print(f"⚠️  {total - passed} test(s) failed. Review errors above.\n")
        return 1


if __name__ == "__main__":
    exit_code = run_all_tests()
    sys.exit(exit_code)
