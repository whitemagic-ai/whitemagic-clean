import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Let's add PRAT routing directly into the Unified Fast Brain so it handles tool routing via SHM events

patch = """
// PRAT Tool Router via Koka Effect matching
fun route-to-gana(tool: string) : string
  match tool
    "session_bootstrap" -> "gana_horn"
    "create_memory" -> "gana_neck"
    "update_memory" -> "gana_neck"
    "search_memories" -> "gana_winnowing_basket"
    "vector_search" -> "gana_winnowing_basket"
    "hybrid_recall" -> "gana_winnowing_basket"
    "graph_walk" -> "gana_winnowing_basket"
    "health_report" -> "gana_root"
    "gnosis" -> "gana_ghost"
    "dream" -> "gana_abundance"
    "ensemble" -> "gana_three_stars"
    "galactic_dashboard" -> "gana_void"
    "check" -> "gana_root"
    "manifest" -> "gana_ghost"
    "capabilities" -> "gana_ghost"
    "recall" -> "gana_winnowing_basket"
    _ -> "gana_unknown"

fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : io ()
  val start-time = get-time-ms()
  
  if event.contains("query") then
    // Fast path: Semantic Search -> Graph Walk
    val start-id = shm-embed-search(embed-addr)
    val graph-res = shm-graph-walk(graph-addr, start-id, 3)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
    flush-stdout()
  elif event.contains("prat_route") then
    // Fast path: Koka PRAT Effects Router
    // Simple naive parsing for benchmarking
    val tool = if event.contains("search_memories") then "search_memories" 
               elif event.contains("create_memory") then "create_memory"
               else "unknown"
    val gana = route-to-gana(tool)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"tool\\":\\"" ++ tool ++ "\\", \\"gana\\":\\"" ++ gana ++ "\\"}")
    flush-stdout()
  else
    // Fast path: Telemetry Heartbeat
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")

fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  
  val event = shm-ring-poll(ring-addr)
  if event != "" then
    handle-event(ring-addr, embed-addr, graph-addr, event)
    server-loop(ring-addr, embed-addr, graph-addr)
  else
    sleep-us(1000)
    server-loop(ring-addr, embed-addr, graph-addr)
"""

content = re.sub(r'fun server-loop\(ring-addr: int64, embed-addr: int64, graph-addr: int64\): io \(\).*?    server-loop\(ring-addr, embed-addr, graph-addr\)', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Unified Fast Brain updated with PRAT Routing")
