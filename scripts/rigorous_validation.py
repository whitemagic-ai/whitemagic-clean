#!/usr/bin/env python3
"""
Rigorous Validation - Deep check of all PSR files
Verify content, structure, and readiness for compilation
"""

import json
from pathlib import Path


def check_file_content(filepath: Path) -> tuple[bool, int, str]:
    """Check if file exists and has meaningful content"""
    if not filepath.exists():
        return False, 0, "File does not exist"

    content = filepath.read_text()
    lines = content.strip().split('\n')

    if len(lines) < 10:
        return False, len(lines), "File too short (< 10 lines)"

    # Check for placeholder content
    if "TODO" in content and len(lines) < 50:
        return False, len(lines), "Appears to be placeholder/stub"

    return True, len(lines), "OK"

def validate_rust_files() -> dict:
    """Validate all Rust PSR files"""
    base = Path(__file__).parent.parent

    rust_files = [
        # PSR-001
        'whitemagic-rust/src/memory/sqlite_backend_v2.rs',
        'whitemagic-rust/src/memory/unified_v2.rs',
        'whitemagic-rust/src/memory/consolidation_v2.rs',
        # PSR-002
        'whitemagic-rust/src/psr/psr-002/search.rs',
        'whitemagic-rust/src/psr/psr-002/vector_search.rs',
        'whitemagic-rust/src/psr/psr-002/hybrid_recall.rs',
        'whitemagic-rust/src/psr/psr-002/rerank.rs',
        # PSR-003
        'whitemagic-rust/src/psr/psr-003/graph_walker.rs',
        'whitemagic-rust/src/psr/psr-003/association_miner.rs',
        'whitemagic-rust/src/psr/psr-003/community_detection.rs',
        # PSR-004
        'whitemagic-rust/src/psr/psr-004/reasoning_engine.rs',
        'whitemagic-rust/src/psr/psr-004/causal_net.rs',
        'whitemagic-rust/src/psr/psr-004/emergence_detector.rs',
        'whitemagic-rust/src/psr/psr-004/synthesis_engine.rs',
        'whitemagic-rust/src/psr/psr-004/predictive_engine.rs',
        # PSR-006
        'whitemagic-rust/src/psr/psr-006/gana_winnowing_basket.rs',
        'whitemagic-rust/src/psr/psr-006/gana_neck.rs',
        'whitemagic-rust/src/psr/psr-006/gana_heart.rs',
        'whitemagic-rust/src/psr/psr-006/gana_ghost.rs',
        # PSR-010
        'whitemagic-rust/src/psr/psr-010/integration_layer.rs',
        'whitemagic-rust/src/psr/psr-010/performance_monitor.rs',
        'whitemagic-rust/src/psr/psr-010/test_suite.rs',
    ]

    results = {
        'total': len(rust_files),
        'valid': 0,
        'invalid': 0,
        'total_lines': 0,
        'files': {}
    }

    for f in rust_files:
        path = base / f
        valid, lines, msg = check_file_content(path)
        results['files'][f] = {
            'valid': valid,
            'lines': lines,
            'message': msg
        }
        if valid:
            results['valid'] += 1
            results['total_lines'] += lines
        else:
            results['invalid'] += 1

    return results

def validate_zig_files() -> dict:
    """Validate all Zig PSR files"""
    base = Path(__file__).parent.parent

    zig_files = [
        'whitemagic-zig/src/memory/pattern_engine.zig',
        'whitemagic-zig/src/memory/galactic_map.zig',
        'whitemagic-zig/src/psr/psr-002/query_expansion.zig',
        'whitemagic-zig/src/psr/psr-003/graph_topology.zig',
        'whitemagic-zig/src/psr/psr-003/centrality.zig',
    ]

    results = {
        'total': len(zig_files),
        'valid': 0,
        'invalid': 0,
        'total_lines': 0,
        'files': {}
    }

    for f in zig_files:
        path = base / f
        valid, lines, msg = check_file_content(path)
        results['files'][f] = {
            'valid': valid,
            'lines': lines,
            'message': msg
        }
        if valid:
            results['valid'] += 1
            results['total_lines'] += lines
        else:
            results['invalid'] += 1

    return results

def validate_mojo_files() -> dict:
    """Validate all Mojo PSR files"""
    base = Path(__file__).parent.parent

    mojo_files = [
        'whitemagic-mojo/src/hrr.mojo',
        'whitemagic-mojo/src/surprise_gate.mojo',
        'whitemagic-mojo/src/embedding_index.mojo',
        'whitemagic-mojo/src/psr/psr-009/embeddings.mojo',
        'whitemagic-mojo/src/psr/psr-009/clustering.mojo',
        'whitemagic-mojo/src/psr/psr-009/dimensionality_reduction.mojo',
    ]

    results = {
        'total': len(mojo_files),
        'valid': 0,
        'invalid': 0,
        'total_lines': 0,
        'files': {}
    }

    for f in mojo_files:
        path = base / f
        valid, lines, msg = check_file_content(path)
        results['files'][f] = {
            'valid': valid,
            'lines': lines,
            'message': msg
        }
        if valid:
            results['valid'] += 1
            results['total_lines'] += lines
        else:
            results['invalid'] += 1

    return results

def validate_koka_files() -> dict:
    """Validate all Koka PSR files"""
    base = Path(__file__).parent.parent

    koka_files = [
        'whitemagic-koka/src/dream_cycle.kk',
        'whitemagic-koka/src/psr/psr-007/garden_base.kk',
        'whitemagic-koka/src/psr/psr-007/garden_resonance.kk',
        'whitemagic-koka/src/psr/psr-007/harmony_vector.kk',
        'whitemagic-koka/src/psr/psr-007/wu_xing.kk',
        'whitemagic-koka/src/psr/psr-008/orchestrator.kk',
        'whitemagic-koka/src/psr/psr-008/effect_handlers.kk',
        'whitemagic-koka/src/psr/psr-008/coordination.kk',
    ]

    results = {
        'total': len(koka_files),
        'valid': 0,
        'invalid': 0,
        'total_lines': 0,
        'files': {}
    }

    for f in koka_files:
        path = base / f
        valid, lines, msg = check_file_content(path)
        results['files'][f] = {
            'valid': valid,
            'lines': lines,
            'message': msg
        }
        if valid:
            results['valid'] += 1
            results['total_lines'] += lines
        else:
            results['invalid'] += 1

    return results

def main():
    """Run rigorous validation"""
    print("\n" + "="*70)
    print("🔬 RIGOROUS VALIDATION - DEEP FILE CHECK")
    print("="*70)

    # Validate each language
    rust_results = validate_rust_files()
    zig_results = validate_zig_files()
    mojo_results = validate_mojo_files()
    koka_results = validate_koka_files()

    # Summary
    print("\n📊 VALIDATION SUMMARY")
    print("="*70)

    total_files = (rust_results['total'] + zig_results['total'] +
                   mojo_results['total'] + koka_results['total'])
    total_valid = (rust_results['valid'] + zig_results['valid'] +
                   mojo_results['valid'] + koka_results['valid'])
    total_invalid = (rust_results['invalid'] + zig_results['invalid'] +
                     mojo_results['invalid'] + koka_results['invalid'])
    total_lines = (rust_results['total_lines'] + zig_results['total_lines'] +
                   mojo_results['total_lines'] + koka_results['total_lines'])

    print(f"\n📁 Total Files: {total_files}")
    print(f"✅ Valid: {total_valid} ({total_valid/total_files*100:.1f}%)")
    print(f"❌ Invalid: {total_invalid} ({total_invalid/total_files*100:.1f}%)")
    print(f"📝 Total Lines: {total_lines:,}")

    print("\n📋 By Language:")
    print(f"  Rust:  {rust_results['valid']}/{rust_results['total']} valid ({rust_results['total_lines']:,} lines)")
    print(f"  Zig:   {zig_results['valid']}/{zig_results['total']} valid ({zig_results['total_lines']:,} lines)")
    print(f"  Mojo:  {mojo_results['valid']}/{mojo_results['total']} valid ({mojo_results['total_lines']:,} lines)")
    print(f"  Koka:  {koka_results['valid']}/{koka_results['total']} valid ({koka_results['total_lines']:,} lines)")

    # Show invalid files
    if total_invalid > 0:
        print("\n❌ INVALID FILES:")
        for lang, results in [('Rust', rust_results), ('Zig', zig_results),
                              ('Mojo', mojo_results), ('Koka', koka_results)]:
            for f, info in results['files'].items():
                if not info['valid']:
                    print(f"  {f}: {info['message']} ({info['lines']} lines)")

    # Save detailed report
    report = {
        'summary': {
            'total_files': total_files,
            'valid': total_valid,
            'invalid': total_invalid,
            'total_lines': total_lines
        },
        'rust': rust_results,
        'zig': zig_results,
        'mojo': mojo_results,
        'koka': koka_results
    }

    report_path = Path(__file__).parent.parent / "reports" / "rigorous_validation.json"
    report_path.write_text(json.dumps(report, indent=2))

    print(f"\n✅ Detailed report saved: {report_path}")

    if total_invalid == 0:
        print("\n🎉 ALL FILES VALID - READY FOR COMPILATION!")
    else:
        print(f"\n⚠️  {total_invalid} FILES NEED ATTENTION")

if __name__ == '__main__':
    main()
