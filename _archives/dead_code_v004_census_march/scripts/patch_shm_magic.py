
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Update the magic number in Koka to match Python (0x574D4B4B == 1464683339)
# The previous value in Koka was 1464264013 (0x5746E54D -> "WMEM")
# Python uses "WMKK"
content = content.replace("val magic-number = 1464264013", "val magic-number = 1464683339")

with open(file_path, "w") as f:
    f.write(content)

print("shm_consumer.kk magic number fixed!")
