import json

with open('nexus/src-tauri/tauri.conf.json') as f:
    data = json.load(f)

# Find icon.png and remove it
if "app" in data and "windows" in data["app"]:
    for window in data["app"]["windows"]:
        if "iconPath" in window:
            del window["iconPath"]
        if "iconAsTemplate" in window:
            del window["iconAsTemplate"]

with open('nexus/src-tauri/tauri.conf.json', 'w') as f:
    json.dump(data, f, indent=2)

print("Patched tauri.conf.json icons part 3")
