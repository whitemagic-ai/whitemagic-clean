
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if line.startswith("    def index_count("):
        lines[i] = "    def index_count(self) -> int: return len(self._cache)\n"
    if line.startswith("    def status("):
        lines[i] = "    def status(self) -> dict[str, Any]:\n"

with open(file_path, "w") as f:
    f.writelines(lines)

print("Fixed spacing on class methods")
