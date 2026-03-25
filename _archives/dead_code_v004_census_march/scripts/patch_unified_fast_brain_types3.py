
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.h"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace("if (addr == 0) return 0;", "if (addr == 0) return kk_integer_from_int(0, ctx);")
content = content.replace("if (count == 0) return 0;", "if (count == 0) return kk_integer_from_int(0, ctx);")

with open(file_path, "w") as f:
    f.write(content)

print("Fixed int returns in kk_unified_embed_search")
