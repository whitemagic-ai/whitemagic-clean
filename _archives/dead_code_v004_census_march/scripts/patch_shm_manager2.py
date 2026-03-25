
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/shm_manager.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix adding vectors - actually, wait, the loop seems okay:
# for row in rows:
#     mem_id = row[0]
#     blob = row[1]
#     vec = np.frombuffer(blob, dtype=np.float32)
# Why did we get the same vectors? Let's check if the blob parsing is right, or if it needs .copy(). np.frombuffer creates a view over the buffer, but `struct.pack_into(f"={DIM}f", self._map_file, offset + 4, *vec)` should correctly extract the values.
# Let's inspect the SHM syncing logic again.
