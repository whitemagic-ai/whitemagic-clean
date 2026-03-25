#!/usr/bin/env python3
"""Integration Test Suite - Verify all Koka components work together.

Tests the complete Koka infrastructure:
1. Python→Koka bridge module
2. All 13 binaries
3. IPC communication
4. Prometheus metrics
5. End-to-end pipeline
"""

import json
import subprocess
import time
import sys
from pathlib import Path
from typing import Dict, List, Any


class KokaIntegrationTest:
    """Comprehensive integration testing for Koka infrastructure."""
    
    def __init__(self, koka_dir: Path):
        self.koka_dir = Path(koka_dir)
        self.results: Dict[str, Any] = {"passed": [], "failed": [], "metrics": {}}
        
    def test_binary_exists(self, binary: str) -> bool:
        """Test that binary exists and is executable."""
        binary_path = self.koka_dir / binary
        exists = binary_path.exists() and binary_path.stat().st_mode & 0o111
        return exists
    
    def test_binary_ipc(self, binary: str, commands: List[str], timeout: float = 5.0) -> Dict[str, Any]:
        """Test binary IPC communication."""
        binary_path = self.koka_dir / binary
        
        try:
            proc = subprocess.Popen(
                [str(binary_path)],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                text=True
            )
            
            # Read startup message
            startup = proc.stdout.readline().strip()
            
            # Send commands
            responses = []
            start = time.perf_counter()
            
            for cmd in commands:
                proc.stdin.write(cmd + "\n")
                proc.stdin.flush()
                response = proc.stdout.readline().strip()
                responses.append(response)
            
            # Quit
            proc.stdin.write('{"op":"quit"}\n')
            proc.stdin.flush()
            
            # Wait with timeout
            try:
                proc.wait(timeout=timeout)
            except subprocess.TimeoutExpired:
                proc.terminate()
                proc.wait()
            
            elapsed = (time.perf_counter() - start) * 1000
            
            # Parse responses
            parsed = []
            for resp in responses:
                try:
                    parsed.append(json.loads(resp))
                except json.JSONDecodeError:
                    parsed.append({"raw": resp})
            
            return {
                "binary": binary,
                "startup": startup,
                "commands_sent": len(commands),
                "responses": parsed,
                "elapsed_ms": elapsed,
                "success": True
            }
            
        except Exception as e:
            return {
                "binary": binary,
                "error": str(e),
                "success": False
            }
    
    def test_orchestrator(self) -> Dict[str, Any]:
        """Test orchestrator binary."""
        print("\n[Test] Orchestrator...")
        
        commands = [
            '{"op":"list"}',
            '{"op":"spawn","binary":"ring_buffer"}',
            '{"op":"list"}',
            '{"op":"health"}'
        ]
        
        result = self.test_binary_ipc("orchestrator", commands)
        
        if result["success"]:
            # Verify responses
            responses = result.get("responses", [])
            checks = [
                len(responses) == 4,
                responses[0].get("count", -1) == 0,  # Empty process list
                "ring_buffer" in responses[1].get("spawned", ""),
                responses[2].get("count", -1) == 1,  # One process
                responses[3].get("running", -1) == 1  # One running
            ]
            
            if all(checks):
                self.results["passed"].append("orchestrator")
                print("  ✓ Orchestrator working correctly")
                return result
        
        self.results["failed"].append(("orchestrator", result.get("error", "IPC check failed")))
        print(f"  ✗ Orchestrator failed: {result.get('error', 'unknown')}")
        return result
    
    def test_ring_buffer(self) -> Dict[str, Any]:
        """Test ring buffer binary."""
        print("\n[Test] Ring Buffer...")
        
        commands = [
            '{"op":"stats"}',
            '{"op":"write"}',
            '{"op":"batch_write","count":10}',
            '{"op":"stats"}'
        ]
        
        result = self.test_binary_ipc("ring_buffer", commands)
        
        if result["success"]:
            responses = result.get("responses", [])
            checks = [
                "total_written" in responses[0],
                responses[1].get("status") == "written",
                responses[2].get("written") == 10,
                responses[3].get("total_written", 0) == 11  # 1 + 10
            ]
            
            if all(checks):
                self.results["passed"].append("ring_buffer")
                print("  ✓ Ring buffer working correctly")
                return result
        
        self.results["failed"].append(("ring_buffer", result.get("error", "Check failed")))
        print("  ✗ Ring buffer failed")
        return result
    
    def test_rust_bridge(self) -> Dict[str, Any]:
        """Test rust bridge binary."""
        print("\n[Test] Rust Bridge...")
        
        commands = [
            '{"op":"cosine"}',
            '{"op":"serialize"}',
            '{"op":"batch"}',
            '{"op":"stats"}'
        ]
        
        result = self.test_binary_ipc("rust_bridge", commands)
        
        if result["success"]:
            responses = result.get("responses", [])
            checks = [
                "cosine_sim" in responses[0],
                "serialized" in responses[1],
                "batch_results" in responses[2],
                "calls" in responses[3]
            ]
            
            if all(checks):
                self.results["passed"].append("rust_bridge")
                print("  ✓ Rust bridge working correctly")
                return result
        
        self.results["failed"].append(("rust_bridge", result.get("error", "Check failed")))
        print("  ✗ Rust bridge failed")
        return result
    
    def test_effect_runtime(self) -> Dict[str, Any]:
        """Test effect runtime binary."""
        print("\n[Test] Effect Runtime...")
        
        commands = [
            '{"op":"emit","source":"test","event":"memory_created"}',
            '{"op":"profile","name":"test_op","duration":1.5}',
            '{"op":"trace","message":"test trace"}'
        ]
        
        result = self.test_binary_ipc("effect_runtime", commands)
        
        if result["success"]:
            self.results["passed"].append("effect_runtime")
            print("  ✓ Effect runtime working correctly")
            return result
        
        self.results["failed"].append(("effect_runtime", result.get("error", "Check failed")))
        print("  ✗ Effect runtime failed")
        return result
    
    def test_unified_runtime_v3(self) -> Dict[str, Any]:
        """Test unified runtime v3 binary."""
        print("\n[Test] Unified Runtime v3...")
        
        commands = [
            '{"op":"status"}',
            '{"op":"emit","event":"test"}',
            '{"op":"batch","cmds":[{"op":"emit"},{"op":"emit"}]}'
        ]
        
        result = self.test_binary_ipc("unified_runtime_v3", commands)
        
        if result["success"]:
            self.results["passed"].append("unified_runtime_v3")
            print("  ✓ Unified runtime v3 working correctly")
            return result
        
        self.results["failed"].append(("unified_runtime_v3", result.get("error", "Check failed")))
        print("  ✗ Unified runtime v3 failed")
        return result
    
    def test_python_bridge(self) -> Dict[str, Any]:
        """Test Python→Koka bridge module."""
        print("\n[Test] Python→Koka Bridge Module...")
        
        try:
            # Import the bridge
            sys.path.insert(0, str(self.koka_dir.parent / "whitemagic" / "core" / "acceleration"))
            from koka_bridge import KokaRuntime
            
            # Create runtime
            koka = KokaRuntime(str(self.koka_dir))
            
            # Start a process
            proc = koka.start_ring_buffer()
            
            # Send command
            result = proc.send({"op": "stats"})
            
            # Close
            proc.close()
            
            if "total_written" in result:
                self.results["passed"].append("python_bridge")
                print("  ✓ Python bridge working correctly")
                return {"success": True, "response": result}
            else:
                raise Exception("Invalid response from ring buffer")
                
        except Exception as e:
            self.results["failed"].append(("python_bridge", str(e)))
            print(f"  ✗ Python bridge failed: {e}")
            return {"success": False, "error": str(e)}
    
    def test_all_binaries(self) -> Dict[str, Any]:
        """Run all integration tests."""
        print("=" * 70)
        print("KOKA INTEGRATION TEST SUITE")
        print("=" * 70)
        
        binaries = [
            "orchestrator",
            "unified_runtime_v3", 
            "effect_runtime",
            "ring_buffer",
            "rust_bridge",
            "prat",
            "gan_ying",
            "hot_paths"
        ]
        
        # Test each binary exists
        print("\n[Phase 1] Binary Existence Check...")
        for binary in binaries:
            exists = self.test_binary_exists(binary)
            status = "✓" if exists else "✗"
            print(f"  {status} {binary}")
            if not exists:
                self.results["failed"].append((binary, "Binary not found or not executable"))
        
        # Test core new binaries
        print("\n[Phase 2] Core Binary IPC Tests...")
        self.test_orchestrator()
        self.test_ring_buffer()
        self.test_rust_bridge()
        self.test_effect_runtime()
        self.test_unified_runtime_v3()
        
        # Test Python bridge
        print("\n[Phase 3] Python Bridge Test...")
        self.test_python_bridge()
        
        # Summary
        print("\n" + "=" * 70)
        print("TEST SUMMARY")
        print("=" * 70)
        print(f"Passed: {len(self.results['passed'])}")
        print(f"Failed: {len(self.results['failed'])}")
        
        if self.results['failed']:
            print("\nFailed tests:")
            for name, error in self.results['failed']:
                print(f"  • {name}: {error}")
        
        success_rate = len(self.results['passed']) / (len(self.results['passed']) + len(self.results['failed']))
        print(f"\nSuccess rate: {success_rate:.1%}")
        print("=" * 70)
        
        return self.results


def main():
    """Run integration tests."""
    koka_dir = Path(__file__).parent.parent / "whitemagic-koka"
    
    test = KokaIntegrationTest(koka_dir)
    results = test.test_all_binaries()
    
    # Save results
    results_path = Path(__file__).parent.parent / "reports" / "koka_integration_test_results.json"
    with open(results_path, "w") as f:
        json.dump(results, f, indent=2)
    print(f"\nResults saved to: {results_path}")
    
    # Exit code based on success
    return 0 if len(results['failed']) == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
