import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_runtime_v3.kk"

with open(file_path, "r") as f:
    content = f.read()

# We need to implement a real batch response generator instead of the hardcoded one.
# Koka doesn't have a simple way to parse arbitrary JSON dynamically without a library,
# but we can do a simple string manipulation for the proof of concept or use the existing
# pattern of string building.

patch = """
// ── Batch IPC Support ───────────────────────────────────────────────────────────

fun count-cmds(line: string): int
  line.count("{\\"id\\":")

fun is-batch(line: string): bool
  line.contains("\\"commands\\":")

// Execute single command
fun execute-cmd(op: string, state: unified-state): string
  match op
    "ping" -> "{\\"pong\\":true}"
    "status" -> json-state(state)
    "emit" -> "{\\"emitted\\":true}"
    "count" -> "{\\"count\\":" ++ show(state.events.length) ++ "}"
    _ -> "{\\"error\\":\\"unknown\\"}"

// Extract command operation from a specific command string
fun extract-cmd-op(cmd-str: string): string
  if cmd-str.contains("\\"op\\":\\"ping\\"") then "ping"
  else if cmd-str.contains("\\"op\\":\\"emit\\"") then "emit"
  else if cmd-str.contains("\\"op\\":\\"status\\"") then "status"
  else if cmd-str.contains("\\"op\\":\\"count\\"") then "count"
  else "unknown"

// Extract request ID from batch
fun extract-request-id(line: string): string
  val parts = line.split("\\"request_id\\":\\"")
  if parts.length > 1 then
    match parts[1]
      s -> s.split("\\"")[0]
  else "unknown"

// Extract command ID
fun extract-cmd-id(cmd-str: string): string
  val parts = cmd-str.split("\\"id\\":")
  if parts.length > 1 then
    match parts[1]
      s -> s.split(",")[0]
  else "0"

// Process a list of command strings
fun process-commands(cmds: list<string>, state: unified-state): string
  match cmds
    Nil -> ""
    Cons(c, rest) ->
      if c.trim() == "" then process-commands(rest, state)
      else
        val id = extract-cmd-id(c)
        val op = extract-cmd-op(c)
        val result = execute-cmd(op, state)
        val response = "{\\"id\\":" ++ id ++ ",\\"status\\":\\"ok\\",\\"result\\":" ++ result ++ "}"
        val rest-resp = process-commands(rest, state)
        if rest-resp == "" then response
        else response ++ "," ++ rest-resp

// Generate a real batch response
fun batch-response-real(line: string, state: unified-state): string
  val req-id = extract-request-id(line)
  
  // Quick and dirty JSON split for the commands array
  val parts = line.split("[")
  if parts.length > 1 then
    match parts[1]
      s -> 
        val cmd-array-str = s.split("]")[0]
        val cmds = cmd-array-str.split("},{")
        val results = process-commands(cmds, state)
        val count = show(cmds.length)
        "{\\"request_id\\":\\"" ++ req-id ++ "\\",\\"results\\":[" ++ results ++ "],\\"commands_processed\\":" ++ count ++ "}"
  else
    "{\\"request_id\\":\\"" ++ req-id ++ "\\",\\"results\\":[],\\"commands_processed\\":0}"

"""

# Replace the whole batch section
pattern = r'// ── Batch IPC Support ──.*?(?=// ── IPC Server ──)'
new_content = re.sub(pattern, patch, content, flags=re.DOTALL)

# Now update the server loop to use the real batch response
server_loop_pattern = r'val response = if is-batch\(line\)\s+then\s+val n = count-cmds\(line\)\s+batch-response\(n\)'
server_loop_patch = """val response = if is-batch(line)
      then
        batch-response-real(line, state)"""
new_content = new_content.replace('val response = if is-batch(line)\n      then\n        val n = count-cmds(line)\n        batch-response(n)', server_loop_patch)


with open(file_path, "w") as f:
    f.write(new_content)

print("unified_runtime_v3.kk patched successfully!")
