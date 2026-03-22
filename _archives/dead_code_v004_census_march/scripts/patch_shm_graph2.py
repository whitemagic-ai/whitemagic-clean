import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_graph.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix column name
patch = """
                    cur = conn.execute("SELECT source_id, target_id, strength FROM associations")
"""
content = re.sub(r'                    cur = conn\.execute\("SELECT memory_id, target_id, strength FROM associations"\)', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Column name fixed in shm_graph.py")
