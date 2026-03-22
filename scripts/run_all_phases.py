#!/usr/bin/env python3
"""
Execute Phases 1-4: Verification, In-Progress Push, Strategic Targets, Continuous Iteration
"""

import json
import subprocess
import sys
from datetime import datetime
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent


def run_phase(phase_num: int, description: str, command: list[str]) -> dict:
    """Run a deployment phase and capture results."""
    print("\n" + "="*80)
    print(f"  PHASE {phase_num}: {description.upper()}")
    print("="*80)
    print()

    start_time = datetime.now()

    try:
        result = subprocess.run(
            command,
            cwd=PROJECT_ROOT,
            capture_output=True,
            text=True,
            timeout=600  # 10 minute timeout per phase
        )

        duration = (datetime.now() - start_time).total_seconds()

        print(result.stdout)
        if result.stderr:
            print("STDERR:", result.stderr)

        return {
            "phase": phase_num,
            "description": description,
            "exit_code": result.returncode,
            "duration_seconds": duration,
            "status": "success" if result.returncode == 0 else "failed"
        }
    except subprocess.TimeoutExpired:
        return {
            "phase": phase_num,
            "description": description,
            "status": "timeout",
            "duration_seconds": 600
        }
    except Exception as e:
        return {
            "phase": phase_num,
            "description": description,
            "status": "error",
            "error": str(e)
        }


def main():
    print("="*80)
    print("  MULTI-PHASE ARMY DEPLOYMENT")
    print("="*80)
    print(f"  Start Time: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    print("="*80)

    phases = [
        {
            "num": 1,
            "desc": "Verification - V001 & V006",
            "cmd": ["scripts/wm", "scripts/deploy_grand_army.py", "--army", "gamma"],
            "note": "Deploy verification scouts for S-grade campaigns"
        },
        {
            "num": 2,
            "desc": "In-Progress Push - V002, V004, V003",
            "cmd": ["scripts/wm", "scripts/deploy_grand_army.py", "--army", "beta"],
            "note": "Push in-progress campaigns toward completion"
        },
        {
            "num": 3,
            "desc": "Strategic Targets - IL001-IL005, F001-F002",
            "cmd": ["scripts/wm", "scripts/deploy_grand_army.py", "--army", "alpha"],
            "note": "Deploy for high-priority infrastructure campaigns"
        }
    ]

    results = []

    for phase in phases:
        print(f"\n{'='*80}")
        print(f"  PHASE {phase['num']}: {phase['desc']}")
        print(f"  Note: {phase['note']}")
        print(f"{'='*80}")

        result = run_phase(phase["num"], phase["desc"], phase["cmd"])
        results.append(result)

        if result["status"] != "success":
            print(f"\n⚠ Phase {phase['num']} {result['status']}")
            if result.get("error"):
                print(f"  Error: {result['error']}")

    # Phase 4: Continuous iteration setup
    print("\n" + "="*80)
    print("  PHASE 4: CONTINUOUS ITERATION SETUP")
    print("="*80)
    print()
    print("Setting up continuous iteration cycle for remaining campaigns...")

    # Run audit to get current state
    audit_result = subprocess.run(
        [sys.executable, "scripts/audit_campaigns.py"],
        cwd=PROJECT_ROOT,
        capture_output=True,
        text=True
    )

    print(audit_result.stdout)

    # Summary
    print("\n" + "="*80)
    print("  MULTI-PHASE DEPLOYMENT SUMMARY")
    print("="*80)
    print()

    total_duration = sum(r.get("duration_seconds", 0) for r in results)
    success_count = sum(1 for r in results if r.get("status") == "success")

    print(f"Total Duration: {total_duration:.1f}s")
    print(f"Phases Completed: {success_count}/{len(results)}")
    print()

    for result in results:
        status_icon = "✓" if result["status"] == "success" else "✗"
        print(f"  {status_icon} Phase {result['phase']}: {result['description']:40s} — {result['status']}")

    # Save results
    output_path = PROJECT_ROOT / "reports" / "multi_phase_deployment.json"
    output_path.write_text(json.dumps({
        "timestamp": datetime.now().isoformat(),
        "phases": results,
        "total_duration_seconds": total_duration,
        "success_count": success_count
    }, indent=2))

    print(f"\nResults saved to: {output_path}")

    # Next steps
    print("\n" + "="*80)
    print("  PHASE 4: NEXT ITERATION")
    print("="*80)
    print()
    print("Recommended actions:")
    print("  1. Review campaign audit results")
    print("  2. Identify campaigns that moved from F to higher grades")
    print("  3. Deploy armies for next batch of high-priority campaigns")
    print("  4. Scout codebase for new optimization opportunities")
    print()
    print("To continue iteration:")
    print("  python3 scripts/run_all_phases.py")


if __name__ == "__main__":
    main()
