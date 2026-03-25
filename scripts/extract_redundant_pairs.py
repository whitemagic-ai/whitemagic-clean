from pathlib import Path

ROOT = Path("/home/lucas/Desktop/whitemagicdev")
CENSUS_SCRIPT = ROOT / "scripts" / "codebase_census.py"

def main():
    content = CENSUS_SCRIPT.read_text()
    if 'redundancy_pairs_full.json' not in content:
        # We will inject the json dump right before the other dumps
        target = 'with open(ROOT / "reports" / "import_graph.json", "w") as f:'
        replacement = 'with open(ROOT / "reports" / "redundancy_pairs_full.json", "w") as f:\n        json.dump(results["redundancy_pairs"], f, indent=2)\n    ' + target
        content = content.replace(target, replacement)
        CENSUS_SCRIPT.write_text(content)
        print("Patched census script to dump redundancy pairs.")
    else:
        print("Already patched.")

if __name__ == "__main__":
    main()
