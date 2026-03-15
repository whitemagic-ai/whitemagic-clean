#!/usr/bin/env python3
"""Living Documentation Sync — Auto-update SYSTEM_MAP.md with code reality.

Reads census data and updates SYSTEM_MAP.md statistics section.
Part of S020 Phase 5: Documentation Auto-Sync.
"""

from __future__ import annotations

import re
from datetime import datetime
from pathlib import Path


def sync_system_map(root_dir: Path | None = None) -> dict:
    """Sync SYSTEM_MAP.md with current codebase statistics.
    
    Returns dict with sync results.
    """
    root = root_dir or Path(__file__).resolve().parent.parent
    
    # Load census data
    census_file = root / "reports" / "great_census.md"
    system_map = root / "SYSTEM_MAP.md"
    
    if not census_file.exists():
        return {"status": "error", "error": "Census file not found. Run codebase_census.py first."}
    
    if not system_map.exists():
        return {"status": "error", "error": "SYSTEM_MAP.md not found."}
    
    # Read current SYSTEM_MAP
    content = system_map.read_text()
    
    # Extract stats from census
    census_content = census_file.read_text()
    
    # Parse key metrics from census
    stats = {}
    
    # Python stats
    py_match = re.search(r"\| \*\*Python\*\* \| \*\*(\d+)\*\* \| \*\*([\d,]+)\*\*", census_content)
    if py_match:
        stats["python_files"] = int(py_match.group(1))
        stats["python_loc"] = int(py_match.group(2).replace(",", ""))
    
    # Total stats
    total_match = re.search(r"\| \*\*Grand total\*\* \| \*\*(\d+) files, ([\d,]+) LOC\*\*", census_content)
    if total_match:
        stats["total_files"] = int(total_match.group(1))
        stats["total_loc"] = int(total_match.group(2).replace(",", ""))
    
    # Dead code
    dead_match = re.search(r"Dead code: (\d+) files \(([\d,]+) LOC\)", census_content)
    if dead_match:
        stats["dead_files"] = int(dead_match.group(1))
        stats["dead_loc"] = int(dead_match.group(2).replace(",", ""))
    
    # Build stats section
    dead_files_str = f"{stats['dead_files']:,}" if "dead_files" in stats else "N/A"
    dead_loc_str = f"{stats['dead_loc']:,}" if "dead_loc" in stats else "0"
    
    stats_section = f"""
## Codebase Statistics (Auto-Generated)

> Last synced: {datetime.now().strftime("%Y-%m-%d %H:%M")}

| Metric | Value |
|--------|-------|
| Total files | {stats.get("total_files", "N/A"):,} |
| Total LOC | {stats.get("total_loc", "N/A"):,} |
| Python files | {stats.get("python_files", "N/A"):,} |
| Python LOC | {stats.get("python_loc", "N/A"):,} |
| Dead code candidates | {dead_files_str} ({dead_loc_str} LOC) |

*Run `python scripts/codebase_census.py` to refresh.*
"""
    
    # Check if stats section exists
    if "## Codebase Statistics (Auto-Generated)" in content:
        # Replace existing section
        pattern = r"## Codebase Statistics \(Auto-Generated\).*?(?=\n## |\Z)"
        content = re.sub(pattern, stats_section.strip() + "\n", content, flags=re.DOTALL)
    else:
        # Append to end
        content = content.rstrip() + "\n" + stats_section
    
    # Write back
    system_map.write_text(content)
    
    return {
        "status": "ok",
        "stats": stats,
        "updated_sections": ["Codebase Statistics"],
    }


if __name__ == "__main__":
    result = sync_system_map()
    if result["status"] == "ok":
        print(f"✓ Synced SYSTEM_MAP.md with {result['stats']}")
    else:
        print(f"✗ {result['error']}")
