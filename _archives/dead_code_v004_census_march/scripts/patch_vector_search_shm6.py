
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if line.startswith("with self._lock:"):
        lines[i] = "        with self._lock:\n"
    elif line.startswith("results = []"):
        lines[i] = "        results = []\n"

with open(file_path, "w") as f:
    f.writelines(lines)

print("vector_search.py indentation fixed")
