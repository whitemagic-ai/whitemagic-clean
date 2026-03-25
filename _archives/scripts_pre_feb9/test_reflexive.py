
import sys
import logging
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.intelligence.synthesis.accelerator_bridge import AcceleratorBridge

logging.basicConfig(level=logging.INFO)

def test_reflexive_promotion():
    bridge = AcceleratorBridge(ROOT)
    
    # Simulate a successful action dispatch for Cluster (0, 1)
    # This cluster was found in the Satkona run
    metadata = {"cluster_key": "(0, 1)", "mids": ["1", "2", "3"]}
    print("\nDispatching reflexive action for Cluster (0, 1)...")
    # Using an action that doesn't trigger maintenance so it defaults to success
    bridge.dispatch_action("Wu Wei solution observation", metadata)
    
    # Check if anything was promoted
    from whitemagic.core.intelligence.synthesis.solution_library import SolutionLibrary
    lib = SolutionLibrary(ROOT / "memory" / "whitemagic.db")
    solutions = lib.get_all_solutions()
    
    print(f"\nSolutions in Library: {len(solutions)}")
    for sol in solutions:
        print(f"  [PROMOTED] {sol['content'][:80]} (Confidence: {sol['confidence']:.2f}x)")

if __name__ == "__main__":
    test_reflexive_promotion()
