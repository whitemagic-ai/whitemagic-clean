
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if "pool = get_db_pool()" in line:
        lines[i] = '                import os\n                default_db = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")\n                pool = get_db_pool(default_db)\n'

with open(file_path, "w") as f:
    f.writelines(lines)

print("vector_search.py db_pool argument patched successfully!")
