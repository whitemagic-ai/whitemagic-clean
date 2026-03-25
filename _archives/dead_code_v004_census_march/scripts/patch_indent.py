
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_native_bridge.py"

with open(file_path, "r") as f:
    lines = f.readlines()

for i, line in enumerate(lines):
    if "def _get_process" in line:
        if line.startswith("    def"): # 4 spaces
            lines[i] = line
        else:
            lines[i] = "    " + line.lstrip()

with open(file_path, "w") as f:
    f.writelines(lines)

print("Indentation patched")
