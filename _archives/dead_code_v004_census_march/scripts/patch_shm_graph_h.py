
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_graph.h"

with open(file_path, "r") as f:
    content = f.read()

patch = """
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

#pragma GCC push_options
"""

content = content.replace("#pragma GCC push_options", patch)

with open(file_path, "w") as f:
    f.write(content)

print("shm_graph.h patched")
