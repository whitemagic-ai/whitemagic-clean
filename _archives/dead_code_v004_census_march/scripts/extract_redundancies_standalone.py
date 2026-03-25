import sys
import json
from pathlib import Path

ROOT = Path("/home/lucas/Desktop/whitemagicdev")
sys.path.insert(0, str(ROOT))

import scripts.codebase_census as cc

results = cc.run_census()

with open(ROOT / "reports" / "redundancy_pairs_full.json", "w") as f:
    json.dump(results["redundancy_pairs_full"], f, indent=2)

print(f"Dumped {len(results['redundancy_pairs_full'])} redundancies to reports/redundancy_pairs_full.json")
