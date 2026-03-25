import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix type inference by restoring explicit io, and keeping the with-prat-router purely around handle-event
patch = """
fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : <io,prat-route> ()
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

fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  
  val event = shm-ring-poll(ring-addr)
  if event != "" then {
    with-prat-router {
      handle-event(ring-addr, embed-addr, graph-addr, event)
    }
    server-loop(ring-addr, embed-addr, graph-addr)
  } else {
    sleep-us(1000)
    server-loop(ring-addr, embed-addr, graph-addr)
  }
"""

content = re.sub(r'fun handle-event\(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string\).*?    server-loop\(ring-addr, embed-addr, graph-addr\)\n  \}', patch.strip('\n') + '\n', content, flags=re.DOTALL)

# Revert the main function change
patch_main = """
  else
    println("{\\"status\\":\\"started\\",\\"connected\\":true}")
    flush-stdout()
    server-loop(ring, embed, graph)
"""

content = re.sub(r'  else\n    println\("{\\\\"status\\\\":\\\\"started\\\\",\\\\"connected\\\\":true}"\)\n    flush-stdout\(\)\n    with-prat-router\n      server-loop\(ring, embed, graph\)', patch_main.strip('\n'), content, flags=re.DOTALL)


with open(file_path, "w") as f:
    f.write(content)

