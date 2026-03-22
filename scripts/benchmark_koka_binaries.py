#!/usr/bin/env python3
"""Comprehensive Koka Binary Benchmark Suite

Benchmarks all Koka binaries and compares performance characteristics.
"""

import json
import statistics
import subprocess
import time
from dataclasses import dataclass
from pathlib import Path
from typing import Any


@dataclass
class BenchmarkResult:
    binary: str
    operation: str
    count: int
    total_ms: float
    avg_ms: float
    throughput: float
    ops_per_sec: float


class KokaBenchmarkSuite:
    """Benchmark all Koka binaries."""

    def __init__(self, koka_dir: Path):
        self.koka_dir = Path(koka_dir)
        self.results: list[BenchmarkResult] = []

    def run_ipc_benchmark(self, binary: str, commands: list[str], warmup: int = 10) -> BenchmarkResult:
        """Run IPC benchmark on a binary."""
        binary_path = self.koka_dir / binary

        if not binary_path.exists():
            return BenchmarkResult(binary, "ipc", 0, 0, 0, 0, 0)

        # Warmup
        for _ in range(warmup):
            proc = subprocess.Popen(
                [str(binary_path)],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                text=True
            )
            proc.stdin.write('{"op":"status"}\n')
            proc.stdin.flush()
            proc.stdout.readline()
            proc.stdin.write('{"op":"quit"}\n')
            proc.stdin.flush()
            proc.wait()

        # Benchmark
        start = time.perf_counter()

        proc = subprocess.Popen(
            [str(binary_path)],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            text=True
        )

        # Read startup message
        proc.stdout.readline()

        # Send commands
        for cmd in commands:
            proc.stdin.write(cmd + '\n')
            proc.stdin.flush()
            proc.stdout.readline()

        # Quit
        proc.stdin.write('{"op":"quit"}\n')
        proc.stdin.flush()
        proc.wait()

        elapsed_ms = (time.perf_counter() - start) * 1000

        return BenchmarkResult(
            binary=binary,
            operation="ipc",
            count=len(commands),
            total_ms=elapsed_ms,
            avg_ms=elapsed_ms / len(commands) if commands else 0,
            throughput=len(commands) / (elapsed_ms / 1000) if elapsed_ms > 0 else 0,
            ops_per_sec=len(commands) / (elapsed_ms / 1000) if elapsed_ms > 0 else 0
        )

    def benchmark_unified_runtime_v3(self) -> list[BenchmarkResult]:
        """Benchmark unified_runtime_v3."""
        results = []

        # Single commands
        single_cmds = ['{"op":"status"}'] * 100
        results.append(self.run_ipc_benchmark("unified_runtime_v3", single_cmds))

        # Batch commands
        batch_cmds = ['{"op":"batch","cmds":[{"op":"emit"},{"op":"emit"},{"op":"emit"}]}'] * 50
        results.append(self.run_ipc_benchmark("unified_runtime_v3", batch_cmds))

        return results

    def benchmark_effect_runtime(self) -> list[BenchmarkResult]:
        """Benchmark effect_runtime."""
        results = []

        # Emit operations
        emit_cmds = ['{"op":"emit","event":"memory_created"}'] * 100
        results.append(self.run_ipc_benchmark("effect_runtime", emit_cmds))

        # Cascade operations
        cascade_cmds = ['{"op":"cascade","event":"threat_detected"}'] * 100
        results.append(self.run_ipc_benchmark("effect_runtime", cascade_cmds))

        return results

    def benchmark_ring_buffer(self) -> list[BenchmarkResult]:
        """Benchmark ring_buffer."""
        results = []

        # Single writes
        write_cmds = ['{"op":"write"}'] * 100
        results.append(self.run_ipc_benchmark("ring_buffer", write_cmds))

        # Batch writes
        batch_cmds = ['{"op":"batch_write","count":10}'] * 50
        results.append(self.run_ipc_benchmark("ring_buffer", batch_cmds))

        return results

    def benchmark_rust_bridge(self) -> list[BenchmarkResult]:
        """Benchmark rust_bridge."""
        results = []

        # Cosine operations
        cosine_cmds = ['{"op":"cosine"}'] * 100
        results.append(self.run_ipc_benchmark("rust_bridge", cosine_cmds))

        # Batch operations
        batch_cmds = ['{"op":"batch"}'] * 50
        results.append(self.run_ipc_benchmark("rust_bridge", batch_cmds))

        return results

    def benchmark_legacy_binaries(self) -> list[BenchmarkResult]:
        """Benchmark older binaries for comparison."""
        results = []

        binaries = ["gan_ying", "prat", "hot_paths", "resonance", "circuit", "dream_cycle"]

        for binary in binaries:
            binary_path = self.koka_dir / binary
            if binary_path.exists():
                # Simple status check
                result = self.run_ipc_benchmark(binary, ['{"op":"status"}'] * 10, warmup=1)
                if result.count > 0:
                    results.append(result)

        return results

    def run_all_benchmarks(self) -> dict[str, Any]:
        """Run complete benchmark suite."""
        print("=" * 70)
        print("KOKA BINARY BENCHMARK SUITE")
        print("=" * 70)

        # New binaries (this session)
        print("\n--- New Binaries (Phases 1-6) ---")
        self.results.extend(self.benchmark_unified_runtime_v3())
        self.results.extend(self.benchmark_effect_runtime())
        self.results.extend(self.benchmark_ring_buffer())
        self.results.extend(self.benchmark_rust_bridge())

        # Legacy binaries
        print("\n--- Legacy Binaries ---")
        self.results.extend(self.benchmark_legacy_binaries())

        return self.generate_report()

    def generate_report(self) -> dict[str, Any]:
        """Generate benchmark report."""
        report = {
            "timestamp": time.strftime("%Y-%m-%d %H:%M:%S"),
            "total_binaries": len(set(r.binary for r in self.results)),
            "total_operations": sum(r.count for r in self.results),
            "binaries": {}
        }

        # Group by binary
        for binary in set(r.binary for r in self.results):
            binary_results = [r for r in self.results if r.binary == binary]
            report["binaries"][binary] = {
                "operations": [
                    {
                        "op": r.operation,
                        "count": r.count,
                        "total_ms": round(r.total_ms, 2),
                        "avg_ms": round(r.avg_ms, 4),
                        "ops_per_sec": round(r.ops_per_sec, 0)
                    }
                    for r in binary_results
                ],
                "best_throughput": round(max(r.ops_per_sec for r in binary_results), 0) if binary_results else 0
            }

        # Overall stats
        all_throughputs = [r.ops_per_sec for r in self.results if r.ops_per_sec > 0]
        if all_throughputs:
            report["overall"] = {
                "avg_throughput": round(statistics.mean(all_throughputs), 0),
                "max_throughput": round(max(all_throughputs), 0),
                "min_throughput": round(min(all_throughputs), 0)
            }

        return report

    def print_report(self, report: dict[str, Any]):
        """Print formatted report."""
        print("\n" + "=" * 70)
        print("BENCHMARK RESULTS")
        print("=" * 70)

        for binary, data in report["binaries"].items():
            print(f"\n{binary}:")
            for op in data["operations"]:
                print(f"  {op['op']}: {op['count']} ops, {op['total_ms']:.1f}ms total, "
                      f"{op['avg_ms']:.3f}ms avg, {op['ops_per_sec']:.0f} ops/sec")
            print(f"  → Best: {data['best_throughput']:.0f} ops/sec")

        if "overall" in report:
            print(f"\n{'='*70}")
            print(f"Overall: Avg={report['overall']['avg_throughput']:.0f} "
                  f"Max={report['overall']['max_throughput']:.0f} "
                  f"Min={report['overall']['min_throughput']:.0f} ops/sec")

        print("=" * 70)


def main():
    """Run benchmark suite."""
    koka_dir = Path(__file__).parent.parent / "whitemagic-koka"

    suite = KokaBenchmarkSuite(koka_dir)
    report = suite.run_all_benchmarks()
    suite.print_report(report)

    # Save JSON report
    report_path = Path(__file__).parent.parent / "reports" / "koka_benchmark_results.json"
    report_path.parent.mkdir(exist_ok=True)
    with open(report_path, "w") as f:
        json.dump(report, f, indent=2)
    print(f"\nReport saved to: {report_path}")


if __name__ == "__main__":
    main()
