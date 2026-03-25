import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string)
  val start-time = get-time-ms()
  if event.contains("\\"query\\":") && embed-addr != std/num/int64/int64(0) && graph-addr != std/num/int64/int64(0) then {
    val start-id = shm-embed-search(embed-addr)
    val graph-res = shm-graph-walk(graph-addr, start-id, 3)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
    flush-stdout()
  } else {
    if event.contains("\\"prat_route\\":") then {
      val tool = if event.contains("search_memories") then "search_memories" else { if event.contains("create_memory") then "create_memory" else "unknown" }
      val res = dispatch-tool(tool, "{}")
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"result\\":" ++ res ++ "}")
      flush-stdout()
    } else {
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")
      flush-stdout()
    }
  }
"""

content = re.sub(r'fun handle-event\(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string\).*?    flush-stdout\(\)\n    \}\n  \}', patch.strip('\n') + '\n', content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Patched Koka brain to safely check embed-addr and graph-addr and use strict JSON key matching")
