
with open('whitemagic-rust/src/ipc_bridge.rs', 'r') as f:
    lines = f.readlines()

new_lines = []
in_func = False
for line in lines:
    if line.strip() == "#[pyfunction]":
        # we will add them manually where needed
        continue
        
    new_lines.append(line)

content = "".join(new_lines)

# Now add #[pyfunction] exactly once to the target functions
content = content.replace("pub fn ipc_init", "#[pyfunction]\npub fn ipc_init")
content = content.replace("pub fn ipc_publish", "#[pyfunction]\npub fn ipc_publish")
content = content.replace("pub fn ipc_status", "#[pyfunction]\npub fn ipc_status")

# Fix string to PyErr conversion issue
# iox2::publish(channel, payload).map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(e)) -> 
#   need to make sure `e` is a string or displayable
content = content.replace(".map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(e))", ".map_err(|e| pyo3::exceptions::PyRuntimeError::new_err(e.to_string()))")

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Cleaned up ipc_bridge.rs")
