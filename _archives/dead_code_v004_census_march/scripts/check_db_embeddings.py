import sqlite3
import numpy as np

conn = sqlite3.connect("/home/lucas/.whitemagic/memory/whitemagic.db")
cur = conn.cursor()
cur.execute("SELECT memory_id, embedding FROM memory_embeddings LIMIT 5")
rows = cur.fetchall()

for row in rows:
    mem_id = row[0]
    blob = row[1]
    if blob:
        vec = np.frombuffer(blob, dtype=np.float32)
        print(f"{mem_id}: {vec[:5]}")
