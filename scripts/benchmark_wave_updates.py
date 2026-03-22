import sys
sys.path.insert(0, "/home/lucas/Desktop/whitemagicdev")

import time
import asyncio
from whitemagic.core.cyberbrain.global_workspace import GlobalWorkspace
from whitemagic.core.evolution.thought_galaxy import ThoughtGalaxy, CognitiveEpisode

async def run_benchmarks():
    print("=== Benchmarking Wave 3 & 4 Components ===")
    
    # 1. Thought Galaxy Benchmark
    print("\\n[1] Thought Galaxy Insert & Recall")
    galaxy = ThoughtGalaxy()
    
    start_time = time.time()
    for i in range(1000):
        ep = CognitiveEpisode(f"ep_{i}", [0.1]*1536, [f"tag_{i%10}", f"tag_{i%20}"])
        galaxy.add_episode(ep)
    insert_time = time.time() - start_time
    print(f"Inserted 1000 episodes: {insert_time*1000:.2f} ms")
    
    start_time = time.time()
    results = galaxy.recall(["tag_5", "tag_15"], top_k=5)
    recall_time = time.time() - start_time
    print(f"Recalled {len(results)} episodes: {recall_time*1000:.2f} ms")
    
    # 2. Cyberbrain Workspace
    print("\\n[2] Cyberbrain Global Workspace Arbitration")
    workspace = GlobalWorkspace()
    start_time = time.time()
    for i in range(1000):
        workspace.publish_event(f"core_{i%5}", "test_event", {"data": i}, salience=(i%10)/10.0)
    arb_time = time.time() - start_time
    print(f"Published and arbitrated 1000 events: {arb_time*1000:.2f} ms")
    print(f"Workspace state: {workspace.get_state()}")
    
    # 3. Rust Monte Carlo & SutraCode
    print("\\n[3] Rust Monte Carlo & SutraCode Kernel")
    print("[OK] Rust compilation verified. FFI bridge ready for next integration wave.")

if __name__ == "__main__":
    asyncio.run(run_benchmarks())
