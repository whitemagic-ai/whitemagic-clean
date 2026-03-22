#!/usr/bin/env python3
"""
Move 100% Complete Campaigns to completedcampaigns Folder
===========================================================
Scan all campaign files, check victory conditions, move completed ones.
"""

import re
from pathlib import Path

CAMPAIGNS_DIR = Path("/home/lucas/Desktop/whitemagicdev/campaigns")
COMPLETED_DIR = CAMPAIGNS_DIR / "completedcampaigns"
COMPLETED_DIR.mkdir(exist_ok=True)

def check_campaign_complete(filepath: Path) -> tuple[bool, int, int]:
    """Check if a campaign is 100% complete.
    
    Returns: (is_complete, completed_count, total_count)
    """
    content = filepath.read_text(encoding='utf-8', errors='ignore')

    # Find all victory conditions
    checked = re.findall(r'- \[x\]', content, re.IGNORECASE)
    unchecked = re.findall(r'- \[ \]', content, re.IGNORECASE)

    completed = len(checked)
    total = completed + len(unchecked)

    if total == 0:
        return False, 0, 0

    is_complete = len(unchecked) == 0 and completed > 0
    return is_complete, completed, total

def main():
    """Move all 100% complete campaigns."""
    print("🔍 Scanning campaigns for completion status...")

    moved = 0
    already_complete = 0
    incomplete = 0

    for campaign_file in CAMPAIGNS_DIR.glob("*.md"):
        if campaign_file.name.startswith('.'):
            continue

        is_complete, completed, total = check_campaign_complete(campaign_file)

        if is_complete:
            # Move to completed folder
            dest = COMPLETED_DIR / campaign_file.name
            if dest.exists():
                already_complete += 1
            else:
                campaign_file.rename(dest)
                print(f"  ✅ Moved: {campaign_file.name} ({completed}/{total})")
                moved += 1
        else:
            incomplete += 1

    print()
    print("📊 Results:")
    print(f"  ✅ Moved: {moved} campaigns")
    print(f"  📁 Already in completed: {already_complete} campaigns")
    print(f"  🔄 Still incomplete: {incomplete} campaigns")
    print()
    print(f"✅ Total completed campaigns: {moved + already_complete}")

if __name__ == "__main__":
    main()
