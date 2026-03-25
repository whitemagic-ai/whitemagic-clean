import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Add the PRAT Effect Router hook into the Unified Fast Brain
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

fun extract-prat-tool(event: string) : string
"""

content = content.replace("fun extract-prat-tool(event: string) : string", patch.strip('\n'))

patch2 = """
        val tool = match event.contains("search_memories")
          True -> "search_memories"
          False -> match event.contains("create_memory")
            True -> "create_memory"
            False -> "unknown"
        val res = dispatch-tool(tool, "{}")
        val end-time = get-time-ms()
        val dur = show(end-time - start-time) ++ "ms"
        println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"result\\":" ++ res ++ "}")
        flush-stdout()
"""

# Replace the previous PRAT block in handle-event
content = re.sub(r'        val tool = match event\.contains\("search_memories"\).*?flush-stdout\(\)', patch2.strip('\n'), content, flags=re.DOTALL)

patch3 = """
  val event = shm-ring-poll(ring-addr)
  match event != ""
    True ->
      with-prat-router
        handle-event(ring-addr, embed-addr, graph-addr, event)
      server-loop(ring-addr, embed-addr, graph-addr)
"""

content = re.sub(r'  val event = shm-ring-poll\(ring-addr\)\n  match event != ""\n    True ->\n      handle-event\(ring-addr, embed-addr, graph-addr, event\)\n      server-loop\(ring-addr, embed-addr, graph-addr\)', patch3.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Unified Fast Brain updated to use PRAT Effect Routing")
