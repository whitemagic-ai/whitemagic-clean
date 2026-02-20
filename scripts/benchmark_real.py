#!/usr/bin/env python3
"""Real benchmark harness — PSR-022.

Measures actual Python vs Rust timing for each accelerated function.
No simulated numbers. Every result is a real wall-clock measurement.

Usage:
    python3 scripts/benchmark_real.py
    python3 scripts/benchmark_real.py --functions vector_search,bm25
    python3 scripts/benchmark_real.py --save
"""
import argparse
import json
import sys
import time
from datetime import datetime
from pathlib import Path
from typing import Any

ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(ROOT))

RESULTS: dict[str, dict[str, Any]] = {}


def bench(label: str, fn, n: int = 1000) -> float:
    """Run fn() n times, return median ms."""
    times = []
    for _ in range(n):
        t0 = time.perf_counter()
        fn()
        times.append(time.perf_counter() - t0)
    times.sort()
    return times[len(times) // 2] * 1000  # median ms


def bench_vector_search() -> dict:
    import random
    import math

    DIM = 128
    N = 500
    vecs = [[random.gauss(0, 1) for _ in range(DIM)] for _ in range(N)]
    query = [random.gauss(0, 1) for _ in range(DIM)]

    def python_cosine_search():
        def dot(a, b): return sum(x*y for x, y in zip(a, b))
        def norm(a): return math.sqrt(sum(x*x for x in a))
        qn = norm(query)
        scores = []
        for i, v in enumerate(vecs):
            vn = norm(v)
            if vn > 0 and qn > 0:
                scores.append((dot(query, v) / (qn * vn), i))
        scores.sort(reverse=True)
        return scores[:10]

    py_ms = bench("python_cosine", python_cosine_search, n=200)

    rust_ms = None
    rust_speedup = None
    try:
        import whitemagic_rs
        if hasattr(whitemagic_rs, "VectorIndex"):
            idx = whitemagic_rs.VectorIndex(DIM, "cosine")
            for i, v in enumerate(vecs):
                idx.add(str(i), v)
            def rust_search():
                return idx.search(query, 10)
            rust_ms = bench("rust_cosine", rust_search, n=200)
            rust_speedup = py_ms / rust_ms if rust_ms > 0 else None
    except Exception as e:
        rust_ms = None
        rust_speedup = None

    return {
        "python_ms": round(py_ms, 4),
        "rust_ms": round(rust_ms, 4) if rust_ms else None,
        "speedup": round(rust_speedup, 2) if rust_speedup else "N/A (Rust not wired)",
        "n_vectors": N,
        "dimensions": DIM,
        "status": "REAL" if rust_ms else "PYTHON_ONLY",
    }


def bench_bm25() -> dict:
    import math
    import re

    docs = [
        "memory consolidation holographic spatial index",
        "rust rayon parallel vector search cosine similarity",
        "sqlite wal mode connection pool performance",
        "clone army deployment zodiac strategy selection",
        "association mining graph walk pattern detection",
    ] * 100  # 500 docs
    query = "memory vector search performance"

    def tokenize(s): return re.findall(r'\w+', s.lower())

    def python_bm25():
        k1, b = 1.5, 0.75
        qtoks = tokenize(query)
        tok_docs = [tokenize(d) for d in docs]
        avgdl = sum(len(d) for d in tok_docs) / len(tok_docs)
        N = len(tok_docs)
        scores = []
        for doc in tok_docs:
            dl = len(doc)
            score = 0.0
            for qt in qtoks:
                df = sum(1 for d in tok_docs if qt in d)
                idf = math.log((N - df + 0.5) / (df + 0.5) + 1)
                tf = doc.count(qt)
                score += idf * (tf * (k1 + 1)) / (tf + k1 * (1 - b + b * dl / avgdl))
            scores.append(score)
        return sorted(range(len(scores)), key=lambda i: -scores[i])[:10]

    py_ms = bench("python_bm25", python_bm25, n=100)

    rust_ms = None
    rust_speedup = None
    try:
        import whitemagic_rs
        if hasattr(whitemagic_rs, "BM25Index"):
            idx = whitemagic_rs.BM25Index()
            for i, d in enumerate(docs):
                idx.add_document(str(i), d)
            def rust_bm25():
                return idx.search(query, 10)
            rust_ms = bench("rust_bm25", rust_bm25, n=100)
            rust_speedup = py_ms / rust_ms if rust_ms > 0 else None
    except Exception as e:
        rust_ms = None

    return {
        "python_ms": round(py_ms, 4),
        "rust_ms": round(rust_ms, 4) if rust_ms else None,
        "speedup": round(rust_speedup, 2) if rust_speedup else "N/A (Rust not wired)",
        "n_docs": len(docs),
        "status": "REAL" if rust_ms else "PYTHON_ONLY",
    }


def bench_sha256() -> dict:
    import hashlib

    data = "memory content for hashing " * 50

    def python_sha256():
        return hashlib.sha256(data.encode()).hexdigest()

    py_ms = bench("python_sha256", python_sha256, n=5000)

    return {
        "python_ms": round(py_ms, 6),
        "rust_ms": None,
        "speedup": "N/A (stdlib, already fast)",
        "status": "PYTHON_ONLY",
    }


def bench_json_serialize() -> dict:
    import json as _json

    record = {
        "id": "abc123def456",
        "content": "test memory content " * 20,
        "tags": ["memory", "test", "benchmark"],
        "importance": 0.75,
        "metadata": {"key": "value", "count": 42},
    }

    def python_json():
        return _json.dumps(record)

    py_ms = bench("python_json", python_json, n=5000)

    rust_ms = None
    try:
        import whitemagic_rs
        if hasattr(whitemagic_rs, "fast_json_dumps"):
            def rust_json():
                return whitemagic_rs.fast_json_dumps(record)
            rust_ms = bench("rust_json", rust_json, n=5000)
    except Exception:
        pass

    speedup = round(py_ms / rust_ms, 2) if rust_ms else "N/A (Rust not wired)"
    return {
        "python_ms": round(py_ms, 6),
        "rust_ms": round(rust_ms, 6) if rust_ms else None,
        "speedup": speedup,
        "status": "REAL" if rust_ms else "PYTHON_ONLY",
    }


BENCHMARKS = {
    "vector_search": bench_vector_search,
    "bm25": bench_bm25,
    "sha256": bench_sha256,
    "json_serialize": bench_json_serialize,
}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--functions", default="", help="Comma-separated list of benchmarks to run")
    parser.add_argument("--save", action="store_true", help="Save results to reports/")
    args = parser.parse_args()

    selected = [f.strip() for f in args.functions.split(",") if f.strip()] if args.functions else list(BENCHMARKS.keys())

    print("╔══════════════════════════════════════════════════════════════╗")
    print("║          REAL BENCHMARK HARNESS — PSR-022                    ║")
    print("╚══════════════════════════════════════════════════════════════╝")
    print()

    # Check Rust availability
    try:
        import whitemagic_rs
        print(f"  ✅ whitemagic_rs available: v{getattr(whitemagic_rs, '__version__', 'unknown')}")
    except ImportError:
        print("  ⚠️  whitemagic_rs NOT available — run: cd whitemagic-rust && maturin develop --release")
        print("     Python-only benchmarks will still run.")
    print()

    results = {}
    for name in selected:
        if name not in BENCHMARKS:
            print(f"  Unknown benchmark: {name}")
            continue
        print(f"  Running {name}...", end=" ", flush=True)
        try:
            r = BENCHMARKS[name]()
            results[name] = r
            speedup = r.get("speedup", "N/A")
            py_ms = r.get("python_ms", 0)
            rust_ms = r.get("rust_ms")
            if rust_ms:
                print(f"Python={py_ms:.4f}ms  Rust={rust_ms:.4f}ms  Speedup={speedup}×")
            else:
                print(f"Python={py_ms:.4f}ms  [{r.get('status', 'UNKNOWN')}]")
        except Exception as e:
            print(f"ERROR: {e}")
            results[name] = {"error": str(e)}

    print()
    print("══════════════════════════════════════════════════════════════")
    real_count = sum(1 for r in results.values() if r.get("status") == "REAL")
    print(f"  {real_count}/{len(results)} benchmarks have real Rust measurements")
    if real_count == 0:
        print("  → Run 'cd whitemagic-rust && maturin develop --release' to wire Rust")
    print("══════════════════════════════════════════════════════════════")

    if args.save:
        ts = datetime.now().strftime("%Y%m%d_%H%M%S")
        out = ROOT / "reports" / f"benchmark_real_{ts}.json"
        out.parent.mkdir(exist_ok=True)
        out.write_text(json.dumps({"timestamp": ts, "results": results}, indent=2))
        print(f"\n  📄 Saved to {out}")

    return results


if __name__ == "__main__":
    main()
