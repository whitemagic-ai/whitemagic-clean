import time
from whitemagic.core.resonance.batched_bus import BatchedGanYingBus, BatchConfig, ResonanceEvent, EventType
from whitemagic.utils.core import parse_frontmatter

def test_bus_concurrency():
    print("Testing BatchedBus concurrency...")
    config = BatchConfig(enabled=True, batch_size=5, flush_interval_ms=50)
    bus = BatchedGanYingBus(config)
    
    # Mock slow listener
    def slow_listener(events):
        time.sleep(0.1)
    
    bus.listen(EventType.SYSTEM_STATE_CHANGE, slow_listener)
    
    start = time.perf_counter()
    from datetime import datetime
    for i in range(10):
        bus.emit(ResonanceEvent("test", EventType.SYSTEM_STATE_CHANGE, {"i": i}, datetime.now()))
    
    duration = time.perf_counter() - start
    print(f"Emission duration: {duration:.4f}s")
    
    # Allow flushes to complete
    time.sleep(0.3)
    
    if duration < 0.1:
        print("✅ Bus emit is non-blocking")
    else:
        print("❌ Bus emit BLOCKED (expected < 0.1s)")

def test_python_hygiene():
    print("\nTesting Python hygiene fixes...")
    # Trigger exception in yaml parser
    res = parse_frontmatter("invalid: yaml: :")
    assert res == {}, "Should handle invalid yaml safely"
    print("✅ utils/core.py exception handling works")

def test_rust_bindings():
    print("\nTesting Rust bindings (Smoke Test)...")
    try:
        import whitemagic_rs
        print("✅ whitemagic_rs import successful")
        # Trigger regex usage
        # Assuming scan_tree uses the regexes
        whitemagic_rs.cast_heavens_net(".", "safe")
        print("✅ cast_heavens_net executed without panic")
    except ImportError:
        print("⚠️ whitemagic_rs not built/installed (Skipping Rust test)")
    except Exception as e:
        print(f"❌ Rust binding error: {e}")

if __name__ == "__main__":
    test_bus_concurrency()
    test_python_hygiene()
    test_rust_bindings()
