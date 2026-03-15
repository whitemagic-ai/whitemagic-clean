#!/usr/bin/env python3
"""
Continuous Grand Integration Sprint V2 (Live Mutations)
=========================================================
Runs until midnight. Incorporates live Geneseed AST synthesis and Ralph hot path transmutations.
"""

import sys
import time
import subprocess
from datetime import datetime
from pathlib import Path

def log(msg):
    print(f"[{datetime.now().strftime('%H:%M:%S')}] {msg}")

def is_midnight():
    now = datetime.now()
    return now.hour == 0 and now.minute == 0

def run_cycle(cycle_num):
    log("="*60)
    log(f"GRAND INTEGRATION SPRINT V2: CYCLE {cycle_num}")
    log("="*60)
    
    log("PHASE 1: LIVE GENESEED TEST MUTATION (AST -> Pytest)")
    subprocess.run(["python3", "scripts/evolve_test_coverage_live.py"], capture_output=False)
    
    log("PHASE 2: RALPH ENGINE - LIVE HOT PATH TRANSMUTATION (Python -> Mojo/Rust)")
    subprocess.run(["python3", "scripts/auto_transmute_hotpaths.py"], capture_output=False)
    
    log("PHASE 3: RALPH EVOLUTION METRICS UPDATE")
    import json
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
    from whitemagic.core.evolution.continuous_evolution import ContinuousEvolutionEngine, SelfDirectedEvolution
    
    try:
        engine = ContinuousEvolutionEngine()
        self_directed = SelfDirectedEvolution()
        needs = self_directed.identify_needs()
        plan = self_directed.generate_action_plan()
        log(f"Ralph Global Objective: {plan[0]['objective']}")
        res = engine.run_single_cycle()
        log(f"Ralph System Stats Update: Success Rate: {res['learning']['success_rate']:.1%} | Avg Gain: {res['learning']['avg_performance_gain']:.1f}%")
    except Exception as e:
        log(f"Ralph Engine Error: {e}")
        
    log("PHASE 4: GRAND ARMY DEPLOYMENT (Alpha, Beta, Gamma)")
    res = subprocess.run(["python3", "scripts/deploy_grand_army.py", "--all"], capture_output=True, text=True)
    if res.returncode != 0:
        log("Army deployment reported errors (see logs).")
    else:
        log("Army deployment completed successfully.")
        
    log(f"CYCLE {cycle_num} COMPLETE.\n")

def main():
    log("INITIALIZING LIVE CONTINUOUS INTEGRATION SPRINT (V2) UNTIL MIDNIGHT")
    cycle = 1
    
    while not is_midnight() and cycle <= 3: # Keep the cycle count low for demo purposes during this specific execution
        run_cycle(cycle)
        
        log("Running codebase census telemetry...")
        subprocess.run(["python3", "scripts/codebase_census.py"], capture_output=True)
        
        log("Resting systems for 5 seconds to cool down APIs/DB...")
        time.sleep(5)
        cycle += 1

    log("Continuous loop terminated (Midnight reached or max demo cycles completed).")

if __name__ == "__main__":
    main()
