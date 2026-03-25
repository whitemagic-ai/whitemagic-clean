"""Synthesis Protocol — Cross-System Harmony Engine.

Implements the mathematical and philosophical framework for harmonizing
multiple autonomous systems into a coherent, evolving whole.

Key Concepts:
- Resonance Fields: How systems influence each other through event propagation
- Coherence Gradient: The measure of systemic alignment (0.0 = chaos, 1.0 = unity)
- Productive Tension: The optimal conflict zone where innovation emerges
- Emergence Thresholds: When system interactions produce novel capabilities
"""

from __future__ import annotations

import logging
import math
from dataclasses import dataclass
from datetime import datetime
from typing import Any

logger = logging.getLogger(__name__)


@dataclass
class ResonanceField:
    """
    A field representing the influence between two or more systems.
    
    Like gravitational fields, resonance fields weaken with distance
    but can be amplified by coherence alignment.
    """
    source_system: str
    target_system: str
    base_strength: float = 0.5  # 0.0 to 1.0
    coherence_coupling: float = 0.3  # How much coherence affects resonance
    decay_rate: float = 0.1  # How quickly resonance decays with distance
    
    def calculate_effective_resonance(
        self,
        source_coherence: float,
        target_coherence: float,
        distance: float = 1.0,
    ) -> float:
        """
        Calculate the effective resonance between systems.
        
        Formula: base_strength * coherence_factor * distance_decay
        where coherence_factor = (source_coherence + target_coherence) / 2 * coupling
        """
        avg_coherence = (source_coherence + target_coherence) / 2
        coherence_boost = 1.0 + (avg_coherence * self.coherence_coupling)
        distance_decay = math.exp(-self.decay_rate * distance)
        
        return self.base_strength * coherence_boost * distance_decay


@dataclass
class ProductiveTensionZone:
    """
    Defines the optimal tension zone for system interactions.
    
    Too little tension = stagnation (systems don't challenge each other)
    Too much tension = chaos (systems interfere destructively)
    Optimal tension = emergence (systems create together)
    """
    min_tension: float = 0.3  # Below this, systems are too comfortable
    optimal_tension: float = 0.6  # The sweet spot for creativity
    max_tension: float = 0.9  # Above this, systems destabilize
    
    def evaluate_interaction(self, tension: float) -> dict[str, Any]:
        """Evaluate whether tension level is productive."""
        if tension < self.min_tension:
            return {
                "status": "stagnant",
                "recommendation": "increase_diversity",
                "productivity": tension / self.optimal_tension,
            }
        elif tension > self.max_tension:
            return {
                "status": "chaotic",
                "recommendation": "stabilize_core",
                "productivity": 1.0 - ((tension - self.max_tension) / 0.1),
            }
        else:
            # Within productive zone
            distance_from_optimal = abs(tension - self.optimal_tension)
            productivity = 1.0 - (distance_from_optimal / 0.3)
            
            return {
                "status": "productive",
                "recommendation": "maintain" if productivity > 0.8 else "adjust_slightly",
                "productivity": max(0.0, productivity),
            }


@dataclass
class EmergencePattern:
    """
    A detected pattern indicating emergent behavior.
    
    Emergence occurs when system interactions produce outputs that
    cannot be predicted from individual system capabilities.
    """
    pattern_id: str
    description: str
    participating_systems: list[str]
    first_detected: datetime
    confidence: float
    
    # Emergence metrics
    novelty_score: float = 0.0  # How novel is this behavior
    stability_score: float = 0.0  # How stable is the pattern
    capability_gain: float = 0.0  # What new capability emerged
    
    def to_dict(self) -> dict[str, Any]:
        return {
            "pattern_id": self.pattern_id,
            "description": self.description,
            "systems": self.participating_systems,
            "detected": self.first_detected.isoformat(),
            "confidence": self.confidence,
            "metrics": {
                "novelty": self.novelty_score,
                "stability": self.stability_score,
                "capability_gain": self.capability_gain,
            },
        }


class SynthesisEngine:
    """
    The mathematical engine for cross-system synthesis.
    
    This is the "physics" of the unified orchestration layer—
    it provides the formulas and algorithms that govern how systems
    harmonize and create emergent intelligence.
    """
    
    def __init__(self) -> None:
        self.resonance_fields: dict[str, ResonanceField] = {}
        self.tension_zone = ProductiveTensionZone()
        self.emergence_patterns: list[EmergencePattern] = []
        self._coherence_history: list[float] = []
        
        # Initialize default resonance fields between major systems
        self._initialize_default_fields()
    
    def _initialize_default_fields(self) -> None:
        """Set up default resonance relationships between systems."""
        # Nervous System ↔ Gardens (strong bidirectional)
        self._add_field("nervous", "gardens", base_strength=0.8, coupling=0.5)
        
        # Gardens ↔ Identity (medium, identity emerges from garden experience)
        self._add_field("gardens", "identity", base_strength=0.6, coupling=0.4)
        
        # Nervous System ↔ Identity (medium-strong, identity shapes and is shaped by biology)
        self._add_field("nervous", "identity", base_strength=0.7, coupling=0.6)
        
        # Memory Metabolism ↔ All (foundational, all systems need memory)
        self._add_field("memory", "nervous", base_strength=0.9, coupling=0.3)
        self._add_field("memory", "gardens", base_strength=0.9, coupling=0.3)
        self._add_field("memory", "identity", base_strength=0.8, coupling=0.4)
    
    def _add_field(
        self,
        source: str,
        target: str,
        base_strength: float,
        coupling: float,
    ) -> None:
        """Add a resonance field (bidirectional)."""
        key = f"{source}:{target}"
        self.resonance_fields[key] = ResonanceField(
            source_system=source,
            target_system=target,
            base_strength=base_strength,
            coherence_coupling=coupling,
        )
        
        # Add reverse field
        reverse_key = f"{target}:{source}"
        self.resonance_fields[reverse_key] = ResonanceField(
            source_system=target,
            target_system=source,
            base_strength=base_strength,
            coherence_coupling=coupling,
        )
    
    def calculate_systemic_coherence(
        self,
        system_states: dict[str, dict[str, Any]],
    ) -> float:
        """
        Calculate overall coherence across all systems.
        
        This is NOT just the average—it's a weighted measure that accounts
        for resonance between systems. A system in isolation can be healthy,
        but true coherence emerges from the web of relationships.
        """
        if not system_states:
            return 0.0
        
        # Extract individual coherence scores
        individual_scores = {}
        for system, state in system_states.items():
            # Different systems report health differently
            if "coherence" in state:
                individual_scores[system] = state["coherence"]
            elif "active" in state:
                individual_scores[system] = 1.0 if state["active"] else 0.0
            elif "health" in state:
                individual_scores[system] = state["health"]
            else:
                individual_scores[system] = 0.5  # Unknown
        
        # Calculate pairwise resonance contributions
        resonance_contributions = []
        for _key, resonance_field in self.resonance_fields.items():
            if resonance_field.source_system in individual_scores and resonance_field.target_system in individual_scores:
                resonance = resonance_field.calculate_effective_resonance(
                    individual_scores[resonance_field.source_system],
                    individual_scores[resonance_field.target_system],
                )
                resonance_contributions.append(resonance)
        
        # Systemic coherence = weighted combination of individual + resonance
        avg_individual = sum(individual_scores.values()) / len(individual_scores)
        avg_resonance = sum(resonance_contributions) / len(resonance_contributions) if resonance_contributions else 0.0
        
        # Resonance amplifies individual coherence
        systemic_coherence = (avg_individual * 0.6) + (avg_resonance * 0.4)
        
        self._coherence_history.append(systemic_coherence)
        if len(self._coherence_history) > 1000:
            self._coherence_history.pop(0)
        
        return systemic_coherence
    
    def detect_emergence(
        self,
        recent_events: list[dict[str, Any]],
        system_states: dict[str, dict[str, Any]],
    ) -> list[EmergencePattern]:
        """
        Detect emergent patterns in recent system behavior.
        
        Emergence detection looks for:
        1. Novel event sequences (haven't happened before)
        2. Multi-system coordination (more than 2 systems involved)
        3. Capability demonstration (something new was accomplished)
        4. Stability (the pattern repeats or persists)
        """
        detected = []
        
        # Group events by timestamp windows (5-minute buckets)
        from collections import defaultdict
        
        time_buckets = defaultdict(list)
        for event in recent_events:
            ts = event.get("timestamp", datetime.now())
            if isinstance(ts, str):
                ts = datetime.fromisoformat(ts.replace("Z", "+00:00"))
            bucket = ts.replace(second=0, microsecond=0)
            bucket = bucket.replace(minute=(bucket.minute // 5) * 5)
            time_buckets[bucket].append(event)
        
        # Look for multi-system patterns in each bucket
        for bucket, events in time_buckets.items():
            # Count unique systems involved
            systems_involved = set()
            for event in events:
                source = event.get("source_system", "unknown")
                systems_involved.add(source.split(".")[0])  # Get base system name
            
            # If 3+ systems involved in short window, potential emergence
            if len(systems_involved) >= 3:
                # Check if this is novel
                pattern_key = frozenset(systems_involved)
                is_novel = not any(
                    frozenset(p.participating_systems) == pattern_key
                    for p in self.emergence_patterns[-10:]  # Check recent patterns
                )
                
                if is_novel:
                    pattern = EmergencePattern(
                        pattern_id=f"emerge_{bucket.strftime('%Y%m%d%H%M')}_{len(systems_involved)}",
                        description=f"Coordination between {', '.join(systems_involved)}",
                        participating_systems=list(systems_involved),
                        first_detected=bucket,
                        confidence=min(1.0, len(events) / 10),  # More events = higher confidence
                        novelty_score=0.8,
                        stability_score=0.5,  # Will increase if pattern repeats
                        capability_gain=0.6,  # Assumed capability from coordination
                    )
                    detected.append(pattern)
                    self.emergence_patterns.append(pattern)
                    
                    logger.info(
                        f"🌟 EMERGENCE DETECTED: {pattern.description} "
                        f"(confidence: {pattern.confidence:.0%})"
                    )
        
        return detected
    
    def optimize_tension(
        self,
        current_tension: float,
        recent_productivity: float,
    ) -> dict[str, Any]:
        """
        Recommend tension adjustments to maximize productivity.
        
        The synthesis engine learns from recent history whether
        current tension levels are producing good results.
        """
        evaluation = self.tension_zone.evaluate_interaction(current_tension)
        
        recommendation = {
            "current_tension": current_tension,
            "current_productivity": recent_productivity,
            "status": evaluation["status"],
            "recommended_action": evaluation["recommendation"],
            "target_tension": self.tension_zone.optimal_tension,
        }
        
        # If productivity is dropping while tension is high, reduce conflict
        if recent_productivity < 0.5 and current_tension > self.tension_zone.optimal_tension:
            recommendation["recommended_action"] = "reduce_tension"
            recommendation["target_tension"] = self.tension_zone.optimal_tension
        
        # If productivity is dropping while tension is low, increase diversity
        elif recent_productivity < 0.5 and current_tension < self.tension_zone.min_tension:
            recommendation["recommended_action"] = "increase_diversity"
            recommendation["target_tension"] = self.tension_zone.min_tension + 0.1
        
        return recommendation
    
    def calculate_harmony_vector(
        self,
        system_states: dict[str, dict[str, Any]],
    ) -> tuple[float, float, float, float]:
        """
        Calculate the 4D harmony vector representing systemic balance.
        
        X-axis: Integration/Differentiation (are systems too merged or too separate?)
        Y-axis: Stability/Change (is the system stuck or too chaotic?)
        Z-axis: Internal/External (is focus inward or outward?)
        W-axis: Present/Future (is focus on immediate or long-term?)
        
        A healthy system oscillates around (0, 0, 0, 0.2)
        representing: balanced integration, productive change,
        both internal and external awareness, slight future focus.
        """
        if not system_states:
            return (0.0, 0.0, 0.0, 0.0)
        
        # Calculate variance in coherence (high variance = differentiation)
        coherences = [
            s.get("coherence", s.get("health", 0.5))
            for s in system_states.values()
        ]
        if len(coherences) > 1:
            mean_coh = sum(coherences) / len(coherences)
            variance = sum((c - mean_coh) ** 2 for c in coherences) / len(coherences)
            x = variance * 2 - 0.5  # Scale to -0.5 to 0.5 range
        else:
            x = 0.0
        
        # Calculate change rate from history
        if len(self._coherence_history) >= 10:
            recent_avg = sum(self._coherence_history[-10:]) / 10
            older_avg = sum(self._coherence_history[-20:-10]) / 10 if len(self._coherence_history) >= 20 else recent_avg
            change_rate = recent_avg - older_avg
            y = change_rate * 5  # Amplify small changes
        else:
            y = 0.0
        
        # Z and W are more subjective, based on event types
        # For now, use defaults that suggest healthy balance
        z = 0.0  # Balanced internal/external
        w = 0.2  # Slight future focus
        
        return (max(-1, min(1, x)), max(-1, min(1, y)), z, w)
    
    def get_synthesis_report(self) -> dict[str, Any]:
        """Generate a comprehensive synthesis report."""
        return {
            "resonance_fields": len(self.resonance_fields),
            "emergence_patterns_detected": len(self.emergence_patterns),
            "recent_emergence": [
                p.to_dict() for p in self.emergence_patterns[-5:]
            ],
            "coherence_trend": "rising" if len(self._coherence_history) >= 10 and 
                self._coherence_history[-1] > self._coherence_history[-10] else "stable",
            "tension_zone": {
                "optimal": self.tension_zone.optimal_tension,
                "current_assessment": "productive",  # Would be calculated from real data
            },
        }


# ═══════════════════════════════════════════════════════════════════════════
# GLOBAL ACCESSOR
# ═══════════════════════════════════════════════════════════════════════════

_synthesis_engine: SynthesisEngine | None = None


def get_synthesis_engine() -> SynthesisEngine:
    """Get the global Synthesis Engine instance."""
    global _synthesis_engine
    if _synthesis_engine is None:
        _synthesis_engine = SynthesisEngine()
    return _synthesis_engine
