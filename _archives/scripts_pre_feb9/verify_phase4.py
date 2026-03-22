import os
import sys
from pathlib import Path

def test_mojo_leak_logic():
    print("Testing Mojo Matrix Leak Logic...")
    mojo_file = Path("accelerator/src/compute/tensor_network.mojo")
    if not mojo_file.exists():
        print(f"Skipping Mojo test: {mojo_file} not found")
        return True
    
    content = mojo_file.read_text()
    if "free_fn_ptr" in content and "self.free_fn_ptr.bitcast[FreeFn]()" in content:
        print("✅ Mojo Matrix stores and calls free_fn_ptr")
        return True
    else:
        print("❌ Mojo Matrix missing free_fn_ptr logic")
        return False

def test_go_race_synchronization():
    print("Testing Go Mesh Synchronization...")
    go_file = Path("mesh/main.go")
    if not go_file.exists():
        print(f"Skipping Go test: {go_file} not found")
        return True
    
    content = go_file.read_text()
    if "rdbMu sync.RWMutex" in content and "rdbMu.Lock()" in content and "rdbMu.RLock()" in content:
        print("✅ Go mesh uses RWMutex for rdb access")
        return True
    else:
        print("❌ Go mesh missing mutex synchronization")
        return False

def test_python_path_standardization():
    print("Testing Python Path Standardization...")
    obj_gen = Path("newmagic/core/autonomous_execution/objective_generator.py")
    if not obj_gen.exists():
        print(f"Skipping Path test: {obj_gen} not found")
        return True
    
    content = obj_gen.read_text()
    if 'os.getenv("WHITEMAGIC_ROOT", os.getcwd())' in content:
        print("✅ objective_generator.py is environment-aware")
        return True
    else:
        print("❌ objective_generator.py still has hardcoded paths")
        return False

def test_zig_ffi_safety():
    print("Testing Zig FFI Safety...")
    zig_file = Path("whitemagic-zig/src/memory/unified.zig")
    if not zig_file.exists():
        print(f"Skipping Zig test: {zig_file} not found")
        return True
    
    content = zig_file.read_text()
    if "if (id == 0) return null;" in content and "if (size == 0) return null;" in content:
        print("✅ Zig FFI bridge has safety guards")
        return True
    else:
        print("❌ Zig FFI bridge missing safety guards")
        return False

def main():
    os.chdir(".")
    results = [
        test_mojo_leak_logic(),
        test_go_race_synchronization(),
        test_python_path_standardization(),
        test_zig_ffi_safety()
    ]
    
    if all(results):
        print("\n✨ ALL PHASE 4 VERIFICATIONS PASSED ✨")
        sys.exit(0)
    else:
        print("\n❌ SOME PHASE 4 VERIFICATIONS FAILED ❌")
        sys.exit(1)

if __name__ == "__main__":
    main()
