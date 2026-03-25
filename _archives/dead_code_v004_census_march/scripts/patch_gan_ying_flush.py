
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/gan_ying.kk"

with open(file_path, "r") as f:
    content = f.read()

patch_extern = """
extern flush-stdout() : console ()
  c inline "fflush(stdout)"

fun server-loop(event-count: int): io ()
"""

content = content.replace("fun server-loop(event-count: int): io ()", patch_extern)

content = content.replace("println(response)", "println(response)\n    flush-stdout()")
content = content.replace('println("{\\"status\\":\\"started\\",\\"component\\":\\"gan_ying\\"}")', 'println("{\\"status\\":\\"started\\",\\"component\\":\\"gan_ying\\"}")\n  flush-stdout()')

with open(file_path, "w") as f:
    f.write(content)

print("gan_ying.kk flush patched successfully!")
