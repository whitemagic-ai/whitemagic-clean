#!/usr/bin/env python3
"""
WM Dashboard — The Ram's Horn
Visualizes Aries Will and Reflexive Resonance.
"""

import sys
import sqlite3
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.zodiac.zodiac_cores import AriesCore
from whitemagic.core.intelligence.confidence import ConfidenceLearner

def main():
    print("\n  WHITmagic DASHBOARD — The Ram's Horn")
    print("  " + "═" * 40)
    
    # 1. Aries Willpower
    aries = AriesCore(root_dir=ROOT)
    stats = aries.get_willpower_stats()
    
    print("\n  [♈] ARIES WILLPOWER MONITOR")
    print(f"      Willpower Index: {stats['willpower']*100:>6.1f} %")
    print(f"      Completion Vel:  {stats['velocity']*100:>6.1f} %")
    print(f"      Tasks Cleared:   {stats['tasks_done']:>3} / {stats['tasks_total']}")
    print(f"      Active Momentum: {stats['momentum']:>3} tasks in progress")
    
    # 2. Reflexive Resonance (Confidence)
    db_path = ROOT / "memory" / "whitemagic.db"
    learner = ConfidenceLearner(db_path)
    
    print("\n  [🎻] REFLEXIVE CONFIDENCE MATRIX")
    conn = sqlite3.connect(str(db_path))
    rows = conn.execute("SELECT cluster_key, success_count, failure_count FROM cluster_confidence ORDER BY success_count DESC").fetchall()
    conn.close()
    
    if not rows:
        print("      (No reflexive evidence captured yet)")
    else:
        print(f"      {'Cluster':<15} | {'Wins':<5} | {'Loss':<5} | {'Multiplier':<10}")
        print("      " + "-" * 45)
        for ck, s, f in rows:
            score = learner.get_score(ck)
            print(f"      {ck:<15} | {s:<5} | {f:<5} | {score:>10.2f}x")

    print("\n  [🚀] GANYING LIFT (EST)")
    print("      Latency Target:  < 20s (188k memories)")
    print("      Current Status:  Reflexive Loop Closed")
    
    print("\n  " + "═" * 40 + "\n")

if __name__ == "__main__":
    main()
