import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Koka C inline FFI expects valid C expressions but we are getting warning: control reaches end of non-void function.
# This means Koka generates wrapper functions but expects us to just put an expression in the inline block, not a whole statement or just the call, or it treats the whole `c inline "..."` as the body.
# For Koka v3, if we declare it as `c inline "..."`, Koka puts `return ...;` around it if it returns a value.
# But if it returns `int`, Koka generates `int` function. The warning implies our inline string might be causing issues.
# Actually, the warning is because my_shm_open returns int64_t and Koka expects kk_integer_t if we return `int` maybe?
# We changed all sizes to int, returning int64 for open map, int for unmap, int for read-int, int64 for read-int64.

# Let's write the actual header with `kk_` prefix functions and use `c "function_name"` instead of inline.
patch = """
extern import
  c file "shm_consumer.h"

// Open and map shared memory, returns pointer (0 on error)
extern shm-open-map(name: string, size: int): int64
  c "kk_shm_open_map"

// Unmap shared memory
extern shm-unmap(addr: int64, size: int): int
  c "kk_shm_unmap"

// Read int32 at offset
extern shm-read-int(addr: int64, offset: int): int
  c "kk_shm_read_int"

// Read int64 at offset  
extern shm-read-int64(addr: int64, offset: int): int64
  c "kk_shm_read_int64"

// Read double at offset
extern shm-read-double(addr: int64, offset: int): float64
  c "kk_shm_read_double"
"""

pattern = r'extern import.*?c inline "my_shm_read_double\(#1, #2\)"'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

header_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.h"
header_content = """
#ifndef SHM_CONSUMER_H
#define SHM_CONSUMER_H

#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

static inline int64_t kk_shm_open_map(kk_string_t name, kk_integer_t size, kk_context_t* ctx) {
    const char* c_name = kk_string_cbuf(name, NULL, ctx);
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

static inline double kk_shm_read_double(int64_t addr, kk_integer_t offset, kk_context_t* ctx) {
    intptr_t off = kk_integer_clamp_ssize_t(offset, ctx);
    return *(double*)(addr + off);
}

#endif
"""

with open(header_path, "w") as f:
    f.write(header_content)

print("shm_consumer.kk header and FFI patched!")
