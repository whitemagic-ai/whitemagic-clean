#!/usr/bin/env python3
"""Rust ONNX Embedding Worker - Separate process for embeddings via IPC."""

import sys

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

import os
import signal
import time


class RustONNXWorker:
    """Worker process that receives embed requests via IPC, returns results."""

    def __init__(self):
        self.running = True
        self.requests_processed = 0

    def _init_ipc(self):
        """Initialize IPC subscriber for embed requests."""
        from whitemagic.core.ipc_bridge import get_status, init_ipc

        result = init_ipc(f"onnx_worker_{os.getpid()}")
        print(f"IPC init: {result}")

        status = get_status()
        print(f"IPC status: {status}")
        return status.get('initialized', False)

    def _load_embedder(self):
        """Load Rust ONNX embedder."""
        try:
            import whitemagic_rs as rs
            # Check if onnx_embedder is available
            if hasattr(rs, 'OnnxEmbedder'):
                print("✅ Rust ONNX embedder available")
                return rs
            else:
                print("⚠️ Rust ONNX embedder not in build")
                return None
        except ImportError as e:
            print(f"❌ Cannot import whitemagic_rs: {e}")
            return None

    def _process_embed_request(self, text: str) -> list | None:
        """Process single embedding request."""
        try:
            # Fall back to Python embedder for now
            from whitemagic.core.memory.embeddings import get_embedder
            embedder = get_embedder()
            result = embedder.encode(text)
            return result.tolist() if hasattr(result, 'tolist') else result
        except Exception as e:
            print(f"Embed error: {e}")
            return None

    def run(self):
        """Main worker loop."""

        print("🚀 Rust ONNX Worker starting...")

        # Setup signal handlers
        signal.signal(signal.SIGTERM, lambda s, f: setattr(self, 'running', False))
        signal.signal(signal.SIGINT, lambda s, f: setattr(self, 'running', False))

        # Init IPC
        if not self._init_ipc():
            print("❌ IPC init failed, using direct mode")

        # Load embedder
        self._load_embedder()

        print("📡 Worker ready - waiting for requests via IPC...")
        print("   Subscribe to: wm/commands for embed_requests")
        print("   Publish to: wm/memories for embed_results")

        # Main loop - poll for IPC messages
        while self.running:
            # For now, sleep and wait
            # Full implementation would subscribe to IPC channel
            time.sleep(0.1)

        print(f"👋 Worker shutdown. Processed: {self.requests_processed}")

if __name__ == "__main__":
    worker = RustONNXWorker()
    worker.run()
