
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_runtime_v3.kk"

with open(file_path, "r") as f:
    content = f.read()

# Remove the invalid import from the middle of the file
content = content.replace("import std/core/list\n\n", "")

# Add it to the top of the file if not present
if "import std/core/list" not in content:
    content = content.replace("import gan_ying", "import std/core/list\nimport gan_ying")

with open(file_path, "w") as f:
    f.write(content)

print("unified_runtime_v3.kk patched successfully!")
