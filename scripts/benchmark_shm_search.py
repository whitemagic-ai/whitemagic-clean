import mmap
import struct
import subprocess
import time

import numpy as np
import posix_ipc

HEADER_SIZE = 64
MAGIC = 0x574D4B4B # "WMKK"
SLOT_SIZE = 1540
CAPACITY = 1000
SEGMENT_SIZE = HEADER_SIZE + (CAPACITY * SLOT_SIZE)
DIM = 384

def create_shm_segment(name="/whitemagic_embed_bridge"):
    try:
        posix_ipc.unlink_shared_memory(name)
    except posix_ipc.ExistentialError:
        pass

    shm = posix_ipc.SharedMemory(name, posix_ipc.O_CREX, size=SEGMENT_SIZE)
    map_file = mmap.mmap(shm.fd, shm.size)
    shm.close_fd()

    # Write header (magic, version, capacity, count, write_pos, read_pos)
    struct.pack_into("=iiiiii", map_file, 0, MAGIC, 1, CAPACITY, 0, 0, 0)

    return map_file, name

def write_memory_item(map_file, index, memory_id, vector):
    offset = HEADER_SIZE + (index * SLOT_SIZE)
    struct.pack_into("=i", map_file, offset, memory_id)
    # Write the 384 float32 vector
    struct.pack_into(f"={DIM}f", map_file, offset + 4, *vector)

def update_header_count(map_file, count, write_pos=0, read_pos=0):
    struct.pack_into("=iii", map_file, 12, count, write_pos, read_pos)

def python_baseline_search(query_vec, vectors, top_k=5):
    # Pure python/numpy baseline
    start = time.perf_counter()
    # Normalize
    query_norm = query_vec / np.linalg.norm(query_vec)
    vecs_norm = vectors / np.linalg.norm(vectors, axis=1)[:, np.newaxis]

    similarities = np.dot(vecs_norm, query_norm)
    np.argsort(similarities)[::-1][:top_k]

    end = time.perf_counter()
    return end - start

def test_benchmark():
    print("Generating random vectors...")
    vectors = np.random.randn(CAPACITY, DIM).astype(np.float32)
    # L2 normalize them for proper cosine sim (though our C code does this too)
    vectors = vectors / np.linalg.norm(vectors, axis=1)[:, np.newaxis]

    query_vec = vectors[500].copy() # We'll search for the 500th vector

    print("Creating shared memory...")
    mem, name = create_shm_segment()

    print("Writing 1000 vectors to SHM from Python...")
    start_write = time.perf_counter()
    for i in range(CAPACITY):
        write_memory_item(mem, i, 10000 + i, vectors[i])
    update_header_count(mem, CAPACITY, CAPACITY, 0)
    end_write = time.perf_counter()

    print(f"Python write time: {(end_write - start_write) * 1000:.2f}ms")

    # Baseline test
    py_lat = python_baseline_search(query_vec, vectors)
    print(f"Python/NumPy Search Baseline: {py_lat * 1_000_000:.2f}µs")

    print("Starting Koka SHM Search Engine...")
    proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_search'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=True,
        bufsize=1
    )

    proc.stdout.readline()
    conn = proc.stdout.readline()
    if "error" in conn:
        print("Failed to connect:", conn)
        proc.kill()
        return

    print("Warming up Koka...")
    proc.stdin.write('{"op":"status"}\n')
    proc.stdin.flush()
    proc.stdout.readline()

    print("Executing Koka SHM Search (over 1000 items)...")

    latencies = []

    for _ in range(100):
        # We query for index 500
        start_koka = time.perf_counter()
        proc.stdin.write('{"op":"search", "query_id": 500}\n')
        proc.stdin.flush()
        res = proc.stdout.readline().strip()
        end_koka = time.perf_counter()
        latencies.append((end_koka - start_koka) * 1_000_000)

    print(f"Koka Search Results: {res}")

    latencies.sort()
    avg = sum(latencies) / len(latencies)
    p95 = latencies[int(len(latencies) * 0.95)]

    print(f"Koka Search Latency (Avg): {avg:.2f}µs")
    print(f"Koka Search Latency (P95): {p95:.2f}µs")
    print(f"Speedup vs NumPy: {(py_lat * 1_000_000) / avg:.2f}x")

    proc.stdin.write('{"op":"quit"}\n')
    proc.stdin.flush()
    proc.kill()
    mem.close()

if __name__ == "__main__":
    test_benchmark()
