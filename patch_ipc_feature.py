
with open('whitemagic-rust/src/ipc_bridge.rs') as f:
    content = f.read()

# Fix feature flags, "python" is what we use in lib.rs for other python modules
content = content.replace('#[cfg(feature = "pyo3")]', '#[cfg(feature = "python")]')

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
