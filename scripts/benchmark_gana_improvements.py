#!/usr/bin/env python3
"""Benchmark Gana Improvements - Before/After Comparison

Tests:
1. Sequential execution performance
2. Parallel execution performance
3. Token efficiency (response sizes)
4. Database concurrency (SQLite vs Polyglot)
5. Tool discovery and autocast performance
"""

import json
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))


def benchmark_sequential_old():
    """Benchmark using old unified_api (no integrations)."""
    from whitemagic.tools.unified_api import call_tool
    
    tools = [
        ("search_memories", {"query": "test"}),
        ("gnosis", {"compact": True}),
        ("capabilities", {}),
        ("harmony_vector", {}),
        ("wu_xing_balance", {}),
    ]
    
    start = time.perf_counter()
    results = []
    
    for tool_name, args in tools:
        result = call_tool(tool_name, **args)
        results.append({
            "tool": tool_name,
            "response_size": len(str(result)),
            "status": result.get("status") if isinstance(result, dict) else "unknown",
        })
    
    elapsed = time.perf_counter() - start
    
    return {
        "total_time_s": round(elapsed, 3),
        "avg_time_s": round(elapsed / len(tools), 3),
        "results": results,
        "avg_response_size": sum(r["response_size"] for r in results) / len(results),
    }


def benchmark_sequential_new():
    """Benchmark using new integrated_api (with blackboard, gan ying, autocast)."""
    from whitemagic.tools.integrated_api import call_tool
    
    tools = [
        ("search_memories", {"query": "test"}),
        ("gnosis", {"compact": True}),
        ("capabilities", {}),
        ("harmony_vector", {}),
        ("wu_xing_balance", {}),
    ]
    
    start = time.perf_counter()
    results = []
    
    for tool_name, args in tools:
        result = call_tool(tool_name, **args)
        results.append({
            "tool": tool_name,
            "response_size": len(str(result)),
            "status": result.get("status") if isinstance(result, dict) else "unknown",
        })
    
    elapsed = time.perf_counter() - start
    
    return {
        "total_time_s": round(elapsed, 3),
        "avg_time_s": round(elapsed / len(tools), 3),
        "results": results,
        "avg_response_size": sum(r["response_size"] for r in results) / len(results),
    }


def benchmark_parallel_old(max_workers=5):
    """Benchmark parallel execution with old API."""
    from whitemagic.tools.unified_api import call_tool
    
    tools = [
        ("search_memories", {"query": f"test{i}"})
        for i in range(20)
    ]
    
    start = time.perf_counter()
    results = []
    
    with ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = {
            executor.submit(call_tool, tool, **args): (tool, args)
            for tool, args in tools
        }
        
        for future in as_completed(futures):
            tool, args = futures[future]
            try:
                result = future.result()
                results.append({
                    "tool": tool,
                    "status": result.get("status") if isinstance(result, dict) else "unknown",
                })
            except Exception as e:
                results.append({
                    "tool": tool,
                    "status": "error",
                    "error": str(e)[:100],
                })
    
    elapsed = time.perf_counter() - start
    
    return {
        "total_time_s": round(elapsed, 3),
        "throughput": round(len(tools) / elapsed, 2),
        "success_count": sum(1 for r in results if r["status"] == "success"),
        "error_count": sum(1 for r in results if r["status"] == "error"),
    }


def benchmark_parallel_new(max_workers=5):
    """Benchmark parallel execution with new integrated API."""
    from whitemagic.tools.integrated_api import call_tool
    
    tools = [
        ("search_memories", {"query": f"test{i}"})
        for i in range(20)
    ]
    
    start = time.perf_counter()
    results = []
    
    with ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = {
            executor.submit(call_tool, tool, **args): (tool, args)
            for tool, args in tools
        }
        
        for future in as_completed(futures):
            tool, args = futures[future]
            try:
                result = future.result()
                results.append({
                    "tool": tool,
                    "status": result.get("status") if isinstance(result, dict) else "unknown",
                })
            except Exception as e:
                results.append({
                    "tool": tool,
                    "status": "error",
                    "error": str(e)[:100],
                })
    
    elapsed = time.perf_counter() - start
    
    return {
        "total_time_s": round(elapsed, 3),
        "throughput": round(len(tools) / elapsed, 2),
        "success_count": sum(1 for r in results if r["status"] == "success"),
        "error_count": sum(1 for r in results if r["status"] == "error"),
    }


def benchmark_database_backends():
    """Benchmark different database backends."""
    from whitemagic.core.storage.polyglot_db import get_polyglot_db, BackendType
    
    results = {}
    
    # Test data
    test_memories = [
        {
            "id": f"test_{i}",
            "content": f"Test memory {i}",
            "metadata": {"tags": ["test"], "index": i}
        }
        for i in range(100)
    ]
    
    # Try each backend
    for backend in [BackendType.RUST, BackendType.ELIXIR, BackendType.SQLITE]:
        try:
            db = get_polyglot_db(backend)
            
            # Benchmark batch write
            start = time.perf_counter()
            db.batch_write(test_memories)
            write_time = time.perf_counter() - start
            
            # Benchmark reads
            start = time.perf_counter()
            for i in range(100):
                db.get(f"test_{i}")
            read_time = time.perf_counter() - start
            
            results[backend.value] = {
                "write_time_s": round(write_time, 4),
                "read_time_s": round(read_time, 4),
                "write_throughput": round(100 / write_time, 2),
                "read_throughput": round(100 / read_time, 2),
                "status": "success",
            }
        except Exception as e:
            results[backend.value] = {
                "status": "unavailable",
                "error": str(e)[:100],
            }
    
    return results


def benchmark_tool_discovery():
    """Benchmark tool discovery and autocast."""
    from whitemagic.tools.integrated_api import discover_tools, autocast, tool_stats
    
    results = {}
    
    # Benchmark discovery by category
    start = time.perf_counter()
    result = discover_tools(category="memory")
    results["discover_by_category"] = {
        "time_ms": round((time.perf_counter() - start) * 1000, 2),
        "tools_found": result.get("count", 0),
    }
    
    # Benchmark discovery by search
    start = time.perf_counter()
    result = discover_tools(search="memory")
    results["discover_by_search"] = {
        "time_ms": round((time.perf_counter() - start) * 1000, 2),
        "tools_found": result.get("count", 0),
    }
    
    # Benchmark autocast
    start = time.perf_counter()
    result = autocast(current_context=["memory", "search"], num_suggestions=5)
    results["autocast"] = {
        "time_ms": round((time.perf_counter() - start) * 1000, 2),
        "suggestions": result.get("count", 0),
    }
    
    # Benchmark stats
    start = time.perf_counter()
    result = tool_stats()
    results["global_stats"] = {
        "time_ms": round((time.perf_counter() - start) * 1000, 2),
    }
    
    return results


def main():
    print("="*80)
    print("GANA IMPROVEMENTS BENCHMARK")
    print("="*80)
    
    report = {
        "timestamp": time.time(),
        "benchmarks": {},
    }
    
    # 1. Sequential execution
    print("\n1. Sequential Execution")
    print("  Testing old API...")
    old_seq = benchmark_sequential_old()
    print(f"    Time: {old_seq['total_time_s']}s, Avg response: {old_seq['avg_response_size']:.0f} chars")
    
    print("  Testing new API (integrated)...")
    new_seq = benchmark_sequential_new()
    print(f"    Time: {new_seq['total_time_s']}s, Avg response: {new_seq['avg_response_size']:.0f} chars")
    
    improvement = ((old_seq['total_time_s'] - new_seq['total_time_s']) / old_seq['total_time_s']) * 100
    token_savings = ((old_seq['avg_response_size'] - new_seq['avg_response_size']) / old_seq['avg_response_size']) * 100
    
    print(f"  ⚡ Performance: {improvement:+.1f}%")
    print(f"  💬 Token savings: {token_savings:+.1f}%")
    
    report["benchmarks"]["sequential"] = {
        "old": old_seq,
        "new": new_seq,
        "improvement_pct": round(improvement, 2),
        "token_savings_pct": round(token_savings, 2),
    }
    
    # 2. Parallel execution
    print("\n2. Parallel Execution (20 concurrent calls)")
    print("  Testing old API...")
    old_par = benchmark_parallel_old(max_workers=10)
    print(f"    Time: {old_par['total_time_s']}s, Throughput: {old_par['throughput']:.1f} calls/s")
    
    print("  Testing new API (integrated)...")
    new_par = benchmark_parallel_new(max_workers=10)
    print(f"    Time: {new_par['total_time_s']}s, Throughput: {new_par['throughput']:.1f} calls/s")
    
    throughput_improvement = ((new_par['throughput'] - old_par['throughput']) / old_par['throughput']) * 100
    print(f"  ⚡ Throughput improvement: {throughput_improvement:+.1f}%")
    
    report["benchmarks"]["parallel"] = {
        "old": old_par,
        "new": new_par,
        "throughput_improvement_pct": round(throughput_improvement, 2),
    }
    
    # 3. Database backends
    print("\n3. Database Backend Performance")
    db_results = benchmark_database_backends()
    for backend, result in db_results.items():
        if result.get("status") == "success":
            print(f"  {backend.upper()}:")
            print(f"    Write: {result['write_throughput']:.1f} ops/s")
            print(f"    Read: {result['read_throughput']:.1f} ops/s")
        else:
            print(f"  {backend.upper()}: {result.get('error', 'unavailable')}")
    
    report["benchmarks"]["database"] = db_results
    
    # 4. Tool discovery
    print("\n4. Tool Discovery & Autocast")
    discovery_results = benchmark_tool_discovery()
    for feature, result in discovery_results.items():
        print(f"  {feature}: {result.get('time_ms', 0):.2f}ms")
    
    report["benchmarks"]["discovery"] = discovery_results
    
    # Save report
    report_path = Path(__file__).parent.parent / "reports" / "gana_improvements_benchmark.json"
    with open(report_path, 'w') as f:
        json.dump(report, f, indent=2)
    
    print(f"\n✓ Report saved to: {report_path}")
    
    # Summary
    print("\n" + "="*80)
    print("SUMMARY")
    print("="*80)
    print(f"Sequential performance: {improvement:+.1f}%")
    print(f"Token efficiency: {token_savings:+.1f}%")
    print(f"Parallel throughput: {throughput_improvement:+.1f}%")
    
    # Find best database backend
    best_backend = None
    best_throughput = 0
    for backend, result in db_results.items():
        if result.get("status") == "success":
            total_throughput = result["write_throughput"] + result["read_throughput"]
            if total_throughput > best_throughput:
                best_throughput = total_throughput
                best_backend = backend
    
    if best_backend:
        print(f"Best database backend: {best_backend.upper()}")
    
    return 0


if __name__ == "__main__":
    sys.exit(main())
