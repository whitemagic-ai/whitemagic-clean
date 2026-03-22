
with open('whitemagic/core/memory/embeddings.py') as f:
    content = f.read()

# Replace whitemagic_rs import and function call
content = content.replace("import whitemagic_rs", "import whitemagic_rust")
content = content.replace("whitemagic_rs.simhash_lsh.simhash_find_duplicates", "whitemagic_rust.simhash_lsh.simhash_find_duplicates")

with open('whitemagic/core/memory/embeddings.py', 'w') as f:
    f.write(content)

print("Patched imports.")
