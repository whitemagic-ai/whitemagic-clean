import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the patch in main
patch = """
  else
    println("{\\"status\\":\\"started\\",\\"connected\\":true}")
    flush-stdout()
    with-prat-router
      server-loop(ring, embed, graph)
"""

content = re.sub(r'  else\n    println\("{\\\\"status\\\\":\\\\"started\\\\",\\\\"connected\\\\":true}"\)\n    flush-stdout\(\)\n    server-loop\(ring, embed, graph\)', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Updated main to use with-prat-router")
