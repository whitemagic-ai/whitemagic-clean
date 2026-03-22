#!/usr/bin/env python3
"""
AUTO-COMPILE CHECKER
====================
Session initialization script to check and recompile polyglot modules
"""

import subprocess
import json
from pathlib import Path
from datetime import datetime, timezone

WM2_ROOT = Path.home() / "Desktop" / "WM2"
PROJECT_ROOT = Path(__file__).parent.parent

def check_module_needs_recompile(module_dir: Path) -> bool:
    """Check if a Rust module needs recompilation."""
    module_dir / "Cargo.toml"
    target_dir = module_dir / "target" / "release"
    
    if not target_dir.exists():
        return True
    
    # Check if any source file is newer than the compiled output
    src_dir = module_dir / "src"
    if not src_dir.exists():
        return True
    
    # Find the most recent source modification
    src_files = list(src_dir.rglob("*.rs"))
    if not src_files:
        return True
    
    latest_src = max(f.stat().st_mtime for f in src_files)
    
    # Find compiled libraries
    lib_files = list(target_dir.glob("*.so")) + list(target_dir.glob("*.dylib")) + list(target_dir.glob("*.dll"))
    
    if not lib_files:
        return True
    
    oldest_lib = min(f.stat().st_mtime for f in lib_files)
    
    return latest_src > oldest_lib

def quick_compile_rust_module(module_dir: Path) -> bool:
    """Quick compile a Rust module."""
    try:
        result = subprocess.run(
            ["cargo", "build", "--release"],
            cwd=module_dir,
            capture_output=True,
            text=True,
            timeout=300
        )
        return result.returncode == 0
    except Exception:
        return False

def main():
    print("🔍 Checking polyglot modules...")
    
    rust_dir = WM2_ROOT / "polyglot" / "rust"
    
    if not rust_dir.exists():
        print("   ⚠️  No polyglot directory found")
        return
    
    # Check Rust availability
    try:
        subprocess.run(["cargo", "--version"], capture_output=True, timeout=5)
    except Exception:
        print("   ⚠️  Rust not available, skipping compilation check")
        return
    
    # Find all Rust modules
    rust_modules = [
        d for d in rust_dir.iterdir()
        if d.is_dir() and (d / "Cargo.toml").exists() and d.name.startswith("wm2-")
    ]
    
    if not rust_modules:
        print("   ℹ️  No Rust modules found")
        return
    
    needs_compile = []
    for module_dir in rust_modules:
        if check_module_needs_recompile(module_dir):
            needs_compile.append(module_dir)
    
    if not needs_compile:
        print(f"   ✅ All {len(rust_modules)} modules up to date")
        return
    
    print(f"   🔨 Recompiling {len(needs_compile)} modules...")
    
    compiled = 0
    for module_dir in needs_compile:
        print(f"      {module_dir.name}...", end=" ", flush=True)
        if quick_compile_rust_module(module_dir):
            print("✅")
            compiled += 1
        else:
            print("❌")
    
    print(f"   ✅ {compiled}/{len(needs_compile)} modules recompiled")
    
    # Save check timestamp
    check_log = {
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "modules_checked": len(rust_modules),
        "modules_recompiled": compiled,
    }
    
    log_path = PROJECT_ROOT / "reports" / "last_compile_check.json"
    log_path.write_text(json.dumps(check_log, indent=2))

if __name__ == "__main__":
    main()
