import re
from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic/core/immune/pattern_immunity.py")
if file_path.exists():
    content = file_path.read_text()

    import_statement = "from whitemagic.core.autonomous.unified_nervous_system import get_nervous_system, BiologicalEvent, BiologicalSubsystem\n"
    if "get_nervous_system" not in content:
        content = content.replace("import logging\n", "import logging\n" + import_statement)

    detect_pattern = r"(def detect_threat\(self, pattern: str\) -> bool:\n\s+\"\"\"Evaluate if a pattern matches known threat signatures.\"\"\"\n\s+is_threat = self\._evaluate\(pattern\))"
    replacement = r"""def detect_threat(self, pattern: str) -> bool:
        \"\"\"Evaluate if a pattern matches known threat signatures.\"\"\"
        is_threat = self._evaluate(pattern)
        if is_threat:
            try:
                ns = get_nervous_system()
                ns.emit(
                    event_type="immune.threat_detected",
                    source=BiologicalSubsystem.IMMUNE,
                    target=BiologicalSubsystem.APOTHEOSIS,
                    payload={"pattern": pattern, "severity": "high"}
                )
            except Exception:
                pass"""
    
    if "detect_threat" in content:
        content = re.sub(detect_pattern, replacement, content)
        file_path.write_text(content)
        print("pattern_immunity.py patched successfully.")
    else:
        print("Could not find detect_threat method.")
else:
    print("pattern_immunity.py not found.")
