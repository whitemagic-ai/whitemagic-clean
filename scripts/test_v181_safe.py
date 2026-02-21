#!/usr/bin/env python3
"""
v18.1 Safe Diagnostic Test - Incremental testing to avoid crashes
"""

import sys
import time
from pathlib import Path

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

def test_imports():
    """Test basic imports without heavy computation."""
    print("Step 1: Testing imports...")
    try:
        import numpy as np
        print("  ✓ numpy")
        
        from whitemagic.core.memory.hnsw_index import HNSWIndex
        print("  ✓ HNSWIndex")
        
        from whitemagic.core.memory.open_domain_recall import OpenDomainRecall
        print("  ✓ OpenDomainRecall")
        
        return True
    except Exception as e:
        print(f"  ✗ Import failed: {e}")
        return False

def test_hnsw_light():
    """Lightweight HNSW test."""
    print("\nStep 2: Testing HNSW (light)...")
    try:
        import numpy as np
        from whitemagic.core.memory.hnsw_index import HNSWIndex
        
        index = HNSWIndex(dim=384)
        
        # Add just 10 vectors
        for i in range(10):
            vec = np.random.randn(384).astype(np.float32)
            index.add_item(f"test_{i}", vec)
        
        # Single search
        query = np.random.randn(384).astype(np.float32)
        start = time.perf_counter()
        results = index.search(query, k=5)
        elapsed = (time.perf_counter() - start) * 1000
        
        print(f"  ✓ HNSW search: {elapsed:.2f}ms for 10 vectors")
        return True
    except Exception as e:
        print(f"  ✗ HNSW test failed: {e}")
        return False

def test_open_domain():
    """Test open-domain recall."""
    print("\nStep 3: Testing Open-Domain Recall...")
    try:
        from whitemagic.core.memory.open_domain_recall import OpenDomainRecall
        
        recall = OpenDomainRecall()
        
        # Test title scoring
        score = recall._calculate_title_score(
            "memory system",
            "Memory System Guide"
        )
        
        print(f"  ✓ Title scoring: {score:.3f}")
        return True
    except Exception as e:
        print(f"  ✗ Open-domain test failed: {e}")
        return False

def check_files():
    """Check implementation files exist."""
    print("\nStep 4: Checking implementation files...")
    
    files = {
        "HNSW": "whitemagic/core/memory/hnsw_index.py",
        "Julia Client": "whitemagic/core/bridge/julia_client.py",
        "Open-Domain": "whitemagic/core/memory/open_domain_recall.py",
        "Elixir Pools": "elixir/lib/whitemagic_core/gan_ying/lane_pools.ex",
    }
    
    all_ok = True
    for name, path in files.items():
        full = Path(f"/home/lucas/Desktop/whitemagicdev/{path}")
        if full.exists():
            print(f"  ✓ {name}")
        else:
            print(f"  ✗ {name} missing")
            all_ok = False
    
    return all_ok

def main():
    print("=" * 60)
    print("v18.1 Safe Diagnostic Test")
    print("=" * 60)
    
    results = []
    results.append(("Imports", test_imports()))
    results.append(("HNSW Light", test_hnsw_light()))
    results.append(("Open-Domain", test_open_domain()))
    results.append(("Files", check_files()))
    
    print("\n" + "=" * 60)
    print("Summary")
    print("=" * 60)
    
    passed = sum(1 for _, r in results if r)
    total = len(results)
    
    for name, ok in results:
        status = "PASS" if ok else "FAIL"
        print(f"  {status}: {name}")
    
    print(f"\n{passed}/{total} tests passed")
    
    if passed == total:
        print("\n✓ Ready for full benchmark suite")
    else:
        print("\n✗ Fix issues before full testing")
    
    return passed == total

if __name__ == "__main__":
    success = main()
    sys.exit(0 if success else 1)
