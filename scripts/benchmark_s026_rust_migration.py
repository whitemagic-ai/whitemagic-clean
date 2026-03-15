#!/usr/bin/env python3
"""S026 Benchmark: Rust vs Python for all 6 migrated modules

Tests performance of:
- VC3: HNSW Index (vector search)
- VC4: Galaxy Miner (pattern mining)
- VC5: Recursive Intelligence (n-gram patterns)
- VC6: Holographic Encoder (coordinate encoding)
"""

import json
import random
import string
import sys
import time
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent.parent))

# Benchmark configuration
ITERATIONS = 5
WARMUP = 1

def generate_random_vector(dim: int = 384) -> list[float]:
    """Generate a random normalized vector."""
    vec = [random.gauss(0, 1) for _ in range(dim)]
    norm = sum(x * x for x in vec) ** 0.5
    return [x / norm for x in vec]

def generate_random_memory() -> dict:
    """Generate a random memory dict for testing."""
    words = [''.join(random.choices(string.ascii_lowercase, k=random.randint(3, 8))) 
             for _ in range(random.randint(20, 100))]
    return {
        "id": f"bench_{random.randint(10000, 99999)}",
        "content": " ".join(words),
        "importance": random.uniform(0.3, 0.9),
        "access_count": random.randint(0, 50),
        "age_days": random.randint(0, 365),
        "galactic_distance": random.uniform(0.1, 0.9),
        "garden": random.choice(["joy", "wisdom", "truth", "beauty", ""]),
        "tags": random.sample(["algorithm", "function", "love", "wisdom", "debug", "sacred"], 
                               k=random.randint(1, 4))
    }

def benchmark_hnsw():
    """VC3: Benchmark HNSW index operations."""
    print("\n" + "=" * 60)
    print("VC3: HNSW Index Benchmark")
    print("=" * 60)
    
    try:
        import numpy as np
        import whitemagic_rust as wr
        from whitemagic.core.memory.hnsw_index import HNSWIndex
        
        # Test data
        n_vectors = 1000
        dim = 384
        vectors = [np.array(generate_random_vector(dim), dtype=np.float32) for _ in range(n_vectors)]
        query = np.array(generate_random_vector(dim), dtype=np.float32)
        
        # Rust implementation
        print(f"\n🦀 Rust HNSW (n={n_vectors}, dim={dim})")
        idx = HNSWIndex(dim, 16, 200)
        
        # Insert benchmark
        insert_times = []
        for _ in range(WARMUP):
            idx = HNSWIndex(dim, 16, 200)
        for i in range(ITERATIONS):
            idx = HNSWIndex(dim, 16, 200)
            start = time.perf_counter()
            for j, vec in enumerate(vectors):
                idx.add_item(f"id_{j}", vec)
            elapsed = time.perf_counter() - start
            insert_times.append(elapsed)
            print(f"   Insert {n_vectors} vectors: {elapsed*1000:.1f}ms")
        
        avg_insert = sum(insert_times) / len(insert_times)
        
        # Search benchmark
        search_times = []
        for _ in range(WARMUP):
            idx.search(query, 10)
        for i in range(ITERATIONS):
            start = time.perf_counter()
            for _ in range(100):
                idx.search(query, 10)
            elapsed = time.perf_counter() - start
            search_times.append(elapsed / 100)
        avg_search = sum(search_times) / len(search_times)
        print(f"   Search (100 queries): avg {avg_search*1000:.3f}ms/query")
        
        return {
            "insert_ms": avg_insert * 1000,
            "insert_rate": n_vectors / avg_insert,
            "search_ms": avg_search * 1000,
            "search_rate": 1 / avg_search
        }
    except Exception as e:
        print(f"   ❌ Error: {e}")
        return None

def benchmark_galaxy_miner():
    """VC4: Benchmark galaxy pattern mining."""
    print("\n" + "=" * 60)
    print("VC4: Galaxy Miner Benchmark")
    print("=" * 60)
    
    try:
        import whitemagic_rust as wr
        
        # Create a test database
        import sqlite3
        import tempfile
        db_path = tempfile.mktemp(suffix=".db")
        
        conn = sqlite3.connect(db_path)
        conn.executescript("""
            CREATE TABLE memories (
                id TEXT PRIMARY KEY,
                title TEXT,
                content TEXT,
                tags TEXT,
                created_at TEXT DEFAULT CURRENT_TIMESTAMP,
                access_count INTEGER DEFAULT 0
            );
            CREATE TABLE associations (
                source_id TEXT,
                target_id TEXT,
                association_type TEXT DEFAULT 'associated_with'
            );
        """)
        
        # Insert test data
        n_memories = 500
        for i in range(n_memories):
            conn.execute(
                "INSERT INTO memories (id, title, content, tags, access_count) VALUES (?, ?, ?, ?, ?)",
                (f"mem_{i}", f"Memory {i}", f"Content for memory {i}", 
                 json.dumps(["tag1", "tag2"]), random.randint(1, 20))
            )
        
        # Create associations
        for i in range(n_memories - 1):
            conn.execute(
                "INSERT INTO associations (source_id, target_id) VALUES (?, ?)",
                (f"mem_{i}", f"mem_{i+1}")
            )
        conn.commit()
        conn.close()
        
        # Rust benchmark
        print(f"\n🦀 Rust Galaxy Miner (n={n_memories})")
        times = {}
        
        for _ in range(WARMUP):
            wr.galaxy_miner.get_galaxy_stats(db_path)
        
        for i in range(ITERATIONS):
            start = time.perf_counter()
            stats = wr.galaxy_miner.get_galaxy_stats(db_path)
            elapsed = time.perf_counter() - start
            print(f"   get_galaxy_stats: {elapsed*1000:.2f}ms")
        
        # Cleanup
        Path(db_path).unlink(missing_ok=True)
        
        return {"stats_ms": elapsed * 1000}
    except Exception as e:
        print(f"   ❌ Error: {e}")
        return None

def benchmark_recursive_intelligence():
    """VC5: Benchmark pattern discovery."""
    print("\n" + "=" * 60)
    print("VC5: Recursive Intelligence Benchmark")
    print("=" * 60)
    
    try:
        import whitemagic_rust as wr
        
        # Generate test event sequences
        n_events = 1000
        event_types = ["click", "view", "purchase", "logout", "search", "error"]
        events = [random.choice(event_types) for _ in range(n_events)]
        timestamps = list(range(n_events))
        
        print(f"\n🦀 Rust Pattern Discovery (n={n_events})")
        
        # N-gram patterns
        ngram_times = []
        for _ in range(WARMUP):
            wr.recursive_intelligence.find_ngram_patterns(events, 2, 5)
        for i in range(ITERATIONS):
            start = time.perf_counter()
            patterns = wr.recursive_intelligence.find_ngram_patterns(events, 2, 5)
            elapsed = time.perf_counter() - start
            ngram_times.append(elapsed)
            print(f"   find_ngram_patterns: {elapsed*1000:.2f}ms ({len(patterns)} patterns)")
        
        avg_ngram = sum(ngram_times) / len(ngram_times)
        
        return {
            "ngram_ms": avg_ngram * 1000,
            "patterns_found": len(patterns)
        }
    except Exception as e:
        print(f"   ❌ Error: {e}")
        return None

def benchmark_holographic_encoder():
    """VC6: Benchmark holographic coordinate encoding."""
    print("\n" + "=" * 60)
    print("VC6: Holographic Encoder Benchmark")
    print("=" * 60)
    
    try:
        import whitemagic_rust as wr
        from whitemagic.core.intelligence.hologram.encoder import CoordinateEncoder
        
        # Generate test memories
        n_memories = 100
        memories = [generate_random_memory() for _ in range(n_memories)]
        
        # Rust batch encoding
        print(f"\n🦀 Rust Batch Encoding (n={n_memories})")
        
        rust_memories = []
        for m in memories:
            rust_memories.append({
                "id": m["id"],
                "content": m["content"],
                "importance": m["importance"],
                "access_count": m["access_count"],
                "age_days": m["age_days"],
                "galactic_distance": m["galactic_distance"],
                "garden": m["garden"],
                "tags": m["tags"]
            })
        
        rust_times = []
        for _ in range(WARMUP):
            wr.holographic_encoder_5d.holographic_encode_batch(json.dumps(rust_memories))
        for i in range(ITERATIONS):
            start = time.perf_counter()
            result = wr.holographic_encoder_5d.holographic_encode_batch(json.dumps(rust_memories))
            elapsed = time.perf_counter() - start
            rust_times.append(elapsed)
            print(f"   Batch encode {n_memories}: {elapsed*1000:.2f}ms")
        
        avg_rust = sum(rust_times) / len(rust_times)
        
        # Python fallback
        print(f"\n🐍 Python Batch Encoding (n={n_memories})")
        encoder = CoordinateEncoder()
        # Force Python path
        encoder._routing_active = True
        
        python_times = []
        for _ in range(WARMUP):
            [encoder.encode(m) for m in memories]
        for i in range(ITERATIONS):
            start = time.perf_counter()
            coords = [encoder.encode(m) for m in memories]
            elapsed = time.perf_counter() - start
            python_times.append(elapsed)
            print(f"   Batch encode {n_memories}: {elapsed*1000:.2f}ms")
        
        avg_python = sum(python_times) / len(python_times)
        speedup = avg_python / avg_rust if avg_rust > 0 else 0
        
        print(f"\n   Speedup: {speedup:.1f}×")
        
        return {
            "rust_ms": avg_rust * 1000,
            "python_ms": avg_python * 1000,
            "speedup": speedup,
            "rate_rust": n_memories / avg_rust,
            "rate_python": n_memories / avg_python
        }
    except Exception as e:
        print(f"   ❌ Error: {e}")
        return None

def main():
    print("=" * 60)
    print("S026 Polyglot Migration Benchmark Suite")
    print("=" * 60)
    print(f"Iterations: {ITERATIONS}, Warmup: {WARMUP}")
    
    results = {}
    
    # Run all benchmarks
    results["vc3_hnsw"] = benchmark_hnsw()
    results["vc4_galaxy_miner"] = benchmark_galaxy_miner()
    results["vc5_recursive_intelligence"] = benchmark_recursive_intelligence()
    results["vc6_holographic_encoder"] = benchmark_holographic_encoder()
    
    # Summary
    print("\n" + "=" * 60)
    print("SUMMARY")
    print("=" * 60)
    
    if results["vc3_hnsw"]:
        print(f"VC3 HNSW:         {results['vc3_hnsw']['insert_rate']:.0f} inserts/s, "
              f"{results['vc3_hnsw']['search_rate']:.0f} searches/s")
    
    if results["vc4_galaxy_miner"]:
        print(f"VC4 Galaxy Miner: {results['vc4_galaxy_miner']['stats_ms']:.1f}ms stats")
    
    if results["vc5_recursive_intelligence"]:
        print(f"VC5 Recursive:    {results['vc5_recursive_intelligence']['ngram_ms']:.1f}ms n-gram")
    
    if results["vc6_holographic_encoder"]:
        print(f"VC6 Encoder:      {results['vc6_holographic_encoder']['speedup']:.1f}× speedup "
              f"({results['vc6_holographic_encoder']['rate_rust']:.0f} vs "
              f"{results['vc6_holographic_encoder']['rate_python']:.0f} encodes/s)")
    
    print("\n✅ Benchmark complete!")
    return results

if __name__ == "__main__":
    main()
