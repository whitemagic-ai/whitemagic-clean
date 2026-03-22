#!/usr/bin/env python3
"""Auto-Sync Scheduler — 24h cycle for documentation synchronization.

Cron entry:
0 0 * * * cd /path/to/whitemagicdev && python scripts/auto_sync_scheduler.py

Part of S020 Phase 5: Documentation Auto-Sync.
"""

from __future__ import annotations

import subprocess
import sys
from datetime import datetime
from pathlib import Path


def run_sync_cycle(root_dir: Path | None = None) -> dict:
    """Run full sync cycle: census → sync → drift check.
    
    Returns dict with results.
    """
    root = root_dir or Path(__file__).resolve().parent.parent

    results = {
        "timestamp": datetime.now().isoformat(),
        "steps": [],
    }

    # Step 1: Run census
    try:
        result = subprocess.run(
            [sys.executable, str(root / "scripts" / "codebase_census.py")],
            capture_output=True,
            text=True,
            cwd=str(root),
            timeout=300,
        )
        results["steps"].append({
            "step": "census",
            "status": "ok" if result.returncode == 0 else "error",
            "output": result.stdout[-500:] if result.stdout else "",
        })
    except Exception as e:
        results["steps"].append({"step": "census", "status": "error", "error": str(e)})

    # Step 2: Sync SYSTEM_MAP.md
    try:
        result = subprocess.run(
            [sys.executable, str(root / "scripts" / "living_doc_sync.py")],
            capture_output=True,
            text=True,
            cwd=str(root),
            timeout=60,
        )
        results["steps"].append({
            "step": "sync",
            "status": "ok" if result.returncode == 0 else "error",
            "output": result.stdout[-200:] if result.stdout else "",
        })
    except Exception as e:
        results["steps"].append({"step": "sync", "status": "error", "error": str(e)})

    # Step 3: Drift detection
    try:
        result = subprocess.run(
            [sys.executable, str(root / "scripts" / "drift_detector.py")],
            capture_output=True,
            text=True,
            cwd=str(root),
            timeout=60,
        )
        results["steps"].append({
            "step": "drift_check",
            "status": "ok" if result.returncode == 0 else "error",
            "output": result.stdout[-200:] if result.stdout else "",
        })
    except Exception as e:
        results["steps"].append({"step": "drift_check", "status": "error", "error": str(e)})

    # Summary
    ok_count = sum(1 for s in results["steps"] if s["status"] == "ok")
    results["summary"] = f"{ok_count}/3 steps completed successfully"

    return results


if __name__ == "__main__":
    result = run_sync_cycle()
    print(f"Auto-sync cycle: {result['summary']}")
    for step in result["steps"]:
        status_icon = "✓" if step["status"] == "ok" else "✗"
        print(f"  {status_icon} {step['step']}: {step['status']}")
