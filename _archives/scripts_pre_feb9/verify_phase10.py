
import sys
from pathlib import Path

# ANSI colors
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

ROOT_DIR = Path(__file__).parent.parent.resolve()
WHITEMAGIC_DIR = ROOT_DIR / "whitemagic"
RUST_PROD_DIR = ROOT_DIR / "rust_core/src"

RUST_TARGETS = [
    "clones_optimized.rs",
    "clones_dual.rs",
    "clones.rs",
    "memory_consolidation.rs",
]

def check_pattern(files, directory, pattern, forbidden=True):
    print(f"\nChecking for pattern '{pattern}' in {directory}...")
    issues = 0
    for rel_path in files:
        file_path = directory / rel_path
        if not file_path.exists():
            print(f"{RED}❌ File not found: {file_path}{RESET}")
            issues += 1
            continue
            
        try:
            with open(file_path, "r", encoding="utf-8") as f:
                content = f.read()
            
            lines = content.splitlines()
            for i, line in enumerate(lines):
                if forbidden and pattern in line:
                    # Ignore commented out
                    if "//" in line and line.find("//") < line.find(pattern):
                        continue
                    print(f"{RED}❌ Found forbidden '{pattern}' in {rel_path}:{i+1}: {line.strip()}{RESET}")
                    issues += 1
                    
        except Exception as e:
            print(f"{RED}❌ Error reading {rel_path}: {e}{RESET}")
            issues += 1
            
    return issues

def verify_voice_synthesis():
    print("\nVerifying voice_synthesis.py cleanup...")
    target = WHITEMAGIC_DIR / "gardens/voice/voice_synthesis.py"
    
    if not target.exists():
         print(f"{RED}❌ voice_synthesis.py not found{RESET}")
         return 1
         
    with open(target, "r") as f:
        content = f.read()
        
    if "def __del__(self):" in content:
        print(f"{RED}❌ __del__ method found (should be removed){RESET}")
        return 1
        
    if "atexit.register(self.close)" not in content:
        print(f"{RED}❌ atexit registration not found{RESET}")
        return 1
    
    if "def close(self):" not in content:
         print(f"{RED}❌ close() method not found{RESET}")
         return 1

    print(f"{GREEN}✅ voice_synthesis.py remediation verified{RESET}")
    return 0

def main():
    print("⚔️  PHASE 10 VERIFICATION START ⚔️")
    print(f"Rust Prod Dir: {RUST_PROD_DIR}")
    
    total_issues = 0
    
    # 1. Check Rust Hardening in Production Path
    print("\n--- Rust Hardening Check (Production) ---")
    
    # We allow unwrap() generally, but we want to check specifically for the ones we seemingly removed.
    # However, AhoCorasick::new calls were updated to .expect().
    # Let's check specifically for the "unsafe" signatures if possible, or just grep for unwrap in those specific contexts.
    # Simpler: ensuring AhoCorasick::new...unwrap() is gone.
    
    issues = 0
    for fname in ["clones_optimized.rs", "clones_dual.rs", "clones.rs"]:
        fpath = RUST_PROD_DIR / fname
        if fpath.exists():
            with open(fpath) as f:
                data = f.read()
                if "AhoCorasick::new(&query_terms).unwrap()" in data:
                    print(f"{RED}❌ Found AhoCorasick unwrap in {fname}{RESET}")
                    issues += 1
                else:
                    print(f"{GREEN}✅ {fname} AhoCorasick safe{RESET}")
    
    # Check consolidation ordering panic
    fpath = RUST_PROD_DIR / "memory_consolidation.rs"
    if fpath.exists():
        with open(fpath) as f:
            data = f.read()
            if "partial_cmp(&a.total_score).unwrap()" in data:
                print(f"{RED}❌ Found partial_cmp unwrap in memory_consolidation.rs{RESET}")
                issues += 1
            elif "file_name().unwrap()" in data:
                 print(f"{RED}❌ Found file_name unwrap in memory_consolidation.rs{RESET}")
                 issues += 1
            else:
                 print(f"{GREEN}✅ memory_consolidation.rs safe{RESET}")
                 
    total_issues += issues

    # 2. Check Voice Synthesis
    voice_issues = verify_voice_synthesis()
    total_issues += voice_issues
    
    print("\n" + "="*30)
    if total_issues == 0:
        print(f"{GREEN}✨ PHASE 10 VERIFICATION PASSED: ALIGNED & HARDENED ✨{RESET}")
        sys.exit(0)
    else:
        print(f"{RED}💀 PHASE 10 VERIFICATION FAILED: {total_issues} ISSUES FOUND 💀{RESET}")
        sys.exit(1)

if __name__ == "__main__":
    main()
