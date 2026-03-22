# WhiteMagic Nim Core - 12th Polyglot Implementation
# Fast, Pythonic syntax, C-level performance

import tables, json, times, strutils

type
  Memory* = object
    id*: string
    content*: string
    tags*: seq[string]
    created_at*: DateTime
    importance*: float

  MemoryStore* = ref object
    memories*: Table[string, Memory]

proc newMemoryStore*(): MemoryStore =
  MemoryStore(memories: initTable[string, Memory]())

proc add*(store: MemoryStore, mem: Memory) =
  store.memories[mem.id] = mem

proc get*(store: MemoryStore, id: string): Option[Memory] =
  if store.memories.hasKey(id):
    return some(store.memories[id])
  return none(Memory)

proc similarity*(a, b: string): float {.exportc.} =
  # Simple Jaccard similarity for FFI calls
  let setA = a.splitWhitespace().toHashSet()
  let setB = b.splitWhitespace().toHashSet()
  let intersection = setA * setB
  let union = setA + setB
  if union.len == 0: return 0.0
  return intersection.len.float / union.len.float
