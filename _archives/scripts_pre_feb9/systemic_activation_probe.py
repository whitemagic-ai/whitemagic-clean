#!/usr/bin/env python3
"""
Systemic Activation Probe — Phase 25.4
=====================================
Orchestrates the activation of multiple legacy engines against the Data Sea.
Fires in sequence:
1. SerendipityEngine (Knowledge Surfacing)
2. KaizenEngine (Quality & Gap Analysis)
3. PredictiveEngine (Trend Extrapolation)
4. Council (Strategic Consensus)
"""

import sys
import time
import asyncio
from pathlib import Path
from datetime import datetime

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

# System Imports
from whitemagic.core.intelligence.synthesis.serendipity_engine import get_serendipity_engine
from whitemagic.core.intelligence.synthesis.kaizen_engine import get_kaizen_engine
from whitemagic.core.intelligence.synthesis.predictive_engine import get_predictive_engine
from whitemagic.core.orchestration.council import Council

# Database Path
DB_PATH = ROOT / "memory" / "whitemagic.db"
REPORT_PATH = ROOT / "reports" / "systemic_activation_insights.md"

async def run_activation():
    # [0] Setup
    print("\n  SYSTEMIC ACTIVATION PROBE INITIATED")
    print("  " + "═" * 45)
    
    # [1] Serendipity Activation
    print("  [1] Activating Serendipity Engine (Knowledge Surfacing)...")
    serendipity = get_serendipity_engine()
    serendipity.db_path = str(DB_PATH)
    surfaced = serendipity.surface(mode="balanced", count=10)
    print(f"      Surfaced {len(surfaced)} dormant memories.")

    # [2] Kaizen Activation
    print("  [2] Activating Kaizen Engine (Quality & Gap Analysis)...")
    kaizen = get_kaizen_engine()
    kaizen.db_path = str(DB_PATH)
    kaizen_report = kaizen.analyze()
    print(f"      Generated {len(kaizen_report.proposals)} improvement proposals.")

    # [3] Predictive Activation
    print("  [3] Activating Predictive Engine (Trend Extrapolation)...")
    predictive = get_predictive_engine()
    predictive.db_path = str(DB_PATH)
    pred_report = predictive.predict()
    print(f"      Generated {len(pred_report.predictions)} future-forward predictions.")

    # [4] Council Deliberation
    print("  [4] Convening the Council (Strategic Consensus)...")
    council = Council()
    top_pred = pred_report.predictions[0].title if pred_report.predictions else "General Self-Improvement"
    granted = council.deliberate(top_pred)
    
    # [5] Synthesis: Generating Insight Report
    print("  [5] Synthesizing Surfaced Insights...")
    
    lines = [
        "# Systemic Activation Insights: 188k Pulse",
        f"*Timestamp: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}*",
        "\n## 1. Serendipity: Surfaced Knowledge",
    ]
    for s in surfaced[:5]:
        lines.append(f"- **{s.title}**: {s.reason} (Gravity: {s.gravity:.2f})")
    
    lines.append("\n## 2. Kaizen: Improvement Proposals")
    for p in kaizen_report.proposals[:5]:
        lines.append(f"- [{p.impact.upper()}] **{p.title}**: {p.description}")
        
    lines.append("\n## 3. Predictive: Future-Forward Trends")
    for pr in pred_report.predictions[:5]:
        lines.append(f"- [{pr.confidence.value.upper()}] **{pr.title}**: {pr.description} ({pr.time_horizon})")
        
    lines.append("\n## 4. Council Verdict")
    lines.append(f"The Council has **{'GRANTED' if granted else 'DENIED'}** the primary initiative: *{top_pred}*.")

    with open(REPORT_PATH, "w") as f:
        f.write("\n".join(lines))
        
    print(f"\n  ACTIVATION COMPLETE. Report: {REPORT_PATH}")
    print(f"  PULSE DURATION: {time.time() - start_time:.2f}s\n")

if __name__ == "__main__":
    start_time = time.time()
    asyncio.run(run_activation())
