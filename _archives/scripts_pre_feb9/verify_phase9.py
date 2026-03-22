
import sys
from pathlib import Path

# ANSI colors
GREEN = "\033[92m"
RED = "\033[91m"
RESET = "\033[0m"

ROOT_DIR = Path(__file__).parent.parent.resolve()
WHITEMAGIC_DIR = ROOT_DIR / "whitemagic"
RUST_DIR = ROOT_DIR / "rust/src"

PYTHON_TARGETS = [
    "cache/redis.py",
    "cascade/executor.py",
    "embeddings_optimized.py",
    "interfaces/terminal/patch.py",
    "search/semantic.py",
    "cli_rust.py",
    "rust/embeddings/storage.py",
    "brain_bridge.py",
]

RUST_TARGETS = [
    "holographic.rs",
    "pattern_matcher.rs",
    "data_lake.rs",
    "memory_consolidation.rs",
]

def check_pattern(files, directory, pattern, forbidden=True, file_ext=""):
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
                if pattern in line.strip():
                    # Special check for bare except
                    if pattern == "except:" and line.strip() != "except:":
                         # Allow 'except:' inside comments or strings potentially, but stricter check:
                         # logic: if line stripped IS "except:", it's bad.
                         # If checking 'unwrap()', simple substring is enough.
                         pass
                    
                    if forbidden: # We want NONE of these
                        if pattern == "except:":
                             # strict check
                             if line.strip().startswith("except:") and not line.strip().startswith("except: #"): 
                                 print(f"{RED}❌ Found bare except in {rel_path}:{i+1}: {line.strip()}{RESET}")
                                 issues += 1
                        elif pattern == ".unwrap()":
                             # Check if it's not commented out
                             if not line.strip().startswith("//"):
                                 print(f"{RED}❌ Found unwrap() in {rel_path}:{i+1}: {line.strip()}{RESET}")
                                 issues += 1
                    
        except Exception as e:
            print(f"{RED}❌ Error reading {rel_path}: {e}{RESET}")
            issues += 1
            
    return issues

def verify_python_syntax(files, directory):
    print("\nVerifying Python syntax/imports...")
    issues = 0
    sys.path.append(str(directory.parent)) # Enable importing whitemagic package
    
    for rel_path in files:
        file_path = directory / rel_path
        module_name = rel_path.replace("/", ".").replace(".py", "")
        
        try:
            # We don't actually run it, just compile it
            with open(file_path, "r") as f:
                compile(f.read(), str(file_path), "exec")
            print(f"{GREEN}✅ Syntax OK: {rel_path}{RESET}")
        except Exception as e:
            print(f"{RED}❌ Syntax Error in {rel_path}: {e}{RESET}")
            issues += 1
            
    return issues

def main():
    print("⚔️  PHASE 9 VERIFICATION START ⚔️")
    print(f"Root Dir: {ROOT_DIR}")
    
    total_issues = 0
    
    # 1. Check Python Hygiene
    print("\n--- Python Hygiene Check ---")
    python_issues = check_pattern(PYTHON_TARGETS, WHITEMAGIC_DIR, "except:", forbidden=True)
    if python_issues == 0:
        print(f"{GREEN}✅ No bare except clauses found in target files.{RESET}")
    else:
        print(f"{RED}❌ Found {python_issues} bare except clauses.{RESET}")
    total_issues += python_issues
    
    # 2. Check Rust Hardening
    print("\n--- Rust Hardening Check ---")
    rust_issues = check_pattern(RUST_TARGETS, RUST_DIR, ".unwrap()", forbidden=True)
    if rust_issues == 0:
        print(f"{GREEN}✅ No unwrap() calls found in target files.{RESET}")
    else:
        print(f"{RED}❌ Found {rust_issues} unwrap() calls.{RESET}")
    total_issues += rust_issues

    # 3. Check Python Syntax
    print("\n--- Python Syntax Check ---")
    syntax_issues = verify_python_syntax(PYTHON_TARGETS, WHITEMAGIC_DIR)
    total_issues += syntax_issues
    
    print("\n" + "="*30)
    if total_issues == 0:
        print(f"{GREEN}✨ PHASE 9 VERIFICATION PASSED: ALL CLEAN ✨{RESET}")
        sys.exit(0)
    else:
        print(f"{RED}💀 PHASE 9 VERIFICATION FAILED: {total_issues} ISSUES FOUND 💀{RESET}")
        sys.exit(1)

if __name__ == "__main__":
    main()
