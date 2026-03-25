import sqlite3
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))

def generate_mermaid():
    ROOT = Path(__file__).resolve().parent.parent
    MEM_DB = ROOT / "memory" / "whitemagic.db"
    
    # We'll use the latest clusters and edges from the causal_net log or just re-infer
    from whitemagic.core.intelligence.synthesis.causal_net import CausalNet
    from distill_strategies import load_memories, cluster_memories

    conn = sqlite3.connect(str(MEM_DB))
    memories = load_memories(conn, content_lazy=True)
    clusters = cluster_memories(memories)
    active_clusters = {k: v for k, v in clusters.items() if len(v) >= 5}
    
    net = CausalNet(MEM_DB)
    edges = net.infer_dependencies(active_clusters)
    conn.close()
    
    # Generate Mermaid
    mermaid = ["graph TD"]
    mermaid.append("  %% Whitemagic Causal Resonance Concept Map")
    
    # Nodes with labels (first 20 chars of patterns if possible)
    for k in active_clusters.keys():
        label = str(k).replace("(", "").replace(")", "").replace(", ", "_")
        mermaid.append(f"  {label}[\"{k}\"]")
    
    # Edges
    for src, dst in edges:
        s_label = src.replace("(", "").replace(")", "").replace(", ", "_")
        d_label = dst.replace("(", "").replace(")", "").replace(", ", "_")
        mermaid.append(f"  {s_label} --> {d_label}")
    
    print("\n".join(mermaid))

if __name__ == "__main__":
    generate_mermaid()
