import struct
import posix_ipc
import mmap
import numpy as np

shm = posix_ipc.SharedMemory("/whitemagic_embed_bridge_real")
map_file = mmap.mmap(shm.fd, shm.size)
shm.close_fd()

count = struct.unpack_from("=i", map_file, 12)[0]
print(f"Count: {count}")

def read_vec(idx):
    offset = 64 + (idx * 1540)
    int_id = struct.unpack_from("=i", map_file, offset)[0]
    vec = struct.unpack_from("=384f", map_file, offset + 4)
    return int_id, np.array(vec, dtype=np.float32)

q_id, q_vec = read_vec(count + 1)
print(f"Query vector norm: {np.linalg.norm(q_vec)}")
print(f"Query vector (first 5): {q_vec[:5]}")

id0, vec0 = read_vec(0)
print(f"Vec0 norm: {np.linalg.norm(vec0)}")
print(f"Vec0 (first 5): {vec0[:5]}")

id1, vec1 = read_vec(1)
print(f"Vec1 norm: {np.linalg.norm(vec1)}")
print(f"Vec1 (first 5): {vec1[:5]}")

id2, vec2 = read_vec(2)
print(f"Vec2 norm: {np.linalg.norm(vec2)}")
print(f"Vec2 (first 5): {vec2[:5]}")

dot0 = np.dot(q_vec, vec0)
dot1 = np.dot(q_vec, vec1)
dot2 = np.dot(q_vec, vec2)
print(f"Dots: {dot0}, {dot1}, {dot2}")

