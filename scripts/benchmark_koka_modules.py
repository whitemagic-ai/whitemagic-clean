#!/usr/bin/env python3
"""Benchmark all ported Koka modules vs Python implementations."""

import json
import statistics
import subprocess
import time
from pathlib import Path

KOKA_DIR = Path("/home/lucas/Desktop/whitemagicdev/whitemagic-koka")

def benchmark_koka_persistent(binary_name: str, requests: list[dict], warmup: int = 3) -> dict:
    """Benchmark a Koka binary with persistent IPC process."""
    binary_path = KOKA_DIR / binary_name
    if not binary_path.exists():
        return {"error": f"Binary not found: {binary_path}"}

    # Warmup
    proc = subprocess.Popen(
        [str(binary_path)],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    for _ in range(warmup):
        proc.stdin.write('{"op":"status"}\n')
        proc.stdin.flush()
        proc.stdout.readline()

    # Benchmark
    latencies = []
    for req in requests:
        start = time.perf_counter()
        proc.stdin.write(json.dumps(req) + '\n')
        proc.stdin.flush()
        proc.stdout.readline()
        latencies.append((time.perf_counter() - start) * 1_000_000)  # microseconds

    proc.terminate()

    return {
        "avg_us": statistics.mean(latencies),
        "min_us": min(latencies),
        "max_us": max(latencies),
        "p50_us": statistics.median(latencies),
        "samples": len(latencies)
    }

def benchmark_python_dict_lookup(operations: int = 1000) -> dict:
    """Benchmark Python dict lookup (baseline for PRAT routing)."""
    tool_to_gana = {
        "search_memories": "gana_winnowing_basket",
        "gnosis": "gana_ghost",
        "health_report": "gana_horn",
        "create_memory": "gana_heart",
        "cluster_stats": "gana_dipper",
    }

    tools = list(tool_to_gana.keys())
    latencies = []

    for i in range(operations):
        tool = tools[i % len(tools)]
        start = time.perf_counter()
        _ = tool_to_gana[tool]
        latencies.append((time.perf_counter() - start) * 1_000_000)

    return {
        "avg_us": statistics.mean(latencies),
        "min_us": min(latencies),
        "max_us": max(latencies),
        "p50_us": statistics.median(latencies),
        "samples": operations
    }

def benchmark_python_circuit_breaker(operations: int = 1000) -> dict:
    """Benchmark Python circuit breaker simulation."""
    latencies = []
    state = {"failures": 0, "state": "closed", "threshold": 5}

    for i in range(operations):
        start = time.perf_counter()
        # Check state
        if state["state"] == "closed":
            if state["failures"] >= state["threshold"]:
                state["state"] = "open"
        # Record result
        if i % 10 == 0:
            state["failures"] += 1
        latencies.append((time.perf_counter() - start) * 1_000_000)

    return {
        "avg_us": statistics.mean(latencies),
        "min_us": min(latencies),
        "max_us": max(latencies),
        "p50_us": statistics.median(latencies),
        "samples": operations
    }

def benchmark_python_resonance(operations: int = 1000) -> dict:
    """Benchmark Python resonance/predecessor lookup."""
    gana_order = [f"gana_{i}" for i in ["horn", "neck", "root", "room", "heart",
                                          "tail", "winnowing_basket", "ghost"]]

    latencies = []
    for i in range(operations):
        gana = gana_order[i % len(gana_order)]
        start = time.perf_counter()
        idx = gana_order.index(gana)
        gana_order[(idx - 1) % len(gana_order)]
        gana_order[(idx + 1) % len(gana_order)]
        latencies.append((time.perf_counter() - start) * 1_000_000)

    return {
        "avg_us": statistics.mean(latencies),
        "min_us": min(latencies),
        "max_us": max(latencies),
        "p50_us": statistics.median(latencies),
        "samples": operations
    }

def main():
    print("=" * 60)
    print("Koka Module Benchmark Suite")
    print("=" * 60)

    operations = 1000

    # Python baselines
    print("\n[Python Baselines]")

    py_prat = benchmark_python_dict_lookup(operations)
    print(f"  PRAT routing (dict lookup): {py_prat['avg_us']:.2f} µs avg")

    py_circuit = benchmark_python_circuit_breaker(operations)
    print(f"  Circuit breaker: {py_circuit['avg_us']:.2f} µs avg")

    py_resonance = benchmark_python_resonance(operations)
    print(f"  Resonance lookup: {py_resonance['avg_us']:.2f} µs avg")

    # Koka modules
    print("\n[Koka Persistent IPC]")

    # PRAT
    prat_requests = [{"op": "check", "tool": "gnosis"} for _ in range(operations)]
    koka_prat = benchmark_koka_persistent("prat", prat_requests)
    if "error" not in koka_prat:
        print(f"  PRAT router: {koka_prat['avg_us']:.2f} µs avg ({koka_prat['avg_us']/py_prat['avg_us']:.1f}x Python)")
    else:
        print(f"  PRAT router: {koka_prat['error']}")

    # Circuit
    circuit_requests = [{"op": "check"} for _ in range(operations)]
    koka_circuit = benchmark_koka_persistent("circuit", circuit_requests)
    if "error" not in koka_circuit:
        print(f"  Circuit breaker: {koka_circuit['avg_us']:.2f} µs avg ({koka_circuit['avg_us']/py_circuit['avg_us']:.1f}x Python)")
    else:
        print(f"  Circuit breaker: {koka_circuit['error']}")

    # Resonance
    resonance_requests = [{"op": "predecessor", "gana": "gana_ghost"} for _ in range(operations)]
    koka_resonance = benchmark_koka_persistent("resonance", resonance_requests)
    if "error" not in koka_resonance:
        print(f"  Resonance: {koka_resonance['avg_us']:.2f} µs avg ({koka_resonance['avg_us']/py_resonance['avg_us']:.1f}x Python)")
    else:
        print(f"  Resonance: {koka_resonance['error']}")

    # Dream cycle
    dream_requests = [{"op": "status"} for _ in range(operations)]
    koka_dream = benchmark_koka_persistent("dream_cycle", dream_requests)
    if "error" not in koka_dream:
        print(f"  Dream cycle: {koka_dream['avg_us']:.2f} µs avg")
    else:
        print(f"  Dream cycle: {koka_dream['error']}")

    # Summary
    print("\n" + "=" * 60)
    print("Summary")
    print("=" * 60)
    print(f"Python in-memory operations: ~{py_prat['avg_us']:.2f} µs")
    print(f"Koka persistent IPC: ~{koka_prat.get('avg_us', 0):.2f} µs")
    print(f"Overhead factor: {koka_prat.get('avg_us', 0)/py_prat['avg_us']:.1f}x")
    print("\nNote: Koka IPC overhead is expected for process communication.")
    print("Benefits come from effect handling, type safety, and single-process chaining.")

if __name__ == "__main__":
    main()
