
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the weird trailing dashes caused by the encoding fix script
content = content.replace("else new-lst-------------------------------------------------------------", "else new-lst")

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk syntax fixed!")
