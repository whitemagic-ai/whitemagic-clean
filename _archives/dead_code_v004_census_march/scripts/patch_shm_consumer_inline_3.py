import re

header_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.h"

with open(header_path, "r") as f:
    content = f.read()

# Fix the linker errors: 'shm_open' needs -lrt, but Koka might not link it by default.
# The error `undefined reference to kk_string_cbuf` means we probably shouldn't use it directly in our header,
# or we need to include kklib.h properly, but we did include it. It might be a macro or missing from our include path.
# Better yet, let's just pass `const char*` directly from Koka by declaring the FFI parameter as `string` and letting Koka generate the C-string conversion.

patch = """
#ifndef SHM_CONSUMER_H
#define SHM_CONSUMER_H

#include <kklib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>

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
"""

content = re.sub(r'static inline int64_t kk_shm_open_map.*?return \(int64_t\)addr;\n}', patch.strip(), content, flags=re.DOTALL)

with open(header_path, "w") as f:
    f.write(content)

print("shm_consumer.h patched to use kk_string_cbuf_borrow")
