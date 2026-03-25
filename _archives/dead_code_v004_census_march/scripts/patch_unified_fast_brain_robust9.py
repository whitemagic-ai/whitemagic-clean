import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Let's replace from fun handle-event to the end of the file
match = re.search(r'fun handle-event\(ring-addr: int64.*', content, re.DOTALL)
if match:
    new_tail = """fun handle-event(ring-addr: int64, embed-addr: int64, graph-addr: int64, event: string) : <io,prat-route> ()
  val start-time = get-time-ms()
  if event.contains("\\"query\\":") && embed-addr != std/num/int64/int64(0) && graph-addr != std/num/int64/int64(0) then
    val start-id = shm-embed-search(embed-addr)
    val graph-res = shm-graph-walk(graph-addr, start-id, 3)
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
    flush-stdout()
  elif event.contains("\\"prat_route\\":") then
    val tool = if event.contains("search_memories") then "search_memories" else (if event.contains("create_memory") then "create_memory" else "unknown")
    val res = dispatch-tool(tool, "{}")
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"prat_routed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"result\\":" ++ res ++ "}")
    flush-stdout()
  else
    val end-time = get-time-ms()
    val dur = show(end-time - start-time) ++ "ms"
    println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")
    flush-stdout()

fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64) : io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  
  val event = shm-ring-poll(ring-addr)
  if event != "" then
    with-prat-router
      handle-event(ring-addr, embed-addr, graph-addr, event)
    server-loop(ring-addr, embed-addr, graph-addr)
  else
    sleep-us(1000)
    server-loop(ring-addr, embed-addr, graph-addr)

fun main() : io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
      
  println("{\\"status\\":\\"starting\\",\\"unified_fast_brain\\":true}")
  flush-stdout()
  
  val ring = shm-ring-open(ring-name, ring-size)
  val embed = shm-embed-open(embed-name)
  val graph = shm-graph-open(graph-name, graph-size)
  
  if ring == std/num/int64/int64(0) then
    println("{\\"error\\":\\"failed to open event ring\\"}")
    flush-stdout()
  else
    if graph == std/num/int64/int64(0) then
      println("{\\"error\\":\\"failed to open graph topology\\"}")
      flush-stdout()
    println("{\\"status\\":\\"started\\",\\"connected\\":true}")
    flush-stdout()
    server-loop(ring, embed, graph)
"""
    content = content[:match.start()] + new_tail
    
    with open(file_path, "w") as f:
        f.write(content)
