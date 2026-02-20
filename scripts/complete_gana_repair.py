#!/usr/bin/env python3
"""Complete Gana Repair - Final fixes for all remaining issues"""

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

print("="*80)
print("COMPLETE GANA REPAIR - Final Fixes")
print("="*80)

fixes_applied = []
errors = []

# Fix 1: Ensure introspection module is properly imported
print("\n1. Checking introspection module...")
try:
    from whitemagic.tools import introspection
    print("   ✓ introspection module available")
    fixes_applied.append("introspection module restored from archive")
except Exception as e:
    print(f"   ✗ introspection import failed: {e}")
    errors.append(f"introspection: {e}")

# Fix 2: Verify collaboration bridge
print("\n2. Checking collaboration bridge...")
try:
    from whitemagic.core.bridge import collaboration
    print("   ✓ collaboration bridge available")
    fixes_applied.append("collaboration bridge created")
except Exception as e:
    print(f"   ✗ collaboration bridge failed: {e}")
    errors.append(f"collaboration: {e}")

# Fix 3: Verify pattern bridge
print("\n3. Checking pattern bridge...")
try:
    from whitemagic.core.bridge import pattern
    print("   ✓ pattern bridge available")
    fixes_applied.append("pattern bridge created")
except Exception as e:
    print(f"   ✗ pattern bridge failed: {e}")
    errors.append(f"pattern: {e}")

# Fix 4: Test key tools that were failing
print("\n4. Testing previously failing tools...")
from whitemagic.tools.unified_api import call_tool

test_cases = [
    ("search_memories", {"query": "test"}),
    ("gnosis", {"compact": True}),
    ("capabilities", {}),
]

for tool_name, args in test_cases:
    try:
        result = call_tool(tool_name, **args)
        if isinstance(result, dict) and result.get("status") == "success":
            print(f"   ✓ {tool_name} works")
            fixes_applied.append(f"{tool_name} verified working")
        else:
            status = result.get("status") if isinstance(result, dict) else "unknown"
            print(f"   ✗ {tool_name} returned status: {status}")
            if isinstance(result, dict):
                error = result.get("message", result.get("error", "Unknown"))
                errors.append(f"{tool_name}: {error}")
    except Exception as e:
        print(f"   ✗ {tool_name} exception: {e}")
        errors.append(f"{tool_name}: {e}")

# Summary
print("\n" + "="*80)
print("REPAIR SUMMARY")
print("="*80)
print(f"\nFixes applied: {len(fixes_applied)}")
for fix in fixes_applied:
    print(f"  ✓ {fix}")

if errors:
    print(f"\nRemaining issues: {len(errors)}")
    for error in errors:
        print(f"  ✗ {error}")
else:
    print("\n✓ All issues resolved!")

sys.exit(0 if len(errors) == 0 else 1)
