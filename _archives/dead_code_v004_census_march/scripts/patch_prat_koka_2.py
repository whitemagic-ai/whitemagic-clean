import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/prat.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the server-loop effects by wrapping the route-prat-call inside handlers
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
        
      // Handle the effects required by route-prat-call
      val response = with basic-prat-dispatcher
                     with state-resonance
                     route-prat-call(tool-name, "{}")
                     
      println(response)
      flush-stdout()
      server-loop()
  else ()
"""

pattern = r'fun server-loop\(\): io \(\).*?(?=\n\nfun main)'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("prat.kk effect handlers patched successfully!")
