"""Context-Aware Polyglot Router
================================
Automatically routes operations to optimal backend based on:
- Operation type (pattern matching, vector ops, tensor ops, etc.)
- Context (parallel, sequential, memory-bound, compute-bound)
- Available backends (Rust, Mojo, Zig, Elixir, Go, Julia, Haskell)

This enables automatic optimization without manual backend selection.
"""

import logging
from dataclasses import dataclass
from enum import Enum
from typing import Any, Optional

logger = logging.getLogger(__name__)


class Backend(Enum):
    """Available execution backends."""
    RUST = "rust"
    MOJO = "mojo"
    ZIG = "zig"
    JULIA = "julia"
    HASKELL = "haskell"
    ELIXIR = "elixir"
    GO = "go"
    PYTHON = "python"
    AUTO = "auto"


class OperationType(Enum):
    """Types of operations for context-aware routing."""
    PATTERN_MATCHING = "pattern_matching"
    VECTOR_OPS = "vector_ops"
    TENSOR_OPS = "tensor_ops"
    GRAPH_ALGORITHMS = "graph_algorithms"
    CONCURRENT_TASKS = "concurrent_tasks"
    NETWORK_IO = "network_io"
    FILE_IO = "file_io"
    PURE_TRANSFORMATION = "pure_transformation"
    SEARCH = "search"
    COMPRESSION = "compression"
    UNKNOWN = "unknown"


@dataclass
class RoutingContext:
    """Context information for routing decisions."""
    operation_type: OperationType
    data_size: int = 0
    parallel: bool = False
    memory_bound: bool = False
    compute_bound: bool = False
    latency_critical: bool = False
    metadata: dict[str, Any] | None = None


@dataclass
class BackendCapability:
    """Capability profile for a backend."""
    backend: Backend
    available: bool
    strengths: list[OperationType]
    relative_speed: float  # 1.0 = Python baseline
    startup_cost_ms: float


class ContextRouter:
    """Smart router that selects optimal backend based on operation context."""
    
    def __init__(self):
        self._backends: dict[Backend, BackendCapability] = {}
        self._check_backends()
        
    def _check_backends(self):
        """Check which backends are available and their capabilities."""
        
        # Rust - Fast for pattern matching, vector ops, file I/O
        rust_available = self._check_rust_available()
        
        self._backends[Backend.RUST] = BackendCapability(
            backend=Backend.RUST,
            available=rust_available,
            strengths=[
                OperationType.PATTERN_MATCHING,
                OperationType.VECTOR_OPS,
                OperationType.FILE_IO,
                OperationType.SEARCH,
                OperationType.COMPRESSION,
            ],
            relative_speed=100.0,  # 100x faster than Python for hot paths
            startup_cost_ms=0.01,
        )
        
        # Mojo - Fast for tensor ops, ML inference
        mojo_available = False
        try:
            from whitemagic.optimization.polyglot_router import get_router
            router = get_router()
            mojo_available = router._mojo_available
            if mojo_available:
                logger.info("🔥 Mojo backend available")
        except Exception:
            pass
        
        self._backends[Backend.MOJO] = BackendCapability(
            backend=Backend.MOJO,
            available=mojo_available,
            strengths=[
                OperationType.TENSOR_OPS,
                OperationType.VECTOR_OPS,
            ],
            relative_speed=50.0,  # 50x faster for tensor ops
            startup_cost_ms=0.1,
        )
        
        # Zig - Fast for SIMD, low-level operations
        zig_available = False
        try:
            from whitemagic.core.acceleration.simd_cosine import simd_status
            status = simd_status()
            zig_available = status.get("has_zig_simd", False)
            if zig_available:
                logger.info("⚡ Zig SIMD backend available")
        except Exception:
            pass
        
        self._backends[Backend.ZIG] = BackendCapability(
            backend=Backend.ZIG,
            available=zig_available,
            strengths=[
                OperationType.VECTOR_OPS,
                OperationType.FILE_IO,
            ],
            relative_speed=20.0,  # 20x faster for SIMD ops
            startup_cost_ms=0.01,
        )
        
        # Elixir - Fast for concurrent tasks
        elixir_available = self._check_elixir_available()
        
        self._backends[Backend.ELIXIR] = BackendCapability(
            backend=Backend.ELIXIR,
            available=elixir_available,
            strengths=[
                OperationType.CONCURRENT_TASKS,
            ],
            relative_speed=10.0,  # 10x faster for parallel tasks
            startup_cost_ms=50.0,  # Higher startup cost
        )
        
        # Go - Fast for network I/O
        go_available = self._check_go_available()
        
        self._backends[Backend.GO] = BackendCapability(
            backend=Backend.GO,
            available=go_available,
            strengths=[
                OperationType.NETWORK_IO,
                OperationType.CONCURRENT_TASKS,
            ],
            relative_speed=5.0,  # 5x faster for network ops
            startup_cost_ms=10.0,
        )
        
        # Julia - Fast for graph algorithms
        julia_available = self._check_julia_available()
        
        self._backends[Backend.JULIA] = BackendCapability(
            backend=Backend.JULIA,
            available=julia_available,
            strengths=[
                OperationType.GRAPH_ALGORITHMS,
            ],
            relative_speed=10.0,  # 10x faster for graph ops
            startup_cost_ms=100.0,  # High startup cost (JIT)
        )
        
        # Haskell - Fast for pure transformations
        haskell_available = self._check_haskell_available()
        
        self._backends[Backend.HASKELL] = BackendCapability(
            backend=Backend.HASKELL,
            available=haskell_available,
            strengths=[
                OperationType.PURE_TRANSFORMATION,
            ],
            relative_speed=3.0,  # 3x faster for pure functions
            startup_cost_ms=50.0,
        )
        
        # Python - Always available, baseline
        self._backends[Backend.PYTHON] = BackendCapability(
            backend=Backend.PYTHON,
            available=True,
            strengths=[OperationType.UNKNOWN],
            relative_speed=1.0,
            startup_cost_ms=0.0,
        )
    
    def route(self, context: RoutingContext) -> Backend:
        """Select optimal backend for given context.
        
        Args:
            context: Routing context with operation type and metadata
            
        Returns:
            Optimal backend for this operation
        """
        
        # Find backends that are good at this operation type
        candidates = [
            cap for cap in self._backends.values()
            if cap.available and context.operation_type in cap.strengths
        ]
        
        if not candidates:
            # No specialized backend, use Python
            return Backend.PYTHON
        
        # For latency-critical operations, prefer low startup cost
        if context.latency_critical:
            candidates.sort(key=lambda c: c.startup_cost_ms)
        else:
            # Otherwise, prefer highest relative speed
            candidates.sort(key=lambda c: c.relative_speed, reverse=True)
        
        selected = candidates[0]
        
        logger.debug(
            f"Routed {context.operation_type.value} to {selected.backend.value} "
            f"({selected.relative_speed:.1f}x speedup expected)"
        )
        
        return selected.backend
    
    def infer_operation_type(self, operation_name: str, **kwargs) -> OperationType:
        """Infer operation type from operation name and context.
        
        Args:
            operation_name: Name of the operation (e.g., "pattern_match", "cosine_similarity")
            **kwargs: Additional context
            
        Returns:
            Inferred operation type
        """
        op_lower = operation_name.lower()
        
        # Pattern matching
        if any(kw in op_lower for kw in ["pattern", "regex", "match", "rule"]):
            return OperationType.PATTERN_MATCHING
        
        # Vector operations
        if any(kw in op_lower for kw in ["vector", "cosine", "similarity", "distance", "embedding"]):
            return OperationType.VECTOR_OPS
        
        # Tensor operations
        if any(kw in op_lower for kw in ["tensor", "matrix", "batch", "inference"]):
            return OperationType.TENSOR_OPS
        
        # Graph algorithms
        if any(kw in op_lower for kw in ["graph", "walk", "path", "community", "constellation"]):
            return OperationType.GRAPH_ALGORITHMS
        
        # Concurrent tasks
        if kwargs.get("parallel", False) or "parallel" in op_lower or "concurrent" in op_lower:
            return OperationType.CONCURRENT_TASKS
        
        # Network I/O
        if any(kw in op_lower for kw in ["http", "request", "network", "api"]):
            return OperationType.NETWORK_IO
        
        # File I/O
        if any(kw in op_lower for kw in ["file", "read", "write", "io"]):
            return OperationType.FILE_IO
        
        # Search
        if any(kw in op_lower for kw in ["search", "query", "find"]):
            return OperationType.SEARCH
        
        # Compression
        if any(kw in op_lower for kw in ["compress", "decompress", "zip"]):
            return OperationType.COMPRESSION
        
        # Pure transformation
        if any(kw in op_lower for kw in ["transform", "map", "filter", "reduce"]):
            return OperationType.PURE_TRANSFORMATION
        
        return OperationType.UNKNOWN
    
    def route_auto(self, operation_name: str, **kwargs) -> Backend:
        """Automatically route based on operation name and context.
        
        Args:
            operation_name: Name of the operation
            **kwargs: Additional context (parallel, data_size, etc.)
            
        Returns:
            Optimal backend
        """
        op_type = self.infer_operation_type(operation_name, **kwargs)
        
        context = RoutingContext(
            operation_type=op_type,
            data_size=kwargs.get("data_size", 0),
            parallel=kwargs.get("parallel", False),
            memory_bound=kwargs.get("memory_bound", False),
            compute_bound=kwargs.get("compute_bound", True),
            latency_critical=kwargs.get("latency_critical", False),
            metadata=kwargs.get("metadata"),
        )
        
        return self.route(context)
    
    def get_status(self) -> dict[str, Any]:
        """Get status of all backends.
        
        Returns:
            Dict with backend availability and capabilities
        """
        return {
            backend.value: {
                "available": cap.available,
                "strengths": [s.value for s in cap.strengths],
                "relative_speed": cap.relative_speed,
                "startup_cost_ms": cap.startup_cost_ms,
            }
            for backend, cap in self._backends.items()
        }


# Global router instance
_router: Optional[ContextRouter] = None


def get_context_router() -> ContextRouter:
    """Get or create the global context router."""
    global _router
    if _router is None:
        _router = ContextRouter()
    return _router


def route_operation(operation_name: str, **kwargs) -> Backend:
    """Convenience function to route an operation.
    
    Args:
        operation_name: Name of the operation
        **kwargs: Additional context
        
    Returns:
        Optimal backend for this operation
    """
    router = get_context_router()
    return router.route_auto(operation_name, **kwargs)
