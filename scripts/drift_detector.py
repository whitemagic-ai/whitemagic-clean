#!/usr/bin/env python3
"""Documentation Drift Detector — Compare code reality vs documented state.

Detects when:
- SYSTEM_MAP.md stats are stale
- Grimoire chapters reference non-existent gardens
- Garden/Gana counts mismatch

Part of S020 Phase 5: Documentation Auto-Sync.
"""

from __future__ import annotations

import re
from datetime import datetime
from pathlib import Path


def detect_drift(root_dir: Path | None = None) -> dict:
    """Detect documentation drift.

    Returns dict with drift findings.
    """
    root = root_dir or Path(__file__).resolve().parent.parent

    drifts = []

    # 1. Check SYSTEM_MAP.md stats freshness
    system_map = root / "SYSTEM_MAP.md"
    census_file = root / "reports" / "great_census.md"

    if system_map.exists() and census_file.exists():
        sm_content = system_map.read_text()
        census_content = census_file.read_text()

        # Extract Python LOC from both
        sm_match = re.search(r"\| Python LOC \| ([\d,]+) \|", sm_content)
        census_match = re.search(r"\| \*\*Python\*\* \| \*\*\d+\*\* \| \*\*([\d,]+)\*\*", census_content)

        if sm_match and census_match:
            sm_loc = int(sm_match.group(1).replace(",", ""))
            census_loc = int(census_match.group(1).replace(",", ""))

            if sm_loc != census_loc:
                drifts.append({
                    "type": "stats_stale",
                    "file": "SYSTEM_MAP.md",
                    "field": "Python LOC",
                    "documented": sm_loc,
                    "actual": census_loc,
                    "delta": census_loc - sm_loc,
                })

    # 2. Check grimoire chapters vs gardens
    try:
        import sys
        sys.path.insert(0, str(root))
        from whitemagic.gardens import _GARDEN_MODULES
        from whitemagic.grimoire.chapters import _CHAPTERS_28

        for ch in _CHAPTERS_28:
            if ch.garden not in _GARDEN_MODULES:
                drifts.append({
                    "type": "orphan_garden_reference",
                    "file": "grimoire/chapters.py",
                    "chapter": ch.number,
                    "garden": ch.garden,
                    "actual": None,
                })
    except ImportError:
        pass  # Modules not available

    # 3. Check garden/gana count alignment
    try:
        from whitemagic.gardens import _GARDEN_MODULES
        from whitemagic.tools.prat_router import GANA_TO_TOOLS

        garden_count = len(_GARDEN_MODULES)
        gana_count = len(GANA_TO_TOOLS)

        if garden_count != gana_count:
            drifts.append({
                "type": "count_mismatch",
                "gardens": garden_count,
                "ganas": gana_count,
            })
    except ImportError:
        pass

    return {
        "timestamp": datetime.now().isoformat(),
        "drift_count": len(drifts),
        "drifts": drifts,
        "status": "drift_detected" if drifts else "synchronized",
    }


if __name__ == "__main__":
    result = detect_drift()
    if result["drift_count"] > 0:
        print(f"⚠ Drift detected: {result['drift_count']} issues")
        for d in result["drifts"]:
            print(f"  - {d['type']}: {d}")
    else:
        print("✓ Documentation synchronized with code reality")
