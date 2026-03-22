import re

with open('whitemagic/core/memory/embeddings.py') as f:
    content = f.read()

# Look for _load_vec_cache and replace the np.array creation
pattern = r"            ids = \[r\[0\] for r in rows\]\n            # Unpack all blobs into a single contiguous float32 array\n            vecs = np\.array\(\n                \[_unpack_embedding\(r\[1\]\) for r in rows\],\n                dtype=np\.float32,\n            \)"

replacement = """            # Filter by embedding dimension (avoid inhomogeneous shape errors)
            valid_ids = []
            valid_vecs = []
            for r in rows:
                vec = _unpack_embedding(r[1])
                if len(vec) == EMBEDDING_DIM:
                    valid_ids.append(r[0])
                    valid_vecs.append(vec)

            ids = valid_ids
            # Unpack all blobs into a single contiguous float32 array
            vecs = np.array(
                valid_vecs,
                dtype=np.float32,
            )"""

if pattern in content:
    print("Match found!")
else:
    print("Match not found, using regex.")

new_content = re.sub(pattern, replacement, content)
with open('whitemagic/core/memory/embeddings.py', 'w') as f:
    f.write(new_content)

print("Patched.")
