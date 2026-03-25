#!/usr/bin/env python3
"""
Whitemagic Dream Feeder
=======================
Manually feeds recent Markdown artifacts into the Dream State
to generate immediate insights, bypassing the database ingestion lag.
"""

import sys
import logging
from pathlib import Path
from typing import List, Dict, Any

# Add core_system to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.patterns.emergence.dream_state import DreamState

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(message)s')
logger = logging.getLogger("dream_feeder")

ARTIFACTS_DIR = "53737b45-d3b0-435f-a93d-fecaa99910ec")"
FILES_TO_FEED = [
    "chronological_timeline.md",
    "v9_roadmap.md",
    "polyglot_census.md",
    "engine_audit.md"
]

def parse_markdown_to_patterns(filepath: Path) -> List[Dict[str, Any]]:
    """Convert markdown lines into 'Pattern' dictionaries."""
    patterns = []
    try:
        with open(filepath, 'r') as f:
            lines = f.readlines()
        
        filename = filepath.name
        
        for line in lines:
            line = line.strip()
            # Heuristic: Treat bolded items or list items as patterns
            if line.startswith("- **") or line.startswith("* **"):
                # Extract content between **...**
                parts = line.split("**")
                if len(parts) >= 3:
                    concept = parts[1]
                    desc = parts[2].strip(" :.-")
                    
                    patterns.append({
                        "id": f"P_{filename}_{len(patterns)}",
                        "pattern": f"{concept}: {desc}",
                        "domain": filename.replace(".md", ""),
                        "confidence": 0.85
                    })
            elif line.startswith("## "):
                patterns.append({
                    "id": f"H_{filename}_{len(patterns)}",
                    "pattern": f"Phase: {line.replace('## ', '')}",
                    "domain": "roadmap",
                    "confidence": 0.9
                })
                
    except Exception as e:
        logger.error(f"Failed to read {filepath}: {e}")
        
    return patterns

def main():
    logger.info("🌌 Initializing Dream State Manual Feed...")
    
    # 1. Collect Patterns from Artifacts
    all_patterns = []
    for fname in FILES_TO_FEED:
        fpath = ARTIFACTS_DIR / fname
        if fpath.exists():
            logger.info(f"📖 Reading artifact: {fname}")
            new_patterns = parse_markdown_to_patterns(fpath)
            all_patterns.extend(new_patterns)
            logger.info(f"   -> Extracted {len(new_patterns)} patterns")
        else:
            logger.warning(f"⚠️ Artifact not found: {fpath}")
            
    if not all_patterns:
        logger.error("❌ No patterns extracted. Aborting dream.")
        return
        
    # 2. Initialize Dream State
    dream = DreamState()
    
    # 3. Force-Feed Patterns (Bypassing PatternEngine)
    logger.info(f"\n💤 Entering Dream State with {len(all_patterns)} active patterns...")
    
    # Use internal method to synthesize
    insights = dream._synthesize_patterns(all_patterns)
    
    # 4. Display Results
    print("\n" + "="*60)
    print("✨ DREAM INSIGHTS GENERATED")
    print("="*60)
    
    for i, insight in enumerate(insights, 1):
        print(f"\n🔮 Insight #{i}:")
        print(f"   {insight.insight}")
        print(f"   Novelty: {insight.novelty_score:.2f} | Practical Value: {insight.practical_value:.2f}")
        print(f"   Sources: {', '.join(insight.synthesized_from)}")

if __name__ == "__main__":
    main()
