#!/usr/bin/env python3
"""
Individual Code Validator
Validates each generated implementation individually with detailed analysis
"""

import re
from pathlib import Path
from typing import Dict, List, Any

class DetailedValidator:
    """Detailed validation of individual implementations"""
    
    @staticmethod
    def validate_file(file_path: Path) -> Dict[str, Any]:
        """Comprehensive validation of a single file"""
        code = file_path.read_text()
        lines = code.split('\n')
        
        validation = {
            'file': file_path.name,
            'path': str(file_path),
            'line_count': len(lines),
            'char_count': len(code),
            'checks': {},
            'score': 0,
            'grade': '',
            'issues': [],
            'strengths': []
        }
        
        # Check 1: Not a stub
        has_todo = 'TODO' in code
        is_short = len(lines) < 50
        validation['checks']['is_stub'] = has_todo and is_short
        
        if not validation['checks']['is_stub']:
            validation['score'] += 30
            validation['strengths'].append("Real implementation (not stub)")
        else:
            validation['issues'].append("Appears to be stub (TODO + <50 lines)")
        
        # Check 2: Error handling
        has_result = 'Result<' in code or 'PyResult' in code
        has_error_handling = 'map_err' in code or 'unwrap_or' in code
        validation['checks']['error_handling'] = has_result and has_error_handling
        
        if validation['checks']['error_handling']:
            validation['score'] += 15
            validation['strengths'].append("Proper error handling")
        elif has_result:
            validation['score'] += 10
            validation['strengths'].append("Has Result types")
        else:
            validation['issues'].append("Missing error handling")
        
        # Check 3: Documentation
        has_module_doc = '//!' in code
        has_function_doc = '///' in code
        doc_lines = sum(1 for line in lines if line.strip().startswith('//'))
        validation['checks']['documentation'] = {
            'module_doc': has_module_doc,
            'function_doc': has_function_doc,
            'doc_lines': doc_lines
        }
        
        if has_module_doc and has_function_doc:
            validation['score'] += 15
            validation['strengths'].append("Comprehensive documentation")
        elif has_module_doc or has_function_doc:
            validation['score'] += 10
            validation['strengths'].append("Some documentation")
        else:
            validation['issues'].append("Missing documentation")
        
        # Check 4: Parallel processing
        has_rayon = 'rayon' in code
        has_par_iter = 'par_iter' in code
        validation['checks']['parallel'] = has_rayon or has_par_iter
        
        if validation['checks']['parallel']:
            validation['score'] += 10
            validation['strengths'].append("Parallel processing support")
        
        # Check 5: Python bindings
        has_pyclass = '#[pyclass]' in code
        has_pymethods = '#[pymethods]' in code
        validation['checks']['python_bindings'] = has_pyclass and has_pymethods
        
        if validation['checks']['python_bindings']:
            validation['score'] += 10
            validation['strengths'].append("Python bindings present")
        else:
            validation['issues'].append("Missing Python bindings")
        
        # Check 6: Data structures
        has_struct = 'struct ' in code
        has_impl = 'impl ' in code
        validation['checks']['data_structures'] = has_struct and has_impl
        
        if validation['checks']['data_structures']:
            validation['score'] += 10
            validation['strengths'].append("Proper data structures")
        
        # Check 7: Complexity
        fn_count = code.count('fn ')
        impl_count = code.count('impl ')
        struct_count = code.count('struct ')
        
        complexity = fn_count * 5 + impl_count * 10 + struct_count * 5
        validation['checks']['complexity'] = {
            'functions': fn_count,
            'impls': impl_count,
            'structs': struct_count,
            'score': complexity
        }
        
        if complexity > 50:
            validation['score'] += 10
            validation['strengths'].append(f"Good complexity ({complexity} points)")
        elif complexity > 20:
            validation['score'] += 5
        
        # Assign grade
        if validation['score'] >= 90:
            validation['grade'] = 'A'
        elif validation['score'] >= 80:
            validation['grade'] = 'B+'
        elif validation['score'] >= 70:
            validation['grade'] = 'B'
        elif validation['score'] >= 60:
            validation['grade'] = 'C+'
        elif validation['score'] >= 50:
            validation['grade'] = 'C'
        else:
            validation['grade'] = 'D'
        
        return validation

def main():
    """Validate all generated implementations"""
    base_path = Path(__file__).parent.parent
    psr_dir = base_path / "whitemagic-rust" / "src" / "psr"
    
    print("\n" + "="*70)
    print("🔍 INDIVIDUAL CODE VALIDATION")
    print("="*70)
    
    # Find all _v2.rs files
    v2_files = sorted(psr_dir.rglob("*_v2.rs"))
    
    print(f"\nValidating {len(v2_files)} implementations...\n")
    
    validator = DetailedValidator()
    results = []
    
    for file_path in v2_files:
        validation = validator.validate_file(file_path)
        results.append(validation)
        
        # Print result
        grade_emoji = {
            'A': '🌟',
            'B+': '✅',
            'B': '✅',
            'C+': '⚠️',
            'C': '⚠️',
            'D': '❌'
        }
        
        emoji = grade_emoji.get(validation['grade'], '❓')
        print(f"{emoji} {validation['file']}")
        print(f"   Grade: {validation['grade']} ({validation['score']}/100)")
        print(f"   Lines: {validation['line_count']}, Complexity: {validation['checks']['complexity']['score']}")
        
        if validation['strengths']:
            print(f"   ✓ {', '.join(validation['strengths'][:3])}")
        
        if validation['issues']:
            print(f"   ✗ {', '.join(validation['issues'][:2])}")
        
        print()
    
    # Summary
    print("="*70)
    print("📊 VALIDATION SUMMARY")
    print("="*70)
    
    total_files = len(results)
    avg_score = sum(r['score'] for r in results) / total_files if total_files > 0 else 0
    total_lines = sum(r['line_count'] for r in results)
    
    grade_counts = {}
    for result in results:
        grade = result['grade']
        grade_counts[grade] = grade_counts.get(grade, 0) + 1
    
    print(f"\nTotal files: {total_files}")
    print(f"Total lines: {total_lines:,}")
    print(f"Average score: {avg_score:.1f}/100")
    
    print(f"\nGrade Distribution:")
    for grade in ['A', 'B+', 'B', 'C+', 'C', 'D']:
        count = grade_counts.get(grade, 0)
        if count > 0:
            pct = (count / total_files) * 100
            print(f"  {grade}: {count} ({pct:.1f}%)")
    
    # Quality tiers
    excellent = sum(1 for r in results if r['score'] >= 90)
    good = sum(1 for r in results if 70 <= r['score'] < 90)
    acceptable = sum(1 for r in results if 60 <= r['score'] < 70)
    needs_work = sum(1 for r in results if r['score'] < 60)
    
    print(f"\nQuality Tiers:")
    print(f"  Excellent (≥90): {excellent}")
    print(f"  Good (70-89): {good}")
    print(f"  Acceptable (60-69): {acceptable}")
    print(f"  Needs work (<60): {needs_work}")
    
    # Top performers
    print(f"\n🌟 Top 5 Implementations:")
    top_5 = sorted(results, key=lambda r: r['score'], reverse=True)[:5]
    for i, result in enumerate(top_5, 1):
        print(f"  {i}. {result['file']}: {result['score']}/100 ({result['grade']})")
    
    # Files needing improvement
    needs_improvement = [r for r in results if r['score'] < 70]
    if needs_improvement:
        print(f"\n⚠️  Files Needing Improvement ({len(needs_improvement)}):")
        for result in needs_improvement[:5]:
            print(f"  - {result['file']}: {result['score']}/100")
            if result['issues']:
                print(f"    Issues: {', '.join(result['issues'])}")
    
    print(f"\n✅ Validation complete!")

if __name__ == '__main__':
    main()
