#!/usr/bin/env python3
"""Benchmark I008: Arrow IPC vs JSON serialization."""

import json
import time
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

# Test Arrow IPC availability
try:
    import whitemagic_rs
    ARROW_AVAILABLE = hasattr(whitemagic_rs, 'arrow_encode_memories')
    if ARROW_AVAILABLE:
        print("✅ Arrow IPC functions available")
    else:
        print("⚠️  Arrow IPC functions not found in whitemagic_rs")
        print(f"Available functions: {[x for x in dir(whitemagic_rs) if 'arrow' in x.lower()]}")
except ImportError as e:
    print(f"❌ whitemagic_rs not available: {e}")
    ARROW_AVAILABLE = False

def create_test_memories(n=1000):
    """Create test memory data."""
    return [
        {
            "id": f"mem_{i}",
            "title": f"Test Memory {i}",
            "content": f"This is test content for memory number {i}. " * 10,
            "importance": 0.5 + (i * 0.0001),
            "memory_type": "LONG_TERM",
            "x": 0.1, "y": 0.2, "z": 0.3, "w": 0.4, "v": 0.5,
            "tags": ["test", f"tag_{i % 10}"]
        }
        for i in range(n)
    ]

def benchmark_json(memories):
    """Benchmark JSON serialization."""
    start = time.perf_counter()
    json_str = json.dumps(memories)
    encode_time = time.perf_counter() - start
    
    start = time.perf_counter()
    decoded = json.loads(json_str)
    decode_time = time.perf_counter() - start
    
    return encode_time, decode_time, len(json_str)

def benchmark_arrow(memories):
    """Benchmark Arrow IPC."""
    if not ARROW_AVAILABLE:
        return 0, 0, 0
    
    json_str = json.dumps(memories)
    
    start = time.perf_counter()
    ipc_bytes = whitemagic_rs.arrow_encode_memories(json_str)
    encode_time = time.perf_counter() - start
    
    start = time.perf_counter()
    decoded_json = whitemagic_rs.arrow_decode_memories(bytes(ipc_bytes))
    decode_time = time.perf_counter() - start
    
    return encode_time, decode_time, len(ipc_bytes)

def main():
    print("="*80)
    print("I008: ARROW IPC BENCHMARK")
    print("="*80)
    
    if not ARROW_AVAILABLE:
        print("\n❌ Arrow IPC not available - cannot benchmark")
        print("Build with: cd whitemagic-rust && cargo build --release --features arrow")
        return
    
    # Get schema info
    try:
        schema_info = whitemagic_rs.arrow_schema_info()
        print("\n📋 Arrow Schema:")
        schema = json.loads(schema_info)
        print(f"  Format: {schema.get('format')}")
        print(f"  Fields: {schema.get('field_count')}")
    except Exception as e:
        print(f"⚠️  Schema info error: {e}")
    
    # Benchmark different sizes
    for n in [100, 1000, 10000]:
        print(f"\n{'='*80}")
        print(f"Dataset: {n} memories")
        print(f"{'='*80}")
        
        memories = create_test_memories(n)
        
        # JSON baseline
        json_encode, json_decode, json_size = benchmark_json(memories)
        print("\n📊 JSON Serialization:")
        print(f"  Encode: {json_encode*1000:.2f}ms")
        print(f"  Decode: {json_decode*1000:.2f}ms")
        print(f"  Total: {(json_encode + json_decode)*1000:.2f}ms")
        print(f"  Size: {json_size:,} bytes ({json_size/1024:.1f} KB)")
        
        # Arrow IPC
        arrow_encode, arrow_decode, arrow_size = benchmark_arrow(memories)
        print("\n🏹 Arrow IPC:")
        print(f"  Encode: {arrow_encode*1000:.2f}ms")
        print(f"  Decode: {arrow_decode*1000:.2f}ms")
        print(f"  Total: {(arrow_encode + arrow_decode)*1000:.2f}ms")
        print(f"  Size: {arrow_size:,} bytes ({arrow_size/1024:.1f} KB)")
        
        # Speedup
        if arrow_encode > 0 and arrow_decode > 0:
            encode_speedup = json_encode / arrow_encode
            decode_speedup = json_decode / arrow_decode
            total_speedup = (json_encode + json_decode) / (arrow_encode + arrow_decode)
            size_ratio = json_size / arrow_size if arrow_size > 0 else 1.0
            
            print("\n✨ Speedup:")
            print(f"  Encode: {encode_speedup:.1f}×")
            print(f"  Decode: {decode_speedup:.1f}×")
            print(f"  Total: {total_speedup:.1f}×")
            print(f"  Size: {size_ratio:.2f}× (Arrow is {100*(1-1/size_ratio):.0f}% smaller)" if size_ratio > 1 else f"  Size: {1/size_ratio:.2f}× (Arrow is {100*(1/size_ratio-1):.0f}% larger)")
    
    # Rust native benchmark
    print(f"\n{'='*80}")
    print("Rust Native Benchmark (arrow_roundtrip_bench)")
    print(f"{'='*80}")
    
    try:
        encode_ns, decode_ns, ipc_size = whitemagic_rs.arrow_roundtrip_bench(1000)
        print("\n1000 memories:")
        print(f"  Encode: {encode_ns/1_000_000:.2f}ms ({encode_ns/1000:.0f}ns per memory)")
        print(f"  Decode: {decode_ns/1_000_000:.2f}ms ({decode_ns/1000:.0f}ns per memory)")
        print(f"  IPC Size: {ipc_size:,} bytes")
    except Exception as e:
        print(f"⚠️  Native benchmark error: {e}")
    
    print(f"\n{'='*80}")
    print("✅ I008 BENCHMARK COMPLETE")
    print(f"{'='*80}")

if __name__ == "__main__":
    main()
