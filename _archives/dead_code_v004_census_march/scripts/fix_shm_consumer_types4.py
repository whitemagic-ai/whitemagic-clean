
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Change the FFI size types back to int (which Koka maps to intptr_t/int32_t implicitly depending on platform, but represents as 'int' in Koka source)
content = content.replace("extern shm-open-map(name: string, size: int32): int64", "extern shm-open-map(name: string, size: int): int64")
content = content.replace("extern shm-unmap(addr: int64, size: int32): int32", "extern shm-unmap(addr: int64, size: int): int")
content = content.replace("extern shm-read-int(addr: int64, offset: int32): int32", "extern shm-read-int(addr: int64, offset: int): int")
content = content.replace("extern shm-read-int64(addr: int64, offset: int32): int64", "extern shm-read-int64(addr: int64, offset: int): int64")
content = content.replace("extern shm-read-double(addr: int64, offset: int32): float64", "extern shm-read-double(addr: int64, offset: int): float64")

# Revert constants back to plain int
content = content.replace("val segment-size: int32 = int32(1544704)", "val segment-size = 1544704")
content = content.replace("val header-size: int32 = int32(64)", "val header-size = 64")
content = content.replace("val slot-size: int32 = int32(1544)", "val slot-size = 1544")

content = content.replace("val offset: int32 = header-size + (h.read-pos.int32 * slot-size)", "val offset = header-size + (h.read-pos * slot-size)")

with open(file_path, "w") as f:
    f.write(content)

print("shm_consumer.kk restored to int!")
