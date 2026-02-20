#!/usr/bin/env python3
"""
Verify G006: Local Inference Layer Integration
Tests the cohesive operation of:
1. LocalEmbedder (FastEmbed)
2. LocalLLM (Ollama)
3. SpeculativeExecutor (Syntax/Security)
"""

import sys
import os
import time

# Add project root to path
sys.path.insert(0, os.getcwd())

from whitemagic.inference.local_embedder import LocalEmbedder
from whitemagic.inference.local_llm import LocalLLM
from whitemagic.optimization.speculative_exec import SpeculativeExecutor

def verify_g006():
    print("=== G006: Local Inference Layer Verification ===\n")

    # 1. Embeddings
    print("1. Testing Local Embeddings (CPU)...")
    try:
        embedder = LocalEmbedder()
        if embedder.is_available:
            start = time.time()
            texts = ["WhiteMagic is an agentic framework.", "Local inference saves tokens.", "Polyglot architecture is fast."]
            vecs = embedder.embed(texts)
            elapsed = time.time() - start
            if vecs is not None and len(vecs) == 3:
                print(f"   ✅ Success: Generated {len(vecs)} vectors of shape {vecs[0].shape} in {elapsed:.4f}s")
                print(f"   Throughput: {len(texts)/elapsed:.1f} texts/sec")
            else:
                print("   ❌ Failed: Vector generation returned None or wrong count")
        else:
            print("   ⚠️  Skipped: FastEmbed not available/installed")
    except Exception as e:
        print(f"   ❌ Error: {e}")

    # 2. Local LLM (Ollama)
    print("\n2. Testing Local LLM (Ollama)...")
    llm = LocalLLM(model="phi3:mini")
    if llm.is_available:
        print(f"   Connected to Ollama at {llm.base_url}")
        
        # Test Completion
        prompt = "Explain 'Wu Wei' in one sentence."
        print(f"   Prompt: '{prompt}'")
        resp = llm.complete(prompt, max_tokens=64)
        print(f"   Response: '{resp.strip()}'")
        
        # Test Classification
        cat = llm.classify("The system encountered a SQL syntax error in the database.", ["security", "performance", "bug"])
        print(f"   Classification: '{cat}' (Expected: bug/security)")
        
        if resp and cat != "unknown":
             print("   ✅ Success: LLM generation and classification working")
        else:
             print("   ❌ Failed: LLM returned empty response or failed classification")
    else:
        print("   ⚠️  Skipped: Ollama not running or model not found. (Start with 'ollama serve')")

    # 3. Speculative Execution
    print("\n3. Testing Speculative Execution...")
    spec = SpeculativeExecutor(local_llm=llm if llm.is_available else None)
    
    # Valid Code
    code_valid = "def hello():\n    print('Hello World')"
    res_valid = spec.validate(code_valid)
    print(f"   Valid Code: {'✅ Passed' if res_valid['valid'] else '❌ Failed'}")

    # Syntax Error
    code_syntax = "def broken(\n    print('oops')"
    res_syntax = spec.validate(code_syntax)
    if not res_syntax['valid'] and "syntax" in [c['name'] for c in res_syntax['checks'] if not c['passed']]:
        print(f"   Syntax Error Catch: ✅ Success ({res_syntax['errors'][0]})")
    else:
        print("   Syntax Error Catch: ❌ Failed (Should have failed validation)")

    # Security Issue
    code_sqli = "cursor.execute(f'SELECT * FROM users WHERE id={user_input}')"
    res_sec = spec.validate(code_sqli)
    if not res_sec['valid'] and "security" in [c['name'] for c in res_sec['checks'] if not c['passed']]:
        print(f"   Security Heuristic Catch: ✅ Success ({res_sec['errors'][0]})")
    else:
        print("   Security Heuristic Catch: ❌ Failed (Should have caught SQLi)")

if __name__ == "__main__":
    verify_g006()
