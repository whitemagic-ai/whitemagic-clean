#!/usr/bin/env python3
"""Benchmark PSR implementations vs Python baselines."""

import sys
import time
from pathlib import Path

# Add whitemagic to path
sys.path.insert(0, str(Path(__file__).parent.parent / "whitemagic"))

def benchmark_cosine_similarity():
    """Benchmark cosine similarity: Rust vs Python."""
    print("=" * 60)
    print("COSINE SIMILARITY BENCHMARK (384-dim vectors)")
    print("=" * 60)

    query = [float(i) for i in range(384)]
    doc = [float(i) for i in range(384)]
    iterations = 10000

    # Python baseline
    def cosine_python(a, b):
        dot = sum(x * y for x, y in zip(a, b))
        norm_a = sum(x * x for x in a) ** 0.5
        norm_b = sum(x * x for x in b) ** 0.5
        if norm_a == 0 or norm_b == 0:
            return 0.0
        return dot / (norm_a * norm_b)

    start = time.perf_counter()
    for _ in range(iterations):
        cosine_python(query, doc)
    py_time = time.perf_counter() - start
    py_rate = iterations / py_time

    print(f"Python: {py_time:.3f}s ({py_rate:.0f} calls/sec)")

    # Rust implementation
    try:
        import whitemagic_rs
        if hasattr(whitemagic_rs, 'PySearchEngine'):
            engine = whitemagic_rs.PySearchEngine()

            start = time.perf_counter()
            for _ in range(iterations):
                engine.cosine_similarity(query, doc)
            rust_time = time.perf_counter() - start
            rust_rate = iterations / rust_time

            speedup = py_time / rust_time
            print(f"Rust:   {rust_time:.3f}s ({rust_rate:.0f} calls/sec)")
            print(f"Speedup: {speedup:.1f}x")

            return speedup
        else:
            print("Rust: Not available (PySearchEngine not found)")
            return None
    except ImportError:
        print("Rust: Not available (whitemagic_rs not installed)")
        return None

def benchmark_galactic_distance():
    """Benchmark galactic distance: Zig vs Python."""
    print("\n" + "=" * 60)
    print("GALACTIC DISTANCE BENCHMARK")
    print("=" * 60)

    iterations = 100000

    # Python baseline
    def compute_distance_python(access, neuro, temporal, salience, connection):
        weights = [0.3, 0.25, 0.2, 0.15, 0.1]
        scores = [access, neuro, temporal, salience, connection]
        weighted_sum = sum(s * w for s, w in zip(scores, weights))
        distance = 1.0 - weighted_sum
        return max(0.0, min(1.0, distance))

    start = time.perf_counter()
    for _ in range(iterations):
        compute_distance_python(0.9, 0.8, 0.7, 0.6, 0.5)
    py_time = time.perf_counter() - start
    py_rate = iterations / py_time

    print(f"Python: {py_time:.3f}s ({py_rate:.0f} calls/sec)")

    # Zig implementation
    try:
        from core.memory.galactic_map_fast import (
            compute_distance_fast,
            is_zig_available,
        )

        if is_zig_available():
            start = time.perf_counter()
            for _ in range(iterations):
                compute_distance_fast(0.9, 0.8, 0.7, 0.6, 0.5)
            zig_time = time.perf_counter() - start
            zig_rate = iterations / zig_time

            speedup = py_time / zig_time
            print(f"Zig:    {zig_time:.3f}s ({zig_rate:.0f} calls/sec)")
            print(f"Speedup: {speedup:.1f}x")

            return speedup
        else:
            print("Zig: Not available (library not loaded)")
            return None
    except ImportError as e:
        print(f"Zig: Not available ({e})")
        return None

def benchmark_bm25():
    """Benchmark BM25 scoring: Rust vs Python."""
    print("\n" + "=" * 60)
    print("BM25 SCORING BENCHMARK")
    print("=" * 60)

    iterations = 10000

    # Python baseline
    def bm25_python(term_freq, doc_length, avg_doc_length, idf, k1=1.5, b=0.75):
        norm_length = 1.0 - b + b * (doc_length / avg_doc_length)
        numerator = term_freq * (k1 + 1.0)
        denominator = term_freq + k1 * norm_length
        return idf * (numerator / denominator)

    start = time.perf_counter()
    for _ in range(iterations):
        bm25_python(3.0, 100.0, 150.0, 2.5)
    py_time = time.perf_counter() - start
    py_rate = iterations / py_time

    print(f"Python: {py_time:.3f}s ({py_rate:.0f} calls/sec)")

    # Rust implementation
    try:
        import whitemagic_rs
        if hasattr(whitemagic_rs, 'PyBM25Scorer'):
            scorer = whitemagic_rs.PyBM25Scorer()

            start = time.perf_counter()
            for _ in range(iterations):
                scorer.score_term(3.0, 100.0, 2.5)
            rust_time = time.perf_counter() - start
            rust_rate = iterations / rust_time

            speedup = py_time / rust_time
            print(f"Rust:   {rust_time:.3f}s ({rust_rate:.0f} calls/sec)")
            print(f"Speedup: {speedup:.1f}x")

            return speedup
        else:
            print("Rust: Not available (PyBM25Scorer not found)")
            return None
    except ImportError:
        print("Rust: Not available (whitemagic_rs not installed)")
        return None

def main():
    """Run all benchmarks."""
    print("\n" + "=" * 60)
    print("PSR IMPLEMENTATION BENCHMARKS")
    print("=" * 60)
    print()

    results = {}

    # Run benchmarks
    results['cosine'] = benchmark_cosine_similarity()
    results['galactic'] = benchmark_galactic_distance()
    results['bm25'] = benchmark_bm25()

    # Summary
    print("\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)

    for name, speedup in results.items():
        if speedup:
            status = "✅" if speedup >= 10 else "⚠️"
            print(f"{status} {name}: {speedup:.1f}x speedup")
        else:
            print(f"❌ {name}: Not available")

    print()

if __name__ == "__main__":
    main()
