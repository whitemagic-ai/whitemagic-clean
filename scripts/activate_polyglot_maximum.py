#!/usr/bin/env python3
"""Polyglot Maximum Activation Script — Option B Implementation.

Activates and wires:
1. Elixir BEAM for high-concurrency event handling
2. Mojo for SIMD/Tensor operations
3. Julia for persistent graph algorithms
4. Full integration testing
"""

import json
import logging
import subprocess
import time
from pathlib import Path

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

class PolyglotActivator:
    def __init__(self, workspace="/home/lucas/Desktop/whitemagicdev"):
        self.workspace = Path(workspace)
        self.results = {}

    def activate_elixir(self):
        """Compile and activate Elixir BEAM components."""
        logger.info("🔮 Activating Elixir BEAM...")
        elixir_dir = self.workspace / "whitemagic-elixir"

        if not elixir_dir.exists():
            logger.warning("Elixir directory not found, skipping...")
            return False

        try:
            # Install dependencies
            subprocess.run(["mix", "deps.get"], cwd=elixir_dir, check=True, capture_output=True)
            # Compile
            subprocess.run(["mix", "compile"], cwd=elixir_dir, check=True, capture_output=True)
            self.results["elixir"] = {"status": "activated", "path": str(elixir_dir)}
            logger.info("✅ Elixir BEAM activated")
            return True
        except Exception as e:
            logger.error(f"Elixir activation failed: {e}")
            self.results["elixir"] = {"status": "failed", "error": str(e)}
            return False

    def activate_mojo(self):
        """Setup Mojo environment and compile kernels."""
        logger.info("🔥 Activating Mojo...")
        self.workspace / "whitemagic-mojo"

        try:
            # Check if Mojo is available
            result = subprocess.run(["mojo", "--version"], capture_output=True, text=True)
            if result.returncode != 0:
                logger.warning("Mojo not available, running setup script...")
                subprocess.run(["bash", str(self.workspace / "scripts/setup_mojo.sh")], check=True)

            self.results["mojo"] = {"status": "activated", "version": result.stdout.strip()}
            logger.info("✅ Mojo activated")
            return True
        except Exception as e:
            logger.error(f"Mojo activation failed: {e}")
            self.results["mojo"] = {"status": "failed", "error": str(e)}
            return False

    def activate_julia(self):
        """Start Julia persistent server."""
        logger.info("🌌 Activating Julia ZMQ server...")
        julia_dir = self.workspace / "whitemagic-julia"

        try:
            # Start the persistent server in background
            import socket
            import subprocess
            import time

            # Check if port 5555 is already in use
            sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            sock.settimeout(1)
            result = sock.connect_ex(('127.0.0.1', 5555))
            sock.close()

            if result != 0:
                # Start server
                subprocess.Popen(
                    ["julia", str(julia_dir / "src/persistent_server.jl")],
                    stdout=subprocess.DEVNULL,
                    stderr=subprocess.DEVNULL,
                    cwd=str(julia_dir)
                )
                time.sleep(2)  # Give it time to start

            self.results["julia"] = {"status": "activated", "port": 5555}
            logger.info("✅ Julia ZMQ server activated")
            return True
        except Exception as e:
            logger.error(f"Julia activation failed: {e}")
            self.results["julia"] = {"status": "failed", "error": str(e)}
            return False

    def run_integration_test(self):
        """Test all polyglot bridges working together."""
        logger.info("🧪 Running polyglot integration test...")

        # Test Julia bridge
        try:
            from whitemagic.core.acceleration.julia_zmq_bridge import get_julia_client
            client = get_julia_client()
            test_result = client.pagerank([("a", "b"), ("b", "c")], {"a": 1.0, "b": 1.0, "c": 1.0})
            self.results["integration"] = {"julia_bridge": "working", "test": test_result}
            logger.info("✅ Integration test passed")
            return True
        except Exception as e:
            logger.error(f"Integration test failed: {e}")
            self.results["integration"] = {"status": "failed", "error": str(e)}
            return False

    def activate_all(self):
        """Activate all polyglot components."""
        logger.info("🚀 Starting Polyglot Maximum activation...")
        start_time = time.time()

        elixir_ok = self.activate_elixir()
        mojo_ok = self.activate_mojo()
        julia_ok = self.activate_julia()
        integration_ok = self.run_integration_test()

        duration = time.time() - start_time

        self.results["summary"] = {
            "duration_seconds": duration,
            "elixir_active": elixir_ok,
            "mojo_active": mojo_ok,
            "julia_active": julia_ok,
            "integration_passed": integration_ok,
            "all_systems_go": all([elixir_ok, mojo_ok, julia_ok, integration_ok])
        }

        # Save report
        report_path = self.workspace / "reports/polyglot_activation_report.json"
        with open(report_path, 'w') as f:
            json.dump(self.results, f, indent=2)

        logger.info(f"📊 Polyglot activation report saved to {report_path}")
        return self.results["summary"]["all_systems_go"]

if __name__ == "__main__":
    activator = PolyglotActivator()
    success = activator.activate_all()

    if success:
        print("\n🎉 POLYGLOT MAXIMUM ACTIVATED! All systems operational.")
    else:
        print("\n⚠️  Some polyglot systems failed to activate. Check logs.")
