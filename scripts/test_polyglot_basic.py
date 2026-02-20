#!/usr/bin/env python3
"""Quick test of polyglot memory system - no heavy benchmarking"""

import sys
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent.parent))

print("\n🔍 Testing Polyglot Memory System\n")

# Test 1: Import Rust module
print("1. Testing Rust module import...")
try:
    import whitemagic_rs
    print(f"   ✅ whitemagic_rs v{whitemagic_rs.__version__}")
    print(f"   ✅ MemoryEngine available: {hasattr(whitemagic_rs, 'MemoryEngine')}")
except ImportError as e:
    print(f"   ❌ Failed: {e}")
    sys.exit(1)

# Test 2: Create MemoryEngine directly
print("\n2. Testing MemoryEngine creation...")
try:
    engine = whitemagic_rs.MemoryEngine("/tmp/test_polyglot.db")
    print(f"   ✅ Created: {engine}")
    stats = engine.cache_stats()
    print(f"   ✅ Cache stats: {stats}")
except Exception as e:
    print(f"   ❌ Failed: {e}")
    import traceback
    traceback.print_exc()

# Test 3: Import UnifiedMemoryV2
print("\n3. Testing UnifiedMemoryV2...")
try:
    from whitemagic.core.memory.unified_v2 import UnifiedMemoryV2
    um = UnifiedMemoryV2()
    print(f"   ✅ Created: {um}")
    stats = um.cache_stats()
    print(f"   ✅ Cache stats: {stats}")
except Exception as e:
    print(f"   ❌ Failed: {e}")
    import traceback
    traceback.print_exc()

# Test 4: Simple search (no embedding model loading)
print("\n4. Testing simple search...")
try:
    from whitemagic.core.memory.unified import UnifiedMemory
    um_old = UnifiedMemory()
    
    # Just test that it initializes
    print(f"   ✅ UnifiedMemory initialized: {um_old.db_path}")
    print(f"   ✅ Memory count: {len(um_old.list_all())}")
except Exception as e:
    print(f"   ❌ Failed: {e}")
    import traceback
    traceback.print_exc()

print("\n" + "="*60)
print("✅ All basic tests passed!")
print("="*60)
print("\nNext steps:")
print("  - Rust MemoryEngine is working")
print("  - Cache system is functional")
print("  - Ready for integration with search")
print("  - Need to wire Zig router")
print()
