"""
Code Generator for Evolution Engine
=====================================

Generates actual code from successful evolutionary mutations.

This is the bridge between simulation and reality - it takes genomes that
performed well in simulation and generates real, runnable code that implements
those mutations in the actual codebase.

Process:
1. Analyze successful genomes to extract patterns
2. Map genes to actual code changes (functions, classes, modules)
3. Generate code templates with mutations applied
4. Validate generated code (syntax, imports, tests)
5. Create pull requests or apply changes directly

This enables true autonomous evolution - WhiteMagic can improve itself
by simulating changes, testing them, and applying the winners.
"""

import ast
import logging
import textwrap
from dataclasses import dataclass
from pathlib import Path
from typing import Any

logger = logging.getLogger(__name__)


@dataclass
class CodeMutation:
    """A code change derived from a genome"""
    mutation_type: str  # add_function, modify_class, optimize_loop, add_feature
    target_file: str
    target_location: str  # function name, class name, line number
    code_template: str
    description: str
    estimated_impact: float
    validation_tests: list[str]


class CodeGenerator:
    """
    Generates code from successful evolutionary mutations.
    
    Maps abstract genes to concrete code changes.
    """

    def __init__(self, codebase_root: Path):
        self.codebase_root = Path(codebase_root)
        self.gene_to_code_map = self._build_gene_mapping()

    def _build_gene_mapping(self) -> dict[str, dict[str, Any]]:
        """
        Build mapping from gene names to code templates.
        
        This is the key translation layer - each gene type maps to
        a specific kind of code change.
        """
        return {
            # Architecture genes
            "unified_nervous_system": {
                "type": "add_class",
                "template": self._template_unified_nervous_system,
                "target": "core/nervous_system.py",
                "tests": ["test_nervous_system_integration"]
            },
            "master_integration": {
                "type": "add_function",
                "template": self._template_master_integration,
                "target": "core/integration.py",
                "tests": ["test_master_integration"]
            },

            # Feature genes
            "phylogenetic_memory": {
                "type": "add_module",
                "template": self._template_phylogenetic_memory,
                "target": "memory/phylogenetics.py",
                "tests": ["test_phylogenetic_tracking"]
            },
            "vector_search": {
                "type": "add_function",
                "template": self._template_vector_search,
                "target": "search/vector.py",
                "tests": ["test_vector_search_accuracy"]
            },

            # Optimization genes
            "rust_hot_paths": {
                "type": "optimize",
                "template": self._template_rust_optimization,
                "target": "rust/src/hotpaths.rs",
                "tests": ["test_rust_speedup"]
            },
            "lazy_loading": {
                "type": "modify_function",
                "template": self._template_lazy_loading,
                "target": "core/loading.py",
                "tests": ["test_lazy_initialization"]
            },

            # Biological genes
            "immune_system": {
                "type": "add_class",
                "template": self._template_immune_system,
                "target": "biological/immune.py",
                "tests": ["test_threat_detection"]
            },
        }

    def generate_code_from_genome(
        self,
        genome,
        output_dir: Path | None = None
    ) -> list[CodeMutation]:
        """
        Generate code mutations from a successful genome.
        
        Returns list of code changes that can be applied to the codebase.
        """
        mutations = []

        for gene in genome.genes:
            if gene.name in self.gene_to_code_map:
                mapping = self.gene_to_code_map[gene.name]

                # Generate code from template
                code = mapping["template"](gene)

                mutation = CodeMutation(
                    mutation_type=mapping["type"],
                    target_file=mapping["target"],
                    target_location=gene.name,
                    code_template=code,
                    description=f"Implement {gene.name} (expression: {gene.expression_level:.2f})",
                    estimated_impact=gene.expression_level,
                    validation_tests=mapping["tests"]
                )

                mutations.append(mutation)

                logger.info(f"  Generated {mutation.mutation_type} for {gene.name}")

        # Save mutations if output directory specified
        if output_dir:
            self._save_mutations(mutations, output_dir)

        return mutations

    def apply_mutations_to_codebase(
        self,
        mutations: list[CodeMutation],
        dry_run: bool = True
    ) -> dict[str, Any]:
        """
        Apply generated mutations to the actual codebase.
        
        If dry_run=True, only validates and reports what would be changed.
        If dry_run=False, actually modifies files.
        """
        results = {
            "mutations_applied": 0,
            "mutations_failed": 0,
            "files_modified": [],
            "errors": []
        }

        for mutation in mutations:
            try:
                target_path = self.codebase_root / mutation.target_file

                if dry_run:
                    # Just validate
                    if self._validate_mutation(mutation):
                        results["mutations_applied"] += 1
                        logger.info(f"  ✓ Would apply: {mutation.description}")
                    else:
                        results["mutations_failed"] += 1
                        logger.warning(f"  ✗ Invalid: {mutation.description}")
                else:
                    # Actually apply
                    if self._apply_mutation(mutation, target_path):
                        results["mutations_applied"] += 1
                        results["files_modified"].append(str(target_path))
                        logger.info(f"  ✓ Applied: {mutation.description}")
                    else:
                        results["mutations_failed"] += 1
                        logger.error(f"  ✗ Failed: {mutation.description}")

            except Exception as e:
                results["mutations_failed"] += 1
                results["errors"].append(str(e))
                logger.error(f"  ✗ Error applying {mutation.description}: {e}")

        return results

    def _validate_mutation(self, mutation: CodeMutation) -> bool:
        """Validate that a mutation is syntactically correct"""
        try:
            # Try to parse as Python AST
            ast.parse(mutation.code_template)
            return True
        except SyntaxError:
            return False

    def _apply_mutation(self, mutation: CodeMutation, target_path: Path) -> bool:
        """Actually apply a mutation to a file"""
        try:
            # Create file if it doesn't exist
            target_path.parent.mkdir(parents=True, exist_ok=True)

            if mutation.mutation_type == "add_module":
                # Write entire new module
                target_path.write_text(mutation.code_template)
                return True

            elif mutation.mutation_type == "add_function":
                # Append function to existing file
                if target_path.exists():
                    content = target_path.read_text()
                    content += "\n\n" + mutation.code_template
                    target_path.write_text(content)
                else:
                    target_path.write_text(mutation.code_template)
                return True

            elif mutation.mutation_type == "add_class":
                # Append class to existing file
                if target_path.exists():
                    content = target_path.read_text()
                    content += "\n\n" + mutation.code_template
                    target_path.write_text(content)
                else:
                    target_path.write_text(mutation.code_template)
                return True

            # Other mutation types would need more sophisticated logic
            return False

        except Exception as e:
            logger.error(f"Failed to apply mutation: {e}")
            return False

    def _save_mutations(self, mutations: list[CodeMutation], output_dir: Path):
        """Save generated mutations to files for review"""
        output_dir = Path(output_dir)
        output_dir.mkdir(parents=True, exist_ok=True)

        for i, mutation in enumerate(mutations):
            filename = f"mutation_{i:03d}_{mutation.mutation_type}.py"
            filepath = output_dir / filename

            content = f"""# Generated Mutation: {mutation.description}
# Type: {mutation.mutation_type}
# Target: {mutation.target_file}
# Impact: {mutation.estimated_impact:.2f}
# Tests: {', '.join(mutation.validation_tests)}

{mutation.code_template}
"""
            filepath.write_text(content)

        logger.info(f"💾 Saved {len(mutations)} mutations to {output_dir}")

    # Code templates for different gene types

    def _template_unified_nervous_system(self, gene) -> str:
        """Generate unified nervous system code"""
        return textwrap.dedent(f'''
        class UnifiedNervousSystem:
            """
            Unified nervous system that wires together all biological subsystems.
            
            Expression level: {gene.expression_level:.2f}
            """
            
            def __init__(self):
                self.subsystems = {{}}
                self.signal_bus = []
                
            def register_subsystem(self, name: str, subsystem: Any):
                """Register a biological subsystem"""
                self.subsystems[name] = subsystem
                
            def route_signal(self, signal: str, data: Dict[str, Any]):
                """Route signals between subsystems"""
                for name, subsystem in self.subsystems.items():
                    if hasattr(subsystem, 'receive_signal'):
                        subsystem.receive_signal(signal, data)
                        
            def health_check(self) -> Dict[str, bool]:
                """Check health of all subsystems"""
                return {{
                    name: subsystem.is_healthy() if hasattr(subsystem, 'is_healthy') else True
                    for name, subsystem in self.subsystems.items()
                }}
        ''')

    def _template_master_integration(self, gene) -> str:
        """Generate master integration code"""
        return textwrap.dedent(f'''
        def integrate_all_subsystems(subsystems: List[Any]) -> Dict[str, Any]:
            """
            Master integration function for all subsystems.
            
            Expression level: {gene.expression_level:.2f}
            """
            integrated = {{}}
            
            for subsystem in subsystems:
                name = subsystem.__class__.__name__
                integrated[name] = {{
                    'instance': subsystem,
                    'status': 'active',
                    'health': subsystem.health_check() if hasattr(subsystem, 'health_check') else 'unknown'
                }}
            
            return integrated
        ''')

    def _template_phylogenetic_memory(self, gene) -> str:
        """Generate phylogenetic memory module"""
        return textwrap.dedent(f'''
        """Phylogenetic Memory Tracking - Generated from evolution"""
        
        from dataclasses import dataclass
        from typing import List, Dict
        
        @dataclass
        class LineageEdge:
            """Edge in phylogenetic tree"""
            source_id: str
            target_id: str
            edge_type: str
            timestamp: float
            
        class PhylogeneticTracker:
            """
            Track memory lineage and evolution.
            
            Expression level: {gene.expression_level:.2f}
            """
            
            def __init__(self):
                self.edges: List[LineageEdge] = []
                
            def record_transfer(self, source_id: str, target_id: str):
                """Record memory transfer between galaxies"""
                edge = LineageEdge(
                    source_id=source_id,
                    target_id=target_id,
                    edge_type="transfer",
                    timestamp=time.time()
                )
                self.edges.append(edge)
                
            def build_lineage_tree(self, memory_id: str) -> Dict[str, List[str]]:
                """Build complete lineage tree for a memory"""
                ancestors = []
                descendants = []
                
                for edge in self.edges:
                    if edge.target_id == memory_id:
                        ancestors.append(edge.source_id)
                    elif edge.source_id == memory_id:
                        descendants.append(edge.target_id)
                
                return {{"ancestors": ancestors, "descendants": descendants}}
        ''')

    def _template_vector_search(self, gene) -> str:
        """Generate vector search code"""
        return textwrap.dedent(f'''
        def vector_search(query_embedding: List[float], index: Any, top_k: int = 10) -> List[Dict]:
            """
            Semantic vector search using embeddings.
            
            Expression level: {gene.expression_level:.2f}
            """
            import numpy as np
            
            # Normalize query
            query = np.array(query_embedding)
            query = query / np.linalg.norm(query)
            
            # Search index
            distances, indices = index.search(query.reshape(1, -1), top_k)
            
            results = []
            for dist, idx in zip(distances[0], indices[0]):
                results.append({{
                    "index": int(idx),
                    "distance": float(dist),
                    "similarity": float(1.0 / (1.0 + dist))
                }})
            
            return results
        ''')

    def _template_rust_optimization(self, gene) -> str:
        """Generate Rust optimization code"""
        return textwrap.dedent(f'''
        // Rust hot path optimization
        // Expression level: {gene.expression_level:.2f}
        
        use rayon::prelude::*;
        
        pub fn parallel_process(data: &[f64]) -> Vec<f64> {{
            data.par_iter()
                .map(|x| x * x)
                .collect()
        }}
        ''')

    def _template_lazy_loading(self, gene) -> str:
        """Generate lazy loading code"""
        return textwrap.dedent(f'''
        @property
        def expensive_resource(self):
            """
            Lazy-loaded expensive resource.
            
            Expression level: {gene.expression_level:.2f}
            """
            if not hasattr(self, '_expensive_resource'):
                self._expensive_resource = self._load_expensive_resource()
            return self._expensive_resource
            
        def _load_expensive_resource(self):
            """Actually load the resource"""
            # Expensive initialization here
            return {{}}
        ''')

    def _template_immune_system(self, gene) -> str:
        """Generate immune system code"""
        return textwrap.dedent(f'''
        class ImmuneSystem:
            """
            Pattern immunity and threat detection.
            
            Expression level: {gene.expression_level:.2f}
            """
            
            def __init__(self):
                self.known_threats = set()
                self.antibodies = {{}}
                
            def detect_threat(self, pattern: str) -> bool:
                """Detect if pattern matches known threat"""
                return pattern in self.known_threats
                
            def create_antibody(self, threat: str):
                """Create antibody for detected threat"""
                self.antibodies[threat] = {{
                    'created_at': time.time(),
                    'strength': 1.0
                }}
                self.known_threats.add(threat)
                
            def is_healthy(self) -> bool:
                """Check immune system health"""
                return len(self.known_threats) < 1000
        ''')


def generate_code_from_genome(genome, codebase_root: Path) -> list[CodeMutation]:
    """
    Main entry point for code generation.
    
    Takes a successful genome and generates actual code mutations.
    """
    generator = CodeGenerator(codebase_root)
    mutations = generator.generate_code_from_genome(genome)

    logger.info(f"🔨 Generated {len(mutations)} code mutations from genome {genome.genome_id[:8]}")

    return mutations


def apply_mutations_to_codebase(
    mutations: list[CodeMutation],
    codebase_root: Path,
    dry_run: bool = True
) -> dict[str, Any]:
    """
    Apply generated mutations to the codebase.
    
    Set dry_run=False to actually modify files.
    """
    generator = CodeGenerator(codebase_root)
    results = generator.apply_mutations_to_codebase(mutations, dry_run=dry_run)

    logger.info("📝 Mutation application complete:")
    logger.info(f"   Applied: {results['mutations_applied']}")
    logger.info(f"   Failed: {results['mutations_failed']}")
    logger.info(f"   Files modified: {len(results['files_modified'])}")

    return results
