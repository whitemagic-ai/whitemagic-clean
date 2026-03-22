import re

file_path = "/home/lucas/Desktop/whitemagicdev/elixir/mix.exs"

with open(file_path, "r") as f:
    content = f.read()

patch = """
  defp deps do
    [
      {:rustler, "~> 0.32.1", runtime: false},
      {:libcluster, "~> 3.3"},
      {:ecto_sqlite3, "~> 0.13"},
      {:ecto, "~> 3.10"},
      {:jason, "~> 1.4"},
      {:redix, "~> 1.2"},
      {:yaml_elixir, "~> 2.9"},
      {:file_system, "~> 0.2.10"}
    ]
  end
"""

content = re.sub(r'  defp deps do.*?  end', patch.strip('\n'), content, flags=re.DOTALL)
content = content.replace('app: :whitemagic,', 'app: :whitemagic_core,')

with open(file_path, "w") as f:
    f.write(content)

print("mix.exs deps and app name fixed")
