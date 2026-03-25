
file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
// --- PRAT Routing Core ---
// We define a basic effect to handle tool dispatch natively in Koka
effect prat-route
  fun dispatch-tool(tool-name: string, args: string): string

// A basic handler for the PRAT route effect that routes to the correct Gana
fun with-prat-router(action: () -> <prat-route|e> a): e a
  with handler
    fun dispatch-tool(tool, args)
      val gana = route-to-gana(tool)
      "{\\"status\\":\\"routed\\", \\"gana\\":\\"" ++ gana ++ "\\", \\"tool\\":\\"" ++ tool ++ "\\"}"
  action()

// PRAT Tool Router via Koka Effect matching
fun route-to-gana(tool: string) : string
"""

content = content.replace("// PRAT Tool Router via Koka Effect matching\nfun route-to-gana(tool: string) : string", patch.strip('\n'))

with open(file_path, "w") as f:
    f.write(content)

print("Added PRAT effect definition to unified fast brain")
