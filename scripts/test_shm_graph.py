import sys
import logging
import time

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')
logging.basicConfig(level=logging.INFO)

from whitemagic.core.memory.shm_manager import get_shm_manager
from whitemagic.core.memory.shm_graph import get_shm_graph
from whitemagic.core.memory.db_manager import get_db_pool
import os

def main():
    db_pool = get_db_pool(os.path.expanduser("~/.whitemagic/memory/whitemagic.db"))
    
    shm_embs = get_shm_manager()
    print("Syncing embeddings to build UUID mapping...")
    start = time.perf_counter()
    shm_embs.sync_from_db(db_pool)
    print(f"Embedding sync took {(time.perf_counter() - start)*1000:.2f}ms")
    
    # Pass the UUID to Int ID map to the Graph builder
    uuid_to_id = shm_embs._uuid_to_id
    
    shm_graph = get_shm_graph()
    print("Syncing graph edges to SHM...")
    start = time.perf_counter()
    shm_graph.sync_from_db(db_pool, uuid_to_id)
    print(f"Graph sync took {(time.perf_counter() - start)*1000:.2f}ms")
    
if __name__ == "__main__":
    main()
