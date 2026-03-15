use std::sync::{Arc, Mutex};
use std::time::Duration;
use tauri::{AppHandle, Manager, Emitter};
use iceoryx2::prelude::*;

// Shared state for the Tauri frontend
pub struct IpcState {
    pub connected: bool,
    pub backend: String,
    pub messages_received: u64,
}

#[tauri::command]
pub fn get_ipc_status(state: tauri::State<Arc<Mutex<IpcState>>>) -> String {
    let s = state.lock().unwrap();
    format!("{{\"connected\": {}, \"backend\": \"{}\", \"messages_received\": {}}}", 
            s.connected, s.backend, s.messages_received)
}

pub fn init_ipc(app: &AppHandle) {
    let state = Arc::new(Mutex::new(IpcState { 
        connected: false,
        backend: "iceoryx2".to_string(),
        messages_received: 0,
    }));
    app.manage(state.clone());
    
    // Attempt to initialize Iceoryx2 node
    let node_name = format!("nexus_ui_{}", std::process::id());
    
    let app_handle = app.clone();
    let state_clone = state.clone();
    
    // Spawn background thread to initialize and poll IPC
    std::thread::spawn(move || {
        // Wait a bit for the system to settle
        std::thread::sleep(Duration::from_millis(500));
        
        // Setup node
        let node_name_service = match ServiceName::new("wm/events") {
            Ok(name) => name,
            Err(_) => return,
        };
        
        let node = match NodeBuilder::new().create::<ipc::Service>() {
            Ok(n) => n,
            Err(e) => {
                println!("Failed to create IPC node: {:?}", e);
                let mut s = state_clone.lock().unwrap();
                s.backend = "fallback_ws".to_string();
                return;
            }
        };

        let mut s = state_clone.lock().unwrap();
        s.connected = true;
        drop(s);
        
        // Try to open the service created by the WhiteMagic core
        // In a real implementation we would loop and poll to connect to publisher
        let service = match node.service_builder(&node_name_service).publish_subscribe::<[u8]>().open_or_create() {
            Ok(s) => s,
            Err(_) => return,
        };
        
        let subscriber = match service.subscriber_builder().create() {
            Ok(s) => s,
            Err(_) => return,
        };
        
        // Poll loop
        loop {
            match subscriber.receive() {
                Ok(Some(sample)) => {
                    let mut s = state_clone.lock().unwrap();
                    s.messages_received += 1;
                    drop(s);
                    
                    // Convert payload to string (assuming JSON)
                    if let Ok(payload) = std::str::from_utf8(sample.payload()) {
                        let _ = app_handle.emit("wm-event", payload);
                    }
                }
                Ok(None) => {
                    // No data available, yield
                    std::thread::sleep(Duration::from_millis(10));
                }
                Err(_) => {
                    // Error reading
                    std::thread::sleep(Duration::from_millis(100));
                }
            }
        }
    });
}
