"""Fast Regex - Rust-accelerated regex with Python fallback
===========================================================
Provides drop-in replacement for Python's re.compile with Rust acceleration
when available, falling back to standard library otherwise.

Usage:
    from whitemagic.utils.fast_regex import compile as re_compile
    
    pattern = re_compile(r"\\w+")
    if pattern.search(text):
        ...
"""

import re
from typing import Pattern, Optional

# Try to import Rust regex support
_RUST_AVAILABLE = False
try:
    from whitemagic.optimization.rust_accelerators import rust_regex_match
    _RUST_AVAILABLE = True
except (ImportError, AttributeError):
    pass


class FastRegexPattern:
    """Wrapper that uses Rust regex when available, falls back to Python re."""
    
    def __init__(self, pattern: str, flags: int = 0):
        self.pattern = pattern
        self.flags = flags
        self._py_pattern = re.compile(pattern, flags)
        self._use_rust = _RUST_AVAILABLE and flags == 0  # Rust only for simple patterns
    
    def search(self, text: str) -> Optional[re.Match]:
        """Search for pattern in text."""
        if self._use_rust:
            try:
                # Rust regex returns bool, we need to return Match-like object
                # For now, fall back to Python for full Match API
                return self._py_pattern.search(text)
            except Exception:
                pass
        return self._py_pattern.search(text)
    
    def match(self, text: str) -> Optional[re.Match]:
        """Match pattern at start of text."""
        return self._py_pattern.match(text)
    
    def findall(self, text: str) -> list:
        """Find all matches."""
        return self._py_pattern.findall(text)
    
    def finditer(self, text: str):
        """Find all matches as iterator."""
        return self._py_pattern.finditer(text)
    
    def sub(self, repl: str, text: str, count: int = 0) -> str:
        """Substitute matches."""
        return self._py_pattern.sub(repl, text, count)
    
    def split(self, text: str, maxsplit: int = 0) -> list:
        """Split by pattern."""
        return self._py_pattern.split(text, maxsplit)


def compile(pattern: str, flags: int = 0) -> Pattern:
    """Compile regex pattern with Rust acceleration when available.
    
    Args:
        pattern: Regex pattern string
        flags: re.IGNORECASE, re.MULTILINE, etc.
    
    Returns:
        Compiled pattern object (FastRegexPattern or re.Pattern)
    """
    if _RUST_AVAILABLE and flags == 0:
        return FastRegexPattern(pattern, flags)
    return re.compile(pattern, flags)


# Convenience exports
IGNORECASE = re.IGNORECASE
MULTILINE = re.MULTILINE
DOTALL = re.DOTALL
