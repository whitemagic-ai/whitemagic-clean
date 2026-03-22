import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/shm_graph.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
fun extract-start-id(line: string): int
  val parts = line.split("\\"start_id\\":")
  match parts
    Cons(_, Cons(rest, _)) ->
      match rest.split("}")
        Cons(id, _) -> 
          match parse-int(id.trim())
            Just(i) -> i
            Nothing -> 0
        _ -> 0
    _ -> 0
"""

content = re.sub(r'fun extract-start-id\(line: string\): int.*?    _ -> 0', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("shm_graph.kk start_id parse fixed")
