#!/usr/bin/env python3
"""
BENCHMARK WM1 VS WM2
====================
Comprehensive performance comparison
"""

import json
import time
from datetime import UTC, datetime
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent

print("=" * 80)
print("BENCHMARKING WM1 VS WM2")
print("=" * 80)
print()

def benchmark_serialization():
    """Benchmark serialization performance."""
    print("📊 Serialization Benchmark")
    print()

    test_data = {
        "name": "test_component",
        "value": 42,
        "items": list(range(100)),
        "nested": {"key": "value"},
    }

    # WM1 (stdlib json)
    import json as stdlib_json

    wm1_times = []
    for _ in range(1000):
        start = time.perf_counter()
        stdlib_json.dumps(test_data)
        wm1_times.append(time.perf_counter() - start)

    wm1_avg = sum(wm1_times) / len(wm1_times) * 1000000  # microseconds

    # WM2 (orjson if available)
    try:
        import orjson

        wm2_times = []
        for _ in range(1000):
            start = time.perf_counter()
            orjson.dumps(test_data)
            wm2_times.append(time.perf_counter() - start)

        wm2_avg = sum(wm2_times) / len(wm2_times) * 1000000  # microseconds
        speedup = wm1_avg / wm2_avg

        print(f"   WM1 (stdlib): {wm1_avg:.2f} μs")
        print(f"   WM2 (orjson): {wm2_avg:.2f} μs")
        print(f"   Speedup: {speedup:.2f}x")
        print()

        return {
            "wm1_us": wm1_avg,
            "wm2_us": wm2_avg,
            "speedup": speedup,
        }
    except ImportError:
        print(f"   WM1 (stdlib): {wm1_avg:.2f} μs")
        print("   WM2: Not available (orjson not installed)")
        print()
        return {"wm1_us": wm1_avg, "wm2_us": None, "speedup": None}

def benchmark_code_size():
    """Benchmark code size reduction."""
    print("📊 Code Size Benchmark")
    print()

    def count_loc(directory: Path, pattern: str = "*.py") -> int:
        total = 0
        for file in directory.rglob(pattern):
            try:
                total += len(file.read_text(encoding='utf-8').splitlines())
            except Exception:
                pass
        return total

    wm1_loc = count_loc(PROJECT_ROOT / "whitemagic")
    wm2_loc = count_loc(Path.home() / "Desktop" / "WM2")

    reduction = (wm1_loc - wm2_loc) / wm1_loc * 100

    print(f"   WM1: {wm1_loc:,} LOC")
    print(f"   WM2: {wm2_loc:,} LOC")
    print(f"   Reduction: {reduction:.2f}%")
    print()

    return {
        "wm1_loc": wm1_loc,
        "wm2_loc": wm2_loc,
        "reduction_pct": reduction,
    }

def benchmark_memory_usage():
    """Benchmark memory usage."""
    print("📊 Memory Usage Benchmark")
    print()

    try:
        import os

        import psutil

        process = psutil.Process(os.getpid())
        memory_mb = process.memory_info().rss / 1024 / 1024

        print(f"   Current process: {memory_mb:.2f} MB")
        print()

        return {"memory_mb": memory_mb}
    except ImportError:
        print("   ⚠️  psutil not available")
        print()
        return {"memory_mb": None}

def main():
    results = {
        "timestamp": datetime.now(UTC).isoformat(),
        "serialization": benchmark_serialization(),
        "code_size": benchmark_code_size(),
        "memory": benchmark_memory_usage(),
    }

    # Save results
    results_path = PROJECT_ROOT / "reports" / "wm1_vs_wm2_benchmark.json"
    results_path.write_text(json.dumps(results, indent=2))

    print("=" * 80)
    print("BENCHMARK SUMMARY")
    print("=" * 80)

    if results["serialization"].get("speedup"):
        print(f"Serialization speedup: {results['serialization']['speedup']:.2f}x")

    print(f"Code reduction: {results['code_size']['reduction_pct']:.2f}%")

    if results["memory"].get("memory_mb"):
        print(f"Memory usage: {results['memory']['memory_mb']:.2f} MB")

    print()
    print(f"📄 Full report: {results_path}")
    print()
    print("✅ Benchmark complete!")

if __name__ == "__main__":
    main()
