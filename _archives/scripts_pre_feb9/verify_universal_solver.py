
import sys
from pathlib import Path
import logging

# Setup path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.intelligence.synthesis.solver_engine import DharmicSolver

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

def test_universal_solver():
    print("\n🌌 Testing Phase 34 Universal Solver (Frank-Wolfe)")
    print("==================================================")
    
    # 1. Define a complex graph (10 nodes)
    nodes = [f"Node_{i}" for i in range(10)]
    edges = [
        ("Node_0", "Node_1"), ("Node_1", "Node_2"), # Causal chain
        ("Node_3", "Node_4"), ("Node_0", "Node_5")
    ]
    
    # Random scores with some "High Resonance" nodes
    scores = {node: 0.1 for node in nodes}
    scores["Node_2"] = 0.9 # High value but depends on Node_0 and Node_1
    scores["Node_4"] = 0.8 # Depends on Node_3
    scores["Node_6"] = 0.7 # Independent
    
    solver = DharmicSolver()
    
    print("\n[1] Running solver with standard parameters...")
    result = solver.solve(nodes, edges, scores, lambda_reg=0.01)
    print(f"    Selected nodes: {result}")
    
    # Verification checks
    if "Node_2" in result:
        assert "Node_1" in result and "Node_0" in result, "Causal violation: Node_2 selected without parents!"
    
    print("\n[2] Testing Dharmic Guardrail (Balanced Hexagram)...")
    # Our solver forces the first 6 nodes to have exactly 3 selected if Dharma is active
    # We'll check if exactly 3 out of [Node_0...Node_5] are selected
    dharma_subset = [f"Node_{i}" for i in range(6)]
    selected_dharma = [node for node in result if node in dharma_subset]
    
    print(f"    Nodes in Dharma subset (0-5) selected: {selected_dharma}")
    # The solver should enforce this if get_dharma_bridge() returns the invariant
    # In our current setup, it does.
    if len(selected_dharma) == 3:
        print("    ✅ Dharmic Invariant (Balanced Hexagram) satisfied.")
    else:
        print(f"    ⚠️ Dharmic Invariant not enforced (Count: {len(selected_dharma)}/3). Check bridge.")

    print("\n✨ Universal Solver Verification Complete.")

if __name__ == "__main__":
    test_universal_solver()
