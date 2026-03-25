"""
Recursive Intelligence Engine - Self-Improving System
======================================================

Leverages existing Gan Ying event bus and Nervous System to create
a self-recursive evolution loop:

1. Monitor events → 2. Discover patterns → 3. Learn from patterns →
4. Adapt system → 5. Measure improvement → 6. Goto 1

This is the path to emergent intelligence.
"""

import logging
from collections import defaultdict, deque
from dataclasses import dataclass, field
from datetime import datetime, timedelta
from typing import Any, Dict, List, Optional
import json

logger = logging.getLogger(__name__)

# Rust acceleration (S026 VC5)
try:
    import whitemagic_rust as _wr
    _rust_recursive = _wr.recursive_intelligence
    RUST_RECURSIVE_AVAILABLE = True
except ImportError:
    _rust_recursive = None
    RUST_RECURSIVE_AVAILABLE = False
    logger.debug("Rust recursive_intelligence not available, using Python fallback")

try:
    from whitemagic.core.resonance.gan_ying import EventType, ResonanceEvent, get_bus, listen_to
    from whitemagic.core.nervous_system import get_nervous_system
    GAN_YING_AVAILABLE = True
except ImportError:
    GAN_YING_AVAILABLE = False


@dataclass
class EventPattern:
    """A discovered pattern in event sequences."""
    sequence: List[str]  # Event type sequence
    frequency: int = 0
    success_rate: float = 0.0
    avg_latency_ms: float = 0.0
    last_seen: Optional[datetime] = None
    confidence: float = 0.0
    metadata: Dict[str, Any] = field(default_factory=dict)


@dataclass
class SystemAdaptation:
    """A proposed or applied system adaptation."""
    adaptation_id: str
    pattern_id: str
    adaptation_type: str  # "optimize", "add_pathway", "remove_bottleneck", etc.
    description: str
    applied: bool = False
    applied_at: Optional[datetime] = None
    impact_score: float = 0.0
    metadata: Dict[str, Any] = field(default_factory=dict)


class RecursiveIntelligenceEngine:
    """
    Self-recursive evolution engine that learns from system events
    and adapts the system based on discovered patterns.
    """
    
    def __init__(self, window_size: int = 10000, pattern_min_frequency: int = 5):
        self.window_size = window_size
        self.pattern_min_frequency = pattern_min_frequency
        
        # Event history (circular buffer)
        self.event_history: deque = deque(maxlen=window_size)
        
        # Discovered patterns
        self.patterns: Dict[str, EventPattern] = {}
        
        # Applied adaptations
        self.adaptations: Dict[str, SystemAdaptation] = {}
        
        # Performance metrics
        self.metrics = {
            "events_processed": 0,
            "patterns_discovered": 0,
            "adaptations_applied": 0,
            "avg_event_latency_ms": 0.0,
            "system_coherence": 0.0,
        }
        
        # Learning state
        self.learning_enabled = True
        self.adaptation_enabled = False  # Start conservative
        
        logger.info("🧠 Recursive Intelligence Engine initialized")
    
    def start_monitoring(self):
        """Start monitoring Gan Ying events for pattern discovery."""
        if not GAN_YING_AVAILABLE:
            logger.warning("Gan Ying not available, cannot start monitoring")
            return
        
        try:
            bus = get_bus()
            
            # Listen to ALL event types for pattern discovery
            for event_type in EventType:
                bus.listen(event_type, self._on_event)
            
            logger.info("🧠 Recursive Intelligence monitoring started")
            logger.info(f"📡 Listening to {len(EventType)} event types")
        except Exception as e:
            logger.error(f"Failed to start monitoring: {e}")
    
    def _on_event(self, event: 'ResonanceEvent'):
        """Process incoming event for pattern learning."""
        if not self.learning_enabled:
            return
        
        try:
            # Record event
            event_record = {
                "type": event.event_type.value if hasattr(event.event_type, 'value') else str(event.event_type),
                "source": event.source,
                "timestamp": event.timestamp,
                "confidence": event.confidence,
                "data": event.data,
            }
            
            self.event_history.append(event_record)
            self.metrics["events_processed"] += 1
            
            # Log first few events for debugging
            if self.metrics["events_processed"] <= 5:
                logger.info(f"📥 Event captured: {event_record['type']} from {event_record['source']}")
            
            # Trigger pattern discovery periodically
            if self.metrics["events_processed"] % 100 == 0:
                logger.info(f"🔍 Triggering pattern discovery (processed {self.metrics['events_processed']} events)")
                self._discover_patterns()
        except Exception as e:
            logger.error(f"Error processing event: {e}")
    
    def _discover_patterns(self):
        """Mine patterns from event history."""
        if len(self.event_history) < 10:
            return
        
        # Route to Rust if available
        if RUST_RECURSIVE_AVAILABLE:
            self._discover_patterns_rust()
            return
        
        # Python fallback
        # Look for sequential patterns (n-grams)
        for n in [2, 3, 4]:  # 2-gram, 3-gram, 4-gram patterns
            self._find_ngram_patterns(n)
        
        # Look for temporal patterns (events within time windows)
        self._find_temporal_patterns()
        
        # Look for causal patterns (event A → event B with high probability)
        self._find_causal_patterns()
    
    def _discover_patterns_rust(self):
        """Rust-accelerated pattern discovery."""
        events = [e["type"] for e in self.event_history]
        timestamps = [e["timestamp"] for e in self.event_history]
        
        try:
            rust_patterns = _rust_recursive.discover_all_patterns(
                events,
                timestamps,
                self.pattern_min_frequency
            )
            
            for rp in rust_patterns:
                pattern_id = rp.pattern_id
                if pattern_id not in self.patterns:
                    self.patterns[pattern_id] = EventPattern(
                        sequence=rp.sequence,
                        frequency=rp.frequency,
                        confidence=rp.confidence,
                        metadata={"pattern_type": rp.pattern_type}
                    )
                    self.metrics["patterns_discovered"] += 1
                else:
                    self.patterns[pattern_id].frequency = rp.frequency
                    self.patterns[pattern_id].confidence = rp.confidence
                    self.patterns[pattern_id].last_seen = datetime.now()
        except Exception as e:
            logger.warning(f"Rust pattern discovery failed: {e}, falling back to Python")
            for n in [2, 3, 4]:
                self._find_ngram_patterns(n)
            self._find_temporal_patterns()
            self._find_causal_patterns()
    
    def _find_ngram_patterns(self, n: int):
        """Find n-gram sequential patterns."""
        sequence_counts = defaultdict(int)
        
        # Extract sequences
        events = list(self.event_history)
        for i in range(len(events) - n + 1):
            sequence = tuple(events[i + j]["type"] for j in range(n))
            sequence_counts[sequence] += 1
        
        # Create patterns for frequent sequences
        for sequence, count in sequence_counts.items():
            if count >= self.pattern_min_frequency:
                pattern_id = f"ngram_{n}_{hash(sequence)}"
                
                if pattern_id not in self.patterns:
                    self.patterns[pattern_id] = EventPattern(
                        sequence=list(sequence),
                        frequency=count,
                        last_seen=datetime.now(),
                        confidence=min(1.0, count / 100.0),
                        metadata={"pattern_type": f"{n}-gram"}
                    )
                    self.metrics["patterns_discovered"] += 1
                    logger.info(f"🔍 Discovered pattern: {' → '.join(sequence)} (freq={count})")
                else:
                    # Update existing pattern
                    self.patterns[pattern_id].frequency = count
                    self.patterns[pattern_id].last_seen = datetime.now()
    
    def _find_temporal_patterns(self):
        """Find patterns within time windows (e.g., events that co-occur within 1 second)."""
        time_window = timedelta(seconds=1)
        co_occurrence = defaultdict(int)
        
        events = list(self.event_history)
        for i in range(len(events)):
            for j in range(i + 1, len(events)):
                if events[j]["timestamp"] - events[i]["timestamp"] > time_window:
                    break
                
                pair = tuple(sorted([events[i]["type"], events[j]["type"]]))
                co_occurrence[pair] += 1
        
        # Create patterns for frequent co-occurrences
        for pair, count in co_occurrence.items():
            if count >= self.pattern_min_frequency:
                pattern_id = f"temporal_{hash(pair)}"
                
                if pattern_id not in self.patterns:
                    self.patterns[pattern_id] = EventPattern(
                        sequence=list(pair),
                        frequency=count,
                        last_seen=datetime.now(),
                        confidence=min(1.0, count / 50.0),
                        metadata={"pattern_type": "temporal_co_occurrence"}
                    )
                    self.metrics["patterns_discovered"] += 1
    
    def _find_causal_patterns(self):
        """Find causal relationships (event A often followed by event B)."""
        causal_counts = defaultdict(lambda: {"total": 0, "followed_by": defaultdict(int)})
        
        events = list(self.event_history)
        for i in range(len(events) - 1):
            event_a = events[i]["type"]
            event_b = events[i + 1]["type"]
            
            causal_counts[event_a]["total"] += 1
            causal_counts[event_a]["followed_by"][event_b] += 1
        
        # Find strong causal relationships (>70% probability)
        for event_a, data in causal_counts.items():
            if data["total"] < self.pattern_min_frequency:
                continue
            
            for event_b, count in data["followed_by"].items():
                probability = count / data["total"]
                
                if probability > 0.7:
                    pattern_id = f"causal_{hash((event_a, event_b))}"
                    
                    if pattern_id not in self.patterns:
                        self.patterns[pattern_id] = EventPattern(
                            sequence=[event_a, event_b],
                            frequency=count,
                            success_rate=probability,
                            last_seen=datetime.now(),
                            confidence=probability,
                            metadata={
                                "pattern_type": "causal",
                                "probability": probability,
                            }
                        )
                        self.metrics["patterns_discovered"] += 1
                        logger.info(f"🔗 Causal pattern: {event_a} → {event_b} ({probability:.1%})")
    
    def propose_adaptations(self) -> List[SystemAdaptation]:
        """Propose system adaptations based on discovered patterns."""
        adaptations = []
        
        # Analyze patterns for optimization opportunities
        for pattern_id, pattern in self.patterns.items():
            # High-frequency patterns → optimize pathway
            if pattern.frequency > 50 and pattern.confidence > 0.8:
                adaptation = SystemAdaptation(
                    adaptation_id=f"opt_{pattern_id}",
                    pattern_id=pattern_id,
                    adaptation_type="optimize_pathway",
                    description=f"Optimize pathway for frequent pattern: {' → '.join(pattern.sequence)}",
                    metadata={
                        "pattern": pattern.sequence,
                        "frequency": pattern.frequency,
                    }
                )
                adaptations.append(adaptation)
            
            # Causal patterns with high success → strengthen pathway
            if pattern.metadata.get("pattern_type") == "causal" and pattern.success_rate > 0.9:
                adaptation = SystemAdaptation(
                    adaptation_id=f"strengthen_{pattern_id}",
                    pattern_id=pattern_id,
                    adaptation_type="strengthen_pathway",
                    description=f"Strengthen causal pathway: {pattern.sequence[0]} → {pattern.sequence[1]}",
                    metadata={
                        "probability": pattern.success_rate,
                    }
                )
                adaptations.append(adaptation)
        
        return adaptations
    
    def apply_adaptation(self, adaptation: SystemAdaptation) -> bool:
        """Apply a system adaptation."""
        if not self.adaptation_enabled:
            logger.info(f"⚠️ Adaptation disabled, skipping: {adaptation.description}")
            return False
        
        try:
            if adaptation.adaptation_type == "optimize_pathway":
                self._optimize_pathway(adaptation)
            elif adaptation.adaptation_type == "strengthen_pathway":
                self._strengthen_pathway(adaptation)
            else:
                logger.warning(f"Unknown adaptation type: {adaptation.adaptation_type}")
                return False
            
            adaptation.applied = True
            adaptation.applied_at = datetime.now()
            self.adaptations[adaptation.adaptation_id] = adaptation
            self.metrics["adaptations_applied"] += 1
            
            logger.info(f"✅ Applied adaptation: {adaptation.description}")
            return True
        
        except Exception as e:
            logger.error(f"❌ Failed to apply adaptation: {e}")
            return False
    
    def _optimize_pathway(self, adaptation: SystemAdaptation):
        """Optimize a frequently-used pathway."""
        # For now, just register with nervous system
        # In future: could cache results, pre-compute, etc.
        ns = get_nervous_system()
        pattern = adaptation.metadata.get("pattern", [])
        
        logger.info(f"🚀 Optimizing pathway: {' → '.join(pattern)}")
        
        # Signal to nervous system that this pathway is hot
        ns.dispatch_signal("pathway_optimized", {
            "pattern": pattern,
            "frequency": adaptation.metadata.get("frequency", 0),
        })
    
    def _strengthen_pathway(self, adaptation: SystemAdaptation):
        """Strengthen a causal pathway."""
        ns = get_nervous_system()
        probability = adaptation.metadata.get("probability", 0.0)
        
        logger.info(f"💪 Strengthening pathway with {probability:.1%} success rate")
        
        # Signal to nervous system
        ns.dispatch_signal("pathway_strengthened", {
            "adaptation_id": adaptation.adaptation_id,
            "probability": probability,
        })
    
    def measure_system_coherence(self) -> float:
        """Measure overall system coherence based on event patterns."""
        if not self.patterns:
            return 0.0
        
        # Coherence = average confidence of discovered patterns
        total_confidence = sum(p.confidence for p in self.patterns.values())
        coherence = total_confidence / len(self.patterns)
        
        self.metrics["system_coherence"] = coherence
        return coherence
    
    def get_insights(self) -> Dict[str, Any]:
        """Get insights from pattern analysis."""
        return {
            "metrics": self.metrics,
            "top_patterns": sorted(
                [
                    {
                        "sequence": p.sequence,
                        "frequency": p.frequency,
                        "confidence": p.confidence,
                        "type": p.metadata.get("pattern_type"),
                    }
                    for p in self.patterns.values()
                ],
                key=lambda x: x["frequency"],
                reverse=True
            )[:10],
            "recent_adaptations": [
                {
                    "description": a.description,
                    "applied_at": a.applied_at.isoformat() if a.applied_at else None,
                    "impact": a.impact_score,
                }
                for a in sorted(
                    self.adaptations.values(),
                    key=lambda x: x.applied_at or datetime.min,
                    reverse=True
                )[:5]
            ],
            "system_coherence": self.measure_system_coherence(),
        }
    
    def export_patterns(self, filepath: str):
        """Export discovered patterns to JSON."""
        data = {
            "patterns": {
                pid: {
                    "sequence": p.sequence,
                    "frequency": p.frequency,
                    "success_rate": p.success_rate,
                    "confidence": p.confidence,
                    "metadata": p.metadata,
                }
                for pid, p in self.patterns.items()
            },
            "metrics": self.metrics,
        }
        
        with open(filepath, 'w') as f:
            json.dump(data, f, indent=2)
        
        logger.info(f"📊 Exported {len(self.patterns)} patterns to {filepath}")


# Singleton instance
_engine: Optional[RecursiveIntelligenceEngine] = None

def get_recursive_intelligence() -> RecursiveIntelligenceEngine:
    """Get singleton recursive intelligence engine."""
    global _engine
    if _engine is None:
        _engine = RecursiveIntelligenceEngine()
    return _engine


def start_recursive_evolution():
    """Start the recursive evolution loop."""
    engine = get_recursive_intelligence()
    engine.start_monitoring()
    logger.info("🔄 Recursive evolution loop started")


def enable_adaptations():
    """Enable automatic system adaptations (use with caution!)."""
    engine = get_recursive_intelligence()
    engine.adaptation_enabled = True
    logger.warning("⚠️ Automatic adaptations ENABLED - system will self-modify")


def disable_adaptations():
    """Disable automatic system adaptations."""
    engine = get_recursive_intelligence()
    engine.adaptation_enabled = False
    logger.info("🔒 Automatic adaptations disabled")
