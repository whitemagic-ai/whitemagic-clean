#!/usr/bin/env python3
"""Verify VC-01: Batch IPC Protocol implementation.

Tests:
1. Koka batch_ipc.kk compiles successfully
2. Python batch client connects to binary
3. Single command execution works
4. Batch command execution works
5. Benchmark: batch of 10 commands < 5x single command latency

Run: python scripts/verify_koka_batch_ipc.py
"""
from __future__ import annotations

import subprocess
import sys
import time
from pathlib import Path

# Add project root to path
ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(ROOT / "whitemagic"))
sys.path.insert(0, str(ROOT / ".venv/lib/python3.12/site-packages"))

KOKA_DIR = ROOT / "whitemagic-koka"
BATCH_IPC_SRC = KOKA_DIR / "src" / "batch_ipc.kk"
BATCH_IPC_BIN = KOKA_DIR / "batch_ipc"


def check_koka_available() -> bool:
    """Check if Koka compiler is available."""
    result = subprocess.run(
        ["which", "koka"],
        capture_output=True,
        text=True
    )
    return result.returncode == 0


def compile_batch_ipc() -> bool:
    """Compile the batch_ipc.kk module."""
    if not BATCH_IPC_SRC.exists():
        print("❌ Source not found:", BATCH_IPC_SRC)
        return False
    
    print(f"Compiling {BATCH_IPC_SRC}...")
    
    result = subprocess.run(
        ["koka", "-o", str(BATCH_IPC_BIN), str(BATCH_IPC_SRC)],
        capture_output=True,
        text=True,
        cwd=str(KOKA_DIR),
        timeout=120,
    )
    
    if result.returncode == 0 and BATCH_IPC_BIN.exists():
        print("✅ Compiled:", BATCH_IPC_BIN)
        return True
    else:
        print("❌ Compilation failed:")
        print(result.stderr[:500] if result.stderr else "No error output")
        return False


def test_binary_startup() -> bool:
    """Test that the binary starts and responds to ping."""
    if not BATCH_IPC_BIN.exists():
        print("❌ Binary not found")
        return False
    
    print("Testing binary startup...")
    
    try:
        proc = subprocess.Popen(
            [str(BATCH_IPC_BIN)],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        
        # Read startup banner
        banner = proc.stdout.readline()
        print(f"  Banner: {banner.strip()}")
        
        if "started" not in banner and "batch_ipc" not in banner:
            print("❌ Unexpected startup banner")
            proc.terminate()
            return False
        
        # Test ping
        proc.stdin.write('{"op":"ping"}\n')
        proc.stdin.flush()
        response = proc.stdout.readline()
        print(f"  Ping response: {response.strip()}")
        
        if "pong" in response:
            print("✅ Binary responds to ping")
        else:
            print("❌ Binary did not respond correctly to ping")
            proc.terminate()
            return False
        
        # Quit
        proc.stdin.write('{"op":"quit"}\n')
        proc.stdin.flush()
        proc.wait(timeout=5)
        
        return True
        
    except Exception as e:
        print(f"❌ Binary test failed: {e}")
        return False


def test_batch_mode() -> bool:
    """Test batch command execution."""
    if not BATCH_IPC_BIN.exists():
        print("❌ Binary not found")
        return False
    
    print("Testing batch mode...")
    
    try:
        proc = subprocess.Popen(
            [str(BATCH_IPC_BIN)],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        
        # Skip banner
        proc.stdout.readline()
        
        # Send batch request
        import json
        batch_request = {
            "mode": "sequential",
            "request_id": "test_001",
            "commands": [
                {"id": 0, "op": "ping", "payload": "{}"},
                {"id": 1, "op": "status", "payload": "{}"},
                {"id": 2, "op": "emit", "payload": "{\"type\":\"test\"}"},
            ]
        }
        
        proc.stdin.write(json.dumps(batch_request) + "\n")
        proc.stdin.flush()
        
        response = proc.stdout.readline()
        print(f"  Batch response: {response.strip()[:200]}...")
        
        data = json.loads(response)
        
        if "results" in data and len(data["results"]) == 3:
            print(f"✅ Batch returned {len(data['results'])} results")
            for r in data["results"]:
                print(f"    - id={r['id']}, status={r['status']}, latency={r['latency_ms']:.3f}ms")
        else:
            print("❌ Batch response missing results")
            proc.terminate()
            return False
        
        # Quit
        proc.stdin.write('{"op":"quit"}\n')
        proc.stdin.flush()
        proc.wait(timeout=5)
        
        return True
        
    except Exception as e:
        print(f"❌ Batch test failed: {e}")
        return False


def benchmark_batch_vs_single() -> dict:
    """Benchmark batch IPC vs single command IPC."""
    print("\n📊 Benchmarking batch vs single command latency...")
    
    if not BATCH_IPC_BIN.exists():
        return {"error": "Binary not found"}
    
    try:
        proc = subprocess.Popen(
            [str(BATCH_IPC_BIN)],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
        )
        
        import json
        
        # Skip banner
        proc.stdout.readline()
        
        # Warmup
        for _ in range(10):
            proc.stdin.write('{"op":"ping"}\n')
            proc.stdin.flush()
            proc.stdout.readline()
        
        # Benchmark single commands
        single_latencies = []
        for _ in range(100):
            start = time.perf_counter()
            proc.stdin.write('{"op":"ping"}\n')
            proc.stdin.flush()
            proc.stdout.readline()
            elapsed_us = (time.perf_counter() - start) * 1_000_000
            single_latencies.append(elapsed_us)
        
        # Benchmark batch commands (10 per batch)
        batch_latencies = []
        batch_request = {
            "mode": "sequential",
            "request_id": "bench",
            "commands": [{"id": i, "op": "ping", "payload": "{}"} for i in range(10)]
        }
        batch_json = json.dumps(batch_request)
        
        for _ in range(100):
            start = time.perf_counter()
            proc.stdin.write(batch_json + "\n")
            proc.stdin.flush()
            proc.stdout.readline()
            elapsed_us = (time.perf_counter() - start) * 1_000_000
            batch_latencies.append(elapsed_us)
        
        # Quit
        proc.stdin.write('{"op":"quit"}\n')
        proc.stdin.flush()
        proc.wait(timeout=5)
        
        # Calculate stats
        single_avg = sum(single_latencies) / len(single_latencies)
        batch_avg = sum(batch_latencies) / len(batch_latencies)
        batch_per_cmd = batch_avg / 10
        
        speedup = single_avg / batch_per_cmd if batch_per_cmd > 0 else 0
        target_met = speedup >= 2.0  # 10 commands should be < 5x single (ideally ~2x per cmd)
        
        print(f"  Single command avg: {single_avg:.1f}µs")
        print(f"  Batch (10 cmds) avg: {batch_avg:.1f}µs")
        print(f"  Batch per-command: {batch_per_cmd:.1f}µs")
        print(f"  Speedup factor: {speedup:.2f}x")
        print(f"  Target (≥2x): {'✅ MET' if target_met else '❌ NOT MET'}")
        
        return {
            "single_avg_us": single_avg,
            "batch_avg_us": batch_avg,
            "batch_per_cmd_us": batch_per_cmd,
            "speedup_factor": speedup,
            "target_met": target_met,
        }
        
    except Exception as e:
        return {"error": str(e)}


def test_python_client() -> bool:
    """Test Python batch client."""
    print("\n🐍 Testing Python batch client...")
    
    try:
        from whitemagic.core.acceleration.koka_batch_client import (
            KokaBatchClient, BatchCommand, BatchMode
        )
        
        client = KokaBatchClient(binary_path=BATCH_IPC_BIN, auto_start=False)
        
        if not client._ensure_started():
            print("❌ Failed to start client")
            return False
        
        # Test single command
        result = client.execute("ping", {})
        print(f"  Single command: {result}")
        
        if "pong" not in result:
            print("❌ Single command failed")
            client.close()
            return False
        
        # Test batch
        batch = [
            BatchCommand("ping", {}),
            BatchCommand("status", {}),
            BatchCommand("emit", {"type": "test"}),
        ]
        
        response = client.execute_batch(batch, BatchMode.SEQUENTIAL)
        print(f"  Batch: {response.commands_processed} commands processed")
        
        if response.commands_processed != 3:
            print("❌ Batch command failed")
            client.close()
            return False
        
        print("✅ Python client works")
        client.close()
        return True
        
    except ImportError as e:
        print(f"❌ Import error: {e}")
        return False
    except Exception as e:
        print(f"❌ Client test failed: {e}")
        return False


def main():
    print("=" * 60)
    print("VC-01 Verification: Batch IPC Protocol")
    print("=" * 60)
    
    results = {}
    
    # 1. Check Koka available
    print("\n1️⃣ Checking Koka availability...")
    results["koka_available"] = check_koka_available()
    if results["koka_available"]:
        print("✅ Koka compiler found")
    else:
        print("❌ Koka compiler not found - skipping compilation")
    
    # 2. Compile batch_ipc
    if results["koka_available"]:
        print("\n2️⃣ Compiling batch_ipc.kk...")
        results["compiles"] = compile_batch_ipc()
    else:
        results["compiles"] = False
    
    # 3. Test binary startup
    if results["compiles"] or BATCH_IPC_BIN.exists():
        print("\n3️⃣ Testing binary startup...")
        results["binary_starts"] = test_binary_startup()
    else:
        results["binary_starts"] = False
    
    # 4. Test batch mode
    if results["binary_starts"]:
        print("\n4️⃣ Testing batch mode...")
        results["batch_mode_works"] = test_batch_mode()
    else:
        results["batch_mode_works"] = False
    
    # 5. Test Python client
    if results["binary_starts"]:
        results["python_client_works"] = test_python_client()
    else:
        results["python_client_works"] = False
    
    # 6. Benchmark
    if results["binary_starts"]:
        results["benchmark"] = benchmark_batch_vs_single()
    else:
        results["benchmark"] = {"error": "binary not available"}
    
    # Summary
    print("\n" + "=" * 60)
    print("VERIFICATION SUMMARY")
    print("=" * 60)
    
    checks = [
        ("Koka available", results.get("koka_available", False)),
        ("Batch IPC compiles", results.get("compiles", False)),
        ("Binary starts", results.get("binary_starts", False)),
        ("Batch mode works", results.get("batch_mode_works", False)),
        ("Python client works", results.get("python_client_works", False)),
        ("Benchmark target met", results.get("benchmark", {}).get("target_met", False)),
    ]
    
    passed = sum(1 for _, v in checks if v)
    total = len(checks)
    
    for name, status in checks:
        print(f"  {'✅' if status else '❌'} {name}")
    
    print(f"\nScore: {passed}/{total}")
    
    # VC-01 criteria
    print("\n📋 VC-01 Verification Criteria:")
    print("  [ ] Implement multi-command batching in Koka binaries")
    print("  [ ] Single write for N commands, N reads for responses")
    print("  [ ] Benchmark: batch of 10 commands < 5x single command latency")
    print("  [ ] Update gan_ying.kk, hot_paths.kk, unified_runtime.kk")
    print("  [ ] Python client support in hybrid_dispatcher_v2.py")
    
    return results


if __name__ == "__main__":
    results = main()
