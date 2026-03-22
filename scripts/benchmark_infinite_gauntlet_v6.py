"""WhiteMagic Infinite Gauntlet v6 — Extreme Limit Testing.
=========================================================
Pushes the system to absolute hardware limits:
- Micro/Nano/Femto second operation profiling.
- Massive parallel clone deployment (Millions of threads).
- Stress-testing the 5D Holographic index and PRAT router.
- Nanosecond-scale overhead analysis of the tool dispatch pipeline.
"""

import asyncio
import json
import logging
import os
import statistics
import sys
import time
from datetime import datetime
from pathlib import Path

# Ensure root is in path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

import whitemagic_rust as rs

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("infinite_gauntlet")

class InfiniteGauntlet:
    def __init__(self, quick=False):
        self.results = []
        self.quick = quick
        self.hardware_profile = self._get_hardware_profile()

    def _get_hardware_profile(self):
        return {
            "cores": os.cpu_count(),
            "timestamp": datetime.now().isoformat(),
        }

    def _fmt_ns(self, ns):
        if ns < 1: return f"{ns*1000:.2f}ps"
        if ns < 1000: return f"{ns:.2f}ns"
        if ns < 1_000_000: return f"{ns/1000:.2f}µs"
        return f"{ns/1_000_000:.2f}ms"

    def profile_nanoseconds(self, label, fn, iterations=10000):
        """Profile high-frequency operations at nanosecond resolution."""
        logger.info(f"🔬 Nano-Profiling: {label} ({iterations} iters)...")
        times = []
        for _ in range(iterations):
            start = time.perf_counter_ns()
            fn()
            times.append(time.perf_counter_ns() - start)
        
        median = statistics.median(times)
        p99 = sorted(times)[int(len(times) * 0.99)]
        logger.info(f"  Result: median={self._fmt_ns(median)}, p99={self._fmt_ns(p99)}")
        self.results.append({
            "label": label,
            "type": "nano_profile",
            "median_ns": median,
            "p99_ns": p99,
            "iterations": iterations
        })

    async def stress_parallelism(self, label, count=100000):
        """Test massive parallel execution limits."""
        logger.info(f"⚔️ Parallel Stress: {label} ({count} clones)...")
        start = time.perf_counter()
        
        # Test Rust Tokio Clone Army if available
        try:
            # Note: Rust function might return (elapsed_ms, rate)
            res = rs.tokio_clone_bench(count)
            elapsed = time.perf_counter() - start
            rate = count / elapsed
            logger.info(f"  Result: {elapsed:.2f}s, {rate/1e6:.2f}M clones/s")
            self.results.append({
                "label": label,
                "type": "parallel_stress",
                "count": count,
                "elapsed_s": elapsed,
                "rate_m_s": rate/1e6
            })
        except Exception as e:
            logger.error(f"  Parallel stress failed: {e}")

    def run_all(self):
        logger.info("🎬 Starting The Infinite Gauntlet (v6)...")
        
        # 1. Nano-profiling core overhead (Memory & Dispatch)
        from whitemagic.tools.dispatch_table import DISPATCH_TABLE
        tools = list(DISPATCH_TABLE.keys())
        self.profile_nanoseconds("Dispatch Table Lookup", lambda: DISPATCH_TABLE.get(tools[0]), iterations=100000)
        
        from whitemagic.harmony.vector import get_harmony_vector
        hv = get_harmony_vector()
        self.profile_nanoseconds("Harmony Vector Snapshot", lambda: hv.snapshot(), iterations=50000)

        # 2. Rust Hot-Paths (Holographic & SIMD)
        import json as _json
        _holo_input = _json.dumps({"id":"t","content":"test memory content for holographic encoding","importance":0.8,"access_count":1,"age_days":1.0,"galactic_distance":0.1})
        self.profile_nanoseconds("Rust 5D Holographic Encode", lambda: rs.holographic_encoder_5d.holographic_encode_single(_holo_input))
        
        _vec_a = [0.1] * 128
        _vec_b = [0.2] * 128
        self.profile_nanoseconds("Rust SIMD Cosine (128-dim)", lambda: rs.rust_cosine_similarity(_vec_a, _vec_b))

        # 3. Massive Parallelism (Shadow Clones)
        # Hardware: 16-core CPU, 15GiB RAM
        clone_count = 1_000_000 if not self.quick else 100_000
        asyncio.run(self.stress_parallelism("Massive Tokio Clone Deployment", count=clone_count))
        
        # 4. PRAT Router Stress
        from whitemagic.tools.prat_router import route_prat_call
        self.profile_nanoseconds("PRAT Multi-Lane Routing", lambda: route_prat_call("gana_winnowing_basket", tool="search_memories"), iterations=50000)

    def run_monte_carlo_world_events(self, scenario_prompt: str, clone_count: int = 100000):
        """Run a massive Monte Carlo simulation on world events using the Tokio Clone Army."""
        logger.info(f"🌌 Running World Event Simulation: {scenario_prompt} ({clone_count} clones)")
        start = time.perf_counter()
        
        try:
            # Using the direct Rust bridge for maximum throughput
            # We pass a mixed set of strategies to ensure diversity in the 'world event' paths
            strategies = ["analytical", "creative", "adversarial", "synthesis", "memory_grounded"]
            result_json = rs.tokio_deploy_clones(scenario_prompt, clone_count, strategies)
            result = json.loads(result_json)
            
            elapsed = time.perf_counter() - start
            rate = clone_count / elapsed
            
            logger.info(f"✅ Simulation Complete: {elapsed:.2f}s ({rate/1e6:.2f}M outcomes/s)")
            
            # Extract consensus
            winner = result.get("winner", {})
            avg_conf = result.get("avg_confidence", 0.0)
            
            print("\n" + "="*70)
            print(f"🌍 MONTE CARLO SIMULATION: {scenario_prompt}")
            print("="*70)
            print(f"Clones Deployed: {clone_count:,}")
            print(f"Average Confidence: {avg_conf:.4f}")
            print(f"Consensus Strategy: {winner.get('strategy')}")
            print(f"Consensus Response: {winner.get('response')}")
            print("="*70 + "\n")
            
            self.results.append({
                "label": f"Monte Carlo: {scenario_prompt}",
                "type": "monte_carlo_sim",
                "clone_count": clone_count,
                "elapsed_s": elapsed,
                "consensus": winner.get('response'),
                "confidence": avg_conf
            })
            
        except Exception as e:
            logger.error(f"❌ Simulation failed: {e}")

if __name__ == "__main__":
    quick_mode = "--quick" in sys.argv
    gauntlet = InfiniteGauntlet(quick=quick_mode)
    gauntlet.run_all()
    
    # Run the user-requested Monte Carlo simulations
    scenarios = [
        "Technological Progress: Impact of decentralized AGI on global energy markets by 2028",
        "Sociopolitical: Rebalancing of world order following the 'Cambrian AI Bubble Pop'",
        "Quantum Signaling: Stability regimes for linear optical gates in noisy personal ecosystems"
    ]
    
    sim_count = 50000 if quick_mode else 250000
    for scenario in scenarios:
        gauntlet.run_monte_carlo_world_events(scenario, clone_count=sim_count)
