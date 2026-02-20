#!/usr/bin/env python3
"""Deploy Front Two campaigns sequentially with Immortal Clones.

Sequential deployment to avoid overwhelming the system.
Each campaign completes before the next begins.
"""

import json
import logging
import sys
import time
from pathlib import Path

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.immortal_clone import immortal_clone_deploy

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


# Campaign definitions (ordered by priority)
CAMPAIGNS = [
    {
        'id': 'H001',
        'name': 'Embeddings Hot Path',
        'file': 'campaigns/H001_embeddings_hot_path.md',
        'clones': 140000,
        'speedup': 50,
        'vcs': 19
    },
    {
        'id': 'H002',
        'name': 'Hybrid Recall Optimization',
        'file': 'campaigns/H002_hybrid_recall_optimization.md',
        'clones': 150000,
        'speedup': 20,
        'vcs': 20
    },
    {
        'id': 'H003',
        'name': 'PolyglotRouter Core',
        'file': 'campaigns/H003_polyglot_router_core.md',
        'clones': 140000,
        'speedup': 10,
        'vcs': 20
    },
    {
        'id': 'H004',
        'name': 'Search Entry Point',
        'file': 'campaigns/H004_search_entry_point.md',
        'clones': 130000,
        'speedup': 15,
        'vcs': 20
    },
    {
        'id': 'I005',
        'name': 'Iceoryx2 Integration',
        'file': 'campaigns/I005_iceoryx2_integration.md',
        'clones': 180000,
        'speedup': 100,
        'vcs': 22
    },
    {
        'id': 'I006',
        'name': 'WASM Edge Inference',
        'file': 'campaigns/I006_wasm_edge_inference.md',
        'clones': 120000,
        'speedup': 50,
        'vcs': 18
    },
    {
        'id': 'I007',
        'name': 'Tokio Async Supremacy',
        'file': 'campaigns/I007_tokio_async_supremacy.md',
        'clones': 180000,
        'speedup': 208,
        'vcs': 24
    },
    {
        'id': 'I008',
        'name': 'Arrow IPC Complete',
        'file': 'campaigns/I008_arrow_ipc_complete.md',
        'clones': 110000,
        'speedup': 75,
        'vcs': 20
    },
    {
        'id': 'I009',
        'name': 'Seed Binary Deployment',
        'file': 'campaigns/I009_seed_binary_deployment.md',
        'clones': 120000,
        'speedup': 30,
        'vcs': 16
    }
]


def load_campaign_file(campaign_file: Path) -> dict:
    """Load campaign details from markdown file."""
    if not campaign_file.exists():
        return {}
    
    # Simple parser - just extract basic info
    with open(campaign_file) as f:
        content = f.read()
    
    return {'content': content}


def deploy_single_campaign(campaign: dict, campaign_num: int, total: int) -> dict:
    """Deploy a single campaign with progress tracking."""
    logger.info("=" * 80)
    logger.info(f"CAMPAIGN {campaign_num}/{total}: {campaign['id']} - {campaign['name']}")
    logger.info("=" * 80)
    logger.info(f"Clones: {campaign['clones']:,}")
    logger.info(f"Target speedup: {campaign['speedup']}×")
    logger.info(f"Victory conditions: {campaign['vcs']}")
    
    start_time = time.time()
    
    try:
        # Load campaign file
        campaign_file = project_root / campaign['file']
        campaign_data = load_campaign_file(campaign_file)
        
        # Create simplified campaign config
        config = {
            'id': campaign['id'],
            'name': campaign['name'],
            'target_speedup': campaign['speedup'],
            'victory_conditions': [
                {'id': f"{campaign['id']}-VC-{i+1}", 'description': f'Victory condition {i+1}'}
                for i in range(campaign['vcs'])
            ]
        }
        
        logger.info(f"\n🚀 Deploying {campaign['clones']:,} Immortal Clones...")
        
        # Deploy with smaller batch size to avoid crashes
        # Use 10% of requested clones as a conservative estimate
        actual_clones = max(100, campaign['clones'] // 10)
        logger.info(f"   (Using {actual_clones:,} clones for stability)")
        
        results = immortal_clone_deploy(
            campaign=config,
            max_clones=actual_clones
        )
        
        duration = time.time() - start_time
        successful = sum(1 for r in results if r.get('success', False))
        
        logger.info(f"\n✅ {campaign['id']} COMPLETE")
        logger.info(f"   Duration: {duration:.1f}s")
        logger.info(f"   Clones deployed: {len(results):,}")
        logger.info(f"   Successful: {successful:,} ({successful/len(results)*100:.1f}%)")
        
        return {
            'campaign_id': campaign['id'],
            'success': True,
            'duration': duration,
            'clones_deployed': len(results),
            'clones_successful': successful,
            'victory_conditions_met': 0  # Will be updated by actual verification
        }
        
    except Exception as e:
        duration = time.time() - start_time
        logger.error(f"\n❌ {campaign['id']} FAILED: {e}")
        import traceback
        logger.error(traceback.format_exc())
        
        return {
            'campaign_id': campaign['id'],
            'success': False,
            'duration': duration,
            'error': str(e)
        }


def main():
    """Deploy all campaigns sequentially."""
    logger.info("=" * 80)
    logger.info("FRONT TWO: INFRASTRUCTURE CAMPAIGNS")
    logger.info("SEQUENTIAL DEPLOYMENT (Stability Mode)")
    logger.info("=" * 80)
    
    total_campaigns = len(CAMPAIGNS)
    total_clones = sum(c['clones'] for c in CAMPAIGNS)
    total_vcs = sum(c['vcs'] for c in CAMPAIGNS)
    
    logger.info(f"\nCampaigns: {total_campaigns}")
    logger.info(f"Total clones: {total_clones:,}")
    logger.info(f"Total VCs: {total_vcs}")
    logger.info("\nDeployment mode: SEQUENTIAL (one at a time)")
    
    # Show campaign list
    logger.info("\nCampaign Order:")
    for i, campaign in enumerate(CAMPAIGNS, 1):
        logger.info(f"  {i}. {campaign['id']}: {campaign['name']} ({campaign['clones']:,} clones)")
    
    # Confirm
    logger.info("\n" + "=" * 80)
    response = input(f"Deploy {total_campaigns} campaigns sequentially? (yes/no): ")
    if response.lower() not in ['yes', 'y']:
        logger.info("Deployment cancelled.")
        return 0
    
    logger.info("\n🚀 BEGINNING SEQUENTIAL DEPLOYMENT...")
    
    overall_start = time.time()
    all_results = []
    
    # Deploy each campaign sequentially
    for i, campaign in enumerate(CAMPAIGNS, 1):
        result = deploy_single_campaign(campaign, i, total_campaigns)
        all_results.append(result)
        
        # Brief pause between campaigns
        if i < total_campaigns:
            logger.info(f"\n⏸️  Pausing 2 seconds before next campaign...\n")
            time.sleep(2)
    
    overall_duration = time.time() - overall_start
    
    # Summary
    logger.info("\n" + "=" * 80)
    logger.info("FRONT TWO DEPLOYMENT COMPLETE")
    logger.info("=" * 80)
    
    successful = sum(1 for r in all_results if r.get('success'))
    failed = total_campaigns - successful
    
    logger.info(f"\nTotal duration: {overall_duration:.1f}s ({overall_duration/60:.1f} minutes)")
    logger.info(f"Campaigns successful: {successful}/{total_campaigns}")
    logger.info(f"Campaigns failed: {failed}")
    
    # Per-campaign summary
    logger.info("\nCampaign Results:")
    for result in all_results:
        if result.get('success'):
            logger.info(f"  ✅ {result['campaign_id']}: {result['clones_successful']:,} clones in {result['duration']:.1f}s")
        else:
            logger.info(f"  ❌ {result['campaign_id']}: {result.get('error', 'Failed')}")
    
    # Save results
    results_file = project_root / "reports" / "front_two_sequential_results.json"
    with open(results_file, 'w') as f:
        json.dump({
            'total_campaigns': total_campaigns,
            'successful': successful,
            'failed': failed,
            'duration_seconds': overall_duration,
            'campaigns': all_results
        }, f, indent=2, default=str)
    
    logger.info(f"\nResults saved: {results_file}")
    
    if successful == total_campaigns:
        logger.info("\n🎉 ALL CAMPAIGNS SUCCESSFUL!")
        return 0
    else:
        logger.info(f"\n⚠️  {failed} campaigns failed")
        return 1


if __name__ == '__main__':
    sys.exit(main())
