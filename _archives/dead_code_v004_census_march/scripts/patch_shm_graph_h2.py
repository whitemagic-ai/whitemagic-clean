
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_graph.h"

with open(file_path, "r") as f:
    content = f.read()

# I need to fix the walker: `active_count` is returning 0 because the first node is not triggering edges properly, or the ids don't match.
# Wait, I had: 
# int32_t src = *(int32_t*)(addr + offset);
# int32_t tgt = *(int32_t*)(addr + offset + 4);
# Let's add more active tracking and proper indexing later. For now, let's fix the basic loop.
