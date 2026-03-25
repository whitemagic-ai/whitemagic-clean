import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/gan_ying.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
fun extract-op(line: string): string
  if line.contains("\\"emit\\"") then "emit"
  else if line.contains("\\"count\\"") then "count"
  else if line.contains("\\"reset\\"") then "reset"
  else if line.contains("\\"cascade\\"") then "cascade"
  else if line.contains("\\"status\\"") then "status"
  else if line.contains("\\"quit\\"") then "quit"
  else if line.contains("\\"invoke-gana\\"") then "invoke-gana"
  else if line.contains("\\"route-prat\\"") then "route-prat"
  else "unknown"
"""

pattern = r'fun extract-op\(line: string\): string.*?else "unknown"'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("gan_ying.kk extract-op patched successfully!")
