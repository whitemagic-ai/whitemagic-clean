
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Make sure server-loop has the io type
content = content.replace("fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64)", "fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64) : io ()")
content = content.replace("fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64)\n  with handler", "fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64) : io ()\n  with handler")

with open(file_path, "w") as f:
    f.write(content)

print("Restored io type on server-loop")
