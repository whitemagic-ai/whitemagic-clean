from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic-rust/src/lib.rs")
content = file_path.read_text()

# Add module declaration
if "mod sutra_kernel;" not in content:
    content = content.replace("mod recursive_intelligence;", "mod recursive_intelligence;\n#[cfg(feature = \"python\")]\nmod sutra_kernel;")

# Add to pymodule
if "sutra_kernel::sutra_kernel" not in content:
    add_module = """    // Add sutra_kernel sub-module
    let sutra_kernel_module = PyModule::new_bound(_py, "sutra_kernel")?;
    sutra_kernel::sutra_kernel(_py, &sutra_kernel_module)?;
    m.add_submodule(&sutra_kernel_module)?;"""
    
    content = content.replace("    m.add_class::<graph_walker::GraphWalker>()?;", "    m.add_class::<graph_walker::GraphWalker>()?;\n\n" + add_module)

file_path.write_text(content)
print("lib.rs patched to include SutraKernel.")
