import re

with open('whitemagic-rust/src/ipc_bridge.rs', 'r') as f:
    content = f.read()

# Fix the return type of ipc_publish to PyResult<()> and map string errors to PyErr
replacement = """#[pyfunction]
pub fn ipc_publish(channel: &str, payload: &[u8]) -> PyResult<()> {
    match iox2::publish(channel, payload) {
        Ok(()) => {
            IPC_STATS.published.fetch_add(1, Ordering::Relaxed);
            Ok(())
        }
        Err(e) => {
            IPC_STATS.errors.fetch_add(1, Ordering::Relaxed);
            Err(pyo3::exceptions::PyRuntimeError::new_err(e.to_string()))
        }
    }
}"""

content = re.sub(r'#\[pyfunction\]\npub fn ipc_publish\(channel: &str, payload: &\[u8\]\) -> Result<\(\), String> \{[\s\S]*?Err\(e\) => \{[\s\S]*?Err\(e\)[\s\S]*?\}[\s\S]*?\}', replacement, content)

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
