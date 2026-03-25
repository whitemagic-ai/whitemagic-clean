import re

with open('whitemagic-rust/src/ipc_bridge.rs', 'r') as f:
    content = f.read()

# Change the return types of the pyfunctions
content = content.replace("pub fn ipc_init(node_name: &str) -> Result<(), String> {", "pub fn ipc_init(node_name: &str) -> PyResult<()> {\n    iox2::init_node(node_name).map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(e))?;\n    IPC_STATS.initialized.store(true, Ordering::Release);\n    Ok(())")
content = content.replace("    iox2::init_node(node_name)?;\n    IPC_STATS.initialized.store(true, Ordering::Release);\n    Ok(())", "")

content = content.replace("pub fn ipc_publish(channel: &str, payload: &[u8]) -> Result<u64, String> {", "pub fn ipc_publish(channel: &str, payload: &[u8]) -> PyResult<u64> {\n    iox2::publish(channel, payload).map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(e))")
content = content.replace("    iox2::publish(channel, payload)", "")

# For status, return a HashMap of String to String (JSON strings)
content = content.replace("pub fn ipc_status() -> HashMap<String, serde_json::Value> {", "pub fn ipc_status() -> HashMap<String, String> {")
content = content.replace("serde_json::json!(", "serde_json::json!(") # Let's rewrite the status func completely

status_func = """pub fn ipc_status() -> HashMap<String, String> {
    let mut status = HashMap::new();
    status.insert("backend".to_string(), (if iox2::is_available() { "iceoryx2" } else { "fallback" }).to_string());
    status.insert("initialized".to_string(), IPC_STATS.initialized.load(Ordering::Relaxed).to_string());
    status.insert("published".to_string(), IPC_STATS.published.load(Ordering::Relaxed).to_string());
    status.insert("received".to_string(), IPC_STATS.received.load(Ordering::Relaxed).to_string());
    status.insert("errors".to_string(), IPC_STATS.errors.load(Ordering::Relaxed).to_string());
    
    #[cfg(feature = "iceoryx2")]
    status.insert("iceoryx2_compiled".to_string(), "true".to_string());
    #[cfg(not(feature = "iceoryx2"))]
    status.insert("iceoryx2_compiled".to_string(), "false".to_string());
    
    status.insert("channels".to_string(), format!("[{}, {}, {}, {}]", CHANNEL_EVENTS, CHANNEL_MEMORIES, CHANNEL_COMMANDS, CHANNEL_HARMONY));
    
    status
}"""

content = re.sub(r'pub fn ipc_status[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}[^}]+}', status_func, content)

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
