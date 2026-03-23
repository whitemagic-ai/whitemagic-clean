#!/usr/bin/env python3
"""
Targeted Army Deployment System
Deploys armies to complete specific campaign Victory Conditions based on audit results
"""

import json
import sqlite3
import subprocess
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from whitemagic.agents.campaign_metrics import CampaignMetricsTracker  # noqa: E402

# Import audit functionality


def load_audit_results() -> dict:
    """Load the most recent campaign audit results."""
    audit_path = PROJECT_ROOT / "reports" / "campaign_audit.json"
    if not audit_path.exists():
        print("No audit results found. Running audit first...")
        subprocess.run([sys.executable, str(PROJECT_ROOT / "scripts" / "audit_campaigns.py")], check=True)

    return json.loads(audit_path.read_text())


def get_db():
    """Get database connection."""
    db_path = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
    return sqlite3.connect(db_path)


def verify_s_grade_campaign(campaign_id: str, tracker: CampaignMetricsTracker) -> dict:
    """Deploy verification scouts for S-grade campaigns."""
    print(f"\n{'='*80}")
    print(f"  VERIFICATION: {campaign_id}")
    print(f"{'='*80}\n")

    with tracker.track_objective("verification", campaign_id,
                                 lieutenant="verification_scout", phases_total=3) as obj:

        # Phase 1: Load campaign and check VCs
        print("  [1/3] Loading campaign Victory Conditions...")
        campaign_path = PROJECT_ROOT / "campaigns" / f"{campaign_id}.md"
        content = campaign_path.read_text()

        # Parse VCs
        import re
        vc_section = re.search(r'##\s+Victory Conditions.*?(?=##|\Z)', content, re.DOTALL | re.IGNORECASE)
        if not vc_section:
            obj.record_finding("No Victory Conditions section found", severity="high")
            return {"status": "failed", "reason": "no_vcs"}

        vc_pattern = r'[-*]\s+\[([xX])\]\s+(.+?)(?=\n[-*]|\n\n|\Z)'
        vcs = re.findall(vc_pattern, vc_section.group(0), re.DOTALL)

        print(f"         Found {len(vcs)} completed Victory Conditions")
        obj.phases_completed = 1

        # Phase 2: Deploy verification clones
        print("  [2/3] Deploying 10K verification clones...")

        verification_results = []
        for idx, (_, vc_desc) in enumerate(vcs):
            vc_clean = re.sub(r'\s+', ' ', vc_desc.strip())[:200]

            # Deploy small clone squad to verify this VC
            from whitemagic.agents.shadow_clones import deploy_clones
            result = deploy_clones(
                f"Verify this Victory Condition is truly complete: {vc_clean}",
                num_clones=1000,
                strategies=["analytical", "direct"]
            )

            verification_results.append({
                "vc_index": idx,
                "vc_description": vc_clean,
                "confidence": result.get("avg_confidence", 0.0),
                "winner": result.get("winner", "unknown")
            })

            obj.record_clones(1000, result.get("elapsed_ms", 0))

        obj.phases_completed = 2

        # Phase 3: Consensus
        print("  [3/3] Generating verification consensus...")

        avg_confidence = sum(v["confidence"] for v in verification_results) / len(verification_results)
        verified_count = sum(1 for v in verification_results if v["confidence"] >= 0.85)

        obj.record_finding(
            f"Verification: {verified_count}/{len(vcs)} VCs confirmed at ≥85% confidence",
            severity="info" if verified_count == len(vcs) else "medium",
            category="verification",
            details={"avg_confidence": avg_confidence, "results": verification_results}
        )

        obj.phases_completed = 3

        status = "verified" if verified_count == len(vcs) else "needs_review"
        print(f"         Status: {status} (avg confidence: {avg_confidence:.3f})")

        return {
            "status": status,
            "verified_count": verified_count,
            "total_vcs": len(vcs),
            "avg_confidence": avg_confidence,
            "results": verification_results
        }


def complete_campaign_vc(campaign_id: str, vc_description: str,
                         tracker: CampaignMetricsTracker, conn: sqlite3.Connection) -> dict:
    """Deploy armies to complete a specific Victory Condition."""
    print(f"\n  Targeting VC: {vc_description[:80]}...")

    with tracker.track_objective("completion", f"{campaign_id}_vc",
                                 lieutenant="completion_squad", phases_total=2) as obj:

        # Phase 1: Analyze what's needed
        print("    [1/2] Analyzing requirements...")

        from whitemagic.agents.shadow_clones import deploy_clones
        analysis = deploy_clones(
            f"Analyze what work is needed to complete this Victory Condition: {vc_description}",
            num_clones=5000,
            strategies=["analytical", "synthesis"]
        )

        obj.record_clones(5000, analysis.get("elapsed_ms", 0))
        obj.phases_completed = 1

        # Phase 2: Execute
        print("    [2/2] Deploying execution clones...")

        execution = deploy_clones(
            f"Execute the work needed to complete: {vc_description}",
            num_clones=20000,
            strategies=["direct", "synthesis", "analytical"]
        )

        obj.record_clones(20000, execution.get("elapsed_ms", 0))
        obj.phases_completed = 2

        obj.record_finding(
            "Attempted completion of VC",
            severity="info",
            category="vc_completion",
            details={
                "analysis": analysis.get("winner"),
                "execution": execution.get("winner"),
                "confidence": execution.get("avg_confidence", 0.0)
            }
        )

        return {
            "status": "attempted",
            "confidence": execution.get("avg_confidence", 0.0),
            "analysis": analysis.get("winner"),
            "execution": execution.get("winner")
        }


def deploy_for_campaign(campaign_data: dict, tracker: CampaignMetricsTracker,
                       conn: sqlite3.Connection, max_vcs: int = 3) -> dict:
    """Deploy armies to work on a specific campaign."""
    campaign_id = campaign_data["campaign_id"]
    grade = campaign_data.get("grade", "F")

    print(f"\n{'='*80}")
    print(f"  CAMPAIGN: {campaign_id} (Grade: {grade})")
    print(f"{'='*80}")

    if grade == "S":
        # Verification run
        return verify_s_grade_campaign(campaign_id, tracker)

    # Get incomplete VCs
    incomplete_vcs = [vc for vc in campaign_data.get("victory_conditions", [])
                      if not vc["completed"]]

    if not incomplete_vcs:
        print(f"  No incomplete VCs found for {campaign_id}")
        return {"status": "no_work_needed"}

    print(f"  Found {len(incomplete_vcs)} incomplete VCs")
    print(f"  Targeting first {min(max_vcs, len(incomplete_vcs))} VCs...")

    results = []
    for vc in incomplete_vcs[:max_vcs]:
        result = complete_campaign_vc(campaign_id, vc["description"], tracker, conn)
        results.append(result)

    return {
        "status": "work_attempted",
        "vcs_targeted": len(results),
        "results": results
    }


def run_targeted_deployment(priority: str = "high", max_campaigns: int = 5):
    """Run targeted deployment based on priority."""
    print("="*80)
    print("  TARGETED ARMY DEPLOYMENT")
    print("="*80)
    print()

    # Load audit results
    audit = load_audit_results()
    targets = audit["deployment_targets"]

    tracker = CampaignMetricsTracker()
    conn = get_db()

    # Select campaigns based on priority
    if priority == "verification":
        campaigns = targets["verification_needed"][:max_campaigns]
        print(f"Deploying verification scouts for {len(campaigns)} S-grade campaigns...")
    elif priority == "high":
        campaigns = targets["high_priority"][:max_campaigns]
        print(f"Deploying completion squads for {len(campaigns)} high-priority campaigns...")
    elif priority == "medium":
        campaigns = targets["medium_priority"][:max_campaigns]
        print(f"Deploying completion squads for {len(campaigns)} medium-priority campaigns...")
    elif priority == "low":
        campaigns = targets["low_priority"][:max_campaigns]
        print(f"Deploying completion squads for {len(campaigns)} low-priority campaigns...")
    else:
        print(f"Unknown priority: {priority}")
        return

    if not campaigns:
        print(f"No campaigns found for priority: {priority}")
        return

    # Deploy for each campaign
    deployment_results = []
    for campaign_data in campaigns:
        result = deploy_for_campaign(campaign_data, tracker, conn, max_vcs=3)
        deployment_results.append({
            "campaign_id": campaign_data["campaign_id"],
            "grade": campaign_data.get("grade"),
            "result": result
        })

    conn.close()

    # Summary
    print("\n" + "="*80)
    print("  DEPLOYMENT SUMMARY")
    print("="*80)
    print()

    summary = tracker.summary()
    print(f"Total Clones Deployed: {summary.get('total_clones', 0):,}")
    print(f"Total Findings: {summary.get('total_findings', 0)}")
    print()

    for dr in deployment_results:
        status = dr["result"].get("status", "unknown")
        print(f"  {dr['campaign_id']:40s} [{dr['grade']}] — {status}")

    # Save results
    output_path = PROJECT_ROOT / "reports" / "targeted_deployment_results.json"
    output_path.write_text(json.dumps({
        "priority": priority,
        "campaigns_targeted": len(campaigns),
        "deployment_results": deployment_results,
        "tracker_summary": summary
    }, indent=2))

    print(f"\nResults saved to: {output_path}")


if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser(description="Deploy armies to complete campaign VCs")
    parser.add_argument("--priority", choices=["verification", "high", "medium", "low"],
                       default="high", help="Priority level for deployment")
    parser.add_argument("--max-campaigns", type=int, default=5,
                       help="Maximum number of campaigns to target")

    args = parser.parse_args()

    run_targeted_deployment(priority=args.priority, max_campaigns=args.max_campaigns)
