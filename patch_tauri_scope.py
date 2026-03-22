import json

with open('nexus/src-tauri/tauri.conf.json') as f:
    data = json.load(f)

# Need to configure the FS scope properly for Tauri V2
data["app"]["security"] = {
    "assetProtocol": {
        "enable": True,
        "scope": ["**"]
    }
}

with open('nexus/src-tauri/tauri.conf.json', 'w') as f:
    json.dump(data, f, indent=2)

print("Updated FS scope in tauri.conf.json")
