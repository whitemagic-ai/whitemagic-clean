"""
WM2 - Biological Subsystem Wiring
==================================
Wire all 7 biological subsystems into unified nervous system
"""

import sys
from pathlib import Path
from typing import Dict, Any

# Add WM1 to path for imports
WM1_ROOT = Path(__file__).parent.parent.parent / "whitemagicdev"
sys.path.insert(0, str(WM1_ROOT))

class SubsystemWiring:
    """Wire all biological subsystems together."""
    
    def __init__(self):
        self.subsystems = {}
        self.wired = False
    
    def wire_immune_system(self):
        """Wire immune system (10 files)."""
        try:
            from whitemagic.core.security.immune_system import ImmuneSystem
            self.subsystems['immune'] = ImmuneSystem()
            return True
        except ImportError as e:
            print(f"⚠️  Immune system: {e}")
            return False
    
    def wire_evolution_engine(self):
        """Wire genetic/evolutionary system (6 files)."""
        try:
            from whitemagic.agents.phylogenetics import SelectionEngine
            self.subsystems['evolution'] = SelectionEngine()
            return True
        except ImportError as e:
            print(f"⚠️  Evolution engine: {e}")
            return False
    
    def wire_dream_cycle(self):
        """Wire dream/sleep cycle (8 files)."""
        try:
            from whitemagic.core.dreaming.dream_cycle import DreamCycle
            self.subsystems['dreams'] = DreamCycle()
            return True
        except ImportError as e:
            print(f"⚠️  Dream cycle: {e}")
            return False
    
    def wire_memory_metabolism(self):
        """Wire memory metabolism (6 files)."""
        try:
            from whitemagic.core.memory.consolidation import ConsolidationEngine
            self.subsystems['metabolism'] = ConsolidationEngine()
            return True
        except ImportError as e:
            print(f"⚠️  Memory metabolism: {e}")
            return False
    
    def wire_consciousness(self):
        """Wire consciousness/embodiment (5 files)."""
        try:
            from whitemagic.core.consciousness.coherence import CoherenceEngine
            self.subsystems['consciousness'] = CoherenceEngine()
            return True
        except ImportError as e:
            print(f"⚠️  Consciousness: {e}")
            return False
    
    def wire_resonance(self):
        """Wire resonance/harmony (8 files)."""
        try:
            from whitemagic.core.resonance.resonance_engine import ResonanceEngine
            self.subsystems['resonance'] = ResonanceEngine()
            return True
        except ImportError as e:
            print(f"⚠️  Resonance: {e}")
            return False
    
    def wire_emergence(self):
        """Wire emergence/ecology (6 files)."""
        try:
            from whitemagic.core.intelligence.emergence.emergence_engine import EmergenceEngine
            self.subsystems['emergence'] = EmergenceEngine()
            return True
        except ImportError as e:
            print(f"⚠️  Emergence: {e}")
            return False
    
    def wire_all(self) -> Dict[str, bool]:
        """Wire all subsystems."""
        results = {
            'immune': self.wire_immune_system(),
            'evolution': self.wire_evolution_engine(),
            'dreams': self.wire_dream_cycle(),
            'metabolism': self.wire_memory_metabolism(),
            'consciousness': self.wire_consciousness(),
            'resonance': self.wire_resonance(),
            'emergence': self.wire_emergence(),
        }
        
        self.wired = all(results.values())
        return results
    
    def get_health_status(self) -> Dict[str, Any]:
        """Get health status of all subsystems."""
        return {
            'wired': self.wired,
            'subsystems': {
                name: subsystem is not None
                for name, subsystem in self.subsystems.items()
            },
            'total': len(self.subsystems),
            'active': sum(1 for s in self.subsystems.values() if s is not None),
        }
    
    def process_signal(self, signal: Dict[str, Any]) -> Dict[str, Any]:
        """Route signal through nervous system."""
        results = {}
        
        signal_type = signal.get('type', 'unknown')
        
        # Route to appropriate subsystems
        if signal_type == 'threat' and 'immune' in self.subsystems:
            results['immune'] = "threat_detected"
        
        if signal_type == 'consolidation' and 'dreams' in self.subsystems:
            results['dreams'] = "consolidation_queued"
        
        if signal_type == 'evolution' and 'evolution' in self.subsystems:
            results['evolution'] = "mutation_applied"
        
        return results


if __name__ == "__main__":
    print("=" * 80)
    print("WIRING BIOLOGICAL SUBSYSTEMS")
    print("=" * 80)
    print()
    
    wiring = SubsystemWiring()
    results = wiring.wire_all()
    
    print("Wiring Results:")
    for subsystem, success in results.items():
        status = "✅" if success else "⚠️"
        print(f"   {status} {subsystem}")
    
    print()
    
    health = wiring.get_health_status()
    print("Health Status:")
    print(f"   Active: {health['active']}/{health['total']}")
    print(f"   Fully Wired: {'✅' if health['wired'] else '⚠️'}")
    print()
    
    if health['wired']:
        print("✅ All biological subsystems wired into unified nervous system!")
    else:
        print("⚠️  Some subsystems could not be wired (may need dependencies)")
    
    print()
    print("=" * 80)
