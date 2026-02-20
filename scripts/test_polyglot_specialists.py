#!/usr/bin/env python3
"""Test PolyglotSpecialists and Multi-Language Pipelines"""

import sys
import time
from pathlib import Path

# Add project to path
sys.path.insert(0, str(Path(__file__).parent.parent))

def test_specialists():
    """Test all 8 language specialists"""
    print("\n🎓 TESTING POLYGLOT SPECIALISTS")
    print("=" * 70)
    
    from whitemagic.optimization.polyglot_specialists import PolyglotSpecialists
    
    specialists = PolyglotSpecialists()
    
    # Test 1: Pattern Matcher (Rust)
    print("\n1️⃣  Pattern Matcher (Rust specialist)...")
    result = specialists.extract_patterns("The quick brown fox jumps over the lazy dog", limit=10)
    print(f"   Language: {result.language}")
    print(f"   Patterns found: {len(result.result)}")
    print(f"   Time: {result.execution_time_ms:.2f}ms")
    print(f"   Fallback: {result.fallback_used}")
    
    # Test 2: SIMD Processor (Zig)
    print("\n2️⃣  SIMD Processor (Zig specialist)...")
    vectors = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]]
    result = specialists.distance_matrix(vectors)
    print(f"   Language: {result.language}")
    print(f"   Time: {result.execution_time_ms:.2f}ms")
    print(f"   Fallback: {result.fallback_used}")
    
    # Test 3: Tensor Processor (Mojo)
    print("\n3️⃣  Tensor Processor (Mojo specialist)...")
    memories = [{"id": "test1", "content": "test", "title": "Test"}]
    result = specialists.batch_encode(memories, int(time.time()))
    print(f"   Language: {result.language}")
    print(f"   Encoded: {len(result.result)} memories")
    print(f"   Time: {result.execution_time_ms:.2f}ms")
    print(f"   Fallback: {result.fallback_used}")
    
    # Test 4: Rule Evaluator (Haskell)
    print("\n4️⃣  Rule Evaluator (Haskell specialist)...")
    result = specialists.evaluate_rules("test_action", {"context": "test"})
    print(f"   Language: {result.language}")
    print(f"   Decision: {result.result.get('decision', 'N/A')}")
    print(f"   Time: {result.execution_time_ms:.2f}ms")
    print(f"   Fallback: {result.fallback_used}")
    
    # Test 5-8: Quick tests
    print("\n5️⃣  Concurrency Manager (Elixir specialist)...")
    result = specialists.parallel_tasks([{"id": "task1"}])
    print(f"   Language: {result.language}, Time: {result.execution_time_ms:.2f}ms")
    
    print("\n6️⃣  Network Manager (Go specialist)...")
    result = specialists.mesh_discovery()
    print(f"   Language: {result.language}, Time: {result.execution_time_ms:.2f}ms")
    
    print("\n7️⃣  Statistical Analyzer (Julia specialist)...")
    result = specialists.statistical_analysis([1.0, 2.0, 3.0, 4.0, 5.0])
    print(f"   Language: {result.language}, Time: {result.execution_time_ms:.2f}ms")
    
    print("\n8️⃣  Orchestrator (Python specialist)...")
    result = specialists.orchestrate({"id": "workflow1"})
    print(f"   Language: {result.language}, Time: {result.execution_time_ms:.2f}ms")
    
    # Get stats
    stats = specialists.get_stats()
    print("\n📊 SPECIALIST STATS")
    print("=" * 70)
    print(f"Total calls: {stats['total_calls']}")
    print(f"Native calls: {stats['native_calls']}")
    print(f"Native usage: {stats['native_usage_pct']:.1f}%")
    print(f"By language: {stats['by_language']}")
    
    return stats

def test_pipelines():
    """Test multi-language pipelines"""
    print("\n\n🔗 TESTING MULTI-LANGUAGE PIPELINES")
    print("=" * 70)
    
    from whitemagic.optimization.polyglot_pipelines import PolyglotPipeline
    
    pipeline = PolyglotPipeline()
    
    # Pipeline 1: Memory Analysis
    print("\n1️⃣  Memory Analysis Pipeline (Rust→Zig→Julia)...")
    result = pipeline.memory_analysis_pipeline("mem1", "This is test content for analysis")
    print(f"   Stages: {len(result['stages'])}")
    print(f"   Languages used: {result['languages_used']}")
    print(f"   Total time: {result['total_time_ms']:.2f}ms")
    for stage in result['stages']:
        print(f"      Stage {stage['stage']}: {stage['language']} ({stage['time_ms']:.2f}ms)")
    
    # Pipeline 2: Batch Processing
    print("\n2️⃣  Batch Processing Pipeline (Mojo→Haskell)...")
    memories = [{"id": f"mem{i}", "content": f"test{i}"} for i in range(5)]
    result = pipeline.batch_processing_pipeline(memories)
    print(f"   Stages: {len(result['stages'])}")
    print(f"   Languages used: {result['languages_used']}")
    print(f"   Total time: {result['total_time_ms']:.2f}ms")
    
    # Pipeline 3: Concurrent Search
    print("\n3️⃣  Concurrent Search Pipeline (Rust→Julia)...")
    corpus = [("doc1", "test content"), ("doc2", "more content")]
    result = pipeline.concurrent_search_pipeline("test", corpus)
    print(f"   Stages: {len(result['stages'])}")
    print(f"   Languages used: {result['languages_used']}")
    print(f"   Total time: {result['total_time_ms']:.2f}ms")
    
    return True

if __name__ == "__main__":
    start = time.time()
    
    print("\n" + "=" * 70)
    print("🌐 POLYGLOT SPECIALISTS & PIPELINES - COMPREHENSIVE TEST")
    print("=" * 70)
    
    specialist_stats = test_specialists()
    pipeline_success = test_pipelines()
    
    total_time = time.time() - start
    
    print("\n\n" + "=" * 70)
    print("✅ TEST SUMMARY")
    print("=" * 70)
    print(f"Total execution time: {total_time:.2f}s")
    print(f"Specialists tested: 8/8")
    print(f"Pipelines tested: 3/3")
    print(f"Native usage achieved: {specialist_stats['native_usage_pct']:.1f}%")
    print("\n🎉 ALL TESTS COMPLETE!")
