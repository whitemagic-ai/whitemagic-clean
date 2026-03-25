
with open('nexus/src-tauri/src/fs_api.rs', 'r') as f:
    content = f.read()

write_api = """
#[tauri::command]
pub fn write_file(file_path: String, content: String) -> Result<(), String> {
    fs::write(&file_path, content).map_err(|e| e.to_string())
}
"""

if "pub fn write_file" not in content:
    content += write_api
    with open('nexus/src-tauri/src/fs_api.rs', 'w') as f:
        f.write(content)

with open('nexus/src-tauri/src/main.rs', 'r') as f:
    main_content = f.read()

if "fs_api::write_file" not in main_content:
    main_content = main_content.replace("ipc::get_ipc_status, fs_api::list_directory, fs_api::read_file", "ipc::get_ipc_status, fs_api::list_directory, fs_api::read_file, fs_api::write_file")
    with open('nexus/src-tauri/src/main.rs', 'w') as f:
        f.write(main_content)

print("Added write_file to Rust backend")
