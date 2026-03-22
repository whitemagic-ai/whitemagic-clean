import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Completely remove the old search-memories and insert-sorted logic since we call the C-loop now.
patch = """
// ── Server Loop ──

fun extract-op(line: string): string
"""

pattern = r'// -- Server Loop --.*?(?=fun extract-op)'
content = re.sub(pattern, patch.strip() + "\n\n", content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk fully cleaned up old Koka loop!")
