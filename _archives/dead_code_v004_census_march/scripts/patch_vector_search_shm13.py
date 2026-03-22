
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix get_db_pool missing argument properly
patch = """
            if shm.get_count() == 0:
                from whitemagic.core.memory.db_manager import get_db_pool
                import os
                default_db = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
                shm.sync_from_db(get_db_pool(default_db))
"""

pattern = r'            if shm\.get_count\(\) == 0:\n                from whitemagic\.core\.memory\.db_manager import get_db_pool\n                import os\n                default_db = os\.path\.expanduser\("~/\.whitemagic/memory/whitemagic\.db"\)\n                shm\.sync_from_db\(get_db_pool\(default_db\)\)'

# It looks like the previous regex didn't match. Let's do a pure text replace.
f_content = content.replace(
    'shm.sync_from_db(get_db_pool())',
    'import os\n                default_db = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")\n                shm.sync_from_db(get_db_pool(default_db))'
)

with open(file_path, "w") as f:
    f.write(f_content)

print("vector_search.py db_pool argument patched correctly")
