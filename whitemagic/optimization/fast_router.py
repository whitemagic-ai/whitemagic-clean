#!/usr/bin/env python3
"""H003: Fast PolyglotRouter with predictive routing and cached availability checks.

Optimizations:
1. Cache availability checks (avoid repeated file system checks)
2. Predictive routing based on operation history
3. Fast-path for common operations
4. Minimal overhead dispatch
"""

import logging
import time
from collections import defaultdict, deque
from dataclasses import dataclass
from enum import Enum
from typing import Any, Callable, TypeVar

logger = logging.getLogger(__name__)
T = TypeVar("T")


class Backend(Enum):
    """Available backends."""
    RUST = "rust"
    MOJO = "mojo"
    ZIG = "zig"
    PYTHON = "python"


@dataclass
class RouteStats:
    """Lightweight routing statistics."""
    total_routes: int = 0
    rust_routes: int = 0
    mojo_routes: int = 0
    zig_routes: int = 0
    python_routes: int = 0
    cache_hits: int = 0
    prediction_hits: int = 0
    total_time_us: float = 0.0  # Microseconds


class FastRouter:
    """Optimized router with <10μs overhead.
    
    H003 Optimizations:
    - Cached availability checks (computed once at init)
    - Predictive routing (learns best backend per operation)
    - Fast-path dispatch (minimal branching)
    - Microsecond-precision timing
    """
    
    def __init__(self):
        # Cache availability checks (computed once)
        self._rust_available = self._check_rust()
        self._mojo_available = self._check_mojo()
        self._zig_available = self._check_zig()
        
        # Predictive routing: operation_name -> preferred backend
        self._predictions: dict[str, Backend] = {}
        
        # Success history for learning (last 100 per operation)
        self._history: dict[str, deque[Backend]] = defaultdict(lambda: deque(maxlen=100))
        
        # Statistics
        self.stats = RouteStats()
        
        logger.info(f"FastRouter initialized: Rust={self._rust_available}, "
                   f"Mojo={self._mojo_available}, Zig={self._zig_available}")
    
    def _check_rust(self) -> bool:
        """Check Rust availability once at init."""
        try:
            import whitemagic_rs
            return True
        except ImportError:
            return False
    
    def _check_mojo(self) -> bool:
        """Check Mojo availability once at init."""
        try:
            from importlib.util import find_spec
            return find_spec("whitemagic_mojo") is not None
        except Exception:
            return False
    
    def _check_zig(self) -> bool:
        """Check Zig availability once at init."""
        from pathlib import Path
        lib_path = Path.cwd() / "whitemagic-zig/zig-out/lib/libwhitemagic.so"
        return lib_path.exists()
    
    def route(
        self,
        operation_name: str,
        python_fn: Callable[..., T],
        rust_fn: Callable[..., T] | None = None,
        mojo_fn: Callable[..., T] | None = None,
        zig_fn: Callable[..., T] | None = None,
        *args: Any,
        **kwargs: Any,
    ) -> T:
        """Route operation with <10μs overhead.
        
        Fast path:
        1. Check prediction cache
        2. Try predicted backend
        3. Fall back to priority order
        """
        start_ns = time.perf_counter_ns()
        
        # Fast path: Use prediction if available
        predicted = self._predictions.get(operation_name)
        if predicted:
            self.stats.cache_hits += 1
            result = self._try_backend(
                predicted, operation_name, 
                python_fn, rust_fn, mojo_fn, zig_fn,
                *args, **kwargs
            )
            if result is not None:
                self.stats.prediction_hits += 1
                self._record_success(operation_name, predicted)
                self._update_stats(start_ns)
                return result
        
        # Fallback: Try backends in priority order
        # Priority: Mojo > Zig > Rust > Python
        for backend, fn, available in [
            (Backend.MOJO, mojo_fn, self._mojo_available),
            (Backend.ZIG, zig_fn, self._zig_available),
            (Backend.RUST, rust_fn, self._rust_available),
        ]:
            if fn and available:
                result = self._try_backend(
                    backend, operation_name,
                    python_fn, rust_fn, mojo_fn, zig_fn,
                    *args, **kwargs
                )
                if result is not None:
                    self._record_success(operation_name, backend)
                    self._learn_prediction(operation_name)
                    self._update_stats(start_ns)
                    return result
        
        # Final fallback: Python
        result = python_fn(*args, **kwargs)
        self.stats.python_routes += 1
        self._record_success(operation_name, Backend.PYTHON)
        self._update_stats(start_ns)
        return result
    
    def _try_backend(
        self,
        backend: Backend,
        operation_name: str,
        python_fn: Callable[..., T],
        rust_fn: Callable[..., T] | None,
        mojo_fn: Callable[..., T] | None,
        zig_fn: Callable[..., T] | None,
        *args: Any,
        **kwargs: Any,
    ) -> T | None:
        """Try a specific backend, return None on failure."""
        try:
            if backend == Backend.RUST and rust_fn:
                result = rust_fn(*args, **kwargs)
                self.stats.rust_routes += 1
                return result
            elif backend == Backend.MOJO and mojo_fn:
                result = mojo_fn(*args, **kwargs)
                self.stats.mojo_routes += 1
                return result
            elif backend == Backend.ZIG and zig_fn:
                result = zig_fn(*args, **kwargs)
                self.stats.zig_routes += 1
                return result
            elif backend == Backend.PYTHON:
                result = python_fn(*args, **kwargs)
                self.stats.python_routes += 1
                return result
        except Exception as e:
            logger.debug(f"{backend.value} failed for {operation_name}: {e}")
            return None
        return None
    
    def _record_success(self, operation_name: str, backend: Backend):
        """Record successful backend for learning."""
        self._history[operation_name].append(backend)
    
    def _learn_prediction(self, operation_name: str):
        """Learn best backend for operation based on history.
        
        Uses majority vote from last 100 successful routes.
        """
        history = self._history[operation_name]
        if len(history) < 10:  # Need at least 10 samples
            return
        
        # Count backend usage
        counts: dict[Backend, int] = defaultdict(int)
        for backend in history:
            counts[backend] += 1
        
        # Use most common backend (excluding Python if possible)
        sorted_backends = sorted(counts.items(), key=lambda x: x[1], reverse=True)
        
        # Prefer non-Python if it has >50% success rate
        for backend, count in sorted_backends:
            if backend != Backend.PYTHON and count / len(history) > 0.5:
                self._predictions[operation_name] = backend
                return
        
        # Otherwise use most common
        if sorted_backends:
            self._predictions[operation_name] = sorted_backends[0][0]
    
    def _update_stats(self, start_ns: int):
        """Update routing statistics."""
        duration_us = (time.perf_counter_ns() - start_ns) / 1000.0
        self.stats.total_routes += 1
        self.stats.total_time_us += duration_us
    
    def get_stats(self) -> dict[str, Any]:
        """Get routing statistics."""
        total = self.stats.total_routes
        if total == 0:
            return {"total_routes": 0}
        
        avg_overhead_us = self.stats.total_time_us / total
        prediction_accuracy = (self.stats.prediction_hits / max(self.stats.cache_hits, 1)) * 100
        
        return {
            "total_routes": total,
            "rust_routes": self.stats.rust_routes,
            "mojo_routes": self.stats.mojo_routes,
            "zig_routes": self.stats.zig_routes,
            "python_routes": self.stats.python_routes,
            "cache_hits": self.stats.cache_hits,
            "prediction_hits": self.stats.prediction_hits,
            "prediction_accuracy": f"{prediction_accuracy:.1f}%",
            "avg_overhead_us": f"{avg_overhead_us:.2f}μs",
            "native_usage": f"{((total - self.stats.python_routes) / total * 100):.1f}%",
            "learned_predictions": len(self._predictions),
        }


# Global singleton
_fast_router: FastRouter | None = None


def get_fast_router() -> FastRouter:
    """Get or create global FastRouter instance."""
    global _fast_router
    if _fast_router is None:
        _fast_router = FastRouter()
    return _fast_router
