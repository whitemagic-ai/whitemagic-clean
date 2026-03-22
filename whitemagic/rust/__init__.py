"""
WhiteMagic Rust Implementations
High-performance Rust implementations for critical paths
"""

from .rust_bridge import (
    RustBridge,
    get_rust_bridge,
    is_rust_available,
)

__all__ = [
    'get_rust_bridge',
    'is_rust_available',
    'RustBridge',
]
