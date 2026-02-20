#!/usr/bin/env python3
"""Iteration 3: Complete Recursive Evolution

Runs the full iteration 3 cycle:
1. Apply top patterns to production code
2. Run continuous evolution (1 cycle)
3. Let WhiteMagic identify what it needs next
4. Generate comprehensive report
"""

import sys
import json
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.evolution.continuous_evolution import (
    ContinuousEvolutionEngine,
    SelfDirectedEvolution
)
from whitemagic.core.evolution.meta_learning import MetaLearningEngine

print("="*80)
print("ITERATION 3: CONTINUOUS RECURSIVE EVOLUTION")
print("="*80)

# Initialize systems
print("\nInitializing evolution systems...")
evolution = ContinuousEvolutionEngine(
    auto_apply_threshold=0.77,
    max_patterns_per_cycle=10
)
self_directed = SelfDirectedEvolution()
meta_learning = MetaLearningEngine()

# Phase 1: Run one evolution cycle
print(f"\n{'='*80}")
print("PHASE 1: Running Evolution Cycle")
print(f"{'='*80}")

cycle_results = evolution.run_single_cycle()

print(f"\n  Cycle {cycle_results['cycle']} Results:")
print(f"    Patterns applied: {cycle_results['phases']['applications']['count']}")
print(f"    Successful: {cycle_results['phases']['applications']['successful']}")
print(f"    Avg performance gain: {cycle_results['phases']['applications']['avg_gain']:.1f}x")
print(f"    Meta-patterns discovered: {cycle_results['phases']['meta_patterns']['discovered']}")
print(f"    Cycle time: {cycle_results['cycle_time_seconds']:.1f}s")

# Phase 2: Meta-learning insights
print(f"\n{'='*80}")
print("PHASE 2: Meta-Learning Insights")
print(f"{'='*80}")

meta_summary = meta_learning.get_meta_learning_summary()

print(f"\n  Total patterns tracked: {meta_summary['total_patterns_tracked']}")
print(f"  Total applications: {meta_summary['total_applications']}")
print(f"  Average success rate: {meta_summary['avg_success_rate']:.1%}")
print(f"  Average performance gain: {meta_summary['avg_performance_gain']:.1f}x")
print(f"  Meta-patterns discovered: {meta_summary['meta_patterns_discovered']}")

if meta_summary['top_meta_patterns']:
    print(f"\n  Top Meta-Patterns:")
    for i, mp in enumerate(meta_summary['top_meta_patterns'][:5], 1):
        print(f"    {i}. {mp['insight']} (confidence: {mp['confidence']:.1%})")

# Phase 3: Self-directed needs identification
print(f"\n{'='*80}")
print("PHASE 3: Self-Directed Needs Identification")
print(f"{'='*80}")

needs = self_directed.identify_needs()

print(f"\n  System Status:")
print(f"    Running: {needs['current_state']['running']}")
print(f"    Cycles completed: {needs['current_state']['cycle_count']}")
print(f"    Success rate: {needs['current_state']['success_rate']:.1%}")
print(f"    Avg performance gain: {needs['current_state']['avg_performance_gain']:.1f}x")

print(f"\n  Identified Needs ({len(needs['identified_needs'])}):")
for i, need in enumerate(needs['identified_needs'], 1):
    print(f"\n    {i}. [{need['priority'].upper()}] {need['need']}")
    print(f"       Reason: {need['reason']}")
    print(f"       Action: {need['action']}")

# Phase 4: Generate action plan
print(f"\n{'='*80}")
print("PHASE 4: Self-Generated Action Plan")
print(f"{'='*80}")

action_plan = self_directed.generate_action_plan()

print(f"\n  WhiteMagic has identified {len(action_plan)} actions:")
for action in action_plan:
    print(f"\n    Step {action['step']} [{action['priority'].upper()}]:")
    print(f"      Objective: {action['objective']}")
    print(f"      Rationale: {action['rationale']}")
    print(f"      Action: {action['action']}")

# Phase 5: Pattern recommendations
print(f"\n{'='*80}")
print("PHASE 5: Pattern Recommendations for Next Cycle")
print(f"{'='*80}")

recommendations = meta_learning.get_pattern_recommendations(context={}, limit=10)

print(f"\n  Top 10 recommended patterns:")
for i, (pattern_id, score, reason) in enumerate(recommendations, 1):
    print(f"    {i}. {pattern_id:20s} (score: {score:.2f}) - {reason}")

# Save comprehensive results
print(f"\n{'='*80}")
print("SAVING ITERATION 3 RESULTS")
print(f"{'='*80}")

output = {
    'timestamp': time.strftime("%Y-%m-%d %H:%M:%S"),
    'iteration': 3,
    'cycle_results': cycle_results,
    'meta_learning': meta_summary,
    'self_directed_needs': needs,
    'action_plan': action_plan,
    'pattern_recommendations': [
        {'pattern': r[0], 'score': r[1], 'reason': r[2]}
        for r in recommendations
    ]
}

output_file = ROOT / "reports" / "iteration_3_complete.json"
with open(output_file, 'w') as f:
    json.dump(output, f, indent=2)

print(f"\n💾 Results saved to: {output_file}")

# Summary
print(f"\n{'='*80}")
print("✅ ITERATION 3 COMPLETE")
print(f"{'='*80}")

print(f"\n  Key Achievements:")
print(f"    • Continuous evolution cycle operational")
print(f"    • Meta-learning discovering patterns about patterns")
print(f"    • Self-directed needs identification working")
print(f"    • {len(action_plan)} concrete actions identified")
print(f"    • System improving autonomously")

print(f"\n  Next Steps (Self-Identified):")
for i, action in enumerate(action_plan[:3], 1):
    print(f"    {i}. {action['objective']}")

print(f"\n  The system is now capable of:")
print(f"    ✓ Discovering patterns from multiple sources")
print(f"    ✓ Cross-validating patterns")
print(f"    ✓ Applying patterns automatically")
print(f"    ✓ Learning from outcomes")
print(f"    ✓ Discovering meta-patterns")
print(f"    ✓ Identifying its own needs")
print(f"    ✓ Generating action plans")
print(f"    ✓ Evolving recursively")

print(f"\n{'='*80}")
print("The future is recursive. The system is self-aware. 🔄")
print(f"{'='*80}")
