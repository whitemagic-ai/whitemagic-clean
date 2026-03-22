#!/usr/bin/env python3
"""
Quick LLM Performance Test
===========================
Fast test of local LLM capabilities before running full benchmark.
"""

import sys
import time

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.inference.local_llm import LocalLLM


def test_basic_inference():
    """Test basic LLM inference."""
    print("\n" + "="*80)
    print("Quick LLM Performance Test")
    print("="*80 + "\n")

    model_name = "qwen2.5-coder:1.5b"
    print(f"Model: {model_name}\n")

    llm = LocalLLM(model=model_name)

    if not llm.is_available:
        print("❌ LLM not available")
        print("Make sure Ollama is running: ollama serve")
        return False

    print("✅ LLM loaded successfully\n")

    # Test cases with expected performance
    test_cases = [
        {
            "name": "Simple Code Generation",
            "prompt": "Write a Python function to add two numbers",
            "max_tokens": 100,
            "expected_keywords": ["def", "return", "+"],
        },
        {
            "name": "Code Explanation",
            "prompt": "What does list comprehension do in Python?",
            "max_tokens": 80,
            "expected_keywords": ["list", "comprehension", "syntax"],
        },
        {
            "name": "Debugging",
            "prompt": "Why does this fail: x = [1,2]; print(x[5])",
            "max_tokens": 60,
            "expected_keywords": ["IndexError", "out of range"],
        },
    ]

    results = []
    total_time = 0

    for i, test in enumerate(test_cases, 1):
        print(f"Test {i}/{len(test_cases)}: {test['name']}")
        print(f"Prompt: {test['prompt']}")

        start = time.time()
        answer = llm.complete(test['prompt'], max_tokens=test['max_tokens'], temperature=0.7)
        latency = (time.time() - start) * 1000
        total_time += latency

        # Check for expected keywords
        answer_lower = answer.lower()
        keywords_found = sum(1 for kw in test['expected_keywords'] if kw.lower() in answer_lower)
        quality = keywords_found / len(test['expected_keywords'])

        results.append({
            "name": test['name'],
            "latency_ms": latency,
            "tokens": len(answer.split()),
            "quality": quality,
            "answer": answer[:150] + "..." if len(answer) > 150 else answer,
        })

        print(f"  Latency: {latency:.0f}ms")
        print(f"  Tokens: {len(answer.split())}")
        print(f"  Quality: {quality:.0%} ({keywords_found}/{len(test['expected_keywords'])} keywords)")
        print(f"  Answer: {answer[:100]}...")
        print()

    # Summary
    print("="*80)
    print("SUMMARY")
    print("="*80)
    print(f"Total tests: {len(test_cases)}")
    print(f"Total time: {total_time:.0f}ms ({total_time/1000:.1f}s)")
    print(f"Avg latency: {total_time/len(test_cases):.0f}ms per query")
    print(f"Avg quality: {sum(r['quality'] for r in results)/len(results):.0%}")
    print()

    # Performance assessment
    avg_latency = total_time / len(test_cases)
    avg_quality = sum(r['quality'] for r in results) / len(results)

    if avg_latency < 5000 and avg_quality > 0.6:
        print("✅ Performance: EXCELLENT - Ready for full benchmark")
        return True
    elif avg_latency < 10000 and avg_quality > 0.4:
        print("⚠️  Performance: GOOD - Acceptable but may be slow")
        return True
    else:
        print("❌ Performance: POOR - May need different model or settings")
        return False


if __name__ == "__main__":
    success = test_basic_inference()
    sys.exit(0 if success else 1)
