"""
H003: V17 + Rust ONNX Integration
==================================
Optional enhancement to V17 optimizer using Rust ONNX runtime.

Usage:
    optimizer = V17EmbeddingOptimizer(engine, use_rust_onnx=True)
    result = await optimizer.index_memories_v17(...)
"""
from __future__ import annotations

import logging
from typing import TYPE_CHECKING

if TYPE_CHECKING:
    from .v17_embedding_optimizer import V17EmbeddingOptimizer, EmbeddingTask

logger = logging.getLogger(__name__)

# Feature flag for Rust ONNX
ENABLE_RUST_ONNX = False  # Set to True when Rust binary is ready


def patch_v17_with_rust_onnx() -> None:
    """
    Monkey-patch V17 optimizer to support Rust ONNX backend.
    
    This adds an optional `use_rust_onnx` parameter to the optimizer
    that enables the Rust ONNX backend when available.
    """
    try:
        from . import v17_embedding_optimizer as v17
        from .rust_onnx_bridge import get_rust_onnx_bridge
        
        # Store original __init__
        original_init = v17.V17EmbeddingOptimizer.__init__
        
        def patched_init(self, engine, use_rust_onnx: bool = False) -> None:
            """Patched init with Rust ONNX support"""
            # Call original init
            original_init(self, engine)
            
            # Add Rust ONNX bridge if requested
            self._use_rust_onnx = use_rust_onnx and ENABLE_RUST_ONNX
            self._rust_bridge = None
            
            if self._use_rust_onnx:
                try:
                    self._rust_bridge = get_rust_onnx_bridge()
                    if not self._rust_bridge.available():
                        logger.warning(
                            "Rust ONNX requested but not available, "
                            "falling back to Python"
                        )
                        self._use_rust_onnx = False
                    else:
                        logger.info("Rust ONNX enabled for 2-3x speedup")
                except Exception as e:
                    logger.warning(f"Failed to initialize Rust ONNX: {e}")
                    self._use_rust_onnx = False
        
        # Store original _encode_single
        original_encode_single = v17.V17EmbeddingOptimizer._encode_single
        
        async def patched_encode_single(self, task: "EmbeddingTask") -> "EmbeddingTask":
            """Patched encode with Rust ONNX support"""
            if self._use_rust_onnx and self._rust_bridge:
                # Use Rust ONNX for encoding
                try:
                    import asyncio
                    
                    # Run Rust ONNX encode
                    result = await self._rust_bridge.encode_batch_async([task.text])
                    if result and len(result) > 0:
                        task.result = result[0]
                        return task
                except Exception as e:
                    logger.debug(f"Rust ONNX encode failed, falling back: {e}")
                    # Fall through to Python implementation
            
            # Use original Python implementation
            return await original_encode_single(self, task)
        
        # Apply patches
        v17.V17EmbeddingOptimizer.__init__ = patched_init
        v17.V17EmbeddingOptimizer._encode_single = patched_encode_single
        v17.V17EmbeddingOptimizer._use_rust_onnx = False  # Default
        v17.V17EmbeddingOptimizer._rust_bridge = None
        
        logger.info("H003: V17 + Rust ONNX integration patched")
        
    except Exception as e:
        logger.warning(f"Failed to patch V17 with Rust ONNX: {e}")


# Auto-patch on import if enabled
if ENABLE_RUST_ONNX:
    patch_v17_with_rust_onnx()
