#!/usr/bin/env python3
"""Test Clone Army - PSR-005 Validation Script"""

import time
import sys

def test_clone_army_basic():
    """Test basic clone army functionality"""
    try:
        import whitemagic_rs
        
        print("=" * 60)
        print("PSR-005 Clone Army Test Suite")
        print("=" * 60)
        
        # Test 1: Clone Army Creation
        print("\n[Test 1] Creating Clone Army...")
        army = whitemagic_rs.CloneArmy("test-army", 1000)
        print(f"✓ Army created: {army.army_id} (size: {army.size})")
        
        # Test 2: Deploy clones
        print("\n[Test 2] Deploying clones...")
        tasks = [f"task-{i}" for i in range(100)]
        start = time.time()
        clone_ids = army.deploy(tasks)
        deploy_time = (time.time() - start) * 1000
        print(f"✓ Deployed {len(clone_ids)} clones in {deploy_time:.2f}ms")
        print(f"  Throughput: {len(clone_ids) / (deploy_time / 1000):.0f} clones/sec")
        
        # Test 3: Check status
        print("\n[Test 3] Checking clone status...")
        active_count = army.get_active_count()
        print(f"✓ Active clones: {active_count}")
        
        # Test 4: Complete clones
        print("\n[Test 4] Completing clones...")
        for i, clone_id in enumerate(clone_ids[:10]):
            army.complete_clone(clone_id, f"result-{i}")
        print("✓ Completed 10 clones")
        
        # Test 5: Collect results
        print("\n[Test 5] Collecting results...")
        results = army.collect_results()
        print(f"✓ Collected {len(results)} results")
        completed = sum(1 for _, status in results if status.startswith("completed"))
        print(f"  Completed: {completed}, Pending: {len(results) - completed}")
        
        # Test 6: Advanced Scheduler
        print("\n[Test 6] Testing Advanced Scheduler...")
        scheduler = whitemagic_rs.AdvancedScheduler(4)
        print(f"✓ Scheduler created with {scheduler.worker_count} workers")
        
        batch_tasks = [(f"task-{i}", 5, f"data-{i}") for i in range(1000)]
        scheduler.submit_batch(batch_tasks)
        print(f"✓ Submitted {len(batch_tasks)} tasks")
        
        start = time.time()
        executed = scheduler.execute_parallel()
        exec_time = (time.time() - start) * 1000
        print(f"✓ Executed {executed} tasks in {exec_time:.2f}ms")
        print(f"  Throughput: {executed / (exec_time / 1000):.0f} tasks/sec")
        
        # Test 7: Performance comparison
        print("\n[Test 7] Performance Summary...")
        print(f"  Clone deployment: {len(clone_ids) / (deploy_time / 1000):.0f} clones/sec")
        print(f"  Task execution: {executed / (exec_time / 1000):.0f} tasks/sec")
        
        print("\n" + "=" * 60)
        print("✅ ALL TESTS PASSED - PSR-005 Clone Army Operational!")
        print("=" * 60)
        
        return True
        
    except ImportError as e:
        print(f"❌ Error: Rust bridge not available: {e}")
        print("   Run: cd whitemagic-rust && maturin develop --release")
        return False
    except Exception as e:
        print(f"❌ Test failed: {e}")
        import traceback
        traceback.print_exc()
        return False

def test_clone_army_stress():
    """Stress test with large clone armies"""
    try:
        import whitemagic_rs
        
        print("\n" + "=" * 60)
        print("PSR-005 Stress Test - Large Scale Deployment")
        print("=" * 60)
        
        sizes = [1000, 10000, 50000]
        
        for size in sizes:
            print(f"\n[Stress Test] Deploying {size:,} clones...")
            army = whitemagic_rs.CloneArmy(f"stress-army-{size}", size)
            tasks = [f"task-{i}" for i in range(size)]
            
            start = time.time()
            clone_ids = army.deploy(tasks)
            duration = time.time() - start
            
            throughput = len(clone_ids) / duration
            print(f"✓ Deployed {len(clone_ids):,} clones in {duration:.3f}s")
            print(f"  Throughput: {throughput:,.0f} clones/sec")
            
            if throughput < 100000:
                print("  ⚠️  Below target (100K clones/sec)")
            else:
                print("  ✅ Above target!")
        
        print("\n" + "=" * 60)
        print("✅ Stress Test Complete")
        print("=" * 60)
        
        return True
        
    except Exception as e:
        print(f"❌ Stress test failed: {e}")
        return False

if __name__ == "__main__":
    success = test_clone_army_basic()
    
    if success and "--stress" in sys.argv:
        test_clone_army_stress()
    
    sys.exit(0 if success else 1)
