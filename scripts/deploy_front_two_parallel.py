#!/usr/bin/env python3
"""Deploy all Front Two campaigns in parallel with Immortal Clones.

Front Two: Infrastructure Campaigns (H001-H004, I005-I009)
- 9 campaigns total
- 1,270,000 total clones
- Parallel execution for maximum throughput
"""

import json
import logging
import sys
import time
from concurrent.futures import ProcessPoolExecutor, as_completed
from pathlib import Path

# Add project root to path
project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.immortal_clone import immortal_clone_deploy  # noqa: E402

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


# Campaign definitions
FRONT_TWO_CAMPAIGNS = {
    'H001': {
        'name': 'Embeddings Hot Path',
        'target': 'whitemagic/core/memory/embeddings.py',
        'clones': 140000,
        'expected_speedup': 50,
        'vcs': 19
    },
    'H002': {
        'name': 'Hybrid Recall Optimization',
        'target': 'whitemagic/core/memory/unified.py',
        'clones': 150000,
        'expected_speedup': 20,
        'vcs': 20
    },
    'H003': {
        'name': 'PolyglotRouter Core',
        'target': 'whitemagic/optimization/polyglot_router.py',
        'clones': 140000,
        'expected_speedup': 10,
        'vcs': 20
    },
    'H004': {
        'name': 'Search Entry Point',
        'target': 'whitemagic/tools/search.py',
        'clones': 130000,
        'expected_speedup': 15,
        'vcs': 20
    },
    'I005': {
        'name': 'Iceoryx2 Integration',
        'target': 'whitemagic-rust/src/ipc/',
        'clones': 180000,
        'expected_speedup': 100,
        'vcs': 22
    },
    'I006': {
        'name': 'WASM Edge Inference',
        'target': 'whitemagic-rust/src/wasm/',
        'clones': 120000,
        'expected_speedup': 50,
        'vcs': 18
    },
    'I007': {
        'name': 'Tokio Async Supremacy',
        'target': 'whitemagic-rust/src/async/',
        'clones': 180000,
        'expected_speedup': 208,
        'vcs': 24
    },
    'I008': {
        'name': 'Arrow IPC Complete',
        'target': 'whitemagic-rust/src/arrow/',
        'clones': 110000,
        'expected_speedup': 75,
        'vcs': 20
    },
    'I009': {
        'name': 'Seed Binary Deployment',
        'target': 'whitemagic-rust/src/bin/',
        'clones': 120000,
        'expected_speedup': 30,
        'vcs': 16
    }
}


def deploy_campaign(campaign_id: str, config: dict) -> dict:
    """Deploy a single campaign with Immortal Clones."""
    logger.info(f"🚀 Starting {campaign_id}: {config['name']}")
    logger.info(f"   Target: {config['target']}")
    logger.info(f"   Clones: {config['clones']:,}")
    logger.info(f"   Expected speedup: {config['expected_speedup']}×")

    start_time = time.time()

    try:
        # Create campaign configuration
        campaign = {
            'id': campaign_id,
            'name': config['name'],
            'target': config['target'],
            'expected_speedup': config['expected_speedup'],
            'clone_count': config['clones'],
            'victory_conditions': [
                {'id': f"{campaign_id}-VC-{i+1}", 'type': 'optimize', 'target': f'vc_{i+1}'}
                for i in range(config['vcs'])
            ]
        }

        # Deploy Immortal Clones
        results = immortal_clone_deploy(
            campaign=campaign,
            max_clones=config['clones']
        )

        duration = time.time() - start_time
        successful = sum(1 for r in results if r.success)

        logger.info(f"✅ {campaign_id} complete in {duration:.1f}s")
        logger.info(f"   Success rate: {successful}/{len(results)} ({successful/len(results)*100:.1f}%)")

        return {
            'campaign_id': campaign_id,
            'success': True,
            'duration': duration,
            'total_clones': len(results),
            'successful_clones': successful,
            'results': results
        }

    except Exception as e:
        duration = time.time() - start_time
        logger.error(f"❌ {campaign_id} failed after {duration:.1f}s: {e}")
        return {
            'campaign_id': campaign_id,
            'success': False,
            'duration': duration,
            'error': str(e)
        }


def main():
    """Deploy all Front Two campaigns in parallel."""
    logger.info("=" * 80)
    logger.info("FRONT TWO: INFRASTRUCTURE CAMPAIGNS - PARALLEL DEPLOYMENT")
    logger.info("=" * 80)

    # Summary
    total_campaigns = len(FRONT_TWO_CAMPAIGNS)
    total_clones = sum(c['clones'] for c in FRONT_TWO_CAMPAIGNS.values())
    total_vcs = sum(c['vcs'] for c in FRONT_TWO_CAMPAIGNS.values())

    logger.info(f"\nCampaigns: {total_campaigns}")
    logger.info(f"Total clones: {total_clones:,}")
    logger.info(f"Total victory conditions: {total_vcs}")

    # Show campaign breakdown
    logger.info("\nCampaign Breakdown:")
    for campaign_id, config in FRONT_TWO_CAMPAIGNS.items():
        logger.info(f"  {campaign_id}: {config['name']}")
        logger.info(f"    Clones: {config['clones']:,}")
        logger.info(f"    Target speedup: {config['expected_speedup']}×")
        logger.info(f"    VCs: {config['vcs']}")

    # Confirm deployment
    logger.info("\n" + "=" * 80)
    response = input(f"Deploy {total_clones:,} Immortal Clones across {total_campaigns} campaigns in PARALLEL? (yes/no): ")
    if response.lower() not in ['yes', 'y']:
        logger.info("Deployment cancelled.")
        return 0

    logger.info("\n🚀 DEPLOYING IMMORTAL CLONE ARMIES IN PARALLEL...")
    logger.info("=" * 80)

    start_time = time.time()
    all_results = []

    # Deploy campaigns in parallel
    # Use min(cpu_count, num_campaigns) workers to avoid overwhelming system
    import multiprocessing
    max_workers = min(multiprocessing.cpu_count(), total_campaigns)

    logger.info(f"\nUsing {max_workers} parallel workers for {total_campaigns} campaigns")

    with ProcessPoolExecutor(max_workers=max_workers) as executor:
        # Submit all campaigns
        futures = {
            executor.submit(deploy_campaign, campaign_id, config): campaign_id
            for campaign_id, config in FRONT_TWO_CAMPAIGNS.items()
        }

        # Collect results as they complete
        for future in as_completed(futures):
            campaign_id = futures[future]
            try:
                result = future.result()
                all_results.append(result)
            except Exception as e:
                logger.error(f"❌ {campaign_id} exception: {e}")
                all_results.append({
                    'campaign_id': campaign_id,
                    'success': False,
                    'error': str(e)
                })

    total_duration = time.time() - start_time

    # Analyze results
    logger.info("\n" + "=" * 80)
    logger.info("FRONT TWO DEPLOYMENT RESULTS")
    logger.info("=" * 80)

    successful_campaigns = sum(1 for r in all_results if r.get('success'))
    failed_campaigns = total_campaigns - successful_campaigns

    logger.info(f"\nTotal duration: {total_duration:.1f}s ({total_duration/60:.1f} minutes)")
    logger.info(f"Campaigns completed: {successful_campaigns}/{total_campaigns} ({successful_campaigns/total_campaigns*100:.1f}%)")
    logger.info(f"Failed campaigns: {failed_campaigns}")

    # Per-campaign results
    logger.info("\nPer-Campaign Results:")
    for result in sorted(all_results, key=lambda x: x['campaign_id']):
        campaign_id = result['campaign_id']
        if result.get('success'):
            success_rate = result['successful_clones'] / result['total_clones'] * 100
            logger.info(f"  ✅ {campaign_id}: {result['successful_clones']:,}/{result['total_clones']:,} clones ({success_rate:.1f}%) in {result['duration']:.1f}s")
        else:
            logger.info(f"  ❌ {campaign_id}: FAILED - {result.get('error', 'Unknown error')}")

    # Calculate total clone statistics
    total_clones_deployed = sum(r.get('total_clones', 0) for r in all_results if r.get('success'))
    total_clones_successful = sum(r.get('successful_clones', 0) for r in all_results if r.get('success'))

    if total_clones_deployed > 0:
        overall_success_rate = total_clones_successful / total_clones_deployed * 100
        logger.info(f"\nOverall Clone Success Rate: {total_clones_successful:,}/{total_clones_deployed:,} ({overall_success_rate:.1f}%)")
        logger.info(f"Throughput: {total_clones_deployed/total_duration:.0f} clones/second")

    # Save results
    results_file = project_root / "reports" / "front_two_deployment_results.json"
    results_data = {
        'total_campaigns': total_campaigns,
        'successful_campaigns': successful_campaigns,
        'failed_campaigns': failed_campaigns,
        'total_duration_seconds': total_duration,
        'total_clones_deployed': total_clones_deployed,
        'total_clones_successful': total_clones_successful,
        'campaigns': all_results
    }

    with open(results_file, 'w') as f:
        json.dump(results_data, f, indent=2, default=str)

    logger.info(f"\nResults saved to: {results_file}")

    # Final status
    if successful_campaigns == total_campaigns:
        logger.info("\n🎉 FRONT TWO COMPLETE! All campaigns successful!")
        return 0
    else:
        logger.info(f"\n⚠️ Front Two incomplete: {failed_campaigns} campaigns failed")
        return 1


if __name__ == '__main__':
    sys.exit(main())
