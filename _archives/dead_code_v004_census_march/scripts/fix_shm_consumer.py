import re

kk_file = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(kk_file, "r") as f:
    content = f.read()

# Revert to c "function" instead of c inline
patch = """
extern import
  c file "shm_consumer.c"

// Open and map shared memory, returns pointer (0 on error)
extern shm-open-map(name: string, size: int32): int64
  c "kk_shm_open_map"

// Unmap shared memory
extern shm-unmap(addr: int64, size: int32): int32
  c "kk_shm_unmap"

// Read int32 at offset
extern shm-read-int(addr: int64, offset: int32): int32
  c "kk_shm_read_int"

// Read int64 at offset  
extern shm-read-int64(addr: int64, offset: int32): int64
  c "kk_shm_read_int64"

// Read double at offset
extern shm-read-double(addr: int64, offset: int32): float64
  c "kk_shm_read_double"
"""

pattern = r'extern import\n  c file "shm_consumer\.c".*?c inline "kk_shm_read_double\(#1, #2\)"'
content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

# Fix int -> int32 where they are used with these functions
content = content.replace("segment-size = 1544704", "segment-size = 1544704.int32")
content = content.replace("segment-size)", "segment-size)") # will be fine
content = content.replace("offset: int", "offset: int32")
content = content.replace("header-size = 64", "header-size = 64.int32")
content = content.replace("slot-size = 1544", "slot-size = 1544.int32")

# Also fix the call sites
content = content.replace("h.read-pos * slot-size", "h.read-pos.int32 * slot-size")

with open(kk_file, "w") as f:
    f.write(content)

c_file = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.c"
c_content = """
#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

// Open and map shared memory, returns pointer (0 on error)
int64_t kk_shm_open_map(kk_string_t name, int32_t size, kk_context_t* ctx) {
    const char* c_name = kk_string_cbuf(name, NULL, ctx);
    int fd = shm_open(c_name, O_RDWR, 0666);
    kk_string_drop(name, ctx); // free the koka string
    
    if (fd < 0) return 0;
    void* addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    
    if (addr == MAP_FAILED) return 0;
    return (int64_t)addr;
}

// Unmap shared memory
int32_t kk_shm_unmap(int64_t addr, int32_t size, kk_context_t* ctx) {
    return munmap((void*)addr, size);
}

// Read int32 at offset
int32_t kk_shm_read_int(int64_t addr, int32_t offset, kk_context_t* ctx) {
    return *(int32_t*)(addr + offset);
}

// Read int64 at offset
int64_t kk_shm_read_int64(int64_t addr, int32_t offset, kk_context_t* ctx) {
    return *(int64_t*)(addr + offset);
}

// Read double at offset
double kk_shm_read_double(int64_t addr, int32_t offset, kk_context_t* ctx) {
    return *(double*)(addr + offset);
}
"""

with open(c_file, "w") as f:
    f.write(c_content)

print("Patched shm files!")
