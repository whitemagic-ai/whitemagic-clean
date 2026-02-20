#!/usr/bin/env python3
"""
Phase 1: Verification Deployment
Deploy verification scouts for S-grade campaigns (V001, V006)
"""

import json
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

from whitemagic.agents.campaign_metrics import CampaignTracker
from whitemagic.agents.shadow_clones import deploy_clones


def verify_campaign(campaign_id: str, tracker: CampaignTracker) -> dict:
    """Deploy verification scouts for a completed campaign."""
    print(f"\n{'='*80}")
    print(f"  VERIFICATION: {campaign_id}")
    print(f"{'='*80}\n")
    
    campaign_path = PROJECT_ROOT / "campaigns" / f"{campaign_id}.md"
    if not campaign_path.exists():
        print(f"  ✗ Campaign file not found: {campaign_path}")
        return {"status": "error", "reason": "file_not_found"}
    
    content = campaign_path.read_text()
    
    with tracker.track_objective("verification", campaign_id,
                                 lieutenant="verification_scout", phases_total=3) as obj:
        
        # Phase 1: Parse VCs
        print(f"  [1/3] Parsing Victory Conditions...")
        import re
        vc_section = re.search(r'##\s+Victory Conditions.*?(?=##|\Z)', content, re.DOTALL | re.IGNORECASE)
        
        if not vc_section:
            obj.record_finding("No Victory Conditions section found", severity="high")
            return {"status": "error", "reason": "no_vcs"}
        
        vc_pattern = r'[-*]\s+\[([xX])\]\s+(.+?)(?=\n[-*]|\n\n|\Z)'
        vcs = re.findall(vc_pattern, vc_section.group(0), re.DOTALL)
        
        print(f"         Found {len(vcs)} completed VCs")
        obj.phases_completed = 1
        
        # Phase 2: Deploy verification clones
        print(f"  [2/3] Deploying 10K verification clones...")
        
        verification_results = []
        total_clones = 0
        
        for idx, (_, vc_desc) in enumerate(vcs[:5]):  # Verify first 5 VCs
            vc_clean = re.sub(r'\s+', ' ', vc_desc.strip())[:200]
            
            result = deploy_clones(
                f"Verify this Victory Condition is genuinely complete and not just marked: {vc_clean}",
                num_clones=2000,
                strategies=["analytical", "direct"]
            )
            
            total_clones += 2000
            verification_results.append({
                "vc_index": idx,
                "vc_description": vc_clean[:100],
                "confidence": result.get("avg_confidence", 0.0),
                "winner": result.get("winner", "unknown")[:100]
            })
            
            obj.record_clones(2000, result.get("elapsed_ms", 0))
        
        obj.phases_completed = 2
        
        # Phase 3: Consensus
        print(f"  [3/3] Generating verification consensus...")
        
        avg_confidence = sum(v["confidence"] for v in verification_results) / len(verification_results)
        verified_count = sum(1 for v in verification_results if v["confidence"] >= 0.80)
        
        obj.record_finding(
            f"Verification: {verified_count}/{len(verification_results)} VCs confirmed at ≥80% confidence",
            severity="info" if verified_count == len(verification_results) else "medium",
            category="verification",
            details={"avg_confidence": avg_confidence, "results": verification_results}
        )
        
        obj.phases_completed = 3
        
        status = "verified" if verified_count == len(verification_results) else "needs_review"
        grade = "S" if verified_count == len(verification_results) else "A"
        
        print(f"         Status: {status} (Grade: {grade}, avg confidence: {avg_confidence:.3f})")
        
        return {
            "status": status,
            "grade": grade,
            "verified_count": verified_count,
            "total_vcs": len(vcs),
            "sampled_vcs": len(verification_results),
            "avg_confidence": avg_confidence,
            "total_clones": total_clones
        }


def main():
    print("="*80)
    print("  PHASE 1: VERIFICATION DEPLOYMENT")
    print("="*80)
    print()
    
    tracker = CampaignTracker()
    tracker.start_army("verification")
    
    campaigns = ["V001_great_codebase_census", "V006_rust_hot_path_completion"]
    results = {}
    
    for campaign_id in campaigns:
        result = verify_campaign(campaign_id, tracker)
        results[campaign_id] = result
    
    tracker.end_army("verification")
    
    # Summary
    print("\n" + "="*80)
    print("  PHASE 1 SUMMARY")
    print("="*80)
    print()
    
    summary = tracker.summary()
    print(f"Total Clones Deployed: {summary.get('total_clones', 0):,}")
    print(f"Total Findings: {summary.get('total_findings', 0)}")
    print()
    
    for campaign_id, result in results.items():
        status = result.get("status", "unknown")
        grade = result.get("grade", "?")
        confidence = result.get("avg_confidence", 0.0)
        print(f"  {campaign_id:40s} [{grade}] — {status} ({confidence:.3f})")
    
    # Save results
    output_path = PROJECT_ROOT / "reports" / "phase1_verification_results.json"
    output_path.write_text(json.dumps({
        "campaigns": results,
        "tracker_summary": summary
    }, indent=2))
    
    print(f"\nResults saved to: {output_path}")
    
    return results


if __name__ == "__main__":
    main()
