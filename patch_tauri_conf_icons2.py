import json

with open('nexus/src-tauri/tauri.conf.json') as f:
    data = json.load(f)

# Clear app properties that might require icons
if "app" in data:
    if "trayIcon" in data["app"]:
        del data["app"]["trayIcon"]

with open('nexus/src-tauri/tauri.conf.json', 'w') as f:
    json.dump(data, f, indent=2)

print("Patched tauri.conf.json icons part 2")
