"""
H003: Rust ONNX Bridge for V17 Optimizer
=========================================
Arrow IPC bridge to Rust ONNX embedder for 2-3x speedup.

This is an optional enhancement to V17. V17 alone achieves 1,216/sec.
With Rust ONNX: 2,500-3,500/sec expected.
"""
import asyncio
import json
import logging
import subprocess
from pathlib import Path
from typing import List

try:
    import pyarrow as pa
    HAS_PYARROW = True
except ImportError:
    HAS_PYARROW = False

logger = logging.getLogger(__name__)

# Path to Rust binary (built from whitemagic-rust)
RUST_BINARY = Path(__file__).parent.parent.parent.parent / "whitemagic-rust" / "target" / "release" / "h003-onnx-embedder"


class RustOnnxBridge:
    """Zero-copy bridge to Rust ONNX embedder via Arrow IPC"""
    
    def __init__(self) -> None:
        self._available = self._check_binary()
        if not self._available:
            logger.warning("Rust ONNX binary not available, falling back to Python")
    
    def _check_binary(self) -> bool:
        """Check if Rust binary exists and is executable"""
        if not RUST_BINARY.exists():
            # Try debug build
            debug_binary = Path(str(RUST_BINARY).replace("release", "debug"))
            if debug_binary.exists():
                return True
            return False
        return True
    
    def available(self) -> bool:
        """Check if bridge is available"""
        return self._available and HAS_PYARROW
    
    def encode_batch(self, texts: list[str]) -> list[list[float]]:
        """
        Encode batch of texts using Rust ONNX runtime.
        
        Args:
            texts: List of text strings to encode
            
        Returns:
            List of embedding vectors (384-dim for MiniLM-L6-v2)
        """
        if not self.available():
            raise RuntimeError("Rust ONNX bridge not available")
        
        if not HAS_PYARROW:
            raise RuntimeError("pyarrow required for Arrow IPC serialization")
        
        # Serialize to Arrow IPC
        batch = pa.record_batch([pa.array(texts)], names=["text"])
        
        # Write to memory buffer
        sink = pa.BufferOutputStream()
        with pa.ipc.new_stream(sink, batch.schema) as writer:
            writer.write_batch(batch)
        
        ipc_bytes = sink.getvalue().to_pybytes()
        
        # Determine binary path
        binary_path = RUST_BINARY
        if not binary_path.exists():
            binary_path = Path(str(RUST_BINARY).replace("release", "debug"))
        
        # Spawn Rust process with Arrow IPC via stdin/stdout
        try:
            result = subprocess.run(
                [str(binary_path)],
                input=ipc_bytes,
                capture_output=True,
                timeout=300,  # 5 minute timeout for large batches
            )
            
            if result.returncode != 0:
                stderr = result.stderr.decode('utf-8', errors='replace')
                raise RuntimeError(f"Rust ONNX failed: {stderr}")
            
            # Parse JSON output from Rust ONNX embedder
            output = json.loads(result.stdout.decode('utf-8'))
            
            # Extract embeddings from output
            if 'embeddings' in output:
                return output['embeddings']
            elif 'error' in output:
                raise RuntimeError(f"Rust ONNX error: {output['error']}")
            else:
                # Fallback: parse from legacy format
                return [[float(x) for x in emb] for emb in output.get('vectors', [])]
            
        except subprocess.TimeoutExpired:
            raise RuntimeError("Rust ONNX timed out after 5 minutes")
        except json.JSONDecodeError as e:
            raise RuntimeError(f"Failed to parse Rust output: {e}")
    
    async def encode_batch_async(self, texts: list[str]) -> list[list[float]]:
        """Async wrapper for encode_batch"""
        loop = asyncio.get_event_loop()
        return await loop.run_in_executor(None, self.encode_batch, texts)


# Singleton instance
_bridge: RustOnnxBridge | None = None


def get_rust_onnx_bridge() -> RustOnnxBridge:
    """Get or create Rust ONNX bridge singleton"""
    global _bridge
    if _bridge is None:
        _bridge = RustOnnxBridge()
    return _bridge
