
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.c"

with open(file_path, "r") as f:
    content = f.read()

# Fix the warning "control reaches end of non-void function" for the Koka generated C wrappers.
# Koka requires us to return specific types or use `kk_integer_t`. 
# Looking at the warnings, Koka seems to be generating wrapper functions like `kk_whitemagic_dash_koka_src_shm__consumer_shm_unmap` 
# that are calling our functions but not returning properly because our functions might be missing `kk_context_t*`.

# Let's fix the C file to use proper Koka types.
c_content = """
#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

// Open and map shared memory, returns pointer (0 on error)
int64_t kk_shm_open_map(kk_string_t name, intptr_t size, kk_context_t* ctx) {
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
intptr_t kk_shm_unmap(int64_t addr, intptr_t size, kk_context_t* ctx) {
    return munmap((void*)addr, size);
}

// Read int32 at offset
intptr_t kk_shm_read_int(int64_t addr, intptr_t offset, kk_context_t* ctx) {
    return *(int32_t*)(addr + offset);
}

// Read int64 at offset
int64_t kk_shm_read_int64(int64_t addr, intptr_t offset, kk_context_t* ctx) {
    return *(int64_t*)(addr + offset);
}

// Read double at offset
double kk_shm_read_double(int64_t addr, intptr_t offset, kk_context_t* ctx) {
    return *(double*)(addr + offset);
}
"""

with open(file_path, "w") as f:
    f.write(c_content)

print("shm_consumer.c patched for intptr_t!")
