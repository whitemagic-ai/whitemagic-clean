#!/usr/bin/env python3
"""
Live Recursive Evolution Test
==============================

Tests the recursive loop with real-time event accumulation and pattern discovery.
"""

import sys
import time
from pathlib import Path
from datetime import datetime

sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.evolution.continuous_evolution import ContinuousEvolutionEngine, SelfDirectedEvolution

def main():
    print("="*80)
    print("LIVE RECURSIVE EVOLUTION TEST")
    print("="*80)
    print(f"Started: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
    
    engine = ContinuousEvolutionEngine()
    self_directed = SelfDirectedEvolution()

    print("Identifying system needs...")
    needs = self_directed.identify_needs()
    print(needs)
    
    print("Generating action plan...")
    plan = self_directed.generate_action_plan()
    print(plan)
    
    print("\nRunning single evolution cycle...")
    res = engine.run_single_cycle()
    print(res)

if __name__ == "__main__":
    main()
