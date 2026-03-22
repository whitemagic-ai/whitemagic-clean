
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if line.startswith("def search(self, query: str, limit: int = 10) -> list[VSearchResult]:"):
        lines[i] = "    " + line
        # we need to indent everything until index_count
        j = i + 1
        while j < len(lines) and not lines[j].startswith("    def index_count"):
            if lines[j].strip():
                lines[j] = "    " + lines[j]
            j += 1
        break

with open(file_path, "w") as f:
    f.writelines(lines)

print("vector_search.py def search indentation fixed")
