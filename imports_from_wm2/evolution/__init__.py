"""
WM2 Evolution Module — Massively Scaled Self-Evolution System
================================================================

Integrates with WhiteMagic's dream cycle, kaizen engine, and emergence detection
to enable continuous autonomous improvement through evolutionary simulation.

Architecture:
- Python orchestration and integration
- Rust core for parallel evolution (millions of lineages/sec)
- Mojo acceleration for fitness calculations
- Julia for statistical analysis
- Zig for memory-efficient genome storage

Scale targets:
- 10,000,000+ lineages per run
- 10,000+ generations
- 1,000+ mutation types
- Multi-dimensional fitness landscapes
- Real-time code generation from successful mutations
"""

from .hyperevolution_engine import (
    HyperEvolutionEngine,
    Gene,
    Genome,
    FitnessVector,
    EvolutionMetrics,
    GeneLibrary,
    FitnessEvaluator,
)

from .dream_integration import (
    EvolutionDreamPhase,
    integrate_with_dream_cycle,
)

from .kaizen_integration import (
    EvolutionKaizenAnalyzer,
    extract_improvement_proposals,
)

from .code_generator import (
    CodeGenerator,
    generate_code_from_genome,
    apply_mutations_to_codebase,
)

from .insights_pipeline import (
    InsightsPipeline,
    extract_actionable_insights,
    generate_mutation_recommendations,
)

__all__ = [
    "HyperEvolutionEngine",
    "Gene",
    "Genome",
    "FitnessVector",
    "EvolutionMetrics",
    "GeneLibrary",
    "FitnessEvaluator",
    "EvolutionDreamPhase",
    "integrate_with_dream_cycle",
    "EvolutionKaizenAnalyzer",
    "extract_improvement_proposals",
    "CodeGenerator",
    "generate_code_from_genome",
    "apply_mutations_to_codebase",
    "InsightsPipeline",
    "extract_actionable_insights",
    "generate_mutation_recommendations",
]

__version__ = "1.0.0"
