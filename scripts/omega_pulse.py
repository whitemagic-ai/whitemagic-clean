#!/usr/bin/env python3
"""
OMEGA PULSE — All-Systems Introspection Orchestrator
====================================================
Executes 11+ core engines, self-improvement loops, and dream cycles back-to-back.
Captures the complete state of WhiteMagic for v22 synthesis.
"""

import asyncio
import json
import logging
import os
import time
from datetime import datetime

# Configure logging
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger("OmegaPulse")

class OmegaPulse:
    def __init__(self):
        self.results = {}
        self.start_time = time.time()

    async def run_all(self):
        logger.info("⚡ INITIATING OMEGA PULSE — Full System Introspection")

        # 1. Dream Cycle (12 Phases)
        await self.step("dream_cycle", self._run_dream_cycle)

        # 2. Kaizen Engine
        await self.step("kaizen", self._run_kaizen)

        # 3. Emergence Engine
        await self.step("emergence", self._run_emergence)

        # 4. Quantum Engine
        await self.step("quantum", self._run_quantum)

        # 5. Autodidactic Loop
        await self.step("autodidactic", self._run_autodidactic)

        # 6. Apotheosis Engine
        await self.step("apotheosis", self._run_apotheosis)

        # 7. Salience Arbiter
        await self.step("salience", self._run_salience)

        # 8. Pattern Engine
        await self.step("patterns", self._run_patterns)

        # 9. Galactic Telepathy
        await self.step("telepathy", self._run_telepathy)

        # 10. Neuro-Score
        await self.step("neuro_health", self._run_neuro_health)

        # 11. Dharma Audit
        await self.step("dharma", self._run_dharma)

        self.duration = time.time() - self.start_time
        self._save_report()

    async def step(self, name: str, func: callable):
        logger.info(f"--- Running {name.upper()} ---")
        try:
            start = time.perf_counter()
            if asyncio.iscoroutinefunction(func):
                res = await func()
            else:
                res = func()
            duration = (time.perf_counter() - start) * 1000
            self.results[name] = {"success": True, "data": res, "duration_ms": duration}
            logger.info(f"✅ {name} complete ({duration:.1f}ms)")
        except Exception as e:
            logger.error(f"❌ {name} failed: {e}")
            self.results[name] = {"success": False, "error": str(e)}

    async def _run_dream_cycle(self):
        from whitemagic.core.dreaming.dream_cycle import get_dream_cycle
        dc = get_dream_cycle()
        # Trigger an explicit multi-phase run
        report = []
        for _ in range(3): # Run 3 phases for sampling
            await dc._run_phase()
            status = dc.status()
            if status["recent_dreams"]:
                report.append(status["recent_dreams"][-1])
        return report

    def _run_kaizen(self):
        from whitemagic.core.intelligence.synthesis.kaizen_engine import (
            get_kaizen_engine,
        )
        engine = get_kaizen_engine()
        report = engine.analyze()
        return {
            "proposals": [p.__dict__ for p in report.proposals],
            "metrics": report.metrics
        }

    def _run_emergence(self):
        from whitemagic.core.intelligence.agentic.emergence_engine import (
            get_emergence_engine,
        )
        ee = get_emergence_engine()
        insights = ee.scan_for_emergence()
        return [i.to_dict() for i in insights]

    def _run_quantum(self):
        from whitemagic.core.intelligence.quantum_engine import QuantumEngine
        from whitemagic.core.memory.unified import get_unified_memory
        engine = QuantumEngine()
        um = get_unified_memory()

        # Test Grover search on recent memories
        recent = um.list_recent(limit=20)
        if not recent: return "No memories for quantum test"

        # Oracle: items containing 'architecture'
        results = engine.grover_search(recent, lambda m: "architecture" in str(m.content).lower())
        return {
            "grover_found": [m.id for m in results],
            "algorithm": "Grover O(√N)"
        }

    async def _run_autodidactic(self):
        from whitemagic.core.evolution.autodidactic_loop import AutodidacticLoop
        loop = AutodidacticLoop()
        return loop.get_learning_summary()

    def _run_apotheosis(self):
        from whitemagic.core.autonomous.apotheosis_engine import get_apotheosis_engine
        ae = get_apotheosis_engine()
        return ae.status() if hasattr(ae, 'status') else "Engine active"

    def _run_salience(self):
        from whitemagic.core.memory.unified import get_unified_memory
        from whitemagic.core.resonance.gan_ying_enhanced import (
            EventType,
            ResonanceEvent,
        )
        from whitemagic.core.resonance.salience_arbiter import get_salience_arbiter

        sa = get_salience_arbiter()
        um = get_unified_memory()
        memories = um.list_recent(limit=5)
        if not memories: return "No data"

        scored = []
        for m in memories:
            event = ResonanceEvent(
                event_type=EventType.MEMORY_RECALLED,
                source="omega_pulse",
                data={"memory_id": m.id},
                confidence=m.importance
            )
            score = sa.score(event)
            scored.append({"id": m.id, "composite_salience": score.composite})
        return scored

    def _run_patterns(self):
        from whitemagic.core.intelligence.hologram.patterns import get_pattern_engine
        pe = get_pattern_engine()
        result = pe.analyze()
        return {
            "total_patterns": result["total_patterns"],
            "total_insights": result["total_insights"],
            "insights": [i.title for i in result["insights"]]
        }

    async def _run_telepathy(self):
        from whitemagic.core.memory.telepathy_mesh_bridge import go_mesh_status
        return go_mesh_status()

    def _run_neuro_health(self):
        import sqlite3

        from whitemagic.config import DB_PATH
        conn = sqlite3.connect(DB_PATH)
        conn.row_factory = sqlite3.Row
        cur = conn.cursor()

        cur.execute("SELECT AVG(neuro_score) as avg_ns, AVG(novelty_score) as avg_novelty, COUNT(*) as count FROM memories")
        row = cur.fetchone()

        cur.execute("SELECT memory_type, COUNT(*) as count FROM memories GROUP BY memory_type")
        types = {r["memory_type"]: r["count"] for r in cur.fetchall()}

        return {
            "avg_neuro_score": row["avg_ns"],
            "avg_novelty": row["avg_novelty"],
            "total_memories": row["count"],
            "type_distribution": types
        }

    def _run_dharma(self):
        from whitemagic.dharma.rules import get_rules_engine
        re = get_rules_engine()
        return {
            "rules_count": len(re._rules) if hasattr(re, '_rules') else 0,
            "profile": getattr(re, 'current_profile', 'default')
        }

    def _save_report(self):
        report = {
            "timestamp": datetime.now().isoformat(),
            "duration_seconds": self.duration,
            "results": self.results
        }
        os.makedirs("reports", exist_ok=True)
        filename = f"reports/omega_pulse_{int(time.time())}.json"
        with open(filename, "w") as f:
            json.dump(report, f, indent=2)
        logger.info(f"📊 OMEGA PULSE REPORT SAVED: {filename}")

if __name__ == "__main__":
    asyncio.run(OmegaPulse().run_all())
