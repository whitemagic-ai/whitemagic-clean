
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Remove explicit types that might conflict with effect inference
content = content.replace("fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : <io,prat-route> ()", "fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string)")
content = content.replace("fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64): <io,prat-route> ()", "fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64)")

with open(file_path, "w") as f:
    f.write(content)

print("Removed explicit effect types to rely on Koka inference")
