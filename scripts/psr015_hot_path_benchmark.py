#!/usr/bin/env python3
"""PSR-015 Hot Path Benchmark — Python vs Rust Speedup Verification

Demonstrates 10-100× speedup on migrated hot paths:
1. Galactic batch scoring (100 memories)
2. Association mining (50 text pairs)
3. 5D Spatial index queries (1K points)
4. Holographic encoding (batch 100)
5. Keyword extraction (100 texts)

Usage:
    python scripts/psr015_hot_path_benchmark.py
"""
import time
import json
import statistics
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

# Python fallbacks
from whitemagic.optimization._rust_fallbacks import (  # noqa: E402
    _galactic_batch_score_python,
    _association_mine_python,
    PythonSpatialIndex5D,
)  # type: ignore[import-not-found]

# Rust accelerators
try:
    import whitemagic_rs as _rs
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False


def bench(label: str, py_fn, rs_fn, iterations: int = 100):
    """Benchmark Python vs Rust and report speedup."""
    print(f"\n  {label}")
    print(f"  {'─' * 60}")
    
    # Warmup
    for _ in range(5):
        py_fn()
        if RUST_AVAILABLE:
            rs_fn()
    
    # Python timing
    py_times = []
    for _ in range(iterations):
        start = time.perf_counter_ns()
        py_fn()
        py_times.append((time.perf_counter_ns() - start) / 1_000_000)  # ms
    
    py_median = statistics.median(py_times)
    py_p95 = sorted(py_times)[int(len(py_times) * 0.95)]
    
    print(f"  Python:  median={py_median:>7.3f}ms  p95={py_p95:>7.3f}ms  ({iterations} iters)")
    
    # Rust timing
    if RUST_AVAILABLE:
        rs_times = []
        for _ in range(iterations):
            start = time.perf_counter_ns()
            rs_fn()
            rs_times.append((time.perf_counter_ns() - start) / 1_000_000)  # ms
        
        rs_median = statistics.median(rs_times)
        rs_p95 = sorted(rs_times)[int(len(rs_times) * 0.95)]
        speedup = py_median / rs_median if rs_median > 0 else float('inf')
        
        print(f"  Rust:    median={rs_median:>7.3f}ms  p95={rs_p95:>7.3f}ms  ({iterations} iters)")
        print(f"  Speedup: {speedup:>6.1f}× {'✅' if speedup >= 10 else '⚠️'}")
        return speedup
    else:
        print("  Rust:    NOT AVAILABLE")
        return 0.0


def galactic_benchmark():
    """Benchmark galactic batch scoring: 100 memories."""
    memories = [
        {
            "id": f"m{i}",
            "importance": 0.5 + (i % 10) * 0.05,
            "neuro_score": 0.3 + (i % 7) * 0.1,
            "emotional_valence": (i % 5 - 2) * 0.2,
            "recall_count": i * 2,
            "is_protected": i % 20 == 0,
            "is_core_identity": i % 50 == 0,
            "is_sacred": False,
            "is_pinned": i % 100 == 0,
            "memory_type_weight": 0.5,
            "richness": 0.4 + (i % 6) * 0.1,
            "activity": min(1.0, i / 100),
            "recency": 0.9 - (i % 10) * 0.08,
            "emotion": abs((i % 5 - 2) * 0.2),
            "protection": 1.0 if i % 20 == 0 else 0.0,
        }
        for i in range(100)
    ]
    
    memories_json = json.dumps(memories)
    
    def py_fn():
        return _galactic_batch_score_python(memories, quick=True)
    
    def rs_fn():
        result = _rs.galactic_batch_score_quick(memories_json)
        return json.loads(result)
    
    return bench("🌌 Galactic Batch Score (100 memories, quick mode)", py_fn, rs_fn, 200)


def association_benchmark():
    """Benchmark association mining: 50 text pairs."""
    texts = [
        (f"m{i}", f"Rust programming memory optimization performance cache {i}")
        for i in range(50)
    ]
    
    texts_json = json.dumps(texts)
    
    def py_fn():
        return _association_mine_python(texts, max_keywords=10, min_score=0.1, max_results=100)
    
    def rs_fn():
        result = _rs.association_mine_fast(texts_json, 10, 0.1, 100)
        return json.loads(result)
    
    return bench("🔗 Association Mining (50 texts, 10 keywords)", py_fn, rs_fn, 100)


def spatial_index_benchmark():
    """Benchmark 5D spatial index: query nearest from 1K points."""
    # Build index with 1000 points
    points = [(f"p{i}", [float(i % 10) / 10, float(i % 10) / 10, 
                         float(i % 10) / 10, float(i % 10) / 10, 
                         float(i % 10) / 10]) for i in range(1000)]
    
    py_index = PythonSpatialIndex5D()
    for mid, vec in points:
        py_index.add(mid, vec)
    
    # Rust index
    if RUST_AVAILABLE:
        rs_index = _rs.SpatialIndex5D()
        rs_index.add_batch([(mid, vec) for mid, vec in points])
    
    query = [0.5, 0.5, 0.5, 0.5, 0.5]
    
    def py_fn():
        return py_index.query_nearest(query, 10)
    
    def rs_fn():
        return rs_index.query_nearest(query, 10)
    
    return bench("📍 5D Spatial Index (1K points, nearest 10)", py_fn, rs_fn, 500)


def keyword_benchmark():
    """Benchmark keyword extraction: 100 texts."""
    texts = [
        f"Rust programming language memory safety performance optimization {i}"
        for i in range(100)
    ]
    
    def py_fn():
        # Simple Python keyword extraction (basic)
        results = []
        for text in texts:
            words = text.lower().split()
            keywords = {w for w in words if len(w) > 3 and w not in 
                       {"the", "and", "with", "from", "into", "than", "that"}}
            results.append(keywords)
        return results
    
    def rs_fn():
        return _rs.keyword_extract_batch(texts, 10)
    
    return bench("🔑 Keyword Extraction (100 texts, 10 keywords)", py_fn, rs_fn, 200)


def holographic_benchmark():
    """Benchmark holographic encoding: batch 100 memories."""
    memories = [
        {
            "id": f"m{i}",
            "content": f"Memory content about optimization and performance {i}",
            "importance": 0.5 + (i % 10) * 0.05,
            "access_count": i * 2,
            "age_days": i % 30,
            "galactic_distance": 0.3 + (i % 7) * 0.1,
            "garden": ["wood", "fire", "earth", "metal", "water"][i % 5],
            "tags": ["rust", "performance", "optimization"],
        }
        for i in range(100)
    ]
    
    memories_json = json.dumps([{
        "id": m["id"],
        "content": m["content"],
        "importance": m["importance"],
        "access_count": m["access_count"],
        "age_days": m["age_days"],
        "galactic_distance": m["galactic_distance"],
        "garden": m["garden"],
        "tags": m["tags"],
    } for m in memories])
    
    def py_fn():
        # Simple Python fallback (just returns coordinates)
        return [{"x": 0.0, "y": 0.0, "z": 0.0, "w": 0.5, "v": 0.5} for _ in memories]
    
    def rs_fn():
        result = _rs.holographic_encode_batch(memories_json)
        return json.loads(result)
    
    return bench("✨ Holographic Encode (batch 100)", py_fn, rs_fn, 100)


def main():
    print("=" * 70)
    print("PSR-015 Hot Path Benchmark — Python vs Rust Speedup")
    print("=" * 70)
    print(f"Rust Available: {RUST_AVAILABLE}")
    print(f"Timestamp: {time.strftime('%Y-%m-%d %H:%M:%S')}")
    print("=" * 70)
    
    if not RUST_AVAILABLE:
        print("\n⚠️  Rust extension not available — cannot measure speedup")
        print("   Build with: cd whitemagic-rust && maturin develop")
        sys.exit(1)
    
    speedups = []
    
    try:
        speedups.append(("galactic", galactic_benchmark()))
    except Exception as e:
        print(f"\n❌ Galactic benchmark failed: {e}")
    
    try:
        speedups.append(("association", association_benchmark()))
    except Exception as e:
        print(f"\n❌ Association benchmark failed: {e}")
    
    try:
        speedups.append(("spatial", spatial_index_benchmark()))
    except Exception as e:
        print(f"\n❌ Spatial index benchmark failed: {e}")
    
    try:
        speedups.append(("keyword", keyword_benchmark()))
    except Exception as e:
        print(f"\n❌ Keyword benchmark failed: {e}")
    
    try:
        speedups.append(("holographic", holographic_benchmark()))
    except Exception as e:
        print(f"\n❌ Holographic benchmark failed: {e}")
    
    # Summary
    print("\n" + "=" * 70)
    print("SUMMARY")
    print("=" * 70)
    
    if speedups:
        avg_speedup = sum(s for _, s in speedups) / len(speedups)
        tenx_count = sum(1 for _, s in speedups if s >= 10)
        hundredx_count = sum(1 for _, s in speedups if s >= 100)
        
        print(f"Benchmarks completed: {len(speedups)}/5")
        print(f"Average speedup: {avg_speedup:.1f}×")
        print(f"≥10× speedup: {tenx_count}/5")
        print(f"≥100× speedup: {hundredx_count}/5")
        
        if tenx_count >= 3:
            print("\n✅ PSR-015 VC: Benchmarks show 10-100× speedup — ACHIEVED")
        else:
            print("\n⚠️  PSR-015 VC: Need more optimizations for 10× target")
    
    print("=" * 70)


if __name__ == "__main__":
    main()
