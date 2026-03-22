from pathlib import Path

file_path = Path("/home/lucas/Desktop/whitemagicdev/whitemagic-rust/Cargo.toml")
content = file_path.read_text()
content = content.replace(r'\"', '"')
file_path.write_text(content)
print("Cargo.toml quotes fixed.")
