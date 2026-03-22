import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
fun extract-prat-tool(event: string) : string
  if event.contains("search_memories") then "search_memories"
  elif event.contains("create_memory") then "create_memory"
  else "unknown"

fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : io ()
  val start-time = get-time-ms()
  if event.contains("query") then
    val start-id = shm-embed-search(embed-addr)
    val graph-res = shm-graph-walk(graph-addr, start-id, 3)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
    flush-stdout()
  elif event.contains("prat_route") then
    val tool = extract-prat-tool(event)
    val gana = route-to-gana(tool)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"tool\\":\\"" ++ tool ++ "\\", \\"gana\\":\\"" ++ gana ++ "\\"}")
    flush-stdout()
  else
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")
    flush-stdout()
"""

content = re.sub(r'fun handle-event\(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string\) : io \(\).*?fun server-loop', patch.strip('\n') + '\n\nfun server-loop', content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Unified Fast Brain handle-event rewritten cleanly")
