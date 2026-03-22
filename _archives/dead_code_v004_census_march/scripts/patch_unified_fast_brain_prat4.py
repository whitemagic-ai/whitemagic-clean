
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace("elif event.contains(\"prat_route\") then {", "else if event.contains(\"prat_route\") then {")
content = content.replace("elif event.contains(\"create_memory\")", "else if event.contains(\"create_memory\")")

with open(file_path, "w") as f:
    f.write(content)

print("Unified Fast Brain updated with PRAT Routing (else if fix)")
