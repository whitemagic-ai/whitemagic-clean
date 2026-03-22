#!/usr/bin/env python3
"""
Test Rust-Accelerated Ingestion
================================
Extract one dense Windsurf session and benchmark Python vs Rust
"""

import time
import sys
from pathlib import Path

# Add project root to path
sys.path.insert(0, str(Path(__file__).parent.parent))

# Test Rust availability
try:
    import whitemagic_rs
    RUST_AVAILABLE = True
    print("✅ Rust bridge loaded successfully")
    print(f"   Functions available: {len([f for f in dir(whitemagic_rs) if not f.startswith('_')])}")
except ImportError as e:
    RUST_AVAILABLE = False
    print(f"❌ Rust bridge not available: {e}")
    sys.exit(1)

# Test session - using the Polyglot Synthesis Loop (17 MB, very dense)
TEST_SESSION = {
    "id": "d4e1e68d-f993-4730-9477-26b54f3f4e46",
    "date": "2026-02-15",
    "title": "Polyglot Synthesis Loop - TEST",
    "tags": ["windsurf", "test", "feb15", "polyglot"],
}

def extract_session_content(session_id: str) -> str:
    """
    Extract session content using trajectory_search.
    For testing, we'll use a sample from the earlier search results.
    """
    # Sample content from the Polyglot Synthesis session
    sample_content = """
# Polyglot Synthesis Loop - Session Summary

## Comprehensive Evolution Complete

### Mission Accomplished
- Compiled 3 Rust modules (1.3 MB total)
- Deployed 640,000 shadow clones across 3 synthesis passes
- Achieved 97.6% code reduction (143,655 → 3,500 LOC)
- Created 12 synthesized subsystems

### Rust Modules Compiled
1. wm2-search_ops (search operations)
2. wm2-crypto_ops (cryptographic operations)
3. wm2-compression (compression algorithms)

### Deep Scan Results
- Functions analyzed: 12,447
- Classes analyzed: 2,076
- Import dependencies: 10,127
- Unique decorators: 697
- Constants extracted: 3,060
- Docstrings analyzed: 11,862
- Exception types: 418
- Async patterns: 1,658

### Third Pass Synthesis
Deployed 350,000 specialized shadow clones:
- Async Pattern Synthesis Army (100K): 1,036 patterns extracted
- Exception Handling Synthesis Army (80K): 22 custom exceptions, 2,133 handlers
- Decorator Pattern Synthesis Army (50K): 350 unique decorators

### Key Discoveries
1. Pattern efficiency: 34 real patterns = 1000 synthetic (97% efficiency gain)
2. Fitness plateau solution: Real-world validation breaks through 0.67-0.68 ceiling
3. Self-expanding knowledge: Evolution → Code → Validation → Scanner → Vault
4. Polyglot strategy: Rust (speed+safety) + Python (flexibility) + Mojo (GPU)

### Infrastructure Created
- 2 Unified mixins (Serializable, MetricCollector)
- 3 Base classes (Engine, Manager, Handler)
- 12 Synthesized subsystems
- 3 Rust modules (1.3 MB compiled)
- 1 Kaizen daemon (autonomous improvement)
- 1 Master integration

### Code Evolution
WM1 (dev): 143,655 LOC → WM2: 3,500 LOC = 97.6% reduction

### Performance Metrics
- Shadow clones deployed: 640,000
- Compilation time: 27.47s for 3 Rust modules
- Memory usage: 14.92 MB
- Throughput: 934K clones/sec (warm)
""" * 50  # Repeat to make it dense like a real session
    
    return sample_content

def test_rust_functions():
    """Test individual Rust functions."""
    print("\n" + "=" * 80)
    print("TESTING RUST FUNCTIONS")
    print("=" * 80)
    print()
    
    # Test 1: Keyword extraction
    print("Test 1: keyword_extract_batch")
    texts = [
        "Rust compilation successful with zero-copy Arrow serialization",
        "Python fallback for systems without GPU acceleration",
        "Mojo provides 50-200x speedup for ML operations",
    ]
    
    t0 = time.time()
    try:
        keywords = whitemagic_rs.keyword_extract_batch(texts, top_k=5)
        elapsed = time.time() - t0
        print(f"   ✅ Extracted keywords in {elapsed*1000:.2f}ms")
        print(f"   Sample: {keywords[0][:3]}")
    except Exception as e:
        print(f"   ❌ Failed: {e}")
    
    # Test 2: Holographic encoding
    print("\nTest 2: holographic_encode_batch")
    titles = [
        "Windsurf Session: Polyglot Synthesis",
        "Windsurf Session: PSR Deployment",
        "Windsurf Session: Evolution Campaigns",
    ]
    
    t0 = time.time()
    try:
        coords = whitemagic_rs.holographic_encode_batch(titles)
        elapsed = time.time() - t0
        print(f"   ✅ Encoded {len(coords)} coordinates in {elapsed*1000:.2f}ms")
        print(f"   Sample coord dimensions: {len(coords[0]) if coords else 0}")
    except Exception as e:
        print(f"   ❌ Failed: {e}")
    
    # Test 3: Arrow encoding
    print("\nTest 3: arrow_encode_memories + arrow_decode_memories")
    test_memories = [
        {
            "id": "test1",
            "content": "Test content 1",
            "title": "Test Memory 1",
            "created_at": "2026-02-17T00:00:00",
            "content_hash": "hash1",
            "tags": ["test"],
            "metadata": {"source": "test"},
        },
        {
            "id": "test2",
            "content": "Test content 2",
            "title": "Test Memory 2",
            "created_at": "2026-02-17T00:00:00",
            "content_hash": "hash2",
            "tags": ["test"],
            "metadata": {"source": "test"},
        },
    ]
    
    t0 = time.time()
    try:
        arrow_data = whitemagic_rs.arrow_encode_memories(test_memories)
        elapsed_encode = time.time() - t0
        print(f"   ✅ Encoded to Arrow in {elapsed_encode*1000:.2f}ms")
        print(f"   Arrow data size: {len(arrow_data):,} bytes")
        
        t0 = time.time()
        decoded = whitemagic_rs.arrow_decode_memories(arrow_data)
        elapsed_decode = time.time() - t0
        print(f"   ✅ Decoded from Arrow in {elapsed_decode*1000:.2f}ms")
        print(f"   Roundtrip successful: {len(decoded) == len(test_memories)}")
    except Exception as e:
        print(f"   ❌ Failed: {e}")

def benchmark_ingestion():
    """Benchmark Python vs Rust ingestion."""
    print("\n" + "=" * 80)
    print("BENCHMARKING INGESTION")
    print("=" * 80)
    print()
    
    # Extract test session
    print("Extracting test session content...")
    content = extract_session_content(TEST_SESSION["id"])
    print(f"   Content size: {len(content):,} characters")
    print()
    
    # Benchmark Python
    print("Benchmark 1: Python ingestion")
    from ingest_windsurf_rust_accelerated import batch_ingest_python
    
    t0 = time.time()
    result_python = batch_ingest_python([TEST_SESSION], [content])
    python_time = time.time() - t0
    
    print(f"   Time: {python_time:.3f}s")
    print(f"   Status: {result_python['status']}")
    print()
    
    # Benchmark Rust
    print("Benchmark 2: Rust-accelerated ingestion")
    from ingest_windsurf_rust_accelerated import batch_ingest_rust
    
    # Use a different session ID to avoid duplicate
    TEST_SESSION["id"] = TEST_SESSION["id"] + "_rust"
    
    t0 = time.time()
    result_rust = batch_ingest_rust([TEST_SESSION], [content])
    rust_time = time.time() - t0
    
    print(f"   Time: {rust_time:.3f}s")
    print(f"   Status: {result_rust['status']}")
    print()
    
    # Compare
    print("=" * 80)
    print("RESULTS")
    print("=" * 80)
    print()
    print(f"Python time:  {python_time:.3f}s")
    print(f"Rust time:    {rust_time:.3f}s")
    
    if rust_time > 0:
        speedup = python_time / rust_time
        print(f"Speedup:      {speedup:.2f}x")
        
        if speedup >= 5:
            print("\n✅ Rust acceleration is HIGHLY EFFECTIVE!")
            print("   Recommendation: Use Rust-accelerated ingestion")
        elif speedup >= 2:
            print("\n✅ Rust acceleration is EFFECTIVE")
            print("   Recommendation: Use Rust-accelerated ingestion")
        elif speedup >= 1.2:
            print("\n⚠️  Rust acceleration shows modest improvement")
            print("   Recommendation: Optimize further or consider pure Rust")
        else:
            print("\n❌ Rust acceleration not effective")
            print("   Recommendation: Build pure Rust CLI tool (Option 2)")

def main():
    print("=" * 80)
    print("RUST-ACCELERATED INGESTION TEST")
    print("=" * 80)
    print()
    
    # Test Rust functions
    test_rust_functions()
    
    # Benchmark ingestion
    benchmark_ingestion()

if __name__ == "__main__":
    main()
