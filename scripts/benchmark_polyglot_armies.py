#!/usr/bin/env python3
"""
Polyglot Shadow Clone Army Aggregate Throughput Benchmark
Tests all 7 language armies and measures combined throughput
"""

import json
import subprocess
import time
from pathlib import Path

SCRIPT_DIR = Path(__file__).parent
ARMIES = {
    "rust": SCRIPT_DIR / "army_rust.sh",
    "zig": SCRIPT_DIR / "army_zig.sh",
    "mojo": SCRIPT_DIR / "army_mojo.sh",
    "go": SCRIPT_DIR / "army_go.sh",
    "elixir": SCRIPT_DIR / "army_elixir.sh",
    "haskell": SCRIPT_DIR / "army_haskell.sh",
    "julia": SCRIPT_DIR / "army_julia.sh",
}

def test_army(language: str, script_path: Path, clone_count: int) -> tuple[bool, float, dict]:
    """Test a single army script and measure throughput"""
    task = {
        "task": f"{language}_test",
        "clone_count": clone_count
    }

    start_time = time.time()
    try:
        result = subprocess.run(
            [str(script_path)],
            input=json.dumps(task),
            capture_output=True,
            text=True,
            timeout=30
        )

        elapsed = time.time() - start_time

        if result.returncode != 0:
            return False, elapsed, {"error": result.stderr}

        try:
            output = json.loads(result.stdout)
            return True, elapsed, output
        except json.JSONDecodeError:
            return False, elapsed, {"error": "Invalid JSON output", "stdout": result.stdout[:200]}

    except subprocess.TimeoutExpired:
        elapsed = time.time() - start_time
        return False, elapsed, {"error": "Timeout"}
    except Exception as e:
        elapsed = time.time() - start_time
        return False, elapsed, {"error": str(e)}

def run_benchmark(clone_count: int = 10000) -> dict:
    """Run benchmark across all polyglot armies"""
    print(f"\n{'='*70}")
    print("  POLYGLOT ARMY AGGREGATE THROUGHPUT BENCHMARK")
    print(f"{'='*70}\n")
    print(f"  Clone count per army: {clone_count:,}")
    print(f"  Total armies: {len(ARMIES)}")
    print(f"  Total clones: {clone_count * len(ARMIES):,}\n")

    results = {}
    total_clones = 0
    total_time = 0
    successful_armies = 0

    for language, script_path in ARMIES.items():
        print(f"  [{language.upper():>8}] ", end="", flush=True)

        if not script_path.exists():
            print("❌ Script not found")
            results[language] = {"status": "missing", "throughput": 0}
            continue

        success, elapsed, output = test_army(language, script_path, clone_count)

        if success:
            throughput = clone_count / elapsed if elapsed > 0 else 0
            print(f"✅ {elapsed:.3f}s → {throughput:,.0f} clones/sec")
            results[language] = {
                "status": "success",
                "elapsed": elapsed,
                "throughput": throughput,
                "output": output
            }
            total_clones += clone_count
            total_time += elapsed
            successful_armies += 1
        else:
            print(f"❌ Failed: {output.get('error', 'Unknown error')[:50]}")
            results[language] = {
                "status": "failed",
                "error": output.get("error", "Unknown"),
                "throughput": 0
            }

    # Calculate aggregate metrics
    aggregate_throughput = total_clones / total_time if total_time > 0 else 0

    print(f"\n{'='*70}")
    print("  AGGREGATE RESULTS")
    print(f"{'='*70}\n")
    print(f"  Successful armies: {successful_armies}/{len(ARMIES)}")
    print(f"  Total clones processed: {total_clones:,}")
    print(f"  Total time: {total_time:.3f}s")
    print(f"  Aggregate throughput: {aggregate_throughput:,.0f} clones/sec")
    print("\n  Target: 2,000,000 clones/sec")
    print(f"  Achievement: {(aggregate_throughput / 2_000_000 * 100):.1f}%")
    print(f"\n{'='*70}\n")

    return {
        "clone_count_per_army": clone_count,
        "total_armies": len(ARMIES),
        "successful_armies": successful_armies,
        "total_clones": total_clones,
        "total_time": total_time,
        "aggregate_throughput": aggregate_throughput,
        "target_throughput": 2_000_000,
        "achievement_percent": (aggregate_throughput / 2_000_000 * 100),
        "results": results
    }

if __name__ == "__main__":
    import sys

    clone_count = int(sys.argv[1]) if len(sys.argv) > 1 else 10000

    benchmark_results = run_benchmark(clone_count)

    # Save results
    output_file = SCRIPT_DIR.parent / "reports" / "polyglot_throughput_benchmark.json"
    output_file.parent.mkdir(exist_ok=True)

    with open(output_file, "w") as f:
        json.dump(benchmark_results, f, indent=2)

    print(f"  Results saved to: {output_file}\n")

    # Exit with success if we hit target
    sys.exit(0 if benchmark_results["aggregate_throughput"] >= 2_000_000 else 1)
