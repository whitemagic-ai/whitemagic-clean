
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the segment size type mismatch. 
# In shm-open-map, size is int32, but in shm-unmap size is int32.
# However, Koka literals without type suffix default to int. We need .int32 suffix.
content = content.replace("val segment-size = 1544704.int32", "val segment-size: int32 = 1544704.int32")
content = content.replace("val header-size = 64.int32", "val header-size: int32 = 64.int32")
content = content.replace("val slot-size = 1544.int32", "val slot-size: int32 = 1544.int32")

# Also need to cast to int32 for the math
content = content.replace("val offset = header-size + (h.read-pos.int32 * slot-size)", "val offset: int32 = header-size + (h.read-pos.int32 * slot-size)")

with open(file_path, "w") as f:
    f.write(content)

print("shm_consumer.kk int32 literal types fixed!")
