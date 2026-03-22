"""Holographic Encoder Bridge - Rust-accelerated 5D coordinate encoding.

Phase 2 VC3: Translate hologram/encoder.py 5D coords to Rust.
"""
from __future__ import annotations

import hashlib
import math
from typing import Any


# Try to load Rust module
_rs = None
try:
    import whitemagic_rs as _rs
except Exception:
    pass


def encode_5d_coordinates(
    content_hash: str,
    title_hash: str | None = None,
    tag_hashes: list[str] | None = None,
    emotional_valence: float = 0.0,
    importance: float = 0.5,
) -> tuple[float, float, float, float, float]:
    """Encode memory into 5D holographic coordinates with Rust acceleration.
    
    Returns (x, y, z, w, v) where:
    - x, y, z: Spatial coordinates from content hash
    - w: Temporal drift coordinate
    - v: Valence/emotional coordinate
    """
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'encode_holographic_5d'):
        try:
            tags = tag_hashes or []
            result = _rs.encode_holographic_5d(
                content_hash, title_hash or "", tags,
                emotional_valence, importance
            )
            return (result[0], result[1], result[2], result[3], result[4])
        except Exception:
            pass
    
    # Python fallback
    # X coordinate: from content hash (deterministic)
    x = _hash_to_float(content_hash, 0) * 2 - 1  # -1 to 1
    
    # Y coordinate: from content hash (different offset)
    y = _hash_to_float(content_hash, 8) * 2 - 1
    
    # Z coordinate: from content hash (another offset)
    z = _hash_to_float(content_hash, 16) * 2 - 1
    
    # W coordinate: temporal drift (from title + content)
    w_input = (title_hash or "") + content_hash
    w = _hash_to_float(hashlib.sha256(w_input.encode()).hexdigest(), 0)
    
    # V coordinate: valence (emotional dimension)
    v = 0.5 + emotional_valence * 0.3 + importance * 0.2
    v = max(0.0, min(1.0, v))
    
    return (x, y, z, w, v)


def _hash_to_float(hash_str: str, offset: int) -> float:
    """Convert hash substring to float in [0, 1]."""
    if offset + 8 > len(hash_str):
        offset = 0
    substring = hash_str[offset:offset + 8]
    intval = int(substring, 16)
    return intval / 0xFFFFFFFF


def batch_encode_5d(
    memories: list[dict[str, Any]]
) -> list[tuple[float, float, float, float, float]]:
    """Batch encode 5D coordinates with Rust parallelization."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'batch_encode_holographic'):
        try:
            mem_list = []
            for m in memories:
                mem_list.append({
                    'content_hash': m.get('content_hash', hashlib.sha256(
                        str(m.get('content', '')).encode()
                    ).hexdigest()),
                    'title_hash': m.get('title_hash', ''),
                    'tag_hashes': m.get('tag_hashes', []),
                    'emotional_valence': m.get('emotional_valence', 0.0),
                    'importance': m.get('importance', 0.5),
                })
            return list(_rs.batch_encode_holographic(mem_list))
        except Exception:
            pass
    
    # Python fallback
    return [
        encode_5d_coordinates(
            m.get('content_hash', hashlib.sha256(
                str(m.get('content', '')).encode()
            ).hexdigest()),
            m.get('title_hash'),
            m.get('tag_hashes'),
            m.get('emotional_valence', 0.0),
            m.get('importance', 0.5),
        )
        for m in memories
    ]


def compute_spatial_distance(
    coord_a: tuple[float, ...],
    coord_b: tuple[float, ...],
    dims: int = 5
) -> float:
    """Compute Euclidean distance in N-dimensional space."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'euclidean_distance'):
        try:
            return float(_rs.euclidean_distance(list(coord_a[:dims]), list(coord_b[:dims])))
        except Exception:
            pass
    
    # Python fallback
    return math.sqrt(sum((a - b) ** 2 for a, b in zip(coord_a[:dims], coord_b[:dims])))


class HolographicEncoderBridge:
    """Rust-accelerated holographic encoding."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def encode_memory(self, memory: dict[str, Any]) -> tuple[float, float, float, float, float]:
        """Encode a single memory to 5D coordinates."""
        content = str(memory.get('content', ''))
        content_hash = hashlib.sha256(content.encode()).hexdigest()
        
        title = str(memory.get('title', ''))
        title_hash = hashlib.sha256(title.encode()).hexdigest() if title else None
        
        tags = memory.get('tags', [])
        tag_hashes = [hashlib.sha256(t.encode()).hexdigest() for t in tags]
        
        return encode_5d_coordinates(
            content_hash,
            title_hash,
            tag_hashes,
            memory.get('emotional_valence', 0.0),
            memory.get('importance', 0.5),
        )
    
    def batch_encode(self, memories: list[dict[str, Any]]) -> list[tuple[float, float, float, float, float]]:
        """Batch encode memories."""
        return batch_encode_5d(memories)
    
    def find_nearest_neighbors(
        self,
        query_coord: tuple[float, ...],
        candidates: list[tuple[str, tuple[float, ...]]],  # (id, coord)
        k: int = 10,
    ) -> list[tuple[str, float]]:
        """Find k nearest neighbors in 5D space."""
        distances = [
            (mem_id, compute_spatial_distance(query_coord, coord))
            for mem_id, coord in candidates
        ]
        distances.sort(key=lambda x: x[1])
        return distances[:k]
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_holographic_encoder_bridge() -> HolographicEncoderBridge:
    """Get holographic encoder bridge instance."""
    return HolographicEncoderBridge()
