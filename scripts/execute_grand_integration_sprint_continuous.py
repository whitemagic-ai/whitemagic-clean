#!/usr/bin/env python3
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
    log(f"GRAND INTEGRATION SPRINT: CYCLE {cycle_num}")
    log("="*60)
    
    log("PHASE 1: GENESEED MUTATION GENERATION")
    subprocess.run(["python3", "scripts/evolve_test_coverage.py"], capture_output=True)
    
    log("PHASE 2: RALPH AUTONOMOUS LOOP")
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
    from whitemagic.core.evolution.continuous_evolution import ContinuousEvolutionEngine, SelfDirectedEvolution
    
    try:
        engine = ContinuousEvolutionEngine()
        self_directed = SelfDirectedEvolution()
        self_directed.identify_needs()
        plan = self_directed.generate_action_plan()
        log(f"Ralph Objective: {plan[0]['objective']}")
        res = engine.run_single_cycle()
        log(f"Ralph Stats: Success: {res['learning']['success_rate']:.1%} | Avg Gain: {res['learning']['avg_performance_gain']:.1f}%")
    except Exception as e:
        log(f"Ralph Engine Error: {e}")
        
    log("PHASE 3: GRAND ARMY DEPLOYMENT")
    # Redirect stdout to devnull to avoid massive log spam, just capture errors if any
    res = subprocess.run(["python3", "scripts/deploy_grand_army.py", "--all"], capture_output=True, text=True)
    if res.returncode != 0:
        log("Army deployment reported errors.")
    else:
        log("Army deployment completed successfully.")
        
    log(f"CYCLE {cycle_num} COMPLETE.\n")

def main():
    log("INITIALIZING CONTINUOUS INTEGRATION SPRINT UNTIL MIDNIGHT")
    cycle = 1
    
    # Run the continuous loop
    # We will enforce a hard cap of say 10 cycles just so the LLM session doesn't hang forever,
    # but theoretically this runs until is_midnight()
    
    while not is_midnight() and cycle <= 10:
        run_cycle(cycle)
        
        # After each cycle, run the census to track metrics
        log("Running codebase census telemetry...")
        subprocess.run(["python3", "scripts/codebase_census.py"], capture_output=True)
        
        log("Resting systems for 10 seconds to cool down APIs/DB...")
        time.sleep(10)
        cycle += 1

    log("Continuous loop terminated (Midnight reached or max demo cycles completed).")
    subprocess.run(["python3", "scripts/codebase_census.py"])

if __name__ == "__main__":
    main()
