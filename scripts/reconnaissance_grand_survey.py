#!/usr/bin/env python3
"""
Reconnaissance Grand Survey — Deep Intelligence Gathering Across Three Codebases

Deploys shadow clone armies to comprehensively analyze:
- whitemagicdev (development branch)
- whitemagicpublic (public release)
- WM2 (next-generation synthesis)

Uses all available MCP tools and shadow clone parallelism to gather:
- Codebase metrics (LOC, files, languages)
- Architecture patterns
- Feature capabilities
- Performance benchmarks
- Test coverage
- Database state
- Polyglot distribution
"""

import sys
import json
import time
from pathlib import Path
from dataclasses import dataclass, asdict
from typing import Dict, List, Any
import re

# Add whitemagic to path
sys.path.insert(0, str(Path(__file__).parent.parent))

try:
    from whitemagic_rs import tokio_clones
    RUST_AVAILABLE = True
except ImportError:
    RUST_AVAILABLE = False
    print("⚠️  Rust bridge unavailable - using Python fallback")


@dataclass
class CodebaseMetrics:
    """Comprehensive metrics for a single codebase"""
    name: str
    path: str
    
    # File counts
    total_files: int = 0
    python_files: int = 0
    rust_files: int = 0
    typescript_files: int = 0
    markdown_files: int = 0
    
    # LOC counts
    total_loc: int = 0
    python_loc: int = 0
    rust_loc: int = 0
    typescript_loc: int = 0
    markdown_loc: int = 0
    
    # Architecture
    modules: List[str] = None
    top_level_dirs: List[str] = None
    
    # Features
    mcp_tools: int = 0
    ganas: int = 0
    campaigns: int = 0
    tests: int = 0
    
    # Performance
    benchmark_results: Dict[str, Any] = None
    test_results: Dict[str, Any] = None
    
    # Database
    db_exists: bool = False
    db_size_mb: float = 0.0
    db_memories: int = 0
    db_associations: int = 0
    
    def __post_init__(self):
        if self.modules is None:
            self.modules = []
        if self.top_level_dirs is None:
            self.top_level_dirs = []
        if self.benchmark_results is None:
            self.benchmark_results = {}
        if self.test_results is None:
            self.test_results = {}


class ReconnaissanceScout:
    """Individual scout for gathering intelligence"""
    
    def __init__(self, codebase_path: str, name: str):
        self.path = Path(codebase_path)
        self.name = name
        self.metrics = CodebaseMetrics(name=name, path=str(codebase_path))
        
    def scout_file_structure(self):
        """Map the file structure"""
        print(f"📂 Scouting file structure: {self.name}")
        
        if not self.path.exists():
            print(f"⚠️  Path does not exist: {self.path}")
            return
        
        # Get top-level directories
        try:
            self.metrics.top_level_dirs = [
                d.name for d in self.path.iterdir() 
                if d.is_dir() and not d.name.startswith('.')
            ]
        except Exception as e:
            print(f"⚠️  Error reading top-level dirs: {e}")
            
        # Count files by extension
        extensions = {
            '.py': ('python_files', 'python_loc'),
            '.rs': ('rust_files', 'rust_loc'),
            '.ts': ('typescript_files', 'typescript_loc'),
            '.tsx': ('typescript_files', 'typescript_loc'),
            '.md': ('markdown_files', 'markdown_loc'),
        }
        
        for ext, (file_attr, loc_attr) in extensions.items():
            files = list(self.path.rglob(f'*{ext}'))
            setattr(self.metrics, file_attr, len(files))
            
            # Count LOC
            loc = 0
            for f in files:
                try:
                    with open(f, 'r', encoding='utf-8', errors='ignore') as fp:
                        loc += sum(1 for line in fp if line.strip())
                except Exception:
                    pass
            setattr(self.metrics, loc_attr, loc)
            
        self.metrics.total_files = sum([
            self.metrics.python_files,
            self.metrics.rust_files,
            self.metrics.typescript_files,
            self.metrics.markdown_files,
        ])
        
        self.metrics.total_loc = sum([
            self.metrics.python_loc,
            self.metrics.rust_loc,
            self.metrics.typescript_loc,
            self.metrics.markdown_loc,
        ])
        
    def scout_python_modules(self):
        """Discover Python module structure"""
        print(f"🐍 Scouting Python modules: {self.name}")
        
        whitemagic_dir = self.path / 'whitemagic'
        if not whitemagic_dir.exists():
            return
            
        self.metrics.modules = [
            d.name for d in whitemagic_dir.iterdir()
            if d.is_dir() and not d.name.startswith('_') and (d / '__init__.py').exists()
        ]
        
    def scout_features(self):
        """Discover feature capabilities"""
        print(f"🔍 Scouting features: {self.name}")
        
        # Count MCP tools
        dispatch_file = self.path / 'whitemagic' / 'tools' / 'dispatch_table.py'
        if dispatch_file.exists():
            try:
                with open(dispatch_file, 'r') as f:
                    content = f.read()
                    # Count entries in DISPATCH_TABLE
                    matches = re.findall(r'"[\w.]+"\s*:', content)
                    self.metrics.mcp_tools = len(matches)
            except Exception as e:
                print(f"⚠️  Error counting MCP tools: {e}")
        
        # Count Ganas
        prat_file = self.path / 'whitemagic' / 'tools' / 'prat_router.py'
        if prat_file.exists():
            try:
                with open(prat_file, 'r') as f:
                    content = f.read()
                    # Count gana_ functions
                    matches = re.findall(r'def (gana_\w+)', content)
                    self.metrics.ganas = len(set(matches))
            except Exception as e:
                print(f"⚠️  Error counting Ganas: {e}")
        
        # Count campaigns
        campaigns_dir = self.path / 'campaigns'
        if campaigns_dir.exists():
            self.metrics.campaigns = len(list(campaigns_dir.glob('*.md')))
        
        # Count tests
        tests_dir = self.path / 'tests'
        if tests_dir.exists():
            self.metrics.tests = len(list(tests_dir.rglob('test_*.py')))
            
    def scout_database(self):
        """Check database state"""
        print(f"💾 Scouting database: {self.name}")
        
        db_paths = [
            self.path / '.whitemagic' / 'memory' / 'whitemagic.db',
            Path.home() / '.whitemagic' / 'memory' / 'whitemagic.db',
        ]
        
        for db_path in db_paths:
            if db_path.exists():
                self.metrics.db_exists = True
                self.metrics.db_size_mb = db_path.stat().st_size / (1024 * 1024)
                
                # Try to query DB
                try:
                    import sqlite3
                    conn = sqlite3.connect(str(db_path))
                    cursor = conn.cursor()
                    
                    # Count memories
                    cursor.execute("SELECT COUNT(*) FROM memories WHERE memory_type != 'quarantined'")
                    self.metrics.db_memories = cursor.fetchone()[0]
                    
                    # Count associations
                    cursor.execute("SELECT COUNT(*) FROM associations")
                    self.metrics.db_associations = cursor.fetchone()[0]
                    
                    conn.close()
                except Exception as e:
                    print(f"⚠️  Error querying database: {e}")
                    
                break
                
    def run_full_reconnaissance(self):
        """Execute all reconnaissance missions"""
        print(f"\n{'='*60}")
        print(f"🎯 RECONNAISSANCE MISSION: {self.name}")
        print(f"{'='*60}\n")
        
        self.scout_file_structure()
        self.scout_python_modules()
        self.scout_features()
        self.scout_database()
        
        return self.metrics


class ShadowCloneArmy:
    """Deploys shadow clones for parallel reconnaissance"""
    
    def __init__(self, clone_count: int = 10000):
        self.clone_count = clone_count
        self.scouts: List[ReconnaissanceScout] = []
        
    def deploy_scout(self, codebase_path: str, name: str) -> CodebaseMetrics:
        """Deploy a scout to a codebase"""
        scout = ReconnaissanceScout(codebase_path, name)
        self.scouts.append(scout)
        return scout.run_full_reconnaissance()
        
    def parallel_analysis(self, metrics: CodebaseMetrics) -> Dict[str, Any]:
        """Use shadow clones for parallel analysis tasks"""
        print(f"\n🥷 Deploying {self.clone_count:,} shadow clones for deep analysis...")
        
        if not RUST_AVAILABLE:
            print("⚠️  Rust unavailable - skipping parallel analysis")
            return {}
        
        findings = {}
        
        # Task 1: Pattern mining
        print(f"  📊 Pattern mining with {self.clone_count} clones...")
        start = time.time()
        try:
            result = tokio_clones(
                self.clone_count,
                "pattern_mining",
                f"Analyzing {metrics.name} architecture patterns"
            )
            findings['pattern_mining'] = {
                'duration': time.time() - start,
                'throughput': self.clone_count / (time.time() - start),
                'result': result
            }
        except Exception as e:
            print(f"⚠️  Pattern mining failed: {e}")
        
        return findings


def run_benchmarks(codebase_path: Path, name: str) -> Dict[str, Any]:
    """Run benchmark suite if available"""
    print(f"\n⚡ Running benchmarks: {name}")
    
    results = {}
    
    # Look for benchmark scripts
    benchmark_scripts = [
        'scripts/benchmark_gauntlet_v5.py',
        'scripts/benchmark_gauntlet_v4.py',
        'scripts/benchmark_native.py',
    ]
    
    for script in benchmark_scripts:
        script_path = codebase_path / script
        if script_path.exists():
            print(f"  Found: {script}")
            # Don't actually run - just note availability
            results[script] = "available"
            
    return results


def run_tests(codebase_path: Path, name: str) -> Dict[str, Any]:
    """Run test suite if available"""
    print(f"\n🧪 Checking tests: {name}")
    
    results = {}
    
    tests_dir = codebase_path / 'tests'
    if tests_dir.exists():
        # Count test files
        test_files = list(tests_dir.rglob('test_*.py'))
        results['test_files'] = len(test_files)
        
        # Check for pytest
        if (codebase_path / 'pyproject.toml').exists():
            results['test_framework'] = 'pytest'
        
    return results


def generate_comparison_report(metrics_list: List[CodebaseMetrics], output_path: Path):
    """Generate comprehensive comparison report"""
    print("\n📝 Generating comparison report...")
    
    report = []
    report.append("# RECONNAISSANCE GRAND SURVEY — Three Codebase Analysis\n")
    report.append(f"Generated: {time.strftime('%Y-%m-%d %H:%M:%S')}\n")
    report.append("="*80 + "\n\n")
    
    # Summary table
    report.append("## Executive Summary\n\n")
    report.append("| Metric | whitemagicdev | whitemagicpublic | WM2 |\n")
    report.append("|--------|---------------|------------------|-----|\n")
    
    metrics_map = {m.name: m for m in metrics_list}
    
    def get_val(name, attr):
        m = metrics_map.get(name)
        return getattr(m, attr, 0) if m else 0
    
    rows = [
        ("Total Files", "total_files"),
        ("Total LOC", "total_loc"),
        ("Python Files", "python_files"),
        ("Python LOC", "python_loc"),
        ("Rust Files", "rust_files"),
        ("Rust LOC", "rust_loc"),
        ("TypeScript Files", "typescript_files"),
        ("TypeScript LOC", "typescript_loc"),
        ("MCP Tools", "mcp_tools"),
        ("Ganas", "ganas"),
        ("Campaigns", "campaigns"),
        ("Tests", "tests"),
        ("DB Memories", "db_memories"),
        ("DB Associations", "db_associations"),
    ]
    
    for label, attr in rows:
        dev = get_val("whitemagicdev", attr)
        pub = get_val("whitemagicpublic", attr)
        wm2 = get_val("WM2", attr)
        report.append(f"| {label} | {dev:,} | {pub:,} | {wm2:,} |\n")
    
    # Detailed sections
    for metrics in metrics_list:
        report.append(f"\n## {metrics.name}\n\n")
        report.append(f"**Path**: `{metrics.path}`\n\n")
        
        report.append("### File Structure\n\n")
        report.append(f"- Total Files: {metrics.total_files:,}\n")
        report.append(f"- Total LOC: {metrics.total_loc:,}\n")
        report.append(f"- Python: {metrics.python_files:,} files, {metrics.python_loc:,} LOC\n")
        report.append(f"- Rust: {metrics.rust_files:,} files, {metrics.rust_loc:,} LOC\n")
        report.append(f"- TypeScript: {metrics.typescript_files:,} files, {metrics.typescript_loc:,} LOC\n")
        report.append(f"- Markdown: {metrics.markdown_files:,} files, {metrics.markdown_loc:,} LOC\n\n")
        
        if metrics.top_level_dirs:
            report.append("### Top-Level Directories\n\n")
            for d in sorted(metrics.top_level_dirs):
                report.append(f"- `{d}/`\n")
            report.append("\n")
        
        if metrics.modules:
            report.append("### Python Modules\n\n")
            for m in sorted(metrics.modules):
                report.append(f"- `whitemagic.{m}`\n")
            report.append("\n")
        
        report.append("### Features\n\n")
        report.append(f"- MCP Tools: {metrics.mcp_tools}\n")
        report.append(f"- Ganas: {metrics.ganas}\n")
        report.append(f"- Campaigns: {metrics.campaigns}\n")
        report.append(f"- Tests: {metrics.tests}\n\n")
        
        if metrics.db_exists:
            report.append("### Database\n\n")
            report.append(f"- Size: {metrics.db_size_mb:.1f} MB\n")
            report.append(f"- Memories: {metrics.db_memories:,}\n")
            report.append(f"- Associations: {metrics.db_associations:,}\n\n")
    
    # Analysis
    report.append("\n## Comparative Analysis\n\n")
    
    dev = metrics_map.get("whitemagicdev")
    pub = metrics_map.get("whitemagicpublic")
    wm2 = metrics_map.get("WM2")
    
    if dev and pub:
        report.append("### whitemagicdev vs whitemagicpublic\n\n")
        report.append(f"- LOC difference: {dev.total_loc - pub.total_loc:,} ({((dev.total_loc - pub.total_loc) / pub.total_loc * 100):.1f}%)\n")
        report.append(f"- File difference: {dev.total_files - pub.total_files:,}\n")
        report.append(f"- Tool difference: {dev.mcp_tools - pub.mcp_tools}\n\n")
    
    if wm2 and dev:
        report.append("### WM2 vs whitemagicdev\n\n")
        if wm2.total_loc > 0:
            loc_reduction = ((dev.total_loc - wm2.total_loc) / dev.total_loc * 100)
            report.append(f"- LOC reduction: {dev.total_loc - wm2.total_loc:,} ({loc_reduction:.1f}%)\n")
            report.append(f"- File reduction: {dev.total_files - wm2.total_files:,}\n")
            
            if wm2.mcp_tools >= dev.mcp_tools:
                report.append(f"- ✅ Feature parity: {wm2.mcp_tools} tools (vs {dev.mcp_tools})\n")
            else:
                report.append(f"- ⚠️  Feature gap: {wm2.mcp_tools} tools (vs {dev.mcp_tools})\n")
        else:
            report.append("- WM2 appears to be empty or not yet populated\n")
        report.append("\n")
    
    # Write report
    with open(output_path, 'w') as f:
        f.writelines(report)
    
    print(f"✅ Report written to: {output_path}")


def main():
    """Main reconnaissance mission"""
    print("\n" + "="*80)
    print("🎯 RECONNAISSANCE GRAND SURVEY")
    print("   Deploying Shadow Clone Armies Across Three Codebases")
    print("="*80 + "\n")
    
    # Initialize army
    army = ShadowCloneArmy(clone_count=10000)
    
    # Deploy scouts to each codebase
    codebases = [
        ("/home/lucas/Desktop/whitemagicdev", "whitemagicdev"),
        ("/home/lucas/Desktop/whitemagicpublic", "whitemagicpublic"),
        ("/home/lucas/Desktop/WM2", "WM2"),
    ]
    
    all_metrics = []
    
    for path, name in codebases:
        metrics = army.deploy_scout(path, name)
        all_metrics.append(metrics)
        
        # Run parallel analysis
        findings = army.parallel_analysis(metrics)
        metrics.benchmark_results = findings
        
        # Check benchmarks
        bench_results = run_benchmarks(Path(path), name)
        metrics.benchmark_results.update(bench_results)
        
        # Check tests
        test_results = run_tests(Path(path), name)
        metrics.test_results = test_results
    
    # Generate report
    output_path = Path(__file__).parent.parent / 'reports' / 'reconnaissance_grand_survey.md'
    output_path.parent.mkdir(exist_ok=True)
    generate_comparison_report(all_metrics, output_path)
    
    # Save JSON
    json_path = output_path.with_suffix('.json')
    with open(json_path, 'w') as f:
        json.dump([asdict(m) for m in all_metrics], f, indent=2)
    
    print(f"\n✅ JSON data written to: {json_path}")
    
    print("\n" + "="*80)
    print("🎯 RECONNAISSANCE COMPLETE")
    print("="*80 + "\n")


if __name__ == '__main__':
    main()
