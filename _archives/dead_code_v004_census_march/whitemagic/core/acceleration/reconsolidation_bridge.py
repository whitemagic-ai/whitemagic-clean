"""Reconsolidation Bridge - Rust-accelerated labile memory processing.

Phase 2 VC6: Translate reconsolidation.py labile to Rust.
"""
from __future__ import annotations

from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


def compute_labile_window(
    created_at: float,
    modified_at: float | None = None,
    importance: float = 0.5,
) -> tuple[float, float]:
    """Compute labile window for memory reconsolidation.
    
    Returns (window_start, window_end) as Unix timestamps.
    """
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_labile_window'):
        try:
            result = _rs.compute_labile_window(created_at, modified_at or 0, importance)
            return (result[0], result[1])
        except Exception:
            pass
    
    # Python fallback
    # Labile window: 5-30 minutes after creation/modification
    # Importance extends window
    base_duration = 300  # 5 minutes in seconds
    extension = importance * 1500  # up to 25 more minutes
    
    window_start = modified_at or created_at
    window_end = window_start + base_duration + extension
    
    return (window_start, window_end)


def is_in_labile_phase(
    memory: dict[str, Any],
    current_time: float
) -> bool:
    """Check if memory is currently in labile (modifiable) phase."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'is_labile'):
        try:
            return bool(_rs.is_labile(
                memory.get('created_at', 0),
                memory.get('modified_at', 0),
                memory.get('importance', 0.5),
                current_time
            ))
        except Exception:
            pass
    
    # Python fallback
    window = compute_labile_window(
        memory.get('created_at', 0),
        memory.get('modified_at'),
        memory.get('importance', 0.5)
    )
    return window[0] <= current_time <= window[1]


def batch_labile_analysis(
    memories: list[dict[str, Any]],
    current_time: float
) -> list[dict[str, Any]]:
    """Analyze labile state for batch of memories with Rust parallelization."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'batch_labile_analysis'):
        try:
            mem_list = [
                {
                    'created_at': m.get('created_at', 0),
                    'modified_at': m.get('modified_at', 0),
                    'importance': m.get('importance', 0.5),
                }
                for m in memories
            ]
            return list(_rs.batch_labile_analysis(mem_list, current_time))
        except Exception:
            pass
    
    # Python fallback
    return [
        {
            'memory_id': m.get('id'),
            'is_labile': is_in_labile_phase(m, current_time),
            'can_reconsolidate': m.get('importance', 0.5) > 0.3,
        }
        for m in memories
    ]


class ReconsolidationBridge:
    """Rust-accelerated reconsolidation operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def find_labile_memories(
        self,
        memories: list[dict[str, Any]],
        current_time: float | None = None
    ) -> list[str]:
        """Find memory IDs currently in labile phase."""
        import time
        
        if current_time is None:
            current_time = time.time()
        
        analysis = batch_labile_analysis(memories, current_time)
        return [a['memory_id'] for a in analysis if a['is_labile']]
    
    def prioritize_for_reconsolidation(
        self,
        memories: list[dict[str, Any]]
    ) -> list[tuple[str, float]]:
        """Prioritize memories for reconsolidation by importance and recency."""
        import time
        
        current_time = time.time()
        scored = []
        
        for m in memories:
            importance = m.get('importance', 0.5)
            age_days = (current_time - m.get('created_at', 0)) / 86400
            
            # Score: high importance, recent
            score = importance * 0.7 + max(0, 1 - age_days / 30) * 0.3
            scored.append((m.get('id'), score))
        
        scored.sort(key=lambda x: x[1], reverse=True)
        return [(str(mem_id), float(score)) for mem_id, score in scored if mem_id is not None]
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_reconsolidation_bridge() -> ReconsolidationBridge:
    """Get reconsolidation bridge instance."""
    return ReconsolidationBridge()
