#!/usr/bin/env python3
"""
Gene Library Seed Vault Builder

Extract real code patterns from WhiteMagic codebases to create a rich gene library.
This becomes the foundation for meaningful evolution.
"""

import os
import json
from pathlib import Path
from typing import List, Dict, Set
import re
from collections import defaultdict

class GeneLibraryBuilder:
    """Build gene library from real codebases"""
    
    def __init__(self):
        self.genes = []
        self.gene_ids = set()
        self.patterns = defaultdict(int)
        
    def scan_python_file(self, filepath: Path) -> List[Dict]:
        """Extract patterns from Python file"""
        genes = []
        
        try:
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Architecture patterns
            if 'async def' in content:
                genes.append(self._create_gene('async_functions', 'Architecture', 0.85))
            if 'asyncio' in content:
                genes.append(self._create_gene('asyncio_usage', 'Architecture', 0.80))
            if 'multiprocessing' in content:
                genes.append(self._create_gene('multiprocessing', 'Architecture', 0.85))
            if 'threading' in content:
                genes.append(self._create_gene('threading', 'Architecture', 0.75))
            if '@dataclass' in content:
                genes.append(self._create_gene('dataclasses', 'Architecture', 0.70))
            if 'Protocol' in content and 'typing' in content:
                genes.append(self._create_gene('protocols', 'Architecture', 0.75))
            
            # Optimization patterns
            if '@lru_cache' in content or '@cache' in content:
                genes.append(self._create_gene('caching', 'Optimization', 0.85))
            if 'numpy' in content:
                genes.append(self._create_gene('numpy_vectorization', 'Optimization', 0.90))
            if 'numba' in content:
                genes.append(self._create_gene('numba_jit', 'Optimization', 0.95))
            if 'mmap' in content:
                genes.append(self._create_gene('memory_mapping', 'Optimization', 0.80))
            if 'pool' in content.lower() and 'memory' in content.lower():
                genes.append(self._create_gene('memory_pooling', 'Optimization', 0.85))
            
            # Feature patterns
            if 'logging' in content:
                genes.append(self._create_gene('logging', 'Feature', 0.60))
            if 'argparse' in content or 'click' in content:
                genes.append(self._create_gene('cli_interface', 'Feature', 0.65))
            if 'pydantic' in content:
                genes.append(self._create_gene('pydantic_validation', 'Feature', 0.75))
            if 'pytest' in content or 'unittest' in content:
                genes.append(self._create_gene('testing', 'Feature', 0.70))
            
            # Intelligence patterns
            if 'embedding' in content.lower():
                genes.append(self._create_gene('embeddings', 'Intelligence', 0.85))
            if 'vector' in content.lower() and 'search' in content.lower():
                genes.append(self._create_gene('vector_search', 'Intelligence', 0.90))
            if 'graph' in content.lower() and ('node' in content.lower() or 'edge' in content.lower()):
                genes.append(self._create_gene('graph_algorithms', 'Intelligence', 0.85))
            if 'pattern' in content.lower() and 'match' in content.lower():
                genes.append(self._create_gene('pattern_matching', 'Intelligence', 0.80))
            
            # Biological patterns (adaptive systems)
            if 'adapt' in content.lower():
                genes.append(self._create_gene('adaptive_systems', 'Biological', 0.80))
            if 'evolve' in content.lower() or 'evolution' in content.lower():
                genes.append(self._create_gene('evolutionary_algorithms', 'Biological', 0.85))
            if 'feedback' in content.lower() and 'loop' in content.lower():
                genes.append(self._create_gene('feedback_loops', 'Biological', 0.75))
            
            # Polyglot patterns
            if 'rust' in content.lower() or '.rs' in content:
                genes.append(self._create_gene('rust_integration', 'Polyglot', 0.90))
            if 'subprocess' in content and ('cargo' in content or 'rustc' in content):
                genes.append(self._create_gene('rust_subprocess', 'Polyglot', 0.85))
            if 'ctypes' in content or 'cffi' in content:
                genes.append(self._create_gene('c_bindings', 'Polyglot', 0.80))
            
        except Exception as e:
            pass
        
        return genes
    
    def scan_rust_file(self, filepath: Path) -> List[Dict]:
        """Extract patterns from Rust file"""
        genes = []
        
        try:
            with open(filepath, 'r', encoding='utf-8', errors='ignore') as f:
                content = f.read()
            
            # Rust-specific patterns
            if 'rayon' in content:
                genes.append(self._create_gene('rayon_parallelism', 'Optimization', 0.95))
            if 'tokio' in content:
                genes.append(self._create_gene('tokio_async', 'Architecture', 0.90))
            if 'simd' in content.lower():
                genes.append(self._create_gene('simd_vectorization', 'Optimization', 0.95))
            if 'unsafe' in content:
                genes.append(self._create_gene('unsafe_optimization', 'Optimization', 0.85))
            if 'Arc<' in content or 'Mutex<' in content:
                genes.append(self._create_gene('concurrent_data_structures', 'Architecture', 0.85))
            if 'PyO3' in content or 'pyo3' in content:
                genes.append(self._create_gene('python_rust_bridge', 'Polyglot', 0.95))
            
        except Exception as e:
            pass
        
        return genes
    
    def _create_gene(self, name: str, category: str, value: float) -> Dict:
        """Create gene dict"""
        gene_id = f"{category.lower()}_{name}"
        if gene_id not in self.gene_ids:
            self.gene_ids.add(gene_id)
            self.patterns[name] += 1
            return {
                'id': gene_id,
                'name': name,
                'category': category,
                'value': value,
                'frequency': 1
            }
        return None
    
    def scan_directory(self, directory: Path, extensions: List[str]) -> None:
        """Scan directory for code patterns"""
        print(f"📂 Scanning {directory}...")
        
        file_count = 0
        for ext in extensions:
            for filepath in directory.rglob(f"*{ext}"):
                # Skip test files, migrations, etc.
                if any(skip in str(filepath) for skip in ['test_', '__pycache__', '.git', 'node_modules', 'venv', '.venv']):
                    continue
                
                file_count += 1
                
                if ext == '.py':
                    genes = self.scan_python_file(filepath)
                elif ext == '.rs':
                    genes = self.scan_rust_file(filepath)
                else:
                    continue
                
                for gene in genes:
                    if gene:
                        # Check if gene already exists
                        existing = next((g for g in self.genes if g['id'] == gene['id']), None)
                        if existing:
                            existing['frequency'] += 1
                        else:
                            self.genes.append(gene)
        
        print(f"   ✅ Scanned {file_count} files")
        print(f"   ✅ Found {len(self.genes)} unique gene patterns")
    
    def boost_frequent_patterns(self):
        """Boost value of frequently occurring patterns"""
        print("\n🔧 Boosting frequent patterns...")
        
        for gene in self.genes:
            if gene['frequency'] > 10:
                # Very common pattern - boost value
                boost = min(0.10, gene['frequency'] * 0.005)
                gene['value'] = min(0.99, gene['value'] + boost)
                gene['boosted'] = True
        
        boosted_count = sum(1 for g in self.genes if g.get('boosted', False))
        print(f"   ✅ Boosted {boosted_count} high-frequency patterns")
    
    def add_synergy_genes(self):
        """Add synergy genes for pattern combinations"""
        print("\n🧬 Adding synergy genes...")
        
        synergies = []
        gene_names = {g['name'] for g in self.genes}
        
        # Define synergies
        if 'async_functions' in gene_names and 'tokio_async' in gene_names:
            synergies.append(self._create_gene('async_rust_python_bridge', 'Polyglot', 0.95))
        
        if 'numpy_vectorization' in gene_names and 'simd_vectorization' in gene_names:
            synergies.append(self._create_gene('hybrid_vectorization', 'Optimization', 0.95))
        
        if 'caching' in gene_names and 'memory_pooling' in gene_names:
            synergies.append(self._create_gene('memory_optimization_suite', 'Optimization', 0.90))
        
        if 'embeddings' in gene_names and 'vector_search' in gene_names:
            synergies.append(self._create_gene('semantic_search_pipeline', 'Intelligence', 0.95))
        
        for synergy in synergies:
            if synergy:
                self.genes.append(synergy)
        
        print(f"   ✅ Added {len(synergies)} synergy genes")
    
    def save_library(self, filename: str = "gene_library_seed_vault.json"):
        """Save gene library"""
        # Sort by value (highest first)
        self.genes.sort(key=lambda g: g['value'], reverse=True)
        
        # Add metadata
        library = {
            'version': '1.0.0',
            'total_genes': len(self.genes),
            'categories': {
                'Architecture': len([g for g in self.genes if g['category'] == 'Architecture']),
                'Feature': len([g for g in self.genes if g['category'] == 'Feature']),
                'Optimization': len([g for g in self.genes if g['category'] == 'Optimization']),
                'Biological': len([g for g in self.genes if g['category'] == 'Biological']),
                'Intelligence': len([g for g in self.genes if g['category'] == 'Intelligence']),
                'Polyglot': len([g for g in self.genes if g['category'] == 'Polyglot']),
            },
            'top_patterns': sorted(self.patterns.items(), key=lambda x: x[1], reverse=True)[:20],
            'genes': self.genes
        }
        
        with open(filename, 'w') as f:
            json.dump(library, f, indent=2)
        
        print(f"\n💾 Gene library saved to {filename}")
        return library


def main():
    print("=" * 80)
    print("GENE LIBRARY SEED VAULT BUILDER")
    print("=" * 80)
    print()
    print("Building gene library from WhiteMagic codebases...")
    print()
    
    builder = GeneLibraryBuilder()
    
    # Scan WhiteMagic codebases
    codebases = [
        ("/home/lucas/Desktop/whitemagicdev", ['.py', '.rs']),
        ("/home/lucas/Desktop/whitemagicpublic", ['.py', '.rs']),
    ]
    
    for directory, extensions in codebases:
        if os.path.exists(directory):
            builder.scan_directory(Path(directory), extensions)
        else:
            print(f"⚠️  {directory} not found, skipping")
    
    # Enhance library
    builder.boost_frequent_patterns()
    builder.add_synergy_genes()
    
    # Save
    library = builder.save_library()
    
    # Summary
    print()
    print("=" * 80)
    print("GENE LIBRARY SUMMARY")
    print("=" * 80)
    print()
    print(f"Total genes: {library['total_genes']}")
    print()
    print("By category:")
    for cat, count in library['categories'].items():
        print(f"  {cat:15} {count:4} genes")
    print()
    print("Top 10 patterns:")
    for pattern, count in library['top_patterns'][:10]:
        print(f"  {pattern:30} {count:4} occurrences")
    print()
    print("✅ Gene library ready for evolution!")
    print()
    print("Next: Use this library in evolution runs for real-world patterns")


if __name__ == "__main__":
    main()
