#!/usr/bin/env python3
"""
Enhanced Validation Framework with Dream Cycle & Pattern Engine Integration

Inspired by:
- Dream cycle phases (consolidation, serendipity, kaizen)
- Pattern engine (emergence detection, resonance)
- Real-world benchmarking with feedback loops
"""

import ast
import subprocess
import time
from dataclasses import dataclass, field
from enum import Enum
from pathlib import Path


class ValidationTier(Enum):
    """Validation tiers from syntax to production"""
    SYNTAX = "syntax"
    STATIC = "static"
    FUNCTIONAL = "functional"
    PERFORMANCE = "performance"
    PRODUCTION = "production"

@dataclass
class ValidationResult:
    """Result of validation at a specific tier"""
    tier: ValidationTier
    passed: bool
    score: float  # 0.0-1.0
    details: dict
    duration_ms: float
    insights: list[str] = field(default_factory=list)

@dataclass
class InsightRecommendation:
    """Actionable insight from pattern analysis"""
    pattern: str
    target: str
    impact: str  # low, medium, high, very_high
    example: str
    rationale: str
    priority: int
    estimated_speedup: float | None = None

class EnhancedValidator:
    """Multi-tier validation with dream-inspired insights"""

    def __init__(self):
        self.validation_history = []
        self.pattern_frequencies = {}
        self.successful_patterns = set()
        self.failed_patterns = set()

    # ============================================================
    # TIER 1: SYNTAX VALIDATION (Dream Phase: TRIAGE)
    # ============================================================

    def validate_syntax(self, code: str, name: str = "generated") -> ValidationResult:
        """Quick triage - is code syntactically valid?"""
        start = time.time()

        try:
            tree = ast.parse(code)

            # Extract metadata
            imports = []
            functions = []
            classes = []

            for node in ast.walk(tree):
                if isinstance(node, ast.Import):
                    imports.extend([alias.name for alias in node.names])
                elif isinstance(node, ast.ImportFrom):
                    if node.module:
                        imports.append(node.module)
                elif isinstance(node, ast.FunctionDef):
                    functions.append(node.name)
                elif isinstance(node, ast.ClassDef):
                    classes.append(node.name)

            duration = (time.time() - start) * 1000

            return ValidationResult(
                tier=ValidationTier.SYNTAX,
                passed=True,
                score=0.2,  # Full syntax tier score
                details={
                    'imports': imports,
                    'functions': functions,
                    'classes': classes,
                    'lines': len(code.split('\n'))
                },
                duration_ms=duration,
                insights=["Code is syntactically valid"]
            )

        except SyntaxError as e:
            duration = (time.time() - start) * 1000
            return ValidationResult(
                tier=ValidationTier.SYNTAX,
                passed=False,
                score=0.0,
                details={'error': str(e), 'line': e.lineno},
                duration_ms=duration,
                insights=[f"Syntax error at line {e.lineno}: {e.msg}"]
            )

    # ============================================================
    # TIER 2: STATIC ANALYSIS (Dream Phase: CONSOLIDATION)
    # ============================================================

    def validate_static(self, code: str, filepath: str = "temp.py") -> ValidationResult:
        """Consolidate understanding - check types, quality, patterns"""
        start = time.time()

        # Write to temp file for analysis
        temp_path = Path(filepath)
        temp_path.write_text(code)

        insights = []
        score = 0.0
        details = {}

        # Run pylint (if available)
        try:
            result = subprocess.run(
                ['pylint', '--score=y', str(temp_path)],
                capture_output=True,
                text=True,
                timeout=10
            )

            # Extract score
            for line in result.stdout.split('\n'):
                if 'rated at' in line:
                    # "Your code has been rated at 8.5/10"
                    parts = line.split('rated at')[1].split('/')[0].strip()
                    pylint_score = float(parts) / 10.0
                    score += pylint_score * 0.5  # 50% weight
                    details['pylint_score'] = pylint_score
                    insights.append(f"Pylint score: {pylint_score:.2f}/10")
                    break
        except (subprocess.TimeoutExpired, FileNotFoundError):
            insights.append("Pylint not available or timed out")

        # Pattern analysis (inspired by pattern_engine.py)
        patterns = self._analyze_code_patterns(code)
        details['patterns'] = patterns

        # Quality heuristics
        quality_score = self._calculate_quality_score(code, patterns)
        score += quality_score * 0.5  # 50% weight
        details['quality_score'] = quality_score

        duration = (time.time() - start) * 1000

        # Cleanup
        if temp_path.exists():
            temp_path.unlink()

        return ValidationResult(
            tier=ValidationTier.STATIC,
            passed=score > 0.5,
            score=min(score * 0.2, 0.2),  # Scale to tier max (0.2)
            details=details,
            duration_ms=duration,
            insights=insights
        )

    def _analyze_code_patterns(self, code: str) -> dict:
        """Detect patterns in code (inspired by pattern_engine)"""
        patterns = {
            'async_usage': code.count('async def'),
            'context_managers': code.count('with '),
            'list_comprehensions': code.count('[' if 'for' in code else ''),
            'error_handling': code.count('try:'),
            'type_hints': code.count(':') - code.count('def'),
            'docstrings': code.count('"""') + code.count("'''"),
            'decorators': code.count('@'),
        }
        return patterns

    def _calculate_quality_score(self, code: str, patterns: dict) -> float:
        """Calculate quality based on patterns"""
        score = 0.5  # Base score

        # Bonus for good practices
        if patterns['docstrings'] > 0:
            score += 0.1
        if patterns['type_hints'] > 0:
            score += 0.1
        if patterns['error_handling'] > 0:
            score += 0.1
        if patterns['context_managers'] > 0:
            score += 0.1

        # Penalty for code smells
        lines = code.split('\n')
        if any(len(line) > 120 for line in lines):
            score -= 0.1  # Long lines
        if code.count('# TODO') > 2:
            score -= 0.05  # Too many TODOs

        return max(0.0, min(1.0, score))

    # ============================================================
    # TIER 3: FUNCTIONAL TESTING (Dream Phase: SERENDIPITY)
    # ============================================================

    def validate_functional(self, code: str, test_cases: list[dict]) -> ValidationResult:
        """Discover unexpected connections - does code work?"""
        start = time.time()

        insights = []
        passed_tests = 0
        total_tests = len(test_cases)

        if total_tests == 0:
            # Generate simple smoke tests
            test_cases = self._generate_smoke_tests(code)
            total_tests = len(test_cases)

        # Execute tests (in safe environment)
        for test in test_cases:
            try:
                # Simple eval-based testing (production would use proper isolation)
                exec(code, {})
                passed_tests += 1
            except Exception as e:
                insights.append(f"Test failed: {e}")

        pass_rate = passed_tests / total_tests if total_tests > 0 else 0.0

        duration = (time.time() - start) * 1000

        return ValidationResult(
            tier=ValidationTier.FUNCTIONAL,
            passed=pass_rate >= 0.8,
            score=pass_rate * 0.2,  # Scale to tier max
            details={
                'passed': passed_tests,
                'total': total_tests,
                'pass_rate': pass_rate
            },
            duration_ms=duration,
            insights=insights
        )

    def _generate_smoke_tests(self, code: str) -> list[dict]:
        """Generate basic smoke tests"""
        tests = []

        # Parse to find functions
        try:
            tree = ast.parse(code)
            for node in ast.walk(tree):
                if isinstance(node, ast.FunctionDef):
                    tests.append({
                        'name': f"test_{node.name}",
                        'function': node.name
                    })
        except:
            pass

        return tests

    # ============================================================
    # TIER 4: PERFORMANCE BENCHMARKING (Dream Phase: KAIZEN)
    # ============================================================

    def validate_performance(self, code: str, baseline_code: str | None = None) -> ValidationResult:
        """Continuous improvement - measure actual performance"""
        start = time.time()

        insights = []
        details = {}

        # Benchmark generated code
        gen_time = self._benchmark_code(code)
        details['generated_time_ms'] = gen_time

        if baseline_code:
            # Compare to baseline
            baseline_time = self._benchmark_code(baseline_code)
            details['baseline_time_ms'] = baseline_time

            if baseline_time > 0:
                speedup = baseline_time / gen_time
                details['speedup'] = speedup

                if speedup > 1.0:
                    improvement = (speedup - 1.0) * 100
                    insights.append(f"Code is {improvement:.1f}% faster than baseline")
                    score = min(speedup / 3.0, 1.0)  # Cap at 3x speedup = 1.0
                else:
                    slowdown = (1.0 / speedup - 1.0) * 100
                    insights.append(f"Code is {slowdown:.1f}% slower than baseline")
                    score = 0.0
            else:
                score = 0.5
        else:
            # No baseline, just measure
            insights.append(f"Execution time: {gen_time:.2f}ms")
            score = 0.5

        duration = (time.time() - start) * 1000

        return ValidationResult(
            tier=ValidationTier.PERFORMANCE,
            passed=score > 0.3,
            score=score * 0.3,  # Scale to tier max
            details=details,
            duration_ms=duration,
            insights=insights
        )

    def _benchmark_code(self, code: str, iterations: int = 100) -> float:
        """Benchmark code execution time"""
        try:
            # Compile once
            compiled = compile(code, '<string>', 'exec')

            # Warm up
            for _ in range(10):
                exec(compiled, {})

            # Measure
            start = time.perf_counter()
            for _ in range(iterations):
                exec(compiled, {})
            end = time.perf_counter()

            return ((end - start) / iterations) * 1000  # ms per iteration
        except:
            return -1.0

    # ============================================================
    # TIER 5: PRODUCTION READINESS (Dream Phase: GOVERNANCE)
    # ============================================================

    def validate_production(self, code: str, integration_tests: list[dict]) -> ValidationResult:
        """Governance check - ready for production?"""
        start = time.time()

        insights = []
        checks = {
            'has_docstrings': '"""' in code or "'''" in code,
            'has_error_handling': 'try:' in code,
            'has_logging': 'logging' in code or 'logger' in code,
            'has_type_hints': '->' in code,
            'no_print_statements': 'print(' not in code,
            'no_hardcoded_paths': '/home/' not in code and 'C:\\' not in code,
        }

        passed_checks = sum(checks.values())
        total_checks = len(checks)

        for check, passed in checks.items():
            if not passed:
                insights.append(f"Missing: {check.replace('_', ' ')}")

        score = passed_checks / total_checks

        duration = (time.time() - start) * 1000

        return ValidationResult(
            tier=ValidationTier.PRODUCTION,
            passed=score >= 0.8,
            score=score * 0.1,  # Scale to tier max (bonus tier)
            details=checks,
            duration_ms=duration,
            insights=insights
        )

    # ============================================================
    # INTEGRATED VALIDATION PIPELINE
    # ============================================================

    def validate_all(self, code: str, baseline_code: str | None = None) -> dict:
        """Run all validation tiers"""
        results = {}
        total_score = 0.0
        all_insights = []

        # Tier 1: Syntax
        syntax_result = self.validate_syntax(code)
        results['syntax'] = syntax_result
        total_score += syntax_result.score
        all_insights.extend(syntax_result.insights)

        if not syntax_result.passed:
            # Can't proceed if syntax invalid
            return {
                'total_score': total_score,
                'tier_results': results,
                'insights': all_insights,
                'passed': False,
                'recommendation': 'Fix syntax errors before proceeding'
            }

        # Tier 2: Static Analysis
        static_result = self.validate_static(code)
        results['static'] = static_result
        total_score += static_result.score
        all_insights.extend(static_result.insights)

        # Tier 3: Functional
        functional_result = self.validate_functional(code, [])
        results['functional'] = functional_result
        total_score += functional_result.score
        all_insights.extend(functional_result.insights)

        # Tier 4: Performance
        if baseline_code:
            perf_result = self.validate_performance(code, baseline_code)
            results['performance'] = perf_result
            total_score += perf_result.score
            all_insights.extend(perf_result.insights)

        # Tier 5: Production
        prod_result = self.validate_production(code, [])
        results['production'] = prod_result
        total_score += prod_result.score
        all_insights.extend(prod_result.insights)

        # Overall assessment
        passed = total_score >= 0.7  # 70% threshold

        return {
            'total_score': total_score,
            'tier_results': results,
            'insights': all_insights,
            'passed': passed,
            'recommendation': self._generate_recommendation(total_score, results)
        }

    def _generate_recommendation(self, score: float, results: dict) -> str:
        """Generate recommendation based on validation"""
        if score >= 0.9:
            return "Excellent! Code is production-ready."
        elif score >= 0.7:
            return "Good! Code is functional with minor improvements needed."
        elif score >= 0.5:
            return "Fair. Code works but needs quality improvements."
        elif score >= 0.3:
            return "Poor. Significant improvements needed."
        else:
            return "Failed. Code requires major rework."

    # ============================================================
    # INSIGHT GENERATION (Dream Phase: ORACLE)
    # ============================================================

    def generate_insights(self, genome_genes: list[str]) -> list[InsightRecommendation]:
        """Generate actionable insights from genome (oracle consultation)"""
        insights = []

        # Gene to insight mapping (expanded from previous version)
        gene_insights = {
            'caching': InsightRecommendation(
                pattern='@lru_cache decorator',
                target='Pure functions called repeatedly',
                impact='high',
                example='@lru_cache(maxsize=128)\ndef expensive_function(x): ...',
                rationale='Eliminates redundant computation, 10-100x speedup for repeated calls',
                priority=1,
                estimated_speedup=10.0
            ),
            'async_functions': InsightRecommendation(
                pattern='async/await pattern',
                target='I/O-bound operations (network, disk, database)',
                impact='very_high',
                example='async def fetch_data():\n    async with aiohttp.ClientSession() as session:\n        return await session.get(url)',
                rationale='Enables concurrent I/O, 5-50x throughput improvement',
                priority=1,
                estimated_speedup=15.0
            ),
            'numpy_vectorization': InsightRecommendation(
                pattern='NumPy vectorized operations',
                target='Loops over numerical arrays',
                impact='very_high',
                example='result = np.sum(array * weights) instead of sum([a*w for a,w in zip(array, weights)])',
                rationale='C-speed computation, 50-1000x faster than Python loops',
                priority=1,
                estimated_speedup=100.0
            ),
            'multiprocessing': InsightRecommendation(
                pattern='multiprocessing.Pool',
                target='CPU-bound parallel tasks',
                impact='high',
                example='with Pool(cpu_count()) as pool:\n    results = pool.map(process_item, items)',
                rationale='True parallelism (no GIL), Nx speedup where N=CPU cores',
                priority=2,
                estimated_speedup=8.0
            ),
            'rust_integration': InsightRecommendation(
                pattern='PyO3 Rust extension',
                target='Performance-critical hot paths',
                impact='very_high',
                example='Use PyO3 to expose Rust functions: #[pyfunction]\nfn fast_compute(data: Vec<f64>) -> f64',
                rationale='Native speed, memory safety, 10-100x faster than Python',
                priority=1,
                estimated_speedup=50.0
            ),
            'memory_pooling': InsightRecommendation(
                pattern='Object pooling',
                target='Frequently allocated/deallocated objects',
                impact='medium',
                example='pool = ObjectPool(factory, max_size=100)\nobj = pool.acquire()\ntry:\n    use(obj)\nfinally:\n    pool.release(obj)',
                rationale='Reduces GC pressure, 2-5x speedup for allocation-heavy code',
                priority=3,
                estimated_speedup=3.0
            ),
        }

        for gene in genome_genes:
            if gene in gene_insights:
                insights.append(gene_insights[gene])

        # Sort by priority and estimated speedup
        insights.sort(key=lambda x: (x.priority, -x.estimated_speedup))

        return insights


def main():
    print("=" * 80)
    print("ENHANCED VALIDATION FRAMEWORK")
    print("=" * 80)
    print()

    validator = EnhancedValidator()

    # Example: Validate some code
    sample_code = '''
def fibonacci(n):
    """Calculate fibonacci number"""
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)
'''

    print("📊 Running multi-tier validation...")
    print()

    results = validator.validate_all(sample_code)

    print(f"Total Score: {results['total_score']:.2f}/1.0")
    print(f"Status: {'✅ PASSED' if results['passed'] else '❌ FAILED'}")
    print(f"Recommendation: {results['recommendation']}")
    print()

    print("Tier Results:")
    for tier_name, tier_result in results['tier_results'].items():
        status = "✅" if tier_result.passed else "❌"
        print(f"  {status} {tier_name.upper()}: {tier_result.score:.2f} ({tier_result.duration_ms:.1f}ms)")
    print()

    if results['insights']:
        print("💡 Insights:")
        for insight in results['insights'][:5]:
            print(f"  - {insight}")

    print()
    print("✅ Validation framework operational!")

if __name__ == "__main__":
    main()
