import posix_ipc
import mmap
import struct
import subprocess

HEADER_SIZE = 64
MAGIC = 0x574D4B4B # "WMKK"

def create_shm_segment(name="/whitemagic_embed_bridge", capacity=1000):
    slot_size = 1544 # Matches shm_consumer.kk
    segment_size = 1544704 # Matches shm_consumer.kk
    
    try:
        posix_ipc.unlink_shared_memory(name)
    except posix_ipc.ExistentialError:
        pass
        
    shm = posix_ipc.SharedMemory(name, posix_ipc.O_CREX, size=segment_size)
    map_file = mmap.mmap(shm.fd, shm.size)
    shm.close_fd()
    
    # Write header (magic, version, capacity, count, write_pos, read_pos)
    struct.pack_into("=iiiiii", map_file, 0, MAGIC, 1, capacity, 0, 0, 0)
    
    return map_file, name, segment_size

def test():
    print("Creating shared memory...")
    mem, name, size = create_shm_segment()
    
    print("Starting Koka SHM consumer...")
    # Compile it first
    subprocess.run(["koka", "-o", "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_consumer", "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"], check=True)
    
    proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_consumer'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=True,
        bufsize=1
    )
    
    print("Koka Init:", proc.stdout.readline().strip())
    
    # Wait for connected message
    msg = proc.stdout.readline().strip()
    print("Koka connected:", msg)
    
    if "error" in msg:
        proc.kill()
        return
        
    print("Testing read speed...")
    proc.stdin.write('{"op":"status"}\n')
    proc.stdin.flush()
    print("Status:", proc.stdout.readline().strip())
    
    proc.stdin.write('{"op":"quit"}\n')
    proc.stdin.flush()
    proc.kill()
    mem.close()
    
if __name__ == "__main__":
    test()
