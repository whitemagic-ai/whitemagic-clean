import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Switch back to pure inline C FFI to avoid the wrapper generation issue entirely
patch = """
extern import
  c file "shm_consumer.h"

// Open and map shared memory, returns pointer (0 on error)
extern shm-open-map(name: string, size: int): int64
  c inline "my_shm_open(kk_string_cbuf(#1, NULL, ctx), #2)"

// Unmap shared memory
extern shm-unmap(addr: int64, size: int): int
  c inline "my_shm_unmap(#1, #2)"

// Read int32 at offset
extern shm-read-int(addr: int64, offset: int): int
  c inline "my_shm_read_int(#1, #2)"

// Read int64 at offset  
extern shm-read-int64(addr: int64, offset: int): int64
  c inline "my_shm_read_int64(#1, #2)"

// Read double at offset
extern shm-read-double(addr: int64, offset: int): float64
  c inline "my_shm_read_double(#1, #2)"
"""

pattern = r'extern import.*?c "kk_shm_read_double"'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("shm_consumer.kk inline headers patched!")
