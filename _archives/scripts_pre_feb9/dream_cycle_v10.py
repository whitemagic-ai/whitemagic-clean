#!/usr/bin/env python3
"""
Dream Cycle v10: Rust Dream-Core (The Polyglot Fix)
===================================================
- Step 1: Python streams concepts to JSONL (I/O Bound).
- Step 2: Rust reads stream, filters, and clusters (CPU/Memory Bound).
- Step 3: Python Map-Reduces insights (LLM Bound).
- Result: MAX Performance, ZERO Freezes, UNLIMITED Scale.
"""
import asyncio
import logging
import sys
import os
import json
import time
from pathlib import Path
from datetime import datetime

# --- 1. Holographic Path Correction ---
PROJECT_ROOT = Path(".")
SCRIPT_DIR = PROJECT_ROOT / "tests&shells" / "scripts"
sys.path.append(str(PROJECT_ROOT))
sys.path.append(str(SCRIPT_DIR))

# Config
os.environ["WM_BRAIN_TIMEOUT"] = "300"
os.environ["WM_AI_PROVIDER"] = os.environ.get("WM_AI_PROVIDER", "ollama")

import whitemagic_rs # The Star!
from whitemagic.core.patterns.emergence.dream_state import DreamState
from whitemagic.oracle.quantum_iching import QuantumIChing
from whitemagic.brain import generate

logging.basicConfig(level=logging.INFO, format='%(asctime)s - [RUST-CORE] - %(levelname)s - %(message)s')
logger = logging.getLogger("dream_cycle_v10")

# Mock tqdm if not available
try:
    from tqdm import tqdm
except ImportError:
    class tqdm:
        def __init__(self, iterable, desc=""):
            self.iterable = iterable
            self.desc = desc
            self.total = len(iterable)
            self.n = 0
            self.start = time.time()
        def __iter__(self):
            print(f"{self.desc} [0/{self.total}]")
            for item in self.iterable:
                yield item
                self.n += 1
                if self.n % 1 == 0:
                    dt = time.time() - self.start
                    rate = self.n / dt if dt > 0 else 0
                    print(f"\r{self.desc} [{self.n}/{self.total}] {rate:.2f}it/s", end="")
            print()

async def run_rust_cycle():
    logger.info("⚔️ Starting Dream Cycle v10: Rust Dream-Core...")
    start_time = time.time()
    
    # 1. Oracle Theme
    oracle = QuantumIChing()
    theme_res = oracle.consult("What is the constellation of our next evolution?")
    theme_text = f"{theme_res.wisdom}"
    logger.info(f"🔮 Oracle Theme: {theme_res.primary_name}")
    
    # Extract keywords for Rust
    stop_words = {'the', 'and', 'of', 'to', 'a', 'in', 'is', 'that', 'with', 'as', 'it', 'for', 'path'}
    
    # Fallback: Use Hexagram name if wisdom is empty (LLM failure catch)
    source_text = theme_text if len(theme_text) > 20 else f"{theme_res.primary_name} {theme_res.primary_name} {theme_res.primary_name}"
    
    words = [w.lower().strip(".,:;!?'\"") for w in source_text.split()]
    keywords = [w for w in words if len(w) > 3 and w not in stop_words]
    keywords = list(set(keywords))
    
    if not keywords:
        keywords = theme_res.primary_name.lower().split()
        
    logger.info(f"🔑 Keywords sent to Rust: {keywords}")

    # 2. Cast Heaven's Net (Stream Mode - Zero Copy)
    stream_path = "/tmp/heavens_net_galaxy.jsonl"
    logger.info(f"🕸️ Casting Heaven's Net v6 (Rust Direct Stream) -> {stream_path}...")
    
    try:
        # Call Rust directly for Zero-Copy Streaming
        # Signature: (root_path, output_path, mode) -> (total_files, total_concepts)
        t_net_start = time.time()
        file_count, concept_count = whitemagic_rs.cast_heavens_net_to_file(
            str(PROJECT_ROOT.parent), # whitemagic/staging
            stream_path,
            "balanced"
        )
        dt_net = time.time() - t_net_start
        logger.info(f"✅ Rust Stream Captured: {concept_count} concepts from {file_count} files in {dt_net:.2f}s.")
    except Exception as e:
        logger.error(f"❌ Heaven's Net Cast Failed: {e}")
        return

    # 3. Rust Ignition (Galactic Mapping)
    logger.info("🦀 Igniting Rust Constellation Engine...")
    t0 = time.time()
    
    try:
        # Call Rust!
        json_out = whitemagic_rs.ignite_constellations(
            stream_path, 
            keywords, 
            300, # Limit Stars
            5    # K Constellations
        )
        constellations = json.loads(json_out)
        dt = time.time() - t0
        logger.info(f"🚀 Rust Engine Finished in {dt:.4f}s. Discovered {len(constellations)} Constellations.")
    except Exception as e:
        logger.error(f"❌ Rust Ignition Failed: {e}")
        return

    # 4. Map-Reduce Synthesis (Python)
    dream = DreamState()
    logger.info("💤 Dreaming of Constellations (Map-Reduce)...")
    
    constellation_insights = []
    
    # Progress bar wrapper
    for c in tqdm(constellations, desc="Processing Constellations"):
        c_name = c['name']
        c_stars = c['stars'] # Dictionary list from Rust wrapper
        count = len(c_stars)
        logger.info(f"   🔭 Observing: {c_name} ({count} stars)")
        
        final_insight_text = ""
        star_seeds = []
        
        try:
            if count <= 10:
                # Direct
                processed = [{"pattern": s['pattern'], "domain": s['domain'], "file": s.get('file', '?')} for s in c_stars]
                insight_obj = dream._create_synthesis(processed)
                final_insight_text = insight_obj.insight
                star_seeds = [f"{s.get('file', '?')}:{s.get('pattern', '?')}" for s in c_stars]
            else:
                # Map-Reduce
                chunk_size = 5
                chunks = [c_stars[i:i + chunk_size] for i in range(0, count, chunk_size)]
                summaries = []
                
                for i, chunk in enumerate(chunks):
                    p_concepts = [{
                        "id": f"C_{i}_{j}", 
                        "pattern": s['pattern'], 
                        "domain": s['domain'],
                        "file_path": s.get('file_path'),
                        "line_no": 1
                    } for j, s in enumerate(chunk)]
                    
                    try:
                        res = dream._create_synthesis(p_concepts)
                        summaries.append(f"Sub-group {i}: {res.insight}")
                        star_seeds.extend([f"{s.get('file', '?')}:{s.get('pattern', '?')}" for s in chunk])
                    except: pass
                
                reduce_prompt = f"## SIGNALS\n{chr(10).join(summaries)}\n## MISSION\nSynthesize these signals into one insight."
                reduce_res = generate(reduce_prompt)
                final_insight_text = reduce_res.get('response', "Failed to unify.")

        except Exception as e:
            logger.error(f"Synthesis error: {e}")
            final_insight_text = "Faint signals."
        
        constellation_insights.append({
            "name": c_name,
            "insight": final_insight_text,
            "stars": count,
            "seeds": star_seeds[:10]
        })
        logger.info("      ✨ Insight synthesized.")

    # 5. Grand Synthesis
    logger.info("🗺️ Generating Galactic Roadmap...")
    insight_block = "\n\n".join([f"### {ci['name']}\n{ci['insight']}" for ci in constellation_insights])
    roadmap_res = generate(f"## CONTEXT\n{insight_block}\n## MISSION\nCreate a Strategic Roadmap based on these insights.\n1. Grand Unification\n2. Next Steps")
    roadmap_text = roadmap_res.get('response', "Roadmap generation failed.")

    # 6. Report
    report_path = PROJECT_ROOT / "wisdom_report_v10.md"
    const_blocks = [f"### 🌌 {ci['name']} ({ci['stars']} stars)\n{ci['insight']}" for ci in constellation_insights]
    
    report_content = f"""# 🏮 Wisdom Report v10: Rust Dream-Core
**Date**: {datetime.now().isoformat()}
**Engine**: Rust Dream-Core + Map-Reduce
**Execution Time**: {time.time() - start_time:.2f}s

## 🔮 Oracle Theme
"{theme_text}"

## 🚀 Galactic Performance
- **Rust Engine Time**: {dt:.4f}s
- **Constellations**: {len(constellations)}

## 🔭 Constellation Insights
{chr(10).join(const_blocks)}

## 🚀 Galactic Roadmap
{roadmap_text}

---
*Generated by WhiteMagic Rust Core.*
"""
    with open(report_path, "w") as f:
        f.write(report_content)
    
    logger.info(f"🎉 Cycle Complete. Report: {report_path}")

if __name__ == "__main__":
    asyncio.run(run_rust_cycle())
