#!/usr/bin/env python3
import sys
import subprocess
from datetime import datetime

def log(msg):
    print(f"[{datetime.now().strftime('%H:%M:%S')}] {msg}")

def main():
    log("="*60)
    log("GRAND INTEGRATION SPRINT: SINGLE CYCLE EXECUTION")
    log("="*60)
    
    # 1. Run the Geneseed test generator to find coverage holes
    log("PHASE 1: GENESEED AST MAPPING & MUTATION GENERATION")
    subprocess.run(["python3", "scripts/evolve_test_coverage.py"], capture_output=False)
    
    # 2. Run the Ralph Autonomous Loop to identify broader system needs
    log("PHASE 2: RALPH CONTINUOUS EVOLUTION & NEED IDENTIFICATION")
    # Using the existing ralph script but it loops, so let's run a single cycle wrapper
    
    # Let's run a single Ralph cycle manually here
    from pathlib import Path
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
    from whitemagic.core.evolution.continuous_evolution import ContinuousEvolutionEngine, SelfDirectedEvolution
    
    try:
        engine = ContinuousEvolutionEngine()
        self_directed = SelfDirectedEvolution()
        
        needs = self_directed.identify_needs()
        plan = self_directed.generate_action_plan()
        log(f"Ralph Active Objective: {plan[0]['objective']}")
        
        res = engine.run_single_cycle()
        log(f"Ralph Stats: Success Rate: {res['learning']['success_rate']:.1%} | Avg Gain: {res['learning']['avg_performance_gain']:.1f}%")
    except Exception as e:
        log(f"Ralph Engine Error: {e}")
    
    # 3. Deploy the Grand Army to execute the highest priority items from Ralph
    log("PHASE 3: GRAND ARMY DEPLOYMENT (ALPHA, BETA, GAMMA COMPOSITION)")
    subprocess.run(["python3", "scripts/deploy_grand_army.py", "--all"], capture_output=False)
    
    log("SINGLE CYCLE COMPLETE.")
    log("Run 'python3 scripts/benchmark_v181.py' or 'python3 scripts/codebase_census.py' to measure impact.")

if __name__ == "__main__":
    main()
