// WhiteMagic Nexus — Tauri 2.0 Desktop Application
#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

mod ipc;
mod fs_api;

fn main() {
    tauri::Builder::default()
        .setup(|app| {
            ipc::init_ipc(app.handle());
            Ok(())
        })
        .plugin(tauri_plugin_fs::init())
        .plugin(tauri_plugin_shell::init())
        .invoke_handler(tauri::generate_handler![ipc::get_ipc_status, fs_api::list_directory, fs_api::read_file, fs_api::write_file])
        .run(tauri::generate_context!())
        .expect("error while running WhiteMagic Nexus");
}
