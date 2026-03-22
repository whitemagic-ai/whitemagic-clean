import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')
from whitemagic.core.acceleration.koka_native_bridge import koka_dispatch, get_koka_bridge
import time

print("Testing PRAT module...")
start = time.time()
res1 = koka_dispatch("prat", "route-prat", {"tool": "search_memories"})
print(f"PRAT Result ({time.time()-start:.4f}s):", res1)

print("Testing Gana module...")
start = time.time()
res2 = koka_dispatch("gana", "invoke-gana", {"gana": "gana_horn", "tool": "bootstrap", "args": {}})
print(f"Gana Result ({time.time()-start:.4f}s):", res2)

bridge = get_koka_bridge()
bridge.close()
