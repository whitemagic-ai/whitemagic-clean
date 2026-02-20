#!/usr/bin/env python3
"""Deploy H001 with Immortal Clone v2 - Enhanced with Victory Tracking & Dashboard

Uses the new v2 system with:
- Shared victory tracker
- Live progress dashboard
- Auto-completion when all VCs met
- 200 iteration limit (up from 50)
"""

import json
import logging
import sys
from pathlib import Path

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.immortal_clone_v2 import immortal_clone_deploy

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


def load_h001_campaign() -> dict:
    """Load H001 campaign configuration."""
    campaign_file = project_root / "campaigns" / "H001_embeddings_hot_path.md"
    
    # For now, create campaign dict directly
    # In full implementation, would parse from markdown
    return {
        'id': 'H001',
        'name': 'Embeddings Hot Path Optimization',
        'target': 'whitemagic/core/memory/embeddings.py',
        'target_speedup': 50,
        'victory_conditions': [
            # Phase 1: Profiling
            {'id': 'H001-VC-1', 'description': 'Profile find_duplicates() execution'},
            {'id': 'H001-VC-2', 'description': 'Identify hot paths in similarity calculation'},
            {'id': 'H001-VC-3', 'description': 'Measure baseline performance'},
            {'id': 'H001-VC-4', 'description': 'Document optimization targets'},
            {'id': 'H001-VC-5', 'description': 'Create performance baseline report'},
            
            # Phase 2: Rust Optimization
            {'id': 'H001-VC-6', 'description': 'Implement MinHash LSH in Rust'},
            {'id': 'H001-VC-7', 'description': 'Implement similarity calculation in Rust'},
            {'id': 'H001-VC-8', 'description': 'Implement deduplication in Rust'},
            {'id': 'H001-VC-9', 'description': 'Benchmark Rust implementation'},
            {'id': 'H001-VC-10', 'description': 'Achieve 50× speedup on find_duplicates()'},
            {'id': 'H001-VC-11', 'description': 'Reduce memory usage by 40%'},
            
            # Phase 3: Integration
            {'id': 'H001-VC-12', 'description': 'Wire Rust functions into Python'},
            {'id': 'H001-VC-13', 'description': 'Add fallback to Python implementation'},
            {'id': 'H001-VC-14', 'description': 'Write integration tests'},
            {'id': 'H001-VC-15', 'description': 'Achieve 100% test coverage'},
            
            # Phase 4: Expansion
            {'id': 'H001-VC-16', 'description': 'Optimize all similarity operations'},
            {'id': 'H001-VC-17', 'description': 'Achieve 30× average speedup'},
            {'id': 'H001-VC-18', 'description': 'Document API and usage'},
            {'id': 'H001-VC-19', 'description': 'Deploy to production'},
        ]
    }


def main():
    """Deploy H001 campaign with Immortal Clone v2."""
    logger.info("=" * 80)
    logger.info("H001: EMBEDDINGS HOT PATH OPTIMIZATION")
    logger.info("Immortal Clone v2 - Enhanced Deployment")
    logger.info("=" * 80)
    
    # Load campaign
    campaign = load_h001_campaign()
    
    logger.info(f"\nCampaign: {campaign['name']}")
    logger.info(f"Target: {campaign['target']}")
    logger.info(f"Victory Conditions: {len(campaign['victory_conditions'])}")
    logger.info(f"Target Speedup: {campaign['target_speedup']}×")
    
    # Show VCs
    logger.info("\nVictory Conditions:")
    for vc in campaign['victory_conditions']:
        logger.info(f"  - {vc['id']}: {vc['description']}")
    
    # Deployment configuration
    clone_count = 14000  # Conservative for stability
    max_iterations = 200  # Increased from 50
    
    logger.info(f"\nDeployment Configuration:")
    logger.info(f"  Clones: {clone_count:,}")
    logger.info(f"  Max Iterations: {max_iterations}")
    logger.info(f"  Dashboard: Enabled")
    logger.info(f"  Auto-Completion: Enabled")
    
    # Confirm
    logger.info("\n" + "=" * 80)
    response = input(f"Deploy {clone_count:,} Immortal Clones v2? (yes/no): ")
    if response.lower() not in ['yes', 'y']:
        logger.info("Deployment cancelled.")
        return 0
    
    logger.info("\n🚀 DEPLOYING IMMORTAL CLONE ARMIES V2...")
    logger.info("=" * 80)
    
    # Deploy!
    start_time = time.time()
    
    try:
        results = immortal_clone_deploy(
            campaign=campaign,
            max_clones=clone_count,
            max_iterations=max_iterations,
            dashboard_enabled=True
        )
        
        duration = time.time() - start_time
        
        # Analyze results
        successful = sum(1 for r in results if r.success)
        early_stops = sum(1 for r in results if r.data.get('early_stop'))
        vcs_met = sum(1 for r in results if r.data.get('vcs_met'))
        
        logger.info("\n" + "=" * 80)
        logger.info("H001 DEPLOYMENT COMPLETE")
        logger.info("=" * 80)
        
        logger.info(f"\nDuration: {duration:.1f}s ({duration/60:.1f} minutes)")
        logger.info(f"Clones deployed: {len(results):,}")
        logger.info(f"Successful: {successful:,} ({successful/len(results)*100:.1f}%)")
        logger.info(f"Early stops (campaign complete): {early_stops:,}")
        logger.info(f"VCs achieved: {vcs_met:,}")
        
        # Save results
        results_file = project_root / "reports" / "h001_v2_deployment_results.json"
        with open(results_file, 'w') as f:
            json.dump({
                'campaign_id': 'H001',
                'campaign_name': campaign['name'],
                'duration_seconds': duration,
                'clones_deployed': len(results),
                'successful_clones': successful,
                'early_stops': early_stops,
                'vcs_achieved': vcs_met,
                'results': [
                    {
                        'success': r.success,
                        'duration': r.duration,
                        'error': r.error,
                        'data': r.data
                    }
                    for r in results
                ]
            }, f, indent=2, default=str)
        
        logger.info(f"\nResults saved: {results_file}")
        
        if successful == len(results):
            logger.info("\n🎉 ALL CLONES SUCCESSFUL!")
            return 0
        else:
            logger.info(f"\n⚠️ {len(results) - successful} clones failed")
            return 1
            
    except Exception as e:
        logger.error(f"\n❌ Deployment failed: {e}")
        import traceback
        logger.error(traceback.format_exc())
        return 1


if __name__ == '__main__':
    import time
    sys.exit(main())
