import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
// ── Server Loop ──

fun extract-op(line: string): string
"""

pattern = r'// ── Server Loop ──.*?fun extract-op\(line: string\): string'
content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk totally cleaned up old Koka loop!")
