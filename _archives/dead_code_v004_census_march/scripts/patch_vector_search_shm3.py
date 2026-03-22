import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix the duplicate block causing the indent error
patch = """
        with self._lock:
            # Try Zig SIMD batch top-K for large corpora
            if len(self._cache) > 50:
"""

pattern = r'        with self\._lock:\n            # Try Zig SIMD batch top-K for large corpora\n            # Try Zig SIMD batch top-K for large corpora\n            if len\(self\._cache\) > 50:'

content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("vector_search.py syntax fixed")
