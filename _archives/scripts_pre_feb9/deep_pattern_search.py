
import sqlite3
import os
from pathlib import Path
import sys

# Configuration
REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

try:
    from whitemagic.config.paths import DB_PATH as DEFAULT_DB_PATH  # type: ignore
except Exception:
    DEFAULT_DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"

DB_PATH = str(Path(os.getenv("WM_DB_PATH", str(DEFAULT_DB_PATH))).expanduser().resolve())
KEYWORDS = [
    "pattern", "patterns", 
    "dream", "dreaming", 
    "engine", 
    "garden", "gardens", 
    "gana", "ganas", 
    "guna", "gunas", 
    "resonance", 
    "mansion", "mansions", 
    "ganying"
]

def analyze_patterns():
    print(f"🔮 Connecting to Neural Core: {DB_PATH}")
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    
    # 1. Total density check
    total = cursor.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    print(f"🧠 Scanning {total} neural pathways...")
    
    results = {}
    
    for kw in KEYWORDS:
        # Search content and metadata
        # Using simple LIKE for speed on large text. FTS would be better but requires setup.
        query = f"""
            SELECT COUNT(*) FROM memories 
            WHERE content LIKE '%{kw}%' 
            OR metadata LIKE '%{kw}%'
        """
        count = cursor.execute(query).fetchone()[0]
        results[kw] = count
        print(f"   found '{kw}': {count} hits")
        
    print("\n✨ Pattern Density Analysis:")
    sorted_results = sorted(results.items(), key=lambda x: x[1], reverse=True)
    for k, v in sorted_results:
        bar = "█" * int((v / total) * 100 * 2) if total > 0 else "" # visual bar
        print(f"   {k:<12}: {v:>5} {bar}")

    # 2. Extract specific "Hyper-Bridged" insights (containing multiple keywords)
    print("\n🌟 Searching for Hyper-Bridges (memories with >3 keywords)...")
    # This is a bit expensive, so we limit result
    # We construct a dynamic query
    [f"(content LIKE '%{kw}%')" for kw in KEYWORDS]
    # We want rows where at least 3 conditions match
    # Since SQL doesn't easily support "at least N of these booleans", we'll do it in python 
    # iterate over a subset or use a clever query if possible. 
    # For 100k rows, python iteration might be slow if fetching all content.
    # Let's try fetching just IDs and then re-fetching content for hits.
    
    # Optimization: Use the high-frequency keywords to filter first
    top_kw = sorted_results[0][0]
    cursor.execute(f"SELECT id, content FROM memories WHERE content LIKE '%{top_kw}%'")
    
    hyper_bridges = []
    
    # Analyze a sample of the most dense paths
    count_scanned = 0
    while True:
        rows = cursor.fetchmany(1000)
        if not rows:
            break
        for row in rows:
            content = row[1].lower()
            hit_count = sum(1 for kw in KEYWORDS if kw in content)
            if hit_count >= 3:
                hyper_bridges.append((row[0], hit_count, content[:100] + "..."))
        count_scanned += len(rows)
        if count_scanned > 20000: break # limit scan for speed
        
    print(f"   Found {len(hyper_bridges)} Hyper-Bridge memories.")
    for hb in hyper_bridges[:5]:
         print(f"   [Density {hb[1]}] {hb[0]}: {hb[2]}")

if __name__ == "__main__":
    analyze_patterns()
