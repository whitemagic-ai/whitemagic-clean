import json

with open('nexus/src-tauri/tauri.conf.json', 'r') as f:
    data = json.load(f)

if "title" in data["app"]:
    del data["app"]["title"]

with open('nexus/src-tauri/tauri.conf.json', 'w') as f:
    json.dump(data, f, indent=2)

print("Patched tauri.conf.json")
