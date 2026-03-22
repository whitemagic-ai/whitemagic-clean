
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix duplicate definition
content = content.replace("fun extract-op(line: string): string\n\nfun extract-op(line: string): string", "fun extract-op(line: string): string")

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk syntax fixed again!")
