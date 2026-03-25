
file_path = "/home/lucas/Desktop/whitemagicdev/elixir/mix.exs"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace("mod: {WhiteMagic.Application, []}", "mod: {WhitemagicCore.Application, []}")

with open(file_path, "w") as f:
    f.write(content)

print("mix.exs application mod fixed")
