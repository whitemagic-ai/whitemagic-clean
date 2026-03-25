
file_path = "/home/lucas/Desktop/whitemagicdev/elixir/lib/whitemagic/event_ring_nif.ex"

with open(file_path, "r") as f:
    content = f.read()

content = content.replace("otp_app: :whitemagic,", "otp_app: :whitemagic_core,")

with open(file_path, "w") as f:
    f.write(content)

print("otp_app fixed in NIF module")
