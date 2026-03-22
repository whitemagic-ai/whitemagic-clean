import re
from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic/core/dreaming/dream_cycle.py")
content = file_path.read_text()

# Import the nervous system
import_statement = "from whitemagic.core.autonomous.unified_nervous_system import get_nervous_system, BiologicalEvent, BiologicalSubsystem\n"
if "get_nervous_system" not in content:
    content = content.replace("import logging\nimport threading", "import logging\nimport threading\n" + import_statement)

# Find the run_loop to emit start/stop events
run_loop_pattern = r"(def _run_loop\(self\) -> None:\n\s+\"\"\"Background thread for dream cycles.\"\"\"\n\s+while self\._running:)"
replacement = r"""def _run_loop(self) -> None:
        \"\"\"Background thread for dream cycles.\"\"\"
        ns = get_nervous_system()
        ns.emit(
            event_type="dream.cycle_started",
            source=BiologicalSubsystem.DREAM,
            payload={"status": "watching for idle"}
        )
        while self._running:"""
content = re.sub(run_loop_pattern, replacement, content)

file_path.write_text(content)
print("dream_cycle.py patched successfully to emit nervous system events.")
