import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the control reaches end of non-void function error by switching to our working `c "function"` approach 
# and declaring the correct types. We've done this successfully for shm_consumer.kk.

patch = """
extern import
  c file "shm_search.h"

// Open and map shared memory, returns pointer (0 on error)
extern shm-open-map(name: string, size: int): int64
  c "kk_shm_open_map"

// Unmap shared memory
extern shm-unmap(addr: int64, size: int): int
  c "kk_shm_unmap"

// Read int32 at offset
extern shm-read-int(addr: int64, offset: int): int
  c "kk_shm_read_int"

// Fast C-optimized cosine similarity
extern shm-cosine-sim(addr: int64, off1: int, off2: int, dim: int): float64
  c "kk_shm_cosine_sim"
"""

pattern = r'extern import\n  c file "shm_search\.h".*?c inline "kk_shm_cosine_sim\(#1, #2, #3, #4, ctx\)"'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

header_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.h"
header_content = """
#ifndef SHM_SEARCH_H
#define SHM_SEARCH_H

#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <math.h>

static inline int64_t kk_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
    const char* c_name = kk_string_cbuf_borrow(name, NULL, ctx);
    int fd = shm_open(c_name, O_RDWR, 0666);
    kk_string_drop(name, ctx);
    if (fd < 0) return 0;
    
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    void* addr = mmap(NULL, sz, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    close(fd);
    if (addr == MAP_FAILED) return 0;
    return (int64_t)addr;
}

static inline kk_integer_t kk_shm_unmap(int64_t addr, kk_integer_t size, kk_context_t* ctx) {
    intptr_t sz = kk_integer_clamp_ssize_t(size, ctx);
    int res = munmap((void*)addr, sz);
    return kk_integer_from_int(res, ctx);
}

static inline kk_integer_t kk_shm_read_int(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    int32_t val = *(int32_t*)(addr + off);
    return kk_integer_from_int(val, ctx);
}

static inline int64_t kk_shm_read_int64(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    return *(int64_t*)(addr + off);
}

static inline double kk_shm_read_float32(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    float val = *(float*)(addr + off);
    return (double)val;
}

// C-optimized cosine similarity for a single pair to maximize performance
static inline double kk_shm_cosine_sim(int64_t addr, kk_integer_t off1, kk_integer_t off2, kk_integer_t dim, kk_context_t* ctx) {
    intptr_t o1 = kk_integer_clamp_ssize_t(off1, ctx);
    intptr_t o2 = kk_integer_clamp_ssize_t(off2, ctx);
    intptr_t d = kk_integer_clamp_ssize_t(dim, ctx);
    
    float* v1 = (float*)(addr + o1);
    float* v2 = (float*)(addr + o2);
    
    double dot = 0.0;
    double mag1 = 0.0;
    double mag2 = 0.0;
    
    for (intptr_t i = 0; i < d; i++) {
        double a = (double)v1[i];
        double b = (double)v2[i];
        dot += a * b;
        mag1 += a * a;
        mag2 += b * b;
    }
    
    if (mag1 == 0.0 || mag2 == 0.0) return 0.0;
    return dot / (sqrt(mag1) * sqrt(mag2));
}

#endif
"""

with open(header_path, "w") as f:
    f.write(header_content)

print("shm_search FFI files patched!")
