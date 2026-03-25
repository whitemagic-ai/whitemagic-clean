from whitemagic.security.zodiac.ledger import get_ledger
from whitemagic.core.memory.sqlite_backend import SQLiteBackend
from whitemagic.core.memory.unified_types import Memory, MemoryType
from pathlib import Path
import uuid

# Initialize the ledger
ledger = get_ledger()

# Test recording an action
entry = ledger.record_action(
    actor_id="test_user",
    action_type="system_test",
    payload={"msg": "Testing Zodiac Ledger"},
    context_id="test_context",
    consent_token="test_token"
)

print(f"Recorded entry: {entry.entry_id}")
print(f"Hash signature: {entry.hash_signature}")
print(f"Chain valid: {ledger.verify_chain()}")

# Check DB persistence
import sqlite3
conn = sqlite3.connect("/home/lucas/.whitemagic/memory/whitemagic.db")
row = conn.execute("SELECT * FROM zodiac_ledger WHERE entry_id = ?", (entry.entry_id,)).fetchone()
print(f"Found in DB: {row is not None}")

# Now test integration with sqlite_backend
db = SQLiteBackend(Path("/home/lucas/.whitemagic/memory/whitemagic.db"))

test_memory = Memory(
    id=f"test_mem_{uuid.uuid4()}",
    content="This is a test memory for the Zodiac Ledger integration.",
    memory_type=MemoryType.SHORT_TERM,
    is_private=False
)

memory_id = db.store(test_memory)
print(f"Stored memory: {memory_id}")

# Verify memory store triggered Zodiac
row2 = conn.execute("SELECT * FROM zodiac_ledger WHERE action_type = 'memory_store' AND payload LIKE ?", (f'%{test_memory.id}%',)).fetchone()
print(f"Memory store found in Zodiac DB: {row2 is not None}")
conn.close()
