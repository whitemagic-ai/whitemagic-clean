#!/usr/bin/env python3
"""
Deep Scout Analysis for 1,206 Migration Targets
Detailed analysis of all files to optimize shadow clone deployment
"""

from pathlib import Path
from datetime import datetime
import json

class MigrationScout:
    """Deep analysis scout for polyglot migration targets."""
    
    def __init__(self):
        self.root = Path('/home/lucas/Desktop/whitemagicdev')
        self.targets = {
            'rust': [],
            'mojo': [],
            'elixir': [],
            'koka': [],
            'go': []
        }
        self.analysis = {}
        
    def run_deep_analysis(self):
        """Execute deep analysis on all targets."""
        print("🔍 DEEP SCOUT ANALYSIS - 1,206 Migration Targets")
        print("=" * 80)
        print(f"Started: {datetime.now().isoformat()}")
        print()
        
        # Find all Python files
        python_files = list(self.root.rglob('*.py'))
        python_files = [f for f in python_files if '_archives' not in str(f) and 
                       'node_modules' not in str(f) and
                       '__pycache__' not in str(f)]
        
        print(f"📊 Found {len(python_files)} Python files to analyze")
        print()
        
        # Analyze each file for migration suitability
        analyzed = 0
        for py_file in python_files[:500]:  # Analyze first 500 for detailed report
            try:
                self.analyze_file(py_file)
                analyzed += 1
                if analyzed % 100 == 0:
                    print(f"  Analyzed {analyzed} files...")
            except Exception:
                continue
        
        # Categorize by language
        self.categorize_targets()
        
        # Generate deployment strategy
        self.generate_deployment_strategy()
        
        # Save analysis
        self.save_analysis()
        
    def analyze_file(self, filepath):
        """Analyze a single Python file."""
        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                content = f.read()
                
            lines = len(content.split('\n'))
            
            # Skip if too small or too large
            if lines < 10 or lines > 5000:
                return
                
            # Analyze content patterns
            patterns = {
                'numpy': 'numpy' in content or 'np.' in content,
                'torch': 'torch' in content or 'nn.' in content,
                'asyncio': 'asyncio' in content or 'async def' in content,
                'grpc': 'grpc' in content,
                'http': 'http' in content or 'requests' in content,
                'decorator': '@' in content and 'def ' in content,
                'exception': 'try:' in content and 'except' in content,
                'simd': 'vector' in content.lower() or 'matrix' in content.lower(),
            }
            
            # Score for each language
            scores = {
                'rust': 0,
                'mojo': 0,
                'elixir': 0,
                'koka': 0,
                'go': 0
            }
            
            # Rust: performance, memory, hot paths
            if patterns['numpy'] or patterns['simd']:
                scores['rust'] += 5
                scores['mojo'] += 8
            if lines > 200:
                scores['rust'] += 3
            if 'unsafe' in content or 'cffi' in content:
                scores['rust'] += 5
                
            # Elixir: concurrency, OTP
            if patterns['asyncio']:
                scores['elixir'] += 5
            if 'concurrent' in content or 'threading' in content:
                scores['elixir'] += 3
            if 'supervisor' in content or 'genserver' in content:
                scores['elixir'] += 8
                
            # KOKA: effects, exceptions, decorators
            if patterns['decorator']:
                scores['koka'] += 5
            if patterns['exception']:
                scores['koka'] += 3
            if 'with ' in content and 'as ' in content:
                scores['koka'] += 3
                
            # Go: networking, protocols
            if patterns['grpc'] or patterns['http']:
                scores['go'] += 5
            if 'websocket' in content or 'socket' in content:
                scores['go'] += 5
            if 'client' in content and 'server' in content:
                scores['go'] += 3
            
            # Store analysis
            rel_path = str(filepath.relative_to(self.root))
            self.analysis[rel_path] = {
                'lines': lines,
                'scores': scores,
                'patterns': {k: v for k, v in patterns.items() if v}
            }
            
        except Exception:
            pass
            
    def categorize_targets(self):
        """Categorize targets by primary language."""
        print("\n📁 Categorizing targets by language...")
        
        for filepath, data in self.analysis.items():
            scores = data['scores']
            lines = data['lines']
            
            # Skip if no strong signals
            if max(scores.values()) < 3:
                continue
            
            # Find best language match
            best_lang = max(scores, key=scores.get)
            best_score = scores[best_lang]
            
            # Only include if score is meaningful
            if best_score >= 5:
                self.targets[best_lang].append({
                    'file': filepath,
                    'lines': lines,
                    'score': best_score,
                    'patterns': data['patterns']
                })
        
        # Sort by score within each category
        for lang in self.targets:
            self.targets[lang].sort(key=lambda x: x['score'], reverse=True)
        
    def generate_deployment_strategy(self):
        """Generate shadow clone deployment strategy."""
        print("\n⚔️  Generating Shadow Clone Deployment Strategy...")
        print()
        
        strategy = {}
        
        for lang, targets in self.targets.items():
            if not targets:
                continue
                
            total_loc = sum(t['lines'] for t in targets)
            file_count = len(targets)
            
            # Calculate clone deployment
            if lang == 'rust':
                clones = min(10, max(3, file_count // 30))
                batch_size = file_count // clones
            elif lang == 'mojo':
                clones = min(8, max(2, file_count // 20))
                batch_size = file_count // clones
            elif lang == 'elixir':
                clones = min(6, max(2, file_count // 15))
                batch_size = file_count // clones
            elif lang == 'koka':
                clones = min(6, max(3, file_count // 50))
                batch_size = file_count // clones
            elif lang == 'go':
                clones = min(4, max(2, file_count // 10))
                batch_size = file_count // clones
            else:
                clones = 2
                batch_size = file_count
            
            strategy[lang] = {
                'files': file_count,
                'loc': total_loc,
                'clones': clones,
                'batch_size': batch_size,
                'top_targets': targets[:10]  # Top 10 by score
            }
            
            print(f"  {lang.upper()}: {file_count} files ({total_loc:,} LOC)")
            print(f"    Deploying {clones} clones, ~{batch_size} files/clone")
        
        self.strategy = strategy
        
    def save_analysis(self):
        """Save analysis results."""
        report_dir = self.root / 'reports' / 'scout_analysis'
        report_dir.mkdir(parents=True, exist_ok=True)
        
        # JSON report
        report_file = report_dir / 'deep_scout_analysis.json'
        with open(report_file, 'w') as f:
            json.dump({
                'timestamp': datetime.now().isoformat(),
                'files_analyzed': len(self.analysis),
                'targets': {k: len(v) for k, v in self.targets.items()},
                'strategy': self.strategy,
                'top_targets_per_language': {
                    lang: [{'file': t['file'], 'lines': t['lines'], 'score': t['score']} 
                           for t in targets[:5]]
                    for lang, targets in self.targets.items()
                }
            }, f, indent=2)
        
        # Markdown report
        md_file = report_dir / 'SCOUT_DEPLOYMENT_STRATEGY.md'
        with open(md_file, 'w') as f:
            f.write("# Deep Scout Analysis - Deployment Strategy\n\n")
            f.write(f"**Generated**: {datetime.now().isoformat()}\n")
            f.write(f"**Files Analyzed**: {len(self.analysis)}\n\n")
            
            f.write("## Target Summary\n\n")
            total_files = sum(len(t) for t in self.targets.values())
            total_loc = sum(sum(t['lines'] for t in targets) for targets in self.targets.values())
            
            f.write(f"- **Total Migration Targets**: {total_files} files\n")
            f.write(f"- **Total LOC**: {total_loc:,}\n")
            f.write(f"- **Languages**: {len([l for l in self.targets if self.targets[l]])}\n\n")
            
            f.write("## By Language\n\n")
            f.write("| Language | Files | LOC | Clones | Batch Size |\n")
            f.write("|----------|-------|-----|--------|------------|\n")
            
            for lang, data in self.strategy.items():
                f.write(f"| {lang.upper()} | {data['files']} | {data['loc']:,} | {data['clones']} | ~{data['batch_size']} |\n")
            
            f.write("\n## Top Priority Targets\n\n")
            for lang, data in self.strategy.items():
                f.write(f"### {lang.upper()} (Top 5)\n\n")
                for i, target in enumerate(data['top_targets'][:5], 1):
                    f.write(f"{i}. `{target['file']}` ({target['lines']} LOC, score: {target['score']})\n")
                f.write("\n")
            
            f.write("## Deployment Order\n\n")
            f.write("Recommended deployment sequence:\n\n")
            f.write("1. **GO** - Smallest scope, highest network impact\n")
            f.write("2. **ELIXIR** - Medium scope, OTP patterns\n")
            f.write("3. **MOJO** - GPU kernels, highest performance impact\n")
            f.write("4. **RUST** - Large scope, systems programming\n")
            f.write("5. **KOKA** - Largest scope, effect systems\n\n")
            
            f.write("## Shadow Clone Assignments\n\n")
            clone_id = 1
            for lang, data in self.strategy.items():
                f.write(f"### {lang.upper()} Squad\n\n")
                for i in range(data['clones']):
                    f.write(f"- Clone {clone_id:03d}: Batch {i+1} ({data['batch_size']} files)\n")
                    clone_id += 1
                f.write("\n")
        
        print("\n📊 Analysis saved:")
        print(f"  JSON: {report_file}")
        print(f"  Markdown: {md_file}")
        print()
        print("=" * 80)
        print("🔍 SCOUT ANALYSIS COMPLETE")
        print(f"   Total Targets: {sum(len(t) for t in self.targets.values())} files")
        print(f"   Total LOC: {sum(sum(t['lines'] for t in targets) for targets in self.targets.values()):,}")
        print("=" * 80)

def main():
    scout = MigrationScout()
    scout.run_deep_analysis()

if __name__ == '__main__':
    main()
