
with open('whitemagic-rust/src/lib.rs') as f:
    content = f.read()

# Add mod ipc_bridge
if "mod ipc_bridge;" not in content:
    content = content.replace("mod constellations;", "mod constellations;\n#[cfg(feature = \"python\")]\nmod ipc_bridge;")

# Add submodule mapping
if "ipc_bridge_module" not in content:
    replacement = """
    // Add ipc_bridge sub-module
    let ipc_bridge_module = PyModule::new_bound(_py, "ipc_bridge")?;
    ipc_bridge::ipc_bridge(_py, &ipc_bridge_module)?;
    m.add_submodule(&ipc_bridge_module)?;
    
    // Add conductor sub-module"""
    content = content.replace("    // Add conductor sub-module", replacement)

with open('whitemagic-rust/src/lib.rs', 'w') as f:
    f.write(content)

print("Patched lib.rs")
