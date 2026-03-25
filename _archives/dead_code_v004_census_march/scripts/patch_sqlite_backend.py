import re
from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic/core/memory/sqlite_backend.py")
content = file_path.read_text()

# Fix the imports to use the correct autonomous nervous system
import_pattern = r"from whitemagic.core.biology.nervous_system import get_nervous_system, BiologicalEvent, EventType"
replacement = r"from whitemagic.core.autonomous.unified_nervous_system import get_nervous_system, BiologicalEvent, BiologicalSubsystem"
content = content.replace(import_pattern, replacement)

# Fix the nervous system broadcast call
store_pattern = r"(ns\.broadcast\(BiologicalEvent\(\n\s+event_type=EventType\.MEMORY_STORED,\n\s+source_system=\"sqlite_backend\",\n\s+payload={\"memory_id\": memory\.id, \"importance\": memory\.importance}\n\s+\)\))"
new_broadcast = r"""ns.broadcast(BiologicalEvent(
            event_type="memory.stored",
            source=BiologicalSubsystem.METABOLISM,
            target=BiologicalSubsystem.APOTHEOSIS,
            payload={"memory_id": memory.id, "importance": memory.importance}
        ))"""
content = re.sub(store_pattern, new_broadcast, content)

file_path.write_text(content)
print("sqlite_backend.py patched successfully with correct nervous system.")
