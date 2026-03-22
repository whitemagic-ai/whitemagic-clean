#!/usr/bin/env python3
"""Production Deployment Script - Koka Runtime Infrastructure

Deploys the complete Koka runtime infrastructure to production.
"""

import json
import subprocess
import sys
from pathlib import Path
from typing import Any


class KokaProductionDeployer:
    """Deploy Koka infrastructure to production."""

    def __init__(self, root_dir: Path):
        self.root_dir = Path(root_dir)
        self.koka_dir = root_dir / "whitemagic-koka"
        self.results: dict[str, Any] = {
            "binaries": [],
            "python_modules": [],
            "integration_points": [],
            "status": "pending"
        }

    def verify_binaries(self) -> bool:
        """Verify all binaries exist and are executable."""
        print("[Deploy] Verifying binaries...")

        binaries = [
            "orchestrator", "unified_runtime_v3", "effect_runtime",
            "ring_buffer", "rust_bridge", "metrics",
            "prat", "gan_ying", "hot_paths", "resonance"
        ]

        all_ok = True
        for binary in binaries:
            path = self.koka_dir / binary
            exists = path.exists()
            executable = path.stat().st_mode & 0o111 if exists else False

            status = "✓" if exists and executable else "✗"
            print(f"  {status} {binary}")

            if exists and executable:
                self.results["binaries"].append(binary)
            else:
                all_ok = False

        return all_ok

    def verify_python_modules(self) -> bool:
        """Verify Python integration modules."""
        print("\n[Deploy] Verifying Python modules...")

        modules = [
            "whitemagic/core/acceleration/koka_bridge.py",
            "whitemagic/core/acceleration/koka_async.py",
            "whitemagic/core/acceleration/koka_metrics.py",
            "whitemagic/core/acceleration/rust_bridge_ipc.py"
        ]

        all_ok = True
        for module in modules:
            path = self.root_dir / module
            exists = path.exists()

            status = "✓" if exists else "✗"
            print(f"  {status} {module}")

            if exists:
                self.results["python_modules"].append(module)
            else:
                all_ok = False

        return all_ok

    def verify_hot_path_integration(self) -> bool:
        """Verify hot path files are wired to Koka."""
        print("\n[Deploy] Verifying hot path integration...")

        files = [
            "whitemagic/core/memory/surprise_gate_hot_path.py",
            "whitemagic/core/memory/embedding_index_hot_path.py"
        ]

        all_ok = True
        for file in files:
            path = self.root_dir / file
            if path.exists():
                content = path.read_text()
                has_koka = "KokaRuntime" in content or "_KOKA_AVAILABLE" in content

                status = "✓" if has_koka else "✗"
                print(f"  {status} {file} {'(Koka wired)' if has_koka else '(NOT wired)'}")

                if has_koka:
                    self.results["integration_points"].append(file)
                else:
                    all_ok = False
            else:
                print(f"  ✗ {file} (not found)")
                all_ok = False

        return all_ok

    def test_basic_ipc(self) -> bool:
        """Test basic IPC with ring_buffer."""
        print("\n[Deploy] Testing basic IPC...")

        try:
            proc = subprocess.Popen(
                [str(self.koka_dir / "ring_buffer")],
                stdin=subprocess.PIPE,
                stdout=subprocess.PIPE,
                text=True
            )

            # Read startup
            proc.stdout.readline()

            # Test write
            proc.stdin.write('{"op":"write"}\n')
            proc.stdin.flush()
            response = proc.stdout.readline()

            # Quit
            proc.stdin.write('{"op":"quit"}\n')
            proc.stdin.flush()
            proc.wait()

            result = json.loads(response)
            success = result.get("status") == "written"

            status = "✓" if success else "✗"
            print(f"  {status} ring_buffer IPC test")

            return success

        except Exception as e:
            print(f"  ✗ IPC test failed: {e}")
            return False

    def deploy(self) -> dict[str, Any]:
        """Run full deployment verification."""
        print("=" * 70)
        print("KOKA PRODUCTION DEPLOYMENT")
        print("=" * 70)

        checks = [
            ("Binaries", self.verify_binaries()),
            ("Python Modules", self.verify_python_modules()),
            ("Hot Path Integration", self.verify_hot_path_integration()),
            ("Basic IPC", self.test_basic_ipc())
        ]

        all_passed = all(passed for _, passed in checks)

        print("\n" + "=" * 70)
        print("DEPLOYMENT SUMMARY")
        print("=" * 70)

        for name, passed in checks:
            status = "PASS" if passed else "FAIL"
            print(f"  [{status}] {name}")

        self.results["status"] = "ready" if all_passed else "failed"

        print(f"\nOverall Status: {self.results['status'].upper()}")
        print(f"  Binaries: {len(self.results['binaries'])} ready")
        print(f"  Python modules: {len(self.results['python_modules'])} ready")
        print(f"  Integration points: {len(self.results['integration_points'])} wired")

        if all_passed:
            print("\n✓ Production deployment ready!")
            print("\nNext steps:")
            print("  1. Import koka_bridge in your Python code")
            print("  2. Use KokaRuntime() for high-level API")
            print("  3. Use koka_async for non-blocking operations")
            print("  4. Monitor metrics via koka_metrics")
        else:
            print("\n✗ Deployment has issues - review failures above")

        print("=" * 70)

        return self.results


def main():
    """Run deployment."""
    root_dir = Path(__file__).parent.parent

    deployer = KokaProductionDeployer(root_dir)
    results = deployer.deploy()

    # Save results
    results_path = root_dir / "reports" / "koka_deployment_status.json"
    with open(results_path, "w") as f:
        json.dump(results, f, indent=2)
    print(f"\nDeployment status saved to: {results_path}")

    return 0 if results["status"] == "ready" else 1


if __name__ == "__main__":
    sys.exit(main())
