// WhiteMagic Gleam Core - 13th Polyglot Implementation
// BEAM VM concurrency, type-safe, Pythonic syntax

import gleam/dict.{type Dict}
import gleam/list
import gleam/string
import gleam/float
import gleam/option.{type Option, Some, None}

pub type Memory {
  Memory(
    id: String,
    content: String,
    tags: List(String),
    importance: Float,
  )
}

pub type MemoryStore {
  MemoryStore(memories: Dict(String, Memory))
}

pub fn new_memory_store() -> MemoryStore {
  MemoryStore(memories: dict.new())
}

pub fn add_memory(store: MemoryStore, mem: Memory) -> MemoryStore {
  MemoryStore(memories: dict.insert(store.memories, mem.id, mem))
}

pub fn get_memory(store: MemoryStore, id: String) -> Option(Memory) {
  case dict.get(store.memories, id) {
    Ok(mem) -> Some(mem)
    Error(_) -> None
  }
}

// Simple Jaccard similarity for FFI
pub fn similarity(a: String, b: String) -> Float {
  let set_a = string.split(a, " ") |> list.unique()
  let set_b = string.split(b, " ") |> list.unique()
  let intersection = list.filter(set_a, fn(x) { list.contains(set_b, x) })
  let union = list.unique(list.append(set_a, set_b))
  case list.length(union) {
    0 -> 0.0
    n -> int.to_float(list.length(intersection)) /. int.to_float(n)
  }
}
