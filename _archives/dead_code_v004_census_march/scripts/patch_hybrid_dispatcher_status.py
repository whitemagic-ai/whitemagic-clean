import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/hybrid_dispatcher_v2.py"

with open(file_path, "r") as f:
    content = f.read()

patch = """
        return {
            "overall_healthy": healthy,
            "pools": details,
            "python_available": True,
            "fast_brain": self.check_unified_fast_brain()
        }
"""

content = re.sub(r'        return \{\n            "overall_healthy": healthy,\n            "pools": details,\n            "python_available": True,\n        \}', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Patched hybrid dispatcher status hook")
