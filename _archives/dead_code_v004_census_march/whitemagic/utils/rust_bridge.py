"""rust_bridge.py — @rust_accelerated decorator + Rust availability helpers.

PSR-022: Zero-friction Python→Rust migration path.
Usage:
    from whitemagic.utils.rust_bridge import rust_accelerated

    @rust_accelerated("VectorIndex")
    def search_vectors(query, vecs, k=10):
        # Python fallback — runs when Rust not available
        ...
"""
from __future__ import annotations

import functools
import logging
import time
from typing import Any, Callable

logger = logging.getLogger(__name__)

_rust_module = None
_rust_checked = False


def _get_rust() -> Any | None:
    global _rust_module, _rust_checked
    if _rust_checked:
        return _rust_module
    _rust_checked = True
    try:
        # Try both names - some builds use _rs, some use _rust
        try:
            import whitemagic_rust as rs_module
        except ImportError:
            import whitemagic_rs as rs_module
            
        _rust_module = rs_module
        logger.debug("Rust extension loaded")
    except ImportError:
        _rust_module = None
    return _rust_module


def is_rust_available(attr: str | None = None) -> bool:
    rs = _get_rust()
    if rs is None:
        return False
    if attr:
        return hasattr(rs, attr)
    return True


def rust_accelerated(rust_attr: str, fallback_warn: bool = False):
    """Decorator: tries Rust impl first, falls back to Python.

    Args:
        rust_attr: name of the attribute on whitemagic_rs to use.
                   If it's a class, passes through; if a function, calls it.
        fallback_warn: if True, log a warning when falling back to Python.

    The decorated function's first argument is replaced by the Rust object
    when available. The Python function body serves as the fallback.

    Example — wrapping a class method:
        @rust_accelerated("PyVectorIndex")
        def make_index(dim, metric):
            # Python fallback
            return PythonVectorIndex(dim, metric)
    """
    def decorator(fn: Callable) -> Callable:
        @functools.wraps(fn)
        def wrapper(*args, **kwargs):
            rs = _get_rust()
            if rs is not None and hasattr(rs, rust_attr):
                try:
                    t0 = time.perf_counter()
                    result = getattr(rs, rust_attr)
                    # If it's callable (function), call it with same args
                    if callable(result) and not isinstance(result, type):
                        result = result(*args, **kwargs)
                    elapsed = (time.perf_counter() - t0) * 1000
                    logger.debug("rust_accelerated[%s]: %.3fms", rust_attr, elapsed)
                    return result
                except Exception as e:
                    logger.debug("rust_accelerated[%s] failed (%s), falling back", rust_attr, e)
            else:
                if fallback_warn:
                    logger.warning(
                        "rust_accelerated[%s]: Rust not available, using Python fallback. "
                        "Run: cd whitemagic-rust && maturin develop --release",
                        rust_attr,
                    )
            return fn(*args, **kwargs)
        wrapper._rust_attr = rust_attr  # type: ignore[attr-defined]
        wrapper._is_rust_accelerated = True  # type: ignore[attr-defined]
        return wrapper
    return decorator


def rust_class(rust_attr: str):
    """Return the Rust class if available, else None.

    Usage:
        VectorIndex = rust_class("PyVectorIndex") or PythonVectorIndex
    """
    rs = _get_rust()
    if rs is not None:
        return getattr(rs, rust_attr, None)
    return None


def benchmark_rust_vs_python(
    name: str,
    python_fn: Callable,
    rust_fn: Callable | None,
    n: int = 1000,
) -> dict:
    """Run both implementations n times, return timing comparison dict."""
    def _median_ms(fn, count):
        times = []
        for _ in range(count):
            t0 = time.perf_counter()
            fn()
            times.append(time.perf_counter() - t0)
        times.sort()
        return times[len(times) // 2] * 1000

    py_ms = _median_ms(python_fn, n)
    result: dict = {"name": name, "python_ms": round(py_ms, 4), "n": n}

    if rust_fn is not None:
        try:
            rust_ms = _median_ms(rust_fn, n)
            result["rust_ms"] = round(rust_ms, 4)
            result["speedup"] = round(py_ms / rust_ms, 2) if rust_ms > 0 else None
            result["status"] = "REAL"
        except Exception as e:
            result["rust_ms"] = None
            result["speedup"] = None
            result["status"] = f"RUST_ERROR: {e}"
    else:
        result["rust_ms"] = None
        result["speedup"] = None
        result["status"] = "PYTHON_ONLY"

    return result
