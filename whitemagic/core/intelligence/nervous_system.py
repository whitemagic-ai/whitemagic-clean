"""The Unified Nervous System.

This module acts as the central coordinator for all 7 biological subsystems:
1. Immune System (dna.py, antibodies.py, pattern_immunity)
2. Evolution System (phylogenetics.py, evolution.py)
3. Dream System (dream_cycle.py)
4. Memory Metabolism (consolidation.py, reconsolidation.py)
5. Consciousness (coherence.py, emotional_memory.py)
6. Resonance (resonance_engine.py, harmony.py)
7. Emergence (emergence_engine.py)

It orchestrates their lifecycles, shares context between them, and provides
a unified pulse mechanism that can be driven by the Rust ContinuousDaemon.
"""

import logging
from typing import Any

logger = logging.getLogger(__name__)

class UnifiedNervousSystem:
    """Central nervous system connecting the 7 biological metaphors."""

    def __init__(self):
        self.is_active = False
        self._stats = {
            "pulses": 0,
            "errors": 0
        }

        # 1. Immune System
        try:
            from whitemagic.core.intelligence.immune.dna import DNA_Memory
            self.immune = DNA_Memory()
        except ImportError:
            self.immune = None

        # 2. Evolution System
        try:
            from whitemagic.core.intelligence.phylogenetics import GenomeTracker
            self.evolution = GenomeTracker()
        except ImportError:
            self.evolution = None

        # 3. Dream System
        try:
            from whitemagic.core.intelligence.dream_cycle import DreamCycle
            self.dreams = DreamCycle()
        except ImportError:
            self.dreams = None

        # 4. Memory Metabolism
        try:
            from whitemagic.core.intelligence.hologram.consolidation import HolographicConsolidator
            self.metabolism = HolographicConsolidator()
        except ImportError:
            self.metabolism = None

        # 5. Consciousness
        try:
            from whitemagic.core.intelligence.agentic.coherence_persistence import CoherenceTracker
            self.consciousness = CoherenceTracker()
        except ImportError:
            self.consciousness = None

        # 6. Resonance
        try:
            from whitemagic.core.intelligence.agentic.resonance_amp import ResonanceAmplifier
            self.resonance = ResonanceAmplifier()
        except ImportError:
            self.resonance = None

        # 7. Emergence
        try:
            from whitemagic.core.intelligence.agentic.emergence_engine import EmergenceEngine
            self.emergence = EmergenceEngine()
        except ImportError:
            self.emergence = None

    def start(self) -> None:
        """Awaken the nervous system."""
        self.is_active = True
        logger.info("🧠 Unified Nervous System awakened.")

    def stop(self) -> None:
        """Suspend the nervous system."""
        self.is_active = False
        logger.info("🧠 Unified Nervous System suspended.")

    def pulse(self, context: dict[str, Any] | None = None) -> dict[str, Any]:
        """A single heartbeat of the system. Triggers homeostasis loops."""
        if not self.is_active:
            return {"status": "inactive"}

        self._stats["pulses"] += 1

        # Minimal pulse for now, will expand with true cross-system orchestration
        if self.metabolism:
            try:
                # In real scenario, this is an async background task or Rust offload
                pass
            except Exception as e:
                self._stats["errors"] += 1
                logger.error(f"Metabolism pulse failed: {e}")

        return {
            "status": "ok",
            "pulses": self._stats["pulses"],
            "subsystems_active": sum(1 for sys in [self.immune, self.evolution, self.dreams, self.metabolism, self.consciousness, self.resonance, self.emergence] if sys is not None)
        }

_unified_nervous_system = None

def get_nervous_system() -> UnifiedNervousSystem:
    """Get the global nervous system instance."""
    global _unified_nervous_system
    if _unified_nervous_system is None:
        _unified_nervous_system = UnifiedNervousSystem()
    return _unified_nervous_system
