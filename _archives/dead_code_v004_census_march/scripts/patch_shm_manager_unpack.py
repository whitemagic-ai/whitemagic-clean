
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_manager.py"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace('struct.unpack("=i", self._map_file[:4])[0]', 'struct.unpack_from("=i", self._map_file, 0)[0]')
content = content.replace('struct.unpack("=i", self._map_file[12:16])[0]', 'struct.unpack_from("=i", self._map_file, 12)[0]')

with open(file_path, "w") as f:
    f.write(content)

print("shm_manager.py unpack_from fixed")
