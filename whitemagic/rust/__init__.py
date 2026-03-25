"""
WhiteMagic Rust Implementations
High-performance Rust implementations for critical paths
"""

from .rust_bridge import (
    get_rust_bridge,
    is_rust_available,
    RustBridge,
)

__all__ = [
    'get_rust_bridge',
    'is_rust_available',
    'RustBridge',
]
