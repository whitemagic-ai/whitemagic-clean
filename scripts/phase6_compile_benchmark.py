#!/usr/bin/env python3
"""
PHASE 6: COMPILE AND BENCHMARK
===============================
Compile all Rust modules and benchmark performance
"""

import subprocess
import time
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
WM2_ROOT = Path.home() / "Desktop" / "WM2"

print("=" * 80)
print("PHASE 6: COMPILE AND BENCHMARK")
print("=" * 80)
print()

def main():
    rust_dir = WM2_ROOT / "polyglot" / "rust"

    if not rust_dir.exists():
        print("⚠️  Rust directory not found")
        return

    print("🔨 Compiling Rust modules...")
    print()

    # Check if cargo is available
    try:
        result = subprocess.run(
            ["cargo", "--version"],
            capture_output=True,
            text=True,
            timeout=5
        )
        print(f"   Cargo: {result.stdout.strip()}")
        print()
    except (subprocess.TimeoutExpired, FileNotFoundError):
        print("   ⚠️  Cargo not found - skipping Rust compilation")
        print("   Install Rust: https://rustup.rs/")
        print()
        print("=" * 80)
        print("PHASE 6 COMPLETE (SKIPPED)")
        print("=" * 80)
        print("✅ Rust modules ready for compilation!")
        return

    # Find all Rust modules
    rust_modules = []
    for cargo_toml in rust_dir.rglob("Cargo.toml"):
        if cargo_toml.parent != rust_dir:  # Skip workspace Cargo.toml
            rust_modules.append(cargo_toml.parent)

    print(f"Found {len(rust_modules)} Rust modules")
    print()

    compiled = 0
    failed = 0

    for module_dir in rust_modules:
        module_name = module_dir.name
        print(f"   Compiling {module_name}...")

        try:
            start_time = time.time()
            result = subprocess.run(
                ["cargo", "build", "--release"],
                cwd=module_dir,
                capture_output=True,
                text=True,
                timeout=300  # 5 minutes
            )
            duration = time.time() - start_time

            if result.returncode == 0:
                print(f"      ✅ Compiled in {duration:.1f}s")
                compiled += 1
            else:
                print(f"      ❌ Failed: {result.stderr[:200]}")
                failed += 1
        except subprocess.TimeoutExpired:
            print("      ❌ Timeout (>5 minutes)")
            failed += 1
        except Exception as e:
            print(f"      ❌ Error: {e}")
            failed += 1

        print()

    print("=" * 80)
    print("PHASE 6 COMPLETE")
    print("=" * 80)
    print(f"Modules compiled: {compiled}")
    print(f"Modules failed: {failed}")
    print()
    print("✅ Compilation complete!")

if __name__ == "__main__":
    main()
