
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

# Re-replace to fix indentation
content = content.replace('"search" ->\n        val q-id = extract-query-id(line)', '      "search" ->\n        val q-id = extract-query-id(line)')

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk server loop indentation patched!")
