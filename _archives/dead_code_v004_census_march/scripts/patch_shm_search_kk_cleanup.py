import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Remove the old functional search-memories and insert-sorted
pattern = r'// ── Search Logic ──.*?// ── Server Loop ──'
replacement = "// ── Server Loop ──"
content = re.sub(pattern, replacement, content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk old logic removed!")
