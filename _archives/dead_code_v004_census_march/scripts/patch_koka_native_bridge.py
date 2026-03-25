import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_native_bridge.py"

with open(file_path, "r") as f:
    content = f.read()

patch = """
    "resources": _BASE_DIR / "ring_buffer",
    "dream": _BASE_DIR / "dream_cycle",
    "metrics": _BASE_DIR / "metrics",
    "hot_paths": _BASE_DIR / "hot_paths",
    "shm_search": _BASE_DIR / "shm_search",
}
"""

pattern = r'    "resources": _BASE_DIR / "ring_buffer",\n    "dream": _BASE_DIR / "dream_cycle",\n    "metrics": _BASE_DIR / "metrics",\n    "hot_paths": _BASE_DIR / "hot_paths",\n}'
content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("koka_native_bridge.py patched to include shm_search")
