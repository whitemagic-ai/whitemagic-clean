import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the server-loop EOF handling to gracefully exit and correctly parse FFI wrapper payload
patch = """
fun extract-tool-from-ffi(line: string): string
  val parts = line.split("\\"tool\\":\\"")
  match parts
    Cons(_, Cons(rest, _)) ->
      match rest.split("\\"")
        Cons(t, _) -> t
        _ -> "unknown"
    _ -> "unknown"

fun server-loop(): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  val line = readline()
  if line != "" then
    if line.contains("\\"quit\\"") then ()
    else
      // Handle either direct tool name or FFI JSON wrapper
      val tool-name = if line.contains("\\"operation\\":\\"route-prat\\"")
        then extract-tool-from-ffi(line)
        else extract-tool(line)
        
      val response = route-prat-call(tool-name, "{}")
      println(response)
      flush-stdout()
      server-loop()
  else ()

fun main(): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  println("{\\"status\\":\\"started\\",\\"component\\":\\"prat_router\\"}")
  server-loop()
"""

pattern = r'fun server-loop\(\): io \(\).*?(?=$)'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("prat.kk FFI handler patched successfully!")
