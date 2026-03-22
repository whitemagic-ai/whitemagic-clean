import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Update server-loop signature to include <io,prat-route> if it calls handle-event which has prat-route effect
content = content.replace("fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64): io ()", "fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64): <io,prat-route> ()")

# Also, update main to use with-prat-router around server-loop
patch_main = """
  else
    println("{\\"status\\":\\"started\\",\\"connected\\":true}")
    flush-stdout()
    with-prat-router
      server-loop(ring, embed, graph)
"""

content = re.sub(r'  else\n    println\("{\\\\"status\\\\":\\\\"started\\\\",\\\\"connected\\\\":true}"\)\n    flush-stdout\(\)\n    server-loop\(ring, embed, graph\)', patch_main.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Updated server-loop and main signatures for PRAT effect")
