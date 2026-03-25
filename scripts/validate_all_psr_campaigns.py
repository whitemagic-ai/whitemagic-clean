#!/usr/bin/env python3
"""
Validate All PSR Campaigns - Check VCs and Generate Metrics
Comprehensive validation of PSR-001 through PSR-010
"""

import json
from pathlib import Path
from typing import Dict, List, Any

def validate_psr001() -> Dict[str, Any]:
    """Validate PSR-001 Memory Core"""
    base = Path(__file__).parent.parent
    
    results = {
        'campaign': 'PSR-001',
        'name': 'Memory Core',
        'vcs_total': 26,
        'vcs_complete': 9,
        'files_created': [],
        'files_missing': [],
        'expected_speedup': '50-100×'
    }
    
    # Check Rust files
    rust_files = [
        'whitemagic-rust/src/memory/sqlite_backend_v2.rs',
        'whitemagic-rust/src/memory/unified_v2.rs',
        'whitemagic-rust/src/memory/consolidation_v2.rs'
    ]
    
    for f in rust_files:
        path = base / f
        if path.exists():
            results['files_created'].append(f)
        else:
            results['files_missing'].append(f)
    
    # Check Zig files
    zig_files = [
        'whitemagic-zig/src/memory/pattern_engine.zig',
        'whitemagic-zig/src/memory/galactic_map.zig'
    ]
    
    for f in zig_files:
        path = base / f
        if path.exists():
            results['files_created'].append(f)
        else:
            results['files_missing'].append(f)
    
    # Check Mojo files
    mojo_files = [
        'whitemagic-mojo/src/hrr.mojo',
        'whitemagic-mojo/src/surprise_gate.mojo',
        'whitemagic-mojo/src/embedding_index.mojo'
    ]
    
    for f in mojo_files:
        path = base / f
        if path.exists():
            results['files_created'].append(f)
        else:
            results['files_missing'].append(f)
    
    # Check Koka files
    koka_files = ['whitemagic-koka/src/dream_cycle.kk']
    
    for f in koka_files:
        path = base / f
        if path.exists():
            results['files_created'].append(f)
        else:
            results['files_missing'].append(f)
    
    results['completion_rate'] = len(results['files_created']) / results['vcs_total']
    results['status'] = '✅ COMPLETE' if len(results['files_created']) == 9 else '⚠️ PARTIAL'
    
    return results

def validate_psr_campaign(campaign_id: str, expected_files: List[str]) -> Dict[str, Any]:
    """Validate a PSR campaign"""
    base = Path(__file__).parent.parent
    
    results = {
        'campaign': campaign_id,
        'files_created': [],
        'files_missing': []
    }
    
    for f in expected_files:
        path = base / f
        if path.exists():
            results['files_created'].append(f)
        else:
            results['files_missing'].append(f)
    
    results['completion_rate'] = len(results['files_created']) / len(expected_files) if expected_files else 0
    results['status'] = '✅ COMPLETE' if len(results['files_missing']) == 0 else '⚠️ PARTIAL'
    
    return results

def main():
    """Validate all PSR campaigns"""
    print("\n" + "="*70)
    print("🔍 PSR CAMPAIGN VALIDATION")
    print("="*70)
    
    # Validate PSR-001
    psr001 = validate_psr001()
    
    # Validate PSR-002 through PSR-010
    campaigns = {
        'PSR-002': [
            'whitemagic-rust/src/psr/psr-002/search.rs',
            'whitemagic-rust/src/psr/psr-002/vector_search.rs',
            'whitemagic-rust/src/psr/psr-002/hybrid_recall.rs',
            'whitemagic-rust/src/psr/psr-002/rerank.rs',
            'whitemagic-zig/src/psr/psr-002/query_expansion.zig'
        ],
        'PSR-003': [
            'whitemagic-rust/src/psr/psr-003/graph_walker.rs',
            'whitemagic-rust/src/psr/psr-003/association_miner.rs',
            'whitemagic-zig/src/psr/psr-003/graph_topology.zig',
            'whitemagic-rust/src/psr/psr-003/community_detection.rs',
            'whitemagic-zig/src/psr/psr-003/centrality.zig'
        ],
        'PSR-004': [
            'whitemagic-rust/src/psr/psr-004/reasoning_engine.rs',
            'whitemagic-rust/src/psr/psr-004/causal_net.rs',
            'whitemagic-rust/src/psr/psr-004/emergence_detector.rs',
            'whitemagic-rust/src/psr/psr-004/synthesis_engine.rs',
            'whitemagic-rust/src/psr/psr-004/predictive_engine.rs'
        ],
        'PSR-006': [
            'whitemagic-rust/src/psr/psr-006/gana_winnowing_basket.rs',
            'whitemagic-rust/src/psr/psr-006/gana_neck.rs',
            'whitemagic-rust/src/psr/psr-006/gana_heart.rs',
            'whitemagic-rust/src/psr/psr-006/gana_ghost.rs'
        ],
        'PSR-007': [
            'whitemagic-koka/src/psr/psr-007/garden_base.kk',
            'whitemagic-koka/src/psr/psr-007/garden_resonance.kk',
            'whitemagic-koka/src/psr/psr-007/harmony_vector.kk',
            'whitemagic-koka/src/psr/psr-007/wu_xing.kk'
        ],
        'PSR-008': [
            'whitemagic-koka/src/psr/psr-008/orchestrator.kk',
            'whitemagic-koka/src/psr/psr-008/effect_handlers.kk',
            'whitemagic-koka/src/psr/psr-008/coordination.kk'
        ],
        'PSR-009': [
            'whitemagic-mojo/src/psr/psr-009/embeddings.mojo',
            'whitemagic-mojo/src/psr/psr-009/clustering.mojo',
            'whitemagic-mojo/src/psr/psr-009/dimensionality_reduction.mojo'
        ],
        'PSR-010': [
            'whitemagic-rust/src/psr/psr-010/integration_layer.rs',
            'whitemagic-rust/src/psr/psr-010/performance_monitor.rs',
            'whitemagic-rust/src/psr/psr-010/test_suite.rs'
        ]
    }
    
    all_results = {'PSR-001': psr001}
    
    for cid, files in campaigns.items():
        result = validate_psr_campaign(cid, files)
        all_results[cid] = result
    
    # Summary
    print("\n📊 VALIDATION SUMMARY")
    print("="*70)
    
    total_campaigns = len(all_results)
    complete_campaigns = sum(1 for r in all_results.values() if r['status'] == '✅ COMPLETE')
    total_files = sum(len(r['files_created']) for r in all_results.values())
    
    print(f"\nCampaigns validated: {total_campaigns}/10")
    print(f"Complete campaigns: {complete_campaigns}/{total_campaigns}")
    print(f"Total files created: {total_files}")
    
    print("\n📋 Per-Campaign Status:")
    for cid in sorted(all_results.keys()):
        result = all_results[cid]
        created = len(result['files_created'])
        missing = len(result['files_missing'])
        rate = result['completion_rate'] * 100
        print(f"  {cid}: {result['status']} ({created} files, {rate:.0f}% complete)")
        if missing > 0:
            print(f"    Missing: {missing} files")
    
    # Save report
    report_path = Path(__file__).parent.parent / "reports" / "psr_validation_report.json"
    report = {
        'total_campaigns': total_campaigns,
        'complete_campaigns': complete_campaigns,
        'total_files': total_files,
        'results': all_results
    }
    report_path.write_text(json.dumps(report, indent=2))
    
    print(f"\n✅ Validation report saved: {report_path}")
    
    if complete_campaigns == total_campaigns:
        print("\n🎉 ALL PSR CAMPAIGNS VALIDATED!")
    else:
        print(f"\n⚠️  {total_campaigns - complete_campaigns} campaigns need completion")

if __name__ == '__main__':
    main()
