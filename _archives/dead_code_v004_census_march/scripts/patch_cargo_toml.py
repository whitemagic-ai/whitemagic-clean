from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic-rust/Cargo.toml")
content = file_path.read_text()

# Fix the features definition
content = content.replace("python = [\"pyo3\", \"numpy\", \"pyo3-build-config\", \"tokio\", \"arrow\"]", "python = [\"pyo3\", \"numpy\", \"pyo3-build-config\", \"tokio\"]\narrow = [\"dep:arrow\"]")
content = content.replace("default = [\"python\"]", "default = [\"python\", \"arrow\"]")

# Add the dependency correctly
if "name = \"arrow\"" not in content and "dep:arrow" not in content:
    content = content.replace("[dependencies]", "[dependencies]\narrow = { version = \"50.0\", optional = true }")

file_path.write_text(content)
print("Cargo.toml patched.")
