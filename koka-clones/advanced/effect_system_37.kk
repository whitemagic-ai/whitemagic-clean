// Phase 10 Advanced Effects: File 37
module advanced_effects

// Advanced algebraic effect handlers
effect async {
  fun async-op(action : () -> a) : a
}

effect state<s> {
  fun get() : s
  fun put(x : s) : ()
}

fun handle-async(action : () -> <async|e> a) : e a {
  with handler {
    async-op(action) -> action()
  }
  action()
}
