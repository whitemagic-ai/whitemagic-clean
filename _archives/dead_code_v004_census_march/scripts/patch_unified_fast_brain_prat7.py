import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : io ()
  val start-time = get-time-ms()
  
  if event.contains("query") then {
    val start-id = shm-embed-search(embed-addr)
    val graph-res = shm-graph-walk(graph-addr, start-id, 3)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
    flush-stdout()
  } else {
    if event.contains("prat_route") then {
      val tool = if event.contains("search_memories") then "search_memories" else { if event.contains("create_memory") then "create_memory" else "unknown" }
      val gana = route-to-gana(tool)
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"tool\\":\\"" ++ tool ++ "\\", \\"gana\\":\\"" ++ gana ++ "\\"}")
      flush-stdout()
    } else {
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")
      flush-stdout()
    }
  }
"""

content = re.sub(r'fun handle-event\(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string\) : io \(\).*?    flush-stdout\(\)\n', patch.strip('\n') + '\n', content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Unified Fast Brain updated with PRAT Routing (proper nested if-else)")
