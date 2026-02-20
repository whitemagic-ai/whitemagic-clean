"""Polyglot Scout - Analyzes Python files for polyglot translation opportunities

Deploys 500K+ Unified Zodiac Army scouts to analyze every Python file,
identify hot paths, assess migration complexity, and tag files for
Rust/Zig/Mojo/Koka translation.
"""
from __future__ import annotations

import ast
import re
import json
from pathlib import Path
from dataclasses import dataclass, asdict
from collections import defaultdict
import hashlib


@dataclass
class PolyglotTag:
    """Tag metadata for a Python file"""
    file_path: str
    hot_path_score: float
    target_language: str
    secondary_language: str | None
    migration_complexity: int  # 1-5
    performance_impact: int  # 1-5
    priority: str  # P0-P4
    estimated_speedup: str
    dedup_candidates: list[str]
    synthesis_opportunity: bool
    dependencies: list[str]
    migration_order: int
    notes: str
    
    # Detailed metrics
    lines_of_code: int
    function_count: int
    class_count: int
    loop_count: int
    numpy_ops: int
    io_ops: int
    inference_calls: int
    db_queries: int
    network_requests: int
    
    def to_comment(self) -> str:
        """Generate inline comment tag"""
        data = {
            'hot_path_score': self.hot_path_score,
            'target_language': self.target_language,
            'secondary_language': self.secondary_language,
            'migration_complexity': self.migration_complexity,
            'performance_impact': self.performance_impact,
            'priority': self.priority,
            'estimated_speedup': self.estimated_speedup,
            'dedup_candidates': self.dedup_candidates,
            'synthesis_opportunity': self.synthesis_opportunity,
            'dependencies': self.dependencies,
            'migration_order': self.migration_order,
            'notes': self.notes
        }
        return f"# POLYGLOT_TAGS: {json.dumps(data, indent=2)}\n"


class PolyglotScout:
    """Analyzes Python files for polyglot translation"""
    
    # Hot path patterns
    HOT_PATTERNS = {
        'numpy_ops': (r'np\.|numpy\.', 0.8),
        'loop_range': (r'for\s+\w+\s+in\s+range\(', 0.7),
        'loop_enumerate': (r'for\s+\w+\s*,\s*\w+\s+in\s+enumerate\(', 0.6),
        'search_func': (r'def\s+\w*search\w*\(', 0.8),
        'file_write': (r'\.write\(|open\(.*[\'"]w', 0.5),
        'inference': (r'def\s+\w*infer\w*\(|def\s+\w*complete\w*\(', 0.9),
        'file_read': (r'\.read\(|open\(.*[\'"]r', 0.5),
        'embedding': (r'def\s+\w*embed\w*\(|embedding', 0.9),
        'infinite_loop': (r'while\s+True:', 0.8),
        'http_route': (r'@app\.|@router\.', 0.6),
        'json_serialize': (r'json\.dumps\(', 0.7),
        'json_parse': (r'json\.loads\(', 0.7),
        'db_query': (r'execute\(|cursor\.|SELECT|INSERT|UPDATE', 0.7),
        'async_await': (r'async\s+def|await\s+', 0.6),
        'list_comp_heavy': (r'\[.*for.*for.*\]', 0.6),
    }
    
    def __init__(self):
        self.analyzed_files: dict[str, PolyglotTag] = {}
        self.dedup_clusters: dict[str, list[str]] = defaultdict(list[str])
    
    def analyze_file(self, file_path: Path) -> PolyglotTag | None:
        """Analyze a single Python file"""
        try:
            content = file_path.read_text()
            
            # Parse AST
            try:
                tree = ast.parse(content)
            except SyntaxError:
                return None
            
            # Calculate metrics
            metrics = self._calculate_metrics(content, tree)
            
            # Calculate hot path score
            hot_path_score = self._calculate_hot_path_score(content, metrics)
            
            # Determine target language
            target_lang, secondary_lang = self._determine_target_language(metrics, hot_path_score)
            
            # Assess complexity
            complexity = self._assess_migration_complexity(tree, metrics)
            
            # Assess performance impact
            perf_impact = self._assess_performance_impact(hot_path_score, metrics)
            
            # Calculate priority
            priority = self._calculate_priority(complexity, perf_impact, hot_path_score)
            
            # Estimate speedup
            speedup = self._estimate_speedup(target_lang, hot_path_score, metrics)
            
            # Extract dependencies
            deps = self._extract_dependencies(tree)
            
            # Generate notes
            notes = self._generate_notes(metrics, hot_path_score)
            
            # Calculate content hash for dedup
            content_hash = hashlib.sha256(content.encode()).hexdigest()[:16]
            self.dedup_clusters[content_hash].append(str(file_path))
            
            tag = PolyglotTag(
                file_path=str(file_path),
                hot_path_score=hot_path_score,
                target_language=target_lang,
                secondary_language=secondary_lang,
                migration_complexity=complexity,
                performance_impact=perf_impact,
                priority=priority,
                estimated_speedup=speedup,
                dedup_candidates=[],  # Will be filled later
                synthesis_opportunity=False,  # Will be determined later
                dependencies=deps,
                migration_order=0,  # Will be calculated later
                notes=notes,
                lines_of_code=metrics['loc'],
                function_count=metrics['function_count'],
                class_count=metrics['class_count'],
                loop_count=metrics['loop_count'],
                numpy_ops=metrics['numpy_ops'],
                io_ops=metrics['io_ops'],
                inference_calls=metrics['inference_calls'],
                db_queries=metrics['db_queries'],
                network_requests=metrics['network_requests']
            )
            
            return tag
            
        except Exception as e:
            print(f"Error analyzing {file_path}: {e}")
            return None
    
    def _calculate_metrics(self, content: str, tree: ast.AST) -> dict:
        """Calculate file metrics"""
        metrics = {
            'loc': len(content.splitlines()),
            'function_count': 0,
            'class_count': 0,
            'loop_count': 0,
            'numpy_ops': 0,
            'io_ops': 0,
            'inference_calls': 0,
            'db_queries': 0,
            'network_requests': 0,
        }
        
        # AST-based metrics
        for node in ast.walk(tree):
            if isinstance(node, ast.FunctionDef):
                metrics['function_count'] += 1
            elif isinstance(node, ast.ClassDef):
                metrics['class_count'] += 1
            elif isinstance(node, (ast.For, ast.While)):
                metrics['loop_count'] += 1
        
        # Pattern-based metrics
        for pattern_name, (pattern, _) in self.HOT_PATTERNS.items():
            count = len(re.findall(pattern, content, re.IGNORECASE))
            if 'numpy' in pattern_name:
                metrics['numpy_ops'] += count
            elif 'file' in pattern_name:
                metrics['io_ops'] += count
            elif 'infer' in pattern_name or 'embed' in pattern_name:
                metrics['inference_calls'] += count
            elif 'db' in pattern_name or 'SELECT' in pattern:
                metrics['db_queries'] += count
            elif 'http' in pattern_name or 'request' in pattern_name:
                metrics['network_requests'] += count
        
        return metrics
    
    def _calculate_hot_path_score(self, content: str, metrics: dict) -> float:
        """Calculate hot path score (0.0-1.0)"""
        score = 0.0
        total_weight = 0.0
        
        # Pattern-based scoring
        for pattern_name, (pattern, weight) in self.HOT_PATTERNS.items():
            count = len(re.findall(pattern, content, re.IGNORECASE))
            if count > 0:
                score += weight * min(count / 10.0, 1.0)  # Cap at 10 occurrences
                total_weight += weight
        
        # Normalize
        if total_weight > 0:
            score = score / total_weight
        
        # Boost for high loop count
        if metrics['loop_count'] > 5:
            score = min(1.0, score * 1.2)
        
        # Boost for inference/embedding
        if metrics['inference_calls'] > 0:
            score = min(1.0, score * 1.3)
        
        return round(score, 2)
    
    def _determine_target_language(self, metrics: dict, hot_path_score: float) -> tuple[str, str | None]:
        """Determine target language(s) for migration"""
        
        # Mojo for ML/inference
        if metrics['inference_calls'] > 0 or metrics['numpy_ops'] > 5:
            return 'mojo', 'rust'
        
        # Zig for ultra-hot paths
        if hot_path_score > 0.85:
            return 'zig', 'rust'
        
        # Rust for systems/concurrency
        if metrics['db_queries'] > 0 or metrics['io_ops'] > 3:
            return 'rust', 'zig'
        
        # Koka for coordination (low hot path, many functions)
        if hot_path_score < 0.3 and metrics['function_count'] > 10:
            return 'koka', None
        
        # Default to Rust
        return 'rust', None
    
    def _assess_migration_complexity(self, tree: ast.AST, metrics: dict) -> int:
        """Assess migration complexity (1-5)"""
        complexity = 1
        
        # More functions = more complex
        if metrics['function_count'] > 20:
            complexity += 2
        elif metrics['function_count'] > 10:
            complexity += 1
        
        # Classes add complexity
        if metrics['class_count'] > 5:
            complexity += 1
        elif metrics['class_count'] > 0:
            complexity += 1
        
        # Many dependencies = complex
        imports = sum(1 for node in ast.walk(tree) if isinstance(node, (ast.Import, ast.ImportFrom)))
        if imports > 15:
            complexity += 1
        elif imports > 8:
            complexity += 1
        
        return min(5, int(complexity))
    
    def _assess_performance_impact(self, hot_path_score: float, metrics: dict) -> int:
        """Assess performance impact (1-5)"""
        if hot_path_score > 0.9 or metrics['inference_calls'] > 0:
            return 5  # Critical
        elif hot_path_score > 0.7:
            return 4  # High
        elif hot_path_score > 0.5:
            return 3  # Medium
        elif hot_path_score > 0.3:
            return 2  # Low
        else:
            return 1  # Minimal
    
    def _calculate_priority(self, complexity: int, perf_impact: int, hot_path_score: float) -> str:
        """Calculate migration priority"""
        # P0: High impact, low complexity
        if perf_impact >= 4 and complexity <= 2:
            return 'P0'
        
        # P1: High impact, medium complexity OR very high impact
        if (perf_impact >= 4 and complexity <= 3) or perf_impact == 5:
            return 'P1'
        
        # P2: Medium-high impact
        if perf_impact >= 3:
            return 'P2'
        
        # P3: Low-medium impact
        if perf_impact >= 2:
            return 'P3'
        
        # P4: Minimal impact
        return 'P4'
    
    def _estimate_speedup(self, target_lang: str, hot_path_score: float, metrics: dict) -> str:
        """Estimate speedup range"""
        if target_lang == 'mojo' and metrics['inference_calls'] > 0:
            return '50-100x'
        elif target_lang == 'zig' and hot_path_score > 0.85:
            return '100-1000x'
        elif target_lang == 'rust' and hot_path_score > 0.7:
            return '20-50x'
        elif target_lang == 'rust' and hot_path_score > 0.5:
            return '10-20x'
        elif hot_path_score > 0.3:
            return '5-10x'
        else:
            return '2-5x'
    
    def _extract_dependencies(self, tree: ast.AST) -> list[str]:
        """Extract import dependencies"""
        deps: set[str] = set()
        for node in ast.walk(tree):
            if isinstance(node, ast.Import):
                for alias in node.names:
                    deps.add(alias.name.split('.')[0])
            elif isinstance(node, ast.ImportFrom):
                if node.module:
                    deps.add(node.module.split('.')[0])
        return sorted(list(deps))
    
    def _generate_notes(self, metrics: dict, hot_path_score: float) -> str:
        """Generate migration notes"""
        notes = []
        
        if metrics['inference_calls'] > 0:
            notes.append('LLM inference hot path')
        if metrics['numpy_ops'] > 5:
            notes.append('Heavy NumPy operations')
        if metrics['db_queries'] > 3:
            notes.append('Database-intensive')
        if metrics['loop_count'] > 10:
            notes.append('Many loops')
        if hot_path_score > 0.8:
            notes.append('Critical hot path')
        
        return '; '.join(notes) if notes else 'Standard migration'
    
    def find_dedup_opportunities(self) -> dict[str, list[str]]:
        """Find deduplication opportunities"""
        opportunities = {}
        
        for content_hash, files in self.dedup_clusters.items():
            if len(files) > 1:
                opportunities[content_hash] = files
        
        return opportunities
    
    def calculate_migration_order(self, tags: list[PolyglotTag]) -> list[PolyglotTag]:
        """Calculate migration order based on dependencies"""
        # Build dependency graph
        dep_graph: dict[str, list[str]] = {}
        for tag in tags:
            deps_in_project = [
                t.file_path for t in tags
                if any(dep in t.file_path for dep in tag.dependencies)
            ]
            dep_graph[tag.file_path] = deps_in_project
        
        # Topological sort (simplified)
        ordered = []
        visited = set()
        
        def visit(file_path):
            if file_path in visited:
                return
            visited.add(file_path)
            for dep in dep_graph.get(file_path, []):
                visit(dep)
            ordered.append(file_path)
        
        for tag in tags:
            visit(tag.file_path)
        
        # Assign migration order
        order_map = {path: i for i, path in enumerate(ordered)}
        for tag in tags:
            tag.migration_order = order_map.get(tag.file_path, 999)
        
        return sorted(tags, key=lambda t: t.migration_order)


class PolyglotScoutCommander:
    """Manages massive-scale scout deployment"""
    
    def __init__(self, root_dir: Path) -> None:
        self.root_dir = root_dir
        self.scout = PolyglotScout()
        self.results: dict[str, PolyglotTag] = {}
    
    def deploy_scouts(self, target_dirs: list[str], max_files: int | None = None) -> dict:
        """Deploy scouts to analyze Python files"""
        print(f"Deploying Polyglot Scouts across {len(target_dirs)} directories...")
        
        # Find all Python files
        python_files: list[Path] = []
        for target_dir in target_dirs:
            dir_path = self.root_dir / target_dir
            if dir_path.exists():
                python_files.extend(dir_path.rglob('*.py'))
        
        if max_files:
            python_files = python_files[:max_files]
        
        print(f"Found {len(python_files)} Python files to analyze")
        
        # Analyze each file
        tags = []
        for i, file_path in enumerate(python_files, 1):
            if i % 100 == 0:
                print(f"  Analyzed {i}/{len(python_files)} files...")
            
            tag = self.scout.analyze_file(file_path)
            if tag:
                tags.append(tag)
                self.results[str(file_path)] = tag
        
        print(f"Analysis complete: {len(tags)} files tagged")
        
        # Find dedup opportunities
        dedup_opps = self.scout.find_dedup_opportunities()
        print(f"Found {len(dedup_opps)} deduplication clusters")
        
        # Update dedup candidates
        for content_hash, files in dedup_opps.items():
            for file_path in files:
                if file_path in self.results:
                    self.results[file_path].dedup_candidates = [
                        f for f in files if f != file_path
                    ]
                    self.results[file_path].synthesis_opportunity = len(files) > 2
        
        # Calculate migration order
        tags = self.scout.calculate_migration_order(tags)
        
        # Generate summary
        summary = self._generate_summary(tags, dedup_opps)
        
        return summary
    
    def _generate_summary(self, tags: list[PolyglotTag], dedup_opps: dict) -> dict:
        """Generate campaign summary"""
        by_priority: dict[str, list[PolyglotTag]] = defaultdict(list)
        by_language: dict[str, list[PolyglotTag]] = defaultdict(list)
        
        for tag in tags:
            by_priority[tag.priority].append(tag)
            by_language[tag.target_language].append(tag)
        
        return {
            'total_files_analyzed': len(tags),
            'total_lines_analyzed': sum(t.lines_of_code for t in tags),
            'by_priority': {
                p: {
                    'count': len(files),
                    'total_loc': sum(t.lines_of_code for t in files),
                    'avg_hot_path_score': sum(t.hot_path_score for t in files) / len(files) if files else 0,
                    'files': [asdict(t) for t in sorted(files, key=lambda x: x.hot_path_score, reverse=True)[:10]]
                }
                for p, files in by_priority.items()
            },
            'by_target_language': {
                lang: {
                    'count': len(files),
                    'total_loc': sum(t.lines_of_code for t in files),
                    'avg_complexity': sum(t.migration_complexity for t in files) / len(files) if files else 0,
                    'files': [t.file_path for t in files[:20]]
                }
                for lang, files in by_language.items()
            },
            'deduplication_opportunities': {
                'cluster_count': len(dedup_opps),
                'total_files': sum(len(files) for files in dedup_opps.values()),
                'clusters': [
                    {'files': files, 'count': len(files)}
                    for files in sorted(dedup_opps.values(), key=len, reverse=True)[:10]
                ]
            },
            'hot_paths': [
                {
                    'file': t.file_path,
                    'score': t.hot_path_score,
                    'target': t.target_language,
                    'speedup': t.estimated_speedup,
                    'notes': t.notes
                }
                for t in sorted(tags, key=lambda x: x.hot_path_score, reverse=True)[:50]
            ]
        }
    
    def save_results(self, output_dir: Path) -> None:
        """Save results to JSON and markdown"""
        output_dir.mkdir(parents=True, exist_ok=True)
        
        # Save JSON
        json_path = output_dir / 'polyglot_scouting_results.json'
        with open(json_path, 'w') as f:
            json.dump(
                {path: asdict(tag) for path, tag in self.results.items()},
                f,
                indent=2
            )
        
        print(f"Results saved to {json_path}")
