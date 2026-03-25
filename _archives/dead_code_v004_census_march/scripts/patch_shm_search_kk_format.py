
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Add back the search-result struct since we accidentally removed it with the Search Logic cleanup!
patch = """
// ── Server Loop ──

struct search-result
  id: int
  score: float64

fun search-memories(addr: int64, query-off: int, count: int, top-k: int, current-idx: int, best-results: list<search-result>): div list<search-result>
  if current-idx >= count then best-results
  else
    val item-off = header-size + (current-idx * slot-size)
    val item-id = shm-read-int(addr, item-off)
    val vec-off = item-off + 4
    
    val score = shm-cosine-sim(addr, query-off, vec-off, embedding-dim)
    
    val new-result = Search-result(item-id, score)
    val new-best = insert-sorted(new-result, best-results, top-k)
    
    search-memories(addr, query-off, count, top-k, current-idx + 1, new-best)

fun insert-sorted(item: search-result, lst: list<search-result>, max-size: int): list<search-result>
  match lst
    Nil -> [item]
    Cons(x, xs) ->
      if item.search-result/score > x.search-result/score then
        val new-lst = Cons(item, lst)
        if new-lst.length > max-size then new-lst.take(max-size) else new-lst
      else
        val new-lst = Cons(x, insert-sorted(item, xs, max-size))
        if new-lst.length > max-size then new-lst.take(max-size) else new-lst
"""

content = content.replace("// ── Server Loop ──", patch.strip())

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk struct restored!")
