
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/gan_ying.kk"

with open(file_path, "r") as f:
    content = f.read()

# Replace json-error with direct string
content = content.replace('json-error("unknown_operation")', '"{\\"error\\":\\"unknown_operation\\"}"')

with open(file_path, "w") as f:
    f.write(content)

print("gan_ying.kk json-error patched successfully!")
