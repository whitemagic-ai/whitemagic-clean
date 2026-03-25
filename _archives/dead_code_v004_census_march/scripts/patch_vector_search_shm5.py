import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    content = f.read()

# Fix the exact indentation error at line 208
patch = """
        results = []
        for mid,s in scored[:limit]:
            m = self._meta.get(mid,{})
            results.append(VSearchResult(memory_id=mid,score=s,title=m.get("title",""),snippet=m.get("snippet","")))
        return results

    def index_count(self) -> int: return len(self._cache)
"""

pattern = r'        results = \[\]\n        for mid,s in scored\[:limit\]:\n            m = self\._meta\.get\(mid,\{\}\)\n            results\.append\(VSearchResult\(memory_id=mid,score=s,title=m\.get\("title",""\),snippet=m\.get\("snippet",""\)\)\)\n        return results\n\n    def index_count\(self\) -> int: return len\(self\._cache\)'

content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("vector_search.py syntax fixed fully")
