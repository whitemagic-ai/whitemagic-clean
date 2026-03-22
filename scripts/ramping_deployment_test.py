#!/home/lucas/Desktop/whitemagicdev/.venv/bin/python3
"""
Ramping Deployment Test - Find Optimal Force Composition
=========================================================

Test increasing clone counts to find optimal deployment size and composition
for different types of campaigns.

Scales tested: 1K, 5K, 10K, 25K, 50K, 100K
"""

import asyncio
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))



async def test_scale(scale: int, backend: str = "rust"):
    """Test deployment at specific scale"""
    print(f"\n{'='*80}")
    print(f"  TESTING SCALE: {scale:,} CLONES")
    print(f"{'='*80}")

    tasks = [f"clone_{i}" for i in range(scale)]

    if backend == "rust":
        try:
            import whitemagic_rs
            start = time.time()
            result = whitemagic_rs.benchmark_rust_vs_python(scale)
            duration = time.time() - start
            throughput = result.get('rust_throughput', 0)
            backend_used = "Rust Tokio"
        except Exception as e:
            print(f"  ⚠️  Rust failed: {e}, falling back to Python")
            backend = "python"

    if backend == "python":
        start = time.time()
        # Simulate Python async deployment
        async def execute_task(task_id):
            await asyncio.sleep(0.001)
            return {'task_id': task_id, 'success': True}

        await asyncio.gather(*[execute_task(t) for t in tasks])
        duration = time.time() - start
        throughput = scale / duration if duration > 0 else 0
        backend_used = "Python"

    # Calculate metrics
    time_per_clone_us = (duration / scale * 1_000_000) if scale > 0 else 0
    clones_per_ms = throughput / 1000 if throughput > 0 else 0

    print(f"\n  Backend: {backend_used}")
    print(f"  Clones: {scale:,}")
    print(f"  Duration: {duration:.6f}s")
    print(f"  Throughput: {throughput:,.0f} clones/sec")
    print(f"  Time per clone: {time_per_clone_us:.3f} microseconds")
    print(f"  Clones per millisecond: {clones_per_ms:.1f}")

    # Efficiency analysis
    baseline_throughput = 18157  # deploy_grand_army.py
    improvement = throughput / baseline_throughput if baseline_throughput > 0 else 0
    print("\n  vs Baseline (18,157 clones/sec):")
    print(f"    Improvement: {improvement:.1f}× faster")

    # Optimal use cases
    print("\n  Optimal for:")
    if scale <= 5000:
        print("    - Quick reconnaissance")
        print("    - Single campaign testing")
        print("    - Rapid iteration")
    elif scale <= 25000:
        print("    - Multi-campaign deployment")
        print("    - Balanced exploration")
        print("    - Standard operations")
    elif scale <= 100000:
        print("    - Massive scale operations")
        print("    - Exhaustive search")
        print("    - Genetic algorithms")
    else:
        print("    - Million-clone deployments")
        print("    - Monte Carlo simulations")
        print("    - Extreme parallelism")

    return {
        'scale': scale,
        'backend': backend_used,
        'duration': duration,
        'throughput': throughput,
        'improvement': improvement,
        'time_per_clone_us': time_per_clone_us
    }


async def main():
    """Run ramping deployment tests"""
    print("\n" + "="*80)
    print("  ☯ RAMPING DEPLOYMENT TEST ☯")
    print("  Finding Optimal Force Composition")
    print("="*80)

    # Test scales
    scales = [1_000, 5_000, 10_000, 25_000, 50_000, 100_000]

    results = []
    for scale in scales:
        result = await test_scale(scale, backend="rust")
        results.append(result)

        # Brief pause between tests
        await asyncio.sleep(0.5)

    # Summary analysis
    print("\n" + "="*80)
    print("  SUMMARY ANALYSIS")
    print("="*80)

    print("\n  Performance by Scale:")
    print(f"  {'Scale':<12} {'Throughput':<20} {'Improvement':<15} {'Time/Clone'}")
    print(f"  {'-'*12} {'-'*20} {'-'*15} {'-'*12}")

    for r in results:
        print(f"  {r['scale']:>10,}  {r['throughput']:>15,.0f}/sec  {r['improvement']:>10.1f}×  {r['time_per_clone_us']:>8.3f}μs")

    # Find optimal scales
    print("\n  Recommended Force Compositions:")
    print("    • Quick Recon: 1K-5K clones (fastest iteration)")
    print("    • Standard Ops: 10K-25K clones (balanced)")
    print("    • Heavy Assault: 50K-100K clones (maximum coverage)")

    # Calculate total capacity
    total_clones = sum(r['scale'] for r in results)
    total_time = sum(r['duration'] for r in results)
    avg_throughput = total_clones / total_time if total_time > 0 else 0

    print("\n  Total Test Statistics:")
    print(f"    Total clones deployed: {total_clones:,}")
    print(f"    Total time: {total_time:.3f}s")
    print(f"    Average throughput: {avg_throughput:,.0f} clones/sec")

    print("\n" + "="*80)
    print("  ✅ RAMPING TEST COMPLETE")
    print("="*80)

    return results


if __name__ == '__main__':
    asyncio.run(main())
