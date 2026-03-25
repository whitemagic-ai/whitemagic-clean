
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the accidental int3232 double replacement
content = content.replace("int3232", "int32")

with open(file_path, "w") as f:
    f.write(content)

print("shm_consumer.kk int32 types fixed!")
