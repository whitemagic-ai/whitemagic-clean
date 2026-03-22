import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_search.kk"

with open(file_path, "r") as f:
    content = f.read()

# We no longer need format-results because the C function returns the JSON string directly.
patch = """
fun extract-query-id(line: string): int
  val parts = line.split("\\"query_id\\":")
  match parts
    Cons(_, Cons(rest, _)) ->
      match rest.split(",")
        Cons(id, _) -> 
          match parse-int(id.trim())
            Just(i) -> i
            Nothing -> 0
        _ -> 0
    _ -> 0

fun server-loop(addr: int64): io ()
"""

pattern = r'fun extract-query-id\(line: string\): int.*?fun server-loop\(addr: int64\): io \(\)'
content = re.sub(pattern, patch.strip() + "\n", content, flags=re.DOTALL)

# In the server-loop search match, we shouldn't format the best results since `shm-search-top5` already returns a string.
patch2 = """
      "search" ->
        val q-id = extract-query-id(line)
        val h = read-header(addr)
        if h.count == 0 then "{\\"error\\":\\"empty\\"}"
        else
          val best = shm-search-top5(addr, h.count, q-id)
          "{\\"status\\":\\"ok\\",\\"results\\":" ++ best ++ "}"
"""

pattern2 = r'      "search" ->.*?\]"\+\+"}"'
content = re.sub(pattern2, patch2.strip(), content, flags=re.DOTALL)


with open(file_path, "w") as f:
    f.write(content)

print("shm_search.kk format-results removed!")
