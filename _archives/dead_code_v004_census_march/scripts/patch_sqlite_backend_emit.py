import re
from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/sqlite_backend.py")
content = file_path.read_text()

# Fix the nervous system broadcast call to use emit
store_pattern = r"(ns\.broadcast\(BiologicalEvent\(\n\s+event_type=\"memory\.stored\",\n\s+source=BiologicalSubsystem\.METABOLISM,\n\s+target=BiologicalSubsystem\.APOTHEOSIS,\n\s+payload={\"memory_id\": memory\.id, \"importance\": memory\.importance}\n\s+\)\))"
new_emit = r"""ns.emit(
            event_type="memory.stored",
            source=BiologicalSubsystem.METABOLISM,
            target=BiologicalSubsystem.APOTHEOSIS,
            payload={"memory_id": memory.id, "importance": memory.importance}
        )"""
content = re.sub(store_pattern, new_emit, content)

file_path.write_text(content)
print("sqlite_backend.py patched successfully to use emit.")
