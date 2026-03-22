#!/usr/bin/env python3
"""V21 Benchmark Gauntlet Suite

Comprehensive performance testing for:
- Event bus latency and throughput
- Willow health check overhead
- Polyglot hot path performance
- Memory system operations
- Biological subsystem coordination

Usage:
    scripts/wm scripts/benchmark_gauntlet.py --all
    scripts/wm scripts/benchmark_gauntlet.py --event-bus
    scripts/wm scripts/benchmark_gauntlet.py --willow-health
    scripts/wm scripts/benchmark_gauntlet.py --polyglot
"""

import asyncio
import json
import logging
import statistics
import time
from typing import Any, Dict

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class BenchmarkGauntlet:
    """Comprehensive benchmark suite for V21 components."""
    
    def __init__(self):
        self.results: Dict[str, Any] = {}
        self.start_time = time.time()
        
    async def benchmark_event_bus(self) -> Dict[str, Any]:
        """Benchmark event bus performance."""
        logger.info("🧠 Benchmarking Biological Event Bus")
        
        try:
            from whitemagic.core.intelligence.biological_event_bus import get_event_bus, EventType
            
            bus = await get_event_bus()
            
            # Test 1: Publish latency
            publish_times = []
            for i in range(1000):
                start = time.perf_counter()
                await bus.publish(EventType.COHERENCE_CHANGE, {"test": i}, "benchmark")
                publish_times.append((time.perf_counter() - start) * 1000)
            
            # Test 2: Subscribe/unsubscribe overhead
            sub_times = []
            for i in range(100):
                async def dummy_handler(event): pass
                start = time.perf_counter()
                bus.subscribe(EventType.COHERENCE_CHANGE, dummy_handler, f"bench_{i}")
                sub_times.append((time.perf_counter() - start) * 1000)
            
            # Test 3: Throughput (burst publishing)
            burst_start = time.perf_counter()
            for i in range(10000):
                await bus.publish(EventType.COHERENCE_CHANGE, {"burst": i}, "burst_test")
            burst_time = (time.perf_counter() - burst_start) * 1000
            
            await bus.stop()
            
            return {
                "publish_latency_ms": {
                    "mean": statistics.mean(publish_times),
                    "median": statistics.median(publish_times),
                    "p95": sorted(publish_times)[int(0.95 * len(publish_times))],
                    "p99": sorted(publish_times)[int(0.99 * len(publish_times))]
                },
                "subscribe_overhead_ms": {
                    "mean": statistics.mean(sub_times),
                    "median": statistics.median(sub_times)
                },
                "throughput_ops_per_sec": 10000 / (burst_time / 1000),
                "total_events": 11000
            }
            
        except Exception as e:
            logger.error(f"Event bus benchmark failed: {e}")
            return {"error": str(e)}
    
    async def benchmark_willow_health(self) -> Dict[str, Any]:
        """Benchmark Willow health check performance."""
        logger.info("🌿 Benchmarking Gana Willow Health Checks")
        
        try:
            from whitemagic.tools.willow_health_check import get_willow_health_checker
            
            checker = get_willow_health_checker()
            
            # Test 1: Health check latency
            health_times = []
            for i in range(100):
                start = time.perf_counter()
                await checker.check_willow_health()
                health_times.append((time.perf_counter() - start) * 1000)
            
            # Test 2: Circuit breaker check overhead
            circuit_times = []
            for i in range(1000):
                start = time.perf_counter()
                checker._check_circuit_breaker()
                circuit_times.append((time.perf_counter() - start) * 1000)
            
            # Test 3: Koka handler timeout
            koka_times = []
            for i in range(50):
                start = time.perf_counter()
                await checker._check_koka_responsiveness()
                koka_times.append((time.perf_counter() - start) * 1000)
            
            return {
                "health_check_latency_ms": {
                    "mean": statistics.mean(health_times),
                    "median": statistics.median(health_times),
                    "p95": sorted(health_times)[int(0.95 * len(health_times))]
                },
                "circuit_breaker_check_ms": {
                    "mean": statistics.mean(circuit_times),
                    "median": statistics.median(circuit_times)
                },
                "koka_timeout_ms": {
                    "mean": statistics.mean(koka_times),
                    "median": statistics.median(koka_times)
                }
            }
            
        except Exception as e:
            logger.error(f"Willow health benchmark failed: {e}")
            return {"error": str(e)}
    
    async def benchmark_polyglot(self) -> Dict[str, Any]:
        """Benchmark polyglot hot paths."""
        logger.info("🚀 Benchmarking Polyglot Hot Paths")
        
        results = {}
        
        # Test Rust bridge
        try:
            import whitemagic_rs
            rust_times = []
            test_data = json.dumps({"test": "data" * 100})  # Large JSON
            
            for i in range(1000):
                start = time.perf_counter()
                whitemagic_rs.json_serialize(test_data)
                rust_times.append((time.perf_counter() - start) * 1000)
            
            results["rust_json_serialize"] = {
                "mean_ms": statistics.mean(rust_times),
                "median_ms": statistics.median(rust_times),
                "ops_per_sec": 1000 / (statistics.mean(rust_times) / 1000)
            }
        except ImportError:
            results["rust_json_serialize"] = {"error": "Rust bridge not available"}
        
        # Test Zig bridge
        try:
            from whitemagic.core.acceleration.zig_graph_bridge import zig_cosine_similarity
            import random
            
            # Generate test vectors
            v1 = [random.random() for _ in range(1536)]
            v2 = [random.random() for _ in range(1536)]
            
            zig_times = []
            for i in range(1000):
                start = time.perf_counter()
                zig_cosine_similarity(v1, v2)
                zig_times.append((time.perf_counter() - start) * 1000)
            
            results["zig_cosine_similarity"] = {
                "mean_ms": statistics.mean(zig_times),
                "median_ms": statistics.median(zig_times),
                "ops_per_sec": 1000 / (statistics.mean(zig_times) / 1000)
            }
        except ImportError:
            results["zig_cosine_similarity"] = {"error": "Zig bridge not available"}
        
        # Test Julia bridge
        try:
            from whitemagic.core.acceleration.julia_zmq_bridge import get_julia_client
            
            client = get_julia_client()
            if client:
                # Test RRF fusion
                lists = [["a", "b", "c"], ["b", "c", "d"], ["c", "d", "e"]]
                weights = [0.5, 0.3, 0.2]
                
                julia_times = []
                for i in range(100):
                    start = time.perf_counter()
                    client.rrf_fuse(lists, weights)
                    julia_times.append((time.perf_counter() - start) * 1000)
                
                results["julia_rrf_fuse"] = {
                    "mean_ms": statistics.mean(julia_times),
                    "median_ms": statistics.median(julia_times),
                    "ops_per_sec": 100 / (statistics.mean(julia_times) / 1000)
                }
            else:
                results["julia_rrf_fuse"] = {"error": "Julia server not connected"}
        except ImportError:
            results["julia_rrf_fuse"] = {"error": "Julia bridge not available"}
        
        return results
    
    async def benchmark_memory_systems(self) -> Dict[str, Any]:
        """Benchmark memory system operations."""
        logger.info("💾 Benchmarking Memory Systems")
        
        results = {}
        
        try:
            from whitemagic.core.memory.embeddings import get_embedder
            
            embedder = get_embedder()
            
            # Test embedding generation
            texts = ["test text " + str(i) for i in range(100)]
            embed_times = []
            
            for text in texts:
                start = time.perf_counter()
                embedder.encode([text])
                embed_times.append((time.perf_counter() - start) * 1000)
            
            results["embedding_generation"] = {
                "mean_ms": statistics.mean(embed_times),
                "median_ms": statistics.median(embed_times),
                "ops_per_sec": 100 / (statistics.mean(embed_times) / 1000)
            }
            
        except Exception as e:
            results["embedding_generation"] = {"error": str(e)}
        
        try:
            from whitemagic.core.memory.sqlite_backend import SQLiteBackend
            
            backend = SQLiteBackend()
            
            # Test search performance
            search_times = []
            for i in range(100):
                start = time.perf_counter()
                backend.search(f"test query {i}", limit=10)
                search_times.append((time.perf_counter() - start) * 1000)
            
            results["sqlite_search"] = {
                "mean_ms": statistics.mean(search_times),
                "median_ms": statistics.median(search_times),
                "ops_per_sec": 100 / (statistics.mean(search_times) / 1000)
            }
            
        except Exception as e:
            results["sqlite_search"] = {"error": str(e)}
        
        return results
    
    async def run_all(self) -> Dict[str, Any]:
        """Run all benchmarks."""
        logger.info("⚡ Starting V21 Benchmark Gauntlet")
        
        # Run all benchmarks
        results = await asyncio.gather(
            self.benchmark_event_bus(),
            self.benchmark_willow_health(),
            self.benchmark_polyglot(),
            self.benchmark_memory_systems(),
            return_exceptions=True
        )
        
        self.results = {
            "event_bus": results[0] if not isinstance(results[0], Exception) else {"error": str(results[0])},
            "willow_health": results[1] if not isinstance(results[1], Exception) else {"error": str(results[1])},
            "polyglot": results[2] if not isinstance(results[2], Exception) else {"error": str(results[2])},
            "memory_systems": results[3] if not isinstance(results[3], Exception) else {"error": str(results[3])},
            "duration_seconds": time.time() - self.start_time
        }
        
        return self.results
    
    def generate_report(self) -> str:
        """Generate benchmark report."""
        report = f"""# V21 Benchmark Gauntlet Report

**Date**: {time.strftime("%Y-%m-%d %H:%M:%S")}
**Duration**: {self.results.get('duration_seconds', 0):.1f}s

## Event Bus Performance
"""
        
        eb = self.results.get("event_bus", {})
        if "error" not in eb:
            report += f"""- **Publish Latency**: {eb.get('publish_latency_ms', {}).get('mean', 0):.2f}ms mean, {eb.get('publish_latency_ms', {}).get('p95', 0):.2f}ms p95
- **Subscribe Overhead**: {eb.get('subscribe_overhead_ms', {}).get('mean', 0):.2f}ms mean
- **Throughput**: {eb.get('throughput_ops_per_sec', 0):.0f} ops/sec
- **Total Events**: {eb.get('total_events', 0)}
"""
        else:
            report += f"- **Error**: {eb.get('error', 'Unknown')}\n"
        
        report += "\n## Willow Health Performance\n"
        wh = self.results.get("willow_health", {})
        if "error" not in wh:
            report += f"""- **Health Check**: {wh.get('health_check_latency_ms', {}).get('mean', 0):.2f}ms mean
- **Circuit Breaker**: {wh.get('circuit_breaker_check_ms', {}).get('mean', 0):.2f}ms mean
- **Koka Timeout**: {wh.get('koka_timeout_ms', {}).get('mean', 0):.2f}ms mean
"""
        else:
            report += f"- **Error**: {wh.get('error', 'Unknown')}\n"
        
        report += "\n## Polyglot Performance\n"
        poly = self.results.get("polyglot", {})
        for bridge, metrics in poly.items():
            if "error" not in metrics:
                report += f"- **{bridge}**: {metrics.get('mean_ms', 0):.2f}ms mean, {metrics.get('ops_per_sec', 0):.0f} ops/sec\n"
            else:
                report += f"- **{bridge}**: {metrics.get('error', 'Unknown')}\n"
        
        report += "\n## Memory System Performance\n"
        mem = self.results.get("memory_systems", {})
        for system, metrics in mem.items():
            if "error" not in metrics:
                report += f"- **{system}**: {metrics.get('mean_ms', 0):.2f}ms mean, {metrics.get('ops_per_sec', 0):.0f} ops/sec\n"
            else:
                report += f"- **{system}**: {metrics.get('error', 'Unknown')}\n"
        
        report += f"\n## Full Results\n\n```json\n{json.dumps(self.results, indent=2, default=str)}\n```\n"
        
        return report

async def main():
    import argparse
    
    parser = argparse.ArgumentParser(description="V21 Benchmark Gauntlet")
    parser.add_argument("--all", action="store_true", help="Run all benchmarks")
    parser.add_argument("--event-bus", action="store_true", help="Benchmark event bus")
    parser.add_argument("--willow-health", action="store_true", help="Benchmark Willow health")
    parser.add_argument("--polyglot", action="store_true", help="Benchmark polyglot")
    parser.add_argument("--memory", action="store_true", help="Benchmark memory systems")
    parser.add_argument("--report", default="reports/v21_benchmark_report.md", help="Report output path")
    
    args = parser.parse_args()
    
    gauntlet = BenchmarkGauntlet()
    
    if args.all or (not any([args.event_bus, args.willow_health, args.polyglot, args.memory])):
        results = await gauntlet.run_all()
    elif args.event_bus:
        results = {"event_bus": await gauntlet.benchmark_event_bus()}
    elif args.willow_health:
        results = {"willow_health": await gauntlet.benchmark_willow_health()}
    elif args.polyglot:
        results = {"polyglot": await gauntlet.benchmark_polyglot()}
    elif args.memory:
        results = {"memory_systems": await gauntlet.benchmark_memory_systems()}
    else:
        parser.print_help()
        return
    
    gauntlet.results.update(results)
    
    # Generate and save report
    report = gauntlet.generate_report()
    
    import os
    os.makedirs(os.path.dirname(args.report), exist_ok=True)
    with open(args.report, "w") as f:
        f.write(report)
        
    print(f"\n📊 Benchmark report saved to: {args.report}")
    print(report)

if __name__ == "__main__":
    asyncio.run(main())
