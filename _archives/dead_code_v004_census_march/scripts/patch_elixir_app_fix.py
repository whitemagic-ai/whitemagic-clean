import re

file_path = "/home/lucas/Desktop/whitemagicdev/elixir/lib/whitemagic_core/application.ex"

with open(file_path, "r") as f:
    content = f.read()

# Fix the catch/rescue logic
patch = """
    try do
      WhiteMagic.EventRing.Nif.init_shm_ring()
    rescue
      e -> IO.puts("Warning: Failed to initialize Event Ring SHM: #{inspect(e)}")
    end
"""

content = re.sub(r'    try do.*?    end', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

file2 = "/home/lucas/Desktop/whitemagicdev/elixir/lib/whitemagic_core/gan_ying/lane_pools.ex"

with open(file2, "r") as f:
    content2 = f.read()

patch2 = """
    try do
      WhiteMagic.EventRing.Nif.push_event(event_id, sender_hash, timestamp, payload)
    rescue
      _ -> :error
    end
"""

content2 = re.sub(r'    try do.*?    end', patch2.strip('\n'), content2, flags=re.DOTALL)

with open(file2, "w") as f:
    f.write(content2)

print("Elixir catch statements fixed")
