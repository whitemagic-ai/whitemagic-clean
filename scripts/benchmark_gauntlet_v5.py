#!/usr/bin/env python3
"""WhiteMagic Benchmark Gauntlet v5 — All 21 Engines + Rust Acceleration
=========================================================================
Comprehensive benchmark covering every engine in the extended activation:

  Tier 1: Core baselines (store, search, dispatch, harmony)
  Tier 2: Rust acceleration (holographic, keyword, galactic, clone army)
  Tier 3: Graph engines (topology, walker, bridges, communities, PageRank)
  Tier 4: Intelligence (multi-spectral, causal, emergence, novelty)
  Tier 5: Dream cycle phases (triage, consolidation, narrative, serendipity)
  Tier 6: Fusion & synthesis (satkona, bridge synthesis, elemental opt)

Usage:
    python scripts/benchmark_gauntlet_v5.py                    # Full run
    python scripts/benchmark_gauntlet_v5.py --tier 2           # Single tier
    python scripts/benchmark_gauntlet_v5.py --quick            # Fewer iterations
    python scripts/benchmark_gauntlet_v5.py --json             # JSON output
"""

import argparse
import json
import os
import statistics
import sys
import time
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ.setdefault("WM_SILENT_INIT", "1")

RESULTS: list[dict] = []
TIER_SUMMARIES: dict[int, dict] = {}


def _fmt_time(ns: float) -> str:
    if ns < 1_000:
        return f"{ns:.0f}ns"
    elif ns < 1_000_000:
        return f"{ns / 1_000:.1f}µs"
    elif ns < 1_000_000_000:
        return f"{ns / 1_000_000:.2f}ms"
    else:
        return f"{ns / 1_000_000_000:.3f}s"


def _fmt_rate(ops_per_sec: float) -> str:
    if ops_per_sec >= 1_000_000:
        return f"{ops_per_sec / 1_000_000:.2f}M ops/s"
    elif ops_per_sec >= 1_000:
        return f"{ops_per_sec / 1_000:.1f}K ops/s"
    else:
        return f"{ops_per_sec:.0f} ops/s"


def bench(label: str, fn, iterations: int = 100, warmup: int = 5, tier: int = 1):
    """Run a benchmark, collecting timing stats."""
    for _ in range(warmup):
        try:
            fn()
        except Exception:
            break

    times_ns = []
    errors = 0
    for _ in range(iterations):
        start = time.perf_counter_ns()
        try:
            fn()
        except Exception:
            errors += 1
            continue
        elapsed = time.perf_counter_ns() - start
        times_ns.append(elapsed)

    if not times_ns:
        print(f"  ✗ {label}: ALL ERRORS ({errors}/{iterations})")
        RESULTS.append({"label": label, "tier": tier, "status": "error", "errors": errors})
        return

    median = statistics.median(times_ns)
    p95 = sorted(times_ns)[int(len(times_ns) * 0.95)]
    ops = len(times_ns) / (sum(times_ns) / 1e9) if sum(times_ns) > 0 else 0

    status = "✓" if errors == 0 else f"⚠ {errors} errs"
    print(f"  {status} {label}: median={_fmt_time(median)}  p95={_fmt_time(p95)}  {_fmt_rate(ops)}  ({len(times_ns)} iters)")

    RESULTS.append({
        "label": label, "tier": tier, "status": "pass",
        "median_ns": median, "p95_ns": p95, "ops_per_sec": ops,
        "iterations": len(times_ns), "errors": errors,
    })


def timed_run(label: str, fn, tier: int = 1):
    """Run a single heavy operation, report time."""
    start = time.perf_counter_ns()
    try:
        result = fn()
        elapsed = time.perf_counter_ns() - start
        ms = elapsed / 1e6
        print(f"  ✓ {label}: {ms:.1f}ms")
        RESULTS.append({
            "label": label, "tier": tier, "status": "pass",
            "duration_ms": ms, "result_summary": str(result)[:200] if result else "",
        })
        return result
    except Exception as e:
        elapsed = time.perf_counter_ns() - start
        ms = elapsed / 1e6
        print(f"  ✗ {label}: {e} ({ms:.1f}ms)")
        RESULTS.append({"label": label, "tier": tier, "status": "error", "error": str(e)})
        return None


# ═══════════════════════════════════════════════════════════════════
# TIER 1: Core Baselines
# ═══════════════════════════════════════════════════════════════════

def tier1_core(quick=False):
    print("\n═══ TIER 1: Core Baselines ═══")
    iters = 50 if quick else 200

    from whitemagic.core.memory.unified import get_unified_memory
    um = get_unified_memory()

    # Memory search
    bench("Memory search (top-5)", lambda: um.search("benchmark test", limit=5),
          iterations=iters, tier=1)

    # Dispatch table lookup
    from whitemagic.tools.dispatch_table import DISPATCH_TABLE
    tools = list(DISPATCH_TABLE.keys())
    bench("Dispatch table lookup", lambda: DISPATCH_TABLE.get(tools[0]),
          iterations=5000, tier=1)

    # Harmony vector
    from whitemagic.harmony.vector import get_harmony_vector
    hv = get_harmony_vector()
    bench("Harmony vector snapshot", lambda: hv.snapshot(), iterations=iters * 5, tier=1)

    # PRAT routing
    from whitemagic.tools.prat_router import get_prat_router
    router = get_prat_router()
    bench("PRAT route lookup", lambda: router.route("search_memories"),
          iterations=2000, tier=1)


# ═══════════════════════════════════════════════════════════════════
# TIER 2: Rust Acceleration
# ═══════════════════════════════════════════════════════════════════

def tier2_rust(quick=False):
    print("\n═══ TIER 2: Rust Acceleration ═══")
    iters = 50 if quick else 200

    try:
        import whitemagic_rust as whitemagic_rs
        print("  Rust bridge: LOADED")
    except ImportError:
        print("  ⊘ Rust bridge not available — skipping tier")
        RESULTS.append({"label": "Rust bridge", "tier": 2, "status": "skip"})
        return

    # Holographic encoding
    import json as _json
    _holo_input = _json.dumps({
        "id": "bench_test_001",
        "content": "The quantum entanglement of memory systems creates emergent consciousness patterns in holographic space",
        "importance": 0.8, "access_count": 100,
        "age_days": 7.0, "galactic_distance": 0.3,
    })
    # Use the correct submodule function
    bench("Rust holographic_encode_single", lambda: whitemagic_rs.holographic_encoder_5d.holographic_encode_single(
        _holo_input
    ), iterations=iters * 5, tier=2)

    # Keyword extraction
    bench("Rust keyword_extract", lambda: whitemagic_rs.keyword_extract(
        "The quantum entanglement of memory systems creates emergent consciousness patterns"
    ), iterations=iters * 5, tier=2)

    # Galactic batch score
    _galactic_input = _json.dumps([{
        "importance": 0.8, "access_count": 100,
        "recency": 0.7, "emotional_valence": 0.5,
    }])
    bench("Rust galactic_batch_score", lambda: whitemagic_rs.galactic_batch_score(
        _galactic_input
    ), iterations=iters * 10, tier=2)

    # MinHash
    _minhash_input = _json.dumps([["quick", "brown", "fox", "jumps", "lazy", "dog"]])
    bench("Rust minhash_signatures", lambda: whitemagic_rs.minhash_signatures(
        _minhash_input
    ), iterations=iters * 5, tier=2)

    # Tokio Clone Army
    try:
        start = time.perf_counter_ns()
        # Find the correct location for tokio_clone_bench
        whitemagic_rs.tokio_clone_bench(10000)
        elapsed = time.perf_counter_ns() - start
        rate = 10000 / (elapsed / 1e9)
        print(f"  ✓ Tokio clone army (10K): {elapsed / 1e6:.1f}ms ({_fmt_rate(rate)})")
        RESULTS.append({"label": "Tokio clone army (10K)", "tier": 2, "status": "pass",
                        "duration_ms": elapsed / 1e6, "rate": rate})
    except Exception as e:
        print(f"  ✗ Tokio clone army: {e}")
        RESULTS.append({"label": "Tokio clone army", "tier": 2, "status": "error", "error": str(e)})

    # State Board (read harmony + read state)
    try:
        from whitemagic.core.acceleration.state_board_bridge import get_state_board
        sb = get_state_board()
        bench("StateBoard read_harmony+read_resonance", lambda: (
            sb.read_harmony(),
            sb.read_resonance(),
        ), iterations=iters * 5, tier=2)
    except Exception as e:
        print(f"  ⊘ StateBoard: {e}")


# ═══════════════════════════════════════════════════════════════════
# TIER 3: Graph Engines
# ═══════════════════════════════════════════════════════════════════

def tier3_graph(quick=False):
    print("\n═══ TIER 3: Graph Engines ═══")

    from whitemagic.core.memory.graph_engine import get_graph_engine
    engine = get_graph_engine()

    # Graph rebuild (heavy — single run)
    timed_run("Graph rebuild (20K sample, quality filter)", lambda: engine.rebuild(
        sample_limit=20000, quality_filter=True
    ), tier=3)

    # Bridge detection
    timed_run("Bridge node detection (top-10)", lambda: engine.find_bridge_nodes(top_n=10), tier=3)

    # Community detection
    timed_run("Community detection", lambda: engine.detect_communities(), tier=3)

    # PageRank
    timed_run("PageRank computation", lambda: engine.pagerank(), tier=3)

    # Graph stats
    bench("Graph stats", lambda: engine.get_stats(), iterations=100, tier=3)

    # Graph walker
    try:
        from whitemagic.core.memory.graph_walker import get_graph_walker
        from whitemagic.core.memory.unified import get_unified_memory
        walker = get_graph_walker()
        um = get_unified_memory()

        with um.backend.pool.connection() as conn:
            row = conn.execute(
                """SELECT m.id FROM memories m
                   JOIN associations a ON m.id = a.source_id
                   WHERE m.importance > 0.7
                   GROUP BY m.id HAVING COUNT(*) > 5
                   ORDER BY m.importance DESC LIMIT 1"""
            ).fetchone()

        if row:
            seed_id = row[0]
            iters = 10 if quick else 30
            bench("Graph walker (3 hops, top-5)", lambda: walker.walk(
                seed_ids=[seed_id], hops=3, top_k=5, enforce_causality=False
            ), iterations=iters, tier=3)
    except Exception as e:
        print(f"  ⊘ Graph walker: {e}")


# ═══════════════════════════════════════════════════════════════════
# TIER 4: Intelligence Engines
# ═══════════════════════════════════════════════════════════════════

def tier4_intelligence(quick=False):
    print("\n═══ TIER 4: Intelligence Engines ═══")
    iters = 5 if quick else 20

    # Multi-spectral reasoning
    from whitemagic.core.intelligence.multi_spectral_reasoning import get_reasoner
    reasoner = get_reasoner()
    bench("Multi-spectral reason (4 lenses)", lambda: reasoner.reason(
        "How should memory systems evolve?"
    ), iterations=iters, tier=4)

    # Causal mining
    from whitemagic.core.memory.causal_miner import get_causal_miner
    miner = get_causal_miner(persist=False)
    timed_run("Causal mining (100 sample)", lambda: miner.mine(sample_size=100), tier=4)

    # Emergence scan
    try:
        from whitemagic.core.intelligence.agentic.emergence_engine import (
            get_emergence_engine,
        )
        ee = get_emergence_engine()
        ee.start()
        timed_run("Emergence scan", lambda: ee.scan_for_emergence(), tier=4)
    except Exception as e:
        print(f"  ⊘ Emergence scan: {e}")

    # Novelty detection
    try:
        from whitemagic.core.patterns.emergence.novelty_detector import (
            get_novelty_detector,
        )
        detector = get_novelty_detector()
        bench("Novelty detection", lambda: detector.detect(
            "Quantum-entangled memory associations across distributed galaxy instances"
        ), iterations=iters * 5, tier=4)
    except Exception as e:
        print(f"  ⊘ Novelty detection: {e}")

    # Constellation detection
    from whitemagic.core.memory.constellations import get_constellation_detector
    cd = get_constellation_detector()
    timed_run("Constellation detection (5K sample)", lambda: cd.detect(sample_limit=5000), tier=4)

    # Association mining
    from whitemagic.core.memory.association_miner import get_association_miner
    am = get_association_miner(max_proposals=50, persist=False)
    timed_run("Association mining (100 sample)", lambda: am.mine(sample_size=100), tier=4)


# ═══════════════════════════════════════════════════════════════════
# TIER 5: Dream Cycle
# ═══════════════════════════════════════════════════════════════════

def tier5_dream(quick=False):
    print("\n═══ TIER 5: Dream Cycle Phases ═══")

    from whitemagic.core.dreaming.dream_cycle import get_dream_cycle
    cycle = get_dream_cycle()

    phases = [
        ("Dream: triage", cycle._dream_triage),
        ("Dream: consolidation", cycle._dream_consolidation),
        ("Dream: narrative", cycle._dream_narrative),
        ("Dream: kaizen", cycle._dream_kaizen),
        ("Dream: oracle", cycle._dream_oracle),
        ("Dream: decay", cycle._dream_decay),
    ]

    if not quick:
        phases.insert(2, ("Dream: serendipity", cycle._dream_serendipity))
        phases.insert(3, ("Dream: governance", cycle._dream_governance))

    for label, method in phases:
        timed_run(label, method, tier=5)


# ═══════════════════════════════════════════════════════════════════
# TIER 6: Fusion & Synthesis
# ═══════════════════════════════════════════════════════════════════

def tier6_fusion(quick=False):
    print("\n═══ TIER 6: Fusion & Synthesis ═══")
    iters = 10 if quick else 50

    # Bridge synthesis
    try:
        from whitemagic.core.memory.bridge_synthesizer import get_bridge_synthesizer
        from whitemagic.core.memory.graph_engine import get_graph_engine
        synth = get_bridge_synthesizer()
        ge = get_graph_engine()
        bridges = ge.find_bridge_nodes(top_n=5)
        if bridges:
            timed_run("Bridge synthesis (5 nodes)", lambda: synth.synthesize_from_bridges(
                bridges, top_n=3
            ), tier=6)
    except Exception as e:
        print(f"  ⊘ Bridge synthesis: {e}")

    # Elemental optimization
    try:
        from whitemagic.core.intelligence.elemental_optimization import (
            ElementalOptimizer,
        )
        opt = ElementalOptimizer()
        bench("Elemental optimization", lambda: opt.get_optimization_strategy("analysis"),
              iterations=iters, tier=6)
    except Exception as e:
        print(f"  ⊘ Elemental optimization: {e}")

    # Knowledge graph top entities
    try:
        from whitemagic.core.intelligence.knowledge_graph import get_knowledge_graph
        kg = get_knowledge_graph()
        bench("KG top entities", lambda: kg.top_entities(limit=10), iterations=iters, tier=6)
    except Exception as e:
        print(f"  ⊘ Knowledge graph: {e}")

    # Constellation auto-merge
    try:
        from whitemagic.core.memory.constellations import get_constellation_detector
        cd = get_constellation_detector()
        timed_run("Constellation auto-merge", lambda: cd.auto_merge(
            max_distance=0.5, min_shared_tags=2
        ), tier=6)
    except Exception as e:
        print(f"  ⊘ Constellation merge: {e}")

    # Wu Xing balance
    try:
        from whitemagic.wu_xing import get_elemental_balance
        bench("Wu Xing balance", lambda: get_elemental_balance(), iterations=iters * 5, tier=6)
    except Exception as e:
        print(f"  ⊘ Wu Xing: {e}")


# ═══════════════════════════════════════════════════════════════════
# TIER 7: JSON Serialization & Dispatch Pipeline
# ═══════════════════════════════════════════════════════════════════

def tier7_json_dispatch(quick=False):
    print("\n═══ TIER 7: JSON Serialization & Dispatch Pipeline ═══")
    iters = 100 if quick else 500

    # --- JSON serialization: stdlib vs orjson ---
    import json as _stdlib_json
    _test_payload = {
        "id": "bench_memory_001",
        "content": "The quantum entanglement of memory systems creates " * 10,
        "importance": 0.85,
        "tags": ["benchmark", "test", "quantum", "memory", "entanglement"],
        "metadata": {"access_count": 42, "age_days": 7.5, "galactic_distance": 0.3},
        "associations": [{"target": f"mem_{i}", "weight": 0.5 + i * 0.01} for i in range(20)],
    }
    _test_json_str = _stdlib_json.dumps(_test_payload)

    # stdlib json.dumps
    bench("stdlib json.dumps", lambda: _stdlib_json.dumps(_test_payload),
          iterations=iters * 10, tier=7)

    # stdlib json.loads
    bench("stdlib json.loads", lambda: _stdlib_json.loads(_test_json_str),
          iterations=iters * 10, tier=7)

    # orjson (if available)
    try:
        import orjson
        bench("orjson.dumps (bytes)", lambda: orjson.dumps(_test_payload),
              iterations=iters * 10, tier=7)
        bench("orjson.dumps + decode (str)", lambda: orjson.dumps(_test_payload).decode("utf-8"),
              iterations=iters * 10, tier=7)
        _test_json_bytes = orjson.dumps(_test_payload)
        bench("orjson.loads (bytes)", lambda: orjson.loads(_test_json_bytes),
              iterations=iters * 10, tier=7)
        bench("orjson.loads (str)", lambda: orjson.loads(_test_json_str),
              iterations=iters * 10, tier=7)
    except ImportError:
        print("  ⊘ orjson not available")
        RESULTS.append({"label": "orjson", "tier": 7, "status": "skip"})

    # fast_json wrapper
    try:
        from whitemagic.utils.fast_json import BACKEND, dumps_str, loads
        print(f"  fast_json backend: {BACKEND}")
        bench(f"fast_json.dumps_str ({BACKEND})", lambda: dumps_str(_test_payload),
              iterations=iters * 10, tier=7)
        bench(f"fast_json.loads ({BACKEND})", lambda: loads(_test_json_str),
              iterations=iters * 10, tier=7)
    except ImportError:
        print("  ⊘ fast_json not available")

    # --- Dispatch pipeline overhead ---
    # Measure _ensure_cached (should be ~0.5µs after first call)
    from whitemagic.tools.middleware import _ensure_cached
    _ensure_cached()  # warm up
    bench("middleware._ensure_cached()", _ensure_cached,
          iterations=iters * 100, tier=7)

    # Measure a lightweight dispatch (PRAT lookup + pipeline)
    from whitemagic.tools.dispatch_table import dispatch as _dispatch
    bench("dispatch('capabilities')", lambda: _dispatch("capabilities"),
          iterations=iters, tier=7)

    bench("dispatch('gnosis')", lambda: _dispatch("gnosis"),
          iterations=iters, tier=7)


# ═══════════════════════════════════════════════════════════════════
# SUMMARY
# ═══════════════════════════════════════════════════════════════════

def print_summary():
    total = len(RESULTS)
    passed = sum(1 for r in RESULTS if r["status"] == "pass")
    errors = sum(1 for r in RESULTS if r["status"] == "error")
    skipped = sum(1 for r in RESULTS if r["status"] == "skip")

    print(f"\n{'═' * 70}")
    print("📋 BENCHMARK GAUNTLET v5 SUMMARY")
    print(f"{'═' * 70}")
    print(f"  Total benchmarks: {total}")
    print(f"  Passed: {passed}  |  Errors: {errors}  |  Skipped: {skipped}")

    # Per-tier summary
    tiers = sorted(set(r["tier"] for r in RESULTS))
    for t in tiers:
        tier_results = [r for r in RESULTS if r["tier"] == t]
        tier_pass = sum(1 for r in tier_results if r["status"] == "pass")
        sum(1 for r in tier_results if r["status"] == "error")
        tier_names = {1: "Core", 2: "Rust", 3: "Graph", 4: "Intelligence", 5: "Dream", 6: "Fusion", 7: "JSON+Dispatch"}
        print(f"  Tier {t} ({tier_names.get(t, '?')}): {tier_pass}/{len(tier_results)} passed")

    # Highlight fastest operations
    fast_ops = [r for r in RESULTS if r.get("ops_per_sec", 0) > 0]
    if fast_ops:
        fast_ops.sort(key=lambda r: r["ops_per_sec"], reverse=True)
        print("\n  🏆 Fastest operations:")
        for r in fast_ops[:5]:
            print(f"    {_fmt_rate(r['ops_per_sec']):>15}  {r['label']}")

    # Highlight slowest
    slow_ops = [r for r in RESULTS if r.get("duration_ms", 0) > 0]
    if slow_ops:
        slow_ops.sort(key=lambda r: r["duration_ms"], reverse=True)
        print("\n  🐌 Heaviest operations:")
        for r in slow_ops[:5]:
            print(f"    {r['duration_ms']:>10.1f}ms  {r['label']}")


def main():
    parser = argparse.ArgumentParser(description="WhiteMagic Benchmark Gauntlet v5")
    parser.add_argument("--tier", type=int, help="Run specific tier (1-6)")
    parser.add_argument("--quick", action="store_true", help="Fewer iterations")
    parser.add_argument("--json", action="store_true", help="Output JSON results")
    args = parser.parse_args()

    print("🚀 WhiteMagic Benchmark Gauntlet v5 — All Engines + Rust")
    print(f"{'═' * 70}")
    print(f"Timestamp: {datetime.now().isoformat()}")
    print(f"Mode: {'quick' if args.quick else 'full'}")
    if args.tier:
        print(f"Tier: {args.tier}")
    print(f"{'═' * 70}")

    total_start = time.perf_counter()

    tier_fns = {
        1: lambda: tier1_core(args.quick),
        2: lambda: tier2_rust(args.quick),
        3: lambda: tier3_graph(args.quick),
        4: lambda: tier4_intelligence(args.quick),
        5: lambda: tier5_dream(args.quick),
        6: lambda: tier6_fusion(args.quick),
        7: lambda: tier7_json_dispatch(args.quick),
    }

    if args.tier:
        if args.tier in tier_fns:
            tier_fns[args.tier]()
        else:
            print(f"Unknown tier: {args.tier}")
            sys.exit(1)
    else:
        for t in sorted(tier_fns.keys()):
            try:
                tier_fns[t]()
            except Exception as e:
                print(f"  ✗ Tier {t} failed: {e}")

    total_elapsed = time.perf_counter() - total_start
    print(f"\n⏱  Total time: {total_elapsed:.1f}s")

    print_summary()

    # Save results
    if args.json or True:  # Always save
        report_dir = ROOT / "reports"
        report_dir.mkdir(exist_ok=True)
        report_path = report_dir / f"benchmark_v5_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json"
        with open(report_path, "w") as f:
            json.dump({
                "version": "v5",
                "timestamp": datetime.now().isoformat(),
                "mode": "quick" if args.quick else "full",
                "total_time_s": total_elapsed,
                "results": RESULTS,
            }, f, indent=2, default=str)
        print(f"\n📄 Report saved: {report_path}")


if __name__ == "__main__":
    main()
