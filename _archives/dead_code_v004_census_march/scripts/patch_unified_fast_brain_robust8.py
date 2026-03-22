import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_fast_brain.kk"

with open(file_path, "r") as f:
    content = f.read()

# Remove explicit types from server-loop and main
content = content.replace("fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64) : <io,prat-route> ()", "fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64)")
content = content.replace("fun main(): io ()", "fun main()")

# To avoid type inference infinite type errors due to the exn handler, 
# let's just use with-prat-router only inside handle-event, and let server-loop be purely basic effects.
# Wait, if we put with-prat-router around handle-event inside server-loop, we don't need it in main!

patch_server_loop = """
fun server-loop(ring-addr: int64, embed-addr: int64, graph-addr: int64)
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

content = re.sub(r'fun server-loop\(ring-addr: int64, embed-addr: int64, graph-addr: int64\).*?    server-loop\(ring-addr, embed-addr, graph-addr\)\n', patch_server_loop.strip('\\n') + '\\n', content, flags=re.DOTALL)

# Revert main
patch_main = """
fun main()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
      
  println("{\\"status\\":\\"starting\\",\\"unified_fast_brain\\":true}")
  flush-stdout()
  
  val ring = shm-ring-open(ring-name, ring-size)
  val embed = shm-embed-open(embed-name)
  val graph = shm-graph-open(graph-name, graph-size)
  
  if ring == std/num/int64/int64(0) then {
    println("{\\"error\\":\\"failed to open event ring\\"}")
    flush-stdout()
  } else {
    if graph == std/num/int64/int64(0) then {
      println("{\\"error\\":\\"failed to open graph topology\\"}")
      flush-stdout()
    } else {
      println("{\\"status\\":\\"started\\",\\"connected\\":true}")
      flush-stdout()
      server-loop(ring, embed, graph)
    }
  }
"""

# Let's just strip everything from "fun main" to the end and replace it
content = re.sub(r'fun main\(\).*', patch_main.strip('\\n') + '\\n', content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(content)
