import sqlite3

conn = sqlite3.connect("/home/lucas/.whitemagic/memory/whitemagic.db")
cur = conn.cursor()
cur.execute("PRAGMA table_info(associations)")
print(cur.fetchall())
