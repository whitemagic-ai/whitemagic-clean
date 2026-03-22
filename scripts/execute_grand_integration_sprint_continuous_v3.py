#!/usr/bin/env python3
"""
Continuous Grand Integration Sprint V3 (Infinite Loop until Midnight)
====================================================================
Runs the actual Geneseed live mutation loop and Ralph Auto-Transmutation
engines continuously until the system clock hits midnight.
"""

import subprocess
import sys
import time
from datetime import datetime
from pathlib import Path


def log(msg):
    print(f"[{datetime.now().strftime('%H:%M:%S')}] {msg}")

def is_midnight():
    now = datetime.now()
    return now.hour == 0 and now.minute == 0

def run_cycle(cycle_num):
    log("="*60)
    log(f"GRAND INTEGRATION SPRINT V3: CYCLE {cycle_num}")
    log("="*60)

    log("PHASE 1: LIVE GENESEED TEST MUTATION (AST -> Pytest)")
    subprocess.run(["python3", "scripts/evolve_test_coverage_live.py"], capture_output=True)

    log("PHASE 2: RALPH ENGINE - LIVE HOT PATH TRANSMUTATION")
    subprocess.run(["python3", "scripts/auto_transmute_hotpaths.py"], capture_output=True)

    log("PHASE 3: RALPH EVOLUTION METRICS UPDATE")
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
    from whitemagic.core.evolution.continuous_evolution import (
        ContinuousEvolutionEngine,
        SelfDirectedEvolution,
    )

    try:
        engine = ContinuousEvolutionEngine()
        self_directed = SelfDirectedEvolution()
        plan = self_directed.generate_action_plan()
        log(f"Ralph Global Objective: {plan[0]['objective']}")
        res = engine.run_single_cycle()
        log(f"Ralph System Stats Update: Success Rate: {res['learning']['success_rate']:.1%} | Avg Gain: {res['learning']['avg_performance_gain']:.1f}%")
    except Exception as e:
        log(f"Ralph Engine Error: {e}")

    log("PHASE 4: GRAND ARMY DEPLOYMENT (Alpha, Beta, Gamma)")
    res = subprocess.run(["python3", "scripts/deploy_grand_army.py", "--all"], capture_output=True, text=True)
    if res.returncode != 0:
        log("Army deployment reported errors.")
    else:
        log("Army deployment completed successfully.")

    log(f"CYCLE {cycle_num} COMPLETE.\n")

def main():
    log("INITIALIZING INFINITE LIVE INTEGRATION SPRINT (V3) UNTIL MIDNIGHT")
    cycle = 1

    while not is_midnight():
        run_cycle(cycle)

        # Every 5 cycles, run the full census to avoid bottlenecking every single run
        if cycle % 5 == 0:
            log("Running codebase census telemetry...")
            subprocess.run(["python3", "scripts/codebase_census.py"], capture_output=True)
            log("Resting systems for 30 seconds to cool down APIs/DB...")
            time.sleep(30)
        else:
            log("Resting systems for 5 seconds...")
            time.sleep(5)

        cycle += 1

    log("Continuous loop terminated (Midnight reached).")

if __name__ == "__main__":
    main()
