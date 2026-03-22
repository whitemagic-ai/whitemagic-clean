"""Parallel Sort — Rust-accelerated sorting for large collections.

Uses Rust parallel sort (rayon) for collections >1000 items, falls back to
Python's built-in sort for smaller collections.
"""
from __future__ import annotations

import logging
from typing import Any, Callable, TypeVar

logger = logging.getLogger(__name__)

T = TypeVar('T')

# Lazy import Rust accelerators
_rust_available = False
_rust_module = None

def _init_rust() -> Any:
    """Lazy initialization of Rust accelerators."""
    global _rust_available, _rust_module
    if _rust_module is not None:
        return _rust_module
    
    try:
        from whitemagic.optimization import rust_accelerators
        _rust_module = rust_accelerators
        _rust_available = True
        logger.debug("Rust parallel sort available")
        return _rust_module
    except ImportError:
        logger.debug("Rust parallel sort unavailable, using Python fallback")
        _rust_available = False
        return None


def parallel_sort(
    items: list[T],
    key: Callable[[T], Any] | None = None,
    reverse: bool = False,
    threshold: int = 1000,
) -> list[T]:
    """Sort items using Rust parallel sort for large collections.
    
    Args:
        items: List of items to sort
        key: Optional key function for sorting
        reverse: Sort in descending order
        threshold: Minimum size for parallel sort (default: 1000)
    
    Returns:
        Sorted list (in-place sort, returns same list)
    """
    # Use Python's built-in sort for small collections
    if len(items) < threshold:
        items.sort(key=key, reverse=reverse)
        return items
    
    # Try Rust parallel sort for large collections
    rust = _init_rust()
    if rust and hasattr(rust, 'parallel_sort'):
        try:
            # If key function provided, extract keys first
            if key is not None:
                # Create list of (key, item) tuples
                keyed_items = [(key(item), item) for item in items]
                # Sort by keys using Rust
                rust.parallel_sort(keyed_items, reverse=reverse)
                # Extract sorted items
                items[:] = [item for _, item in keyed_items]
            else:
                # Direct sort without key function
                rust.parallel_sort(items, reverse=reverse)
            
            logger.debug(f"Rust parallel sort: {len(items)} items")
            return items
        except Exception as e:
            logger.debug(f"Rust parallel sort failed: {e}, falling back to Python")
    
    # Fall back to Python's built-in sort
    items.sort(key=key, reverse=reverse)
    return items


def parallel_sorted(
    items: list[T],
    key: Callable[[T], Any] | None = None,
    reverse: bool = False,
    threshold: int = 1000,
) -> list[T]:
    """Return sorted copy using Rust parallel sort for large collections.
    
    Args:
        items: List of items to sort
        key: Optional key function for sorting
        reverse: Sort in descending order
        threshold: Minimum size for parallel sort (default: 1000)
    
    Returns:
        New sorted list
    """
    items_copy = list(items)
    return parallel_sort(items_copy, key=key, reverse=reverse, threshold=threshold)


__all__ = [
    "parallel_sort",
    "parallel_sorted",
]
