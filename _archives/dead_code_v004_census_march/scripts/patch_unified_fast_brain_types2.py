
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.h"

with open(file_path, "r") as f:
    content = f.read()

# Fix int64_t returns
content = content.replace("return kk_integer_from_int(0, ctx);", "return 0;")

with open(file_path, "w") as f:
    f.write(content)

print("Fixed int64_t returns in unified fast brain")
