
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Update handle-event signature to use the effect
content = content.replace("fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : io ()", "fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : <io,prat-route> ()")

with open(file_path, "w") as f:
    f.write(content)

print("Updated handle-event signature")
