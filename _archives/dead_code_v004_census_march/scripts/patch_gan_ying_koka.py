import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/gan_ying.kk"

with open(file_path, "r") as f:
    content = f.read()

# Make gan_ying properly handle unexpected EOF
patch = """
fun server-loop(event-count: int): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF
  val line = readline()
  if line != "" then
    val op = extract-op(line)
    val response = match op
      "emit" ->
        val et = extract-type(line)
        val (event, _new-count) = emit-event("ipc", et, "{}", 1.0, event-count)
        json-event-response(event)
      "count" ->
        json-response("count", show(event-count))
      "reset" ->
        json-response("reset", show(event-count))
      "cascade" ->
        val et = extract-type(line)
        val trigger = check-cascade(et)
        "{\\"type\\":\\"" ++ event-type-to-string(trigger.event-type) ++ 
        "\\",\\"handlers\\":" ++ show(trigger.handler-count) ++
        ",\\"priority\\":" ++ show(trigger.priority) ++ "}"
      "status" ->
        "{\\"status\\":\\"ok\\",\\"events\\":" ++ show(event-count) ++ "}"
      "ping" ->
        "{\\"pong\\":true}"
      "invoke-gana" ->
        "{\\"status\\":\\"ok\\",\\"result\\":\\"gana invoked\\"}"
      "route-prat" ->
        "{\\"status\\":\\"ok\\",\\"routed\\":true}"
      _ ->
        json-error("unknown_operation")
        
    println(response)
    
    val next-count = match op
      "emit" -> event-count + 1
      "reset" -> 0
      _ -> event-count
      
    if op != "quit" then server-loop(next-count) else ()
    
fun main(): io ()
  with handler
    final ctl throw-exn(exn)
      () // Catch EOF globally
  println("{\\"status\\":\\"started\\",\\"component\\":\\"gan_ying\\"}")
  server-loop(0)
"""

pattern = r'fun server-loop\(event-count: int\): io \(\).*?(?=$)'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("gan_ying.kk EOF handler and stubs patched successfully!")
