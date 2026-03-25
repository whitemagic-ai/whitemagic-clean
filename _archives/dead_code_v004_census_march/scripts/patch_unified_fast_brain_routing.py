import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

patch = """
  val event = shm-ring-poll(ring-addr)
  if event != "" then
    val start-time = get-time-ms()
    
    // Simple routing based on whether it looks like a query
    if event.contains("query") then
      val start-id = shm-embed-search(embed-addr)
      val graph-res = shm-graph-walk(graph-addr, start-id, 3)
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"system_resonance_achieved\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ ", \\"context\\":" ++ graph-res ++ "}")
      flush-stdout()
    else
      // Fast path for telemetry
      val end-time = get-time-ms()
      val dur = show(end-time - start-time) ++ "ms"
      println("{\\"status\\":\\"telemetry_processed\\", \\"latency\\":\\"" ++ dur ++ "\\", \\"input_event\\":" ++ event ++ "}")
      // Only flush occasionally if we are fast-pathing to avoid stdout bottleneck, but let's just flush for now
      flush-stdout()
    
    server-loop(ring-addr, embed-addr, graph-addr)
"""

# Replace the body of the if event != "" block
content = re.sub(r'  val event = shm-ring-poll\(ring-addr\)\n  if event != "" then.*?    server-loop\(ring-addr, embed-addr, graph-addr\)', patch.strip('\n'), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)

print("Patched unified fast brain routing")
