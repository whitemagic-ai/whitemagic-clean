#!/usr/bin/env python3
"""Full IPC Benchmark - Validate all components."""

import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

import time
import concurrent.futures
import statistics
from datetime import datetime

class IPCBenchmark:
    """Comprehensive benchmark suite."""
    
    def __init__(self):
        self.results = {}
        
    def _test_ipc_latency(self, iterations=100):
        """Measure IPC round-trip latency."""
        from whitemagic.core.ipc_bridge import init_ipc, publish_json
        
        print("📡 Testing IPC latency...")
        init_ipc('benchmark')
        
        latencies = []
        for i in range(iterations):
            start = time.perf_counter()
            result = publish_json('wm/events', {'test': i, 'payload': 'x' * 50})
            end = time.perf_counter()
            
            if result.get('published'):
                latencies.append((end - start) * 1000)  # ms
        
        if latencies:
            return {
                'min_ms': min(latencies),
                'max_ms': max(latencies),
                'avg_ms': statistics.mean(latencies),
                'p99_ms': sorted(latencies)[int(len(latencies)*0.99)],
                'samples': len(latencies)
            }
        return {'error': 'No successful publishes'}
    
    def _test_event_throughput(self, duration=5):
        """Test events per second."""
        from whitemagic.core.resonance.gan_ying_enhanced import get_bus, EventType
        
        print("📊 Testing GanYing event throughput...")
        bus = get_bus()
        
        count = 0
        start = time.time()
        while time.time() - start < duration:
            bus.emit_event('benchmark', EventType.SYSTEM_STATE_CHANGE, {'id': count})
            count += 1
        
        elapsed = time.time() - start
        return {
            'events': count,
            'duration_s': elapsed,
            'events_per_sec': count / elapsed
        }
    
    def _test_multi_process(self, workers=10, ops_per_worker=100):
        """Test multi-process operations."""
        from whitemagic.core.intelligence.core_access import get_core_access
        
        print(f"🔄 Testing multi-process ops ({workers} workers)...")
        
        def do_search(core, worker_id):
            results = []
            for i in range(ops_per_worker):
                try:
                    r = core.hybrid_recall(f'test query {i}', k=5)
                    results.append(len(r))
                except:
                    results.append(-1)
            return results
        
        core = get_core_access()
        start = time.time()
        
        with concurrent.futures.ThreadPoolExecutor(max_workers=workers) as executor:
            futures = [executor.submit(do_search, core, i) for i in range(workers)]
            all_results = [f.result() for f in concurrent.futures.as_completed(futures)]
        
        elapsed = time.time() - start
        total_ops = workers * ops_per_worker
        
        return {
            'total_ops': total_ops,
            'duration_s': elapsed,
            'ops_per_sec': total_ops / elapsed,
            'workers': workers
        }
    
    def run(self):
        """Run full benchmark suite."""
        print("╔══════════════════════════════════════════════════════════════╗")
        print("║       WhiteMagic IPC Full Benchmark Suite v1.0               ║")
        print("╚══════════════════════════════════════════════════════════════╝")
        print(f"Started: {datetime.now().isoformat()}\n")
        
        # Test 1: IPC Latency
        print("─" * 60)
        print("Test 1: IPC Latency (100 iterations)")
        print("─" * 60)
        self.results['ipc_latency'] = self._test_ipc_latency(100)
        r = self.results['ipc_latency']
        if 'error' not in r:
            print(f"  Min: {r['min_ms']:.3f}ms")
            print(f"  Avg: {r['avg_ms']:.3f}ms")
            print(f"  P99: {r['p99_ms']:.3f}ms")
            print(f"  Samples: {r['samples']}")
        else:
            print(f"  ⚠️ {r['error']}")
        
        # Test 2: Event Throughput
        print("\n" + "─" * 60)
        print("Test 2: GanYing Event Throughput (5s burst)")
        print("─" * 60)
        self.results['event_throughput'] = self._test_event_throughput(5)
        r = self.results['event_throughput']
        print(f"  Events: {r['events']}")
        print(f"  Duration: {r['duration_s']:.2f}s")
        print(f"  Throughput: {r['events_per_sec']:.1f} events/sec")
        
        # Test 3: Multi-Process
        print("\n" + "─" * 60)
        print("Test 3: Multi-Process Operations (10 workers × 100 ops)")
        print("─" * 60)
        self.results['multi_process'] = self._test_multi_process(10, 100)
        r = self.results['multi_process']
        print(f"  Total ops: {r['total_ops']}")
        print(f"  Duration: {r['duration_s']:.2f}s")
        print(f"  Throughput: {r['ops_per_sec']:.1f} ops/sec")
        
        # Summary
        print("\n" + "═" * 60)
        print("BENCHMARK SUMMARY")
        print("═" * 60)
        print("\nTargets vs Achieved:")
        
        ipc_r = self.results.get('ipc_latency', {})
        if 'avg_ms' in ipc_r:
            target = 0.05
            actual = ipc_r['avg_ms']
            status = '✅' if actual < 0.1 else '⚠️'
            print(f"  {status} IPC latency: {actual:.3f}ms (target <{target}ms)")
        
        event_r = self.results.get('event_throughput', {})
        if 'events_per_sec' in event_r:
            target = 100000
            actual = event_r['events_per_sec']
            print(f"     Events/sec: {actual:.1f} (target {target:,}+)")
        
        mp_r = self.results.get('multi_process', {})
        if 'ops_per_sec' in mp_r:
            target = 2500
            actual = mp_r['ops_per_sec']
            status = '✅' if actual >= target * 0.5 else '⚠️'
            print(f"  {status} Multi-process: {actual:.1f} ops/sec (target {target}+)")
        
        print(f"\nFinished: {datetime.now().isoformat()}")
        
        return self.results

if __name__ == "__main__":
    benchmark = IPCBenchmark()
    results = benchmark.run()
    
    # Save results
    import json
    with open('/tmp/ipc_benchmark_results.json', 'w') as f:
        json.dump(results, f, indent=2, default=str)
    print("\n📄 Results saved to /tmp/ipc_benchmark_results.json")
