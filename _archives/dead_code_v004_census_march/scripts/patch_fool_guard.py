import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/intelligence/agentic/fool_guard.py"

with open(file_path, "r") as f:
    content = f.read()

patch = """
    def check_rigidity(self, current_resonance: float) -> bool:
        \"\"\"Add resonance to history and check if it's too static at a high level.\"\"\"
        self.resonance_history.append(current_resonance)
        if len(self.resonance_history) > self.window_size:
            self.resonance_history.pop(0)

        if len(self.resonance_history) < self.window_size:
            return False

        avg = sum(self.resonance_history) / self.window_size
        variance = sum((x - avg)**2 for x in self.resonance_history) / self.window_size

        if avg > self.threshold and variance < 0.001:
            # We are stuck in high-resonance groupthink
            # Check the SutraCode Kernel
            try:
                import whitemagic_rust
                if hasattr(whitemagic_rust, 'sutra_kernel'):
                    kernel = whitemagic_rust.sutra_kernel.SutraKernel()
                    if kernel.is_compromised():
                        self.trigger_apoptosis()
                        return True
            except Exception:
                pass
                
            return True
        return False
        
    def trigger_apoptosis(self) -> None:
        \"\"\"Programmed cell death - terminate execution environment if kernel compromised.\"\"\"
        import os
        import signal
        import logging
        logger = logging.getLogger(__name__)
        logger.critical("SUTRACODE KERNEL COMPROMISED. TRIGGERING APOPTOSIS.")
        logger.critical("Fool's Guard executing SIGKILL on current process.")
        
        # In a real deployed environment, this kills the container/process.
        os.kill(os.getpid(), signal.SIGKILL)
"""

pattern = r'    def check_rigidity\(self, current_resonance: float\) -> bool:\n        """Add resonance to history and check if it\'s too static at a high level."""\n        self\.resonance_history\.append\(current_resonance\)\n        if len\(self\.resonance_history\) > self\.window_size:\n            self\.resonance_history\.pop\(0\)\n\n        if len\(self\.resonance_history\) < self\.window_size:\n            return False\n\n        avg = sum\(self\.resonance_history\) / self\.window_size\n        variance = sum\(\(x - avg\)\*\*2 for x in self\.resonance_history\) / self\.window_size\n\n        if avg > self\.threshold and variance < 0\.001:\n            # We are stuck in high-resonance groupthink\n            return True\n        return False'

new_content = re.sub(pattern, patch.lstrip(), content, flags=re.MULTILINE)

with open(file_path, "w") as f:
    f.write(new_content)

print("fool_guard.py patched successfully!")
