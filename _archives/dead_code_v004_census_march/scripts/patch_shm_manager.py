import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_manager.py"

with open(file_path, "r") as f:
    content = f.read()

# Python's `struct.unpack_into` requires the buffer object as the first argument, 
# unlike `struct.pack_into` which takes format, buffer, offset.
# Wait, struct.unpack_into(fmt, buffer, offset=0) is correct.
# Wait, in the error message it says: "module 'struct' has no attribute 'unpack_into'".
# Ah, `struct.unpack_into` exists, maybe I imported it wrong or it's named differently?
# Actually, wait, `struct` module definitely has `unpack_into` in Python 3.
# Wait, I imported `struct` at the top of shm_manager.py. Let's see.

patch = """
            # Initialize header if it's a new segment or corrupted
            magic = struct.unpack("=i", self._map_file[:4])[0]
            if magic != MAGIC:
                struct.pack_into("=iiiiii", self._map_file, 0, MAGIC, 1, CAPACITY, 0, 0, 0)
                self._count = 0
            else:
                self._count = struct.unpack("=i", self._map_file[12:16])[0]
"""

pattern = r'            # Initialize header if it\'s a new segment or corrupted\n            magic = struct\.unpack_into\("=i", self\._map_file, 0\)\[0\]\n            if magic != MAGIC:\n                struct\.pack_into\("=iiiiii", self\._map_file, 0, MAGIC, 1, CAPACITY, 0, 0, 0\)\n                self\._count = 0\n            else:\n                self\._count = struct\.unpack_into\("=i", self\._map_file, 12\)\[0\]'

content = re.sub(pattern, patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_manager.py unpack_into fixed")
