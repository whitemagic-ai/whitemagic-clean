
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Make sure server-loop has the right effect
content = content.replace("fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64) : io ()", "fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64) : <io,prat-route> ()")

with open(file_path, "w") as f:
    f.write(content)
