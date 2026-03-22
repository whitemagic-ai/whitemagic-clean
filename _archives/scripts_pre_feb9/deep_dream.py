
import sqlite3
import json
from collections import Counter
from pathlib import Path

DB_PATH = Path("staging/project_memory/whitemagic.db")

def deep_dream():
    print("💤 Entering Deep Dream State (Analyzing 87k+ Memories)...")
    
    conn = sqlite3.connect(DB_PATH)
    conn.row_factory = sqlite3.Row
    cursor = conn.cursor()
    
    # Fetch all metadata
    print("   Loading neural pathways...")
    cursor.execute("SELECT content, metadata FROM memories")
    
    rows = cursor.fetchall()
    print(f"   Loaded {len(rows)} neural pathways.")
    
    # Analysis Containers
    concepts_by_lang = {
        'python': set(),
        'rust': set(),
        'elixir': set(),
        'javascript': set(),
        'zig': set(),
        'markdown': set()
    }
    
    pattern_frequency = Counter()
    
    print("   Tracing synaptic connections...")
    
    for row in rows:
        pattern = row['content']
        pattern_frequency[pattern] += 1
        
        try:
            meta = json.loads(row['metadata'])
            source_id = meta.get('id', '') # e.g. "filename.py_C1"
            
            # Heuristic language detection from source ID/filename
            if '.py' in source_id:
                concepts_by_lang['python'].add(pattern)
            elif '.rs' in source_id:
                concepts_by_lang['rust'].add(pattern)
            elif '.ex' in source_id or '.exs' in source_id:
                concepts_by_lang['elixir'].add(pattern)
            elif '.js' in source_id or '.ts' in source_id:
                concepts_by_lang['javascript'].add(pattern)
            elif '.zig' in source_id:
                concepts_by_lang['zig'].add(pattern)
            elif '.md' in source_id:
                concepts_by_lang['markdown'].add(pattern)
                
        except:
            continue

    print("\n✨ DEEP DREAM MANIFESTATION")
    print("==========================================")
    
    # 1. Hyper-Bridges: Concepts shared between Rust and Python (The Core Bridge)
    py_rs_bridge = concepts_by_lang['python'].intersection(concepts_by_lang['rust'])
    print(f"\n🌉 Python-Rust Intersections ({len(py_rs_bridge)} Shared Concepts):")
    for c in list(py_rs_bridge)[:10]:
        print(f"   - {c}")
        
    # 2. The Trinity: Python, Rust, Elixir
    trinity = concepts_by_lang['python'].intersection(concepts_by_lang['rust']).intersection(concepts_by_lang['elixir'])
    print(f"\nTRIAD-LINK :: Concepts spanning Python, Rust, and Elixir ({len(trinity)}):")
    for c in list(trinity)[:10]:
        print(f"   - {c}")

    # 3. Dominant Thoughtforms (Top Frequency)
    print("\n🧠 Dominant Thoughtforms (Most Frequent Patterns):")
    for pattern, count in pattern_frequency.most_common(10):
        print(f"   - {pattern}: {count} occurrences")
        
    # 4. Novelty Search (Zig-only concepts?)
    zig_only = concepts_by_lang['zig'] - concepts_by_lang['python'] - concepts_by_lang['rust']
    print("\n⚡ Zig-Exclusive Concepts (The Hidden Physics):")
    for c in list(zig_only)[:10]:
        print(f"   - {c}")

    conn.close()

if __name__ == "__main__":
    deep_dream()
