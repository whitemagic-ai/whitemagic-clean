#!/usr/bin/env python3
"""
WhiteMagic v15.9 — Extended Activation Sequence
=================================================

Runs ALL engines (original 9 + 12 newly-wired v15.8/v15.9 engines)
across the expanded 111K+ memory corpus:

  ORIGINAL (from v15.7):
    0. DB Stats
    1. Galactic Sweep (paginated, full corpus)
    2. Association Mining (keyword + semantic)
    3. Constellation Detection (HDBSCAN)
    4. Graph Topology + Bridge Discovery
    5. Dream Cycle (all 8 phases)
    6. Harmony Vector
    7. Wu Xing Balance
    8. Graph Walker Test

  NEW (v15.8/v15.9):
    9.  Causal Mining — temporal-semantic directed edges
    10. Emergence Scan — resonance cascade, convergence detection
    11. Constellation Auto-Merge — merge converging clusters
    12. Satkona Fusion — multi-signal ranking
    13. Multi-Spectral Reasoning — I Ching + Wu Xing + Art of War + Zodiac
    14. Novelty Detection — corpus novelty scoring
    15. Bridge Synthesis — cross-community insight generation
    16. Knowledge Graph Analysis — entity-relation triples
    17. Pattern Consciousness Status — autonomous learner state
    18. Guideline Evolution — self-modifying system guidelines
    19. Elemental Optimization — Wu Xing optimization pass
    20. Galactic Stats — zone distribution report

Usage:
    python scripts/run_extended_activation.py              # Full sequence
    python scripts/run_extended_activation.py --quick      # Skip slow ops
    python scripts/run_extended_activation.py --step causal # Single step
"""

import argparse
import json
import logging
import os
import sys
import time
from datetime import datetime
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(ROOT))
os.environ["WM_SILENT_INIT"] = "1"

logging.basicConfig(
    level=logging.INFO,
    format="%(asctime)s [%(levelname)s] %(name)s: %(message)s",
    datefmt="%H:%M:%S",
)
logger = logging.getLogger("activation_ext")

REPORT_PATH = ROOT / "reports" / f"activation_extended_{datetime.now().strftime('%Y%m%d_%H%M%S')}.json"


# ── Helpers ──────────────────────────────────────────────────

def banner(step_num, emoji, title):
    print(f"\n{'=' * 70}")
    print(f"{emoji} STEP {step_num}: {title}")
    print("=" * 70)


def safe_json(obj, max_len=300):
    """Compact JSON for printing."""
    try:
        s = json.dumps(obj, default=str, indent=None)
        return s[:max_len] + "..." if len(s) > max_len else s
    except Exception:
        return str(obj)[:max_len]


# ══════════════════════════════════════════════════════════════
# ORIGINAL STEPS (0–8)
# ══════════════════════════════════════════════════════════════

def step_db_stats():
    banner(0, "📊", "DATABASE STATISTICS")
    from whitemagic.core.memory.unified import get_unified_memory
    um = get_unified_memory()
    stats = um.get_stats()
    print(f"  Memories: {stats.get('total_memories', '?'):,}")
    print(f"  DB size: {stats.get('db_size_kb', 0) / 1024:.1f} MB")

    with um.backend.pool.connection() as conn:
        assoc_count = conn.execute("SELECT COUNT(*) FROM associations").fetchone()[0]
        typed_count = conn.execute("SELECT COUNT(*) FROM associations WHERE relation_type != 'associated_with'").fetchone()[0]
        holo_count = conn.execute("SELECT COUNT(*) FROM holographic_coords").fetchone()[0]
        embed_count = conn.execute("SELECT COUNT(*) FROM memory_embeddings").fetchone()[0]
        tag_count = conn.execute("SELECT COUNT(*) FROM tags").fetchone()[0]
        try:
            constellation_count = conn.execute("SELECT COUNT(*) FROM constellation_membership").fetchone()[0]
        except Exception:
            constellation_count = 0
        try:
            kg_count = conn.execute("SELECT COUNT(*) FROM knowledge_graph").fetchone()[0]
        except Exception:
            kg_count = 0
        try:
            causal_count = conn.execute("SELECT COUNT(*) FROM associations WHERE relation_type IN ('led_to','influenced','preceded','caused')").fetchone()[0]
        except Exception:
            causal_count = 0

    print(f"  Associations: {assoc_count:,} ({typed_count:,} typed, {causal_count:,} causal)")
    print(f"  Holographic coords: {holo_count:,}")
    print(f"  Embeddings: {embed_count:,}")
    print(f"  Tags: {tag_count:,}")
    print(f"  Constellation memberships: {constellation_count:,}")
    print(f"  Knowledge graph triples: {kg_count:,}")

    return {
        "memories": stats.get("total_memories", 0),
        "associations": assoc_count,
        "typed_associations": typed_count,
        "causal_associations": causal_count,
        "holographic_coords": holo_count,
        "embeddings": embed_count,
        "tags": tag_count,
        "constellation_memberships": constellation_count,
        "knowledge_graph_triples": kg_count,
        "db_size_mb": round(stats.get("db_size_kb", 0) / 1024, 1),
    }


def step_galactic_sweep():
    banner(1, "🌌", "GALACTIC SWEEP (PAGINATED)")
    from whitemagic.core.memory.galactic_map import get_galactic_map
    gmap = get_galactic_map()

    start = time.perf_counter()
    report = gmap.full_sweep(batch_size=2000)
    elapsed = time.perf_counter() - start

    print(f"  Memories mapped: {report.memories_updated}/{report.total_memories}")
    print(f"  Duration: {elapsed:.1f}s")
    print("  Zone distribution:")
    n = max(report.total_memories, 1)
    for zone_name, count in report.zone_counts.items():
        pct = count / n * 100
        bar = "█" * int(pct / 2)
        print(f"    {zone_name:>12}: {count:5,d} ({pct:5.1f}%) {bar}")

    print(f"  Core: {report.core_count:,}  |  Far Edge: {report.edge_count:,}  |  Protected: {report.protected_count:,}")
    print(f"  Avg retention: {report.avg_retention:.4f}  |  Avg distance: {report.avg_distance:.4f}")
    return report.to_dict()


def step_association_mining(quick=False):
    banner(2, "🔗", "ASSOCIATION MINING")
    from whitemagic.core.memory.association_miner import get_association_miner
    miner = get_association_miner(max_proposals=100, persist=True)

    print("  [2a] Keyword Jaccard mining...")
    start = time.perf_counter()
    report_kw = miner.mine(sample_size=300)
    elapsed_kw = time.perf_counter() - start
    print(f"    Sampled: {report_kw.memories_sampled}, Pairs: {report_kw.pairs_evaluated:,}")
    print(f"    Proposed: {report_kw.links_proposed}, Created: {report_kw.links_created}")
    print(f"    Duration: {elapsed_kw:.1f}s")

    result = {"keyword_mining": {
        "sampled": report_kw.memories_sampled,
        "pairs_evaluated": report_kw.pairs_evaluated,
        "links_proposed": report_kw.links_proposed,
        "links_created": report_kw.links_created,
        "duration_ms": report_kw.duration_ms,
    }}

    if not quick:
        print("  [2b] Semantic embedding mining...")
        start = time.perf_counter()
        report_sem = miner.mine_semantic(min_similarity=0.50, strong_threshold=0.70, max_proposals=50, persist=True)
        elapsed_sem = time.perf_counter() - start
        print(f"    Pairs: {report_sem.pairs_evaluated:,}, Proposed: {report_sem.links_proposed}, Created: {report_sem.links_created}")
        print(f"    Duration: {elapsed_sem:.1f}s")
        result["semantic_mining"] = {
            "pairs_evaluated": report_sem.pairs_evaluated,
            "links_proposed": report_sem.links_proposed,
            "links_created": report_sem.links_created,
            "duration_ms": report_sem.duration_ms,
        }
    return result


def step_constellation_detection():
    banner(3, "✨", "CONSTELLATION DETECTION")
    from whitemagic.core.memory.constellations import get_constellation_detector
    detector = get_constellation_detector()

    start = time.perf_counter()
    report = detector.detect(sample_limit=50000)
    elapsed = time.perf_counter() - start

    print(f"  Algorithm: {report.algorithm}")
    print(f"  Memories scanned: {report.memories_scanned:,}")
    print(f"  Constellations found: {report.constellations_found}")
    print(f"  Largest constellation: {report.largest_constellation} members")
    print(f"  Duration: {elapsed:.1f}s")

    if report.constellations:
        print("\n  Top constellations:")
        for c in report.constellations[:10]:
            print(f"    🌟 {c.name} ({len(c.member_ids)} members, zone={c.zone}, stability={c.stability:.2f})")
            if c.dominant_tags:
                print(f"       tags: {', '.join(c.dominant_tags[:5])}")
    return report.to_dict()


def step_graph_topology():
    banner(4, "🕸️", "GRAPH TOPOLOGY ANALYSIS")
    from whitemagic.core.memory.graph_engine import get_graph_engine
    engine = get_graph_engine()

    print("  Rebuilding graph (with quality filter)...")
    start = time.perf_counter()
    build = engine.rebuild(sample_limit=30000, quality_filter=True)
    elapsed = time.perf_counter() - start
    print(f"  Graph built in {elapsed:.1f}s — {build.get('nodes', 0):,} nodes, {build.get('edges', 0):,} edges")
    print(f"  Noise filtered: {build.get('noise_filtered', 0):,}")

    stats = engine.get_stats()
    print(f"  Components: {stats.get('connected_components', 0):,}, Density: {stats.get('density', 0):.6f}")

    bridges = engine.find_bridge_nodes(top_n=10)
    print(f"  Bridge nodes: {len(bridges)}")
    for b in bridges[:5]:
        print(f"    🌉 {b.get('memory_id', '?')[:12]}... (betweenness={b.get('betweenness', 0):.6f})")

    try:
        communities = engine.detect_communities()
        print(f"  Communities: {len(communities)}")
    except Exception:
        communities = []

    try:
        pr = engine.pagerank()
        top_pr = sorted(pr.items(), key=lambda x: x[1], reverse=True)[:5]
        print("  Top PageRank:")
        for nid, score in top_pr:
            print(f"    📊 {nid[:12]}... (PR={score:.6f})")
    except Exception:
        pass

    return {"stats": stats, "bridges": len(bridges), "communities": len(communities), "noise_filtered": build.get("noise_filtered", 0)}


def step_dream_cycle(quick=False):
    if quick:
        banner(5, "💤", "DREAM CYCLE (SKIPPED)")
        return {"skipped": True}

    banner(5, "💤", "DREAM CYCLE")
    try:
        from whitemagic.core.dreaming.dream_cycle import get_dream_cycle
        cycle = get_dream_cycle()
        start = time.perf_counter()
        results_phases = {}
        phase_methods = [
            ("triage", cycle._dream_triage),
            ("consolidation", cycle._dream_consolidation),
            ("serendipity", cycle._dream_serendipity),
            ("governance", cycle._dream_governance),
            ("narrative", cycle._dream_narrative),
            ("kaizen", cycle._dream_kaizen),
            ("oracle", cycle._dream_oracle),
            ("decay", cycle._dream_decay),
        ]
        for phase_name, method in phase_methods:
            t0 = time.perf_counter()
            try:
                result = method()
                dt = time.perf_counter() - t0
                results_phases[phase_name] = result
                print(f"    💤 {phase_name} ({dt:.1f}s): {safe_json(result)}")
            except Exception as e:
                dt = time.perf_counter() - t0
                results_phases[phase_name] = {"error": str(e)}
                print(f"    ❌ {phase_name} ({dt:.1f}s): {e}")
        elapsed = time.perf_counter() - start
        print(f"\n  All dream phases complete in {elapsed:.1f}s")
        return results_phases
    except Exception as e:
        print(f"  ❌ Dream cycle error: {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_harmony_vector():
    banner(6, "🎵", "HARMONY VECTOR")
    try:
        from whitemagic.harmony.vector import get_harmony_vector
        hv = get_harmony_vector()
        snap = hv.snapshot()
        assessment = snap.to_dict()
        for key in ["sattva", "rajas", "tamas", "karma_debt", "galactic_vitality", "tool_diversity", "harmony"]:
            val = assessment.get(key)
            if val is not None and isinstance(val, (int, float)):
                bar = "█" * int(float(val) * 20)
                print(f"    {key:>20}: {val:.4f} {bar}")
        return assessment
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


def step_wu_xing():
    banner(7, "🔥", "WU XING BALANCE")
    try:
        from whitemagic.wu_xing import get_elemental_balance
        balance = get_elemental_balance()
        # Handle both old format (elements dict) and new format (flat keys)
        cycle = balance.get("cycle", balance.get("current_phase", "?"))
        print(f"  Current phase: {cycle}")
        elements = balance.get("elements", {})
        if elements and isinstance(elements, dict):
            for elem, val in elements.items():
                bar = "█" * int(float(val) * 20) if isinstance(val, (int, float)) else ""
                print(f"    {elem:>8}: {val:.3f} {bar}")
        else:
            for key in ("balance", "harmony"):
                val = balance.get(key)
                if val is not None and isinstance(val, (int, float)):
                    bar = "█" * int(float(val) * 20)
                    print(f"    {key:>8}: {val:.3f} {bar}")
        return balance
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


def step_graph_walker():
    banner(8, "🚶", "GRAPH WALKER TEST")
    try:
        from whitemagic.core.memory.graph_walker import get_graph_walker
        from whitemagic.core.memory.unified import get_unified_memory
        walker = get_graph_walker()
        um = get_unified_memory()

        with um.backend.pool.connection() as conn:
            row = conn.execute(
                """SELECT m.id, m.title FROM memories m
                   JOIN associations a ON m.id = a.source_id
                   WHERE m.importance > 0.7
                   GROUP BY m.id HAVING COUNT(*) > 5
                   ORDER BY m.importance DESC LIMIT 1"""
            ).fetchone()

        if not row:
            print("  No high-importance connected memory found")
            return {"error": "no seed"}

        seed_id, seed_title = row[0], row[1] or row[0][:12]
        print(f"  Seed: {seed_title} ({seed_id[:12]}...)")
        result = walker.walk(seed_ids=[seed_id], hops=3, top_k=5, enforce_causality=False)
        print(f"  Nodes visited: {result.unique_nodes_visited}, Paths: {result.paths_explored}, Duration: {result.duration_ms:.0f}ms")
        for i, path in enumerate(result.paths[:3]):
            print(f"    Path {i+1}: {' → '.join(n[:8] for n in path.nodes)} (score={path.total_score:.6f})")
        return {"seed": seed_id, "nodes_visited": result.unique_nodes_visited, "paths": result.paths_explored, "duration_ms": result.duration_ms}
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


# ══════════════════════════════════════════════════════════════
# NEW v15.8/v15.9 STEPS (9–20)
# ══════════════════════════════════════════════════════════════

def step_causal_mining():
    banner(9, "⚡", "CAUSAL MINING")
    try:
        from whitemagic.core.memory.causal_miner import get_causal_miner
        miner = get_causal_miner()
        start = time.perf_counter()
        report = miner.mine(sample_size=300)
        elapsed = time.perf_counter() - start
        d = report.to_dict()
        print(f"  Memories sampled: {d.get('memories_sampled', '?')}")
        print(f"  Pairs evaluated: {d.get('pairs_evaluated', '?'):,}")
        print(f"  Causal edges found: {d.get('edges_created', d.get('links_created', '?'))}")
        print(f"  Duration: {elapsed:.1f}s")
        if d.get("top_causal_chains"):
            print("  Top causal chains:")
            for chain in d["top_causal_chains"][:5]:
                print(f"    ⚡ {chain}")
        return d
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_emergence_scan():
    banner(10, "🌊", "EMERGENCE SCAN")
    try:
        from whitemagic.core.intelligence.agentic.emergence_engine import (
            get_emergence_engine,
        )
        engine = get_emergence_engine()
        engine.start()
        start = time.perf_counter()
        insights = engine.scan_for_emergence()
        elapsed = time.perf_counter() - start
        print(f"  Insights found: {len(insights)}")
        print(f"  Duration: {elapsed:.1f}s")
        for i, insight in enumerate(insights[:10]):
            d = insight.to_dict() if hasattr(insight, 'to_dict') else str(insight)
            if isinstance(d, dict):
                print(f"    🌊 [{d.get('type', '?')}] {d.get('description', d.get('content', ''))[:100]}")
                if d.get('confidence'):
                    print(f"       confidence: {d['confidence']:.2f}")
            else:
                print(f"    🌊 {str(d)[:120]}")
        return {"insights_found": len(insights), "insights": [i.to_dict() if hasattr(i, 'to_dict') else str(i) for i in insights[:20]]}
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_constellation_merge():
    banner(11, "🔄", "CONSTELLATION AUTO-MERGE")
    try:
        from whitemagic.core.memory.constellations import get_constellation_detector
        detector = get_constellation_detector()
        start = time.perf_counter()
        result = detector.auto_merge(max_distance=0.5, min_shared_tags=2)
        elapsed = time.perf_counter() - start
        print(f"  Status: {result.get('status')}")
        print(f"  Merges performed: {result.get('merges', 0)}")
        print(f"  Constellations: {result.get('constellations_before', '?')} → {result.get('constellations_after', '?')}")
        print(f"  Duration: {elapsed:.1f}s")
        for m in result.get("merge_log", [])[:5]:
            print(f"    🔄 {m.get('absorbed')} → {m.get('into')} (dist={m.get('distance', '?')}, tags={m.get('shared_tags', [])})")
        return result
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


def step_satkona_fusion():
    banner(12, "✡", "SATKONA FUSION")
    try:
        from whitemagic.core.fusion.satkona_fusion import fuse_signals_with_fusion
        start = time.perf_counter()
        result = fuse_signals_with_fusion(signals={}, clusters={}, memories={}, agg={})
        elapsed = time.perf_counter() - start
        print(f"  Duration: {elapsed:.1f}s")
        print(f"  Result: {safe_json(result)}")
        return result
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_multispectral_reasoning():
    banner(13, "🔮", "MULTI-SPECTRAL REASONING")
    try:
        from whitemagic.core.intelligence.multi_spectral_reasoning import get_reasoner
        reasoner = get_reasoner()
        questions = [
            "What patterns emerge from the convergence of Aria-era memories with the modern architecture?",
            "How should WhiteMagic's memory system evolve to better serve autonomous agents?",
            "What is the optimal balance between memory retention and forgetting for a 111K corpus?",
        ]
        results = []
        for q in questions:
            start = time.perf_counter()
            r = reasoner.reason(question=q)
            elapsed = time.perf_counter() - start
            print(f"\n  Q: {q[:80]}...")
            print(f"    Synthesis: {r.synthesis[:150]}...")
            print(f"    Confidence: {r.confidence:.2f}, Lenses: {[p.lens.value for p in r.perspectives]}")
            print(f"    Duration: {elapsed:.1f}s")
            results.append({
                "question": q,
                "synthesis": r.synthesis,
                "recommendation": r.recommendation,
                "confidence": r.confidence,
                "lenses_used": [p.lens.value for p in r.perspectives],
                "patterns_matched": len(r.patterns_matched),
            })
        return {"questions_asked": len(results), "results": results}
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_novelty_detection():
    banner(14, "🆕", "NOVELTY DETECTION")
    try:
        from whitemagic.core.patterns.emergence.novelty_detector import (
            get_novelty_detector,
        )
        detector = get_novelty_detector()

        test_contents = [
            "WhiteMagic now supports 375 MCP tools across 28 Gana meta-tools with full PRAT resonance routing",
            "The constellation auto-merge system identifies converging 5D clusters and unifies them",
            "Hello world test memory with no novel information",
            "Causal mining discovers directed temporal edges between memories that represent causation chains",
            "A completely new paradigm: quantum-entangled memory associations across distributed galaxy instances",
        ]

        results = []
        for content in test_contents:
            event = detector.detect(content)
            score = event.novelty_score
            is_novel = score > 0.5
            emoji = "🆕" if is_novel else "📋"
            print(f"  {emoji} novelty={score:.3f} {'NOVEL' if is_novel else 'known'}: {content[:80]}...")
            results.append({"content": content[:80], "novelty_score": score, "is_novel": is_novel})

        stats = detector.get_novelty_stats()
        print(f"\n  Stats: {safe_json(stats)}")
        return {"detections": results, "stats": stats}
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_bridge_synthesis():
    banner(15, "🌉", "BRIDGE SYNTHESIS")
    try:
        from whitemagic.core.memory.bridge_synthesizer import get_bridge_synthesizer
        from whitemagic.core.memory.graph_engine import get_graph_engine
        synth = get_bridge_synthesizer()
        ge = get_graph_engine()

        bridges_raw = ge.find_bridge_nodes(top_n=10)
        print(f"  Bridge nodes available: {len(bridges_raw)}")

        if not bridges_raw:
            print("  No bridge nodes — rebuilding graph first...")
            ge.rebuild(sample_limit=20000, quality_filter=True)
            bridges_raw = ge.find_bridge_nodes(top_n=10)
            print(f"  After rebuild: {len(bridges_raw)} bridge nodes")

        if bridges_raw:
            start = time.perf_counter()
            insights = synth.synthesize_from_bridges(bridges_raw, top_n=5)
            elapsed = time.perf_counter() - start
            print(f"  Insights synthesized: {len(insights)}")
            print(f"  Duration: {elapsed:.1f}s")
            for ins in insights[:5]:
                d = ins.to_dict() if hasattr(ins, 'to_dict') else str(ins)
                if isinstance(d, dict):
                    print(f"    🌉 {d.get('insight', d.get('content', ''))[:120]}")
                    print(f"       confidence: {d.get('confidence', '?')}")
                else:
                    print(f"    🌉 {str(d)[:120]}")
            stats = synth.get_stats()
            return {"insights": len(insights), "stats": stats}
        else:
            return {"insights": 0, "message": "No bridge nodes found"}
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_knowledge_graph():
    banner(16, "🧠", "KNOWLEDGE GRAPH ANALYSIS")
    try:
        from whitemagic.core.intelligence.knowledge_graph import get_knowledge_graph
        kg = get_knowledge_graph()
        status = kg.status()
        print(f"  KG Status: {safe_json(status)}")

        top = kg.top_entities(limit=15)
        print(f"\n  Top entities ({len(top)}):")
        for entity in top[:10]:
            if isinstance(entity, dict):
                print(f"    🧠 {entity.get('entity', '?')} — {entity.get('count', '?')} relations")
            else:
                print(f"    🧠 {entity}")

        return {"status": status, "top_entities": top[:15]}
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


def step_pattern_consciousness():
    banner(17, "🧬", "PATTERN CONSCIOUSNESS STATUS")
    try:
        try:
            from whitemagic.core.patterns.pattern_consciousness.autonomous_learner import (
                AutonomousLearner,
            )
            learner = AutonomousLearner()
        except Exception:
            learner = None
        try:
            from whitemagic.core.patterns.pattern_consciousness.pattern_engine_enhanced import (
                EnhancedPatternEngine,
            )
            engine = EnhancedPatternEngine()
        except Exception:
            engine = None
        status = {
            "pattern_engine": type(engine).__name__,
            "autonomous_learner": type(learner).__name__,
            "systems_available": ["EnhancedPatternEngine", "DreamSynthesizer", "EmergenceDetector", "AutonomousLearner", "ResonanceOrchestrator"],
        }
        # Try to get learner status if available
        if hasattr(learner, 'get_status'):
            status["learner_status"] = learner.get_status()
        if hasattr(engine, 'get_status'):
            status["engine_status"] = engine.get_status()
        print(f"  Status: {safe_json(status)}")
        return status
    except Exception as e:
        print(f"  ❌ {e}")
        import traceback; traceback.print_exc()
        return {"error": str(e)}


def step_guideline_evolution():
    banner(18, "📜", "GUIDELINE EVOLUTION")
    try:
        from whitemagic.core.patterns.emergence.guideline_evolution import (
            GuidelineEvolution,
        )
        evolver = GuidelineEvolution()
        pending = evolver.get_pending_proposals()
        result = {
            "pending_proposals": len(pending),
            "proposals": [{"id": p.id, "title": p.title, "confidence": p.confidence} for p in pending[:10]],
        }
        print(f"  Pending proposals: {len(pending)}")
        for p in pending[:5]:
            print(f"    📜 {p.title} (confidence={p.confidence:.2f})")
        return result
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


def step_elemental_optimization():
    banner(19, "⚖️", "ELEMENTAL OPTIMIZATION")
    try:
        from whitemagic.core.intelligence.elemental_optimization import (
            ElementalOptimizer,
        )
        optimizer = ElementalOptimizer()
        tasks = ["exploration", "analysis", "consolidation", "refinement", "reflection"]
        results = []
        for task in tasks:
            strategy = optimizer.get_optimization_strategy(task)
            print(f"    {strategy.get('emoji', '?')} {task}: {strategy.get('description', '?')[:60]}")
            results.append({"task": task, "strategy": strategy})
        return {"optimizations": results, "wu_xing_connected": optimizer.wu_xing is not None}
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


def step_galactic_stats():
    banner(20, "🗺️", "GALACTIC ZONE STATISTICS")
    try:
        from whitemagic.core.memory.galactic_map import get_galactic_map
        gmap = get_galactic_map()
        zones = gmap.get_zone_counts()
        print(f"  Zone distribution: {safe_json(zones)}")
        return zones
    except Exception as e:
        print(f"  ❌ {e}")
        return {"error": str(e)}


# ══════════════════════════════════════════════════════════════
# SUMMARY
# ══════════════════════════════════════════════════════════════

def print_summary(results):
    print(f"\n{'=' * 70}")
    print("📋 EXTENDED ACTIVATION SEQUENCE COMPLETE")
    print("=" * 70)

    db = results.get("db_stats", {})
    results.get("galactic_sweep", {})
    mining = results.get("association_mining", {})
    constellations = results.get("constellation_detection", {})
    graph = results.get("graph_topology", {})
    results.get("dream_cycle", {})
    causal = results.get("causal_mining", {})
    emergence = results.get("emergence_scan", {})
    merge = results.get("constellation_merge", {})
    results.get("multispectral_reasoning", {})
    results.get("novelty_detection", {})
    results.get("bridge_synthesis", {})
    results.get("knowledge_graph", {})

    new_assocs = (
        mining.get("keyword_mining", {}).get("links_created", 0) +
        mining.get("semantic_mining", {}).get("links_created", 0) +
        causal.get("edges_created", causal.get("links_created", 0))
    )

    errors = sum(1 for v in results.values() if isinstance(v, dict) and "error" in v)
    successes = len(results) - errors

    print(f"""
  ╔══════════════════════════════════════════════════════════════╗
  ║  CORPUS                                                      ║
  ║    Memories:      {db.get('memories', '?'):>10,}                              ║
  ║    Associations:  {db.get('associations', '?'):>10,} ({db.get('typed_associations', '?'):,} typed)     ║
  ║    Embeddings:    {db.get('embeddings', '?'):>10,}                              ║
  ║    Holo Coords:   {db.get('holographic_coords', '?'):>10,}                              ║
  ║    KG Triples:    {db.get('knowledge_graph_triples', '?'):>10,}                              ║
  ║    DB Size:       {db.get('db_size_mb', '?'):>10} MB                            ║
  ╠══════════════════════════════════════════════════════════════╣
  ║  ANALYSIS                                                    ║
  ║    Constellations: {constellations.get('constellations_found', '?'):>8}                                ║
  ║    Merges:         {merge.get('merges', '?'):>8}                                ║
  ║    Bridge Nodes:   {graph.get('bridges', '?'):>8}                                ║
  ║    Communities:    {graph.get('communities', '?'):>8}                                ║
  ║    Emergence:      {emergence.get('insights_found', '?'):>8} insights                       ║
  ║    Causal Edges:   {causal.get('edges_created', causal.get('links_created', '?')):>8}                                ║
  ║    New Assocs:     {new_assocs:>8}                                ║
  ╠══════════════════════════════════════════════════════════════╣
  ║  ENGINES: {successes} succeeded, {errors} had errors                      ║
  ╚══════════════════════════════════════════════════════════════╝
""")


# ══════════════════════════════════════════════════════════════
# MAIN
# ══════════════════════════════════════════════════════════════

def main():
    parser = argparse.ArgumentParser(description="WhiteMagic v15.9 Extended Activation Sequence")
    parser.add_argument("--quick", action="store_true", help="Skip slow operations (dream, semantic mining)")
    parser.add_argument("--step", help="Run a single step only")
    args = parser.parse_args()

    print("🚀 WhiteMagic v15.9 — Extended Activation Sequence (21 steps)")
    print("=" * 70)
    print(f"Timestamp: {datetime.now().isoformat()}")
    print(f"Mode: {'quick' if args.quick else 'full'}")
    if args.step:
        print(f"Step: {args.step}")
    print("=" * 70)

    total_start = time.perf_counter()
    results = {}

    step_map = {
        "stats":          ("db_stats", step_db_stats),
        "sweep":          ("galactic_sweep", step_galactic_sweep),
        "mine":           ("association_mining", lambda: step_association_mining(args.quick)),
        "constellations": ("constellation_detection", step_constellation_detection),
        "graph":          ("graph_topology", step_graph_topology),
        "dream":          ("dream_cycle", lambda: step_dream_cycle(args.quick)),
        "harmony":        ("harmony_vector", step_harmony_vector),
        "wuxing":         ("wu_xing", step_wu_xing),
        "walker":         ("graph_walker", step_graph_walker),
        # v15.8/v15.9 new engines
        "causal":         ("causal_mining", step_causal_mining),
        "emergence":      ("emergence_scan", step_emergence_scan),
        "merge":          ("constellation_merge", step_constellation_merge),
        "satkona":        ("satkona_fusion", step_satkona_fusion),
        "multispectral":  ("multispectral_reasoning", step_multispectral_reasoning),
        "novelty":        ("novelty_detection", step_novelty_detection),
        "bridges":        ("bridge_synthesis", step_bridge_synthesis),
        "kg":             ("knowledge_graph", step_knowledge_graph),
        "consciousness":  ("pattern_consciousness", step_pattern_consciousness),
        "guidelines":     ("guideline_evolution", step_guideline_evolution),
        "elemental":      ("elemental_optimization", step_elemental_optimization),
        "galactic_stats": ("galactic_stats", step_galactic_stats),
    }

    if args.step:
        if args.step not in step_map:
            print(f"Unknown step: {args.step}")
            print(f"Available: {', '.join(step_map.keys())}")
            sys.exit(1)
        key, func = step_map[args.step]
        try:
            results[key] = func()
        except Exception as e:
            print(f"  ❌ Error: {e}")
            import traceback; traceback.print_exc()
            results[key] = {"error": str(e)}
    else:
        for step_name, (key, func) in step_map.items():
            try:
                results[key] = func()
            except Exception as e:
                print(f"\n  ❌ Step '{step_name}' failed: {e}")
                import traceback; traceback.print_exc()
                results[key] = {"error": str(e)}

    total_elapsed = time.perf_counter() - total_start

    if not args.step:
        print_summary(results)

    print(f"\n⏱  Total time: {total_elapsed:.1f}s")

    # Save report
    REPORT_PATH.parent.mkdir(exist_ok=True)
    try:
        with open(REPORT_PATH, "w") as f:
            json.dump(results, f, indent=2, default=str)
        print(f"📄 Report saved: {REPORT_PATH}")
    except Exception as e:
        print(f"⚠ Could not save report: {e}")


if __name__ == "__main__":
    main()
