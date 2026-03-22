import logging
import sys
import time

sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

logging.basicConfig(level=logging.INFO)

from whitemagic.core.memory.vector_search import get_vector_search


def main():
    vs = get_vector_search()

    # Run a test search
    query = "What is consciousness?"
    print(f"Searching for: '{query}'")

    start = time.perf_counter()
    results = vs.search(query, limit=5)
    end = time.perf_counter()

    print(f"Search completed in {(end - start) * 1000:.2f}ms")
    for r in results:
        print(f" - {r.score:.4f} | {r.memory_id} | {r.title}")

if __name__ == "__main__":
    main()
