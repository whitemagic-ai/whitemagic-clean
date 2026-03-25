
import sys
import asyncio
import logging
from pathlib import Path

# Setup path
ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.governance.scaffolding.subnet_manager import get_subnet_manager
from whitemagic.core.intelligence.synthesis.solver_engine import DharmicSolver
from whitemagic.core.governance.scaffolding.resonance_ledger import get_resonance_ledger

logging.basicConfig(level=logging.INFO, format='%(levelname)s: %(message)s')
logger = logging.getLogger(__name__)

async def run_science_fair():
    print("\n🏗️  Phase 34: The Distributed Science Fair")
    print("==========================================")
    
    manager = get_subnet_manager()
    solver = DharmicSolver()
    ledger = get_resonance_ledger()
    
    # 1. Task Definition: Resolving a hypothetical 'Memory Leak' in the Data Sea
    print("\n[1] Defining Task: 'Data Sea Memory Leak Analysis'")
    required_capabilities = ["research", "coding", "math"]
    
    allocated_subnets = {}
    for cap in required_capabilities:
        subnet = await manager.allocate_resource(cap, {"heavy_compute": False})
        if subnet:
            allocated_subnets[cap] = subnet
    
    print(f"    Subnets Allocated: {[s.name for s in allocated_subnets.values()]}")
    
    # 2. Optimization: Solving for the best action constellation
    print("\n[2] Universal Solver: Calculating optimal implementation path...")
    nodes = ["Trace Leak", "Analyze Patterns", "Optimize Allocations", "Verify Fix", "Log Resonance"]
    edges = [
        ("Trace Leak", "Analyze Patterns"), 
        ("Analyze Patterns", "Optimize Allocations"),
        ("Optimize Allocations", "Verify Fix")
    ]
    # Scores influenced by allocated subnets' resonance
    scores = {
        "Trace Leak": 0.8 * allocated_subnets["research"].resonance,
        "Analyze Patterns": 0.9 * allocated_subnets["math"].resonance,
        "Optimize Allocations": 0.7 * allocated_subnets["coding"].resonance,
        "Verify Fix": 0.9,
        "Log Resonance": 0.5
    }
    
    # The solver will respect budget (e.g. 3 nodes) and Dharma
    selected_actions = solver.solve(nodes, edges, scores, budget=3)
    print(f"    Optimal Action Set: {selected_actions}")
    
    # 3. Execution & Reward (Proof of Resonance)
    print("\n[3] Finalizing Solution: Distributing Resonance Rewards...")
    # Simulate success
    mock_solution_id = "sol_12345"
    utility_score = 0.95
    
    for cap, subnet in allocated_subnets.items():
        # Each contributing subnet gets a slice of resonance
        await manager.process_solution_success(subnet.id, mock_solution_id, utility_score)
    
    # 4. Ledger Verification
    print("\n[4] Resonance Ledger: Current Balances")
    balances = ledger.get_all_balances()
    for sid, bal in balances.items():
        if bal > 1.0: # Only show rewarded ones
            print(f"    - {sid}: {bal:.2f} TAO (Resonance)")

    print("\n✨ Science Fair Complete. The Scaffolding is Active.")

if __name__ == "__main__":
    asyncio.run(run_science_fair())
