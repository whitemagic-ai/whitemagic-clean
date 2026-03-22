#!/usr/bin/env python3
"""Benchmark the Hybrid Adaptive Dispatcher."""

import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

import statistics
import time

from whitemagic.core.acceleration.hybrid_dispatcher import (
    DispatchMode,
    HybridDispatcher,
)


def benchmark_mode(mode: DispatchMode, operations: int = 1000) -> dict:
    """Benchmark a specific dispatch mode."""
    dispatcher = HybridDispatcher(mode)

    # Warmup
    for _ in range(10):
        dispatcher.prat_route("gnosis")
        dispatcher.get_predecessor("gana_ghost")

    # Benchmark routing
    route_times = []
    for i in range(operations):
        tools = ["gnosis", "search_memories", "health_report", "create_memory"]
        tool = tools[i % len(tools)]
        start = time.perf_counter()
        dispatcher.prat_route(tool)
        route_times.append((time.perf_counter() - start) * 1_000_000)

    # Benchmark resonance
    resonance_times = []
    for i in range(operations):
        ganas = ["gana_ghost", "gana_horn", "gana_dipper", "gana_heart"]
        gana = ganas[i % len(ganas)]
        start = time.perf_counter()
        dispatcher.get_predecessor(gana)
        resonance_times.append((time.perf_counter() - start) * 1_000_000)

    # Benchmark circuit
    circuit_times = []
    for i in range(operations):
        start = time.perf_counter()
        dispatcher.circuit_check()
        circuit_times.append((time.perf_counter() - start) * 1_000_000)

    dispatcher.close()

    return {
        "route_avg_us": statistics.mean(route_times),
        "resonance_avg_us": statistics.mean(resonance_times),
        "circuit_avg_us": statistics.mean(circuit_times),
        "stats": dispatcher.stats(),
    }


def main():
    print("=" * 70)
    print("Hybrid Adaptive Dispatcher Benchmark")
    print("=" * 70)

    operations = 1000

    print(f"\nRunning {operations} operations per mode...\n")

    # Speed mode (Python only)
    print("[SPEED MODE] Python in-memory only")
    speed = benchmark_mode(DispatchMode.SPEED, operations)
    print(f"  PRAT routing:    {speed['route_avg_us']:.3f} µs")
    print(f"  Resonance:       {speed['resonance_avg_us']:.3f} µs")
    print(f"  Circuit:         {speed['circuit_avg_us']:.3f} µs")

    # Safety mode (Koka only)
    print("\n[SAFETY MODE] Koka IPC only")
    safety = benchmark_mode(DispatchMode.SAFETY, operations)
    print(f"  PRAT routing:    {safety['route_avg_us']:.2f} µs ({safety['route_avg_us']/speed['route_avg_us']:.0f}x slower)")
    print(f"  Resonance:       {safety['resonance_avg_us']:.2f} µs ({safety['resonance_avg_us']/speed['resonance_avg_us']:.0f}x slower)")
    print(f"  Circuit:         {safety['circuit_avg_us']:.2f} µs ({safety['circuit_avg_us']/speed['circuit_avg_us']:.0f}x slower)")

    # Adaptive mode (best of both)
    print("\n[ADAPTIVE MODE] Intelligent selection")
    adaptive = benchmark_mode(DispatchMode.ADAPTIVE, operations)
    print(f"  PRAT routing:    {adaptive['route_avg_us']:.3f} µs (Python fast path)")
    print(f"  Resonance:       {adaptive['resonance_avg_us']:.3f} µs (Python fast path)")
    print(f"  Circuit:         {adaptive['circuit_avg_us']:.2f} µs (Koka safe path)")

    # Summary
    print("\n" + "=" * 70)
    print("Summary")
    print("=" * 70)
    print(f"Speed mode:    All operations ~{speed['route_avg_us']:.2f} µs (pure Python)")
    print(f"Safety mode:   All operations ~{safety['route_avg_us']:.0f} µs (pure Koka)")
    print(f"Adaptive mode: Simple ~{adaptive['route_avg_us']:.2f} µs, Complex ~{adaptive['circuit_avg_us']:.0f} µs")

    print("\nRecommendation:")
    print("  - Use SPEED for high-throughput simple operations")
    print("  - Use SAFETY for type-safe stateful operations")
    print("  - Use ADAPTIVE (default) for best of both worlds")

    # Show adaptive stats
    print(f"\nAdaptive dispatch stats: {adaptive['stats']}")


if __name__ == "__main__":
    main()
