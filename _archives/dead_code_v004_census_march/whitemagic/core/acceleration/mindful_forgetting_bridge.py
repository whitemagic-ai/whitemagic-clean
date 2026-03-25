"""Mindful Forgetting Bridge - Rust-accelerated retention decay.

Phase 2 VC5: Translate mindful_forgetting.py decay to Rust.
"""
from __future__ import annotations

import math
from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


def compute_decay_factor(
    days_since_access: float,
    half_life_days: float = 30.0,
    importance: float = 0.5
) -> float:
    """Compute retention decay factor with Rust acceleration.
    
    Returns value between 0 and 1 (1 = fully retained, 0 = fully decayed).
    """
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_decay'):
        try:
            return float(_rs.compute_decay(days_since_access, half_life_days, importance))
        except Exception:
            pass
    
    # Python fallback: exponential decay with importance protection
    effective_half_life = half_life_days * (1 + importance)
    decay = math.exp(-days_since_access / effective_half_life)
    return decay


def should_forget(
    access_count: int,
    days_since_access: float,
    importance: float,
    is_protected: bool = False,
    threshold: float = 0.1
) -> bool:
    """Determine if a memory should be forgotten/archived.
    
    Returns True if memory should be archived.
    """
    # Never forget protected memories
    if is_protected:
        return False
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'should_forget'):
        try:
            return bool(_rs.should_forget(
                access_count, days_since_access, importance, is_protected, threshold
            ))
        except Exception:
            pass
    
    # Python fallback: heuristics
    # High access count = keep
    if access_count > 50:
        return False
    
    # High importance = keep
    if importance > 0.8:
        return False
    
    # Recent access = keep
    if days_since_access < 7:
        return False
    
    # Compute decay score
    decay = compute_decay_factor(days_since_access, 30.0, importance)
    
    # Forget if decayed below threshold
    return decay < threshold


def batch_decay_analysis(
    memories: list[dict[str, Any]],
    current_time: float | None = None
) -> list[dict[str, Any]]:
    """Analyze decay for batch of memories with Rust parallelization."""
    import time
    
    if current_time is None:
        current_time = time.time()
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'batch_decay_analysis'):
        try:
            mem_list = []
            for m in memories:
                mem_list.append({
                    'access_count': m.get('access_count', 0),
                    'last_access': m.get('accessed_at', m.get('created_at', 0)),
                    'importance': m.get('importance', 0.5),
                    'is_protected': m.get('is_protected', False),
                })
            return list(_rs.batch_decay_analysis(mem_list, current_time))
        except Exception:
            pass
    
    # Python fallback
    results = []
    for m in memories:
        last_access = m.get('accessed_at', m.get('created_at', 0))
        if isinstance(last_access, str):
            from datetime import datetime
            try:
                last_access = datetime.fromisoformat(last_access).timestamp()
            except Exception:
                last_access = 0
        
        days_since = (current_time - last_access) / 86400.0 if last_access else 365
        
        decay = compute_decay_factor(
            days_since,
            m.get('half_life_days', 30.0),
            m.get('importance', 0.5)
        )
        
        forget = should_forget(
            m.get('access_count', 0),
            days_since,
            m.get('importance', 0.5),
            m.get('is_protected', False)
        )
        
        results.append({
            'memory_id': m.get('id'),
            'decay_factor': decay,
            'should_forget': forget,
            'days_since_access': days_since,
        })
    
    return results


class MindfulForgettingBridge:
    """Rust-accelerated mindful forgetting operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def evaluate_retention(self, memory: dict[str, Any]) -> dict[str, Any]:
        """Evaluate if a memory should be retained or archived."""
        analysis = batch_decay_analysis([memory])[0]
        return {
            'retain': not analysis['should_forget'],
            'decay_factor': analysis['decay_factor'],
            'reason': 'decayed' if analysis['should_forget'] else 'active',
        }
    
    def sweep_for_archival(
        self,
        memories: list[dict[str, Any]],
        batch_size: int = 1000
    ) -> list[str]:
        """Sweep memories and return IDs that should be archived."""
        to_archive = []
        
        for i in range(0, len(memories), batch_size):
            batch = memories[i:i + batch_size]
            analysis = batch_decay_analysis(batch)
            
            for mem, result in zip(batch, analysis):
                if result['should_forget']:
                    to_archive.append(mem.get('id'))
        
        return [mem_id for mem_id in to_archive if mem_id is not None]
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_mindful_forgetting_bridge() -> MindfulForgettingBridge:
    """Get mindful forgetting bridge instance."""
    return MindfulForgettingBridge()
