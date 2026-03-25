"""Fast Search Utilities - Rust-Accelerated Search Operations
=============================================================
Provides high-performance search with Rust acceleration and Python fallbacks.

Wires the following Rust functions:
- fast_regex_search (parallel regex search across files)
- batch_similarities (SIMD-accelerated vector similarity)
- search_embedding / add_embedding (vector index operations)

Expected speedup: 20-100x for search operations
"""

import logging
import os
import re
from pathlib import Path
from typing import Optional, Union

logger = logging.getLogger(__name__)

# Check for Rust availability
_RUST_AVAILABLE = False
_rs = None

try:
    import whitemagic_rs as _rs_module
    _rs = _rs_module
    # Check for actual Rust function names
    if hasattr(_rs, "fast_search") or hasattr(_rs, "fast_similarity"):
        _RUST_AVAILABLE = True
        logger.debug("Rust fast search acceleration available")
except ImportError:
    logger.debug("Rust extension not available - using Python fallback")


def rust_available() -> bool:
    """Check if Rust search acceleration is available."""
    return _RUST_AVAILABLE


def fast_regex_search(
    directory: Union[str, Path],
    pattern: str,
    extensions: Optional[list[str]] = None,
    case_sensitive: bool = False,
) -> list[tuple[str, int, str]]:
    """Search for regex pattern across files (50-100x faster with Rust).
    
    Args:
        directory: Directory to search
        pattern: Regex pattern
        extensions: File extensions to include (e.g., ["py", "rs"])
        case_sensitive: Whether search is case-sensitive
        
    Returns:
        List of (file_path, line_number, matching_line)
    """
    directory = str(directory)
    extensions = extensions or []
    
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "fast_regex_search"):
        try:
            return _rs.fast_regex_search(directory, pattern, extensions, case_sensitive)
        except Exception as e:
            logger.debug(f"Rust fast_regex_search failed, using Python: {e}")
    
    # Python fallback
    results = []
    flags = 0 if case_sensitive else re.IGNORECASE
    try:
        regex = re.compile(pattern, flags)
    except re.error as e:
        raise ValueError(f"Invalid regex: {e}")
    
    for root, _, files in os.walk(directory):
        for filename in files:
            if extensions:
                ext = Path(filename).suffix.lstrip(".")
                if ext not in extensions:
                    continue
            
            filepath = os.path.join(root, filename)
            try:
                with open(filepath, "r", encoding="utf-8", errors="ignore") as f:
                    for line_num, line in enumerate(f, 1):
                        if regex.search(line):
                            results.append((filepath, line_num, line.rstrip()))
            except Exception:
                continue
    
    return results


def batch_similarities(
    query_embedding: list[float],
    all_embeddings: list[list[float]],
) -> list[float]:
    """Compute cosine similarity between query and all embeddings (20-50x faster with Rust).
    
    Args:
        query_embedding: Query vector
        all_embeddings: List of vectors to compare against
        
    Returns:
        List of similarity scores
    """
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "batch_similarities"):
        try:
            # Rust expects f32
            query_f32 = [float(x) for x in query_embedding]
            all_f32 = [[float(x) for x in emb] for emb in all_embeddings]
            return list(_rs.batch_similarities(query_f32, all_f32))
        except Exception as e:
            logger.debug(f"Rust batch_similarities failed, using Python: {e}")
    
    # Python fallback
    import math
    
    def cosine_sim(a: list[float], b: list[float]) -> float:
        if len(a) != len(b):
            return 0.0
        dot = sum(x * y for x, y in zip(a, b))
        norm_a = math.sqrt(sum(x * x for x in a))
        norm_b = math.sqrt(sum(x * x for x in b))
        if norm_a == 0 or norm_b == 0:
            return 0.0
        return dot / (norm_a * norm_b)
    
    return [cosine_sim(query_embedding, emb) for emb in all_embeddings]


def add_embedding(memory_id: str, vector: list[float]) -> bool:
    """Add embedding to Rust index (for fast retrieval).
    
    Args:
        memory_id: ID of the memory
        vector: 4D embedding vector
        
    Returns:
        True if successful
    """
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "add_embedding"):
        try:
            return _rs.add_embedding(memory_id, vector)
        except Exception as e:
            logger.debug(f"Rust add_embedding failed: {e}")
            return False
    
    # No Python fallback - requires Rust index
    logger.warning("add_embedding requires Rust acceleration")
    return False


def search_embedding(query: list[float], k: int = 10) -> list[tuple[str, float]]:
    """Search for nearest embeddings in Rust index.
    
    Args:
        query: 4D query vector
        k: Number of results to return
        
    Returns:
        List of (memory_id, distance)
    """
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "search_embedding"):
        try:
            return _rs.search_embedding(query, k)
        except Exception as e:
            logger.debug(f"Rust search_embedding failed: {e}")
            return []
    
    # No Python fallback - requires Rust index
    logger.warning("search_embedding requires Rust acceleration")
    return []


def build_embedding_cache(embeddings: list[tuple[str, list[float]]]) -> bool:
    """Build embedding cache for fast search.
    
    Args:
        embeddings: List of (memory_id, vector) tuples
        
    Returns:
        True if successful
    """
    if _RUST_AVAILABLE and _rs is not None and hasattr(_rs, "build_embedding_cache"):
        try:
            return _rs.build_embedding_cache(embeddings)
        except Exception as e:
            logger.debug(f"Rust build_embedding_cache failed: {e}")
            return False
    
    return False


def get_status() -> dict:
    """Get status of fast search acceleration."""
    return {
        "rust_available": _RUST_AVAILABLE,
        "functions": {
            "fast_regex_search": _RUST_AVAILABLE and hasattr(_rs, "fast_regex_search"),
            "batch_similarities": _RUST_AVAILABLE and hasattr(_rs, "batch_similarities"),
            "add_embedding": _RUST_AVAILABLE and hasattr(_rs, "add_embedding"),
            "search_embedding": _RUST_AVAILABLE and hasattr(_rs, "search_embedding"),
            "build_embedding_cache": _RUST_AVAILABLE and hasattr(_rs, "build_embedding_cache"),
        },
        "expected_speedup": "20-100x" if _RUST_AVAILABLE else "1x (Python)",
    }
