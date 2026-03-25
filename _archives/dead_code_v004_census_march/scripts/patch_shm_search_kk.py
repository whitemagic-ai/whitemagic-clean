import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
extern shm-search-top5(addr: int64, count: int, query-id: int): string
  c "kk_shm_search_top5"

extern flush-stdout() : console ()
  c inline "fflush(stdout)"
"""

content = content.replace('extern shm-cosine-sim(addr: int64, off1: int, off2: int, dim: int): float64\n  c "kk_shm_cosine_sim"\n\nextern flush-stdout() : console ()\n  c inline "fflush(stdout)"', patch.strip())

patch2 = """
      "search" ->
        val q-id = extract-query-id(line)
        val h = read-header(addr)
        if h.count == 0 then "{\\"error\\":\\"empty\\"}"
        else
          val best = shm-search-top5(addr, h.count, q-id)
          "{\\"status\\":\\"ok\\",\\"results\\":" ++ best ++ "}"
"""

pattern = r'      "search" ->.*?\]"\+\+"}"'
content = re.sub(pattern, patch2.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk patched to use new top5 C-loop!")
