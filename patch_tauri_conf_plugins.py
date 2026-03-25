import json

with open('nexus/src-tauri/tauri.conf.json', 'r') as f:
    data = json.load(f)

if "plugins" in data:
    del data["plugins"]

with open('nexus/src-tauri/tauri.conf.json', 'w') as f:
    json.dump(data, f, indent=2)

print("Removed plugins config from tauri.conf.json")
