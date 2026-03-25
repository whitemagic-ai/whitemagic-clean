
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Change the signature to include <div,ndet> or just remove it.
# We'll change it to `fun search-memories(..., best-results: list<search-result>) : div list<search-result>`
content = content.replace(
    "fun search-memories(addr: int64, query-off: int, count: int, top-k: int, current-idx: int, best-results: list<search-result>): list<search-result>",
    "fun search-memories(addr: int64, query-off: int, count: int, top-k: int, current-idx: int, best-results: list<search-result>)"
)

# same for insert-sorted
content = content.replace(
    "fun insert-sorted(item: search-result, lst: list<search-result>, max-size: int): list<search-result>",
    "fun insert-sorted(item: search-result, lst: list<search-result>, max-size: int)"
)

with open(file_path, "w") as f:
    f.write(content)

print("Patched shm_search.kk types!")
