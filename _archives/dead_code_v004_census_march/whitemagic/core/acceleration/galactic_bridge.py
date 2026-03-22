"""Galactic Map Bridge - Rust-accelerated galactic distance calculations.

Phase 2 VC1: Translate galactic_map.py retention scoring to Rust.
"""
from __future__ import annotations

import math
from typing import Any


# Try to load Rust module
_rs = None
try:
    import whitemagic_rs as _rs
except Exception:
    pass


def compute_retention_score(
    access_count: int,
    emotional_valence: float,
    importance: float,
    recency_days: float,
    neuro_score: float = 1.0,
    novelty_score: float = 1.0,
) -> float:
    """Compute memory retention score with Rust acceleration.
    
    Retention = f(access, emotion, importance, recency, neuro, novelty)
    """
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_retention'):
        try:
            return float(_rs.compute_retention(
                access_count,
                emotional_valence,
                importance,
                recency_days,
                neuro_score,
                novelty_score,
            ))
        except Exception:
            pass
    
    # Python fallback
    # Access frequency component (log scale)
    access_component = math.log1p(access_count) / 5.0  # log1p(0) = 0, log1p(100) ≈ 4.6
    
    # Emotional component (absolute value matters)
    emotion_component = abs(emotional_valence) * 0.2
    
    # Importance component (direct)
    importance_component = importance * 0.3
    
    # Recency decay (exponential)
    recency_component = math.exp(-recency_days / 30.0) * 0.2
    
    # Neuro boost (pattern recognition strength)
    neuro_component = neuro_score * 0.15
    
    # Novelty boost
    novelty_component = novelty_score * 0.15
    
    # Combine (normalize to 0-1 range)
    retention = min(1.0, (
        access_component +
        emotion_component +
        importance_component +
        recency_component +
        neuro_component +
        novelty_component
    ))
    
    return retention


def compute_galactic_distance(retention_score: float, is_protected: bool = False) -> float:
    """Convert retention score to galactic distance (0.0 = core, 1.0 = edge).
    
    Higher retention = closer to core (lower distance).
    """
    if is_protected:
        return 0.0  # Protected memories stay at core
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'retention_to_distance'):
        try:
            return float(_rs.retention_to_distance(retention_score, is_protected))
        except Exception:
            pass
    
    # Python fallback
    # Invert retention: high retention = low distance
    distance = 1.0 - retention_score
    
    # Apply gentle curve to emphasize core zone
    distance = math.pow(distance, 0.7)
    
    return min(1.0, max(0.0, distance))


def batch_compute_distances(
    retention_scores: list[float],
    protected_flags: list[bool] | None = None
) -> list[float]:
    """Compute galactic distances in batch with Rust parallelization."""
    n = len(retention_scores)
    if protected_flags is None:
        protected_flags = [False] * n
    
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'batch_retention_to_distance'):
        try:
            return list(_rs.batch_retention_to_distance(retention_scores, protected_flags))
        except Exception:
            pass
    
    # Python fallback
    return [
        compute_galactic_distance(r, p)
        for r, p in zip(retention_scores, protected_flags)
    ]


def classify_zone(distance: float) -> str:
    """Classify galactic distance into zone."""
    if distance < 0.15:
        return "CORE"
    elif distance < 0.40:
        return "INNER_RIM"
    elif distance < 0.65:
        return "MID_BAND"
    elif distance < 0.85:
        return "OUTER_RIM"
    else:
        return "FAR_EDGE"


def compute_zone_distribution(distances: list[float]) -> dict[str, int]:
    """Compute count of memories in each zone."""
    zones = [classify_zone(d) for d in distances]
    counts: dict[str, int] = {}
    for z in zones:
        counts[z] = counts.get(z, 0) + 1
    return counts


class GalacticBridge:
    """Rust-accelerated galactic map operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def full_sweep_metrics(
        self,
        memories: list[dict[str, Any]]
    ) -> dict[str, Any]:
        """Compute galactic metrics for all memories."""
        if not memories:
            return {"total": 0, "avg_distance": 0.0, "zone_counts": {}}
        
        # Extract features
        retention_scores = []
        protected_flags = []
        
        for m in memories:
            retention = compute_retention_score(
                access_count=m.get('access_count', 0),
                emotional_valence=m.get('emotional_valence', 0.0),
                importance=m.get('importance', 0.5),
                recency_days=m.get('recency_days', 30.0),
                neuro_score=m.get('neuro_score', 1.0),
                novelty_score=m.get('novelty_score', 1.0),
            )
            retention_scores.append(retention)
            protected_flags.append(m.get('is_protected', False))
        
        # Compute distances
        distances = batch_compute_distances(retention_scores, protected_flags)
        
        # Zone distribution
        zone_counts = compute_zone_distribution(distances)
        
        # Statistics
        avg_distance = sum(distances) / len(distances) if distances else 0.0
        
        return {
            "total": len(memories),
            "avg_distance": round(avg_distance, 4),
            "zone_counts": zone_counts,
            "core_count": zone_counts.get("CORE", 0),
            "edge_count": zone_counts.get("FAR_EDGE", 0),
        }
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_galactic_bridge() -> GalacticBridge:
    """Get galactic bridge instance."""
    return GalacticBridge()
