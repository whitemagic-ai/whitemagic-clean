
with open('whitemagic-rust/src/ipc_bridge.rs') as f:
    content = f.read()

# Make sure wrap_pyfunction is imported or the macro works
# Actually, the error is 'wrapped_pyfunction is not a crate or module'
# We might need to ensure #[pyfunction] is on the functions
if "#[pyfunction]" not in content:
    content = content.replace("pub fn ipc_init() -> PyResult<String> {", "#[pyfunction]\npub fn ipc_init() -> PyResult<String> {")
    content = content.replace("pub fn ipc_publish(channel: &str, payload: &[u8]) -> PyResult<u64> {", "#[pyfunction]\npub fn ipc_publish(channel: &str, payload: &[u8]) -> PyResult<u64> {")
    content = content.replace("pub fn ipc_status() -> PyResult<std::collections::HashMap<String, String>> {", "#[pyfunction]\npub fn ipc_status() -> PyResult<std::collections::HashMap<String, String>> {")

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
