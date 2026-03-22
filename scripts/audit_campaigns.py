#!/usr/bin/env python3
"""
Campaign Victory Condition Audit & Grading System
Scans all campaigns, checks VC completion status, assigns grades (S/A/B/C/D/F)
"""

import re
import sqlite3
from pathlib import Path
from typing import Dict, List, Tuple
import json

PROJECT_ROOT = Path(__file__).resolve().parent.parent
CAMPAIGNS_DIR = PROJECT_ROOT / "campaigns"
DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"


def get_grade(completion_pct: float) -> str:
    """Assign letter grade based on completion percentage."""
    if completion_pct >= 100.0:
        return "S"
    elif completion_pct >= 90.0:
        return "A"
    elif completion_pct >= 80.0:
        return "B"
    elif completion_pct >= 70.0:
        return "C"
    elif completion_pct >= 60.0:
        return "D"
    else:
        return "F"


def parse_campaign_file(filepath: Path) -> Dict:
    """Parse a campaign markdown file and extract Victory Conditions."""
    content = filepath.read_text()
    
    # Extract campaign metadata
    campaign_id = filepath.stem
    title_match = re.search(r'^#\s+(.+?)$', content, re.MULTILINE)
    title = title_match.group(1) if title_match else campaign_id
    
    # Find Victory Conditions section
    vc_section = re.search(
        r'##\s+Victory Conditions.*?(?=##|\Z)',
        content,
        re.DOTALL | re.IGNORECASE
    )
    
    if not vc_section:
        return {
            "campaign_id": campaign_id,
            "title": title,
            "victory_conditions": [],
            "total_vcs": 0,
            "completed_vcs": 0,
            "completion_pct": 0.0,
            "grade": "F",
            "status": "no_vcs_defined"
        }
    
    vc_text = vc_section.group(0)
    
    # Parse individual VCs (look for checkbox patterns)
    vc_pattern = r'[-*]\s+\[([ xX])\]\s+(.+?)(?=\n[-*]|\n\n|\Z)'
    vcs = re.findall(vc_pattern, vc_text, re.DOTALL)
    
    victory_conditions = []
    for checkbox, description in vcs:
        is_complete = checkbox.lower() == 'x'
        # Clean up description
        desc_clean = re.sub(r'\s+', ' ', description.strip())
        victory_conditions.append({
            "description": desc_clean,
            "completed": is_complete
        })
    
    total_vcs = len(victory_conditions)
    completed_vcs = sum(1 for vc in victory_conditions if vc["completed"])
    completion_pct = (completed_vcs / total_vcs * 100) if total_vcs > 0 else 0.0
    grade = get_grade(completion_pct)
    
    # Determine status
    if total_vcs == 0:
        status = "no_vcs_defined"
    elif completed_vcs == 0:
        status = "not_started"
    elif completed_vcs == total_vcs:
        status = "complete"
    else:
        status = "in_progress"
    
    return {
        "campaign_id": campaign_id,
        "title": title,
        "victory_conditions": victory_conditions,
        "total_vcs": total_vcs,
        "completed_vcs": completed_vcs,
        "completion_pct": completion_pct,
        "grade": grade,
        "status": status
    }


def get_db_stats() -> Dict:
    """Get current database statistics for context."""
    try:
        conn = sqlite3.connect(DB_PATH)
        cursor = conn.cursor()
        
        # Active memories
        cursor.execute("SELECT COUNT(*) FROM memories WHERE quarantined = 0")
        active_memories = cursor.fetchone()[0]
        
        # Quarantined memories
        cursor.execute("SELECT COUNT(*) FROM memories WHERE quarantined = 1")
        quarantined_memories = cursor.fetchone()[0]
        
        # Associations
        cursor.execute("SELECT COUNT(*) FROM associations")
        total_assocs = cursor.fetchone()[0]
        
        # Typed associations
        cursor.execute("SELECT COUNT(*) FROM associations WHERE relation_type != 'associated_with'")
        typed_assocs = cursor.fetchone()[0]
        
        # Entities
        cursor.execute("SELECT COUNT(DISTINCT entity_name) FROM entities")
        unique_entities = cursor.fetchone()[0]
        
        # Embeddings
        cursor.execute("SELECT COUNT(*) FROM embeddings")
        embeddings = cursor.fetchone()[0]
        
        conn.close()
        
        return {
            "active_memories": active_memories,
            "quarantined_memories": quarantined_memories,
            "total_associations": total_assocs,
            "typed_associations": typed_assocs,
            "untyped_associations": total_assocs - typed_assocs,
            "unique_entities": unique_entities,
            "embeddings": embeddings
        }
    except Exception as e:
        return {"error": str(e)}


def audit_all_campaigns() -> Tuple[List[Dict], Dict]:
    """Audit all campaign files and return results with statistics."""
    campaign_files = sorted(CAMPAIGNS_DIR.glob("*.md"))
    campaign_files = [f for f in campaign_files if f.name != "README.md"]
    
    results = []
    for filepath in campaign_files:
        try:
            result = parse_campaign_file(filepath)
            results.append(result)
        except Exception as e:
            results.append({
                "campaign_id": filepath.stem,
                "title": filepath.stem,
                "error": str(e),
                "status": "parse_error"
            })
    
    # Calculate aggregate statistics
    total_campaigns = len(results)
    grade_counts = {"S": 0, "A": 0, "B": 0, "C": 0, "D": 0, "F": 0}
    status_counts = {
        "complete": 0,
        "in_progress": 0,
        "not_started": 0,
        "no_vcs_defined": 0,
        "parse_error": 0
    }
    
    total_vcs = 0
    completed_vcs = 0
    
    for result in results:
        if "grade" in result:
            grade_counts[result["grade"]] += 1
        if "status" in result:
            status_counts[result["status"]] += 1
        if "total_vcs" in result:
            total_vcs += result["total_vcs"]
            completed_vcs += result["completed_vcs"]
    
    overall_completion = (completed_vcs / total_vcs * 100) if total_vcs > 0 else 0.0
    overall_grade = get_grade(overall_completion)
    
    stats = {
        "total_campaigns": total_campaigns,
        "total_vcs": total_vcs,
        "completed_vcs": completed_vcs,
        "overall_completion_pct": overall_completion,
        "overall_grade": overall_grade,
        "grade_distribution": grade_counts,
        "status_distribution": status_counts,
        "db_stats": get_db_stats()
    }
    
    return results, stats


def print_audit_report(results: List[Dict], stats: Dict):
    """Print a formatted audit report."""
    print("=" * 80)
    print("  CAMPAIGN VICTORY CONDITION AUDIT")
    print("=" * 80)
    print()
    
    # Overall statistics
    print(f"Overall Grade: {stats['overall_grade']} ({stats['overall_completion_pct']:.1f}%)")
    print(f"Total Campaigns: {stats['total_campaigns']}")
    print(f"Victory Conditions: {stats['completed_vcs']}/{stats['total_vcs']} complete")
    print()
    
    # Grade distribution
    print("Grade Distribution:")
    for grade in ["S", "A", "B", "C", "D", "F"]:
        count = stats['grade_distribution'][grade]
        bar = "█" * count
        print(f"  {grade}: {count:2d} {bar}")
    print()
    
    # Status distribution
    print("Status Distribution:")
    for status, count in stats['status_distribution'].items():
        print(f"  {status:20s}: {count:2d}")
    print()
    
    # Database stats
    print("Database Statistics:")
    db = stats['db_stats']
    if "error" not in db:
        print(f"  Active Memories:       {db['active_memories']:,}")
        print(f"  Quarantined Memories:  {db['quarantined_memories']:,}")
        print(f"  Total Associations:    {db['total_associations']:,}")
        print(f"  Typed Associations:    {db['typed_associations']:,}")
        print(f"  Untyped Associations:  {db['untyped_associations']:,}")
        print(f"  Unique Entities:       {db['unique_entities']:,}")
        print(f"  Embeddings:            {db['embeddings']:,}")
    else:
        print(f"  Error: {db['error']}")
    print()
    
    # Campaign details by grade
    print("=" * 80)
    print("  CAMPAIGNS BY GRADE")
    print("=" * 80)
    print()
    
    for grade in ["F", "D", "C", "B", "A", "S"]:
        campaigns = [r for r in results if r.get("grade") == grade]
        if not campaigns:
            continue
        
        print(f"Grade {grade} ({len(campaigns)} campaigns):")
        print("-" * 80)
        for camp in campaigns:
            status_icon = {
                "complete": "✓",
                "in_progress": "◐",
                "not_started": "○",
                "no_vcs_defined": "?",
                "parse_error": "✗"
            }.get(camp.get("status", "unknown"), "?")
            
            print(f"  {status_icon} {camp['campaign_id']:40s} {camp['completed_vcs']:2d}/{camp['total_vcs']:2d} VCs ({camp['completion_pct']:5.1f}%)")
            
            # Show incomplete VCs for non-S grades
            if grade != "S" and camp.get("victory_conditions"):
                incomplete = [vc for vc in camp["victory_conditions"] if not vc["completed"]]
                if incomplete and len(incomplete) <= 5:  # Only show if manageable
                    for vc in incomplete[:3]:  # Show first 3
                        desc = vc["description"][:70] + "..." if len(vc["description"]) > 70 else vc["description"]
                        print(f"      ☐ {desc}")
                    if len(incomplete) > 3:
                        print(f"      ... and {len(incomplete) - 3} more")
        print()
    
    # Flagged campaigns for deployment
    print("=" * 80)
    print("  FLAGGED FOR DEPLOYMENT")
    print("=" * 80)
    print()
    
    # S-grade campaigns need verification
    s_campaigns = [r for r in results if r.get("grade") == "S"]
    if s_campaigns:
        print(f"S-Grade (Verification Review): {len(s_campaigns)} campaigns")
        for camp in s_campaigns:
            print(f"  ✓ {camp['campaign_id']:40s} — Final verification needed")
        print()
    
    # Non-S campaigns need improvement
    non_s = [r for r in results if r.get("grade") in ["A", "B", "C", "D", "F"]]
    if non_s:
        print(f"Below S-Grade (Improvement Needed): {len(non_s)} campaigns")
        for camp in sorted(non_s, key=lambda x: x.get("completion_pct", 0)):
            grade = camp.get("grade", "?")
            print(f"  {grade} {camp['campaign_id']:40s} — {camp['total_vcs'] - camp['completed_vcs']} VCs remaining")
        print()


def generate_deployment_targets(results: List[Dict]) -> Dict:
    """Generate prioritized deployment targets for armies."""
    targets = {
        "verification_needed": [],  # S-grade campaigns
        "high_priority": [],        # A/B grade, close to completion
        "medium_priority": [],      # C/D grade
        "low_priority": [],         # F grade, many VCs remaining
        "needs_definition": []      # No VCs defined
    }
    
    for camp in results:
        grade = camp.get("grade")
        status = camp.get("status")
        
        if status == "no_vcs_defined":
            targets["needs_definition"].append(camp)
        elif grade == "S":
            targets["verification_needed"].append(camp)
        elif grade in ["A", "B"]:
            targets["high_priority"].append(camp)
        elif grade in ["C", "D"]:
            targets["medium_priority"].append(camp)
        elif grade == "F":
            targets["low_priority"].append(camp)
    
    return targets


def save_audit_results(results: List[Dict], stats: Dict, targets: Dict):
    """Save audit results to JSON for programmatic access."""
    output = {
        "timestamp": Path(__file__).stat().st_mtime,
        "overall_stats": stats,
        "campaigns": results,
        "deployment_targets": targets
    }
    
    output_path = PROJECT_ROOT / "reports" / "campaign_audit.json"
    output_path.parent.mkdir(parents=True, exist_ok=True)
    output_path.write_text(json.dumps(output, indent=2))
    print(f"Audit results saved to: {output_path}")


if __name__ == "__main__":
    results, stats = audit_all_campaigns()
    targets = generate_deployment_targets(results)
    
    print_audit_report(results, stats)
    
    print("=" * 80)
    print("  DEPLOYMENT RECOMMENDATIONS")
    print("=" * 80)
    print()
    
    if targets["verification_needed"]:
        print(f"✓ {len(targets['verification_needed'])} S-grade campaigns ready for final verification")
    if targets["high_priority"]:
        print(f"⚠ {len(targets['high_priority'])} campaigns at A/B grade — close to completion")
    if targets["medium_priority"]:
        print(f"◐ {len(targets['medium_priority'])} campaigns at C/D grade — moderate work needed")
    if targets["low_priority"]:
        print(f"○ {len(targets['low_priority'])} campaigns at F grade — significant work needed")
    if targets["needs_definition"]:
        print(f"? {len(targets['needs_definition'])} campaigns need Victory Conditions defined")
    print()
    
    save_audit_results(results, stats, targets)
