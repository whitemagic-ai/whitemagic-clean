#!/usr/bin/env python3
"""
Ralph: The Autonomous Self-Improvement Engine (v2.1)
=================================================
Runs the continuous evolution cycle, generates action plans,
and attempts to execute them recursively using the WhiteMagic Army Deployments.
"""

import sys
import time
import subprocess
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.evolution.continuous_evolution import ContinuousEvolutionEngine, SelfDirectedEvolution

def is_midnight():
    now = datetime.now()
    return now.hour == 0 and now.minute == 0

def run_ralph():
    print("="*80)
    print(f"RALPH AUTONOMOUS ENGINE STARTED - {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    print("="*80)
    
    engine = ContinuousEvolutionEngine()
    self_directed = SelfDirectedEvolution()
    
    cycles = 0
    while not is_midnight():
        print(f"\n[CYCLE {cycles + 1}] {datetime.now().isoformat()}")
        
        # 1. Identify needs & plan
        needs = self_directed.identify_needs()
        plan = self_directed.generate_action_plan()
        print("  Active Objective:", plan[0]['objective'])
        
        # 2. Evolutionary cycle (Mutation / Learning)
        res = engine.run_single_cycle()
        print("  Evolution Stats: Success Rate:", f"{res['learning']['success_rate']:.1%}", 
              "| Avg Gain:", f"{res['learning']['avg_performance_gain']:.1f}%")
        
        # 3. Deploy an appropriate army to execute the objective
        try:
            print("  Deploying Grand Army for systematic review...")
            # We run the grand army script to process the objective, but cap the output
            subprocess.run(["python3", "scripts/deploy_grand_army.py", "--army", "alpha"], capture_output=True, check=False)
            print("  Army deployment complete.")
        except Exception as e:
            print(f"  Army deployment failed: {e}")
            
        print("  Cycle complete. Sleeping for 15 seconds...")
        time.sleep(15)
        cycles += 1
        
        # Allow the loop to run for a while, but break out for demo purposes after 3
        if cycles >= 3:
            print("Max cycles reached for this run. Suspending.")
            break

if __name__ == "__main__":
    run_ralph()
