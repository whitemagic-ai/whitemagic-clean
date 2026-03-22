import mmap
import os
import struct
import subprocess
import sys
import time

import numpy as np
import posix_ipc

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.core.memory.db_manager import get_db_pool

HEADER_SIZE = 64
MAGIC = 0x574D4B4B # "WMKK"
SLOT_SIZE = 1540
CAPACITY = 20000
SEGMENT_SIZE = HEADER_SIZE + (CAPACITY * SLOT_SIZE)
DIM = 384

def create_shm_segment(name="/whitemagic_embed_bridge_real"):
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

def write_memory_item(map_file, index, memory_id_hash, vector):
    offset = HEADER_SIZE + (index * SLOT_SIZE)
    # We use a simple hash of the UUID for the int32 ID, or store actual UUID elsewhere.
    # For benchmark we just need to prove similarity speed.
    struct.pack_into("=i", map_file, offset, memory_id_hash)
    struct.pack_into(f"={DIM}f", map_file, offset + 4, *vector)

def update_header_count(map_file, count):
    struct.pack_into("=i", map_file, 12, count)

def load_real_memories():
    db_path = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
    print(f"Loading real embeddings from {db_path}...")

    pool = get_db_pool(db_path)
    vectors = []
    ids = []

    with pool.connection() as conn:
        with conn:
            # We fetch up to CAPACITY embeddings
            cur = conn.execute(f"SELECT memory_id, embedding FROM memory_embeddings LIMIT {CAPACITY}")
            rows = cur.fetchall()

            for row in rows:
                mem_id = row[0]
                blob = row[1]
                if blob:
                    # Deserialize blob to numpy array
                    try:
                        vec = np.frombuffer(blob, dtype=np.float32)
                        if len(vec) == DIM:
                            vectors.append(vec)
                            ids.append(hash(mem_id) & 0x7FFFFFFF)
                    except Exception:
                        pass

    return ids, np.array(vectors, dtype=np.float32)

def python_baseline_search(query_vec, vectors, top_k=5):
    start = time.perf_counter()
    query_norm = query_vec / np.linalg.norm(query_vec)
    vecs_norm = vectors / np.linalg.norm(vectors, axis=1)[:, np.newaxis]

    similarities = np.dot(vecs_norm, query_norm)
    top_indices = np.argsort(similarities)[::-1][:top_k]
    end = time.perf_counter()
    return end - start, similarities[top_indices]

def run_benchmark():
    ids, vectors = load_real_memories()
    count = len(vectors)
    print(f"Loaded {count} embeddings from DB.")

    if count == 0:
        print("No embeddings found. Exiting.")
        return

    print("Creating shared memory segment...")
    mem, name = create_shm_segment()

    print(f"Writing {count} vectors to SHM from Python...")
    start_write = time.perf_counter()

    # Pre-normalize for speed
    vectors = vectors / np.linalg.norm(vectors, axis=1)[:, np.newaxis]

    for i in range(count):
        write_memory_item(mem, i, ids[i], vectors[i])
    update_header_count(mem, count)

    end_write = time.perf_counter()
    print(f"Python to SHM write time: {(end_write - start_write) * 1000:.2f}ms")

    # Pick a random query vector from the set
    query_idx = count // 2
    query_vec = vectors[query_idx]

    print("Running Python/NumPy Baseline...")
    py_lat, py_scores = python_baseline_search(query_vec, vectors)
    print(f"Python/NumPy Search Latency: {py_lat * 1_000_000:.2f}µs")
    print(f"Top 5 Scores: {py_scores}")

    # Now patch the Koka consumer to use our new SHM name
    import fileinput
    for line in fileinput.input("/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk", inplace=True):
        if 'val shm-name =' in line:
            print('val shm-name = "/whitemagic_embed_bridge_real"')
        elif 'val segment-size =' in line:
            print(f'val segment-size = {SEGMENT_SIZE}')
        else:
            print(line, end='')

    # Recompile
    subprocess.run(["koka", "-o", "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_search", "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"], check=True)

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

    print("Executing Koka SHM Search...")

    latencies = []
    # Warmup
    proc.stdin.write(f'{{"op":"search", "query_id": {query_idx}}}\n')
    proc.stdin.flush()
    proc.stdout.readline()

    for _ in range(100):
        start_koka = time.perf_counter()
        proc.stdin.write(f'{{"op":"search", "query_id": {query_idx}}}\n')
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

    # Clean up
    proc.stdin.write('{"op":"quit"}\n')
    proc.stdin.flush()
    proc.kill()
    mem.close()

if __name__ == "__main__":
    run_benchmark()
