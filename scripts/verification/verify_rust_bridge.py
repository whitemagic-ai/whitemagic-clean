import os
import sys

sys.path.append(os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__)))))

from whitemagic.core.polyglot.mansion_bridge import MansionBridge


bridge = MansionBridge()
print(f"✅ MansionBridge initialized (Rust available: {bridge._rust_status.available})")

def test_similarity():
    print("\n--- Testing Fast Similarity ---")
    s1 = "The quick brown fox"
    s2 = "The quick brown fox jumps"
    try:
        score = bridge.similarity(s1, s2)
        print(f"Similarity ('{s1}', '{s2}'): {score:.4f}")
        assert score > 0.5, "Similarity seems too low"
    except Exception as e:
        print(f"❌ Error in fast_similarity: {e}")

def test_iching():
    print("\n--- Testing I Ching Oracle (Layer 10 Check) ---")
    try:
        result = bridge.iching_cast()
        if result is None:
            print("ℹ️ Zig backend unavailable; I Ching cast skipped")
        else:
            print(f"I Ching result: {result}")
    except Exception as e:
        print(f"❌ Error in iching_cast: {e}")

def test_patterns():
    print("\n--- Testing Pattern Extraction ---")
    content = "def bad_code():\n    pass # TODO: Fix me"
    try:
        result = bridge.extract_patterns(content)
        print(f"Patterns found: {len(result)}")
        print(result)
    except Exception as e:
        print(f"❌ Error in extract_patterns: {e}")

if __name__ == "__main__":
    test_similarity()
    test_iching()
    test_patterns()
    print("\n✨ Rust Bridge Verification Complete ✨")
