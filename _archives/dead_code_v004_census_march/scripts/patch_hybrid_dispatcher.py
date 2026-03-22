
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/hybrid_dispatcher_v2.py"

with open(file_path, "r") as f:
    content = f.read()

patch = """
    # Unified Fast Brain Hook
    def check_unified_fast_brain(self) -> dict:
        \"\"\"Poll the Unified Fast Brain for its status via Elixir or direct Koka check.\"\"\"
        try:
            from whitemagic.core.acceleration.koka_native_bridge import get_koka_bridge
            b = get_koka_bridge()
            if "unified_fast_brain" in b._binaries:
                return {"active": True, "shm_ring": True}
        except Exception:
            pass
        return {"active": False}
"""

content = content.replace('    def health_check(self) -> dict:', patch.strip('\n') + '\n\n    def health_check(self) -> dict:')

with open(file_path, "w") as f:
    f.write(content)

print("Patched hybrid dispatcher to support Unified Fast Brain check")
