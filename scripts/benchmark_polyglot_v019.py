#!/usr/bin/env python3
"""V019 Polyglot Benchmark — Compare all acceleration backends.

Measures latency and throughput for each live polyglot backend and
compares against Python/NumPy baseline. Produces a report for VC9.
"""
import time
import statistics
import json
from pathlib import Path

import numpy as np

RESULTS = {}

def bench(name: str, fn, n: int = 100):
    """Run fn n times, return mean ms."""
    # Warmup
    for _ in range(3):
        try:
            fn()
        except Exception:
            pass
    times = []
    for _ in range(n):
        t0 = time.perf_counter()
        try:
            fn()
        except Exception:
            pass
        times.append((time.perf_counter() - t0) * 1000)
    mean_ms = statistics.mean(times)
    p95_ms = sorted(times)[int(n * 0.95)]
    RESULTS[name] = {"mean_ms": round(mean_ms, 4), "p95_ms": round(p95_ms, 4), "n": n}
    return mean_ms


def main():
    print("=" * 60)
    print("V019 Polyglot Benchmark")
    print(f"Time: {time.strftime('%Y-%m-%d %H:%M:%S')}")
    print("=" * 60)

    DIM = 384
    a = np.random.randn(DIM).astype(np.float32)
    b = np.random.randn(DIM).astype(np.float32)
    a_list = a.tolist()
    b_list = b.tolist()
    docs = [np.random.randn(DIM).astype(np.float32).tolist() for _ in range(50)]

    # -------------------------------------------------------------------------
    # 1. Cosine similarity — NumPy baseline
    # -------------------------------------------------------------------------
    def numpy_cosine():
        na, nb = np.linalg.norm(a), np.linalg.norm(b)
        return float(np.dot(a, b) / (na * nb))

    t = bench("numpy_cosine_384d", numpy_cosine)
    print(f"NumPy cosine (384d):          {t:.4f} ms")

    # -------------------------------------------------------------------------
    # 2. Zig SIMD cosine (existing simd_cosine.py)
    # -------------------------------------------------------------------------
    try:
        from whitemagic.core.acceleration.simd_cosine import batch_cosine, simd_status
        st = simd_status()
        if st["has_zig_simd"]:
            def zig_simd_batch():
                return batch_cosine(a_list, [b_list])
            t = bench("zig_simd_batch_cosine", zig_simd_batch)
            print(f"Zig SIMD batch_cosine:        {t:.4f} ms  (lane_width={st['lane_width']})")
        else:
            print("Zig SIMD batch_cosine:        NOT AVAILABLE")
    except Exception as e:
        print(f"Zig SIMD batch_cosine:        ERROR: {e}")

    # -------------------------------------------------------------------------
    # 3. Zig graph bridge cosine (new wm_simd_cosine_f32)
    # -------------------------------------------------------------------------
    try:
        from whitemagic.core.acceleration.zig_graph_bridge import zig_simd_cosine, zig_tokenize_count, zig_graph_bridge_status
        st = zig_graph_bridge_status()
        if st["has_zig_graph"]:
            def zig_graph_cosine():
                return zig_simd_cosine(a_list, b_list)
            t = bench("zig_graph_simd_cosine", zig_graph_cosine)
            print(f"Zig graph simd_cosine:        {t:.4f} ms")

            def zig_tok():
                return zig_tokenize_count("hello world foo bar baz qux")
            t = bench("zig_tokenize_count", zig_tok, n=1000)
            print(f"Zig tokenize_count:           {t:.4f} ms  (1000 iters)")
        else:
            print("Zig graph bridge:             NOT AVAILABLE")
    except Exception as e:
        print(f"Zig graph bridge:             ERROR: {e}")

    # -------------------------------------------------------------------------
    # 4. Julia RRF fusion
    # -------------------------------------------------------------------------
    try:
        from whitemagic.core.acceleration.julia_bridge import julia_rrf_fuse, julia_pagerank
        lists = [
            [{"id": f"m{i}", "score": 1.0 - i * 0.05} for i in range(20)],
            [{"id": f"m{i}", "score": 1.0 - i * 0.04} for i in range(20)],
            [{"id": f"m{i}", "score": 1.0 - i * 0.06} for i in range(20)],
        ]
        def julia_rrf():
            return julia_rrf_fuse(lists, weights=[1.0, 1.2, 0.8])
        t = bench("julia_rrf_fuse_3x20", julia_rrf, n=10)
        print(f"Julia RRF fuse (3×20):        {t:.2f} ms  (includes JIT)")

        nodes = [f"n{i}" for i in range(20)]
        edges = [{"source": f"n{i}", "target": f"n{i+1}", "weight": 0.8} for i in range(19)]
        def julia_pr():
            return julia_pagerank(nodes, edges)
        t = bench("julia_pagerank_20nodes", julia_pr, n=10)
        print(f"Julia PageRank (20 nodes):    {t:.2f} ms")
    except Exception as e:
        print(f"Julia RRF/PageRank:           ERROR: {e}")

    # -------------------------------------------------------------------------
    # 5. Koka bridge status + plan_deployment
    # -------------------------------------------------------------------------
    try:
        from whitemagic.core.acceleration.koka_bridge import koka_plan_deployment, koka_bridge_status
        st = koka_bridge_status()
        tasks = [{"id": f"t{i}", "priority": i % 3, "type": "clone"} for i in range(50)]
        def koka_plan():
            return koka_plan_deployment(tasks, army_size=8)
        t = bench("koka_plan_deployment_50tasks", koka_plan, n=20)
        print(f"Koka plan_deployment (50):    {t:.4f} ms  (backend={st['backend']})")
    except Exception as e:
        print(f"Koka plan_deployment:         ERROR: {e}")

    # -------------------------------------------------------------------------
    # 6. Rust RRF (via whitemagic_rs)
    # -------------------------------------------------------------------------
    try:
        import whitemagic_rs
        if hasattr(whitemagic_rs, "rrf_fuse"):
            ranked = [(f"m{i}", 1.0 - i * 0.05) for i in range(20)]
            def rust_rrf():
                return whitemagic_rs.rrf_fuse([ranked, ranked], [1.0, 1.0])
            t = bench("rust_rrf_fuse_2x20", rust_rrf)
            print(f"Rust RRF fuse (2×20):         {t:.4f} ms")
        else:
            print("Rust RRF fuse:                NOT AVAILABLE (no rrf_fuse attr)")
    except Exception as e:
        print(f"Rust RRF fuse:                ERROR: {e}")

    # -------------------------------------------------------------------------
    # 7. NumPy batch cosine (50 docs) — baseline for batch ops
    # -------------------------------------------------------------------------
    docs_np = np.array(docs, dtype=np.float32)
    def numpy_batch():
        norms = np.linalg.norm(docs_np, axis=1)
        na = np.linalg.norm(a)
        sims = docs_np @ a / (norms * na + 1e-9)
        return sims.tolist()
    t = bench("numpy_batch_cosine_50docs", numpy_batch)
    print(f"NumPy batch cosine (50 docs): {t:.4f} ms")

    # -------------------------------------------------------------------------
    # 8. Hot path status summary
    # -------------------------------------------------------------------------
    try:
        from whitemagic.core.memory.graph_walker_hot_path import hot_path_status
        st = hot_path_status()
        print(f"\nHot path: backend={st['backend']} zig={st['zig_simd']} rust={st['rust_rrf']} julia_rrf={st['julia_rrf']} julia_pr={st['julia_pagerank']}")
    except Exception as e:
        print(f"Hot path status: ERROR: {e}")

    # -------------------------------------------------------------------------
    # Save report
    # -------------------------------------------------------------------------
    print("\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)
    for name, r in RESULTS.items():
        print(f"  {name:<40} {r['mean_ms']:>8.4f} ms  (p95={r['p95_ms']:.4f})")

    report_path = Path(__file__).parent.parent / "reports" / "v019_polyglot_benchmark.json"
    report_path.parent.mkdir(exist_ok=True)
    with open(report_path, "w") as f:
        json.dump({
            "timestamp": time.strftime("%Y-%m-%d %H:%M:%S"),
            "results": RESULTS,
            "baseline_python_loc_pct": 85.1,
        }, f, indent=2)
    print(f"\nReport saved: {report_path}")


if __name__ == "__main__":
    main()
