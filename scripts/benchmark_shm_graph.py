import subprocess
import time
import json
import sys
import os

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

from whitemagic.core.memory.shm_graph import get_shm_graph
from whitemagic.core.memory.db_manager import get_db_pool

def main():
    db_pool = get_db_pool(os.path.expanduser("~/.whitemagic/memory/whitemagic.db"))
    
    shm_graph = get_shm_graph()
    shm_graph.initialize()
    print("Syncing graph to SHM...")
    shm_graph.sync_from_db(db_pool) # Force sync so we populate uuid_to_id

    # Walk 100 random valid start nodes
    start_nodes = []
    with db_pool.connection() as conn:
        with conn:
            cur = conn.execute("SELECT source_id FROM associations LIMIT 5000")
            rows = cur.fetchall()
            for row in rows:
                if row[0] in shm_graph.uuid_to_id:
                    start_nodes.append(shm_graph.uuid_to_id[row[0]])
                    if len(start_nodes) >= 100:
                        break

    if not start_nodes:
        print("No start nodes found!")
        return

    print(f"Walking {len(start_nodes)} start nodes...")

    print("Starting Koka SHM Graph Walker...")
    proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/shm_graph'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=True,
        bufsize=1
    )
    
    proc.stdout.readline()
    proc.stdout.readline()
    
    times = []
    total_nodes = 0
    total_edges = 0
    
    for start_node_id in start_nodes:
        start = time.perf_counter()
        proc.stdin.write(f'{{"op":"walk", "start_id": {start_node_id}}}\n')
        proc.stdin.flush()
        res = proc.stdout.readline().strip()
        end = time.perf_counter()
        times.append((end - start) * 1000)
        
        try:
            data = json.loads(res)
            total_nodes += data.get("results", {}).get("nodes_visited", 0)
            total_edges += data.get("results", {}).get("edges_traversed", 0)
        except Exception:
            pass
        
    avg = sum(times) / len(times)
    
    print(f"Koka SHM Walker Results (Total): {total_nodes} nodes, {total_edges} edges")
    print(f"Koka SHM Walker took {avg:.2f}ms (avg over {len(start_nodes)} runs)")
    
    proc.stdin.write('{"op":"quit"}\n')
    proc.stdin.flush()
    proc.kill()

if __name__ == "__main__":
    main()
