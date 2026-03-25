#!/usr/bin/env python3
"""
Heaven's Net Introspector
=========================
Recursively crawls the data lake to feed the Dream Engine.
"Nothing slips through it."
"""

import sys
import logging
import json
from pathlib import Path
from typing import List, Dict, Any

# Add core_system to path
sys.path.insert(0, str(Path(__file__).parent.parent))

from whitemagic.core.patterns.emergence.dream_state import DreamState

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(message)s')
logger = logging.getLogger("heavens_net")

SUPPORTED_EXTENSIONS = {'.md', '.txt', '.json', '.yaml', '.yml'}
IGNORE_DIRS = {'__pycache__', '.git', 'node_modules', 'venv', '.venv'}

def extract_patterns_from_file(filepath: Path) -> List[Dict[str, Any]]:
    """Extract patterns/concepts from a single file based on its type."""
    patterns = []
    try:
        content = ""
        with open(filepath, 'r', errors='ignore') as f:
            content = f.read()
            
        filename = filepath.name
        rel_path = filepath.parent.name + "/" + filename
        
        # Strategy 1: Titles/Headers (Markdown)
        if filepath.suffix == '.md':
            for line in content.splitlines():
                if line.startswith("# ") or line.startswith("## "):
                    concept = line.lstrip("# ").strip()
                    if len(concept) > 5:
                        patterns.append({
                            "id": f"DOC_{filename}_{len(patterns)}",
                            "pattern": f"{concept} (from {rel_path})",
                            "domain": "documentation",
                            "confidence": 0.8
                        })
                        
        # Strategy 2: Keys (JSON/YAML) - simplified for JSON
        elif filepath.suffix == '.json':
            try:
                data = json.loads(content)
                if isinstance(data, dict):
                    # Check for specific schemas
                    if "title" in data:
                        patterns.append({
                            "id": f"DATA_{filename}_1",
                            "pattern": f"{data['title']} (Artifact)",
                            "domain": "artifact",
                            "confidence": 0.9
                        })
            except:
                pass

        # Strategy 3: Heuristic scan for "Concept words" (General)
        # Very simple: look for capitalized words in sequence (e.g. "Dharma Core")
        # This is primitive but effective for "dreaming" up associations.
        
    except Exception as e:
        logger.warning(f"Failed to read {filepath}: {e}")
        
    return patterns

def crawl_and_dream(root_path: Path, max_files: int = 50):
    logger.info(f"🕸️  Casting Heaven's Net over: {root_path}")
    
    all_patterns = []
    file_count = 0
    
    for path in root_path.rglob("*"):
        if file_count >= max_files:
            break
            
        # Skip ignore dirs
        if any(part in IGNORE_DIRS for part in path.parts):
            continue
            
        if path.is_file() and path.suffix in SUPPORTED_EXTENSIONS:
            new_patterns = extract_patterns_from_file(path)
            if new_patterns:
                all_patterns.extend(new_patterns)
                file_count += 1
                logger.info(f"   Caught {len(new_patterns)} concepts from {path.name}")

    if not all_patterns:
        logger.error("❌ The Net came up empty.")
        return

    # Enter Dream State
    logger.info(f"\n💤 Entering Deep Dream with {len(all_patterns)} concepts caught from {file_count} files...")
    dream = DreamState()
    
    # Force feed
    insights = dream._synthesize_patterns(all_patterns)
    
    # Report
    print("\n" + "="*60)
    print("✨ DEEP DREAM INSIGHTS")
    print("="*60)
    
    for i, insight in enumerate(insights, 1):
        print(f"\n🔮 Insight #{i}:")
        print(f"   {insight.insight}")
        print(f"   Novelty: {insight.novelty_score:.2f} | Strength: {insight.practical_value:.2f}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: introspect.py <directory_to_crawl>")
        sys.exit(1)
        
    target_dir = Path(sys.argv[1])
    if not target_dir.exists():
        print(f"Error: Directory {target_dir} does not exist.")
        sys.exit(1)
        
    crawl_and_dream(target_dir)
