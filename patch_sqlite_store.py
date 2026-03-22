import re

with open('whitemagic/core/memory/sqlite_backend.py') as f:
    content = f.read()

# Make sure sutra_bridge is imported
if "from whitemagic.core.bridge.sutra_bridge import get_sutra_kernel" not in content:
    content = content.replace("from whitemagic.security.zodiac.ledger import get_ledger", "from whitemagic.security.zodiac.ledger import get_ledger\nfrom whitemagic.core.bridge.sutra_bridge import get_sutra_kernel")

# Add the sutra check to store()
replacement = """    def store(self, memory: Memory, content_hash: str | None = None) -> str:
        \"\"\"Store or update a memory.\"\"\"

        # 0. Rust Sutra Kernel Check (Ahimsa/Satya/Harmony)
        sutra = get_sutra_kernel()
        verdict = sutra.evaluate_action(
            action_type="memory_store",
            intent_score=1.0,
            karma_debt=0.0
        )
        if verdict.startswith("Panic"):
            import logging
            logging.getLogger(__name__).critical(f"SUTRA KERNEL PANIC: {verdict}")
            raise RuntimeError(verdict)

        # 1. Cryptographic Ledger Record"""

content = re.sub(r'    def store\(self, memory: Memory, content_hash: str \| None = None\) -> str:\n        """Store or update a memory."""\n        # 1. Cryptographic Ledger Record', replacement, content)

with open('whitemagic/core/memory/sqlite_backend.py', 'w') as f:
    f.write(content)

print("Patched sqlite_backend.py")
