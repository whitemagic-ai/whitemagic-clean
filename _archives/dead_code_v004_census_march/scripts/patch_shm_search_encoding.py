
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "rb") as f:
    content = f.read()

# Filter out non-ascii characters that are breaking the Koka compiler's Haskell backend text encoding
clean_content = content.decode('utf-8', errors='ignore')
clean_content = clean_content.replace('─', '-')
clean_content = clean_content.replace('═', '=')
clean_content = clean_content.encode('ascii', errors='ignore').decode('ascii')

with open(file_path, "w") as f:
    f.write(clean_content)

print("shm_search.kk encoding fixed!")
