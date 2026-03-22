import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

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
        
      val response = handle-prat-dispatch-production {
        handle-resonance {
          route-prat-call(tool-name, "{}")
        }
      }
                     
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

print("prat.kk effect handlers patched successfully!")
