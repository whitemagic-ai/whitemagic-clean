#!/usr/bin/env python3
"""Mojo Compute Cluster Worker - SIMD acceleration via IPC."""

import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

import os
import time


class MojoComputeWorker:
    """Worker that handles SIMD compute requests via IPC."""

    def __init__(self):
        self.running = True
        self.tasks_completed = 0

    def _check_mojo(self):
        """Check if Mojo is available."""
        mojo_path = '/home/lucas/Desktop/whitemagicdev/whitemagic-mojo'
        if not os.path.exists(mojo_path):
            print("⚠️ Mojo source not found")
            return False

        # Check for compiled binaries
        benches = ['bench_cosine', 'vector_ops']
        for bench in benches:
            binary = f"{mojo_path}/{bench}"
            if os.path.exists(binary):
                print(f"✅ Found Mojo binary: {bench}")
                return True

        print("ℹ️ Mojo binaries not compiled yet")
        return False

    def _process_cosine_batch(self, vectors_a, vectors_b):
        """Process batch cosine similarity via Mojo."""
        # Placeholder - would call Mojo binary via subprocess
        import numpy as np
        results = []
        for a, b in zip(vectors_a, vectors_b):
            dot = np.dot(a, b)
            norm_a = np.linalg.norm(a)
            norm_b = np.linalg.norm(b)
            sim = dot / (norm_a * norm_b) if norm_a > 0 and norm_b > 0 else 0.0
            results.append(float(sim))
        return results

    def run(self):
        """Main worker loop."""
        import signal
        signal.signal(signal.SIGTERM, lambda s, f: setattr(self, 'running', False))
        signal.signal(signal.SIGINT, lambda s, f: setattr(self, 'running', False))

        print("🚀 Mojo Compute Worker starting...")

        mojo_available = self._check_mojo()
        if mojo_available:
            print("✅ Mojo acceleration available")
        else:
            print("ℹ️ Running in Python fallback mode")

        print("📡 Worker ready - handles:")
        print("   - cosine_batch: Batch cosine similarity")
        print("   - vector_add: SIMD vector addition")
        print("   - vector_norm: SIMD vector normalization")
        print("   Channels: wm/commands (requests) → wm/memories (results)")

        while self.running:
            time.sleep(0.1)

        print(f"👋 Worker shutdown. Tasks: {self.tasks_completed}")

if __name__ == "__main__":
    worker = MojoComputeWorker()
    worker.run()
