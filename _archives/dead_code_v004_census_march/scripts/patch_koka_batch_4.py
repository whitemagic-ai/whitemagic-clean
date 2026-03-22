import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_runtime_v3.kk"

with open(file_path, "r") as f:
    content = f.read()

# Replace the server-loop with a version that catches exceptions on readline
patch = """
fun server-loop(state: unified-state): io ()
  with handler
    final ctl throw-exn(exn)
      () // Silent exit on EOF
  val line = readline()
  if line == "" then ()
  else if line.contains("\\"quit\\"") then
    println("{\\"status\\":\\"stopped\\"}")
  else
    // Handle batch vs single command
    val response = if is-batch(line)
      then
        batch-response-real(line, state)
      else
        val op = extract-op(line)
        match op
          "emit" ->
            val et = extract-event-type(line)
            val new-state = emit-profiled(et, "unified_runtime_v3", state)
            "{\\"emitted\\":\\"" ++ event-type-to-string(et) ++ "\\",\\"state\\":" ++ json-state(new-state) ++ "}"
          "cascade" ->
            val et = extract-event-type(line)
            val (handlers, _) = cascade-profiled(et, state)
            "{\\"handlers_triggered\\":" ++ show(handlers) ++ "}"
          "profile" ->
            "{\\"profiled\\":true}"
          "hot" ->
            val paths = extract-hot-paths(line)
            "{\\"hot_paths_registered\\":" ++ show(paths.length) ++ "}"
          "status" -> execute-cmd("status", state)
          "count" -> execute-cmd("count", state)
          _ -> execute-cmd("ping", state)
          
    println(response)
    
    val new-state = if is-batch(line)
      then Unified-state(state.events, state.profiles, state.total-ops, state.batch-count + 1, state.session-start)
      else
        val op = extract-op(line)
        match op
          "emit" ->
            val et = extract-event-type(line)
            emit-profiled(et, "unified_runtime_v3", state)
          "cascade" ->
            val et = extract-event-type(line)
            val (_, ns) = cascade-profiled(et, state)
            ns
          _ -> state
          
    server-loop(new-state)
"""

# Replace the whole server-loop function
pattern = r'fun server-loop\(state: unified-state\): io \(\).*?(?=\n\n// ── Main ──)'
new_content = re.sub(pattern, patch.strip(), content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("unified_runtime_v3.kk EOF handler patched successfully!")
