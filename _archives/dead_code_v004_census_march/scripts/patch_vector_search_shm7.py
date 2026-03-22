
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/vector_search.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i in range(len(lines)):
    lines[i] = lines[i].replace("\t", "    ")

with open(file_path, "w") as f:
    f.writelines(lines)

print("Tabs removed!")
