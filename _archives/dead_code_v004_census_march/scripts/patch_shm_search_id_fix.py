
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Undo the previous bad patch
content = content.replace("r.search-result/id", "r.item-id")
content = content.replace("r.search-result/score", "r.score")
content = content.replace("item.search-result/score", "item.score")
content = content.replace("x.search-result/score", "x.score")

# Rename the struct field to avoid collision with built-in 'id'
content = content.replace("id: int", "item-id: int")
content = content.replace("Search-result(item-id, score)", "Search-result(item-id, score)") # this is fine
content = content.replace("Search-result(item_id, score)", "Search-result(item-id, score)") # just in case

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk fields renamed to avoid collision!")
