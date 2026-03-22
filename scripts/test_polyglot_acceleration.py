#!/usr/bin/env python3
"""Test and benchmark polyglot acceleration infrastructure.

This script verifies that the unified PolyglotAccelerator correctly routes
operations to the fastest available backend and measures performance gains.
"""
import sys
import time
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

import numpy as np

from whitemagic.core.acceleration.polyglot_accelerator import (
    get_acceleration_stats,
    get_accelerator,
)


def test_cosine_similarity():
    """Test single vector cosine similarity."""
    print("\n🧪 Testing Cosine Similarity...")

    accel = get_accelerator()

    # Generate test vectors
    vec_a = np.random.rand(384).astype(np.float32).tolist()
    vec_b = np.random.rand(384).astype(np.float32).tolist()

    # Warm-up
    _ = accel.cosine_similarity(vec_a, vec_b)

    # Benchmark
    iterations = 1000
    start = time.time()
    for _ in range(iterations):
        result = accel.cosine_similarity(vec_a, vec_b)
    elapsed = time.time() - start

    print(f"   Result: {result:.6f}")
    print(f"   Time: {elapsed*1000:.2f}ms for {iterations} iterations")
    print(f"   Avg: {elapsed*1000/iterations:.4f}ms per call")

    return result


def test_batch_cosine():
    """Test batch cosine similarity."""
    print("\n🧪 Testing Batch Cosine Similarity...")

    accel = get_accelerator()

    # Generate test data
    query = np.random.rand(384).astype(np.float32).tolist()
    vectors = [np.random.rand(384).astype(np.float32).tolist() for _ in range(100)]

    # Warm-up
    _ = accel.batch_cosine(query, vectors)

    # Benchmark
    iterations = 100
    start = time.time()
    for _ in range(iterations):
        results = accel.batch_cosine(query, vectors)
    elapsed = time.time() - start

    print(f"   Vectors: {len(vectors)}")
    print(f"   Results: {len(results)} scores")
    print(f"   Time: {elapsed*1000:.2f}ms for {iterations} iterations")
    print(f"   Avg: {elapsed*1000/iterations:.2f}ms per batch")
    print(f"   Per-vector: {elapsed*1000/(iterations*len(vectors)):.4f}ms")

    return results


def test_pattern_extraction():
    """Test pattern extraction."""
    print("\n🧪 Testing Pattern Extraction...")

    accel = get_accelerator()

    content = """
    The holographic memory system uses 5D spatial indexing to organize memories
    across multiple dimensions including time, importance, and emotional valence.
    Pattern extraction identifies recurring themes and concepts across the memory
    space, enabling the system to learn from past experiences and optimize future
    operations. The polyglot architecture leverages Rust, Zig, and Mojo for
    maximum performance on different types of computational workloads.
    """

    start = time.time()
    patterns = accel.extract_patterns(content, limit=10)
    elapsed = time.time() - start

    print(f"   Patterns found: {len(patterns)}")
    print(f"   Time: {elapsed*1000:.2f}ms")

    if patterns:
        print(f"   Top pattern: {patterns[0].get('pattern', 'N/A')}")

    return patterns


def test_duplicate_detection():
    """Test duplicate detection."""
    print("\n🧪 Testing Duplicate Detection...")

    accel = get_accelerator()

    texts = [
        "This is a test memory about holographic encoding",
        "Another memory about pattern extraction",
        "This is a test memory about holographic encoding",  # Duplicate
        "Memory consolidation and optimization",
        "Pattern extraction and analysis",
    ]

    start = time.time()
    duplicates = accel.find_duplicates(texts, threshold=0.9)
    elapsed = time.time() - start

    print(f"   Texts: {len(texts)}")
    print(f"   Duplicates found: {len(duplicates)}")
    print(f"   Time: {elapsed*1000:.2f}ms")

    if duplicates:
        print(f"   Example: indices {duplicates[0][0]}, {duplicates[0][1]} (score: {duplicates[0][2]:.2f})")

    return duplicates


def test_memory_search():
    """Test memory search."""
    print("\n🧪 Testing Memory Search...")

    accel = get_accelerator()

    memories = [
        ("mem_001", "holographic coordinate system for spatial indexing"),
        ("mem_002", "pattern extraction using rust accelerators"),
        ("mem_003", "memory consolidation and lifecycle management"),
        ("mem_004", "polyglot architecture with rust zig and mojo"),
        ("mem_005", "cognitive episode tracking and strategy recall"),
    ]

    query = "pattern extraction"

    start = time.time()
    results = accel.search_memories(query, memories, threshold=0.3, limit=3)
    elapsed = time.time() - start

    print(f"   Query: '{query}'")
    print(f"   Memories: {len(memories)}")
    print(f"   Results: {len(results)}")
    print(f"   Time: {elapsed*1000:.2f}ms")

    for mid, score in results[:3]:
        print(f"      {mid}: {score:.4f}")

    return results


def benchmark_comparison():
    """Compare Python vs accelerated performance."""
    print("\n📊 Performance Comparison...")

    accel = get_accelerator()

    # Test data
    vec_a = np.random.rand(384).astype(np.float32).tolist()
    vec_b = np.random.rand(384).astype(np.float32).tolist()

    # Python baseline
    iterations = 1000
    start = time.time()
    for _ in range(iterations):
        accel._py_cosine(vec_a, vec_b)
    time_py = time.time() - start

    # Accelerated
    start = time.time()
    for _ in range(iterations):
        accel.cosine_similarity(vec_a, vec_b)
    time_accel = time.time() - start

    speedup = time_py / max(time_accel, 0.001)

    print(f"   Python: {time_py*1000:.2f}ms ({time_py*1000/iterations:.4f}ms/call)")
    print(f"   Accelerated: {time_accel*1000:.2f}ms ({time_accel*1000/iterations:.4f}ms/call)")
    print(f"   Speedup: {speedup:.2f}x")

    return speedup


def main():
    """Run all tests and display results."""
    print("=" * 70)
    print("🚀 Polyglot Acceleration Test Suite")
    print("=" * 70)

    # Get initial stats
    accel = get_accelerator()
    initial_stats = accel.get_stats()

    print("\n📦 Available Backends:")
    for backend, available in initial_stats["backends"].items():
        status = "✓" if available else "✗"
        print(f"   {status} {backend.capitalize()}")

    # Run tests
    try:
        test_cosine_similarity()
        test_batch_cosine()
        test_pattern_extraction()
        test_duplicate_detection()
        test_memory_search()
        speedup = benchmark_comparison()

        # Final stats
        print("\n" + "=" * 70)
        print("📈 Acceleration Statistics")
        print("=" * 70)

        stats = get_acceleration_stats()

        print(f"\n   Total Calls: {stats['calls']['total']}")
        print(f"   Rust: {stats['calls']['rust']}")
        print(f"   Zig: {stats['calls']['zig']}")
        print(f"   Mojo: {stats['calls']['mojo']}")
        print(f"   Python: {stats['calls']['python']}")
        print(f"\n   Native Usage: {stats['native_usage_pct']:.1f}%")
        print(f"   Total Time: {stats['total_time_ms']:.2f}ms")
        print(f"   Avg Time: {stats['avg_time_ms']:.4f}ms")

        # Success criteria
        print("\n" + "=" * 70)
        print("✅ Test Results")
        print("=" * 70)

        success = True

        if stats['native_usage_pct'] > 0:
            print("   ✓ Native acceleration active")
        else:
            print("   ⚠ Using Python fallback only")
            success = False

        if speedup > 1.5:
            print(f"   ✓ Significant speedup achieved ({speedup:.2f}x)")
        elif speedup > 1.0:
            print(f"   ⚠ Modest speedup ({speedup:.2f}x)")
        else:
            print(f"   ✗ No speedup detected ({speedup:.2f}x)")
            success = False

        if success:
            print("\n🎉 All tests passed! Polyglot acceleration is working.")
        else:
            print("\n⚠️  Tests completed but acceleration may not be optimal.")

        return 0 if success else 1

    except Exception as e:
        print(f"\n❌ Test failed: {e}")
        import traceback
        traceback.print_exc()
        return 1


if __name__ == "__main__":
    sys.exit(main())
