import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : io ()
  val start-time = get-time-ms()
  match event.contains("query")
    True -> 
      val start-id = shm-embed-search(embed-addr)
      val graph-res = shm-graph-walk(graph-addr, start-id, 3)
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
      flush-stdout()
    False -> match event.contains("prat_route")
      True ->
        val tool = match event.contains("search_memories")
          True -> "search_memories"
          False -> match event.contains("create_memory")
            True -> "create_memory"
            False -> "unknown"
        val gana = route-to-gana(tool)
        val end-time = get-time-ms()
        val dur = show(end-time - start-time) ++ "ms"
        println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"tool\\":\\"" ++ tool ++ "\\", \\"gana\\":\\"" ++ gana ++ "\\"}")
        flush-stdout()
      False ->
        val end-time = get-time-ms()
        val dur = show(end-time - start-time) ++ "ms"
        println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")
        flush-stdout()

fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  
  val event = shm-ring-poll(ring-addr)
  match event != ""
    True ->
      handle-event(ring-addr, embed-addr, graph-addr, event)
      server-loop(ring-addr, embed-addr, graph-addr)
    False ->
      sleep-us(1000)
      server-loop(ring-addr, embed-addr, graph-addr)
"""

content = re.sub(r'fun handle-event\(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string\) : io \(\).*?    server-loop\(ring-addr, embed-addr, graph-addr\)\n  \}', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

