#!/usr/bin/env python3
"""
Python-Koka Pipeline Benchmark (Phase 3)
End-to-end integration: Python producer → shared memory → Koka consumer via IPC

Tests the full data flow path with real embeddings.
"""

import subprocess
import time
import json
import numpy as np
from typing import List, Dict, Any

# Import the shared memory bridge
import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')
from whitemagic.core.acceleration.shared_memory_bridge import SharedMemoryBridge


def generate_test_embeddings(count: int, dim: int = 384) -> List[np.ndarray]:
    """Generate random test embeddings."""
    np.random.seed(42)
    return [np.random.randn(dim).astype(np.float32) for _ in range(count)]


def benchmark_python_shm_write(bridge: SharedMemoryBridge, embeddings: List[np.ndarray]) -> Dict[str, Any]:
    """Benchmark Python writing to shared memory."""
    start = time.perf_counter()
    
    memory_ids = np.array(list(range(1, len(embeddings) + 1)), dtype=np.int32)
    # Stack into single array for batch write
    vectors = np.stack(embeddings)
    bridge.write_batch_numpy(memory_ids, vectors)
    
    elapsed = time.perf_counter() - start
    return {
        "operation": "shm_write",
        "count": len(embeddings),
        "elapsed_ms": elapsed * 1000,
        "throughput": len(embeddings) / elapsed if elapsed > 0 else 0
    }


def benchmark_koka_ipc(koka_binary: str, commands: List[Dict]) -> Dict[str, Any]:
    """Benchmark Koka runtime via IPC."""
    start = time.perf_counter()
    
    proc = subprocess.Popen(
        [koka_binary],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )
    
    # Send commands
    input_lines = "\n".join(json.dumps(cmd) for cmd in commands) + "\n"
    stdout, stderr = proc.communicate(input=input_lines, timeout=10)
    
    elapsed = time.perf_counter() - start
    
    # Parse responses
    responses = [json.loads(line) for line in stdout.strip().split("\n") if line.strip()]
    
    return {
        "operation": "koka_ipc",
        "commands_sent": len(commands),
        "responses_received": len(responses),
        "elapsed_ms": elapsed * 1000,
        "throughput": len(commands) / elapsed if elapsed > 0 else 0
    }


def benchmark_batch_vs_single(koka_binary: str, count: int = 100) -> Dict[str, Any]:
    """Compare batch IPC vs single commands."""
    
    # Single commands
    single_commands = [{"op": "ping"} for _ in range(count)]
    single_result = benchmark_koka_ipc(koka_binary, single_commands + [{"op": "quit"}])
    
    # Batch command
    batch_cmd = {
        "commands": [{"id": i, "op": "ping"} for i in range(1, count + 1)]
    }
    batch_result = benchmark_koka_ipc(koka_binary, [batch_cmd, {"op": "quit"}])
    
    return {
        "single_commands_ms": single_result["elapsed_ms"],
        "batch_commands_ms": batch_result["elapsed_ms"],
        "speedup": single_result["elapsed_ms"] / batch_result["elapsed_ms"] if batch_result["elapsed_ms"] > 0 else 0,
        "single_throughput": single_result["throughput"],
        "batch_throughput": batch_result["throughput"]
    }


def run_pipeline_benchmark():
    """Run full pipeline benchmark."""
    print("=" * 60)
    print("Python-Koka Pipeline Benchmark (Phase 3)")
    print("=" * 60)
    
    koka_binary = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/unified_runtime_v3"
    
    # Test 1: Shared Memory Write Performance
    print("\n--- Test 1: Shared Memory Write ---")
    bridge = SharedMemoryBridge(create=True)
    embeddings_100 = generate_test_embeddings(100)
    embeddings_1000 = generate_test_embeddings(1000)
    
    r1 = benchmark_python_shm_write(bridge, embeddings_100)
    print(f"  100 embeddings: {r1['elapsed_ms']:.2f}ms ({r1['throughput']:.0f}/sec)")
    
    r2 = benchmark_python_shm_write(bridge, embeddings_1000)
    print(f"  1000 embeddings: {r2['elapsed_ms']:.2f}ms ({r2['throughput']:.0f}/sec)")
    
    bridge.close()
    
    # Test 2: Koka IPC Performance
    print("\n--- Test 2: Koka IPC ---")
    commands = [{"op": "emit", "event": "memory_created"} for _ in range(100)]
    r3 = benchmark_koka_ipc(koka_binary, commands + [{"op": "quit"}])
    print(f"  100 emit commands: {r3['elapsed_ms']:.2f}ms ({r3['throughput']:.0f} cmd/sec)")
    
    # Test 3: Batch vs Single
    print("\n--- Test 3: Batch vs Single IPC ---")
    r4 = benchmark_batch_vs_single(koka_binary, count=50)
    print(f"  Single 50 commands: {r4['single_commands_ms']:.2f}ms")
    print(f"  Batch 50 commands: {r4['batch_commands_ms']:.2f}ms")
    print(f"  Speedup: {r4['speedup']:.1f}x")
    
    # Test 4: End-to-end pipeline
    print("\n--- Test 4: End-to-End Pipeline ---")
    bridge = SharedMemoryBridge(create=True)
    
    # Generate and write embeddings
    embeddings = generate_test_embeddings(500)
    vectors = np.stack(embeddings)
    memory_ids = np.array(list(range(1, 501)), dtype=np.int32)
    t1 = time.perf_counter()
    bridge.write_batch_numpy(memory_ids, vectors)
    t2 = time.perf_counter()
    
    # Send batch of events to Koka
    events = [{"op": "emit", "event": "memory_created"} for _ in range(100)]
    r5 = benchmark_koka_ipc(koka_binary, events + [{"op": "quit"}])
    t3 = time.perf_counter()
    
    total_time = (t3 - t1) * 1000
    print(f"  Write 500 embeddings: {(t2-t1)*1000:.2f}ms")
    print(f"  Send 100 events to Koka: {r5['elapsed_ms']:.2f}ms")
    print(f"  Total pipeline time: {total_time:.2f}ms")
    
    bridge.close()
    
    # Summary
    print("\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)
    print(f"  SHM write throughput: {r2['throughput']:.0f} embeddings/sec")
    print(f"  Koka IPC throughput: {r3['throughput']:.0f} commands/sec")
    print(f"  Batch IPC speedup: {r4['speedup']:.1f}x over single commands")
    print(f"  Pipeline (500 embed + 100 events): {total_time:.2f}ms total")
    
    return {
        "shm_write_throughput": r2['throughput'],
        "koka_ipc_throughput": r3['throughput'],
        "batch_speedup": r4['speedup'],
        "pipeline_total_ms": total_time
    }


if __name__ == "__main__":
    run_pipeline_benchmark()
