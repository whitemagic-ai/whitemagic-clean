import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the duplicate server-loop logic resulting from a bad regex replacement
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
        
      val response = 
        with handle-prat-dispatch-production
        with handle-resonance
        route-prat-call(tool-name, "{}")
                     
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

pattern = r'fun extract-tool-from-ffi\(line: string\): string.*?$'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("prat.kk duplicate syntax fixed!")
