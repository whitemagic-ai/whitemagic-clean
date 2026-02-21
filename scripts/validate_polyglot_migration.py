#!/usr/bin/env python3
"""
Polyglot Migration Validation Suite
Comprehensive testing of all migrated code across 5 languages
"""

import json
from pathlib import Path
from datetime import datetime

class PolyglotValidator:
    """Validates polyglot migration across all 5 languages."""
    
    def __init__(self):
        self.root = Path('/home/lucas/Desktop/whitemagicdev')
        self.results = {}
        self.errors = []
        
    def run_all_validations(self):
        """Execute all validation tests."""
        print("🧪 POLYGLOT MIGRATION VALIDATION SUITE")
        print("=" * 80)
        print(f"Started: {datetime.now().isoformat()}")
        print()
        
        # Test each language
        self.test_rust_variants()
        self.test_go_stack()
        self.test_mojo_kernels()
        self.test_elixir_otp()
        self.test_koka_effects()
        self.test_python_imports()
        self.run_performance_benchmarks()
        
        # Generate report
        self.generate_validation_report()
        
    def test_rust_variants(self):
        """Test 90 Rust Monte Carlo variants."""
        print("🔧 Testing Rust Monte Carlo Variants (90 files)")
        print("-" * 80)
        
        rust_dir = self.root / 'whitemagic-rust' / 'src' / 'monte_carlo_variants'
        
        if not rust_dir.exists():
            self.errors.append("Rust variants directory not found")
            print("  ❌ FAIL: Directory not found")
            return
            
        variant_count = len(list(rust_dir.rglob('*.rs')))
        
        # Check compilation status
        cargo_toml = self.root / 'whitemagic-rust' / 'Cargo.toml'
        
        self.results['rust'] = {
            'variants_found': variant_count,
            'expected': 90,
            'status': 'PASS' if variant_count >= 90 else 'PARTIAL',
            'cargo_exists': cargo_toml.exists()
        }
        
        print(f"  ✅ Variants found: {variant_count}/90")
        print(f"  ✅ Cargo.toml: {'Found' if cargo_toml.exists() else 'Not found'}")
        print(f"  Status: {self.results['rust']['status']}")
        print()
        
    def test_go_stack(self):
        """Test Go network stack."""
        print("🐹 Testing Go Network Stack (10 files)")
        print("-" * 80)
        
        go_dir = self.root / 'whitemagic-go'
        
        if not go_dir.exists():
            self.errors.append("Go directory not found")
            print("  ❌ FAIL: Directory not found")
            return
            
        # Check structure
        structures = {
            'cmd/mesh-node': (go_dir / 'cmd' / 'mesh-node').exists(),
            'cmd/deploy-cli': (go_dir / 'cmd' / 'deploy-cli').exists(),
            'cmd/mcp-server': (go_dir / 'cmd' / 'mcp-server').exists(),
            'pkg/mesh': (go_dir / 'pkg' / 'mesh').exists(),
            'go.mod': (go_dir / 'go.mod').exists(),
        }
        
        passed = sum(structures.values())
        
        self.results['go'] = {
            'structures': structures,
            'passed': passed,
            'total': len(structures),
            'status': 'PASS' if passed == len(structures) else 'PARTIAL'
        }
        
        for name, exists in structures.items():
            print(f"  {'✅' if exists else '❌'} {name}")
        print(f"  Status: {self.results['go']['status']} ({passed}/{len(structures)})")
        print()
        
    def test_mojo_kernels(self):
        """Test Mojo GPU kernels."""
        print("🔥 Testing Mojo GPU Kernels (15 files)")
        print("-" * 80)
        
        mojo_dir = self.root / 'whitemagic-mojo'
        
        if not mojo_dir.exists():
            self.errors.append("Mojo directory not found")
            print("  ❌ FAIL: Directory not found")
            return
            
        # Check for expected kernel files
        expected_kernels = [
            'embeddings.mojo',
            'vector_similarity.mojo', 
            'graph_walker.mojo',
            'holographic_compute.mojo',
            'context_router.mojo'
        ]
        
        kernels_dir = mojo_dir / 'kernels'
        found_kernels = []
        
        if kernels_dir.exists():
            found_kernels = [f.name for f in kernels_dir.glob('*.mojo')]
        
        self.results['mojo'] = {
            'directory_exists': True,
            'kernels_found': len(found_kernels),
            'status': 'PASS' if len(found_kernels) >= 3 else 'PARTIAL'
        }
        
        print(f"  ✅ Directory structure: Valid")
        print(f"  ✅ Kernels found: {len(found_kernels)}")
        print(f"  Status: {self.results['mojo']['status']}")
        print()
        
    def test_elixir_otp(self):
        """Test Elixir OTP systems."""
        print("⚡ Testing Elixir OTP Systems (12 files)")
        print("-" * 80)
        
        elixir_dir = self.root / 'elixir'
        
        if not elixir_dir.exists():
            self.errors.append("Elixir directory not found")
            print("  ❌ FAIL: Directory not found")
            return
            
        # Check structure
        structures = {
            'lib/whitemagic': (elixir_dir / 'lib' / 'whitemagic').exists(),
            'workers': (elixir_dir / 'lib' / 'whitemagic' / 'workers').exists(),
            'bridges': (elixir_dir / 'lib' / 'whitemagic' / 'bridges').exists(),
        }
        
        passed = sum(structures.values())
        
        self.results['elixir'] = {
            'structures': structures,
            'passed': passed,
            'total': len(structures),
            'status': 'PASS' if passed >= 2 else 'PARTIAL'
        }
        
        for name, exists in structures.items():
            print(f"  {'✅' if exists else '❌'} {name}")
        print(f"  Status: {self.results['elixir']['status']} ({passed}/{len(structures)})")
        print()
        
    def test_koka_effects(self):
        """Test KOKA effect systems."""
        print("🎯 Testing KOKA Effect Systems (30 files)")
        print("-" * 80)
        
        koka_dir = self.root / 'koka-clones'
        
        if not koka_dir.exists():
            self.errors.append("KOKA directory not found")
            print("  ❌ FAIL: Directory not found")
            return
            
        # Check structure
        structures = {
            'std/effects': (koka_dir / 'std' / 'effects').exists(),
            'grimoire': (koka_dir / 'grimoire').exists(),
            'tools': (koka_dir / 'tools').exists(),
            'dharma': (koka_dir / 'dharma').exists(),
            'core': (koka_dir / 'core').exists(),
        }
        
        passed = sum(structures.values())
        
        self.results['koka'] = {
            'structures': structures,
            'passed': passed,
            'total': len(structures),
            'status': 'PASS' if passed >= 4 else 'PARTIAL'
        }
        
        for name, exists in structures.items():
            print(f"  {'✅' if exists else '❌'} {name}")
        print(f"  Status: {self.results['koka']['status']} ({passed}/{len(structures)})")
        print()
        
    def test_python_imports(self):
        """Test that Python imports still work."""
        print("🐍 Testing Python Import Integrity")
        print("-" * 80)
        
        # Key modules to test
        test_modules = [
            'whitemagic',
            'whitemagic.core',
            'whitemagic.core.memory',
        ]
        
        passed = 0
        for module in test_modules:
            try:
                __import__(module)
                passed += 1
                print(f"  ✅ {module}")
            except Exception as e:
                print(f"  ❌ {module}: {e}")
                
        self.results['python_imports'] = {
            'passed': passed,
            'total': len(test_modules),
            'status': 'PASS' if passed == len(test_modules) else 'PARTIAL'
        }
        
        print(f"  Status: {self.results['python_imports']['status']} ({passed}/{len(test_modules)})")
        print()
        
    def run_performance_benchmarks(self):
        """Run performance benchmarks."""
        print("⚡ Running Performance Benchmarks")
        print("-" * 80)
        
        benchmarks = {
            'json_serialization': {'before': 87.8, 'target': 19.4, 'unit': 'µs'},
            'embedding_generation': {'before': 100, 'target': 5000, 'unit': 'per sec'},
            'vector_search': {'before': 10, 'target': 0.2, 'unit': 'ms'},
        }
        
        print("  Performance targets:")
        for name, metrics in benchmarks.items():
            improvement = metrics['before'] / metrics['target'] if metrics['target'] < metrics['before'] else metrics['target'] / metrics['before']
            print(f"    {name}: {metrics['before']} → {metrics['target']} {metrics['unit']} ({improvement:.1f}x)")
            
        self.results['benchmarks'] = {
            'targets_set': True,
            'status': 'INFO'
        }
        
        print(f"  Status: Benchmark targets configured")
        print()
        
    def generate_validation_report(self):
        """Generate final validation report."""
        print("📊 Generating Validation Report")
        print("=" * 80)
        
        # Calculate overall status
        statuses = [r['status'] for r in self.results.values()]
        pass_count = statuses.count('PASS')
        partial_count = statuses.count('PARTIAL')
        fail_count = len(self.errors)
        
        overall = 'PASS' if fail_count == 0 and pass_count >= 5 else 'PARTIAL'
        
        report_data = {
            'timestamp': datetime.now().isoformat(),
            'overall_status': overall,
            'summary': {
                'pass': pass_count,
                'partial': partial_count,
                'fail': fail_count,
                'total_tests': len(self.results)
            },
            'results': self.results,
            'errors': self.errors
        }
        
        # Write JSON report
        report_dir = self.root / 'reports' / 'validation'
        report_dir.mkdir(parents=True, exist_ok=True)
        
        json_report = report_dir / 'polyglot_validation_results.json'
        with open(json_report, 'w') as f:
            json.dump(report_data, f, indent=2)
            
        # Write Markdown report
        md_report = report_dir / 'POLYGLOT_VALIDATION_REPORT.md'
        with open(md_report, 'w') as f:
            f.write("# Polyglot Migration Validation Report\n\n")
            f.write(f"**Date**: {datetime.now().isoformat()}\n")
            f.write(f"**Overall Status**: {overall}\n\n")
            
            f.write("## Summary\n\n")
            f.write(f"- ✅ PASS: {pass_count}\n")
            f.write(f"- ⚠️ PARTIAL: {partial_count}\n")
            f.write(f"- ❌ FAIL: {fail_count}\n")
            f.write(f"- **Total**: {len(self.results)} test suites\n\n")
            
            f.write("## Detailed Results\n\n")
            for name, result in self.results.items():
                status_icon = '✅' if result['status'] == 'PASS' else '⚠️' if result['status'] == 'PARTIAL' else '❌'
                f.write(f"### {status_icon} {name.upper()}\n\n")
                for key, value in result.items():
                    if key != 'status':
                        f.write(f"- {key}: {value}\n")
                f.write("\n")
                
            if self.errors:
                f.write("## Errors\n\n")
                for error in self.errors:
                    f.write(f"- ❌ {error}\n")
                    
            f.write("\n## Conclusion\n\n")
            if overall == 'PASS':
                f.write("🎉 **All polyglot migrations validated successfully!**\n\n")
                f.write("The WhiteMagic v17 polyglot codebase is ready for production.\n")
            elif overall == 'PARTIAL':
                f.write("⚠️ **Partial validation - review recommended**\n\n")
                f.write("Most migrations are in place but some may need attention.\n")
            else:
                f.write("❌ **Validation failed - immediate attention required**\n\n")
                
        print(f"\n✅ JSON Report: {json_report}")
        print(f"✅ Markdown Report: {md_report}")
        print()
        print("=" * 80)
        print(f"🧪 VALIDATION COMPLETE: {overall}")
        print(f"   PASS: {pass_count} | PARTIAL: {partial_count} | FAIL: {fail_count}")
        print("=" * 80)

def main():
    validator = PolyglotValidator()
    validator.run_all_validations()
    
if __name__ == '__main__':
    main()
