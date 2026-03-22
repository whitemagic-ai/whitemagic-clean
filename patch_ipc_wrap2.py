
with open('whitemagic-rust/src/ipc_bridge.rs', 'r') as f:
    content = f.read()

# Fix wrap_pyfunction macro usage
# The error says "wrapped_pyfunction is not a crate or module"
# This typically happens if PyO3's module macro isn't correctly pulling it in or we need to use it directly
# Let's remove the import of wrap_pyfunction and just use pyo3::wrap_pyfunction!
content = content.replace("use pyo3::wrap_pyfunction;", "")
content = content.replace("wrap_pyfunction!(ipc_init, m)", "pyo3::wrap_pyfunction!(ipc_init, m)")
content = content.replace("wrap_pyfunction!(ipc_publish, m)", "pyo3::wrap_pyfunction!(ipc_publish, m)")
content = content.replace("wrap_pyfunction!(ipc_status, m)", "pyo3::wrap_pyfunction!(ipc_status, m)")

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
