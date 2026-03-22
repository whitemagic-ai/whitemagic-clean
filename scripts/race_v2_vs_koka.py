#!/usr/bin/env python3
"""Race Deployment: Python v2 vs Koka Prototype

Deploy both systems on the same Front Two objectives and compare performance.
"""

import json
import logging
import subprocess
import sys
import time
from concurrent.futures import ThreadPoolExecutor, as_completed
from dataclasses import dataclass, asdict
from pathlib import Path
from typing import List

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

from whitemagic.agents.immortal_clone_v2 import immortal_clone_deploy

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


@dataclass
class RaceResult:
    """Results from a single deployment."""
    system: str  # "python_v2" or "koka"
    campaign_id: str
    campaign_name: str
    start_time: float
    end_time: float
    duration: float
    clones_deployed: int
    iterations_total: int
    vcs_met: int
    vcs_total: int
    success_rate: float
    throughput: float  # clones/sec
    early_termination: bool
    error: str = None


# Front Two campaigns (simplified for testing)
FRONT_TWO_CAMPAIGNS = [
    {
        'id': 'TEST-H001',
        'name': 'Embeddings Hot Path Test',
        'target': 'whitemagic/core/memory/embeddings.py',
        'victory_conditions': [
            {'id': 'H001-VC-1', 'description': 'Profile execution'},
            {'id': 'H001-VC-2', 'description': 'Identify hot paths'},
            {'id': 'H001-VC-3', 'description': 'Measure baseline'},
        ]
    },
    {
        'id': 'TEST-H002',
        'name': 'Graph Walker Optimization Test',
        'target': 'whitemagic/core/intelligence/graph/walker.py',
        'victory_conditions': [
            {'id': 'H002-VC-1', 'description': 'Profile graph traversal'},
            {'id': 'H002-VC-2', 'description': 'Optimize hot loops'},
            {'id': 'H002-VC-3', 'description': 'Benchmark improvements'},
        ]
    },
]


def deploy_python_v2(campaign: dict, max_clones: int, max_iterations: int) -> RaceResult:
    """Deploy using Python v2 system."""
    logger.info(f"🐍 Python v2 deploying: {campaign['name']}")
    
    start_time = time.time()
    
    try:
        results = immortal_clone_deploy(
            campaign=campaign,
            max_clones=max_clones,
            max_iterations=max_iterations,
            dashboard_enabled=False  # Disable for cleaner comparison
        )
        
        end_time = time.time()
        duration = end_time - start_time
        
        # Calculate metrics
        successful = sum(1 for r in results if r.success)
        total_iterations = sum(r.data.get('iterations', 0) for r in results if r.data)
        early_stops = sum(1 for r in results if r.data.get('early_stop', False))
        
        # Mock VC tracking for test (in real deployment, would check actual VCs)
        vcs_met = min(len(campaign['victory_conditions']), successful)
        
        return RaceResult(
            system='python_v2',
            campaign_id=campaign['id'],
            campaign_name=campaign['name'],
            start_time=start_time,
            end_time=end_time,
            duration=duration,
            clones_deployed=len(results),
            iterations_total=total_iterations,
            vcs_met=vcs_met,
            vcs_total=len(campaign['victory_conditions']),
            success_rate=successful / len(results) if results else 0.0,
            throughput=len(results) / duration if duration > 0 else 0.0,
            early_termination=early_stops > 0
        )
    
    except Exception as e:
        end_time = time.time()
        logger.error(f"Python v2 deployment failed: {e}")
        return RaceResult(
            system='python_v2',
            campaign_id=campaign['id'],
            campaign_name=campaign['name'],
            start_time=start_time,
            end_time=end_time,
            duration=end_time - start_time,
            clones_deployed=0,
            iterations_total=0,
            vcs_met=0,
            vcs_total=len(campaign['victory_conditions']),
            success_rate=0.0,
            throughput=0.0,
            early_termination=False,
            error=str(e)
        )


def deploy_koka(campaign: dict, max_clones: int, max_iterations: int) -> RaceResult:
    """Deploy using Koka prototype."""
    logger.info(f"🔮 Koka deploying: {campaign['name']}")
    
    start_time = time.time()
    
    try:
        # Run multiple Koka clones in parallel
        koka_binary = project_root / "koka-clones/.koka/v3.2.2/gcc-debug-4b9ae4/minimal_dash_clone__main"
        
        if not koka_binary.exists():
            raise FileNotFoundError(f"Koka binary not found: {koka_binary}")
        
        results = []
        with ThreadPoolExecutor(max_workers=min(max_clones, 8)) as executor:
            futures = []
            for clone_id in range(max_clones):
                future = executor.submit(run_koka_clone, koka_binary, clone_id, max_iterations)
                futures.append(future)
            
            for future in as_completed(futures):
                try:
                    result = future.result(timeout=60)
                    results.append(result)
                except Exception as e:
                    logger.error(f"Koka clone failed: {e}")
                    results.append({'success': False, 'error': str(e)})
        
        end_time = time.time()
        duration = end_time - start_time
        
        # Calculate metrics
        successful = sum(1 for r in results if r.get('success', False))
        total_iterations = sum(r.get('iterations', 0) for r in results)
        
        # Mock VC tracking
        vcs_met = min(len(campaign['victory_conditions']), successful)
        
        return RaceResult(
            system='koka',
            campaign_id=campaign['id'],
            campaign_name=campaign['name'],
            start_time=start_time,
            end_time=end_time,
            duration=duration,
            clones_deployed=len(results),
            iterations_total=total_iterations,
            vcs_met=vcs_met,
            vcs_total=len(campaign['victory_conditions']),
            success_rate=successful / len(results) if results else 0.0,
            throughput=len(results) / duration if duration > 0 else 0.0,
            early_termination=False  # Koka prototype doesn't have early termination yet
        )
    
    except Exception as e:
        end_time = time.time()
        logger.error(f"Koka deployment failed: {e}")
        return RaceResult(
            system='koka',
            campaign_id=campaign['id'],
            campaign_name=campaign['name'],
            start_time=start_time,
            end_time=end_time,
            duration=end_time - start_time,
            clones_deployed=0,
            iterations_total=0,
            vcs_met=0,
            vcs_total=len(campaign['victory_conditions']),
            success_rate=0.0,
            throughput=0.0,
            early_termination=False,
            error=str(e)
        )


def run_koka_clone(binary_path: Path, clone_id: int, max_iterations: int) -> dict:
    """Run a single Koka clone."""
    try:
        result = subprocess.run(
            [str(binary_path)],
            capture_output=True,
            text=True,
            timeout=30,
            cwd=binary_path.parent
        )
        
        # Parse output to extract results
        success = result.returncode == 0 and "✅" in result.stdout
        
        # Extract iteration count from output
        iterations = max_iterations
        if "Iterations:" in result.stdout:
            try:
                iterations = int(result.stdout.split("Iterations:")[1].split()[0])
            except:
                pass
        
        return {
            'success': success,
            'iterations': iterations,
            'stdout': result.stdout,
            'stderr': result.stderr
        }
    
    except subprocess.TimeoutExpired:
        return {'success': False, 'iterations': 0, 'error': 'Timeout'}
    except Exception as e:
        return {'success': False, 'iterations': 0, 'error': str(e)}


def compare_results(python_results: List[RaceResult], koka_results: List[RaceResult]) -> dict:
    """Compare Python v2 vs Koka results."""
    
    comparison = {
        'python_v2': {
            'total_duration': sum(r.duration for r in python_results),
            'avg_duration': sum(r.duration for r in python_results) / len(python_results) if python_results else 0,
            'total_clones': sum(r.clones_deployed for r in python_results),
            'total_iterations': sum(r.iterations_total for r in python_results),
            'avg_throughput': sum(r.throughput for r in python_results) / len(python_results) if python_results else 0,
            'total_vcs_met': sum(r.vcs_met for r in python_results),
            'avg_success_rate': sum(r.success_rate for r in python_results) / len(python_results) if python_results else 0,
        },
        'koka': {
            'total_duration': sum(r.duration for r in koka_results),
            'avg_duration': sum(r.duration for r in koka_results) / len(koka_results) if koka_results else 0,
            'total_clones': sum(r.clones_deployed for r in koka_results),
            'total_iterations': sum(r.iterations_total for r in koka_results),
            'avg_throughput': sum(r.throughput for r in koka_results) / len(koka_results) if koka_results else 0,
            'total_vcs_met': sum(r.vcs_met for r in koka_results),
            'avg_success_rate': sum(r.success_rate for r in koka_results) / len(koka_results) if koka_results else 0,
        }
    }
    
    # Calculate speedup
    if comparison['python_v2']['avg_duration'] > 0:
        comparison['speedup'] = {
            'duration': comparison['python_v2']['avg_duration'] / comparison['koka']['avg_duration'] if comparison['koka']['avg_duration'] > 0 else 0,
            'throughput': comparison['koka']['avg_throughput'] / comparison['python_v2']['avg_throughput'] if comparison['python_v2']['avg_throughput'] > 0 else 0,
        }
    
    return comparison


def print_results(python_results: List[RaceResult], koka_results: List[RaceResult], comparison: dict):
    """Print race results in a nice format."""
    
    print("\n" + "="*80)
    print("🏁 RACE RESULTS: Python v2 vs Koka")
    print("="*80)
    
    print("\n📊 PYTHON V2 RESULTS")
    print("-"*80)
    for r in python_results:
        print(f"  Campaign: {r.campaign_name}")
        print(f"    Duration: {r.duration:.2f}s")
        print(f"    Clones: {r.clones_deployed}")
        print(f"    Iterations: {r.iterations_total}")
        print(f"    VCs Met: {r.vcs_met}/{r.vcs_total}")
        print(f"    Success Rate: {r.success_rate*100:.1f}%")
        print(f"    Throughput: {r.throughput:.1f} clones/sec")
        if r.error:
            print(f"    ❌ Error: {r.error}")
        print()
    
    print("\n🔮 KOKA RESULTS")
    print("-"*80)
    for r in koka_results:
        print(f"  Campaign: {r.campaign_name}")
        print(f"    Duration: {r.duration:.2f}s")
        print(f"    Clones: {r.clones_deployed}")
        print(f"    Iterations: {r.iterations_total}")
        print(f"    VCs Met: {r.vcs_met}/{r.vcs_total}")
        print(f"    Success Rate: {r.success_rate*100:.1f}%")
        print(f"    Throughput: {r.throughput:.1f} clones/sec")
        if r.error:
            print(f"    ❌ Error: {r.error}")
        print()
    
    print("\n⚡ COMPARISON")
    print("-"*80)
    py = comparison['python_v2']
    kk = comparison['koka']
    
    print("  Total Duration:")
    print(f"    Python v2: {py['total_duration']:.2f}s")
    print(f"    Koka:      {kk['total_duration']:.2f}s")
    
    print("\n  Average Duration per Campaign:")
    print(f"    Python v2: {py['avg_duration']:.2f}s")
    print(f"    Koka:      {kk['avg_duration']:.2f}s")
    
    print("\n  Average Throughput:")
    print(f"    Python v2: {py['avg_throughput']:.1f} clones/sec")
    print(f"    Koka:      {kk['avg_throughput']:.1f} clones/sec")
    
    print("\n  Total VCs Met:")
    print(f"    Python v2: {py['total_vcs_met']}")
    print(f"    Koka:      {kk['total_vcs_met']}")
    
    if 'speedup' in comparison:
        speedup = comparison['speedup']
        print("\n  🚀 SPEEDUP:")
        print(f"    Duration: {speedup['duration']:.2f}× faster" if speedup['duration'] > 1 else f"    Duration: {1/speedup['duration']:.2f}× slower")
        print(f"    Throughput: {speedup['throughput']:.2f}× faster" if speedup['throughput'] > 1 else f"    Throughput: {1/speedup['throughput']:.2f}× slower")
    
    print("\n" + "="*80)


def main():
    """Run the race!"""
    
    print("🏁 IMMORTAL CLONE RACE: Python v2 vs Koka")
    print("="*80)
    print(f"Campaigns: {len(FRONT_TWO_CAMPAIGNS)}")
    print("Clones per campaign: 10 (test size)")
    print("Max iterations: 20")
    print("="*80)
    
    # Configuration
    max_clones = 10  # Small for testing
    max_iterations = 20
    
    python_results = []
    koka_results = []
    
    # Run races for each campaign
    for campaign in FRONT_TWO_CAMPAIGNS:
        print(f"\n🏁 Racing on: {campaign['name']}")
        print("-"*80)
        
        # Deploy both systems
        with ThreadPoolExecutor(max_workers=2) as executor:
            py_future = executor.submit(deploy_python_v2, campaign, max_clones, max_iterations)
            kk_future = executor.submit(deploy_koka, campaign, max_clones, max_iterations)
            
            py_result = py_future.result()
            kk_result = kk_future.result()
            
            python_results.append(py_result)
            koka_results.append(kk_result)
        
        print(f"  Python v2: {py_result.duration:.2f}s, {py_result.throughput:.1f} clones/sec")
        print(f"  Koka:      {kk_result.duration:.2f}s, {kk_result.throughput:.1f} clones/sec")
    
    # Compare results
    comparison = compare_results(python_results, koka_results)
    
    # Print results
    print_results(python_results, koka_results, comparison)
    
    # Save results
    results_file = project_root / "reports" / f"race_results_{int(time.time())}.json"
    with open(results_file, 'w') as f:
        json.dump({
            'python_v2': [asdict(r) for r in python_results],
            'koka': [asdict(r) for r in koka_results],
            'comparison': comparison
        }, f, indent=2)
    
    print(f"\n💾 Results saved to: {results_file}")
    
    return 0 if all(r.error is None for r in python_results + koka_results) else 1


if __name__ == '__main__':
    sys.exit(main())
