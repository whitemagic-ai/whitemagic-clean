import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.h"

with open(file_path, "r") as f:
    content = f.read()

# Fix the Koka to C type bindings in unified_fast_brain.h
content = content.replace("static inline int kk_unified_embed_search(int64_t addr, kk_context_t* ctx) {", "static inline kk_integer_t kk_unified_embed_search(int64_t addr, kk_context_t* ctx) {")
content = content.replace("return 0;", "return kk_integer_from_int(0, ctx);")
content = content.replace("return 1;", "return kk_integer_from_int(1, ctx);")

content = content.replace("static inline kk_string_t kk_unified_graph_walk(int64_t addr, int32_t start_id, int hops, kk_context_t* ctx)", "static inline kk_string_t kk_unified_graph_walk(int64_t addr, kk_integer_t kk_start_id, kk_integer_t kk_hops, kk_context_t* ctx)")

patch = """
    int32_t start_id = (int32_t)kk_integer_clamp_ssize_t(kk_start_id, ctx);
    int hops = (int)kk_integer_clamp_ssize_t(kk_hops, ctx);
    
    if (addr == 0 || start_id == 0) return kk_string_alloc_from_utf8("{\\"nodes_visited\\":0,\\"edges_traversed\\":0}", ctx);
"""

content = re.sub(r'    if \(addr == 0 \|\| start_id == 0\).*?ctx\);', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Patched unified fast brain types")
