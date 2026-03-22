
with open('whitemagic-rust/Cargo.toml', 'r') as f:
    content = f.read()

# Add iceoryx2 to features
if "iceoryx2 =" not in content and "iceoryx2" not in content.split("[features]")[1].split("\n")[1]:
    content = content.replace('default = ["python", "arrow"]', 'default = ["python", "arrow", "iceoryx2"]\niceoryx2 = ["dep:iceoryx2"]')

# Add iceoryx2 to dependencies if not there
if "iceoryx2 =" not in content.split("[dependencies]")[1]:
    content = content.replace('[dependencies]', '[dependencies]\niceoryx2 = { version = "0.8.1", optional = true }')

with open('whitemagic-rust/Cargo.toml', 'w') as f:
    f.write(content)

print("Patched Cargo.toml")
