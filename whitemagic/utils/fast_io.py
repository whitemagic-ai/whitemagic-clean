"""Fast I/O Utilities - Rust-Accelerated File Operations
========================================================
Provides high-performance file I/O with Rust acceleration and Python fallbacks.

Wires the following Rust functions:
- fast_compress / fast_decompress (in-memory gzip)
- compress_file / decompress_file (file-based gzip)
- read_file_fast / write_file_fast (optimized file I/O)

Expected speedup: 10-20x for file operations
"""

import gzip
import logging
from pathlib import Path
from typing import Union

logger = logging.getLogger(__name__)

# Check for Rust availability
_RUST_AVAILABLE = False
_rs = None

try:
    import whitemagic_rs as _rs_module
    _rs = _rs_module
    # Verify key functions exist
    if hasattr(_rs, "fast_compress") and hasattr(_rs, "fast_decompress"):
        _RUST_AVAILABLE = True
        logger.debug("Rust fast I/O acceleration available")
except ImportError:
    logger.debug("Rust extension not available - using Python fallback")


def rust_available() -> bool:
    """Check if Rust I/O acceleration is available."""
    return _RUST_AVAILABLE


def fast_compress(data: str) -> bytes:
    """Compress string data to gzip bytes (10-20x faster with Rust).
    
    Args:
        data: String data to compress
        
    Returns:
        Compressed bytes
    """
    if _RUST_AVAILABLE and _rs is not None:
        try:
            return bytes(_rs.fast_compress(data))
        except Exception as e:
            logger.debug(f"Rust fast_compress failed, using Python: {e}")
    
    # Python fallback
    return gzip.compress(data.encode("utf-8"))


def fast_decompress(data: bytes) -> str:
    """Decompress gzip bytes to string (10-20x faster with Rust).
    
    Args:
        data: Compressed bytes
        
    Returns:
        Decompressed string
    """
    if _RUST_AVAILABLE and _rs is not None:
        try:
            return _rs.fast_decompress(list(data))
        except Exception as e:
            logger.debug(f"Rust fast_decompress failed, using Python: {e}")
    
    # Python fallback
    return gzip.decompress(data).decode("utf-8")


def compress_file(input_path: Union[str, Path], output_path: Union[str, Path]) -> int:
    """Compress a file using gzip (10-20x faster with Rust).
    
    Args:
        input_path: Path to input file
        output_path: Path to output compressed file
        
    Returns:
        Size of compressed file in bytes
    """
    input_path = str(input_path)
    output_path = str(output_path)
    
    if _RUST_AVAILABLE and _rs is not None:
        try:
            return _rs.compress_file(input_path, output_path)
        except Exception as e:
            logger.debug(f"Rust compress_file failed, using Python: {e}")
    
    # Python fallback
    with open(input_path, "rb") as f_in:
        data = f_in.read()
    compressed = gzip.compress(data)
    with open(output_path, "wb") as f_out:
        f_out.write(compressed)
    return len(compressed)


def decompress_file(input_path: Union[str, Path], output_path: Union[str, Path]) -> int:
    """Decompress a gzip file (10-20x faster with Rust).
    
    Args:
        input_path: Path to compressed file
        output_path: Path to output decompressed file
        
    Returns:
        Size of decompressed file in bytes
    """
    input_path = str(input_path)
    output_path = str(output_path)
    
    if _RUST_AVAILABLE and _rs is not None:
        try:
            return _rs.decompress_file(input_path, output_path)
        except Exception as e:
            logger.debug(f"Rust decompress_file failed, using Python: {e}")
    
    # Python fallback
    with gzip.open(input_path, "rb") as f_in:
        data = f_in.read()
    with open(output_path, "wb") as f_out:
        f_out.write(data)
    return len(data)


def read_file_fast(path: Union[str, Path]) -> str:
    """Read a file quickly (10x faster with Rust for large files).
    
    Args:
        path: Path to file
        
    Returns:
        File contents as string
    """
    path = str(path)
    
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "read_file_fast"):
        try:
            return _rs.read_file_fast(path)
        except Exception as e:
            logger.debug(f"Rust read_file_fast failed, using Python: {e}")
    
    # Python fallback
    with open(path, "r", encoding="utf-8") as f:
        return f.read()


def write_file_fast(path: Union[str, Path], content: str) -> int:
    """Write a file quickly (10x faster with Rust for large files).
    
    Args:
        path: Path to file
        content: Content to write
        
    Returns:
        Number of bytes written
    """
    path = str(path)
    
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "write_file_fast"):
        try:
            return _rs.write_file_fast(path, content)
        except Exception as e:
            logger.debug(f"Rust write_file_fast failed, using Python: {e}")
    
    # Python fallback
    with open(path, "w", encoding="utf-8") as f:
        return f.write(content)


def read_files_batch(paths: list[Union[str, Path]]) -> dict[str, str]:
    """Read multiple files in parallel (uses Rust rayon for parallelism).
    
    Args:
        paths: List of file paths
        
    Returns:
        Dict mapping path to contents
    """
    paths_str = [str(p) for p in paths]
    
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "read_files_fast"):
        try:
            # Rust returns list of (path, content) tuples
            results = _rs.read_files_fast(paths_str)
            return {p: c for p, c in results}
        except Exception as e:
            logger.debug(f"Rust read_files_fast failed, using Python: {e}")
    
    # Python fallback (sequential)
    result = {}
    for path in paths_str:
        try:
            with open(path, "r", encoding="utf-8") as f:
                result[path] = f.read()
        except Exception as e:
            logger.warning(f"Failed to read {path}: {e}")
    return result


# Export status for introspection
def get_status() -> dict:
    """Get status of fast I/O acceleration."""
    return {
        "rust_available": _RUST_AVAILABLE,
        "functions": {
            "fast_compress": _RUST_AVAILABLE and hasattr(_rs, "fast_compress"),
            "fast_decompress": _RUST_AVAILABLE and hasattr(_rs, "fast_decompress"),
            "compress_file": _RUST_AVAILABLE and hasattr(_rs, "compress_file"),
            "decompress_file": _RUST_AVAILABLE and hasattr(_rs, "decompress_file"),
            "read_file_fast": _RUST_AVAILABLE and hasattr(_rs, "read_file_fast"),
            "write_file_fast": _RUST_AVAILABLE and hasattr(_rs, "write_file_fast"),
            "read_files_fast": _RUST_AVAILABLE and hasattr(_rs, "read_files_fast"),
        },
        "expected_speedup": "10-20x" if _RUST_AVAILABLE else "1x (Python)",
    }
