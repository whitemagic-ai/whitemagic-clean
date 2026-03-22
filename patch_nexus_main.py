
with open('nexus/src-tauri/src/main.rs') as f:
    content = f.read()

replacement = """// WhiteMagic Nexus — Tauri 2.0 Desktop Application
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

mod ipc;

fn main() {
    tauri::Builder::default()
        .setup(|app| {
            ipc::init_ipc(app.handle());
            Ok(())
        })
        .plugin(tauri_plugin_fs::init())
        .plugin(tauri_plugin_shell::init())
        .invoke_handler(tauri::generate_handler![ipc::get_ipc_status])
        .run(tauri::generate_context!())
        .expect("error while running WhiteMagic Nexus");
}
"""

with open('nexus/src-tauri/src/main.rs', 'w') as f:
    f.write(replacement)

print("Patched main.rs")
