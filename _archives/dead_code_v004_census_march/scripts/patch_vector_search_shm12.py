import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix get_db_pool missing argument
patch = """
            if shm.get_count() == 0:
                from whitemagic.core.memory.db_manager import get_db_pool
                import os
                default_db = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
                shm.sync_from_db(get_db_pool(default_db))
"""

pattern = r'            if shm\.get_count\(\) == 0:\n                from whitemagic\.core\.memory\.db_manager import get_db_pool\n                shm\.sync_from_db\(get_db_pool\(\)\)'

content = re.sub(pattern, patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("vector_search.py get_db_pool fixed")
