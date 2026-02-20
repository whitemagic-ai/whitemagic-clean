#!/usr/bin/env python3
"""
MASTER SCOUT DEPLOYMENT — All Non-PSR Campaigns
Deploys scout waves across all active campaigns to assess completion status.
"""
import json
import sys
import os
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.tools.unified_api import call_tool

def scout_all_campaigns():
    """Deploy scouts to all non-PSR campaigns."""
    print("🎖️ MASTER SCOUT DEPLOYMENT — Non-PSR Campaign Assessment")
    print("=" * 80)
    
    campaigns_dir = "/home/lucas/Desktop/whitemagicdev/campaigns"
    
    # Find all non-PSR, non-completed campaigns
    active_campaigns = []
    for f in os.listdir(campaigns_dir):
        if f.endswith('.md') and not f.startswith('PSR') and f != 'README.md':
            # Skip if in completedcampaigns
            completed_path = os.path.join(campaigns_dir, 'completedcampaigns', f)
            if not os.path.exists(completed_path):
                active_campaigns.append(f)
    
    print(f"\n📋 Active Non-PSR Campaigns Found: {len(active_campaigns)}")
    for c in active_campaigns:
        print(f"  • {c}")
    
    results = {
        "total_campaigns": len(active_campaigns),
        "scouted": [],
        "findings": {},
        "ready_for_clones": [],
        "needs_direct_action": []
    }
    
    # Scout each campaign
    for campaign_file in active_campaigns:
        campaign_name = campaign_file.replace('.md', '')
        print(f"\n🔍 Scouting: {campaign_name}")
        print("-" * 60)
        
        # Read campaign file to check current VCs
        campaign_path = os.path.join(campaigns_dir, campaign_file)
        try:
            with open(campaign_path) as f:
                content = f.read()
                
            # Count victory conditions
            total_vcs = content.count('- [') + content.count('- [x]') + content.count('- [ ]')
            completed_vcs = content.count('- [x]')
            
            progress = (completed_vcs / total_vcs * 100) if total_vcs > 0 else 0
            
            print(f"  VCs: {completed_vcs}/{total_vcs} ({progress:.1f}%)")
            
            campaign_result = {
                "name": campaign_name,
                "total_vcs": total_vcs,
                "completed_vcs": completed_vcs,
                "progress": progress,
                "status": "COMPLETE" if progress >= 100 else "NEAR_COMPLETE" if progress >= 80 else "IN_PROGRESS" if progress >= 50 else "NEEDS_WORK"
            }
            
            results["scouted"].append(campaign_result)
            
            # Categorize for next actions
            if progress >= 100:
                print(f"  ✅ COMPLETE — Move to completed folder")
            elif progress >= 80:
                print(f"  🟡 NEAR-COMPLETE — Shadow clones can likely finish")
                results["ready_for_clones"].append(campaign_name)
            elif progress >= 50:
                print(f"  🟠 IN-PROGRESS — Clones + some direct action needed")
                results["ready_for_clones"].append(campaign_name)
            else:
                print(f"  🔴 NEEDS_WORK — Significant direct implementation required")
                results["needs_direct_action"].append(campaign_name)
                
        except Exception as e:
            print(f"  ⚠️ Error reading campaign: {e}")
            results["findings"][campaign_name] = f"Error: {str(e)}"
    
    # Summary
    print("\n" + "=" * 80)
    print("📊 SCOUT DEPLOYMENT SUMMARY")
    print("=" * 80)
    
    complete = sum(1 for c in results["scouted"] if c["progress"] >= 100)
    near_complete = sum(1 for c in results["scouted"] if 80 <= c["progress"] < 100)
    in_progress = sum(1 for c in results["scouted"] if 50 <= c["progress"] < 80)
    needs_work = sum(1 for c in results["scouted"] if c["progress"] < 50)
    
    print(f"\nBy Status:")
    print(f"  ✅ Complete: {complete}")
    print(f"  🟡 Near-Complete (80-99%): {near_complete}")
    print(f"  🟠 In-Progress (50-79%): {in_progress}")
    print(f"  🔴 Needs Work (<50%): {needs_work}")
    
    print(f"\n🎯 Recommended Actions:")
    print(f"  • Shadow Clone Deployment: {len(results['ready_for_clones'])} campaigns")
    for c in results["ready_for_clones"]:
        print(f"    - {c}")
    print(f"  • Direct Implementation: {len(results['needs_direct_action'])} campaigns")
    for c in results["needs_direct_action"]:
        print(f"    - {c}")
    
    return results

if __name__ == "__main__":
    result = scout_all_campaigns()
    print("\n✅ Master scout deployment complete")
    print(json.dumps(result, indent=2))
