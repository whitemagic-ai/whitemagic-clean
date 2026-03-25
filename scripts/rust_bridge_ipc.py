#!/usr/bin/env python3
"""Rust Bridge IPC Server - Python wrapper for WhiteMagic Rust acceleration.

This script provides an IPC interface between Koka and WhiteMagic's Rust
acceleration layer via the polyglot accelerator.

Usage:
    python rust_bridge_ipc.py

Reads JSON commands from stdin, writes JSON responses to stdout.
"""

import json
import sys
import time
import numpy as np
from typing import Any

Any  # Use Any in type hints

# Try to import WhiteMagic acceleration
try:
    from whitemagic.core.acceleration.polyglot_accelerator import get_accelerator
    from whitemagic.utils.fast_json import fast_dumps
    ACCEL_AVAILABLE = True
except ImportError:
    ACCEL_AVAILABLE = False
    print("Warning: WhiteMagic acceleration not available, using fallbacks", file=sys.stderr)


def cosine_similarity(a: list[float], b: list[float]) -> float:
    """Compute cosine similarity using Rust if available."""
    if ACCEL_AVAILABLE:
        try:
            accel = get_accelerator()
            vec_a = np.array(a, dtype=np.float32)
            vec_b = np.array(b, dtype=np.float32)
            return float(accel.cosine_similarity(vec_a, vec_b))
        except Exception as e:
            print(f"Rust acceleration failed: {e}, using numpy", file=sys.stderr)
    
    # Fallback to numpy
    vec_a = np.array(a, dtype=np.float32)
    vec_b = np.array(b, dtype=np.float32)
    dot = np.dot(vec_a, vec_b)
    norm_a = np.linalg.norm(vec_a)
    norm_b = np.linalg.norm(vec_b)
    
    if norm_a == 0 or norm_b == 0:
        return 0.0
    return float(dot / (norm_a * norm_b))


def batch_cosine_similarity(queries: list[list[float]], vectors: list[list[float]]) -> list[list[float]]:
    """Compute batch cosine similarities."""
    results = []
    for query in queries:
        row = []
        for vec in vectors:
            row.append(cosine_similarity(query, vec))
        results.append(row)
    return results


def json_serialize(obj: dict) -> str:
    """Serialize object to JSON using fast JSON if available."""
    if ACCEL_AVAILABLE:
        try:
            return fast_dumps(obj)
        except:
            pass
    return json.dumps(obj)


def process_command(cmd: dict) -> dict:
    """Process a single command and return response."""
    op = cmd.get("op", "unknown")
    start = time.perf_counter()
    
    try:
        if op == "cosine":
            a = cmd.get("a", [1.0, 2.0, 3.0])
            b = cmd.get("b", [2.0, 3.0, 4.0])
            sim = cosine_similarity(a, b)
            elapsed = (time.perf_counter() - start) * 1000
            return {
                "cosine_sim": sim,
                "rust_accelerated": ACCEL_AVAILABLE,
                "elapsed_ms": elapsed
            }
        
        elif op == "batch_cosine":
            queries = cmd.get("queries", [[1.0, 2.0]])
            vectors = cmd.get("vectors", [[1.0, 2.0], [3.0, 4.0]])
            results = batch_cosine_similarity(queries, vectors)
            elapsed = (time.perf_counter() - start) * 1000
            return {
                "batch_results": results,
                "rust_accelerated": ACCEL_AVAILABLE,
                "elapsed_ms": elapsed
            }
        
        elif op == "serialize":
            data = cmd.get("data", {"test": "object"})
            result = json_serialize(data)
            elapsed = (time.perf_counter() - start) * 1000
            return {
                "serialized": result,
                "rust_accelerated": ACCEL_AVAILABLE,
                "elapsed_ms": elapsed
            }
        
        elif op == "stats":
            return {
                "rust_available": ACCEL_AVAILABLE,
                "commands_processed": 0,  # Would track in production
                "total_time_ms": 0.0
            }
        
        elif op == "quit":
            return {"status": "stopped"}
        
        else:
            return {"error": f"unknown op: {op}"}
    
    except Exception as e:
        return {"error": str(e)}


def main():
    """Main IPC loop."""
    print(json.dumps({
        "status": "started",
        "rust_bridge_ipc": True,
        "version": "6.1",
        "rust_available": ACCEL_AVAILABLE,
        "features": ["cosine_similarity", "batch_cosine", "json_serialize"]
    }), flush=True)
    
    while True:
        try:
            line = input()
            if not line:
                continue
            
            cmd = json.loads(line)
            response = process_command(cmd)
            print(json.dumps(response), flush=True)
            
            if cmd.get("op") == "quit":
                break
        
        except EOFError:
            break
        except json.JSONDecodeError as e:
            print(json.dumps({"error": f"invalid json: {str(e)}"}), flush=True)
        except Exception as e:
            print(json.dumps({"error": str(e)}), flush=True)


if __name__ == "__main__":
    main()
