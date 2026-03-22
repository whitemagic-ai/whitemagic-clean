#!/usr/bin/env python3
"""WhiteMagic Benchmark Gauntlet v4 — Full System Reality Check
================================================================
Tests the COMPLETE WhiteMagic stack with Rust acceleration compiled:

  Tier 1: Rust Core (118 functions — holographic, BM25, galactic, minhash)
  Tier 2: Arrow IPC (zero-copy columnar vs JSON baseline)
  Tier 3: Tokio Clone Army (parallel exploration at scale)
  Tier 4: Parallel Engine Execution (21 engines concurrently)
  Tier 5: Swarm & Worker Infrastructure
  Tier 6: Full Activation (sequential vs parallel comparison)

Usage:
    .venv/bin/python scripts/benchmark_gauntlet_v4.py [--tier 1-6|all]
"""

import concurrent.futures
import json
import os
import statistics
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
os.environ.setdefault("WM_STATE_ROOT", str(Path.home() / ".whitemagic"))
os.environ.setdefault("WM_SILENT_INIT", "1")

RESULTS: list[dict] = []
VENV_PYTHON = str(Path(__file__).resolve().parent.parent / ".venv" / "bin" / "python3")


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


def bench(label: str, fn, iterations: int = 1000, warmup: int = 10, tier: int = 1):
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

    status_icon = "✓" if errors == 0 else f"⚠ {errors} errs"
    print(f"  {status_icon} {label}: median={_fmt_time(median)}  p95={_fmt_time(p95)}  {_fmt_rate(ops)}  ({len(times_ns)} iters)")

    RESULTS.append({
        "label": label, "tier": tier, "status": "pass",
        "median_ns": median, "p95_ns": p95, "ops_per_sec": ops,
        "iterations": len(times_ns), "errors": errors,
    })


# ═══════════════════════════════════════════════════════════════════
# TIER 1: Rust Core Acceleration
# ═══════════════════════════════════════════════════════════════════

def tier1_rust_core():
    print("\n═══ TIER 1: Rust Core Acceleration (118 functions) ═══")

    try:
        import whitemagic_rs as rs
        print(f"  ✓ whitemagic_rs loaded: {len([f for f in dir(rs) if not f.startswith('_')])} functions")
    except ImportError:
        print("  ✗ whitemagic_rs NOT AVAILABLE — run: cd whitemagic-rust && maturin develop --release")
        return

    # Holographic 5D encoding (takes JSON string with id, content, importance, memory_type, tags)
    _holo_json = json.dumps({"id": "bench", "content": "Test content for holographic encoding with meaningful text",
                             "importance": 0.7, "memory_type": "LONG_TERM", "tags": ["test", "bench", "memory"]})
    bench("Rust holographic_encode_single", lambda: rs.holographic_encode_single(_holo_json),
          iterations=10000, tier=1)

    # Keyword extraction
    bench("Rust keyword_extract (single)", lambda: rs.keyword_extract(
        "WhiteMagic uses holographic memory coordinates for spatial indexing of memories"
    ), iterations=5000, tier=1)

    bench("Rust keyword_extract_batch (100)", lambda: rs.keyword_extract_batch(
        [f"Memory about topic {i} with holographic coordinates" for i in range(100)], 50
    ), iterations=200, tier=1)

    # MinHash LSH (takes list of keyword sets, single arg)
    _kw_sets = [[f"word{j}" for j in range(i, i + 5)] for i in range(100)]
    bench("Rust minhash_signatures (100 docs)", lambda: rs.minhash_signatures(_kw_sets),
          iterations=100, tier=1)

    # Galactic scoring
    bench("Rust galactic_batch_score (100)", lambda: rs.galactic_batch_score(json.dumps([{
        "id": f"m{i}", "importance": 0.5, "neuro_score": 0.6, "emotional_valence": 0.3,
        "recall_count": 5, "link_count": 3, "is_protected": False, "access_count": 10,
    } for i in range(100)])), iterations=500, tier=1)

    # Fast file I/O
    _version_path = str(Path(__file__).resolve().parent.parent / "VERSION")
    bench("Rust read_file_fast", lambda: rs.read_file_fast(_version_path), iterations=5000, tier=1)

    # Event bus (needs event_type, payload, source)
    bench("Rust event_bus_try_emit", lambda: rs.event_bus_try_emit("bench_event", json.dumps({"test": True}), "bench"),
          iterations=5000, tier=1)

    # StateBoard
    bench("Rust board_read_harmony", lambda: rs.board_read_harmony(), iterations=10000, tier=1)

    # Rate limiter (single arg: tool name)
    bench("Rust rate_check", lambda: rs.rate_check("bench_tool"), iterations=5000, tier=1)

    # Python comparison: holographic encoding
    try:
        from whitemagic.core.memory.holographic import HolographicIndex
        hi = HolographicIndex()
        bench("Python holographic_encode (single)", lambda: hi.encode(
            content="Test content for holographic encoding with meaningful text",
            importance=0.7, memory_type="LONG_TERM", tags={"test", "bench", "memory"},
        ), iterations=2000, tier=1)
    except Exception as e:
        print(f"  ⊘ Python holographic comparison: {e}")


# ═══════════════════════════════════════════════════════════════════
# TIER 2: Arrow IPC
# ═══════════════════════════════════════════════════════════════════

def tier2_arrow():
    print("\n═══ TIER 2: Arrow IPC (Zero-Copy Columnar) ═══")

    try:
        import whitemagic_rs as rs
    except ImportError:
        print("  ✗ Rust not available")
        return

    sample_100 = json.dumps([{
        "id": f"test_{i}", "title": f"Memory Title {i}", "content": f"Content about topic {i} " * 20,
        "importance": 0.5, "memory_type": "SHORT_TERM",
        "x": 0.1, "y": 0.2, "z": 0.3, "w": 0.4, "v": 0.5,
        "tags": [f"tag{i % 5}"],
    } for i in range(100)])

    sample_1000 = json.dumps([{
        "id": f"test_{i}", "title": f"Memory Title {i}", "content": f"Content about topic {i} " * 20,
        "importance": 0.5, "memory_type": "SHORT_TERM",
        "x": 0.1, "y": 0.2, "z": 0.3, "w": 0.4, "v": 0.5,
        "tags": [f"tag{i % 5}"],
    } for i in range(1000)])

    bench("Arrow encode 100 memories", lambda: rs.arrow_encode_memories(sample_100),
          iterations=500, tier=2)

    ipc_100 = rs.arrow_encode_memories(sample_100)
    print(f"    → 100 memories → {len(ipc_100):,} Arrow IPC bytes")

    bench("Arrow decode 100 memories", lambda: rs.arrow_decode_memories(bytes(ipc_100)),
          iterations=500, tier=2)

    bench("Arrow encode 1000 memories", lambda: rs.arrow_encode_memories(sample_1000),
          iterations=100, tier=2)

    ipc_1000 = rs.arrow_encode_memories(sample_1000)
    print(f"    → 1000 memories → {len(ipc_1000):,} Arrow IPC bytes")

    # Roundtrip benchmark (takes int: number of records)
    roundtrip = rs.arrow_roundtrip_bench(100)
    print(f"    → Arrow roundtrip (100): encode={roundtrip[0]}ns, decode={roundtrip[1]}ns, total={roundtrip[2]}ns")

    # JSON baseline comparison
    bench("JSON serialize 100 memories", lambda: json.dumps(json.loads(sample_100)),
          iterations=500, tier=2)
    bench("JSON serialize 1000 memories", lambda: json.dumps(json.loads(sample_1000)),
          iterations=100, tier=2)


# ═══════════════════════════════════════════════════════════════════
# TIER 3: Tokio Clone Army
# ═══════════════════════════════════════════════════════════════════

def tier3_tokio():
    print("\n═══ TIER 3: Tokio Clone Army (Shadow Clone Jutsu) ═══")

    try:
        from whitemagic.optimization.rust_accelerators import (
            tokio_deploy_clones, tokio_clone_bench, tokio_clone_stats,
        )
    except ImportError:
        print("  ✗ Tokio not available")
        return

    scales = [10, 100, 1_000, 5_000, 10_000, 50_000, 100_000]
    for n in scales:
        result = tokio_clone_bench(n)
        if result:
            ms, cps = result
            print(f"  ✓ {n:>7,} clones: {ms:>8.1f}ms  ({cps:>12,.0f} clones/sec)")
            RESULTS.append({
                "label": f"Tokio {n:,} clones", "tier": 3, "status": "pass",
                "median_ns": ms * 1e6, "ops_per_sec": cps,
            })
        else:
            print(f"  ✗ {n:,} clones: FAILED")

    # Consensus test with different strategies
    strategies = ["direct", "chain_of_thought", "adversarial", "creative", "analytical", "synthesis", "memory_grounded"]
    result = tokio_deploy_clones("Analyze the patterns in a 111K memory corpus and recommend optimizations", 1000, strategies)
    if result:
        print("\n  Consensus (1000 clones, 7 strategies):")
        print(f"    Winner: {result['winner']['strategy']} (confidence={result['winner']['confidence']:.3f})")
        print(f"    Votes: {result['strategy_votes']}")
        print(f"    Avg confidence: {result['avg_confidence']:.3f}")
        print(f"    Total tokens: {result['total_tokens']:,}")
        print(f"    Elapsed: {result['elapsed_ms']:.1f}ms")

    stats = tokio_clone_stats()
    if stats:
        print(f"\n  Clone Army Stats: {json.dumps(stats, indent=2)}")


# ═══════════════════════════════════════════════════════════════════
# TIER 4: Parallel Engine Execution
# ═══════════════════════════════════════════════════════════════════

def _run_engine(name: str, fn) -> dict:
    """Run a single engine and return timing + result."""
    start = time.perf_counter()
    try:
        result = fn()
        elapsed = time.perf_counter() - start
        return {"engine": name, "status": "ok", "elapsed_s": elapsed, "result_keys": list(result.keys()) if isinstance(result, dict) else str(type(result))}
    except Exception as e:
        elapsed = time.perf_counter() - start
        return {"engine": name, "status": "error", "elapsed_s": elapsed, "error": str(e)[:200]}


def tier4_parallel_engines():
    print("\n═══ TIER 4: Parallel Engine Execution (21 engines) ═══")

    # Define all engine functions
    engines = {}

    def _galactic_sweep():
        from whitemagic.core.memory.galactic_map import get_galactic_map
        gm = get_galactic_map()
        return gm.sweep(sample_limit=5000)

    def _association_mining():
        from whitemagic.core.memory.association_miner import get_association_miner
        am = get_association_miner()
        return am.mine(sample_limit=100, max_new=50)

    def _constellation_detection():
        from whitemagic.core.memory.constellations import get_constellation_detector
        cd = get_constellation_detector()
        return cd.detect().to_dict() if cd.detect() else {}

    def _emergence_scan():
        from whitemagic.core.intelligence.agentic.emergence_engine import get_emergence_engine
        ee = get_emergence_engine()
        return {"insights": len(ee.scan())}

    def _novelty_detection():
        from whitemagic.core.intelligence.agentic.novelty_detector import NoveltyDetector
        nd = NoveltyDetector()
        return nd.detect("Test content about holographic memory coordinates in 5D space")

    def _harmony_vector():
        from whitemagic.harmony import get_harmony_vector
        hv = get_harmony_vector()
        return hv.snapshot()

    def _wu_xing():
        from whitemagic.wu_xing import get_wuxing_engine
        wx = get_wuxing_engine()
        return wx.get_balance()

    def _satkona_fusion():
        from whitemagic.core.fusion.satkona_fusion import fuse_signals_with_fusion
        return fuse_signals_with_fusion(signals={}, clusters={}, memories={}, agg={})

    def _multispectral():
        from whitemagic.core.intelligence.agentic.multi_spectral_reasoner import MultiSpectralReasoner
        msr = MultiSpectralReasoner()
        return msr.reason("What patterns emerge?")

    def _elemental_opt():
        from whitemagic.core.intelligence.elemental_optimization import ElementalOptimizer
        opt = ElementalOptimizer()
        return opt.get_optimization_strategy("exploration")

    def _guideline_evolution():
        from whitemagic.core.patterns.emergence.guideline_evolution import GuidelineEvolution
        ge = GuidelineEvolution()
        return {"pending": len(ge.get_pending_proposals())}

    def _pattern_consciousness():
        from whitemagic.core.patterns.pattern_consciousness.autonomous_learner import AutonomousLearner
        al = AutonomousLearner()
        return {"learner": type(al).__name__}

    def _knowledge_graph():
        from whitemagic.core.intelligence.knowledge_graph import get_knowledge_graph
        kg = get_knowledge_graph()
        return kg.status()

    engines = {
        "galactic_sweep": _galactic_sweep,
        "association_mining": _association_mining,
        "constellation_detection": _constellation_detection,
        "emergence_scan": _emergence_scan,
        "novelty_detection": _novelty_detection,
        "harmony_vector": _harmony_vector,
        "wu_xing": _wu_xing,
        "satkona_fusion": _satkona_fusion,
        "multispectral": _multispectral,
        "elemental_optimization": _elemental_opt,
        "guideline_evolution": _guideline_evolution,
        "pattern_consciousness": _pattern_consciousness,
        "knowledge_graph": _knowledge_graph,
    }

    # SEQUENTIAL execution (baseline)
    print(f"\n  --- Sequential ({len(engines)} engines) ---")
    seq_start = time.perf_counter()
    seq_results = []
    for name, fn in engines.items():
        r = _run_engine(name, fn)
        seq_results.append(r)
        icon = "✓" if r["status"] == "ok" else "✗"
        print(f"    {icon} {name}: {r['elapsed_s']:.3f}s")
    seq_total = time.perf_counter() - seq_start
    seq_ok = sum(1 for r in seq_results if r["status"] == "ok")
    print(f"  Sequential total: {seq_total:.2f}s ({seq_ok}/{len(engines)} ok)")

    # PARALLEL execution (ThreadPoolExecutor)
    print(f"\n  --- Parallel ThreadPool ({len(engines)} engines) ---")
    par_start = time.perf_counter()
    par_results = []
    with concurrent.futures.ThreadPoolExecutor(max_workers=len(engines)) as executor:
        futures = {executor.submit(_run_engine, name, fn): name for name, fn in engines.items()}
        for future in concurrent.futures.as_completed(futures):
            r = future.result()
            par_results.append(r)
    par_total = time.perf_counter() - par_start
    par_ok = sum(1 for r in par_results if r["status"] == "ok")

    for r in sorted(par_results, key=lambda x: x["elapsed_s"]):
        icon = "✓" if r["status"] == "ok" else "✗"
        print(f"    {icon} {r['engine']}: {r['elapsed_s']:.3f}s")
    print(f"  Parallel total: {par_total:.2f}s ({par_ok}/{len(engines)} ok)")

    speedup = seq_total / par_total if par_total > 0 else 0
    print(f"\n  ⚡ Parallel speedup: {speedup:.1f}× faster")

    RESULTS.append({
        "label": f"Sequential {len(engines)} engines", "tier": 4, "status": "pass",
        "median_ns": seq_total * 1e9, "ops_per_sec": len(engines) / seq_total,
    })
    RESULTS.append({
        "label": f"Parallel {len(engines)} engines", "tier": 4, "status": "pass",
        "median_ns": par_total * 1e9, "ops_per_sec": len(engines) / par_total,
        "extra": {"speedup": speedup},
    })


# ═══════════════════════════════════════════════════════════════════
# TIER 5: Swarm & Worker Infrastructure
# ═══════════════════════════════════════════════════════════════════

def tier5_swarm():
    print("\n═══ TIER 5: Swarm & Worker Infrastructure ═══")

    from whitemagic.agents.swarm import get_swarm

    swarm = get_swarm()

    # Task decomposition
    bench("Swarm decompose (simple)", lambda: swarm.decompose("Analyze codebase and generate report"),
          iterations=500, tier=5)

    bench("Swarm decompose (complex)", lambda: swarm.decompose(
        "Search memories, analyze patterns, test code, deploy service, monitor health",
        hints=["Search memory for patterns", "Analyze emerging themes", "Run test suite", "Deploy to staging", "Monitor harmony"],
    ), iterations=200, tier=5)

    # Voting
    plan = swarm.decompose("Test task")
    bench("Swarm vote", lambda: swarm.vote("bench_topic", "agent_1", "yes", 0.9),
          iterations=1000, tier=5)
    bench("Swarm resolve (majority)", lambda: swarm.resolve("bench_topic"),
          iterations=1000, tier=5)

    # Routing
    plan = swarm.decompose("Search and analyze memories")
    bench("Swarm route", lambda: swarm.route(plan.id), iterations=500, tier=5)

    status = swarm.status()
    print(f"  Swarm status: {json.dumps(status)}")


# ═══════════════════════════════════════════════════════════════════
# TIER 6: Full System Integration
# ═══════════════════════════════════════════════════════════════════

def tier6_integration():
    print("\n═══ TIER 6: Full System Integration ═══")

    # StateBoard + EventRing + HarmonyVector integrated test
    try:
        import whitemagic_rs as rs
        # Write harmony → read back → emit event
        def _full_cycle():
            rs.board_write_harmony(0.8, 0.7, 0.1, 0.05, 0.9, 0.1, 0.7)
            h = rs.board_read_harmony()
            rs.event_bus_try_emit("harmony_update", json.dumps({"score": h[0]}))
            return h

        bench("StateBoard+EventRing cycle", _full_cycle, iterations=5000, tier=6)
    except Exception as e:
        print(f"  ⊘ StateBoard integration: {e}")

    # Memory store → embed → search roundtrip (if available)
    try:
        from whitemagic.core.memory.unified import UnifiedMemory, MemoryType
        um = UnifiedMemory()

        def _store_search_cycle():
            um.store(content=f"Benchmark memory {time.time()}", memory_type=MemoryType.SHORT_TERM,
                     title="bench_v4", importance=0.3)
            return um.search("benchmark memory", limit=3)

        bench("Store→Search roundtrip", _store_search_cycle, iterations=100, tier=6)
    except Exception as e:
        print(f"  ⊘ Memory roundtrip: {e}")

    # Tokio + Arrow combined: deploy clones AND encode results
    try:
        from whitemagic.optimization.rust_accelerators import tokio_deploy_clones
        import whitemagic_rs as rs

        def _tokio_arrow_pipeline():
            result = tokio_deploy_clones("Full pipeline test", 100)
            # Encode clone results as Arrow
            docs = json.dumps([{
                "id": f"clone_{i}", "title": f"Clone {i}", "content": result["winner"]["response"],
                "importance": result["avg_confidence"], "memory_type": "SHORT_TERM",
                "x": 0.0, "y": 0.0, "z": 0.0, "w": 0.5, "v": 0.5, "tags": ["clone"],
            } for i in range(10)])
            ipc = rs.arrow_encode_memories(docs)
            return len(ipc)

        bench("Tokio+Arrow pipeline (100 clones → Arrow)", _tokio_arrow_pipeline,
              iterations=50, tier=6)
    except Exception as e:
        print(f"  ⊘ Tokio+Arrow pipeline: {e}")


# ═══════════════════════════════════════════════════════════════════
# Summary
# ═══════════════════════════════════════════════════════════════════

def print_summary():
    print("\n" + "═" * 72)
    print("  BENCHMARK GAUNTLET v4 — FULL SYSTEM REALITY CHECK")
    print("═" * 72)

    passed = sum(1 for r in RESULTS if r.get("status") == "pass")
    failed = sum(1 for r in RESULTS if r.get("status") == "error")
    print(f"\n  Total: {len(RESULTS)} benchmarks | {passed} passed | {failed} failed")

    # Rust vs Python comparisons
    rust_holo = next((r for r in RESULTS if "Rust holographic_encode_5d" in r.get("label", "")), None)
    py_holo = next((r for r in RESULTS if "Python holographic_encode" in r.get("label", "")), None)
    if rust_holo and py_holo and rust_holo.get("median_ns") and py_holo.get("median_ns"):
        speedup = py_holo["median_ns"] / rust_holo["median_ns"]
        print(f"\n  🦀 Rust vs Python 5D encode: {speedup:.1f}× speedup")

    # Arrow vs JSON
    arrow_100 = next((r for r in RESULTS if "Arrow encode 100" in r.get("label", "")), None)
    json_100 = next((r for r in RESULTS if "JSON serialize 100" in r.get("label", "")), None)
    if arrow_100 and json_100 and arrow_100.get("median_ns") and json_100.get("median_ns"):
        speedup = json_100["median_ns"] / arrow_100["median_ns"]
        print(f"  🏹 Arrow vs JSON (100 docs): {speedup:.1f}× speedup")

    # Tokio scale
    tokio_results = [r for r in RESULTS if r.get("label", "").startswith("Tokio") and r.get("ops_per_sec")]
    if tokio_results:
        best = max(tokio_results, key=lambda r: r["ops_per_sec"])
        print(f"  ⚡ Peak Tokio throughput: {_fmt_rate(best['ops_per_sec'])} ({best['label']})")

    # Parallel speedup
    par = next((r for r in RESULTS if "Parallel" in r.get("label", "")), None)
    if par and par.get("extra", {}).get("speedup"):
        print(f"  🔀 Parallel engine speedup: {par['extra']['speedup']:.1f}×")

    # Save results
    out_path = Path(__file__).parent.parent / "reports" / f"benchmark_v4_{time.strftime('%Y%m%d_%H%M%S')}.json"
    out_path.parent.mkdir(exist_ok=True)
    with open(out_path, "w") as f:
        json.dump({
            "timestamp": time.strftime("%Y-%m-%dT%H:%M:%S"),
            "python": sys.version,
            "rust_available": True,
            "results": RESULTS,
        }, f, indent=2)
    print(f"\n  📄 Results saved to: {out_path}")
    print("═" * 72)


def main():
    import argparse
    parser = argparse.ArgumentParser(description="WhiteMagic Benchmark Gauntlet v4")
    parser.add_argument("--tier", default="all", help="Tier: 1|2|3|4|5|6|all")
    args = parser.parse_args()

    print("═" * 72)
    print("  WhiteMagic Benchmark Gauntlet v4 — Full System Reality Check")
    print("  Rust Core • Arrow IPC • Tokio Clones • Parallel Engines • Swarm")
    print("═" * 72)

    # Check Rust
    try:
        import whitemagic_rs
        n = len([f for f in dir(whitemagic_rs) if not f.startswith("_")])
        print(f"\n  🦀 Rust binary: {n} functions loaded")
    except ImportError:
        print("\n  ⚠️  Rust binary NOT available — many tiers will be skipped")

    tier = args.tier.lower()
    start = time.time()

    if tier in ("1", "all"):
        tier1_rust_core()
    if tier in ("2", "all"):
        tier2_arrow()
    if tier in ("3", "all"):
        tier3_tokio()
    if tier in ("4", "all"):
        tier4_parallel_engines()
    if tier in ("5", "all"):
        tier5_swarm()
    if tier in ("6", "all"):
        tier6_integration()

    elapsed = time.time() - start
    print(f"\n  ⏱  Total gauntlet time: {elapsed:.1f}s")
    print_summary()


if __name__ == "__main__":
    main()
