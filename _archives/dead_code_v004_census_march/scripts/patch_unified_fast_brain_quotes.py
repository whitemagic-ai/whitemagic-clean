
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.h"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace('"{\\\\"event_type\\\\":%d,\\\\"sender_hash\\\\":%d,\\\\"timestamp\\\\":%f,\\\\"payload\\\\":%s}"', '"{\\"event_type\\":%d,\\"sender_hash\\":%d,\\"timestamp\\":%f,\\"payload\\":%s}"')
content = content.replace('"{\\\\"nodes_visited\\\\":0,\\\\"edges_traversed\\\\":0}"', '"{\\"nodes_visited\\":0,\\"edges_traversed\\":0}"')
content = content.replace('"{\\\\"nodes_visited\\\\":%d,\\\\"edges_traversed\\\\":%d}"', '"{\\"nodes_visited\\":%d,\\"edges_traversed\\":%d}"')

with open(file_path, "w") as f:
    f.write(content)

print("Fixed quotes in unified fast brain")
