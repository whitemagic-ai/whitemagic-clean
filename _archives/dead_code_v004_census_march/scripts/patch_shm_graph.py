import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_graph.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix table name: it's "associations", not "memory_associations"
patch = """
                    cur = conn.execute("SELECT memory_id, target_id, strength FROM associations")
"""
content = re.sub(r'                    cur = conn\.execute\("SELECT memory_id, target_id, strength FROM memory_associations"\)', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Table name fixed in shm_graph.py")
