import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

patch2 = """
      "search" ->
        val q-id = extract-query-id(line)
        val h = read-header(addr)
        if h.count == 0 then "{\\"error\\":\\"empty\\"}"
        else
          val best = shm-search-top5(addr, h.count, q-id)
          "{\\"status\\":\\"ok\\",\\"results\\":" ++ best ++ "}"
"""

pattern = r'      "search" ->.*?"{\\"status\\":\\"ok\\",\\"results\\":" \+\+ format-results\(best\) \+\+ "}"'
content = re.sub(pattern, patch2.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk server loop patched!")
