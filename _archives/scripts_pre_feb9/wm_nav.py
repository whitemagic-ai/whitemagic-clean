#!/usr/bin/env python3
"""
WM NAV — Holographic Navigation CLI
Strategy III of Protocol 26: Navigating the Manifold.
"""

import sys
import argparse
import sqlite3
import asyncio
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

from whitemagic.core.intelligence.synthesis.causal_net import CausalNet
from scripts.satkona_v3 import run_stars_julia, load_memories

async def navigate(target_id_or_query: str):
    db_path = ROOT / "memory" / "whitemagic.db"
    conn = sqlite3.connect(str(db_path))
    
    # 1. Resolve Target Point
    target_pos = None
    target_title = "Unknown"
    
    if target_id_or_query.isdigit():
        row = conn.execute("SELECT x, y, z, w, m.title FROM holographic_coords h JOIN memories m ON h.memory_id = m.id WHERE h.memory_id = ?", (target_id_or_query,)).fetchone()
        if row:
            target_pos = list(row[:4])
            target_title = row[4]
            print(f"\n  Navigating from Memory {target_id_or_query}: \"{target_title}\"")
    
    if not target_pos:
        # Simple centroid of nearest title matches as fallback
        rows = conn.execute("SELECT x, y, z, w FROM holographic_coords h JOIN memories m ON h.memory_id = m.id WHERE m.title LIKE ? LIMIT 5", (f"%{target_id_or_query}%",)).fetchall()
        if rows:
            import numpy as np
            target_pos = np.mean(rows, axis=0).tolist()
            print(f"\n  Navigating from Search Query: \"{target_id_or_query}\" (Resolved to spatial centroid)")
        else:
            print(f"\n  [!] Could not resolve \"{target_id_or_query}\" to a spatial point.")
            conn.close()
            return

    # 2. Find Spatial Neighbors (Julia Stars)
    print("  [🌌] Searching Spatial Manifold (Julia Stars)...")
    stars_results = await run_stars_julia([target_pos])
    stars = stars_results[0] if stars_results else []
    
    # 3. Find Causal Context
    print("  [🕸️] Inferring Causal Neighborhood (Reflexive DAG)...")
    # We'll use the current cluster logic to find the node's cluster
    cx, cy = int(round(target_pos[0])), int(round(target_pos[1]))
    cluster_key = f"({cx}, {cy})"
    
    from distill_strategies import cluster_memories
    # We only need a slice for clustering efficiency if we don't have global cluster map
    memories = load_memories(conn, content_lazy=True)
    all_clusters = cluster_memories(memories)
    active_clusters = {k: v for k, v in all_clusters.items() if len(v) >= 5}
    
    net = CausalNet(db_path)
    edges = net.infer_dependencies(active_clusters)
    
    parents = [src for src, dst in edges if dst == cluster_key]
    children = [dst for src, dst in edges if src == cluster_key]

    # 4. Report
    print(f"\n  RESULTS: {target_title}")
    print("  " + "═" * 50)
    
    print("\n  [STARS] Nearest Semantic Neighbors:")
    if stars:
        for s in stars[:5]:
            s_id = s.get("id")
            s_row = conn.execute("SELECT title FROM memories WHERE id = ?", (s_id,)).fetchone()
            s_title = s_row[0] if s_row else "Unknown"
            print(f"    - {s_id}: {s_title} (Dist: {s.get('distance', 0):.4f})")
    else:
        print("    (No nearby stars identified)")

    print("\n  [CAUSAL] Conceptual Flow:")
    if parents: print(f"    Parents (Drivers): {', '.join(parents)}")
    else: print("    Parents: [Root Cluster]")
    
    print(f"    Current Cluster: {cluster_key}")
    
    if children: print(f"    Children (Driven):  {', '.join(children)}")
    else: print("    Children: [Leaf Cluster]")

    print("\n  " + "═" * 50 + "\n")
    conn.close()

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Navigate the Whitemagic Manifold.")
    parser.add_argument("target", help="Memory ID or Title search term")
    args = parser.parse_args()
    
    asyncio.run(navigate(args.target))
