#!/usr/bin/env python3
"""WhiteMagic Benchmark Gauntlet v2 — Progressive Stress Testing
================================================================
Tier 1: Core subsystem latency (memory ops, dispatch, harmony, events)
Tier 2: Polyglot accelerators (Rust, Zig, SIMD hot paths)
Tier 3: Swarm & concurrency (clone armies, async agents, collective dreams)

Usage:
    python scripts/benchmark_gauntlet_v2.py [--tier 1|2|3|all] [--verbose]
"""

import asyncio
import os
import statistics
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent.parent))

os.environ.setdefault("WHITEMAGIC_STATE_ROOT", str(Path.home() / ".whitemagic"))
os.environ.setdefault("WHITEMAGIC_LOG_LEVEL", "WARNING")

# ═══════════════════════════════════════════════════════════════════
# Utilities
# ═══════════════════════════════════════════════════════════════════

RESULTS: list[dict] = []

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

def bench(label: str, fn, iterations: int = 1000, warmup: int = 10):
    """Run a benchmark, collecting timing stats."""
    # Warmup
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
        print(f"  ❌ {label} — all {iterations} iterations failed")
        RESULTS.append({"label": label, "status": "FAIL", "errors": errors})
        return

    p50 = statistics.median(times_ns)
    p99 = sorted(times_ns)[int(len(times_ns) * 0.99)] if len(times_ns) >= 100 else max(times_ns)
    mean = statistics.mean(times_ns)
    ops_per_sec = 1_000_000_000 / mean if mean > 0 else 0

    print(f"  ✅ {label}")
    print(f"     p50={_fmt_time(p50)}  p99={_fmt_time(p99)}  mean={_fmt_time(mean)}  {_fmt_rate(ops_per_sec)}")
    if errors:
        print(f"     ⚠️  {errors}/{iterations} errors")

    RESULTS.append({
        "label": label,
        "status": "OK",
        "p50_ns": p50,
        "p99_ns": p99,
        "mean_ns": mean,
        "ops_per_sec": ops_per_sec,
        "iterations": len(times_ns),
        "errors": errors,
    })

async def async_bench(label: str, fn, iterations: int = 1000, warmup: int = 10):
    """Run an async benchmark."""
    for _ in range(warmup):
        try:
            await fn()
        except Exception:
            break

    times_ns = []
    errors = 0
    for _ in range(iterations):
        start = time.perf_counter_ns()
        try:
            await fn()
        except Exception:
            errors += 1
            continue
        elapsed = time.perf_counter_ns() - start
        times_ns.append(elapsed)

    if not times_ns:
        print(f"  ❌ {label} — all {iterations} iterations failed")
        RESULTS.append({"label": label, "status": "FAIL", "errors": errors})
        return

    p50 = statistics.median(times_ns)
    p99 = sorted(times_ns)[int(len(times_ns) * 0.99)] if len(times_ns) >= 100 else max(times_ns)
    mean = statistics.mean(times_ns)
    ops_per_sec = 1_000_000_000 / mean if mean > 0 else 0

    print(f"  ✅ {label}")
    print(f"     p50={_fmt_time(p50)}  p99={_fmt_time(p99)}  mean={_fmt_time(mean)}  {_fmt_rate(ops_per_sec)}")
    if errors:
        print(f"     ⚠️  {errors}/{iterations} errors")

    RESULTS.append({
        "label": label,
        "status": "OK",
        "p50_ns": p50,
        "p99_ns": p99,
        "mean_ns": mean,
        "ops_per_sec": ops_per_sec,
        "iterations": len(times_ns),
        "errors": errors,
    })

def section(title: str):
    print()
    print("═" * 70)
    print(f"  {title}")
    print("═" * 70)


# ═══════════════════════════════════════════════════════════════════
# TIER 1: Core Subsystem Latency
# ═══════════════════════════════════════════════════════════════════

def tier1_core():
    section("TIER 1: Core Subsystem Latency")

    # --- 1a. Harmony Vector ---
    print("\n  --- Harmony Vector ---")
    try:
        from whitemagic.harmony.vector import get_harmony_vector
        hv = get_harmony_vector()
        bench("HarmonyVector.snapshot()", lambda: hv.snapshot(), iterations=5000)
        bench("HarmonyVector.snapshot_dict()", lambda: hv.snapshot_dict(), iterations=5000)
    except Exception as e:
        print(f"  ⚠️  Harmony Vector not available: {e}")

    # --- 1b. Circuit Breaker ---
    print("\n  --- Circuit Breaker ---")
    try:
        from whitemagic.tools.circuit_breaker import BreakerRegistry
        cbr = BreakerRegistry()
        cb = cbr.get("test_tool")
        bench("CircuitBreaker.allow('test_tool')", lambda: cb.allow(), iterations=10000)
        bench("CircuitBreaker.record_success()", lambda: cb.record_success(), iterations=10000)
    except Exception as e:
        print(f"  ⚠️  Circuit Breaker not available: {e}")

    # --- 1c. Rate Limiter ---
    print("\n  --- Rate Limiter ---")
    try:
        from whitemagic.tools.rate_limiter import get_rate_limiter
        rl = get_rate_limiter()
        bench("RateLimiter.check('test', 'agent1')", lambda: rl.check("test_tool", "agent_bench"), iterations=5000)
    except Exception as e:
        print(f"  ⚠️  Rate Limiter not available: {e}")

    # --- 1d. Input Sanitizer ---
    print("\n  --- Input Sanitizer ---")
    try:
        from whitemagic.tools.input_sanitizer import sanitize_tool_args
        test_args = {"query": "test search", "limit": 10, "tags": ["a", "b"]}
        bench("sanitize_tool_args(typical args)", lambda: sanitize_tool_args("search_memories", dict(test_args)), iterations=5000)
    except Exception as e:
        print(f"  ⚠️  Input Sanitizer not available: {e}")

    # --- 1e. Dharma Rules ---
    print("\n  --- Dharma Rules Engine ---")
    try:
        from whitemagic.dharma.rules import get_rules_engine
        engine = get_rules_engine()
        bench("DharmaRules.evaluate(action)", lambda: engine.evaluate({"tool_name": "create_memory", "content": "test"}), iterations=3000)
    except Exception as e:
        print(f"  ⚠️  Dharma Rules not available: {e}")

    # --- 1f. Karma Ledger ---
    print("\n  --- Karma Ledger ---")
    try:
        from whitemagic.dharma.karma_ledger import KarmaLedger
        import tempfile
        kl = KarmaLedger(storage_dir=Path(tempfile.mkdtemp()))
        bench("KarmaLedger.record()", lambda: kl.record("test_tool", "read", "read"), iterations=5000)
    except Exception as e:
        print(f"  ⚠️  Karma Ledger not available: {e}")

    # --- 1g. PRAT Router (dry classify) ---
    print("\n  --- PRAT Router ---")
    try:
        from whitemagic.tools.prat_router import TOOL_TO_GANA
        bench("PRAT lookup (dict)", lambda: TOOL_TO_GANA.get("search_memories"), iterations=50000)
    except Exception as e:
        print(f"  ⚠️  PRAT Router not available: {e}")

    # --- 1h. Maturity Gate ---
    print("\n  --- Maturity Gate ---")
    try:
        from whitemagic.tools.maturity_check import check_maturity_for_tool
        bench("maturity_check('search_memories')", lambda: check_maturity_for_tool("search_memories"), iterations=5000)
    except Exception as e:
        print(f"  ⚠️  Maturity Gate not available: {e}")

    # --- 1i. StateBoard (Python fallback) ---
    print("\n  --- StateBoard Bridge ---")
    try:
        from whitemagic.core.acceleration.state_board_bridge import get_state_board
        board = get_state_board()
        bench("StateBoard.read_harmony()", lambda: board.read_harmony(), iterations=5000)
        bench("StateBoard.read_tick()", lambda: board.read_tick(), iterations=10000)
    except Exception as e:
        print(f"  ⚠️  StateBoard not available: {e}")

    # --- 1j. EventRing Bridge ---
    print("\n  --- EventRing Bridge ---")
    try:
        from whitemagic.core.acceleration.event_ring_bridge import get_event_ring
        ring = get_event_ring()
        bench("EventRing.publish('tool_called')", lambda: ring.publish("tool_called", "bench", b"test"), iterations=10000)
    except Exception as e:
        print(f"  ⚠️  EventRing not available: {e}")


# ═══════════════════════════════════════════════════════════════════
# TIER 2: Polyglot Accelerators
# ═══════════════════════════════════════════════════════════════════

def tier2_accelerators():
    section("TIER 2: Polyglot Accelerators")

    # --- 2a. Rust Holographic Encoding ---
    print("\n  --- Rust Holographic Encoding ---")
    try:
        import whitemagic_rs
        import json as _json
        mem_json = _json.dumps({'id': 'bench1', 'title': 'test', 'content': 'benchmark memory', 'tags': ['bench'], 'importance': 0.8, 'memory_type': 'LONG_TERM'})
        bench("Rust holographic_encode_single",
              lambda: whitemagic_rs.holographic_encode_single(mem_json),
              iterations=10000)
        batch_json = _json.dumps([{'id': f'b{i}', 'title': f'test{i}', 'content': f'batch memory {i}', 'tags': ['bench'], 'importance': 0.5, 'memory_type': 'LONG_TERM'} for i in range(100)])
        bench("Rust holographic_encode_batch(100)",
              lambda: whitemagic_rs.holographic_encode_batch(batch_json),
              iterations=1000)
    except ImportError:
        print("  ⚠️  whitemagic_rs not available (Rust accelerators not compiled)")

    # --- 2b. Rust BM25 Search ---
    print("\n  --- Rust BM25 Search ---")
    try:
        import whitemagic_rs
        import json as _json
        docs_json = _json.dumps([{'id': str(i), 'title': f'doc {i}', 'content': f'This is test document number {i} about memory systems and patterns'} for i in range(500)])
        whitemagic_rs.search_build_index(docs_json)
        bench("Rust BM25 search_query (500 docs)",
              lambda: whitemagic_rs.search_query("memory systems", 10),
              iterations=5000)
        bench("Rust BM25 search_fuzzy (500 docs)",
              lambda: whitemagic_rs.search_fuzzy("memry systms", 10, 2),
              iterations=5000)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Rust BM25 not available: {e}")

    # --- 2c. Rust Atomic Rate Limiter ---
    print("\n  --- Rust Atomic Rate Limiter ---")
    try:
        import whitemagic_rs
        import json as _json
        rate_json = _json.dumps({'tool': 'test_tool', 'agent': 'agent_bench'})
        bench("Rust rate_check (atomic)",
              lambda: whitemagic_rs.rate_check(rate_json),
              iterations=50000)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Rust rate limiter not available: {e}")

    # --- 2d. Rust MinHash ---
    print("\n  --- Rust MinHash ---")
    try:
        import whitemagic_rs
        import json as _json
        keyword_sets = [["memory", "search", "pattern", "test", f"unique_{i}"] for i in range(60)]
        sets_json = _json.dumps(keyword_sets)
        bench("Rust MinHash (60 sets, threshold=0.5)",
              lambda: whitemagic_rs.minhash_find_duplicates(sets_json, 0.5, 100),
              iterations=500)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Rust MinHash not available: {e}")

    # --- 2e. Rust Keyword Extract ---
    print("\n  --- Rust Keyword Extraction ---")
    try:
        import whitemagic_rs
        test_text = "WhiteMagic is a cognitive operating system with persistent memory, " * 50
        bench("Rust keyword_extract (3KB text)",
              lambda: whitemagic_rs.keyword_extract(test_text, 20),
              iterations=2000)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Rust keyword extraction not available: {e}")

    # --- 2f-extra. Rust StateBoard (native) ---
    print("\n  --- Rust StateBoard (native PyO3) ---")
    try:
        import whitemagic_rs
        whitemagic_rs.board_write_harmony(1.0, 0.9, 0.1, 0.05, 0.95, 0.02, 0.8)
        bench("Rust board_read_harmony (native)",
              lambda: whitemagic_rs.board_read_harmony(),
              iterations=50000)
        bench("Rust board_write_harmony (native)",
              lambda: whitemagic_rs.board_write_harmony(1.0, 0.9, 0.1, 0.05, 0.95, 0.02, 0.8),
              iterations=50000)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Rust StateBoard not available: {e}")

    # --- 2g-extra. Rust EventRing (native) ---
    print("\n  --- Rust EventRing (native PyO3) ---")
    try:
        import whitemagic_rs
        bench("Rust ring_publish (native)",
              lambda: whitemagic_rs.ring_publish(9, "benchmark_source", 0.95, b"benchmark payload"),
              iterations=50000)
        bench("Rust ring_stats (native)",
              lambda: whitemagic_rs.ring_stats(),
              iterations=10000)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Rust EventRing not available: {e}")

    # --- 2h. Arrow IPC Bridge (v14.5) ---
    print("\n  --- Arrow IPC Bridge (v14.5) ---")
    try:
        import whitemagic_rs
        bench("Arrow roundtrip (100 memories)",
              lambda: whitemagic_rs.arrow_roundtrip_bench(100),
              iterations=500)
        bench("Arrow roundtrip (1000 memories)",
              lambda: whitemagic_rs.arrow_roundtrip_bench(1000),
              iterations=100)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Arrow IPC not available: {e}")

    # --- 2i. Tokio Clone Army (v14.5) ---
    print("\n  --- Tokio Clone Army (v14.5) ---")
    try:
        import whitemagic_rs
        bench("Tokio clone army (100 clones)",
              lambda: whitemagic_rs.tokio_clone_bench(100),
              iterations=50)
        bench("Tokio clone army (1000 clones)",
              lambda: whitemagic_rs.tokio_clone_bench(1000),
              iterations=20)
        bench("Tokio clone army (5000 clones)",
              lambda: whitemagic_rs.tokio_clone_bench(5000),
              iterations=10)
    except (ImportError, AttributeError) as e:
        print(f"  ⚠️  Tokio clones not available: {e}")

    # --- 2f. Zig SIMD Distance Matrix ---
    print("\n  --- Zig SIMD ---")
    try:
        from whitemagic.core.acceleration.simd_distance import zig_distance_matrix, _zig_available
        if _zig_available:
            import random
            random.seed(42)
            vecs = [[random.random() for _ in range(64)] for _ in range(50)]
            bench("Zig SIMD distance_matrix (50×64d)",
                  lambda: zig_distance_matrix(vecs),
                  iterations=200)
        else:
            print("  ⚠️  Zig SIMD .so not loaded")
    except Exception as e:
        print(f"  ⚠️  Zig SIMD not available: {e}")

    # --- 2g. Python fallback comparison ---
    print("\n  --- Python Fallback (baseline) ---")
    import hashlib
    test_text = "WhiteMagic cognitive operating system memory" * 20
    bench("Python hashlib.sha256 (800 chars)",
          lambda: hashlib.sha256(test_text.encode()).hexdigest(),
          iterations=10000)

    # Simple keyword extraction (Python)
    def _py_keywords():
        words = test_text.lower().split()
        stopwords = {"is", "a", "the", "with", "and", "for", "to", "of", "in", "on"}
        return list(set(w for w in words if w not in stopwords and len(w) > 2))[:20]
    bench("Python keyword_extract fallback (800 chars)",
          _py_keywords,
          iterations=5000)


# ═══════════════════════════════════════════════════════════════════
# TIER 3: Swarm & Concurrency
# ═══════════════════════════════════════════════════════════════════

async def tier3_swarm():
    section("TIER 3: Swarm & Concurrency Stress Tests")

    # --- 3a. ThoughtArmy (sync, 4 clones) ---
    print("\n  --- ThoughtArmy (sync, 4 clones) ---")
    try:
        from whitemagic.edge.thought_clones import ThoughtArmy
        army = ThoughtArmy(num_clones=4)
        bench("ThoughtArmy.parallel_explore (4 clones)",
              lambda: army.parallel_explore("What is the meaning of consciousness?"),
              iterations=100, warmup=2)
    except Exception as e:
        print(f"  ⚠️  ThoughtArmy not available: {e}")

    # --- 3b. ThoughtArmy (sync, 16 clones) ---
    print("\n  --- ThoughtArmy (sync, 16 clones) ---")
    try:
        from whitemagic.edge.thought_clones import ThoughtArmy
        army16 = ThoughtArmy(num_clones=16)
        bench("ThoughtArmy.parallel_explore (16 clones)",
              lambda: army16.parallel_explore("Analyze the polyglot architecture"),
              iterations=50, warmup=2)
    except Exception as e:
        print(f"  ⚠️  ThoughtArmy 16 not available: {e}")

    # --- 3c. AsyncThoughtCloneArmy ---
    print("\n  --- AsyncThoughtCloneArmy ---")
    try:
        from whitemagic.edge.thought_clones_async import AsyncThoughtCloneArmy, CloneConfig
        config = CloneConfig(max_clones=100, max_concurrent_api_calls=50, timeout_seconds=5.0)
        async_army = AsyncThoughtCloneArmy(config=config)
        await async_bench("AsyncThoughtArmy (100 clones)",
                          lambda: async_army.parallel_explore("Explore distributed consensus", num_clones=100),
                          iterations=20, warmup=2)
    except Exception as e:
        print(f"  ⚠️  AsyncThoughtCloneArmy not available: {e}")

    # --- 3d. Scale test: 1000 async clones ---
    print("\n  --- Scale: 1000 Async Clones ---")
    try:
        from whitemagic.edge.thought_clones_async import AsyncThoughtCloneArmy, CloneConfig
        config_1k = CloneConfig(max_clones=1000, max_concurrent_api_calls=100, timeout_seconds=10.0)
        army_1k = AsyncThoughtCloneArmy(config=config_1k)
        await async_bench("AsyncThoughtArmy (1000 clones)",
                          lambda: army_1k.parallel_explore("Scale test: thousand minds", num_clones=1000),
                          iterations=5, warmup=1)
    except Exception as e:
        print(f"  ⚠️  1000 clone scale test failed: {e}")

    # --- 3e. Scale test: 5000 async clones ---
    print("\n  --- Scale: 5000 Async Clones ---")
    try:
        from whitemagic.edge.thought_clones_async import AsyncThoughtCloneArmy, CloneConfig
        config_5k = CloneConfig(max_clones=5000, max_concurrent_api_calls=200, timeout_seconds=15.0)
        army_5k = AsyncThoughtCloneArmy(config=config_5k)
        await async_bench("AsyncThoughtArmy (5000 clones)",
                          lambda: army_5k.parallel_explore("Maximum scale test", num_clones=5000),
                          iterations=3, warmup=1)
    except Exception as e:
        print(f"  ⚠️  5000 clone scale test failed: {e}")

    # --- 3f. AgentSwarm decompose + route ---
    print("\n  --- AgentSwarm Protocols ---")
    try:
        from whitemagic.agents.swarm import AgentSwarm
        swarm = AgentSwarm()
        bench("Swarm.decompose(goal)",
              lambda: swarm.decompose("Search memory, analyze patterns, generate report"),
              iterations=500, warmup=5)

        plan = swarm.decompose("Test plan for routing benchmark")
        bench("Swarm.route(plan)",
              lambda: swarm.route(plan.id),
              iterations=200, warmup=2)

        # Vote + resolve
        import uuid
        def _vote_cycle():
            topic = f"topic_{uuid.uuid4().hex[:8]}"
            for i in range(5):
                swarm.vote(topic, f"agent_{i}", f"option_{i % 3}", confidence=0.8)
            swarm.resolve(topic)
        bench("Swarm vote cycle (5 votes + resolve)",
              _vote_cycle,
              iterations=200, warmup=5)
    except Exception as e:
        print(f"  ⚠️  AgentSwarm not available: {e}")

    # --- 3g. CollectiveDreams ---
    print("\n  --- CollectiveDreams ---")
    try:
        from whitemagic.gardens.wonder.collective_dreams import CollectiveDreams
        import tempfile
        with tempfile.TemporaryDirectory() as td:
            dreams = CollectiveDreams(dream_dir=td)
            def _dream_cycle():
                agents = [f"agent_{i}" for i in range(10)]
                dream_id = dreams.begin_collective_dream("benchmark_theme", agents)
                for agent in agents:
                    dreams.contribute_to_dream(dream_id, agent, {"pattern": "test"}, "wonder")
                for i in range(5):
                    dreams.express_resonance(dream_id, i, 0.8)
                dreams.synthesize_dream(dream_id)
            bench("CollectiveDream full cycle (10 agents)",
                  _dream_cycle,
                  iterations=100, warmup=2)
    except Exception as e:
        print(f"  ⚠️  CollectiveDreams not available: {e}")

    # --- 3h. SanghaChat ---
    print("\n  --- SanghaChat ---")
    try:
        from whitemagic.gardens.sangha.chat import SanghaChat
        import tempfile
        with tempfile.TemporaryDirectory() as td:
            chat = SanghaChat(base_dir=Path(td))
            bench("SanghaChat.send_message",
                  lambda: chat.send_message("bench_agent", "Test message", "general"),
                  iterations=200, warmup=5)
            # Read after some writes
            for i in range(50):
                chat.send_message("bench_agent", f"Message {i}", "general")
            bench("SanghaChat.read_messages(50)",
                  lambda: chat.read_messages("general", limit=50),
                  iterations=200, warmup=5)
    except Exception as e:
        print(f"  ⚠️  SanghaChat not available: {e}")

    # --- 3i. Concurrent event publishing ---
    print("\n  --- Concurrent Event Publishing ---")
    try:
        from whitemagic.core.acceleration.event_ring_bridge import get_event_ring
        ring = get_event_ring()
        async def _burst_publish():
            for i in range(100):
                ring.publish("tool_called", f"agent_{i}", f"payload_{i}".encode())
        await async_bench("EventRing burst publish (100 events)",
                          _burst_publish,
                          iterations=50, warmup=2)
    except Exception as e:
        print(f"  ⚠️  EventRing burst not available: {e}")


# ═══════════════════════════════════════════════════════════════════
# SUMMARY
# ═══════════════════════════════════════════════════════════════════

def print_summary():
    section("BENCHMARK SUMMARY")
    ok = [r for r in RESULTS if r["status"] == "OK"]
    fail = [r for r in RESULTS if r["status"] == "FAIL"]

    print(f"\n  Total benchmarks: {len(RESULTS)}")
    print(f"  Passed: {len(ok)}  |  Failed: {len(fail)}")

    if ok:
        # Find fastest and slowest
        fastest = min(ok, key=lambda r: r["mean_ns"])
        slowest = max(ok, key=lambda r: r["mean_ns"])
        highest_throughput = max(ok, key=lambda r: r["ops_per_sec"])

        print(f"\n  🏆 Fastest:    {fastest['label']} — {_fmt_time(fastest['mean_ns'])}")
        print(f"  🐢 Slowest:    {slowest['label']} — {_fmt_time(slowest['mean_ns'])}")
        print(f"  ⚡ Throughput:  {highest_throughput['label']} — {_fmt_rate(highest_throughput['ops_per_sec'])}")

    # Table of all results
    print(f"\n  {'Benchmark':<50} {'p50':>10} {'p99':>10} {'ops/s':>14}")
    print(f"  {'─' * 50} {'─' * 10} {'─' * 10} {'─' * 14}")
    for r in ok:
        print(f"  {r['label']:<50} {_fmt_time(r['p50_ns']):>10} {_fmt_time(r['p99_ns']):>10} {_fmt_rate(r['ops_per_sec']):>14}")

    if fail:
        print("\n  Failed benchmarks:")
        for r in fail:
            print(f"    ❌ {r['label']}")


# ═══════════════════════════════════════════════════════════════════
# MAIN
# ═══════════════════════════════════════════════════════════════════

async def main():
    import argparse
    parser = argparse.ArgumentParser(description="WhiteMagic Benchmark Gauntlet v2")
    parser.add_argument("--tier", type=str, default="all", help="Tier to run: 1, 2, 3, or all")
    args = parser.parse_args()

    print("╔══════════════════════════════════════════════════════════════════╗")
    print("║         WhiteMagic Benchmark Gauntlet v2 — v14.5.0             ║")
    print("╚══════════════════════════════════════════════════════════════════╝")

    tier = args.tier.lower()

    if tier in ("1", "all"):
        tier1_core()

    if tier in ("2", "all"):
        tier2_accelerators()

    if tier in ("3", "all"):
        await tier3_swarm()

    print_summary()


if __name__ == "__main__":
    asyncio.run(main())
