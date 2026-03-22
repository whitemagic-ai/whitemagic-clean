from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic-rust/src/lib.rs")
content = file_path.read_text()

# Add module declaration
if "mod arrow_bridge;" not in content:
    content = content.replace("#[cfg(feature = \"python\")]\nmod sutra_kernel;", "#[cfg(feature = \"python\")]\nmod sutra_kernel;\n#[cfg(feature = \"python\")]\nmod arrow_bridge;")

# Add to pymodule
if "arrow_bridge::arrow_bridge" not in content:
    add_module = """    // Add arrow_bridge sub-module
    let arrow_bridge_module = PyModule::new_bound(_py, "arrow_bridge")?;
    arrow_bridge::arrow_bridge(_py, &arrow_bridge_module)?;
    m.add_submodule(&arrow_bridge_module)?;"""
    
    content = content.replace("    m.add_class::<graph_walker::GraphWalker>()?;", "    m.add_class::<graph_walker::GraphWalker>()?;\n\n" + add_module)

file_path.write_text(content)
print("lib.rs patched to include Arrow Bridge.")
