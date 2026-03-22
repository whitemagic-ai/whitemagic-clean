
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

# Remove the old main loop
pattern = r'// Main server loop\nfun main\(\): io \(\)\n  // Run with handlers\n  handle-resonance {\n    handle-prat-dispatch-production {\n      server-loop\(\)\n    }\n  }'

new_content = content.replace('// Main server loop\nfun main(): io ()\n  // Run with handlers\n  handle-resonance {\n    handle-prat-dispatch-production {\n      server-loop()\n    }\n  }', '')

with open(file_path, "w") as f:
    f.write(new_content)

print("prat.kk main duplicate fixed!")
