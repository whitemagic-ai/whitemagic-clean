#!/usr/bin/env python3
"""
Scout G005: The Great Work — Transmutation Scout
Performs the Nigredo (decomposition) analysis on the memory corpus.
Classifies memories into Novelty, Routine, and Noise to estimate the yield of the Great Work.
"""
import sqlite3
from pathlib import Path
from collections import Counter

# Configuration
DB_PATH = Path.home() / ".whitemagic" / "memory" / "whitemagic.db"
REPORT_PATH = Path("reports/great_work_transmutation.md")

# Heuristics
NOISE_TITLES = ["Checkpoint", "Session Handoff", "Twice-daily", "Summary", "Update", "Backup"]
ROUTINE_CONTENT = ["traceback", "error", "exception", "lint", "mypy", "fix", "debug"]
NOVELTY_KEYWORDS = ["concept", "architecture", "strategy", "philosophy", "insight", "discovery", "pattern", "synthesis"]

def classify_memory(title: str, content: str) -> str:
    """Classifies a memory as Novelty, Routine, or Noise."""
    title_lower = (title or "").lower()
    content_lower = (content or "").lower()
    
    # 1. Noise Filter
    if any(k.lower() in title_lower for k in NOISE_TITLES):
        return "Noise"
    
    # 2. Novelty Detection
    novelty_score = sum(1 for k in NOVELTY_KEYWORDS if k in content_lower)
    if novelty_score >= 2 or "white paper" in content_lower or "manifesto" in content_lower:
        return "Novelty"
    
    # 3. Routine/Operational
    routine_score = sum(1 for k in ROUTINE_CONTENT if k in content_lower)
    if routine_score >= 1 or len(content) < 500:
        return "Routine"
        
    return "Unknown" # Default bucket

def analyze_corpus(db_path: Path):
    """Analyzes the memory corpus."""
    if not db_path.exists():
        print(f"DB not found: {db_path}")
        return None

    conn = sqlite3.connect(db_path)
    cursor = conn.cursor()
    
    cursor.execute("SELECT title, content FROM memories WHERE memory_type != 'quarantined'")
    memories = cursor.fetchall()
    conn.close()
    
    stats = Counter()
    novelty_samples = []
    
    for title, content in memories:
        category = classify_memory(title, content)
        stats[category] += 1
        if category == "Novelty" and len(novelty_samples) < 10:
            novelty_samples.append(title)
            
    return stats, novelty_samples, len(memories)

def generate_report(stats, samples, total):
    """Generates the Nigredo report."""
    with open(REPORT_PATH, "w") as f:
        f.write("# The Great Work: Nigredo Analysis\n\n")
        f.write(f"Total Active Memories Analyzed: {total:,}\n\n")
        
        f.write("## Decomposition Results\n")
        f.write("| Category | Count | Percentage |\n")
        f.write("|----------|-------|------------|\n")
        
        for category, count in stats.most_common():
            pct = (count / total) * 100 if total > 0 else 0
            f.write(f"| {category} | {count:,} | {pct:.1f}% |\n")
            
        f.write("\n## Sample Novelty (Potential Gold)\n")
        for title in samples:
            f.write(f"- {title}\n")
            
        f.write("\n## Projection\n")
        novelty_count = stats.get("Novelty", 0)
        f.write(f"Estimated yield: {novelty_count} potential Golden Rules to be synthesized in Rubedo stage.\n")

if __name__ == "__main__":
    print("Starting Transmutation Scout (Nigredo Phase)...")
    stats, samples, total = analyze_corpus(DB_PATH)
    
    if stats:
        REPORT_PATH.parent.mkdir(parents=True, exist_ok=True)
        generate_report(stats, samples, total)
        print(f"Report generated at {REPORT_PATH}")
        print(f"Analysis complete: {total} memories processed.")
    else:
        print("Analysis failed.")
