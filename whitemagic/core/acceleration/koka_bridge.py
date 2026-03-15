"""Koka Bridge - Python interface to Koka binaries.

Provides high-level Python API for all Koka runtime binaries.
"""

import json
import queue
import subprocess
import threading
from typing import List, Dict, Any, Optional
from dataclasses import dataclass

_DEFAULT_KOKA_BRIDGE_TIMEOUT_S = 5.0


@dataclass
class KokaProcess:
    name: str
    proc: subprocess.Popen
    
    def _readline_with_timeout(self, timeout: float = _DEFAULT_KOKA_BRIDGE_TIMEOUT_S) -> str | None:
        result_queue: queue.Queue[str | None] = queue.Queue(maxsize=1)

        def _reader() -> None:
            try:
                result_queue.put(self.proc.stdout.readline())
            except Exception:
                result_queue.put(None)

        thread = threading.Thread(target=_reader, name=f"koka-bridge-{self.name}", daemon=True)
        thread.start()

        try:
            return result_queue.get(timeout=timeout)
        except queue.Empty:
            return None

    def send(self, cmd: dict, timeout: float = _DEFAULT_KOKA_BRIDGE_TIMEOUT_S) -> dict:
        """Send command and receive response."""
        self.proc.stdin.write(json.dumps(cmd) + "\n")
        self.proc.stdin.flush()
        response = self._readline_with_timeout(timeout=timeout)
        if not response:
            raise TimeoutError(f"Koka bridge timed out waiting for response from {self.name}")
        return json.loads(response)
    
    def close(self):
        try:
            self.send({"op": "quit"}, timeout=1.0)
        except Exception:
            pass
        try:
            self.proc.wait(timeout=1.0)
        except subprocess.TimeoutExpired:
            self.proc.kill()


class KokaRuntime:
    """Unified interface to all Koka binaries."""
    
    def __init__(self, koka_dir: str = "./whitemagic-koka"):
        self.koka_dir = koka_dir
        self.processes: Dict[str, KokaProcess] = {}
        
    def start_unified_runtime(self) -> KokaProcess:
        """Start unified runtime v3."""
        proc = subprocess.Popen(
            [f"{self.koka_dir}/unified_runtime_v3"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            text=True
        )
        koka_proc = KokaProcess("unified_runtime_v3", proc)
        # Read startup message with timeout
        startup = koka_proc._readline_with_timeout(timeout=2.0)
        if not startup:
            proc.kill()
            raise TimeoutError("unified_runtime_v3 startup timed out")
        self.processes["unified"] = koka_proc
        return koka_proc
    
    def start_ring_buffer(self) -> KokaProcess:
        """Start ring buffer."""
        proc = subprocess.Popen(
            [f"{self.koka_dir}/ring_buffer"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            text=True
        )
        koka_proc = KokaProcess("ring_buffer", proc)
        startup = koka_proc._readline_with_timeout(timeout=2.0)
        if not startup:
            proc.kill()
            raise TimeoutError("ring_buffer startup timed out")
        self.processes["ring_buffer"] = koka_proc
        return koka_proc
    
    def start_rust_bridge(self) -> KokaProcess:
        """Start rust bridge."""
        proc = subprocess.Popen(
            [f"{self.koka_dir}/rust_bridge"],
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            text=True
        )
        koka_proc = KokaProcess("rust_bridge", proc)
        startup = koka_proc._readline_with_timeout(timeout=2.0)
        if not startup:
            proc.kill()
            raise TimeoutError("rust_bridge startup timed out")
        self.processes["rust_bridge"] = koka_proc
        return koka_proc
    
    def batch_write_embeddings(self, embeddings: List[List[float]], ids: List[int]) -> dict:
        """Batch write embeddings via ring buffer."""
        if "ring_buffer" not in self.processes:
            self.start_ring_buffer()
        
        rb = self.processes["ring_buffer"]
        return rb.send({
            "op": "batch_write",
            "count": len(embeddings)
        })
    
    def emit_event(self, source: str, event_type: str) -> dict:
        """Emit event via effect runtime."""
        if "unified" not in self.processes:
            self.start_unified_runtime()
        
        return self.processes["unified"].send({
            "op": "emit",
            "source": source,
            "event": event_type
        })
    
    def cosine_similarity(self, a: List[float], b: List[float]) -> float:
        """Compute cosine similarity via rust bridge."""
        if "rust_bridge" not in self.processes:
            self.start_rust_bridge()
        
        result = self.processes["rust_bridge"].send({
            "op": "cosine",
            "a": a,
            "b": b
        })
        return result.get("cosine_sim", 0.0)
    
    def close_all(self):
        """Close all Koka processes."""
        for proc in self.processes.values():
            proc.close()
        self.processes.clear()
