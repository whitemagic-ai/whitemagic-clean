with open('whitemagic-rust/src/ipc_bridge.rs') as f:
    content = f.read()

import re

# Just replace the whole function cleanly
func_new = """#[pyfunction]
pub fn ipc_status() -> HashMap<String, String> {
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

content = re.sub(r'pub fn ipc_status\(\) -> HashMap<String, String> \{[\s\S]*?^}', func_new, content, flags=re.MULTILINE)

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)
