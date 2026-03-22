
with open('whitemagic-rust/Cargo.toml') as f:
    content = f.read()

# Add iceoryx2 feature
content = content.replace('default = ["python", "arrow"]', 'default = ["python", "arrow", "iceoryx2"]\niceoryx2 = ["dep:iceoryx2"]')

# Add iceoryx2 dependency
content = content.replace('[dependencies]', '[dependencies]\niceoryx2 = { version = "0.8.1", optional = true }')

with open('whitemagic-rust/Cargo.toml', 'w') as f:
    f.write(content)

print("Patched Cargo.toml")
