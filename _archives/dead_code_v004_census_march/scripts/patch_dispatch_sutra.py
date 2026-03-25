import re
from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic/tools/dispatch_table.py")
content = file_path.read_text()

import_statement = "import whitemagic_rust\nfrom whitemagic.security.zodiac.ledger import get_ledger\nfrom whitemagic.core.autonomous.unified_nervous_system import get_nervous_system, BiologicalEvent, BiologicalSubsystem\n"
content = content.replace("import logging\nimport time", "import logging\nimport time\n" + import_statement)

dispatch_pattern = r"(def dispatch\(tool_name: str, args: dict\[str, Any\]\) -> Any:\n\s+\"\"\"Execute a tool dynamically.\"\"\")"
replacement = r"""def dispatch(tool_name: str, args: dict[str, Any]) -> Any:
    \"\"\"Execute a tool dynamically.\"\"\"
    # 1. SUTRACODE KERNEL ENFORCEMENT
    try:
        kernel = whitemagic_rust.sutra_kernel.SutraKernel()
        # This will panic the entire Python process (via Rust) if a violation is detected
        kernel.verify_action("dispatch_router", tool_name, str(args))
    except Exception as e:
        # We only catch Python-level errors here. Rust panics will kill the process.
        import logging
        logging.getLogger(__name__).error(f"SutraCode Verification Error (Non-Fatal): {e}")

    # 2. ZODIAC LEDGER RECORDING
    try:
        ledger = get_ledger()
        ledger.record_action(
            actor_id="dispatch_router",
            action_type=f"tool_call:{tool_name}",
            payload=args
        )
    except Exception:
        pass"""

content = re.sub(dispatch_pattern, replacement, content)
file_path.write_text(content)
print("dispatch_table.py patched with SutraCode enforcement and Zodiac Ledger.")
