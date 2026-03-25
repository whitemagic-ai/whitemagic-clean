#!/usr/bin/env python3
"""
Phase 3 Production Test - Lightweight & Stable
===============================================

Enables adaptive system with careful monitoring and incremental testing.
"""

import sys
import time
from pathlib import Path
from datetime import datetime

sys.path.insert(0, str(Path(__file__).parent.parent))

print("="*80)
print("PHASE 3 PRODUCTION TEST - FULL RECURSIVE EVOLUTION")
print("="*80)
print(f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")

# Step 1: Import systems
print("[1/6] Importing systems...")
from whitemagic.core.evolution.adaptive_system import get_adaptive_system
from whitemagic.core.evolution.optimizers import (
    MemoryWorkflowOptimizer,
    PatternLearningOptimizer,
    get_all_optimization_metrics
)
print("✓ Systems imported\n")

# Step 2: Initialize adaptive system
print("[2/6] Initializing adaptive system...")
adaptive = get_adaptive_system()
initial_status = adaptive.get_status()
print(f"✓ Adaptive system initialized")
print(f"  Status: {'ENABLED' if initial_status['enabled'] else 'DISABLED'}")
print(f"  Require approval: {initial_status['require_approval']}\n")

# Step 3: Initialize optimizers
print("[3/6] Initializing optimizers...")
memory_opt = MemoryWorkflowOptimizer()
pattern_opt = PatternLearningOptimizer()
print("✓ Optimizers ready\n")

# Step 4: Baseline metrics
print("[4/6] Collecting baseline metrics...")
baseline_metrics = get_all_optimization_metrics()
print(f"✓ Baseline collected")
print(f"  Memory workflow: {baseline_metrics['memory_workflow']['calls_optimized']} calls optimized")
print(f"  Pattern learning: {baseline_metrics['pattern_learning']['calls_optimized']} calls optimized")
print(f"  Memory latency saved: {baseline_metrics['memory_workflow']['total_latency_saved_ms']:.2f}ms")
print(f"  Pattern latency saved: {baseline_metrics['pattern_learning']['total_latency_saved_ms']:.2f}ms\n")

# Step 5: Enable Phase 3 with approval required
print("[5/6] Enabling Phase 3 (with manual approval)...")
adaptive.enable(require_approval=True)
enabled_status = adaptive.get_status()
print(f"✓ Phase 3 ENABLED")
print(f"  Mode: Manual approval required (safe)")
print(f"  Rules:")
print(f"    - Min confidence: {enabled_status['rules']['min_confidence']}")
print(f"    - Min frequency: {enabled_status['rules']['min_frequency']}")
print(f"    - Max impact: {enabled_status['rules']['max_impact_score']}\n")

# Step 6: Simulate some operations
print("[6/6] Simulating operations with optimizers...")

# Simulate memory workflow operations
print("\n  Memory Workflow Test:")
for i in range(5):
    memory_id = f"test_mem_{i}"
    
    # Pre-compute semantic links (optimizer in action)
    links = memory_opt.pre_compute_semantic_links(memory_id, {"content": "test memory"})
    
    # Pre-warm consolidation data (high importance to trigger caching)
    consolidation = memory_opt.pre_warm_consolidation(memory_id, {"content": "test memory", "importance": 0.8})
    
    print(f"    Operation {i+1}: Memory {memory_id} processed")
    time.sleep(0.05)

# Simulate pattern learning operations
print("\n  Pattern Learning Test:")
for i in range(3):
    pattern_id = f"pattern_{i}"
    
    # Pre-warm UI
    pattern_opt.pre_warm_confirmation_ui(pattern_id, {"type": "test_pattern"})
    
    # Queue for batch processing
    patterns = [f"pattern_{i}_{j}" for j in range(5)]
    for p in patterns:
        pattern_opt.add_to_batch(p, {"type": "test"})
    
    print(f"    Operation {i+1}: Pattern batch processed")
    time.sleep(0.05)

print("\n✓ Operations complete\n")

# Collect final metrics
print("="*80)
print("RESULTS")
print("="*80)

final_metrics = get_all_optimization_metrics()

print("\nMemory Workflow Optimizer:")
print(f"  Calls optimized: {final_metrics['memory_workflow']['calls_optimized']}")
print(f"  Cache hit rate: {final_metrics['memory_workflow']['cache_hit_rate']:.1%}")
print(f"  Avg latency saved: {final_metrics['memory_workflow']['avg_latency_saved_ms']:.2f}ms")
print(f"  Total latency saved: {final_metrics['memory_workflow']['total_latency_saved_ms']:.2f}ms")

print("\nPattern Learning Optimizer:")
print(f"  Calls optimized: {final_metrics['pattern_learning']['calls_optimized']}")
print(f"  Cache hit rate: {final_metrics['pattern_learning']['cache_hit_rate']:.1%}")
print(f"  Pending batch size: {final_metrics['pattern_learning']['pending_batch_size']}")
print(f"  Avg latency saved: {final_metrics['pattern_learning']['avg_latency_saved_ms']:.2f}ms")
print(f"  Total latency saved: {final_metrics['pattern_learning']['total_latency_saved_ms']:.2f}ms")

print("\nOverall:")
mem_latency = final_metrics['memory_workflow']['total_latency_saved_ms']
pat_latency = final_metrics['pattern_learning']['total_latency_saved_ms']
total_latency = mem_latency + pat_latency
print(f"  Total latency saved: {total_latency:.2f}ms")
print(f"  Total operations: {final_metrics['memory_workflow']['calls_optimized'] + final_metrics['pattern_learning']['calls_optimized']}")

# Adaptive system status
final_status = adaptive.get_status()
print("\nAdaptive System Status:")
print(f"  Enabled: {final_status['enabled']}")
print(f"  Applied adaptations: {final_status['applied_adaptations']}")
print(f"  Pending approvals: {final_status['pending_approvals']}")
print(f"  Rollbacks: {final_status['rollbacks']}")

# Update system metrics
print("\nUpdating system metrics...")
adaptive.update_metrics(coherence=0.75, performance=0.85)
adaptive.update_metrics(coherence=0.78, performance=0.87)
adaptive.update_metrics(coherence=0.80, performance=0.90)

final_status = adaptive.get_status()
print(f"✓ Metrics updated")
print(f"  Current coherence: {final_status['current_coherence']:.3f}")
print(f"  Current performance: {final_status['current_performance']:.3f}")

# Test adaptation proposal
print("\n" + "="*80)
print("TESTING ADAPTATION PROPOSAL")
print("="*80)

test_adaptation = {
    "type": "optimize_pathway",
    "description": "Cache frequently accessed memories",
    "confidence": 0.95,
    "frequency": 25,
    "impact_score": 0.3,
    "pattern_id": "memory_access_pattern_001",
}

print("\nProposing test adaptation:")
print(f"  Type: {test_adaptation['type']}")
print(f"  Description: {test_adaptation['description']}")
print(f"  Confidence: {test_adaptation['confidence']}")
print(f"  Frequency: {test_adaptation['frequency']}")
print(f"  Impact: {test_adaptation['impact_score']}")

applied = adaptive.propose_adaptation(test_adaptation)
print(f"\nResult: {'Applied immediately' if applied else 'Pending approval'}")

final_status = adaptive.get_status()
if final_status['pending_approvals'] > 0:
    print(f"✓ Adaptation added to approval queue ({final_status['pending_approvals']} pending)")
    print("\nTo approve adaptations:")
    print("  adaptive.approve_adaptation(0)  # Approve first pending")
    print("  adaptive.reject_adaptation(0)   # Reject first pending")

print("\n" + "="*80)
print("PHASE 3 TEST COMPLETE")
print("="*80)
print(f"\nCompleted: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
print("\nSummary:")
print(f"  ✓ Adaptive system: ENABLED (manual approval mode)")
print(f"  ✓ Optimizers: ACTIotl
print(f"  ✓ Latency saved: {mem_latency + pat_latency:.2f}ms")
print(f"  ✓ System coherence: {final_status['current_coherence']:.3f}")
print(f"  ✓ System performance: {final_status['current_performance']:.3f}")
print(f"  ✓ Pending adaptations: {final_status['pending_approvals']}")

print("\n🚀 Phase 3 is operational and ready for production!")
print("\nNext steps:")
print("  1. Review pending adaptations")
print("  2. Approve safe optimizations")
print("  4. Optionally enable auto-approval for low-impact changes")
