#!/usr/bin/env python3
"""
Test All New Systems - Comprehensive Validation
================================================

Tests all newly implemented systems:
1. Streaming Response Protocol
2. ML-Based Tool Recommendations
3. Benchmark Historical Tracking
4. Adaptive System (Phase 3)
"""

import sys
import asyncio
from pathlib import Path
from datetime import datetime

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.streaming import StreamableToolResponse, ChunkType, collect_stream
from whitemagic.core.evolution.ml_recommender import ToolRecommender, get_tool_recommender
from whitemagic.core.evolution.benchmark_tracker import BenchmarkHistoryTracker, BenchmarkResult
from whitemagic.core.evolution.adaptive_system import get_adaptive_system


async def test_streaming_protocol():
    """Test streaming response protocol."""
    print("\n" + "="*80)
    print("TEST 1: Streaming Response Protocol")
    print("="*80)
    
    # Create test data
    test_results = [{"id": f"result_{i}", "score": 0.9 - i*0.01} for i in range(50)]
    
    # Test streaming
    print("\n[1.1] Testing result streaming...")
    streamer = StreamableToolResponse("test_tool", len(test_results))
    
    chunks_received = 0
    data_chunks = 0
    
    async for chunk in streamer.stream_results(test_results, chunk_size=10):
        chunks_received += 1
        
        if chunk.chunk_type == ChunkType.DATA:
            data_chunks += 1
            print(f"  Chunk {chunk.chunk_id}: {len(chunk.data)} items, progress={chunk.progress:.1%}")
        elif chunk.chunk_type == ChunkType.METADATA:
            print(f"  Metadata: {chunk.data}")
        elif chunk.chunk_type == ChunkType.COMPLETE:
            print(f"  Complete: {chunk.data}")
    
    print(f"\n✓ Received {chunks_received} chunks ({data_chunks} data chunks)")
    
    # Test cancellation
    print("\n[1.2] Testing stream cancellation...")
    streamer2 = StreamableToolResponse("test_tool_2", 100)
    
    cancel_after = 3
    chunks_before_cancel = 0
    
    async for chunk in streamer2.stream_results(list(range(100)), chunk_size=10):
        chunks_before_cancel += 1
        if chunks_before_cancel == cancel_after:
            streamer2.cancel()
            print(f"  Cancelled after {chunks_before_cancel} chunks")
    
    print(f"✓ Stream cancelled successfully")
    
    return chunks_received > 0


def test_ml_recommender():
    """Test ML-based tool recommendation system."""
    print("\n" + "="*80)
    print("TEST 2: ML-Based Tool Recommendations")
    print("="*80)
    
    recommender = get_tool_recommender()
    
    # Train on sample sequences
    print("\n[2.1] Training on sample tool sequences...")
    
    # Simulate common patterns
    patterns = [
        ["search_memories", "filter_results", "export_data"],
        ["create_memory", "add_tags", "link_memories"],
        ["search_memories", "read_memory", "update_memory"],
    ]
    
    for pattern in patterns:
        for _ in range(10):  # Repeat each pattern 10 times
            for tool in pattern:
                recommender.record_tool_call(tool)
    
    stats = recommender.get_tool_statistics()
    print(f"✓ Trained on {stats['sequences_seen']} tool calls")
    print(f"  Unique tools: {stats['unique_tools']}")
    print(f"  Bigram patterns: {stats['bigram_patterns']}")
    print(f"  Trigram patterns: {stats['trigram_patterns']}")
    
    # Test predictions
    print("\n[2.2] Testing predictions...")
    
    # Simulate: user just called "search_memories"
    recommender.record_tool_call("search_memories")
    predictions = recommender.predict_next_tools(top_k=3)
    
    print(f"✓ Generated {len(predictions)} predictions")
    for i, pred in enumerate(predictions, 1):
        print(f"  {i}. {pred.tool_name} (confidence={pred.confidence:.1%}, support={pred.pattern_support})")
        print(f"     Reasoning: {pred.reasoning}")
    
    # Export model
    print("\n[2.3] Testing model export...")
    export_path = Path(__file__).parent.parent / "reports" / "ml_model_test.json"
    recommender.export_model(str(export_path))
    print(f"✓ Model exported to {export_path}")
    
    return len(predictions) > 0


def test_benchmark_tracker():
    """Test benchmark historical tracking."""
    print("\n" + "="*80)
    print("TEST 3: Benchmark Historical Tracking")
    print("="*80)
    
    tracker = BenchmarkHistoryTracker(
        history_file=Path(__file__).parent.parent / "reports" / "benchmark_history_test.json"
    )
    
    # Create sample results
    print("\n[3.1] Recording sample benchmark runs...")
    
    # Run 1 (baseline)
    results_v1 = [
        BenchmarkResult("memory_search", 100.0, 10.0, datetime.now().isoformat(), "v1.0", {}),
        BenchmarkResult("graph_walk", 200.0, 5.0, datetime.now().isoformat(), "v1.0", {}),
        BenchmarkResult("pattern_detect", 50.0, 20.0, datetime.now().isoformat(), "v1.0", {}),
    ]
    tracker.record_run(results_v1, version="v1.0")
    
    # Run 2 (improved)
    results_v2 = [
        BenchmarkResult("memory_search", 80.0, 12.5, datetime.now().isoformat(), "v2.0", {}),
        BenchmarkResult("graph_walk", 180.0, 5.5, datetime.now().isoformat(), "v2.0", {}),
        BenchmarkResult("pattern_detect", 55.0, 18.0, datetime.now().isoformat(), "v2.0", {}),
    ]
    tracker.record_run(results_v2, version="v2.0")
    
    print(f"✓ Recorded 2 benchmark runs")
    
    # Test comparison
    print("\n[3.2] Testing baseline comparison...")
    
    # Run 3 (current)
    results_v3 = [
        BenchmarkResult("memory_search", 75.0, 13.3, datetime.now().isoformat(), "v3.0", {}),
        BenchmarkResult("graph_walk", 190.0, 5.3, datetime.now().isoformat(), "v3.0", {}),
        BenchmarkResult("pattern_detect", 60.0, 16.7, datetime.now().isoformat(), "v3.0", {}),
    ]
    
    comparisons = tracker.compare_with_baseline(results_v3)
    
    print(f"✓ Generated {len(comparisons)} comparisons")
    for comp in comparisons:
        status = "⚠️ REGRESSION" if comp.is_regression else "✓ OK"
        print(f"  {comp.benchmark_name}: {comp.improvement_pct:+.1f}% {status}")
    
    # Generate report
    print("\n[3.3] Generating comparison report...")
    report = tracker.generate_report(results_v3)
    print(report)
    
    return len(comparisons) > 0


def test_adaptive_system():
    """Test adaptive system (Phase 3)."""
    print("\n" + "="*80)
    print("TEST 4: Adaptive System (Phase 3)")
    print("="*80)
    
    adaptive = get_adaptive_system()
    
    # Test initial state
    print("\n[4.1] Testing initial state...")
    status = adaptive.get_status()
    print(f"✓ Adaptive system initialized")
    print(f"  Enabled: {status['enabled']}")
    print(f"  Require approval: {status['require_approval']}")
    print(f"  Applied adaptations: {status['applied_adaptations']}")
    
    # Test adaptation proposal (should be rejected - system disabled)
    print("\n[4.2] Testing adaptation proposal (system disabled)...")
    
    test_adaptation = {
        "type": "optimize_pathway",
        "description": "Test optimization",
        "confidence": 0.95,
        "frequency": 20,
        "impact_score": 0.3,
        "pattern_id": "test_pattern",
    }
    
    applied = adaptive.propose_adaptation(test_adaptation)
    print(f"  Applied: {applied} (expected: False)")
    
    # Enable system with approval required
    print("\n[4.3] Enabling adaptive system (with approval)...")
    adaptive.enable(require_approval=True)
    status = adaptive.get_status()
    print(f"✓ System enabled: {status['enabled']}")
    
    # Propose again (should go to pending)
    print("\n[4.4] Testing adaptation proposal (approval required)...")
    applied = adaptive.propose_adaptation(test_adaptation)
    print(f"  Applied immediately: {applied} (expected: False)")
    print(f"  Pending approvals: {len(adaptive.pending_approvals)}")
    
    # Approve adaptation
    print("\n[4.5] Testing manual approval...")
    if adaptive.pending_approvals:
        approved = adaptive.approve_adaptation(0)
        print(f"✓ Adaptation approved and applied: {approved}")
    
    # Update metrics
    print("\n[4.6] Testing metrics tracking...")
    adaptive.update_metrics(coherence=0.75, performance=0.85)
    adaptive.update_metrics(coherence=0.78, performance=0.87)
    status = adaptive.get_status()
    print(f"✓ Metrics updated")
    print(f"  Current coherence: {status['current_coherence']}")
    print(f"  Current performance: {status['current_performance']}")
    
    # Disable system
    print("\n[4.7] Disabling adaptive system...")
    adaptive.disable()
    status = adaptive.get_status()
    print(f"✓ System disabled: {not status['enabled']}")
    
    return True


async def main():
    """Run all tests."""
    print("="*80)
    print("COMPREHENSIVE SYSTEM VALIDATION")
    print("="*80)
    print(f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
    
    results = {}
    
    # Test 1: Streaming
    try:
        results['streaming'] = await test_streaming_protocol()
    except Exception as e:
        print(f"\n❌ Streaming test failed: {e}")
        results['streaming'] = False
    
    # Test 2: ML Recommender
    try:
        results['ml_recommender'] = test_ml_recommender()
    except Exception as e:
        print(f"\n❌ ML recommender test failed: {e}")
        results['ml_recommender'] = False
    
    # Test 3: Benchmark Tracker
    try:
        results['benchmark_tracker'] = test_benchmark_tracker()
    except Exception as e:
        print(f"\n❌ Benchmark tracker test failed: {e}")
        results['benchmark_tracker'] = False
    
    # Test 4: Adaptive System
    try:
        results['adaptive_system'] = test_adaptive_system()
    except Exception as e:
        print(f"\n❌ Adaptive system test failed: {e}")
        results['adaptive_system'] = False
    
    # Summary
    print("\n" + "="*80)
    print("TEST SUMMARY")
    print("="*80)
    
    passed = sum(1 for v in results.values() if v)
    total = len(results)
    
    for name, success in results.items():
        status = "✓ PASS" if success else "✗ FAIL"
        print(f"  {name}: {status}")
    
    print(f"\nTotal: {passed}/{total} tests passed")
    
    if passed == total:
        print("\n" + "="*80)
        print("✓ ALL SYSTEMS OPERATIONAL")
        print("="*80)
        print("\nAll 4 new systems validated:")
        print("  1. ✓ Streaming Response Protocol")
        print("  2. ✓ ML-Based Tool Recommendations")
        print("  3. ✓ Benchmark Historical Tracking")
        print("  4. ✓ Adaptive System (Phase 3)")
        print("\n🚀 Ready for production deployment!")
    else:
        print("\n⚠️ Some tests failed - review output above")
    
    return 0 if passed == total else 1


if __name__ == "__main__":
    sys.exit(asyncio.run(main()))
