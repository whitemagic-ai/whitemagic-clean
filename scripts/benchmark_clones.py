#!/usr/bin/env python3
"""
Benchmark Clone Army Throughput
Validate the 10.2M clones/sec claim with real measurements
"""

import statistics
import time


def benchmark_clone_throughput(clone_count: int, iterations: int = 5) -> list[float]:
    """Benchmark clone army deployment"""
    try:
        import whitemagic_rs
    except ImportError:
        print("❌ whitemagic_rs not available - need to build Rust bridge")
        return []

    throughputs = []

    print(f"\n🔬 Benchmarking {clone_count:,} clones × {iterations} iterations...")

    for i in range(iterations):
        start = time.time()
        whitemagic_rs.spawn_clone_army(clone_count, f"benchmark_{i}")
        duration = time.time() - start

        throughput = clone_count / duration
        throughputs.append(throughput)

        print(f"  Iteration {i+1}: {throughput:,.0f} clones/sec ({duration:.4f}s)")

    return throughputs

def main():
    """Run clone throughput benchmarks"""
    print("\n" + "="*70)
    print("🚀 CLONE ARMY THROUGHPUT BENCHMARK")
    print("="*70)

    # Test different scales
    scales = [
        (10_000, "10K"),
        (100_000, "100K"),
        (1_000_000, "1M"),
        (10_000_000, "10M"),
    ]

    results = {}

    for count, label in scales:
        print(f"\n📊 Testing {label} clones...")
        throughputs = benchmark_clone_throughput(count, iterations=3)

        if throughputs:
            results[label] = {
                'count': count,
                'mean': statistics.mean(throughputs),
                'median': statistics.median(throughputs),
                'stdev': statistics.stdev(throughputs) if len(throughputs) > 1 else 0,
                'min': min(throughputs),
                'max': max(throughputs)
            }

    # Summary
    print("\n" + "="*70)
    print("📊 BENCHMARK SUMMARY")
    print("="*70)

    if not results:
        print("\n❌ No results - Rust bridge not available")
        print("\nTo build Rust bridge:")
        print("  cd whitemagic-rust")
        print("  maturin develop --release")
        return

    print(f"\n{'Scale':<10} {'Mean':<15} {'Median':<15} {'StdDev':<15}")
    print("-" * 70)

    for label, data in results.items():
        mean = data['mean']
        median = data['median']
        stdev = data['stdev']

        print(f"{label:<10} {mean:>13,.0f}/s {median:>13,.0f}/s {stdev:>13,.0f}/s")

    # Validate 10.2M claim
    if '10M' in results:
        measured = results['10M']['mean']
        claimed = 10_200_000
        ratio = measured / claimed

        print("\n🎯 Validation:")
        print(f"  Claimed:  {claimed:>13,}/s")
        print(f"  Measured: {measured:>13,.0f}/s")
        print(f"  Ratio:    {ratio:>13.2f}×")

        if ratio >= 0.8:
            print("\n✅ CLAIM VALIDATED (within 20%)")
        else:
            print(f"\n⚠️  CLAIM OVERSTATED (measured {ratio*100:.0f}% of claimed)")

if __name__ == '__main__':
    main()
