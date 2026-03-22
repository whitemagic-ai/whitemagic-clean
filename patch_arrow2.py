
with open('whitemagic-rust/src/arrow_bridge.rs', 'r') as f:
    content = f.read()

# Fix the extra brace
content = content.replace("    }\n}\n}", "    }\n}")

with open('whitemagic-rust/src/arrow_bridge.rs', 'w') as f:
    f.write(content)

print("Patched arrow_bridge.rs")
