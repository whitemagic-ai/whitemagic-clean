
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Just use `int32` function for explicit casting
content = content.replace("1544704.int32", "int32(1544704)")
content = content.replace("64.int32", "int32(64)")
content = content.replace("1544.int32", "int32(1544)")

with open(file_path, "w") as f:
    f.write(content)

print("shm_consumer.kk explicit casts fixed!")
