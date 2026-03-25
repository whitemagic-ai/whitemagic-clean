import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
  else {
    println("{\\"status\\":\\"started\\",\\"connected\\":true}")
    flush-stdout()
    with-prat-router {
      server-loop(ring, embed, graph)
    }
  }
"""

# We need to replace lines 142-145
content = re.sub(r'  else\n    println\("{\\\\"status\\\\":\\\\"started\\\\",\\\\"connected\\\\":true}"\)\n    flush-stdout\(\)\n    server-loop\(ring, embed, graph\)', patch.strip('\n'), content, flags=re.DOTALL)


with open(file_path, "w") as f:
    f.write(content)
