import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the handler effect type signature issue
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
        
      val response = with basic-prat-dispatcher
                     with state-resonance
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

# Go back to basic-prat-dispatcher and state-resonance which are standard `with` handlers
# We need to make sure basic-prat-dispatcher handles `prat-dispatch` and state-resonance handles `resonance`

pattern = r'fun server-loop\(\): io \(\).*?(?=$)'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("prat.kk effect handlers patched successfully!")
