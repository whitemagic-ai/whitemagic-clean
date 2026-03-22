import os
import sqlite3

db_path = os.path.expanduser("~/.whitemagic/memory/whitemagic.db")
db = sqlite3.connect(db_path)
cursor = db.cursor()
rows = cursor.execute("SELECT memory_id, embedding FROM memory_embeddings").fetchall()
print(f"Found {len(rows)} embeddings.")

sizes = {}
for r in rows:
    data = r[1]
    n = len(data) // 4
    if n not in sizes:
        sizes[n] = 0
    sizes[n] += 1

print("Embedding dimensions in DB:", sizes)
