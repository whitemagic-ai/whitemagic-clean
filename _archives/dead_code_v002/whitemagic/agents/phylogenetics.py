"""Digital Phylogenetics — Evolutionary Agent Improvement (S003).

Tracks which agent mutations, strategies, and prompt variations are most
effective over time. Agents evolve through recursive self-improvement:
successful "genotypes" (prompt + temperature + tools + personality) are
bred forward, while failures are culled.

Core classes:
  - GenomeTracker: tracks agent genotypes (prompt, temp, tools, personality)
  - PhenotypeRecorder: measures agent outcomes (VCs met, throughput, error rate)
  - SelectionEngine: breeds top performers with mutation
  - Blackboard: shared STATE.json for inter-officer communication

Usage:
    from whitemagic.agents.phylogenetics import GenomeTracker, PhenotypeRecorder
    tracker = GenomeTracker()
    genome_id = tracker.register("clone_001", temperature=0.7, tools=["search", "recall"])
    recorder = PhenotypeRecorder()
    recorder.record(genome_id, vcs_met=5, throughput=1200, error_rate=0.02)
"""

from __future__ import annotations

import hashlib
import json
import logging
import os
import random
import threading
import time
from dataclasses import asdict, dataclass, field
from datetime import datetime
from pathlib import Path
from typing import Any

logger = logging.getLogger(__name__)

# Compressed Hanzi shorthand for status codes (token-efficient agent comms)
HANZI_STATUS = {
    "complete": "完",
    "fail": "失",
    "progress": "進",
    "waiting": "待",
    "blocked": "阻",
    "victory": "勝",
    "mutation": "變",
    "transfer": "轉",
    "promote": "升",
    "cull": "汰",
}

GENE_POOL_DIR = Path(os.environ.get(
    "WM_GENE_POOL", os.path.expanduser("~/.whitemagic/gene_pool")
))
BLACKBOARD_DIR = Path(os.environ.get(
    "WM_BLACKBOARD", os.path.expanduser("~/.whitemagic/blackboard")
))


# ---------------------------------------------------------------------------
# Genotype
# ---------------------------------------------------------------------------

@dataclass
class Genotype:
    """An agent's complete genetic configuration."""

    genome_id: str
    agent_name: str
    prompt_template: str = "default"
    temperature: float = 0.7
    tools: list[str] = field(default_factory=list)
    personality: str = "balanced"
    parent_id: str | None = None
    generation: int = 0
    mutation_history: list[str] = field(default_factory=list)
    created_at: str = field(default_factory=lambda: datetime.now().isoformat())

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)

    @classmethod
    def from_dict(cls, d: dict[str, Any]) -> Genotype:
        return cls(**{k: v for k, v in d.items() if k in cls.__dataclass_fields__})


@dataclass
class Phenotype:
    """Measured outcomes of an agent's performance."""

    genome_id: str
    vcs_met: int = 0
    vcs_total: int = 0
    throughput: float = 0.0
    error_rate: float = 0.0
    elapsed_s: float = 0.0
    findings_count: int = 0
    fitness_score: float = 0.0
    recorded_at: str = field(default_factory=lambda: datetime.now().isoformat())

    def compute_fitness(self) -> float:
        """Compute composite fitness: VCs dominate, throughput secondary."""
        vc_ratio = self.vcs_met / max(self.vcs_total, 1)
        error_penalty = max(0, 1.0 - self.error_rate * 5)
        throughput_bonus = min(1.0, self.throughput / 100000) * 0.1
        self.fitness_score = round(vc_ratio * 0.7 + error_penalty * 0.2 + throughput_bonus, 4)
        return self.fitness_score

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


# ---------------------------------------------------------------------------
# GenomeTracker
# ---------------------------------------------------------------------------

class GenomeTracker:
    """Tracks agent genotypes across generations.

    Persists genomes to ~/.whitemagic/gene_pool/ as JSON files.
    Supports registration, mutation, breeding, and lineage queries.
    """

    def __init__(self, gene_pool_dir: Path | None = None):
        self._dir = gene_pool_dir or GENE_POOL_DIR
        self._dir.mkdir(parents=True, exist_ok=True)
        self._lock = threading.Lock()
        self._genomes: dict[str, Genotype] = {}
        self._load_pool()

    def _load_pool(self):
        """Load existing genomes from gene pool directory."""
        for f in self._dir.glob("*.json"):
            try:
                data = json.loads(f.read_text())
                g = Genotype.from_dict(data)
                self._genomes[g.genome_id] = g
            except Exception:
                pass

    def register(
        self,
        agent_name: str,
        prompt_template: str = "default",
        temperature: float = 0.7,
        tools: list[str] | None = None,
        personality: str = "balanced",
        parent_id: str | None = None,
        generation: int = 0,
    ) -> str:
        """Register a new agent genotype. Returns genome_id."""
        genome_id = hashlib.sha256(
            f"{agent_name}:{prompt_template}:{temperature}:{time.time()}".encode()
        ).hexdigest()[:12]

        genotype = Genotype(
            genome_id=genome_id,
            agent_name=agent_name,
            prompt_template=prompt_template,
            temperature=temperature,
            tools=tools or [],
            personality=personality,
            parent_id=parent_id,
            generation=generation,
        )

        with self._lock:
            self._genomes[genome_id] = genotype
            self._persist(genotype)

        return genome_id

    def mutate(self, genome_id: str, mutation_rate: float = 0.1) -> str:
        """Create a mutated child from an existing genome."""
        parent = self._genomes.get(genome_id)
        if not parent:
            raise ValueError(f"Genome {genome_id} not found")

        # Mutate temperature (±0.1)
        new_temp = parent.temperature + random.uniform(-mutation_rate, mutation_rate)
        new_temp = max(0.0, min(2.0, round(new_temp, 2)))

        # Possibly swap a tool
        new_tools = list(parent.tools)
        mutations = [f"temp:{parent.temperature:.2f}->{new_temp:.2f}"]

        if random.random() < mutation_rate and new_tools:
            idx = random.randint(0, len(new_tools) - 1)
            removed = new_tools.pop(idx)
            mutations.append(f"tool_removed:{removed}")

        # Create child
        child_id = self.register(
            agent_name=f"{parent.agent_name}_mut",
            prompt_template=parent.prompt_template,
            temperature=new_temp,
            tools=new_tools,
            personality=parent.personality,
            parent_id=genome_id,
            generation=parent.generation + 1,
        )

        child = self._genomes[child_id]
        child.mutation_history = list(parent.mutation_history) + mutations
        self._persist(child)

        return child_id

    def breed(self, parent_a_id: str, parent_b_id: str) -> str:
        """Breed two genomes: crossover + small mutation."""
        a = self._genomes.get(parent_a_id)
        b = self._genomes.get(parent_b_id)
        if not a or not b:
            raise ValueError("Both parents must exist")

        # Crossover: average temp, merge tools, pick personality
        temp = round((a.temperature + b.temperature) / 2, 2)
        tools = list(set(a.tools) | set(b.tools))
        personality = random.choice([a.personality, b.personality])
        gen = max(a.generation, b.generation) + 1

        child_id = self.register(
            agent_name=f"bred_gen{gen}",
            prompt_template=random.choice([a.prompt_template, b.prompt_template]),
            temperature=temp,
            tools=tools,
            personality=personality,
            parent_id=parent_a_id,
            generation=gen,
        )

        child = self._genomes[child_id]
        child.mutation_history = [f"bred:{parent_a_id[:8]}x{parent_b_id[:8]}"]
        self._persist(child)

        return child_id

    def get(self, genome_id: str) -> Genotype | None:
        return self._genomes.get(genome_id)

    def get_lineage(self, genome_id: str, max_depth: int = 10) -> list[Genotype]:
        """Walk back through parent chain."""
        lineage = []
        current = genome_id
        for _ in range(max_depth):
            g = self._genomes.get(current)
            if not g:
                break
            lineage.append(g)
            if not g.parent_id:
                break
            current = g.parent_id
        return lineage

    def get_generation(self, generation: int) -> list[Genotype]:
        """Get all genomes from a specific generation."""
        return [g for g in self._genomes.values() if g.generation == generation]

    def all_genomes(self) -> list[Genotype]:
        return list(self._genomes.values())

    def stats(self) -> dict[str, Any]:
        genomes = list(self._genomes.values())
        if not genomes:
            return {"total": 0}
        generations = set(g.generation for g in genomes)
        return {
            "total": len(genomes),
            "generations": len(generations),
            "max_generation": max(generations),
            "avg_temperature": round(sum(g.temperature for g in genomes) / len(genomes), 3),
        }

    def _persist(self, genotype: Genotype):
        path = self._dir / f"{genotype.genome_id}.json"
        path.write_text(json.dumps(genotype.to_dict(), indent=2))


# ---------------------------------------------------------------------------
# PhenotypeRecorder
# ---------------------------------------------------------------------------

class PhenotypeRecorder:
    """Records and queries agent performance phenotypes.

    Stores phenotype records as JSONL in the gene pool directory.
    """

    def __init__(self, gene_pool_dir: Path | None = None):
        self._dir = gene_pool_dir or GENE_POOL_DIR
        self._dir.mkdir(parents=True, exist_ok=True)
        self._log_file = self._dir / "phenotypes.jsonl"
        self._lock = threading.Lock()
        self._records: list[Phenotype] = []
        self._load()

    def _load(self):
        if self._log_file.exists():
            for line in self._log_file.read_text().strip().split("\n"):
                if line.strip():
                    try:
                        d = json.loads(line)
                        self._records.append(Phenotype(**{
                            k: v for k, v in d.items() if k in Phenotype.__dataclass_fields__
                        }))
                    except Exception:
                        pass

    def record(
        self,
        genome_id: str,
        vcs_met: int = 0,
        vcs_total: int = 0,
        throughput: float = 0.0,
        error_rate: float = 0.0,
        elapsed_s: float = 0.0,
        findings_count: int = 0,
    ) -> Phenotype:
        """Record a phenotype measurement for a genome."""
        p = Phenotype(
            genome_id=genome_id,
            vcs_met=vcs_met,
            vcs_total=vcs_total,
            throughput=throughput,
            error_rate=error_rate,
            elapsed_s=elapsed_s,
            findings_count=findings_count,
        )
        p.compute_fitness()

        with self._lock:
            self._records.append(p)
            with open(self._log_file, "a") as f:
                f.write(json.dumps(p.to_dict()) + "\n")

        return p

    def get_fitness_ranking(self, top_n: int = 10) -> list[Phenotype]:
        """Get top N phenotypes by fitness score."""
        scored = [p for p in self._records if p.fitness_score > 0]
        scored.sort(key=lambda p: -p.fitness_score)
        return scored[:top_n]

    def select_top_percent(self, percent: float = 0.1) -> list[str]:
        """Select top X% genome IDs by fitness (for breeding)."""
        ranking = self.get_fitness_ranking(top_n=len(self._records))
        n = max(1, int(len(ranking) * percent))
        return [p.genome_id for p in ranking[:n]]

    def get_for_genome(self, genome_id: str) -> list[Phenotype]:
        return [p for p in self._records if p.genome_id == genome_id]

    def stats(self) -> dict[str, Any]:
        if not self._records:
            return {"total_records": 0}
        fitnesses = [p.fitness_score for p in self._records if p.fitness_score > 0]
        return {
            "total_records": len(self._records),
            "unique_genomes": len(set(p.genome_id for p in self._records)),
            "avg_fitness": round(sum(fitnesses) / max(len(fitnesses), 1), 4),
            "max_fitness": round(max(fitnesses) if fitnesses else 0, 4),
            "min_fitness": round(min(fitnesses) if fitnesses else 0, 4),
        }


# ---------------------------------------------------------------------------
# Selection Engine
# ---------------------------------------------------------------------------

class SelectionEngine:
    """Breeds top performers and culls underperformers.

    Implements:
      - Tournament selection
      - Crossover breeding
      - Mutation
      - Horizontal gene transfer (strategy sharing across campaigns)
    """

    def __init__(self, tracker: GenomeTracker, recorder: PhenotypeRecorder):
        self.tracker = tracker
        self.recorder = recorder

    def evolve_generation(self, mutation_rate: float = 0.1) -> dict[str, Any]:
        """Run one generation of evolution.

        1. Score all agents
        2. Select top 10%
        3. Breed winners with crossover
        4. Mutate children slightly
        5. Return new generation stats
        """
        top_ids = self.recorder.select_top_percent(0.1)
        if len(top_ids) < 2:
            return {"error": "Not enough genomes to evolve", "top_count": len(top_ids)}

        new_children = []
        # Breed pairs from top performers
        for i in range(0, len(top_ids) - 1, 2):
            try:
                child_id = self.tracker.breed(top_ids[i], top_ids[i + 1])
                new_children.append(child_id)
            except Exception:
                pass

        # Mutate some children
        mutated = []
        for child_id in new_children:
            if random.random() < mutation_rate:
                try:
                    mut_id = self.tracker.mutate(child_id, mutation_rate)
                    mutated.append(mut_id)
                except Exception:
                    pass

        return {
            "selected": len(top_ids),
            "bred": len(new_children),
            "mutated": len(mutated),
            "generation": max((self.tracker.get(cid).generation for cid in new_children), default=0),
        }

    def horizontal_gene_transfer(
        self, source_campaign: str, target_campaign: str, strategy: str,
    ) -> dict[str, Any]:
        """Transfer a successful strategy from one campaign to another.

        Records the transfer event and creates a new genome incorporating
        the transferred strategy.
        """
        transfer_id = hashlib.sha256(
            f"hgt:{source_campaign}:{target_campaign}:{strategy}:{time.time()}".encode()
        ).hexdigest()[:12]

        genome_id = self.tracker.register(
            agent_name=f"hgt_{target_campaign}",
            prompt_template=strategy,
            personality="transferred",
            parent_id=None,
            generation=0,
        )

        child = self.tracker.get(genome_id)
        if child:
            child.mutation_history = [f"hgt:{source_campaign}->{target_campaign}"]
            self.tracker._persist(child)

        return {
            "transfer_id": transfer_id,
            "genome_id": genome_id,
            "source": source_campaign,
            "target": target_campaign,
            "strategy": strategy[:100],
        }


# ---------------------------------------------------------------------------
# Blackboard (STATE.json inter-officer communication)
# ---------------------------------------------------------------------------

class Blackboard:
    """Shared state file for inter-officer communication without chat.

    Officers read/write to a shared STATE.json. Supports:
    - Status updates (Hanzi shorthand)
    - Bounty posting (dynamic objective discovery)
    - Promotion records (fluid hierarchy)
    """

    def __init__(self, blackboard_dir: Path | None = None):
        self._dir = blackboard_dir or BLACKBOARD_DIR
        self._dir.mkdir(parents=True, exist_ok=True)
        self._state_file = self._dir / "STATE.json"
        self._lock = threading.Lock()
        self._state: dict[str, Any] = self._load()

    def _load(self) -> dict[str, Any]:
        if self._state_file.exists():
            try:
                return json.loads(self._state_file.read_text())
            except Exception:
                pass
        return {
            "officers": {},
            "bounties": [],
            "promotions": [],
            "gene_transfers": [],
            "updated_at": datetime.now().isoformat(),
        }

    def _save(self):
        self._state["updated_at"] = datetime.now().isoformat()
        self._state_file.write_text(json.dumps(self._state, indent=2, default=str))

    def post_status(self, officer: str, status: str, detail: str = ""):
        """Post officer status using Hanzi shorthand."""
        hanzi = HANZI_STATUS.get(status, status)
        with self._lock:
            self._state.setdefault("officers", {})[officer] = {
                "status": status,
                "hanzi": hanzi,
                "detail": detail,
                "updated": datetime.now().isoformat(),
            }
            self._save()

    def post_bounty(self, officer: str, description: str, priority: int = 2):
        """Post a bounty for dynamic objective discovery."""
        with self._lock:
            self._state.setdefault("bounties", []).append({
                "from": officer,
                "description": description,
                "priority": priority,
                "posted": datetime.now().isoformat(),
                "claimed_by": None,
            })
            self._save()

    def claim_bounty(self, officer: str, bounty_idx: int) -> bool:
        """Claim an unclaimed bounty."""
        with self._lock:
            bounties = self._state.get("bounties", [])
            if 0 <= bounty_idx < len(bounties) and bounties[bounty_idx].get("claimed_by") is None:
                bounties[bounty_idx]["claimed_by"] = officer
                bounties[bounty_idx]["claimed_at"] = datetime.now().isoformat()
                self._save()
                return True
        return False

    def promote(self, clone_id: str, from_rank: str, to_rank: str, reason: str):
        """Record a fluid promotion."""
        with self._lock:
            self._state.setdefault("promotions", []).append({
                "clone_id": clone_id,
                "from": from_rank,
                "to": to_rank,
                "reason": reason,
                "timestamp": datetime.now().isoformat(),
            })
            self._save()

    def record_gene_transfer(self, source: str, target: str, strategy: str):
        """Record a horizontal gene transfer event."""
        with self._lock:
            self._state.setdefault("gene_transfers", []).append({
                "source": source,
                "target": target,
                "strategy": strategy[:200],
                "timestamp": datetime.now().isoformat(),
            })
            self._save()

    def get_state(self) -> dict[str, Any]:
        return dict(self._state)

    def get_active_bounties(self) -> list[dict]:
        return [b for b in self._state.get("bounties", []) if b.get("claimed_by") is None]


# ---------------------------------------------------------------------------
# Report Generation
# ---------------------------------------------------------------------------

def generate_phylogenetics_report(
    tracker: GenomeTracker,
    recorder: PhenotypeRecorder,
    output_dir: Path | None = None,
) -> Path:
    """Generate reports/phylogenetics_results.md."""
    out_dir = output_dir or Path(__file__).resolve().parent.parent.parent / "reports"
    out_dir.mkdir(parents=True, exist_ok=True)

    lines = [
        "# Digital Phylogenetics Results",
        f"\nGenerated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}",
        "\n## Genome Statistics",
    ]

    gs = tracker.stats()
    lines.append(f"- Total genomes: {gs.get('total', 0)}")
    lines.append(f"- Generations: {gs.get('generations', 0)}")
    lines.append(f"- Max generation: {gs.get('max_generation', 0)}")
    lines.append(f"- Avg temperature: {gs.get('avg_temperature', 0)}")

    lines.append("\n## Phenotype Statistics")
    ps = recorder.stats()
    lines.append(f"- Total records: {ps.get('total_records', 0)}")
    lines.append(f"- Unique genomes measured: {ps.get('unique_genomes', 0)}")
    lines.append(f"- Avg fitness: {ps.get('avg_fitness', 0)}")
    lines.append(f"- Max fitness: {ps.get('max_fitness', 0)}")

    lines.append("\n## Top Performers")
    lines.append("| Rank | Genome ID | Fitness | VCs | Throughput | Error Rate |")
    lines.append("|------|-----------|---------|-----|------------|------------|")
    for i, p in enumerate(recorder.get_fitness_ranking(10), 1):
        lines.append(
            f"| {i} | {p.genome_id[:10]} | {p.fitness_score:.4f} | "
            f"{p.vcs_met}/{p.vcs_total} | {p.throughput:.0f} | {p.error_rate:.3f} |"
        )

    lines.append("\n## Compressed Shorthand (Hanzi)")
    lines.append("| Code | Meaning |")
    lines.append("|------|---------|")
    for eng, hanzi in HANZI_STATUS.items():
        lines.append(f"| {hanzi} | {eng} |")

    lines.append("\n## Phylogenetic Tree (sample)")
    all_genomes = tracker.all_genomes()
    if all_genomes:
        lines.append("```")
        for g in all_genomes[:20]:
            parent = f" <- {g.parent_id[:8]}" if g.parent_id else " (root)"
            lines.append(f"  gen{g.generation}: {g.genome_id[:10]} {g.agent_name}{parent}")
        lines.append("```")

    path = out_dir / "phylogenetics_results.md"
    path.write_text("\n".join(lines))
    return path
