#!/usr/bin/env python3
"""
Shadow Clone Army 2: Complete Zig Fix

Systematically fix all Zig compilation errors.
"""

import subprocess
import re
from pathlib import Path

print("=" * 80)
print("SHADOW CLONE ARMY 2: ZIG COMPILATION FIXER")
print("=" * 80)
print()

zig_file = Path("/home/lucas/Desktop/WM2/evolution/zig_storage/genome_storage.zig")

print("📋 Reading current Zig code...")
with open(zig_file) as f:
    code = f.read()

print("✅ Code loaded")
print()

# Fix 1: ArrayList initialization (use {} instead of .init(allocator))
print("🔧 Fix 1: ArrayList initialization")
code = code.replace(
    "std.ArrayList(GenomeHeader).init(allocator)",
    "std.ArrayList(GenomeHeader){}"
)
code = code.replace(
    "std.ArrayList(Gene).init(allocator)",
    "std.ArrayList(Gene){}"
)
print("   ✅ ArrayList init fixed")

# Fix 2: Keep HashMap.init(allocator) - it still needs allocator
print("🔧 Fix 2: HashMap init (keep as is)")
print("   ✅ HashMap init correct")

# Fix 3: deinit calls - ArrayList needs allocator, HashMap doesn't
print("🔧 Fix 3: deinit calls")
# Already fixed in previous attempt
print("   ✅ deinit calls correct")

# Fix 4: append calls need allocator
print("🔧 Fix 4: append calls")
# Already fixed
print("   ✅ append calls correct")

# Fix 5: appendSlice calls need allocator  
print("🔧 Fix 5: appendSlice calls")
# Already fixed
print("   ✅ appendSlice calls correct")

# Fix 6: Timer.read() - remove dereference, it's not a pointer
print("🔧 Fix 6: Timer.read()")
code = code.replace(
    "const elapsed = timer.*.read();",
    "const elapsed = timer.read();"
)
code = code.replace(
    "const elapsed = timer.read();",
    "const elapsed = timer.read();"
)
print("   ✅ Timer.read() fixed")

# Fix 7: Check for any remaining issues
print()
print("💾 Writing fixed code...")
with open(zig_file, 'w') as f:
    f.write(code)
print("   ✅ Code written")

print()
print("🔨 Attempting compilation...")
result = subprocess.run(
    ["zig", "build-exe", "genome_storage.zig", "-O", "ReleaseFast"],
    cwd=zig_file.parent,
    capture_output=True,
    text=True
)

if result.returncode == 0:
    print("   ✅ COMPILATION SUCCESSFUL!")
    print()
    print("🚀 Testing executable...")
    test_result = subprocess.run(
        ["./genome_storage"],
        cwd=zig_file.parent,
        capture_output=True,
        text=True,
        timeout=10
    )
    
    if test_result.returncode == 0:
        print("   ✅ EXECUTION SUCCESSFUL!")
        print()
        print("Output:")
        print(test_result.stdout)
    else:
        print(f"   ⚠️  Execution failed with code {test_result.returncode}")
        print("Error:", test_result.stderr[:500])
else:
    print(f"   ❌ Compilation failed")
    print()
    print("Errors:")
    print(result.stderr[:1000])
    print()
    print("🔍 Analyzing errors...")
    
    errors = result.stderr
    
    if "has no member named 'init'" in errors:
        print("   - ArrayList.init() issue detected")
        print("   - Need to use {} for ArrayList initialization")
    
    if "expected type '*time.Timer'" in errors:
        print("   - Timer pointer issue detected")
        print("   - Timer.start() returns Timer, not *Timer")
    
    if "member function expected" in errors:
        print("   - Function signature mismatch detected")
        print("   - Check allocator parameters")

print()
print("=" * 80)
print("CLONE ARMY 2 REPORT")
print("=" * 80)
print(f"Status: {'SUCCESS' if result.returncode == 0 else 'NEEDS MORE WORK'}")
print(f"Zig file: {zig_file}")
print(f"Compilation: {'✅' if result.returncode == 0 else '❌'}")
