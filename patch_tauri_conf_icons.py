import json

with open('nexus/src-tauri/tauri.conf.json', 'r') as f:
    data = json.load(f)

# Remove the icon requirement or disable it
if "icon" in data["app"]:
    del data["app"]["icon"]
elif "icons" in data["app"]:
    del data["app"]["icons"]

# Tauri v2 bundle options usually have the icon
if "bundle" in data:
    if "icon" in data["bundle"]:
        del data["bundle"]["icon"]

with open('nexus/src-tauri/tauri.conf.json', 'w') as f:
    json.dump(data, f, indent=2)

print("Patched tauri.conf.json icons")
