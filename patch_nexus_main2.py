
with open('nexus/src-tauri/src/main.rs') as f:
    content = f.read()

content = content.replace("mod ipc;", "mod ipc;\nmod fs_api;")
content = content.replace("ipc::get_ipc_status", "ipc::get_ipc_status, fs_api::list_directory, fs_api::read_file")

with open('nexus/src-tauri/src/main.rs', 'w') as f:
    f.write(content)

print("Patched main.rs with fs_api")
