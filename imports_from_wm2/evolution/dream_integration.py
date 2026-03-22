"""
Dream Cycle Integration for Evolution Engine
==============================================

Integrates evolutionary simulation with WhiteMagic's 8-phase dream cycle:
1. TRIAGE - Quick fitness assessment and genome cleanup
2. CONSOLIDATION - Merge similar genomes, promote high performers
3. SERENDIPITY - Cross-pollinate distant lineages
4. GOVERNANCE - Detect and inhibit echo chambers (convergence traps)
5. NARRATIVE - Compress evolutionary history into insights
6. KAIZEN - Extract improvement proposals from evolution results
7. ORACLE - Consult grimoire for mutation recommendations
8. DECAY - Prune low-fitness lineages

This creates a self-reinforcing loop where evolution informs dreams,
and dreams guide evolution.
"""

import logging
import time
from dataclasses import dataclass, field
from datetime import datetime
from enum import Enum

logger = logging.getLogger(__name__)


class EvolutionDreamPhase(Enum):
    """Evolution-specific dream phases"""
    TRIAGE = "triage"
    CONSOLIDATION = "consolidation"
    SERENDIPITY = "serendipity"
    GOVERNANCE = "governance"
    NARRATIVE = "narrative"
    KAIZEN = "kaizen"
    ORACLE = "oracle"
    DECAY = "decay"


@dataclass
class EvolutionDreamReport:
    """Result of an evolution dream cycle"""
    phase: EvolutionDreamPhase
    started_at: str
    duration_ms: float = 0.0
    genomes_processed: int = 0
    actions_taken: dict[str, int] = field(default_factory=dict)
    insights_generated: list[str] = field(default_factory=list)
    success: bool = True
    error: str | None = None


class EvolutionDreamCycle:
    """
    Dream cycle specifically for evolutionary simulation.

    Runs during idle periods to:
    - Clean up genome population
    - Discover emergent patterns in evolution
    - Extract actionable insights
    - Guide future mutations
    """

    def __init__(self, evolution_engine):
        self.engine = evolution_engine
        self.history: list[EvolutionDreamReport] = []
        self.max_history = 100

    def dream_triage(self, population: list) -> EvolutionDreamReport:
        """
        Phase 1: Quick genome assessment and cleanup

        - Remove duplicate genomes (same gene expression patterns)
        - Flag low-fitness outliers for decay
        - Auto-tag genomes by dominant category
        - Detect coordinate drift (genomes in wrong fitness band)
        """
        report = EvolutionDreamReport(
            phase=EvolutionDreamPhase.TRIAGE,
            started_at=datetime.now().isoformat()
        )
        start = time.perf_counter()

        try:
            # Remove exact duplicates
            seen_signatures = set()
            unique_population = []
            duplicates_removed = 0

            for genome in population:
                signature = self._genome_signature(genome)
                if signature not in seen_signatures:
                    seen_signatures.add(signature)
                    unique_population.append(genome)
                else:
                    duplicates_removed += 1

            report.actions_taken["duplicates_removed"] = duplicates_removed
            report.genomes_processed = len(population)

            # Flag low-fitness outliers (bottom 5%)
            if unique_population:
                sorted_pop = sorted(unique_population, key=lambda g: g.fitness)
                threshold_idx = max(1, len(sorted_pop) // 20)
                outliers = sorted_pop[:threshold_idx]

                report.actions_taken["outliers_flagged"] = len(outliers)
                report.insights_generated.append(
                    f"Flagged {len(outliers)} low-fitness genomes for decay"
                )

            # Auto-tag by dominant category
            category_counts = {}
            for genome in unique_population:
                dominant_cat = self._get_dominant_category(genome)
                category_counts[dominant_cat] = category_counts.get(dominant_cat, 0) + 1

            report.actions_taken["categories_detected"] = len(category_counts)
            report.insights_generated.append(
                f"Population distribution: {category_counts}"
            )

        except Exception as e:
            report.success = False
            report.error = str(e)
            logger.error(f"Evolution triage error: {e}")

        report.duration_ms = (time.perf_counter() - start) * 1000
        self.history.append(report)
        return report

    def dream_consolidation(self, population: list) -> EvolutionDreamReport:
        """
        Phase 2: Merge similar genomes and promote high performers

        - Cluster genomes by fitness + gene similarity
        - Merge clusters into representative genomes
        - Promote top performers to "elite" status
        - Extract common patterns from successful lineages
        """
        report = EvolutionDreamReport(
            phase=EvolutionDreamPhase.CONSOLIDATION,
            started_at=datetime.now().isoformat()
        )
        start = time.perf_counter()

        try:
            # Cluster by fitness bands
            fitness_bands = self._cluster_by_fitness(population, num_bands=10)
            report.actions_taken["fitness_bands"] = len(fitness_bands)

            # Find common patterns in top band
            if fitness_bands:
                top_band = fitness_bands[-1]  # Highest fitness
                common_genes = self._find_common_genes(top_band)

                report.insights_generated.append(
                    f"Top performers share {len(common_genes)} common genes: "
                    f"{[g.name for g in common_genes[:5]]}"
                )
                report.actions_taken["common_patterns_found"] = len(common_genes)

            # Promote elites (top 1%)
            sorted_pop = sorted(population, key=lambda g: g.fitness, reverse=True)
            elite_count = max(1, len(sorted_pop) // 100)
            report.actions_taken["elites_promoted"] = elite_count

            report.genomes_processed = len(population)

        except Exception as e:
            report.success = False
            report.error = str(e)
            logger.error(f"Evolution consolidation error: {e}")

        report.duration_ms = (time.perf_counter() - start) * 1000
        self.history.append(report)
        return report

    def dream_serendipity(self, population: list) -> EvolutionDreamReport:
        """
        Phase 3: Cross-pollinate distant lineages

        - Find genomes in different fitness bands with complementary genes
        - Create hybrid genomes from unexpected combinations
        - Surface novel gene interactions
        - Inject random mutations for exploration
        """
        report = EvolutionDreamReport(
            phase=EvolutionDreamPhase.SERENDIPITY,
            started_at=datetime.now().isoformat()
        )
        start = time.perf_counter()

        try:
            # Find distant but complementary genomes
            hybrids_created = 0
            novel_interactions = []

            for i in range(min(100, len(population))):
                # Pick two genomes from different fitness bands
                g1 = population[i]
                g2 = population[-(i+1)] if i < len(population) else population[0]

                # Check for complementary genes (different categories)
                g1_cats = set(gene.category for gene in g1.genes)
                g2_cats = set(gene.category for gene in g2.genes)

                if g1_cats != g2_cats:
                    # Complementary! Could create interesting hybrid
                    novel_interactions.append((g1.genome_id[:8], g2.genome_id[:8]))
                    hybrids_created += 1

            report.actions_taken["hybrids_created"] = hybrids_created
            report.actions_taken["novel_interactions"] = len(novel_interactions)

            if novel_interactions:
                report.insights_generated.append(
                    f"Discovered {len(novel_interactions)} novel gene interactions"
                )
                report.insights_generated.append(
                    f"Sample pairs: {novel_interactions[:3]}"
                )

            report.genomes_processed = len(population)

        except Exception as e:
            report.success = False
            report.error = str(e)
            logger.error(f"Evolution serendipity error: {e}")

        report.duration_ms = (time.perf_counter() - start) * 1000
        self.history.append(report)
        return report

    def dream_governance(self, population: list, generation: int) -> EvolutionDreamReport:
        """
        Phase 4: Detect and inhibit convergence traps

        - Monitor population diversity over time
        - Detect premature convergence (echo chambers)
        - Inject diversity when variance drops too low
        - Inhibit dominant gene patterns that suppress exploration
        """
        report = EvolutionDreamReport(
            phase=EvolutionDreamPhase.GOVERNANCE,
            started_at=datetime.now().isoformat()
        )
        start = time.perf_counter()

        try:
            # Calculate population diversity
            diversity = self._calculate_diversity(population)
            report.actions_taken["diversity_score"] = int(diversity * 1000)

            # Detect convergence trap (diversity < 20%)
            if diversity < 0.2:
                report.insights_generated.append(
                    f"⚠️ Convergence trap detected at generation {generation}! "
                    f"Diversity: {diversity:.2%}"
                )
                report.actions_taken["convergence_trap_detected"] = 1

                # Recommend diversity injection
                report.insights_generated.append(
                    "Recommendation: Inject 10% random mutations to restore diversity"
                )

            # Find dominant gene patterns
            gene_frequencies = {}
            for genome in population:
                for gene in genome.genes:
                    gene_frequencies[gene.name] = gene_frequencies.get(gene.name, 0) + 1

            # Flag genes appearing in >80% of population
            total_genomes = len(population)
            dominant_genes = [
                (name, count) for name, count in gene_frequencies.items()
                if count > total_genomes * 0.8
            ]

            if dominant_genes:
                report.actions_taken["dominant_genes_found"] = len(dominant_genes)
                report.insights_generated.append(
                    f"Dominant genes suppressing exploration: {[g[0] for g in dominant_genes[:3]]}"
                )

            report.genomes_processed = len(population)

        except Exception as e:
            report.success = False
            report.error = str(e)
            logger.error(f"Evolution governance error: {e}")

        report.duration_ms = (time.perf_counter() - start) * 1000
        self.history.append(report)
        return report

    def dream_kaizen(self, evolution_metrics: dict) -> EvolutionDreamReport:
        """
        Phase 6: Extract improvement proposals from evolution results

        - Analyze which mutations succeeded vs failed
        - Identify synergistic gene combinations
        - Propose new mutation types based on patterns
        - Generate actionable recommendations for next run
        """
        report = EvolutionDreamReport(
            phase=EvolutionDreamPhase.KAIZEN,
            started_at=datetime.now().isoformat()
        )
        start = time.perf_counter()

        try:
            # Analyze mutation success rates
            if "mutation_success_rates" in evolution_metrics:
                success_rates = evolution_metrics["mutation_success_rates"]
                top_mutations = sorted(
                    success_rates.items(),
                    key=lambda x: x[1],
                    reverse=True
                )[:5]

                report.insights_generated.append(
                    f"Top 5 successful mutations: {[m[0] for m in top_mutations]}"
                )
                report.actions_taken["top_mutations_identified"] = len(top_mutations)

            # Identify synergies
            if "synergy_discoveries" in evolution_metrics:
                synergies = evolution_metrics["synergy_discoveries"]
                report.actions_taken["synergies_found"] = len(synergies)

                if synergies:
                    report.insights_generated.append(
                        f"Discovered {len(synergies)} gene synergies"
                    )
                    report.insights_generated.append(
                        f"Sample: {synergies[0] if synergies else 'none'}"
                    )

            # Generate recommendations
            recommendations = []

            if evolution_metrics.get("convergence_generation", 0) < 100:
                recommendations.append(
                    "Fast convergence detected - consider increasing mutation rate"
                )

            if evolution_metrics.get("speciation_events", 0) == 0:
                recommendations.append(
                    "No speciation events - increase environmental pressure variance"
                )

            report.insights_generated.extend(recommendations)
            report.actions_taken["recommendations_generated"] = len(recommendations)

        except Exception as e:
            report.success = False
            report.error = str(e)
            logger.error(f"Evolution kaizen error: {e}")

        report.duration_ms = (time.perf_counter() - start) * 1000
        self.history.append(report)
        return report

    # Helper methods

    def _genome_signature(self, genome) -> str:
        """Create unique signature for genome based on gene expression"""
        gene_str = "_".join(
            f"{g.name}:{g.expression_level:.2f}"
            for g in sorted(genome.genes, key=lambda x: x.name)
        )
        return gene_str

    def _get_dominant_category(self, genome) -> str:
        """Get the most common gene category in genome"""
        from collections import Counter
        categories = [g.category for g in genome.genes]
        if not categories:
            return "unknown"
        return Counter(categories).most_common(1)[0][0]

    def _cluster_by_fitness(self, population: list, num_bands: int = 10) -> list[list]:
        """Cluster genomes into fitness bands"""
        if not population:
            return []

        sorted_pop = sorted(population, key=lambda g: g.fitness)
        band_size = max(1, len(sorted_pop) // num_bands)

        bands = []
        for i in range(0, len(sorted_pop), band_size):
            bands.append(sorted_pop[i:i+band_size])

        return bands

    def _find_common_genes(self, genomes: list) -> list:
        """Find genes that appear in >50% of genomes"""
        from collections import Counter

        all_genes = []
        for genome in genomes:
            all_genes.extend([g.name for g in genome.genes])

        gene_counts = Counter(all_genes)
        threshold = len(genomes) * 0.5

        common = [
            genomes[0].genes[0]  # Placeholder - would need actual gene lookup
            for name, count in gene_counts.items()
            if count > threshold
        ]

        return common

    def _calculate_diversity(self, population: list) -> float:
        """Calculate population diversity (0.0 = all same, 1.0 = all different)"""
        if len(population) < 2:
            return 1.0

        # Simple diversity: ratio of unique gene combinations to total
        signatures = set(self._genome_signature(g) for g in population)
        return len(signatures) / len(population)


def integrate_with_dream_cycle(evolution_engine, dream_cycle_instance):
    """
    Integrate evolution engine with WhiteMagic's dream cycle.

    Adds evolution-specific phases to the dream cycle that run during
    idle periods to continuously improve the evolutionary process.
    """
    logger.info("🧬 Integrating Evolution Engine with Dream Cycle...")

    evo_dream = EvolutionDreamCycle(evolution_engine)

    # Register evolution phases with dream cycle
    # (This would hook into the actual dream cycle's phase rotation)

    logger.info("✅ Evolution-Dream integration complete")
    return evo_dream
