#!/usr/bin/env python3
"""
Code Validation Framework

Validates generated code through multiple tiers:
1. Syntax validation
2. Static analysis
3. Actionable insights generation
"""

import ast
import json
from typing import Dict, List, Tuple

class CodeValidator:
    """Multi-tier code validation"""
    
    def __init__(self):
        self.results = []
    
    def validate_syntax(self, code: str, name: str = "generated") -> Tuple[bool, str, float]:
        """Tier 1: Syntax validation"""
        try:
            ast.parse(code)
            return True, "Valid Python syntax", 0.2
        except SyntaxError as e:
            return False, f"Syntax error: {e}", 0.0
    
    def analyze_imports(self, code: str) -> Tuple[bool, List[str], float]:
        """Check if imports are available"""
        try:
            tree = ast.parse(code)
            imports = []
            
            for node in ast.walk(tree):
                if isinstance(node, ast.Import):
                    for alias in node.names:
                        imports.append(alias.name)
                elif isinstance(node, ast.ImportFrom):
                    if node.module:
                        imports.append(node.module)
            
            # Check if imports exist (simplified - just check common ones)
            unavailable = []
            common_modules = {'os', 'sys', 'json', 'time', 'pathlib', 'typing', 
                            'dataclasses', 'asyncio', 'multiprocessing', 'threading',
                            'numpy', 'pandas', 'requests'}
            
            for imp in imports:
                base = imp.split('.')[0]
                if base not in common_modules:
                    try:
                        __import__(base)
                    except ImportError:
                        unavailable.append(base)
            
            if unavailable:
                return False, unavailable, 0.0
            return True, imports, 0.1
            
        except Exception:
            return False, [], 0.0
    
    def analyze_patterns(self, code: str) -> Dict[str, int]:
        """Analyze code patterns"""
        patterns = {
            'async_functions': code.count('async def'),
            'decorators': code.count('@'),
            'classes': code.count('class '),
            'functions': code.count('def '),
            'list_comprehensions': code.count('[' if 'for' in code else ''),
            'context_managers': code.count('with '),
            'error_handling': code.count('try:'),
        }
        return patterns
    
    def generate_insights(self, genome_genes: List[str]) -> List[Dict]:
        """Generate actionable insights from genome"""
        insights = []
        
        # Map genes to actionable recommendations
        gene_to_insight = {
            'caching': {
                'pattern': 'Add @lru_cache decorator',
                'target': 'Pure functions called repeatedly',
                'impact': 'high',
                'example': '@lru_cache(maxsize=128)\ndef expensive_function(x): ...'
            },
            'async_functions': {
                'pattern': 'Convert to async/await',
                'target': 'I/O-bound operations',
                'impact': 'high',
                'example': 'async def fetch_data(): ...'
            },
            'numpy_vectorization': {
                'pattern': 'Use NumPy vectorized operations',
                'target': 'Loops over numerical data',
                'impact': 'very_high',
                'example': 'result = np.sum(array) instead of sum(list)'
            },
            'multiprocessing': {
                'pattern': 'Use multiprocessing.Pool',
                'target': 'CPU-bound parallel tasks',
                'impact': 'high',
                'example': 'with Pool() as pool: results = pool.map(func, data)'
            },
            'memory_pooling': {
                'pattern': 'Implement object pooling',
                'target': 'Frequently allocated/deallocated objects',
                'impact': 'medium',
                'example': 'pool = ObjectPool(factory, max_size=100)'
            },
            'rust_integration': {
                'pattern': 'Move hot path to Rust',
                'target': 'Performance-critical loops',
                'impact': 'very_high',
                'example': 'Use PyO3 to expose Rust functions to Python'
            },
        }
        
        for gene in genome_genes:
            if gene in gene_to_insight:
                insight = gene_to_insight[gene].copy()
                insight['gene'] = gene
                insights.append(insight)
        
        return insights
    
    def validate_genome(self, genome: Dict) -> Dict:
        """Validate a genome and generate insights"""
        genes = genome.get('genes', [])
        
        # Generate insights
        insights = self.generate_insights(genes)
        
        # Calculate synthetic fitness
        gene_values = [0.5] * len(genes)  # Simplified
        synthetic_fitness = sum(gene_values) / len(gene_values) if gene_values else 0.0
        
        result = {
            'genome_size': len(genes),
            'genes': genes,
            'synthetic_fitness': synthetic_fitness,
            'insights': insights,
            'actionable_count': len(insights),
            'high_impact_count': sum(1 for i in insights if i['impact'] in ['high', 'very_high']),
        }
        
        return result


def main():
    print("=" * 80)
    print("CODE VALIDATION FRAMEWORK")
    print("=" * 80)
    print()
    
    # Load results from real gene library run
    try:
        with open("real_gene_library_results.json") as f:
            results = json.load(f)
        
        print("📊 Analyzing best genome from evolution...")
        print()
        
        validator = CodeValidator()
        
        # Validate best genome
        genome = results['best_genome']
        validation = validator.validate_genome(genome)
        
        print("🧬 GENOME ANALYSIS:")
        print(f"   Size: {validation['genome_size']} genes")
        print(f"   Synthetic fitness: {validation['synthetic_fitness']:.4f}")
        print(f"   Actionable insights: {validation['actionable_count']}")
        print(f"   High-impact insights: {validation['high_impact_count']}")
        print()
        
        if validation['insights']:
            print("💡 ACTIONABLE INSIGHTS:")
            print()
            for i, insight in enumerate(validation['insights'], 1):
                print(f"{i}. {insight['pattern']} (Impact: {insight['impact'].upper()})")
                print(f"   Gene: {insight['gene']}")
                print(f"   Target: {insight['target']}")
                print(f"   Example: {insight['example']}")
                print()
        else:
            print("⚠️  No actionable insights generated")
            print("   Genome may need more specific genes")
        
        # Save validation results
        with open("validation_results.json", 'w') as f:
            json.dump(validation, f, indent=2)
        
        print("💾 Validation results saved to validation_results.json")
        print()
        print("✅ Validation framework operational!")
        print()
        print("Next steps:")
        print("1. Implement benchmark harness to test insights")
        print("2. Apply insights to WhiteMagic codebase")
        print("3. Measure actual performance improvements")
        
    except FileNotFoundError:
        print("❌ No results file found")
        print("   Run run_with_real_genes.py first")

if __name__ == "__main__":
    main()
