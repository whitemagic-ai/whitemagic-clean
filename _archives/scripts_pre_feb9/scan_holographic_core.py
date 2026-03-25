import sqlite3
import os
import sys
import logging
from collections import Counter
from pathlib import Path

# Allow running from repo root without requiring installation.
REPO_ROOT = Path(__file__).resolve().parent.parent
if str(REPO_ROOT) not in sys.path:
    sys.path.insert(0, str(REPO_ROOT))

try:
    from scripts.heavens_net_v3 import extract_concepts_density
except ImportError:
    print("Could not import heavens_net_v3. Run from project root.")
    sys.exit(1)

# Config
try:
    from whitemagic.config.paths import DB_PATH as DEFAULT_DB_PATH  # type: ignore
except Exception:
    DEFAULT_DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"

DB_PATH = str(Path(os.getenv("WM_DB_PATH", str(DEFAULT_DB_PATH))).expanduser())
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')
logger = logging.getLogger("HoloScan")

def scan_core():
    logger.info(f"🔮 Connecting to Holographic Core: {DB_PATH}")
    conn = sqlite3.connect(DB_PATH)
    cursor = conn.cursor()
    
    total = cursor.execute("SELECT COUNT(*) FROM memories").fetchone()[0]
    logger.info(f"🧠 Scanning {total} neural pathways for spontaneous emergence...")
    
    # We fetch content in batches
    batch_size = 1000
    offset = 0
    
    all_insights = Counter()
    processed = 0
    
    while True:
        rows = cursor.execute(f"SELECT id, content FROM memories LIMIT {batch_size} OFFSET {offset}").fetchall()
        if not rows:
            break
            
        for row in rows:
            mem_id, content = row
            if not content: continue
            
            # Treat memory as a "file" named by its ID
            concepts = extract_concepts_density(content, mem_id)
            
            # Aggregate themes
            for c in concepts:
                if c['domain'] == 'theme':
                    all_insights[c['pattern']] += 1
                elif c['domain'] == 'entity':
                    all_insights[c['pattern']] += 1
        
        processed += len(rows)
        offset += batch_size
        print(f"   Scanned {processed}/{total} memories...", end='\r')
        
    print("\n✨ Scan Complete. Analyzing Emergence...")
    
    # Report top emergent patterns
    print("\n" + "="*40)
    print("🌟 SPONTANEOUS EMERGENCE REPORT")
    print("="*40)
    
    for pattern, count in all_insights.most_common(50):
        # Filter noise
        if len(pattern) < 5: continue
        print(f"{count:>6} x  {pattern}")
        
if __name__ == "__main__":
    scan_core()
