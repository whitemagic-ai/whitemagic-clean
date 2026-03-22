"""
WM2 - Unified Nervous System
=============================
Integrates all biological subsystems into coherent whole
"""

from dataclasses import dataclass
from typing import Dict, Any, Optional


@dataclass
class NervousSystem:
    """Central coordination for all biological subsystems."""
    
    # Subsystem references
    immune_system: Optional[Any] = None
    evolution_engine: Optional[Any] = None
    dream_cycle: Optional[Any] = None
    memory_metabolism: Optional[Any] = None
    consciousness: Optional[Any] = None
    resonance_engine: Optional[Any] = None
    emergence_detector: Optional[Any] = None
    
    def __post_init__(self):
        """Initialize nervous system."""
        self.initialized = False
    
    def wire_subsystems(self):
        """Wire all subsystems together."""
        # Import and initialize each subsystem
        try:
            from whitemagic.core.security.immune_system import ImmuneSystem
            self.immune_system = ImmuneSystem()
        except ImportError:
            pass
        
        try:
            from whitemagic.agents.phylogenetics import SelectionEngine
            self.evolution_engine = SelectionEngine()
        except ImportError:
            pass
        
        try:
            from whitemagic.core.memory.dream_cycle import DreamCycle
            self.dream_cycle = DreamCycle()
        except ImportError:
            pass
        
        # Continue for other subsystems...
        
        self.initialized = True
    
    def get_health_status(self) -> Dict[str, Any]:
        """Get health status of all subsystems."""
        return {
            "immune": self.immune_system is not None,
            "evolution": self.evolution_engine is not None,
            "dreams": self.dream_cycle is not None,
            "metabolism": self.memory_metabolism is not None,
            "consciousness": self.consciousness is not None,
            "resonance": self.resonance_engine is not None,
            "emergence": self.emergence_detector is not None,
            "overall_health": self.initialized,
        }
    
    def process_signal(self, signal: Dict[str, Any]) -> Dict[str, Any]:
        """Process signal through nervous system."""
        # Route signal to appropriate subsystems
        results = {}
        
        if self.immune_system and signal.get("type") == "threat":
            results["immune"] = self.immune_system.respond(signal)
        
        if self.dream_cycle and signal.get("type") == "consolidation":
            results["dreams"] = self.dream_cycle.process(signal)
        
        # Continue routing...
        
        return results
