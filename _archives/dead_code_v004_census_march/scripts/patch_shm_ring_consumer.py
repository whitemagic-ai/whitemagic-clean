
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_ring_consumer.h"

with open(file_path, "r") as f:
    content = f.read()

# Fix the quotes
content = content.replace('"{\\\\"event_type\\\\":%d,\\\\"sender_hash\\\\":%d,\\\\"timestamp\\\\":%f,\\\\"payload\\\\":\\\\"%s\\\\"}"', '"{\\"event_type\\":%d,\\"sender_hash\\":%d,\\"timestamp\\":%f,\\"payload\\":\\"%s\\"}"')

# Also fix kk_integer_clamp_int to kk_integer_clamp32
file2 = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_ring_consumer.kk"
with open(file2, "r") as f:
    kk_content = f.read()

kk_content = kk_content.replace('kk_integer_clamp_int(us, kk_context())', 'kk_integer_clamp32(us, kk_context())')

with open(file_path, "w") as f:
    f.write(content)

with open(file2, "w") as f:
    f.write(kk_content)

print("Patched ring consumer files")
