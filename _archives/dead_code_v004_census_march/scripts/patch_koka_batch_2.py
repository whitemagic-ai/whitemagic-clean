import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic-koka/src/unified_runtime_v3.kk"

with open(file_path, "r") as f:
    content = f.read()

# Fix the Koka string split issue
# In Koka v3, string.split usually takes a separator and an optional limit.
# We'll use split(s, sep) -> list<string>

patch = """
// ── Batch IPC Support ───────────────────────────────────────────────────────────

import std/core/list

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
  match parts
    Cons(_, Cons(rest, _)) ->
      match rest.split("\\"")
        Cons(id, _) -> id
        _ -> "unknown"
    _ -> "unknown"

// Extract command ID
fun extract-cmd-id(cmd-str: string): string
  val parts = cmd-str.split("\\"id\\":")
  match parts
    Cons(_, Cons(rest, _)) ->
      match rest.split(",")
        Cons(id, _) -> id
        _ -> "0"
    _ -> "0"

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
  
  val parts = line.split("[")
  match parts
    Cons(_, Cons(rest, _)) ->
      match rest.split("]")
        Cons(cmd-array-str, _) ->
          val cmds = cmd-array-str.split("},{")
          val results = process-commands(cmds, state)
          val count = show(cmds.length)
          "{\\"request_id\\":\\"" ++ req-id ++ "\\",\\"results\\":[" ++ results ++ "],\\"commands_processed\\":" ++ count ++ "}"
        _ -> "{\\"request_id\\":\\"" ++ req-id ++ "\\",\\"results\\":[],\\"commands_processed\\":0}"
    _ -> "{\\"request_id\\":\\"" ++ req-id ++ "\\",\\"results\\":[],\\"commands_processed\\":0}"
"""

# Replace the whole batch section
pattern = r'// ── Batch IPC Support ──.*?(?=// ── IPC Server ──)'
new_content = re.sub(pattern, patch, content, flags=re.DOTALL)

with open(file_path, "w") as f:
    f.write(new_content)

print("unified_runtime_v3.kk patched successfully!")
