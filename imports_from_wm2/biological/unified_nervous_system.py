"""
WM2 Biological: Unified Nervous System
=======================================

Wires all 7 biological subsystems together for emergent intelligence.
"""

from typing import Any

from wm2.biological.consciousness_monitor import ConsciousnessMonitor

# Import all biological controllers
from wm2.biological.dream_cycle_controller import DreamCycleController
from wm2.biological.emergence_detector import EmergenceDetector
from wm2.biological.evolution_engine import EvolutionEngine
from wm2.biological.immune_coordinator import ImmuneCoordinator
from wm2.biological.metabolism_controller import MetabolismController
from wm2.biological.resonance_bus import ResonanceBus
from wm2.core import BaseEngine
from wm2.core.metrics import MetricCollector, tracked
from wm2.core.serializable import Serializable


class UnifiedNervousSystem(BaseEngine, Serializable, MetricCollector):
    """
    Unified nervous system integrating all 7 biological subsystems.

    Enables emergent behaviors through cross-system communication.
    """

    def __init__(self, name: str = "nervous_system"):
        BaseEngine.__init__(self, name=name)
        MetricCollector.__init__(self)

        # Initialize all subsystems
        self.subsystems = {
            "dream": DreamCycleController(),
            "resonance": ResonanceBus(),
            "evolution": EvolutionEngine(),
            "consciousness": ConsciousnessMonitor(),
            "emergence": EmergenceDetector(),
            "metabolism": MetabolismController(),
            "immune": ImmuneCoordinator(),
        }

        self.wired = False

    @tracked
    def wire_all(self) -> dict[str, bool]:
        """Wire all subsystems together."""
        results = {}

        for name, subsystem in self.subsystems.items():
            try:
                subsystem.activate()
                results[name] = True
            except Exception:
                results[name] = False

        self.wired = all(results.values())
        self.record_metric("wiring_complete", self.wired)

        return results

    @tracked
    def route_signal(self, signal: dict[str, Any]) -> dict[str, Any]:
        """Route a signal through appropriate subsystems."""
        if not self.wired:
            return {"error": "nervous_system_not_wired"}

        signal_type = signal.get("type", "unknown")
        results = {}

        # Route to appropriate subsystems based on signal type
        if signal_type in ["consolidation", "dream"]:
            results["dream"] = self.subsystems["dream"].process_signal(signal)

        if signal_type in ["harmony", "resonance"]:
            results["resonance"] = self.subsystems["resonance"].process_signal(signal)

        if signal_type in ["evolution", "mutation"]:
            results["evolution"] = self.subsystems["evolution"].process_signal(signal)

        if signal_type in ["awareness", "consciousness"]:
            results["consciousness"] = self.subsystems["consciousness"].process_signal(signal)

        if signal_type in ["emergence", "serendipity"]:
            results["emergence"] = self.subsystems["emergence"].process_signal(signal)

        if signal_type in ["decay", "metabolism"]:
            results["metabolism"] = self.subsystems["metabolism"].process_signal(signal)

        if signal_type in ["threat", "immune"]:
            results["immune"] = self.subsystems["immune"].process_signal(signal)

        return results

    @tracked
    def get_system_health(self) -> dict[str, Any]:
        """Get health status of entire nervous system."""
        health = {
            "wired": self.wired,
            "subsystems": {},
        }

        for name, subsystem in self.subsystems.items():
            health["subsystems"][name] = subsystem.get_health()

        active_count = sum(1 for s in self.subsystems.values() if s.active)
        health["active_subsystems"] = active_count
        health["total_subsystems"] = len(self.subsystems)

        return health

    @tracked
    def get_stats(self) -> dict[str, Any]:
        """Get comprehensive statistics."""
        return {
            **BaseEngine.get_stats(self),
            **MetricCollector.get_stats(self),
            "system_health": self.get_system_health(),
        }
