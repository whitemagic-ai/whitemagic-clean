"""Resonance Bridge - Rust-accelerated scheduling and harmony operations.

Phase 5: Resonance/Governance - temporal_scheduler.py, salience_arbiter.py, harmony/vector.py, homeostatic_loop.py
"""
from __future__ import annotations

from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


def compute_priority_score(
    urgency: float,
    importance: float,
    energy_cost: float,
    time_pressure: float = 1.0,
) -> float:
    """Compute task priority score with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_priority'):
        try:
            return float(_rs.compute_priority(urgency, importance, energy_cost, time_pressure))
        except Exception:
            pass
    
    # Python fallback: weighted combination
    # Higher urgency and importance = higher priority
    # Higher energy cost = lower priority (conservation)
    # Higher time pressure = boost to urgency component
    
    adjusted_urgency = urgency * time_pressure
    score = adjusted_urgency * 0.4 + importance * 0.4 - energy_cost * 0.2
    
    return max(0.0, min(1.0, score))


def schedule_tasks(
    tasks: list[dict[str, Any]],
    time_slots: list[tuple[float, float]],
    strategy: str = "priority",
) -> list[tuple[str, tuple[float, float]]]:
    """Schedule tasks into time slots with Rust acceleration.
    
    Returns list of (task_id, (start, end)) tuples.
    """
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'schedule_tasks'):
        try:
            result = _rs.schedule_tasks(tasks, time_slots, strategy)
            return [(str(r[0]), (float(r[1]), float(r[2]))) for r in result]
        except Exception:
            pass
    
    # Python fallback: greedy by priority
    # Sort tasks by priority
    sorted_tasks = sorted(
        tasks,
        key=lambda t: t.get("priority", 0.5),
        reverse=True
    )
    
    scheduled = []
    used_slots = set()
    
    for task in sorted_tasks:
        duration = task.get("duration_seconds", 3600)
        task_id = task.get("id")
        
        # Find first available slot
        for i, (start, end) in enumerate(time_slots):
            if i in used_slots:
                continue
            
            slot_duration = end - start
            if slot_duration >= duration:
                scheduled.append((task_id, (start, start + duration)))
                used_slots.add(i)
                break
    
    return scheduled


def compute_harmony_vector(
    vectors: list[list[float]],
    weights: list[float] | None = None
) -> list[float]:
    """Compute weighted harmony (centroid) of multiple vectors."""
    if not vectors:
        return []
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'weighted_centroid'):
        try:
            return list(_rs.weighted_centroid(vectors, weights or [1.0] * len(vectors)))
        except Exception:
            pass
    
    # Python fallback
    dim = len(vectors[0])
    if weights is None:
        weights = [1.0] * len(vectors)
    
    total_weight = sum(weights)
    if total_weight == 0:
        return [0.0] * dim
    
    result = []
    for d in range(dim):
        weighted_sum = sum(v[d] * w for v, w in zip(vectors, weights))
        result.append(weighted_sum / total_weight)
    
    return result


class ResonanceBridge:
    """Rust-accelerated resonance and governance operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def arbitrate_salience(
        self,
        candidates: list[dict[str, Any]],
        current_load: float = 0.5,
        max_concurrent: int = 5
    ) -> list[str]:
        """Arbitrate which candidates should be active based on salience."""
        # Score each candidate
        scored = []
        for c in candidates:
            score = compute_priority_score(
                c.get("urgency", 0.5),
                c.get("importance", 0.5),
                c.get("energy_cost", 0.3),
                1.0 + current_load,  # Higher load = more time pressure
            )
            scored.append((c.get("id"), score))
        
        # Sort by score, take top N
        scored.sort(key=lambda x: x[1], reverse=True)
        return [item_id for item_id, _ in scored[:max_concurrent]]
    
    def homeostatic_balance(
        self,
        metrics: dict[str, float],
        targets: dict[str, float]
    ) -> dict[str, float]:
        """Compute homeostatic adjustments to reach targets."""
        adjustments = {}
        
        for key, current in metrics.items():
            target = targets.get(key, current)
            delta = target - current
            
            # Compute adjustment (proportional control)
            adjustment = delta * 0.1  # 10% correction per cycle
            adjustments[key] = round(adjustment, 4)
        
        return adjustments
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_resonance_bridge() -> ResonanceBridge:
    """Get resonance bridge instance."""
    return ResonanceBridge()
