
import sys
from pathlib import Path

# ANSI colors
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

ROOT_DIR = Path(__file__).parent.parent.resolve()
WHITEMAGIC_DIR = ROOT_DIR / "whitemagic"
RUST_PROD_DIR = ROOT_DIR / "whitemagic-rust" / "src"

# Clone variants that were consolidated into clones.rs during dedup.
# These should NOT exist in production (they were merged/removed).
CLONE_VARIANT_FILES = ["clones_optimized.rs", "clones_dual.rs", "clones_ultra.rs"]

def check_ahocorasick_safety(fpath: Path) -> int:
    """Scan a .rs file for AhoCorasick::new with unwrap/expect. Returns issue count."""
    file_issues = 0
    with open(fpath, "r") as f:
        for i, line in enumerate(f):
            if "AhoCorasick::new" in line:
                if "unwrap()" in line:
                    print(f"{RED}❌ {fpath.name}:{i+1} AhoCorasick unwrap(): {line.strip()}{RESET}")
                    file_issues += 1
                elif "expect(" in line:
                    print(f"{RED}❌ {fpath.name}:{i+1} AhoCorasick expect(): {line.strip()}{RESET}")
                    file_issues += 1
    return file_issues

def check_rust_files():
    print("⚔️  PHASE 11 VERIFICATION START ⚔️")
    print(f"Rust Prod Dir: {RUST_PROD_DIR}")
    issues = 0

    # 1. Clone variant files were consolidated into clones.rs during dedup.
    #    Verify: variants absent from production (merged into single clones.rs).
    print("\n--- Clone Variant Dedup Check ---")
    if (RUST_PROD_DIR / "clones.rs").exists():
        print(f"{GREEN}✅ clones.rs: present in production (canonical){RESET}")
    else:
        print(f"{RED}❌ clones.rs missing from production{RESET}")
        issues += 1
    for fname in CLONE_VARIANT_FILES:
        in_prod = (RUST_PROD_DIR / fname).exists()
        if in_prod:
            print(f"{RED}❌ {fname} still in production — dedup incomplete{RESET}")
            issues += 1
        else:
            print(f"{GREEN}✅ {fname}: removed (consolidated into clones.rs){RESET}")

    # 2. AhoCorasick panic check on all current production .rs files
    print("\n--- Production AhoCorasick Safety ---")
    found_any = False
    for rs_file in sorted(RUST_PROD_DIR.glob("*.rs")):
        file_issues = check_ahocorasick_safety(rs_file)
        issues += file_issues
        # Only print files that actually contain AhoCorasick
        with open(rs_file) as f:
            if "AhoCorasick" in f.read():
                found_any = True
                if file_issues == 0:
                    print(f"{GREEN}✅ {rs_file.name}: AhoCorasick safe{RESET}")
    if not found_any:
        print(f"{GREEN}✅ No AhoCorasick usage in production — nothing to check{RESET}")

    print("\n" + "=" * 30)
    if issues == 0:
        print(f"{GREEN}✨ PHASE 11 VERIFICATION PASSED: RUST ROBUSTNESS ACHIEVED ✨{RESET}")
        sys.exit(0)
    else:
        print(f"{RED}💀 PHASE 11 VERIFICATION FAILED: {issues} ISSUES FOUND 💀{RESET}")
        sys.exit(1)

if __name__ == "__main__":
    check_rust_files()
