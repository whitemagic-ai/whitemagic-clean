
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/core/acceleration/koka_native_bridge.py"

with open(file_path, "r") as f:
    lines = f.readlines()

new_lines = []
for line in lines:
    if line.startswith("try:"):
        new_lines.append("            try:\n")
    else:
        new_lines.append(line)

with open(file_path, "w") as f:
    f.writelines(new_lines)

print("koka_native_bridge.py indentation fixed!")
