#!/usr/bin/env python3
"""Unified Shadow Clone Army Deployment System

Synthesizes ALL 12 shadow clone army systems into one cohesive deployment interface.
Automatically selects the best army type(s) for each objective.

Usage:
    # Deploy all armies on all objectives
    python3 scripts/deploy_unified_army.py --all
    
    # Deploy specific army type
    python3 scripts/deploy_unified_army.py --army immortal
    python3 scripts/deploy_unified_army.py --army tokio
    python3 scripts/deploy_unified_army.py --army shadow
    
    # Deploy specific lieutenant
    python3 scripts/deploy_unified_army.py --lieutenant security
    python3 scripts/deploy_unified_army.py --lieutenant performance
    
    # Deploy on specific campaign
    python3 scripts/deploy_unified_army.py --campaign H001
    
    # Auto-select best army for objective
    python3 scripts/deploy_unified_army.py --objective "optimize embeddings hot path"
"""

import asyncio
import importlib.util
import logging
import sys
import time
from dataclasses import dataclass, field
from enum import Enum
from pathlib import Path
from typing import Any

project_root = Path(__file__).parent.parent
sys.path.insert(0, str(project_root))

# Import all army systems
from whitemagic.agents.immortal_clone_v2 import immortal_clone_deploy  # type: ignore[import-not-found]  # noqa: E402
from whitemagic.agents.lieutenants import LieutenantCorps, LieutenantDomain  # noqa: E402
from whitemagic.agents.mcp_lieutenants import LIEUTENANT_MCP_TOOLS  # noqa: E402

logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s - %(levelname)s - %(message)s'
)
logger = logging.getLogger(__name__)


class ArmyType(Enum):
    """All available shadow clone army types."""
    IMMORTAL = "immortal"              # Persistent execution loops
    TOKIO = "tokio"                    # Rust massively parallel
    SHADOW = "shadow"                  # Consensus search
    GRAND = "grand"                    # 3-tier Alpha/Beta/Gamma
    WAR_ROOM = "war_room"              # Military campaigns
    ADAPTIVE = "adaptive"              # Tier-based parallelism
    BATCH = "batch"                    # Dependency graph
    THOUGHT = "thought"                # Edge inference
    FILE_SEARCH = "file_search"        # Parallel file search
    ELIXIR = "elixir"                  # Distributed OTP
    CAMPAIGN = "campaign"              # Markdown-driven
    LIEUTENANT = "lieutenant"          # Domain specialists


@dataclass
class ArmyCapability:
    """Capabilities of an army type."""
    name: str
    army_type: ArmyType
    throughput: str
    max_concurrency: int
    languages: list[str]
    specialties: list[str]
    best_for: list[str]


@dataclass
class UnifiedDeployment:
    """A unified deployment across multiple army types."""
    objective: str
    armies_deployed: list[ArmyType] = field(default_factory=list)
    total_clones: int = 0
    total_duration: float = 0.0
    results: dict[str, Any] = field(default_factory=dict)
    victories: int = 0
    findings: list[dict] = field(default_factory=list)


# Army capability matrix
ARMY_CAPABILITIES = {
    ArmyType.IMMORTAL: ArmyCapability(
        name="Immortal Clone System",
        army_type=ArmyType.IMMORTAL,
        throughput="50 clones/sec/core",
        max_concurrency=64,
        languages=["Python"],
        specialties=["Persistent loops", "Real subprocess", "Victory tracking", "Auto-completion"],
        best_for=["Compilation", "Testing", "Benchmarking", "Verification"]
    ),
    ArmyType.TOKIO: ArmyCapability(
        name="Tokio Clone Army",
        army_type=ArmyType.TOKIO,
        throughput="534K clones/sec",
        max_concurrency=100000,
        languages=["Rust"],
        specialties=["Massively parallel", "Async tokio", "Strategy voting", "Sub-ms latency"],
        best_for=["Rapid exploration", "Strategy selection", "Parallel reasoning"]
    ),
    ArmyType.SHADOW: ArmyCapability(
        name="Shadow Clone Army",
        army_type=ArmyType.SHADOW,
        throughput="10K ops/sec",
        max_concurrency=100,
        languages=["Python", "Rust"],
        specialties=["Consensus search", "Expertise weighting", "Diversity bonus", "Multi-perspective"],
        best_for=["Search", "Classification", "Voting", "Consensus"]
    ),
    ArmyType.GRAND: ArmyCapability(
        name="Grand Army System",
        army_type=ArmyType.GRAND,
        throughput="934K clones/sec",
        max_concurrency=240000,
        languages=["Python", "Rust"],
        specialties=["3-tier structure", "Campaign-driven", "Auto-verification", "Full metrics"],
        best_for=["Large campaigns", "Multi-phase operations", "Victory conditions"]
    ),
    ArmyType.LIEUTENANT: ArmyCapability(
        name="Lieutenant System",
        army_type=ArmyType.LIEUTENANT,
        throughput="Variable",
        max_concurrency=765000,
        languages=["Python"],
        specialties=["Domain expertise", "MCP tool authority", "Autonomous decisions", "Resource management"],
        best_for=["Specialized domains", "MCP integration", "Strategic coordination"]
    ),
}


class UnifiedArmyCommander:
    """Unified commander for all shadow clone army systems."""
    
    def __init__(self):
        self.lieutenant_corps = LieutenantCorps()
        self.deployments: list[UnifiedDeployment] = []
        
        # Check available systems
        self.available_armies = self._check_available_armies()
        logger.info(f"Available armies: {[a.value for a in self.available_armies]}")
    
    def _check_available_armies(self) -> list[ArmyType]:
        """Check which army systems are available."""
        available = [ArmyType.IMMORTAL, ArmyType.LIEUTENANT]  # Always available
        
        # Check Rust
        try:
            import whitemagic_rs
            if hasattr(whitemagic_rs, 'tokio_deploy_clones'):
                available.append(ArmyType.TOKIO)
        except ImportError:
            pass
        
        # Check other systems
        try:
            if importlib.util.find_spec("whitemagic.core.intelligence.agentic.clone_army") is not None:
                available.append(ArmyType.SHADOW)
        except ImportError:
            pass
        
        try:
            if importlib.util.find_spec("whitemagic.agents.war_room") is not None:
                available.append(ArmyType.WAR_ROOM)
        except ImportError:
            pass
        
        return available
    
    def select_best_army(self, objective: str, requirements: dict[str, Any] | None = None) -> list[ArmyType]:
        """Auto-select best army type(s) for an objective.
        
        Args:
            objective: The objective description
            requirements: Optional requirements (throughput, concurrency, etc.)
        
        Returns:
            List of recommended army types (can deploy multiple)
        """
        obj_lower = objective.lower()
        selected = []
        
        # Keyword-based selection
        if any(kw in obj_lower for kw in ["compile", "test", "benchmark", "verify"]):
            selected.append(ArmyType.IMMORTAL)
        
        if any(kw in obj_lower for kw in ["search", "find", "discover", "explore"]):
            selected.append(ArmyType.SHADOW)
        
        if any(kw in obj_lower for kw in ["fast", "rapid", "massive", "parallel", "scale"]):
            if ArmyType.TOKIO in self.available_armies:
                selected.append(ArmyType.TOKIO)
        
        if any(kw in obj_lower for kw in ["security", "vulnerability", "sql", "injection"]):
            selected.append(ArmyType.LIEUTENANT)
        
        if any(kw in obj_lower for kw in ["performance", "optimize", "accelerate", "hot path"]):
            selected.append(ArmyType.LIEUTENANT)
        
        # Default to Immortal if nothing selected
        if not selected:
            selected.append(ArmyType.IMMORTAL)
        
        # Filter to available
        selected = [a for a in selected if a in self.available_armies]
        
        return selected
    
    async def deploy_immortal_army(
        self,
        objective: str,
        campaign: dict[str, Any],
        max_clones: int = 10,
        max_iterations: int = 20
    ) -> dict[str, Any]:
        """Deploy Immortal Clone army."""
        logger.info(f"🥷 Deploying Immortal Clone Army: {objective}")
        
        start_time = time.time()
        results = immortal_clone_deploy(
            campaign=campaign,
            max_clones=max_clones,
            max_iterations=max_iterations,
            dashboard_enabled=False
        )
        duration = time.time() - start_time
        
        successful = sum(1 for r in results if r.success)
        
        return {
            'army_type': 'immortal',
            'clones_deployed': len(results),
            'successful': successful,
            'success_rate': successful / len(results) if results else 0.0,
            'duration': duration,
            'throughput': len(results) / duration if duration > 0 else 0.0,
            'results': results
        }
    
    async def deploy_tokio_army(
        self,
        objective: str,
        num_clones: int = 1000,
        strategies: list[str] | None = None
    ) -> dict[str, Any]:
        """Deploy Tokio Clone Army (Rust)."""
        logger.info(f"🦀 Deploying Tokio Clone Army: {objective}")
        
        try:
            from whitemagic.optimization.rust_accelerators import tokio_deploy_clones
            
            result = tokio_deploy_clones(
                objective,
                num_clones,
                strategies or ["direct", "chain_of_thought", "analytical", "creative", "synthesis"]
            )
            
            if result:
                return {
                    'army_type': 'tokio',
                    'clones_deployed': result.get('total_clones', 0),
                    'winner_strategy': result.get('winner', {}).get('strategy', 'unknown'),
                    'avg_confidence': result.get('avg_confidence', 0.0),
                    'duration': result.get('elapsed_ms', 0) / 1000.0,
                    'throughput': result.get('total_clones', 0) / (result.get('elapsed_ms', 1) / 1000.0),
                    'results': result
                }
        except Exception as e:
            logger.error(f"Tokio deployment failed: {e}")
        
        return {
            'army_type': 'tokio',
            'clones_deployed': 0,
            'error': 'Tokio unavailable',
            'duration': 0.0
        }
    
    async def deploy_shadow_army(
        self,
        objective: str,
        army_size: int = 50,
        top_k: int = 10
    ) -> dict[str, Any]:
        """Deploy Shadow Clone Army (consensus search)."""
        logger.info(f"👥 Deploying Shadow Clone Army: {objective}")
        
        try:
            from whitemagic.core.intelligence.agentic.clone_army import get_clone_army
            
            army = get_clone_army()
            start_time = time.time()
            results = await army.deploy_search(objective, army_size=army_size, top_k=top_k)
            duration = time.time() - start_time
            
            return {
                'army_type': 'shadow',
                'clones_deployed': army_size,
                'results_found': len(results),
                'top_consensus': results[0].consensus_score if results else 0.0,
                'duration': duration,
                'throughput': army_size / duration if duration > 0 else 0.0,
                'results': results
            }
        except Exception as e:
            logger.error(f"Shadow army deployment failed: {e}")
        
        return {
            'army_type': 'shadow',
            'clones_deployed': 0,
            'error': 'Shadow army unavailable',
            'duration': 0.0
        }
    
    async def deploy_lieutenant(
        self,
        objective: str,
        domain: LieutenantDomain,
        campaign_code: str = "UNIFIED-001"
    ) -> dict[str, Any]:
        """Deploy via Lieutenant system."""
        logger.info(f"👨‍✈️ Deploying Lieutenant {domain.value}: {objective}")
        
        lieutenant = self.lieutenant_corps.get_lieutenant(domain)
        if not lieutenant:
            return {'error': f'Lieutenant {domain.value} not found'}
        
        # Assign campaign
        lieutenant.assign_campaign(campaign_code, 10000)  # 10K clone budget
        
        # Get MCP tools for this lieutenant
        tools = LIEUTENANT_MCP_TOOLS.get(domain, [])
        
        return {
            'army_type': 'lieutenant',
            'lieutenant': lieutenant.name,
            'domain': domain.value,
            'clone_budget': 10000,
            'mcp_tools': len(tools),
            'expertise': lieutenant.expertise,
            'status': 'deployed'
        }
    
    async def deploy_unified(
        self,
        objective: str,
        auto_select: bool = True,
        armies: list[ArmyType] | None = None,
        max_clones: int = 10,
    ) -> UnifiedDeployment:
        """Deploy unified army (multiple types in parallel).
        
        Args:
            objective: The objective to achieve
            auto_select: Auto-select best armies
            armies: Specific armies to deploy (if not auto-selecting)
            max_clones: Max clones per army
        
        Returns:
            UnifiedDeployment with results from all armies
        """
        deployment = UnifiedDeployment(objective=objective)
        
        # Select armies
        if auto_select:
            selected_armies = self.select_best_army(objective)
        else:
            selected_armies = armies or [ArmyType.IMMORTAL]
        
        logger.info(f"🎯 Unified Deployment: {objective}")
        logger.info(f"   Selected armies: {[a.value for a in selected_armies]}")
        
        # Deploy all armies in parallel
        tasks = []
        for army_type in selected_armies:
            if army_type == ArmyType.IMMORTAL:
                campaign = {
                    'id': 'UNIFIED-001',
                    'name': objective,
                    'target': 'unified-target',
                    'victory_conditions': [
                        {'id': 'VC-1', 'description': 'Objective achieved'}
                    ]
                }
                tasks.append(self.deploy_immortal_army(objective, campaign, max_clones))
            
            elif army_type == ArmyType.TOKIO:
                tasks.append(self.deploy_tokio_army(objective, max_clones * 100))
            
            elif army_type == ArmyType.SHADOW:
                tasks.append(self.deploy_shadow_army(objective, max_clones * 5))
            
            elif army_type == ArmyType.LIEUTENANT:
                # Auto-select lieutenant domain based on objective
                domain = LieutenantDomain.DISCOVERY  # Default
                if "security" in objective.lower():
                    domain = LieutenantDomain.SECURITY
                elif "performance" in objective.lower():
                    domain = LieutenantDomain.PERFORMANCE
                elif "intelligence" in objective.lower():
                    domain = LieutenantDomain.INTELLIGENCE
                
                tasks.append(self.deploy_lieutenant(objective, domain))
        
        # Execute all deployments
        results = await asyncio.gather(*tasks, return_exceptions=True)
        
        # Aggregate results
        for army_type, result in zip(selected_armies, results):
            if isinstance(result, Exception):
                logger.error(f"Army {army_type.value} failed: {result}")
                continue
            
            deployment.armies_deployed.append(army_type)
            deployment.total_clones += result.get('clones_deployed', 0)
            deployment.total_duration += result.get('duration', 0.0)
            deployment.results[army_type.value] = result
        
        self.deployments.append(deployment)
        
        return deployment
    
    def generate_report(self) -> str:
        """Generate unified deployment report."""
        report = ["# Unified Shadow Clone Army Deployment Report\n"]
        report.append(f"**Total Deployments**: {len(self.deployments)}\n")
        
        for i, deployment in enumerate(self.deployments, 1):
            report.append(f"## Deployment {i}: {deployment.objective}\n")
            report.append(f"**Armies**: {', '.join(a.value for a in deployment.armies_deployed)}")
            report.append(f"**Total Clones**: {deployment.total_clones:,}")
            report.append(f"**Total Duration**: {deployment.total_duration:.2f}s")
            report.append(f"**Avg Throughput**: {deployment.total_clones / deployment.total_duration:.1f} clones/sec\n" if deployment.total_duration > 0 else "")
            
            for army_type, result in deployment.results.items():
                report.append(f"### {army_type.title()} Results")
                report.append(f"- Clones: {result.get('clones_deployed', 0):,}")
                report.append(f"- Duration: {result.get('duration', 0):.2f}s")
                if 'success_rate' in result:
                    report.append(f"- Success Rate: {result['success_rate']*100:.1f}%")
                if 'winner_strategy' in result:
                    report.append(f"- Winner: {result['winner_strategy']}")
                report.append("")
        
        return "\n".join(report)


async def main():
    """Main entry point."""
    import argparse
    
    parser = argparse.ArgumentParser(description="Unified Shadow Clone Army Deployment")
    parser.add_argument('--all', action='store_true', help="Deploy all armies")
    parser.add_argument('--army', type=str, help="Deploy specific army type")
    parser.add_argument('--lieutenant', type=str, help="Deploy specific lieutenant")
    parser.add_argument('--campaign', type=str, help="Deploy specific campaign")
    parser.add_argument('--objective', type=str, help="Deploy on objective (auto-select armies)")
    parser.add_argument('--clones', type=int, default=10, help="Max clones per army")
    
    args = parser.parse_args()
    
    commander = UnifiedArmyCommander()
    
    print("="*80)
    print("🎯 UNIFIED SHADOW CLONE ARMY DEPLOYMENT SYSTEM")
    print("="*80)
    print(f"Available armies: {len(commander.available_armies)}")
    for army in commander.available_armies:
        cap = ARMY_CAPABILITIES.get(army)
        if cap:
            print(f"  - {cap.name} ({cap.throughput})")
    print("="*80)
    print()
    
    if args.objective:
        # Auto-select and deploy
        deployment = await commander.deploy_unified(
            args.objective,
            auto_select=True,
            max_clones=args.clones
        )
        
        print("\n✅ Deployment Complete!")
        print(f"   Objective: {deployment.objective}")
        print(f"   Armies: {', '.join(a.value for a in deployment.armies_deployed)}")
        print(f"   Total Clones: {deployment.total_clones:,}")
        print(f"   Duration: {deployment.total_duration:.2f}s")
        
    elif args.all:
        # Deploy all available armies on test objective
        test_objective = "Test unified deployment across all army types"
        deployment = await commander.deploy_unified(
            test_objective,
            auto_select=False,
            armies=commander.available_armies,
            max_clones=args.clones
        )
        
        print("\n✅ All Armies Deployed!")
        print(f"   Total Clones: {deployment.total_clones:,}")
        print(f"   Duration: {deployment.total_duration:.2f}s")
    
    else:
        print("Usage: python3 scripts/deploy_unified_army.py --objective 'your objective'")
        print("   or: python3 scripts/deploy_unified_army.py --all")
        return 1
    
    # Generate report
    report = commander.generate_report()
    report_path = project_root / "reports" / f"unified_deployment_{int(time.time())}.md"
    report_path.write_text(report)
    print(f"\n📄 Report saved: {report_path}")
    
    return 0


if __name__ == '__main__':
    sys.exit(asyncio.run(main()))
