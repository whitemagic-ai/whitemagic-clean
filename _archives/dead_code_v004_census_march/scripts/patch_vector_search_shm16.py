
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if "def index_memory(" in line:
        patch = """    def index_memory(self, memory_id: str, content: str, title: str = "") -> None:
        vecs = self._encode([content[:5000]])
        vec = vecs[0]
        blob = struct.pack(f"{len(vec)}f",*vec)
        snip = content[:300]
        with sqlite3.connect(self._db) as c:
            c.execute("INSERT OR REPLACE INTO embeddings(memory_id,vector,title,snippet) VALUES(?,?,?,?)",(memory_id,blob,title,snip))
        with self._lock:
            self._cache[memory_id]=vec
            self._meta[memory_id]={"title":title,"snippet":snip}
            
            # Sync to Koka SHM Engine
            try:
                from whitemagic.core.memory.shm_manager import get_shm_manager
                shm = get_shm_manager()
                shm.add_or_update(memory_id, vec)
            except Exception as e:
                import logging
                logging.getLogger(__name__).warning(f"Failed to sync embedding to SHM: {e}")
"""
        
        # Replace the function body
        lines[i:i+10] = [patch]
        break

with open(file_path, "w") as f:
    f.writelines(lines)

print("vector_search.py index_memory updated to sync SHM!")
