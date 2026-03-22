
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_graph.h"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace('"{\\\\"nodes_visited\\\\":%d,\\\\"edges_traversed\\\\":%d}"', '"{\\"nodes_visited\\":%d,\\"edges_traversed\\":%d}"')

with open(file_path, "w") as f:
    f.write(content)

print("shm_graph.h quotes fixed")
