"""
Insights Pipeline for Evolution Engine
========================================

Extracts actionable insights from evolutionary simulation metrics and
transforms them into concrete recommendations for system improvement.

This is the bridge between "what happened in simulation" and "what to do next".

Pipeline stages:
1. Metric extraction - Pull key statistics from evolution run
2. Pattern detection - Find trends, anomalies, breakthroughs
3. Insight synthesis - Combine patterns into coherent insights
4. Recommendation generation - Create actionable next steps
5. Priority ranking - Order recommendations by impact/effort
"""

import logging
import statistics
from collections import defaultdict
from dataclasses import dataclass, field
from typing import Any

logger = logging.getLogger(__name__)


@dataclass
class EvolutionInsight:
    """A single insight extracted from evolution metrics"""
    id: str
    category: str  # breakthrough, trend, anomaly, optimization, discovery
    title: str
    description: str
    evidence: dict[str, Any]
    confidence: float  # 0.0-1.0
    actionable: bool
    recommendations: list[str] = field(default_factory=list)


@dataclass
class MutationRecommendation:
    """A recommended mutation to try in future runs"""
    mutation_name: str
    category: str
    description: str
    rationale: str
    expected_impact: float
    priority: int


class InsightsPipeline:
    """
    Transforms raw evolution metrics into actionable insights.
    
    This is where the magic happens - we go from numbers to understanding.
    """

    def __init__(self):
        self.insights: list[EvolutionInsight] = []
        self.recommendations: list[MutationRecommendation] = []

    def process_evolution_run(
        self,
        metrics: dict[str, Any],
        population: list,
        generation: int
    ) -> dict[str, Any]:
        """
        Complete pipeline: metrics → insights → recommendations
        """
        logger.info("🔍 Starting insights pipeline...")

        # Stage 1: Extract key metrics
        extracted = self._extract_metrics(metrics, population, generation)

        # Stage 2: Detect patterns
        patterns = self._detect_patterns(extracted)

        # Stage 3: Synthesize insights
        self.insights = self._synthesize_insights(patterns, extracted)

        # Stage 4: Generate recommendations
        self.recommendations = self._generate_recommendations(self.insights, extracted)

        # Stage 5: Rank by priority
        self._rank_recommendations()

        logger.info("✅ Pipeline complete:")
        logger.info(f"   Insights: {len(self.insights)}")
        logger.info(f"   Recommendations: {len(self.recommendations)}")
        logger.info(f"   High-priority: {sum(1 for r in self.recommendations if r.priority >= 8)}")

        return {
            "insights": [self._insight_to_dict(i) for i in self.insights],
            "recommendations": [self._recommendation_to_dict(r) for r in self.recommendations],
            "summary": self._generate_summary()
        }

    def _extract_metrics(
        self,
        metrics: dict[str, Any],
        population: list,
        generation: int
    ) -> dict[str, Any]:
        """Extract and compute key metrics"""
        extracted = {
            "total_lineages": metrics.get("total_lineages_simulated", 0),
            "generations": metrics.get("generations_completed", generation),
            "throughput": metrics.get("throughput_lineages_per_sec", 0),
            "convergence_gen": metrics.get("convergence_generation", 0),
            "best_fitness": metrics.get("best_fitness", {}),
            "fitness_history": metrics.get("fitness_history", []),
            "diversity_history": metrics.get("diversity_history", []),
            "mutation_success_rates": metrics.get("mutation_success_rates", {}),
            "synergy_discoveries": metrics.get("synergy_discoveries", []),
            "speciation_events": metrics.get("speciation_events", 0),
            "extinction_events": metrics.get("extinction_events", 0),
        }

        # Compute derived metrics
        if extracted["fitness_history"]:
            extracted["fitness_improvement"] = (
                extracted["fitness_history"][-1] - extracted["fitness_history"][0]
            )
            extracted["fitness_variance"] = statistics.variance(extracted["fitness_history"])
            extracted["fitness_trend"] = self._compute_trend(extracted["fitness_history"])

        if extracted["diversity_history"]:
            extracted["diversity_trend"] = self._compute_trend(extracted["diversity_history"])
            extracted["final_diversity"] = extracted["diversity_history"][-1]

        # Population metrics
        if population:
            fitnesses = [g.fitness for g in population]
            extracted["population_size"] = len(population)
            extracted["fitness_mean"] = statistics.mean(fitnesses)
            extracted["fitness_stdev"] = statistics.stdev(fitnesses) if len(fitnesses) > 1 else 0
            extracted["fitness_range"] = max(fitnesses) - min(fitnesses)

        return extracted

    def _detect_patterns(self, metrics: dict[str, Any]) -> list[dict[str, Any]]:
        """Detect interesting patterns in the metrics"""
        patterns = []

        # Pattern: Rapid convergence
        if metrics.get("convergence_gen", 0) < metrics.get("generations", 0) * 0.2:
            patterns.append({
                "type": "rapid_convergence",
                "severity": "high",
                "data": {
                    "convergence_gen": metrics["convergence_gen"],
                    "total_gens": metrics["generations"]
                }
            })

        # Pattern: Fitness plateau
        if metrics.get("fitness_history"):
            recent = metrics["fitness_history"][-20:]
            if len(recent) > 10 and max(recent) - min(recent) < 0.1:
                patterns.append({
                    "type": "fitness_plateau",
                    "severity": "medium",
                    "data": {"plateau_length": len(recent)}
                })

        # Pattern: Diversity collapse
        if metrics.get("diversity_trend", 0) < -0.5:  # Strong negative trend
            patterns.append({
                "type": "diversity_collapse",
                "severity": "high",
                "data": {
                    "trend": metrics["diversity_trend"],
                    "final_diversity": metrics.get("final_diversity", 0)
                }
            })

        # Pattern: Breakthrough mutation
        if metrics.get("mutation_success_rates"):
            success_rates = metrics["mutation_success_rates"]
            if success_rates:
                best_mutation = max(success_rates.items(), key=lambda x: x[1])
                if best_mutation[1] > 0.8:  # >80% success rate
                    patterns.append({
                        "type": "breakthrough_mutation",
                        "severity": "high",
                        "data": {
                            "mutation": best_mutation[0],
                            "success_rate": best_mutation[1]
                        }
                    })

        # Pattern: Synergy discovery
        if len(metrics.get("synergy_discoveries", [])) > 10:
            patterns.append({
                "type": "synergy_rich",
                "severity": "medium",
                "data": {
                    "synergy_count": len(metrics["synergy_discoveries"]),
                    "sample": metrics["synergy_discoveries"][:3]
                }
            })

        # Pattern: High throughput
        if metrics.get("throughput", 0) > 1_000_000:  # >1M lineages/sec
            patterns.append({
                "type": "high_throughput",
                "severity": "low",
                "data": {"throughput": metrics["throughput"]}
            })

        return patterns

    def _synthesize_insights(
        self,
        patterns: list[dict[str, Any]],
        metrics: dict[str, Any]
    ) -> list[EvolutionInsight]:
        """Synthesize patterns into coherent insights"""
        insights = []

        for pattern in patterns:
            if pattern["type"] == "rapid_convergence":
                insights.append(EvolutionInsight(
                    id="insight_rapid_convergence",
                    category="anomaly",
                    title="Rapid Convergence Detected",
                    description=(
                        f"Population converged at generation {pattern['data']['convergence_gen']} "
                        f"({pattern['data']['convergence_gen'] / pattern['data']['total_gens']:.1%} of total). "
                        "This suggests insufficient exploration or too strong selection pressure."
                    ),
                    evidence=pattern["data"],
                    confidence=0.9,
                    actionable=True,
                    recommendations=[
                        "Increase mutation rate by 50%",
                        "Reduce selection pressure",
                        "Add diversity injection every 100 generations"
                    ]
                ))

            elif pattern["type"] == "fitness_plateau":
                insights.append(EvolutionInsight(
                    id="insight_fitness_plateau",
                    category="trend",
                    title="Fitness Plateau Reached",
                    description=(
                        f"Fitness has plateaued for {pattern['data']['plateau_length']} generations. "
                        "Population may be stuck in local optimum."
                    ),
                    evidence=pattern["data"],
                    confidence=0.8,
                    actionable=True,
                    recommendations=[
                        "Inject random mutations to escape local optimum",
                        "Try different crossover strategies",
                        "Increase environmental pressure variance"
                    ]
                ))

            elif pattern["type"] == "diversity_collapse":
                insights.append(EvolutionInsight(
                    id="insight_diversity_collapse",
                    category="anomaly",
                    title="Diversity Collapse",
                    description=(
                        f"Population diversity has collapsed (trend: {pattern['data']['trend']:.2f}, "
                        f"final: {pattern['data']['final_diversity']:.2%}). "
                        "Genetic diversity is critically low."
                    ),
                    evidence=pattern["data"],
                    confidence=0.95,
                    actionable=True,
                    recommendations=[
                        "Restart with higher initial diversity",
                        "Implement diversity preservation mechanisms",
                        "Use niching or speciation to maintain variety"
                    ]
                ))

            elif pattern["type"] == "breakthrough_mutation":
                insights.append(EvolutionInsight(
                    id="insight_breakthrough",
                    category="breakthrough",
                    title=f"Breakthrough Mutation: {pattern['data']['mutation']}",
                    description=(
                        f"Mutation '{pattern['data']['mutation']}' achieved "
                        f"{pattern['data']['success_rate']:.1%} success rate. "
                        "This is a highly effective mutation that should be prioritized."
                    ),
                    evidence=pattern["data"],
                    confidence=0.95,
                    actionable=True,
                    recommendations=[
                        f"Increase frequency of {pattern['data']['mutation']} mutation",
                        "Analyze why this mutation succeeds",
                        "Look for similar mutations to try"
                    ]
                ))

            elif pattern["type"] == "synergy_rich":
                insights.append(EvolutionInsight(
                    id="insight_synergies",
                    category="discovery",
                    title="Rich Synergy Landscape",
                    description=(
                        f"Discovered {pattern['data']['synergy_count']} gene synergies. "
                        "Many genes work better together than alone."
                    ),
                    evidence=pattern["data"],
                    confidence=0.85,
                    actionable=True,
                    recommendations=[
                        "Prioritize synergistic gene combinations in crossover",
                        "Create 'gene packages' that stay together",
                        "Analyze synergy patterns for insights"
                    ]
                ))

            elif pattern["type"] == "high_throughput":
                insights.append(EvolutionInsight(
                    id="insight_throughput",
                    category="optimization",
                    title="High Simulation Throughput",
                    description=(
                        f"Achieved {pattern['data']['throughput']:,.0f} lineages/second. "
                        "Parallel execution is working efficiently."
                    ),
                    evidence=pattern["data"],
                    confidence=1.0,
                    actionable=False,
                    recommendations=[]
                ))

        return insights

    def _generate_recommendations(
        self,
        insights: list[EvolutionInsight],
        metrics: dict[str, Any]
    ) -> list[MutationRecommendation]:
        """Generate mutation recommendations from insights"""
        recommendations = []

        # Extract all recommendations from insights
        all_recs = []
        for insight in insights:
            all_recs.extend(insight.recommendations)

        # Convert to structured recommendations
        rec_map = {
            "increase mutation rate": MutationRecommendation(
                mutation_name="adaptive_mutation_rate",
                category="optimization",
                description="Dynamically adjust mutation rate based on diversity",
                rationale="Prevents premature convergence and diversity collapse",
                expected_impact=0.8,
                priority=9
            ),
            "diversity injection": MutationRecommendation(
                mutation_name="periodic_diversity_injection",
                category="exploration",
                description="Inject random genomes every N generations",
                rationale="Maintains genetic diversity and prevents local optima",
                expected_impact=0.7,
                priority=8
            ),
            "synergistic crossover": MutationRecommendation(
                mutation_name="synergy_aware_crossover",
                category="feature",
                description="Crossover that preserves known synergistic gene pairs",
                rationale="Leverages discovered gene synergies",
                expected_impact=0.85,
                priority=9
            ),
            "niching": MutationRecommendation(
                mutation_name="fitness_sharing_niching",
                category="architecture",
                description="Implement fitness sharing to maintain diverse niches",
                rationale="Prevents single strategy from dominating",
                expected_impact=0.75,
                priority=7
            ),
        }

        # Match recommendations to structured versions
        for rec_text in all_recs:
            for key, rec in rec_map.items():
                if key in rec_text.lower():
                    if rec not in recommendations:
                        recommendations.append(rec)

        # Add general recommendations based on metrics
        if metrics.get("convergence_gen", 0) > metrics.get("generations", 0) * 0.8:
            recommendations.append(MutationRecommendation(
                mutation_name="stronger_selection_pressure",
                category="optimization",
                description="Increase selection pressure to speed convergence",
                rationale="Slow convergence detected",
                expected_impact=0.6,
                priority=6
            ))

        if len(metrics.get("synergy_discoveries", [])) < 5:
            recommendations.append(MutationRecommendation(
                mutation_name="synergy_detection_enhancement",
                category="feature",
                description="Improve synergy detection algorithms",
                rationale="Few synergies discovered - may be missing interactions",
                expected_impact=0.7,
                priority=7
            ))

        return recommendations

    def _rank_recommendations(self):
        """Rank recommendations by priority"""
        self.recommendations.sort(key=lambda r: r.priority, reverse=True)

    def _compute_trend(self, values: list[float]) -> float:
        """Compute trend direction (-1 to 1)"""
        if len(values) < 2:
            return 0.0

        # Simple linear regression slope
        n = len(values)
        x = list(range(n))
        x_mean = sum(x) / n
        y_mean = sum(values) / n

        numerator = sum((x[i] - x_mean) * (values[i] - y_mean) for i in range(n))
        denominator = sum((x[i] - x_mean) ** 2 for i in range(n))

        if denominator == 0:
            return 0.0

        slope = numerator / denominator

        # Normalize to -1 to 1 range
        max_slope = (max(values) - min(values)) / n if n > 0 else 1
        return max(-1.0, min(1.0, slope / max_slope if max_slope > 0 else 0))

    def _generate_summary(self) -> str:
        """Generate human-readable summary"""
        lines = ["# Evolution Insights Summary\n"]

        # Insights by category
        by_category = defaultdict(list)
        for insight in self.insights:
            by_category[insight.category].append(insight)

        for category, insights in sorted(by_category.items()):
            lines.append(f"\n## {category.title()}\n")
            for insight in insights:
                lines.append(f"- **{insight.title}**: {insight.description}\n")

        # Top recommendations
        lines.append("\n## Top Recommendations\n")
        for i, rec in enumerate(self.recommendations[:5], 1):
            lines.append(
                f"{i}. **{rec.mutation_name}** (priority {rec.priority}): "
                f"{rec.description}\n"
            )

        return "".join(lines)

    def _insight_to_dict(self, insight: EvolutionInsight) -> dict[str, Any]:
        """Convert insight to dictionary"""
        return {
            "id": insight.id,
            "category": insight.category,
            "title": insight.title,
            "description": insight.description,
            "confidence": insight.confidence,
            "actionable": insight.actionable,
            "recommendations": insight.recommendations
        }

    def _recommendation_to_dict(self, rec: MutationRecommendation) -> dict[str, Any]:
        """Convert recommendation to dictionary"""
        return {
            "mutation_name": rec.mutation_name,
            "category": rec.category,
            "description": rec.description,
            "rationale": rec.rationale,
            "expected_impact": rec.expected_impact,
            "priority": rec.priority
        }


def extract_actionable_insights(
    metrics: dict[str, Any],
    population: list,
    generation: int
) -> dict[str, Any]:
    """
    Main entry point for insights extraction.
    
    Returns insights and recommendations.
    """
    pipeline = InsightsPipeline()
    results = pipeline.process_evolution_run(metrics, population, generation)

    logger.info("💡 Insights extraction complete")

    return results


def generate_mutation_recommendations(
    insights: list[EvolutionInsight]
) -> list[MutationRecommendation]:
    """
    Generate mutation recommendations from insights.
    
    This can be called separately if you already have insights.
    """
    pipeline = InsightsPipeline()
    pipeline.insights = insights
    recommendations = pipeline._generate_recommendations(insights, {})
    pipeline._rank_recommendations()

    return recommendations
