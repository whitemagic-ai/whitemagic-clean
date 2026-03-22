import os
import sys
import asyncio
import sqlite3
from pathlib import Path
from whitemagic.local_ml.engine import get_local_ml_engine
from whitemagic.core.memory.db_manager import get_db_pool
from whitemagic.interfaces.api.rate_limit import RateLimiter

async def test_ml_sanitization():
    print("Testing ML Prompt Sanitization...")
    engine = get_local_ml_engine()
    
    # Test control character stripping
    malicious_prompt = "Hello\x00World\x07!"
    sanitized = engine._sanitize_prompt(malicious_prompt)
    if "\x00" not in sanitized and "\x07" not in sanitized:
        print("✅ Control characters stripped")
    else:
        print("❌ Control characters NOT stripped")
        return False
        
    # Test length limit
    long_prompt = "A" * 5000
    sanitized = engine._sanitize_prompt(long_prompt)
    if len(sanitized) == 4096:
        print("✅ Oversized prompt truncated")
        return True
    else:
        print(f"❌ Length limit failed: {len(sanitized)}")
        return False

async def test_db_pooling():
    print("Testing DB Connection Pooling...")
    db_path = "test_pool.db"
    pool = get_db_pool(db_path, max_connections=2)
    
    with pool.connection() as conn1:
        print("✅ Obtained connection 1")
        with pool.connection() as conn2:
            print("✅ Obtained connection 2")
            # This should timeout if max_connections is 2
            try:
                with pool.connection() as conn3:
                    print("❌ WRONG: Obtained connection 3 (exceeded limit)")
                    return False
            except Exception:
                print("✅ Connection 3 correctly blocked/timed out")
    
    # Cleanup
    if os.path.exists(db_path):
        os.remove(db_path)
    return True

async def test_burstable_rate_limit():
    print("Testing Burstable Rate Limiting...")
    # 10 req/min, 15 request burst
    limiter = RateLimiter(max_requests=10, window_seconds=60, burst_limit=15)
    
    # Fill up to 10
    for _ in range(10):
        if not await limiter.check_rate_limit("user1"):
            print("❌ Rate limited too early")
            return False
    print("✅ Reached base limit (10)")
    
    # Try burst (should allow up to 15 if recent usage is low)
    # Actually my logic allows burst if recent usage in 10% window is low.
    # Since we just hammered it, recent usage is HIGH.
    if await limiter.check_rate_limit("user1"):
        print("❌ Burst allowed when recent usage is high (expected failure)")
        return False
    else:
        print("✅ Burst correctly limited when hammering")
    
    # Wait for "recent" window (10% of 60s = 6s)
    # But for test, let's just create a new limiter with a tiny window
    fast_limiter = RateLimiter(max_requests=10, window_seconds=2, burst_limit=15)
    for _ in range(10):
        await fast_limiter.check_rate_limit("user2")
    
    await asyncio.sleep(0.3) # Wait for 10% window to pass if window is 2s (0.2s)
    if await fast_limiter.check_rate_limit("user2"):
        print("✅ Burst allowed after brief stabilization")
        return True
    else:
        print("❌ Burst NOT allowed after stabilization")
        return False

async def main():
    # Set PYTHONPATH to include current dir
import sys; import os; sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))) # Auto-fixed path
    
    results = [
        await test_ml_sanitization(),
        await test_db_pooling(),
        await test_burstable_rate_limit()
    ]
    
    if all(results):
        print("\n✨ ALL PHASE 5 VERIFICATIONS PASSED ✨")
        sys.exit(0)
    else:
        print("\n❌ SOME PHASE 5 VERIFICATIONS FAILED ❌")
        sys.exit(1)

if __name__ == "__main__":
    asyncio.run(main())
