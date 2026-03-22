
with open('whitemagic-rust/src/ipc_bridge.rs', 'r') as f:
    content = f.read()

# Add #[cfg(feature = "python")] to the ipc_bridge fn
if "#[cfg(feature = \"python\")]\npub fn ipc_bridge" not in content:
    content = content.replace("pub fn ipc_bridge", "#[cfg(feature = \"python\")]\npub fn ipc_bridge")

# Add the missing import for wrap_pyfunction in the python feature block if not there
if "wrap_pyfunction" not in content[:500]:
    content = content.replace("use pyo3::prelude::*;", "use pyo3::prelude::*;\n#[cfg(feature = \"python\")]\nuse pyo3::wrap_pyfunction;")

with open('whitemagic-rust/src/ipc_bridge.rs', 'w') as f:
    f.write(content)

print("Patched ipc_bridge.rs")
