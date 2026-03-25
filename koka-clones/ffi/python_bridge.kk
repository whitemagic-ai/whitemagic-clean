// Koka FFI Bridge for Python interop
module ffi/python_bridge

import std/core/exn
import std/core/string
import std/core/vector

// Effect for Python callback
effect python-call {
  fun call-python(fn-name : string, args : vector<string>) : string
}

// Handler for Python FFI
val handle-python-ffi = handler {
  return(x) -> x
  python-call(fn, args) -> {
    // FFI call to Python
    "{}({})".format(fn, args.join(","))
  }
}
