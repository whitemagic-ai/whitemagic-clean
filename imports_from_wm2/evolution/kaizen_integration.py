"""
Kaizen Integration for Evolution Engine
=========================================

Integrates evolutionary simulation with WhiteMagic's continuous improvement engine.

The kaizen engine analyzes:
- Quality issues (duplicate genomes, malformed genes)
- Knowledge gaps (underexplored gene combinations)
- Integration opportunities (synergistic mutations)
- Emergent themes (new gene categories forming)
- Performance issues (slow convergence, premature optimization)

Evolution feeds kaizen with rich data about what works and what doesn't,
creating a feedback loop for continuous improvement.
"""

import logging
from collections import Counter, defaultdict
from dataclasses import dataclass, field
from typing import Any

logger = logging.getLogger(__name__)


@dataclass
class EvolutionImprovementProposal:
    """An improvement proposal derived from evolution analysis"""
    id: str
    category: str  # quality, gap, integration, performance, exploration
    title: str
    description: str
    impact: str  # high, medium, low
    effort: str  # high, medium, low
    auto_fixable: bool = False
    fix_action: str | None = None
    evidence: dict[str, Any] = field(default_factory=dict)
    priority: int = 0


class EvolutionKaizenAnalyzer:
    """
    Analyzes evolution results to extract improvement proposals.

    This creates actionable insights from evolutionary simulation that can
    be applied to improve future runs or the underlying codebase.
    """

    def __init__(self):
        self.proposals: list[EvolutionImprovementProposal] = []

    def analyze_evolution_run(
        self,
        population: list,
        metrics: dict[str, Any],
        generation: int
    ) -> list[EvolutionImprovementProposal]:
        """
        Comprehensive analysis of an evolution run.

        Returns actionable improvement proposals.
        """
        self.proposals = []

        # Quality checks
        self.proposals.extend(self._check_genome_quality(population))
        self.proposals.extend(self._check_gene_distribution(population))

        # Gap analysis
        self.proposals.extend(self._find_exploration_gaps(population, metrics))

        # Integration opportunities
        self.proposals.extend(self._find_synergy_opportunities(population))

        # Performance analysis
        self.proposals.extend(self._analyze_convergence(metrics, generation))
        self.proposals.extend(self._analyze_diversity_trends(metrics))

        # Prioritize proposals
        self._prioritize_proposals()

        return self.proposals

    def _check_genome_quality(self, population: list) -> list[EvolutionImprovementProposal]:
        """Check for quality issues in genome population"""
        proposals = []

        # Check for genomes with too few genes
        min_genes = 10
        sparse_genomes = [g for g in population if len(g.genes) < min_genes]

        if len(sparse_genomes) > len(population) * 0.1:  # >10% sparse
            proposals.append(EvolutionImprovementProposal(
                id="quality_sparse_genomes",
                category="quality",
                title=f"High proportion of sparse genomes ({len(sparse_genomes)})",
                description=f"{len(sparse_genomes)} genomes have fewer than {min_genes} genes",
                impact="medium",
                effort="low",
                auto_fixable=True,
                fix_action="increase_minimum_gene_count",
                evidence={"sparse_count": len(sparse_genomes), "threshold": min_genes}
            ))

        # Check for genomes with too many genes (complexity bloat)
        max_genes = 100
        bloated_genomes = [g for g in population if len(g.genes) > max_genes]

        if len(bloated_genomes) > len(population) * 0.05:  # >5% bloated
            proposals.append(EvolutionImprovementProposal(
                id="quality_bloated_genomes",
                category="quality",
                title=f"Complexity bloat detected ({len(bloated_genomes)} genomes)",
                description=f"{len(bloated_genomes)} genomes exceed {max_genes} genes",
                impact="high",
                effort="medium",
                auto_fixable=True,
                fix_action="add_complexity_penalty",
                evidence={"bloated_count": len(bloated_genomes), "threshold": max_genes}
            ))

        # Check for duplicate genomes
        signatures = [self._genome_signature(g) for g in population]
        duplicates = len(signatures) - len(set(signatures))

        if duplicates > len(population) * 0.2:  # >20% duplicates
            proposals.append(EvolutionImprovementProposal(
                id="quality_high_duplication",
                category="quality",
                title=f"High genome duplication ({duplicates} duplicates)",
                description="Population has converged too quickly, losing diversity",
                impact="high",
                effort="low",
                auto_fixable=True,
                fix_action="increase_mutation_rate",
                evidence={"duplicate_count": duplicates, "unique_count": len(set(signatures))}
            ))

        return proposals

    def _check_gene_distribution(self, population: list) -> list[EvolutionImprovementProposal]:
        """Check for imbalanced gene category distribution"""
        proposals = []

        # Count genes by category across all genomes
        category_counts = Counter()
        for genome in population:
            for gene in genome.genes:
                category_counts[gene.category] += 1

        if not category_counts:
            return proposals

        total_genes = sum(category_counts.values())

        # Check for underrepresented categories (<5%)
        underrep_threshold = 0.05
        underrepresented = [
            (cat, count) for cat, count in category_counts.items()
            if count / total_genes < underrep_threshold
        ]

        if underrepresented:
            proposals.append(EvolutionImprovementProposal(
                id="gap_underrepresented_categories",
                category="gap",
                title=f"Underrepresented gene categories ({len(underrepresented)})",
                description=f"Categories {[c[0] for c in underrepresented]} are underexplored",
                impact="medium",
                effort="medium",
                auto_fixable=True,
                fix_action="boost_underrepresented_categories",
                evidence={"categories": dict(underrepresented)}
            ))

        # Check for overrepresented categories (>40%)
        overrep_threshold = 0.40
        overrepresented = [
            (cat, count) for cat, count in category_counts.items()
            if count / total_genes > overrep_threshold
        ]

        if overrepresented:
            proposals.append(EvolutionImprovementProposal(
                id="quality_overrepresented_categories",
                category="quality",
                title=f"Overrepresented gene categories ({len(overrepresented)})",
                description=f"Categories {[c[0] for c in overrepresented]} dominate population",
                impact="medium",
                effort="low",
                auto_fixable=True,
                fix_action="add_diversity_pressure",
                evidence={"categories": dict(overrepresented)}
            ))

        return proposals

    def _find_exploration_gaps(
        self,
        population: list,
        metrics: dict[str, Any]
    ) -> list[EvolutionImprovementProposal]:
        """Find underexplored regions of the gene space"""
        proposals = []

        # Check if certain gene combinations are never tried
        gene_pairs = defaultdict(int)
        for genome in population:
            genes = sorted([g.name for g in genome.genes])
            for i in range(len(genes)):
                for j in range(i+1, min(i+5, len(genes))):  # Check nearby pairs
                    pair = (genes[i], genes[j])
                    gene_pairs[pair] += 1

        # Find rare combinations
        total_genomes = len(population)
        rare_threshold = max(1, total_genomes // 100)  # <1% occurrence
        rare_pairs = [(pair, count) for pair, count in gene_pairs.items() if count < rare_threshold]

        if len(rare_pairs) > 100:  # Many unexplored combinations
            proposals.append(EvolutionImprovementProposal(
                id="gap_unexplored_combinations",
                category="gap",
                title=f"Large unexplored gene space ({len(rare_pairs)} rare pairs)",
                description="Many gene combinations have never been tried together",
                impact="high",
                effort="medium",
                auto_fixable=True,
                fix_action="increase_crossover_diversity",
                evidence={"rare_pair_count": len(rare_pairs), "sample": rare_pairs[:5]}
            ))

        return proposals

    def _find_synergy_opportunities(self, population: list) -> list[EvolutionImprovementProposal]:
        """Find gene combinations that work well together"""
        proposals = []

        # Analyze top performers for common patterns
        sorted_pop = sorted(population, key=lambda g: g.fitness, reverse=True)
        top_10_percent = sorted_pop[:max(1, len(sorted_pop) // 10)]

        # Find genes that frequently appear together in top performers
        gene_cooccurrence = defaultdict(int)
        for genome in top_10_percent:
            genes = sorted([g.name for g in genome.genes])
            for i in range(len(genes)):
                for j in range(i+1, len(genes)):
                    pair = (genes[i], genes[j])
                    gene_cooccurrence[pair] += 1

        # Find strong synergies (appear together in >50% of top performers)
        threshold = len(top_10_percent) * 0.5
        strong_synergies = [
            (pair, count) for pair, count in gene_cooccurrence.items()
            if count > threshold
        ]

        if strong_synergies:
            proposals.append(EvolutionImprovementProposal(
                id="integration_strong_synergies",
                category="integration",
                title=f"Strong gene synergies discovered ({len(strong_synergies)})",
                description="Certain gene pairs consistently appear in top performers",
                impact="high",
                effort="low",
                auto_fixable=False,
                evidence={"synergies": strong_synergies[:10]}
            ))

        return proposals

    def _analyze_convergence(
        self,
        metrics: dict[str, Any],
        generation: int
    ) -> list[EvolutionImprovementProposal]:
        """Analyze convergence speed and quality"""
        proposals = []

        convergence_gen = metrics.get("convergence_generation", generation)
        total_gens = metrics.get("generations_completed", generation)

        # Check for premature convergence
        if convergence_gen < total_gens * 0.2:  # Converged in first 20%
            proposals.append(EvolutionImprovementProposal(
                id="performance_premature_convergence",
                category="performance",
                title=f"Premature convergence (generation {convergence_gen})",
                description=f"Population converged too quickly at {convergence_gen}/{total_gens}",
                impact="high",
                effort="low",
                auto_fixable=True,
                fix_action="increase_mutation_rate_and_selection_pressure",
                evidence={"convergence_gen": convergence_gen, "total_gens": total_gens}
            ))

        # Check for slow convergence
        elif convergence_gen > total_gens * 0.8:  # Still evolving at 80%
            proposals.append(EvolutionImprovementProposal(
                id="performance_slow_convergence",
                category="performance",
                title=f"Slow convergence (generation {convergence_gen})",
                description="Population taking too long to converge",
                impact="medium",
                effort="low",
                auto_fixable=True,
                fix_action="increase_selection_pressure",
                evidence={"convergence_gen": convergence_gen, "total_gens": total_gens}
            ))

        return proposals

    def _analyze_diversity_trends(self, metrics: dict[str, Any]) -> list[EvolutionImprovementProposal]:
        """Analyze diversity trends over time"""
        proposals = []

        diversity_history = metrics.get("diversity_history", [])
        if len(diversity_history) < 10:
            return proposals

        # Check for monotonic diversity decrease
        recent_diversity = diversity_history[-10:]
        if all(recent_diversity[i] >= recent_diversity[i+1] for i in range(len(recent_diversity)-1)):
            proposals.append(EvolutionImprovementProposal(
                id="performance_diversity_collapse",
                category="performance",
                title="Diversity monotonically decreasing",
                description="Population diversity is steadily declining without recovery",
                impact="high",
                effort="medium",
                auto_fixable=True,
                fix_action="inject_diversity_periodically",
                evidence={"recent_diversity": recent_diversity}
            ))

        # Check for low absolute diversity
        final_diversity = diversity_history[-1] if diversity_history else 0
        if final_diversity < 0.1:  # <10% diversity
            proposals.append(EvolutionImprovementProposal(
                id="quality_low_diversity",
                category="quality",
                title=f"Very low final diversity ({final_diversity:.1%})",
                description="Population has lost almost all genetic diversity",
                impact="high",
                effort="low",
                auto_fixable=True,
                fix_action="restart_with_higher_mutation_rate",
                evidence={"final_diversity": final_diversity}
            ))

        return proposals

    def _prioritize_proposals(self):
        """Assign priority scores to proposals"""
        impact_scores = {"high": 3, "medium": 2, "low": 1}
        effort_scores = {"low": 3, "medium": 2, "high": 1}

        for proposal in self.proposals:
            impact = impact_scores.get(proposal.impact, 1)
            effort = effort_scores.get(proposal.effort, 1)
            proposal.priority = impact * effort

        # Sort by priority (descending)
        self.proposals.sort(key=lambda p: p.priority, reverse=True)

    def _genome_signature(self, genome) -> str:
        """Create unique signature for genome"""
        gene_str = "_".join(
            f"{g.name}:{g.expression_level:.2f}"
            for g in sorted(genome.genes, key=lambda x: x.name)
        )
        return gene_str


def extract_improvement_proposals(
    evolution_engine,
    population: list,
    metrics: dict[str, Any],
    generation: int
) -> list[EvolutionImprovementProposal]:
    """
    Extract actionable improvement proposals from evolution results.

    This is the main entry point for kaizen integration.
    """
    analyzer = EvolutionKaizenAnalyzer()
    proposals = analyzer.analyze_evolution_run(population, metrics, generation)

    logger.info(f"🔧 Kaizen analysis complete: {len(proposals)} proposals generated")
    logger.info(f"   High priority: {sum(1 for p in proposals if p.impact == 'high')}")
    logger.info(f"   Auto-fixable: {sum(1 for p in proposals if p.auto_fixable)}")

    return proposals
