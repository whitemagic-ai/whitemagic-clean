
import sys
import os
from datetime import datetime

# Ensure we can import our core modules
sys.path.append(os.path.join(os.getcwd(), "staging/core_system"))

try:
    import whitemagic_rs
    from whitemagic.gardens.metal.zodiac.api import get_unified_zodiac
    from whitemagic.gardens.air.agentic.terminal_scratchpad import TerminalScratchpad
except ImportError as e:
    print(f"Error importing modules: {e}")
    sys.exit(1)

# Colors
class Colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'

class WuXingEngine:
    """Simple Wu Xing (Five Elements) Engine"""
    
    def __init__(self):
        self.phases = ["wood", "fire", "earth", "metal", "water"]
        self.generation_cycle = {
            "wood": "fire",
            "fire": "earth",
            "earth": "metal",
            "metal": "water",
            "water": "wood"
        }
        
    def determine_phase(self) -> str:
        """Determine phase based on hour"""
        hour = datetime.now().hour
        # Simple mapping
        if 23 <= hour or hour < 5: return "water" # Night
        if 5 <= hour < 9: return "wood"   # Dawn
        if 9 <= hour < 14: return "fire"  # Noon
        if 14 <= hour < 18: return "earth" # Afternoon
        if 18 <= hour < 23: return "metal" # Evening
        return "earth"
        
    def get_phase_wisdom(self, phase: str) -> str:
        wisdom = {
            "wood": "Growth, creativity, planning. Expand horizons.",
            "fire": "Action, expression, peak energy. Execute boldly.",
            "earth": "Grounding, stability, nourishment. Consolidate gains.",
            "metal": "Refinement, analysis, letting go. Optimize and prune.",
            "water": "Wisdom, dormancy, gestation. Reflect and plan."
        }
        return wisdom.get(phase, "")

class StrategicOracle:
    def __init__(self):
        self.zodiac = get_unified_zodiac()
        self.wu_xing = WuXingEngine()
        
    def consult(self, query: str):
        print(f"\n{Colors.HEADER}🔮 CONSULTING THE STRATEGIC ORACLE{Colors.ENDC}")
        print(f"Original Query: {query}\n")
        
        with TerminalScratchpad("Oracle Consultation") as pad:
            pad.think(f"Analyzing query: '{query}'")
            
            # 1. I Ching (The Seed/Foundation)
            pad.think("Consulting I Ching for foundational energy...")
            hex_num, lines = whitemagic_rs.iching_cast(query)
            pad.observe(f"I Ching Hexagram: {hex_num}")
            
            # 2. Wu Xing (The Current Phase)
            pad.think("Determining current Wu Xing phase...")
            phase = self.wu_xing.determine_phase()
            phase_wisdom = self.wu_xing.get_phase_wisdom(phase)
            pad.observe(f"Wu Xing Phase: {phase.upper()} - {phase_wisdom}")
            
            # 3. Zodiac (The 12 Voices)
            pad.think("Convening Zodiac Council for perspectives...")
            
            # Select relevant signs based on phase/query
            # For "Strategy", we usually want Aries (Action), Virgo (Analysis), Capricorn (Strategy), Aquarius (Vision)
            key_signs = ["aries", "virgo", "capricorn", "aquarius"]
            perspectives = []
            
            for sign in key_signs:
                p = self.zodiac.get_perspective(sign, {"operation": "devise strategy", "intention": query})
                perspectives.append(f"{sign.title()}: {p.wisdom}")
                # pad.observe(f"{sign.title()}: {p.wisdom}") # Too verbose for scratchpad
                
            # 4. Synthesis
            pad.decide("Synthesizing inputs into final strategy...")
            
            strategy = self._synthesize(hex_num, phase, perspectives)
            
            pad.think("Final strategy formulated.")
            
            # Print Final Report
            print(f"\n{Colors.BOLD}=== 📜 THE ORACLE SPEAKS ==={Colors.ENDC}\n")
            
            print(f"{Colors.BLUE}🔹 I CHING (Foundation): Hexagram {hex_num}{Colors.ENDC}")
            print("   Root energy for this movement.\n")
            
            print(f"{Colors.GREEN}🔹 WU XING (Context): {phase.upper()}{Colors.ENDC}")
            print(f"   {phase_wisdom}\n")
            
            print(f"{Colors.HEADER}🔹 ZODIAC COUNCIL (Voices):{Colors.ENDC}")
            for p in perspectives:
                print(f"   • {p}")
            print("")
            
            print(f"{Colors.WARNING}➤ STRATEGIC DIRECTIVE:{Colors.ENDC}")
            print(f"{strategy}\n")

    def _synthesize(self, hex_num, phase, perspectives):
        # Heuristic synthesis
        return f"Based on Hexagram {hex_num} and the {phase.upper()} phase, combined with the pragmatic discipline of Capricorn and the vision of Aquarius, we should proceed by grounding our recent gains (Earth/Metal) before launching the next major initiative. Verify, Optimize, then Expand."

if __name__ == "__main__":
    oracle = StrategicOracle()
    # Use CLI arg if provided, else default
    query = sys.argv[1] if len(sys.argv) > 1 else "How should we explore and integrate the recovered legacy systems?"
    oracle.consult(query)
