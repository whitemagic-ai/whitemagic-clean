
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the field accessor issue in `format-results`. Since `id` is a built-in Koka function,
# accessing `r.id` without `search-result/id` can be ambiguous if Koka infers `r.id` as calling the global `id`.
content = content.replace("r.id", "r.search-result/id")
content = content.replace("r.score", "r.search-result/score")
# And also in the other places
content = content.replace("item.score", "item.search-result/score")
content = content.replace("x.score", "x.search-result/score")

with open(file_path, "w") as f:
    f.write(content)

print("Patched shm_search.kk identifiers!")
