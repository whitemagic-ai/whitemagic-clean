
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_consumer.kk"

with open(file_path, "r") as f:
    content = f.read()

# Add flush-stdout extern
patch_extern = """
extern flush-stdout() : console ()
  c inline "fflush(stdout)"

// ── FFI Bindings via C file ──────────────────────────────────────────────────
"""

content = content.replace("// ── FFI Bindings via C file ──────────────────────────────────────────────────", patch_extern)

# Replace println with flush
content = content.replace("println(response)", "println(response)\n    flush-stdout()")
content = content.replace('println("{\\"status\\":\\"starting\\",\\"shm_consumer\\":true,\\"target\\":\\"" ++ shm-name ++ "\\"}")', 'println("{\\"status\\":\\"starting\\",\\"shm_consumer\\":true,\\"target\\":\\"" ++ shm-name ++ "\\"}")\n  flush-stdout()')
content = content.replace('println("{\\"error\\":\\"failed to open shared memory - producer must create first\\"}")', 'println("{\\"error\\":\\"failed to open shared memory - producer must create first\\"}")\n    flush-stdout()')
content = content.replace('println("{\\"error\\":\\"invalid magic - got " ++ show(header.magic) ++ "\\"}")', 'println("{\\"error\\":\\"invalid magic - got " ++ show(header.magic) ++ "\\"}")\n      flush-stdout()')
content = content.replace('println("{\\"status\\":\\"started\\",\\"connected\\":true,\\"capacity\\":" ++ show(header.capacity) ++ "}")', 'println("{\\"status\\":\\"started\\",\\"connected\\":true,\\"capacity\\":" ++ show(header.capacity) ++ "}")\n      flush-stdout()')


with open(file_path, "w") as f:
    f.write(content)

print("shm_consumer.kk flush patched!")
