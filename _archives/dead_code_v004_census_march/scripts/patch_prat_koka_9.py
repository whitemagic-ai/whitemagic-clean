import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix effect signatures to be polymorphic over other effects
content = content.replace(
    "fun handle-resonance(action: () -> <resonance> a) : a",
    "fun handle-resonance(action: () -> <resonance|e> a) : e a"
)

content = content.replace(
    "fun handle-prat-dispatch-production(action: () -> <prat-dispatch> a) : a",
    "fun handle-prat-dispatch-production(action: () -> <prat-dispatch|e> a) : e a"
)

patch = """
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

pattern = r'fun handle-both.*?server-loop\(\)'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("prat.kk effect handlers patched successfully!")
