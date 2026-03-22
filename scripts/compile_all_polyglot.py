#!/usr/bin/env python3
"""
COMPILE ALL POLYGLOT CORES
===========================
Compile every Rust and Mojo module with comprehensive error reporting
"""

import json
import subprocess
import time
from datetime import UTC, datetime
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
WM2_ROOT = Path.home() / "Desktop" / "WM2"

print("=" * 80)
print("COMPILING ALL POLYGLOT CORES")
print("=" * 80)
print()

def check_rust_installation():
    """Check if Rust/Cargo is installed."""
    try:
        result = subprocess.run(
            ["cargo", "--version"],
            capture_output=True,
            text=True,
            timeout=5
        )
        if result.returncode == 0:
            return True, result.stdout.strip()
    except (subprocess.TimeoutExpired, FileNotFoundError):
        pass
    return False, None

def check_mojo_installation():
    """Check if Mojo is installed."""
    try:
        result = subprocess.run(
            ["mojo", "--version"],
            capture_output=True,
            text=True,
            timeout=5
        )
        if result.returncode == 0:
            return True, result.stdout.strip()
    except (subprocess.TimeoutExpired, FileNotFoundError):
        pass
    return False, None

def compile_rust_module(module_dir: Path) -> dict:
    """Compile a single Rust module."""
    module_name = module_dir.name

    print(f"   🔨 Compiling {module_name}...")

    try:
        start_time = time.time()
        result = subprocess.run(
            ["cargo", "build", "--release"],
            cwd=module_dir,
            capture_output=True,
            text=True,
            timeout=300
        )
        duration = time.time() - start_time

        if result.returncode == 0:
            # Find the compiled library
            target_dir = module_dir / "target" / "release"
            lib_files = list(target_dir.glob("*.so")) + list(target_dir.glob("*.dylib")) + list(target_dir.glob("*.dll"))

            print(f"      ✅ Success in {duration:.1f}s")
            if lib_files:
                print(f"      📦 Output: {lib_files[0].name}")

            return {
                "module": module_name,
                "status": "success",
                "duration": round(duration, 2),
                "output": str(lib_files[0]) if lib_files else None,
            }
        else:
            print("      ❌ Failed")
            print(f"      Error: {result.stderr[:500]}")

            return {
                "module": module_name,
                "status": "failed",
                "duration": round(duration, 2),
                "error": result.stderr[:1000],
            }
    except subprocess.TimeoutExpired:
        print("      ❌ Timeout (>5 minutes)")
        return {
            "module": module_name,
            "status": "timeout",
            "error": "Compilation timeout after 5 minutes",
        }
    except Exception as e:
        print(f"      ❌ Error: {e}")
        return {
            "module": module_name,
            "status": "error",
            "error": str(e),
        }

def compile_mojo_module(module_file: Path) -> dict:
    """Compile a single Mojo module."""
    module_name = module_file.stem

    print(f"   🔨 Compiling {module_name}.mojo...")

    try:
        start_time = time.time()
        # Mojo compilation (if available)
        result = subprocess.run(
            ["mojo", "build", str(module_file)],
            capture_output=True,
            text=True,
            timeout=300
        )
        duration = time.time() - start_time

        if result.returncode == 0:
            print(f"      ✅ Success in {duration:.1f}s")
            return {
                "module": module_name,
                "status": "success",
                "duration": round(duration, 2),
            }
        else:
            print("      ❌ Failed")
            print(f"      Error: {result.stderr[:500]}")
            return {
                "module": module_name,
                "status": "failed",
                "duration": round(duration, 2),
                "error": result.stderr[:1000],
            }
    except subprocess.TimeoutExpired:
        print("      ❌ Timeout")
        return {
            "module": module_name,
            "status": "timeout",
            "error": "Compilation timeout",
        }
    except Exception as e:
        print(f"      ❌ Error: {e}")
        return {
            "module": module_name,
            "status": "error",
            "error": str(e),
        }

def main():
    compilation_results = {
        "timestamp": datetime.now(UTC).isoformat(),
        "rust": {"available": False, "modules": []},
        "mojo": {"available": False, "modules": []},
    }

    # Check Rust installation
    rust_available, rust_version = check_rust_installation()
    compilation_results["rust"]["available"] = rust_available

    if rust_available:
        print(f"✅ Rust: {rust_version}")
        print()

        # Find all Rust modules
        rust_dir = WM2_ROOT / "polyglot" / "rust"
        if rust_dir.exists():
            rust_modules = [
                d for d in rust_dir.iterdir()
                if d.is_dir() and (d / "Cargo.toml").exists() and d.name.startswith("wm2-")
            ]

            print(f"Found {len(rust_modules)} Rust modules")
            print()

            for module_dir in rust_modules:
                result = compile_rust_module(module_dir)
                compilation_results["rust"]["modules"].append(result)
                print()
        else:
            print("⚠️  Rust directory not found")
            print()
    else:
        print("⚠️  Rust not installed")
        print("   Install: https://rustup.rs/")
        print()

    # Check Mojo installation
    mojo_available, mojo_version = check_mojo_installation()
    compilation_results["mojo"]["available"] = mojo_available

    if mojo_available:
        print(f"✅ Mojo: {mojo_version}")
        print()

        # Find all Mojo modules
        mojo_dir = WM2_ROOT / "polyglot" / "mojo"
        if mojo_dir.exists():
            mojo_modules = list(mojo_dir.glob("*.mojo"))

            print(f"Found {len(mojo_modules)} Mojo modules")
            print()

            for module_file in mojo_modules:
                result = compile_mojo_module(module_file)
                compilation_results["mojo"]["modules"].append(result)
                print()
        else:
            print("⚠️  Mojo directory not found")
            print()
    else:
        print("⚠️  Mojo not installed")
        print("   Install: https://www.modular.com/mojo")
        print()

    # Save results
    results_path = PROJECT_ROOT / "reports" / "polyglot_compilation_results.json"
    results_path.write_text(json.dumps(compilation_results, indent=2))

    # Summary
    print("=" * 80)
    print("COMPILATION SUMMARY")
    print("=" * 80)

    if rust_available:
        rust_success = sum(1 for m in compilation_results["rust"]["modules"] if m["status"] == "success")
        rust_total = len(compilation_results["rust"]["modules"])
        print(f"Rust: {rust_success}/{rust_total} modules compiled successfully")
    else:
        print("Rust: Not available")

    if mojo_available:
        mojo_success = sum(1 for m in compilation_results["mojo"]["modules"] if m["status"] == "success")
        mojo_total = len(compilation_results["mojo"]["modules"])
        print(f"Mojo: {mojo_success}/{mojo_total} modules compiled successfully")
    else:
        print("Mojo: Not available")

    print()
    print(f"📄 Results: {results_path}")
    print()
    print("✅ Compilation complete!")

if __name__ == "__main__":
    main()
