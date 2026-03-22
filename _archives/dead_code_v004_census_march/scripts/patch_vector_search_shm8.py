
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

new_lines = []
skip = False
for line in lines:
    if line.startswith("    def search("):
        skip = True
        
        # Insert our correct search function here
        search_func = """    def search(self, query: str, limit: int = 10) -> list[VSearchResult]:
        if not _sbert_model: return []
        qvec = self._encode([query])[0]
        scored = []
        
        # 1. Try Koka Shared Memory Bridge (Native C AVX2) - Fastest!
        try:
            from whitemagic.core.memory.shm_manager import get_shm_manager
            from whitemagic.core.acceleration.koka_native_bridge import get_koka_bridge
            
            shm = get_shm_manager()
            bridge = get_koka_bridge()
            
            if shm.get_count() == 0:
                from whitemagic.core.memory.db_manager import get_db_pool
                shm.sync_from_db(get_db_pool())
                
            if bridge.is_available("shm_search") and shm.get_count() > 0:
                query_idx = shm.get_count() + 1
                shm.write_query(query_idx, qvec)
                
                res = bridge.dispatch("shm_search", "search", {"query_id": query_idx})
                
                if res and res.get("status") == "ok":
                    results = []
                    for item in res.get("results", []):
                        if len(results) >= limit: break
                        mem_id = shm.get_uuid(item["id"])
                        if mem_id:
                            m = self._meta.get(mem_id, {})
                            results.append(VSearchResult(
                                memory_id=mem_id,
                                score=item["score"],
                                title=m.get("title", ""),
                                snippet=m.get("snippet", "")
                            ))
                    if results:
                        return results
        except Exception as e:
            import logging
            logging.getLogger(__name__).warning(f"Koka SHM Search failed: {e}")

        with self._lock:
            # Try Zig SIMD batch top-K for large corpora
            if len(self._cache) > 50:
                try:
                    from whitemagic.core.acceleration.simd_vector_batch import batch_topk_cosine
                    ids = list(self._cache.keys())
                    vecs = list(self._cache.values())
                    topk = batch_topk_cosine(qvec, vecs, limit)
                    scored = [(ids[idx], score) for idx, score in topk]
                except Exception:
                    scored = []
            if not scored:
                for mid, vec in self._cache.items():
                    s = _cosine(qvec, vec)
                    scored.append((mid, s))
                scored.sort(key=lambda x: x[1], reverse=True)
                
        results = []
        for mid, s in scored[:limit]:
            m = self._meta.get(mid, {})
            results.append(VSearchResult(
                memory_id=mid,
                score=s,
                title=m.get("title", ""),
                snippet=m.get("snippet", "")
            ))
        return results

"""
        new_lines.append(search_func)
        continue
    
    if skip and line.startswith("    def index_count("):
        skip = False
        
    if not skip:
        new_lines.append(line)

with open(file_path, "w") as f:
    f.writelines(new_lines)

print("vector_search.py cleanly rewritten")
