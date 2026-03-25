"""Intelligence Bridge - Rust-accelerated predictive and causal inference.

Phase 3: Intelligence Systems - predictive_engine.py, causal_net.py, synthesis/
"""
from __future__ import annotations

from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


def predict_next_event(
    event_sequence: list[str],
    context: dict[str, float],
    memory_patterns: list[dict[str, Any]],
) -> dict[str, Any]:
    """Predict next event based on sequence patterns with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'predict_next'):
        try:
            result = _rs.predict_next(event_sequence, context, memory_patterns)
            return {
                "predicted": result.get("event"),
                "confidence": result.get("confidence", 0.0),
                "alternatives": result.get("alternatives", []),
            }
        except Exception:
            pass
    
    # Python fallback: simple frequency-based prediction
    if not event_sequence:
        return {"predicted": None, "confidence": 0.0, "alternatives": []}
    
    # Find patterns ending with current sequence
    last_event = event_sequence[-1]
    candidates: dict[str, float] = {}
    
    for pattern in memory_patterns:
        events = pattern.get("events", [])
        for i in range(len(events) - 1):
            if events[i] == last_event:
                next_event = events[i + 1]
                weight = pattern.get("strength", 1.0)
                candidates[next_event] = candidates.get(next_event, 0) + weight
    
    if not candidates:
        return {"predicted": None, "confidence": 0.0, "alternatives": []}
    
    # Sort by weight
    sorted_candidates = sorted(candidates.items(), key=lambda x: x[1], reverse=True)
    total = sum(c for _, c in sorted_candidates)
    
    top = sorted_candidates[0]
    alternatives = [
        {"event": e, "confidence": c / total}
        for e, c in sorted_candidates[1:4]
    ]
    
    return {
        "predicted": top[0],
        "confidence": top[1] / total if total > 0 else 0.0,
        "alternatives": alternatives,
    }


def mine_causal_links(
    events: list[dict[str, Any]],
    min_correlation: float = 0.5,
    max_time_delta: float = 3600,  # 1 hour
) -> list[dict[str, Any]]:
    """Mine causal relationships between events with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'mine_causal'):
        try:
            result = _rs.mine_causal(events, min_correlation, max_time_delta)
            return list(result)
        except Exception:
            pass
    
    # Python fallback: temporal correlation
    links = []
    n = len(events)
    
    for i in range(n):
        for j in range(i + 1, n):
            event_a = events[i]
            event_b = events[j]
            
            time_a = event_a.get("timestamp", 0)
            time_b = event_b.get("timestamp", 0)
            
            if time_b - time_a > max_time_delta:
                continue
            
            # Check correlation
            score = _compute_temporal_correlation(event_a, event_b)
            
            if score >= min_correlation:
                links.append({
                    "cause_id": event_a.get("id"),
                    "effect_id": event_b.get("id"),
                    "strength": round(score, 3),
                    "time_delta": time_b - time_a,
                })
    
    # Sort by strength
    links.sort(key=lambda x: x["strength"], reverse=True)
    return links[:100]  # Return top 100


def _compute_temporal_correlation(
    event_a: dict[str, Any],
    event_b: dict[str, Any],
) -> float:
    """Compute temporal correlation between two events."""
    # Tag overlap
    tags_a = set(event_a.get("tags", []))
    tags_b = set(event_b.get("tags", []))
    
    if not tags_a or not tags_b:
        return 0.0
    
    intersection = len(tags_a & tags_b)
    union = len(tags_a | tags_b)
    
    return intersection / union if union > 0 else 0.0


class IntelligenceBridge:
    """Rust-accelerated intelligence operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def synthesize_insights(
        self,
        patterns: list[dict[str, Any]],
        min_confidence: float = 0.7
    ) -> list[dict[str, Any]]:
        """Synthesize high-level insights from patterns."""
        insights = []
        
        for pattern in patterns:
            if pattern.get("confidence", 0) >= min_confidence:
                insight = {
                    "pattern_id": pattern.get("id"),
                    "summary": pattern.get("description", "Unknown pattern"),
                    "confidence": pattern.get("confidence"),
                    "frequency": pattern.get("frequency", 1),
                }
                insights.append(insight)
        
        # Sort by confidence * frequency
        insights.sort(key=lambda x: float(x["confidence"]) * x["frequency"], reverse=True)
        return insights[:50]
    
    def bicameral_synthesis(
        self,
        left_hemisphere: list[dict[str, Any]],
        right_hemisphere: list[dict[str, Any]]
    ) -> list[dict[str, Any]]:
        """Synthesize creative insights from bicameral analysis."""
        # Try Rust fast path
        if _rs is not None and hasattr(_rs, 'bicameral_fusion'):
            try:
                return list(_rs.bicameral_fusion(left_hemisphere, right_hemisphere))
            except Exception:
                pass
        
        # Python fallback: cross-hemisphere pattern matching
        fused = []
        
        for left in left_hemisphere:
            for right in right_hemisphere:
                # Look for complementary patterns
                if _patterns_complement(left, right):
                    fused.append({
                        "left_pattern": left.get("id"),
                        "right_pattern": right.get("id"),
                        "synthesis": f"{left.get('theme', 'Unknown')} + {right.get('theme', 'Unknown')}",
                        "novelty_score": 0.8,
                    })
        
        # Sort by novelty
        fused.sort(key=lambda x: x["novelty_score"], reverse=True)
        return fused[:20]
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def _patterns_complement(a: dict[str, Any], b: dict[str, Any]) -> bool:
    """Check if two patterns are complementary for synthesis."""
    # Simple heuristic: different types, similar importance
    type_a = a.get("type", "")
    type_b = b.get("type", "")
    
    if type_a == type_b:
        return False
    
    imp_a = a.get("importance", 0.5)
    imp_b = b.get("importance", 0.5)
    
    return abs(imp_a - imp_b) < 0.3 if isinstance(imp_a, (int, float)) and isinstance(imp_b, (int, float)) else False


def get_intelligence_bridge() -> IntelligenceBridge:
    """Get intelligence bridge instance."""
    return IntelligenceBridge()
