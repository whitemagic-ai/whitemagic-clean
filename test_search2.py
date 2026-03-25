import whitemagic_rust
print("Direct search method:", hasattr(whitemagic_rust, "search_build_index"))
from whitemagic.optimization.rust_accelerators import search_build_index
print("Wrapper output:", search_build_index([{"id":"1", "title":"a", "content":"b"}]))
