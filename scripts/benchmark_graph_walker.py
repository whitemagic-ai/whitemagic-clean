import logging
import sys
import time

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')
logging.getLogger("whitemagic").setLevel(logging.WARNING)

import os

from whitemagic.core.memory.db_manager import get_db_pool
from whitemagic.core.memory.graph_walker import get_graph_walker


def main():
    db_pool = get_db_pool(os.path.expanduser("~/.whitemagic/memory/whitemagic.db"))

    walker = get_graph_walker()

    print("Running Python Baseline Graph Walker...")
    # Pick a random node with some edges
    with db_pool.connection() as conn:
        with conn:
            cur = conn.execute("SELECT source_id FROM associations LIMIT 1")
            row = cur.fetchone()
            if not row:
                print("No edges found in DB.")
                return
            start_node = row[0]

    times = []

    # Warmup
    _ = walker.walk([start_node], hops=3, top_k=20)

    for _ in range(10):
        start = time.perf_counter()
        res = walker.walk([start_node], hops=3, top_k=20)
        end = time.perf_counter()
        times.append((end - start) * 1000)

    avg = sum(times) / len(times)

    print(f"Python Walker walked {res.unique_nodes_visited} nodes, {res.paths_explored} paths in {avg:.2f}ms (avg over 10 runs)")

if __name__ == "__main__":
    main()
