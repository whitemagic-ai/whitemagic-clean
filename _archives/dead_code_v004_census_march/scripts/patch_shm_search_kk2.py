import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# I need to remove the old Koka loop implementation because we already added the C top-5 search to the FFI!
# The error says "shm-cosine-sim cannot be found", which is because we replaced it with shm-search-top5 in a previous patch!
# But the Koka list loop is still trying to call shm-cosine-sim. Let's just remove the Koka loop entirely.

patch = """
// ── Server Loop ──

fun extract-op(line: string): string
"""

# Replace the whole search logic block
pattern = r'// ── Server Loop ──.*?fun extract-op\(line: string\): string'
content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk cleaned up old Koka loop!")
