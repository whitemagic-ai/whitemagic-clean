
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_native_bridge.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if "def is_available" in line and not line.startswith("    def is_available"):
        lines[i] = "    " + line

with open(file_path, "w") as f:
    f.writelines(lines)

print("Indentation patched 2")
