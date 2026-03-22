#!/usr/bin/env python3
"""Koka Hot Path Benchmark Suite (S023)
=======================================
Benchmarks Python vs Koka native performance for core operations.

Usage:
    scripts/benchmark_koka_v023.py [--iterations N] [--output json|md]
"""
from __future__ import annotations

import argparse
import json
import sys
import time
from typing import Any

# Add whitemagic to path
sys.path.insert(0, "/home/lucas/Desktop/whitemagicdev")

from whitemagic.core.acceleration.koka_native_bridge import (
    benchmark_koka_dispatch,
    koka_native_status,
)
from whitemagic.tools.prat_resonance import _GANA_META
from whitemagic.tools.prat_router import TOOL_TO_GANA


class PythonBaseline:
    """Python implementations for baseline comparison."""

    @staticmethod
    def prat_dispatch(tool_name: str, context: dict) -> dict:
        """Simulate PRAT router dispatch."""
        gana = TOOL_TO_GANA.get(tool_name, "gana_horn")
        return {
            "gana": gana,
            "tool": tool_name,
            "status": "dispatched",
            "context": context
        }

    @staticmethod
    def gana_invoke(gana_name: str, operation: str, args: dict) -> dict:
        """Simulate Gana handler invocation."""
        meta = _GANA_META.get(gana_name, (0, "Unknown", "Unknown", "None"))
        return {
            "gana": gana_name,
            "mansion": meta[0],
            "quadrant": meta[1],
            "operation": operation,
            "result": "success"
        }

    @staticmethod
    def resonance_tracking(gana_name: str) -> dict:
        """Simulate resonance state tracking."""
        idx = list(_GANA_META.keys()).index(gana_name) if gana_name in _GANA_META else 0
        predecessor = list(_GANA_META.keys())[(idx - 1) % 28]
        successor = list(_GANA_META.keys())[(idx + 1) % 28]

        return {
            "gana": gana_name,
            "predecessor": predecessor,
            "successor": successor,
            "lunar_phase": 0.5,
            "harmony_score": 0.95
        }

    @staticmethod
    def circuit_check(name: str, failures: int = 0) -> dict:
        """Simulate circuit breaker check."""
        threshold = 5
        state = "closed" if failures < threshold else "open"
        return {
            "circuit": name,
            "state": state,
            "failures": failures,
            "threshold": threshold
        }

    @staticmethod
    def gana_chain(gana_names: list[str]) -> dict:
        """Simulate 28-Gana chain execution."""
        results = []
        for gana in gana_names:
            result = PythonBaseline.gana_invoke(gana, "process", {})
            results.append(result)

        return {
            "chain_length": len(gana_names),
            "results": results,
            "completed": True
        }


def benchmark_python(
    func,
    args: tuple,
    iterations: int = 1000
) -> dict[str, float]:
    """Benchmark a Python function."""
    # Warmup
    for _ in range(10):
        func(*args)

    latencies = []
    for _ in range(iterations):
        start = time.perf_counter()
        func(*args)
        elapsed = (time.perf_counter() - start) * 1_000_000  # microseconds
        latencies.append(elapsed)

    latencies.sort()
    n = len(latencies)

    return {
        "iterations": n,
        "min_us": latencies[0],
        "max_us": latencies[-1],
        "avg_us": sum(latencies) / n,
        "p50_us": latencies[n // 2],
        "p95_us": latencies[int(n * 0.95)],
        "p99_us": latencies[int(n * 0.99)],
    }


def run_benchmarks(iterations: int = 1000) -> dict[str, Any]:
    """Run complete benchmark suite."""
    results = {
        "timestamp": time.time(),
        "iterations": iterations,
        "python": {},
        "koka": {},
        "comparison": {},
        "koka_status": koka_native_status()
    }

    print("=" * 60)
    print("Koka Hot Path Benchmark Suite (S023)")
    print("=" * 60)
    print(f"Iterations: {iterations}")
    print()

    # 1. PRAT Dispatch
    print("1. PRAT Dispatch Benchmark...")
    py_result = benchmark_python(
        PythonBaseline.prat_dispatch,
        ("memory.create", {"content": "test"}),
        iterations
    )
    results["python"]["prat_dispatch"] = py_result
    print(f"   Python: {py_result['avg_us']:.2f} µs avg, {py_result['p95_us']:.2f} µs p95")

    # Try Koka if available
    koka_result = benchmark_koka_dispatch(
        "prat", "route-prat-call",
        {"tool": "memory.create", "args": {}},
        iterations=iterations
    )
    results["koka"]["prat_dispatch"] = koka_result

    if "error" not in koka_result:
        print(f"   Koka:   {koka_result['avg_us']:.2f} µs avg, {koka_result['p95_us']:.2f} µs p95")
        ratio = koka_result['avg_us'] / py_result['avg_us']
        results["comparison"]["prat_dispatch"] = {
            "ratio": ratio,
            "winner": "koka" if ratio < 1.0 else "python"
        }
        print(f"   Ratio:  {ratio:.2f}x")
    else:
        print(f"   Koka:   unavailable ({koka_result['error']})")
    print()

    # 2. Gana Handler Invoke
    print("2. Gana Handler Invoke...")
    py_result = benchmark_python(
        PythonBaseline.gana_invoke,
        ("gana_horn", "bootstrap", {}),
        iterations
    )
    results["python"]["gana_invoke"] = py_result
    print(f"   Python: {py_result['avg_us']:.2f} µs avg")

    koka_result = benchmark_koka_dispatch(
        "gana", "invoke-gana",
        {"gana": "gana_horn", "tool": "bootstrap", "args": {}},
        iterations=iterations
    )
    results["koka"]["gana_invoke"] = koka_result

    if "error" not in koka_result:
        print(f"   Koka:   {koka_result['avg_us']:.2f} µs avg")
        ratio = koka_result['avg_us'] / py_result['avg_us']
        results["comparison"]["gana_invoke"] = {"ratio": ratio, "winner": "koka" if ratio < 1.0 else "python"}
        print(f"   Ratio:  {ratio:.2f}x")
    else:
        print("   Koka:   unavailable")
    print()

    # 3. Resonance Tracking
    print("3. Resonance Tracking...")
    py_result = benchmark_python(
        PythonBaseline.resonance_tracking,
        ("gana_ghost",),
        iterations
    )
    results["python"]["resonance"] = py_result
    print(f"   Python: {py_result['avg_us']:.2f} µs avg")

    koka_result = benchmark_koka_dispatch(
        "resonance", "track-prat-invocation",
        {"gana": "gana_ghost", "tool": "gnosis", "operation": "query", "output": "result"},
        iterations=iterations
    )
    results["koka"]["resonance"] = koka_result

    if "error" not in koka_result:
        print(f"   Koka:   {koka_result['avg_us']:.2f} µs avg")
        ratio = koka_result['avg_us'] / py_result['avg_us']
        results["comparison"]["resonance"] = {"ratio": ratio, "winner": "koka" if ratio < 1.0 else "python"}
        print(f"   Ratio:  {ratio:.2f}x")
    else:
        print("   Koka:   unavailable")
    print()

    # 4. Circuit Breaker
    print("4. Circuit Breaker Check...")
    py_result = benchmark_python(
        PythonBaseline.circuit_check,
        ("memory-ops", 2),
        iterations
    )
    results["python"]["circuit"] = py_result
    print(f"   Python: {py_result['avg_us']:.2f} µs avg")

    koka_result = benchmark_koka_dispatch(
        "circuit", "check-circuit",
        {"name": "memory-ops"},
        iterations=iterations
    )
    results["koka"]["circuit"] = koka_result

    if "error" not in koka_result:
        print(f"   Koka:   {koka_result['avg_us']:.2f} µs avg")
        ratio = koka_result['avg_us'] / py_result['avg_us']
        results["comparison"]["circuit"] = {"ratio": ratio, "winner": "koka" if ratio < 1.0 else "python"}
        print(f"   Ratio:  {ratio:.2f}x")
    else:
        print("   Koka:   unavailable")
    print()

    # 5. 28-Gana Chain (smaller iteration count)
    print("5. 28-Gana Chain...")
    gana_list = list(_GANA_META.keys())[:28]
    chain_iterations = min(100, iterations // 10)  # Fewer iterations for chains

    py_result = benchmark_python(
        PythonBaseline.gana_chain,
        (gana_list,),
        chain_iterations
    )
    results["python"]["gana_chain"] = py_result
    print(f"   Python: {py_result['avg_us']:.2f} µs avg ({py_result['avg_us']/28:.2f} µs per gana)")

    # Chain benchmark via Koka would need composed handler
    # For now, mark as needing implementation
    results["koka"]["gana_chain"] = {"error": "Chain composition not yet implemented in native bridge"}
    print("   Koka:   not yet implemented")
    print()

    # Summary
    print("=" * 60)
    print("Summary")
    print("=" * 60)

    available_comparisons = [k for k, v in results["comparison"].items() if "ratio" in v]
    if available_comparisons:
        avg_ratio = sum(results["comparison"][k]["ratio"] for k in available_comparisons) / len(available_comparisons)
        koka_wins = sum(1 for k in available_comparisons if results["comparison"][k]["winner"] == "koka")

        print(f"Operations tested: {len(available_comparisons)}")
        print(f"Koka faster: {koka_wins}/{len(available_comparisons)}")
        print(f"Average ratio (Koka/Python): {avg_ratio:.2f}x")

        if avg_ratio < 1.0:
            print("Result: Koka is faster on average ✓")
        elif avg_ratio < 2.0:
            print("Result: Koka within 2x - acceptable for FFI overhead")
        else:
            print("Result: Koka significantly slower - needs optimization")
    else:
        print("No Koka binaries available for comparison")
        print("Run build_native.sh first to compile Koka effects")

    return results


def generate_markdown_report(results: dict) -> str:
    """Generate Markdown report from benchmark results."""
    lines = [
        "# S023: Koka Hot Path Benchmark Results",
        "",
        f"**Date:** {time.strftime('%Y-%m-%d %H:%M:%S')}",
        f"**Iterations:** {results['iterations']}",
        "",
        "## Koka Status",
        "",
        f"- Available modules: {', '.join(results['koka_status'].get('available_modules', [])) or 'None'}",
        "",
        "## Benchmark Results",
        "",
        "| Operation | Python (µs) | Koka (µs) | Ratio | Winner |",
        "|-----------|-------------|-----------|-------|--------|",
    ]

    for op in ['prat_dispatch', 'gana_invoke', 'resonance', 'circuit', 'gana_chain']:
        py_data = results['python'].get(op, {})
        koka_data = results['koka'].get(op, {})
        comp = results['comparison'].get(op, {})

        py_avg = py_data.get('avg_us', 0)
        koka_avg = koka_data.get('avg_us', 'N/A')
        ratio = comp.get('ratio', 'N/A')
        winner = comp.get('winner', 'N/A')

        if isinstance(koka_avg, float):
            lines.append(f"| {op} | {py_avg:.2f} | {koka_avg:.2f} | {ratio if isinstance(ratio, str) else f'{ratio:.2f}'}x | {winner} |")
        else:
            lines.append(f"| {op} | {py_avg:.2f} | N/A | N/A | python |")

    lines.extend([
        "",
        "## Interpretation",
        "",
        "- Ratio < 1.0: Koka is faster",
        "- Ratio 1.0-2.0: Koka within acceptable FFI overhead",
        "- Ratio > 2.0: Koka needs optimization or caching",
        "",
        "## Notes",
        "",
        "- Python baseline uses optimized in-memory operations",
        "- Koka includes JSON serialization + subprocess communication overhead",
        "- Chains should favor Koka due to handler optimization within single process",
    ])

    return '\n'.join(lines)


def main():
    parser = argparse.ArgumentParser(description="Koka Hot Path Benchmarks")
    parser.add_argument("--iterations", "-i", type=int, default=1000,
                        help="Number of iterations per benchmark")
    parser.add_argument("--output", "-o", choices=["json", "md"], default="md",
                        help="Output format")
    parser.add_argument("--save", "-s", type=str, default=None,
                        help="Save results to file")

    args = parser.parse_args()

    # Run benchmarks
    results = run_benchmarks(iterations=args.iterations)

    # Output
    if args.output == "json":
        output = json.dumps(results, indent=2)
    else:
        output = generate_markdown_report(results)

    # Save or print
    if args.save:
        with open(args.save, 'w') as f:
            f.write(output)
        print(f"\nResults saved to: {args.save}")
    else:
        if args.output == "md":
            print("\n" + output)


if __name__ == "__main__":
    main()
