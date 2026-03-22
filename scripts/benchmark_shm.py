import posix_ipc
import mmap
import struct
import time
import subprocess

HEADER_SIZE = 64
MAGIC = 0x574D4B4B # "WMKK"
SLOT_SIZE = 1544
CAPACITY = 1000
SEGMENT_SIZE = HEADER_SIZE + (CAPACITY * SLOT_SIZE)

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

def write_memory_item(map_file, index, memory_id):
    # offset = header + (index * slot_size)
    offset = HEADER_SIZE + (index * SLOT_SIZE)
    struct.pack_into("=i", map_file, offset, memory_id)
    # the rest of the slot is embeddings, we just leave it zeroed for this test
    
def update_header_count(map_file, count, write_pos=0, read_pos=0):
    struct.pack_into("=iii", map_file, 12, count, write_pos, read_pos)

def test_benchmark():
    print("Creating shared memory...")
    mem, name = create_shm_segment()
    
    print("Starting Koka SHM consumer...")
    proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_consumer'],
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
        
    print("Warming up...")
    proc.stdin.write('{"op":"status"}\n')
    proc.stdin.flush()
    proc.stdout.readline()
    
    print("Writing 1000 items to SHM from Python...")
    start_write = time.perf_counter()
    for i in range(1000):
        write_memory_item(mem, i, 10000 + i)
    update_header_count(mem, 1000, 1000, 0)
    end_write = time.perf_counter()
    
    print(f"Python write time: {(end_write - start_write) * 1000:.2f}ms")
    
    print("Telling Koka to read index 500...")
    
    # Update read pos
    update_header_count(mem, 1000, 1000, 500)
    
    start_koka = time.perf_counter()
    proc.stdin.write('{"op":"read"}\n')
    proc.stdin.flush()
    res = proc.stdout.readline().strip()
    end_koka = time.perf_counter()
    
    print(f"Koka read result: {res}")
    print(f"Koka FFI + Read latency: {(end_koka - start_koka) * 1_000_000:.2f}µs")
    
    proc.stdin.write('{"op":"quit"}\n')
    proc.stdin.flush()
    proc.kill()
    mem.close()

if __name__ == "__main__":
    test_benchmark()
