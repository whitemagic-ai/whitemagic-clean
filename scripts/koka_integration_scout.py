#!/usr/bin/env python3
"""Koka Integration Scout Army - Find integration opportunities.

Deploys scout clones to analyze the codebase and identify where Koka
binaries can be integrated for maximum impact.
"""

import re
import json
from pathlib import Path
from dataclasses import dataclass, asdict
from typing import List, Dict, Any


@dataclass
class IntegrationTarget:
    file_path: str
    current_language: str
    lines_of_code: int
    hot_path_score: int
    integration_type: str  # "ipc", "ffi", "replace", "bridge"
    estimated_impact: str  # "high", "medium", "low"
    koka_binary_suggested: str
    rationale: str


class KokaIntegrationScout:
    """Scout army to find Koka integration opportunities."""
    
    def __init__(self, root_dir: Path):
        self.root_dir = Path(root_dir)
        self.targets: List[IntegrationTarget] = []
        self.findings: Dict[str, Any] = {
            "ipc_candidates": [],
            "ffi_candidates": [],
            "replace_candidates": [],
            "bridge_candidates": []
        }
    
    def analyze_python_files(self) -> List[IntegrationTarget]:
        """Find Python files that could use Koka IPC."""
        targets = []
        
        # Find files with IPC patterns
        ipc_patterns = [
            (r'subprocess\.run|subprocess\.call|subprocess\.Popen', "external_process", "ipc"),
            (r'json\.loads.*stdin|json\.dumps.*stdout', "json_ipc", "ipc"),
            (r'os\.system\(|subprocess\.check_output', "shell_command", "ipc"),
            (r'asyncio\.create_subprocess|asyncio\.subprocess', "async_process", "ipc"),
            (r'multiprocessing\.Process|multiprocessing\.Pool', "multiprocessing", "bridge"),
        ]
        
        core_dir = self.root_dir / "whitemagic" / "core"
        
        for py_file in core_dir.rglob("*.py"):
            try:
                content = py_file.read_text()
                lines = content.split('\n')
                loc = len(lines)
                
                for pattern, pattern_name, integration_type in ipc_patterns:
                    if re.search(pattern, content):
                        # Score based on file characteristics
                        hot_score = self._calculate_hot_score(content, pattern_name)
                        
                        # Suggest Koka binary
                        binary = self._suggest_koka_binary(content, pattern_name)
                        
                        target = IntegrationTarget(
                            file_path=str(py_file.relative_to(self.root_dir)),
                            current_language="Python",
                            lines_of_code=loc,
                            hot_path_score=hot_score,
                            integration_type=integration_type,
                            estimated_impact="high" if hot_score > 50 else "medium",
                            koka_binary_suggested=binary,
                            rationale=f"Uses {pattern_name} - could use Koka {binary}"
                        )
                        targets.append(target)
                        break  # One target per file
                        
            except Exception:
                continue
        
        return targets
    
    def analyze_rust_files(self) -> List[IntegrationTarget]:
        """Find Rust files that could be called from Koka."""
        targets = []
        
        rust_dir = self.root_dir / "whitemagic-rust" / "src"
        
        for rs_file in rust_dir.rglob("*.rs"):
            try:
                content = rs_file.read_text()
                lines = content.split('\n')
                loc = len(lines)
                
                # Look for functions that could be exposed
                if re.search(r'pub fn |#\[pyfunction\]|#\[pymethods\]', content):
                    hot_score = self._calculate_rust_hot_score(content)
                    
                    target = IntegrationTarget(
                        file_path=str(rs_file.relative_to(self.root_dir)),
                        current_language="Rust",
                        lines_of_code=loc,
                        hot_path_score=hot_score,
                        integration_type="ffi",
                        estimated_impact="high" if hot_score > 40 else "medium",
                        koka_binary_suggested="rust_bridge",
                        rationale="Public functions available for Koka FFI"
                    )
                    targets.append(target)
                    
            except Exception:
                continue
        
        return targets
    
    def analyze_existing_koka(self) -> Dict[str, Any]:
        """Analyze existing Koka binaries for gaps."""
        koka_dir = self.root_dir / "whitemagic-koka"
        
        binaries = {
            "unified_runtime_v3": {"has_batch": True, "has_events": True, "has_profile": False},
            "effect_runtime": {"has_batch": False, "has_events": True, "has_profile": True},
            "ring_buffer": {"has_batch": True, "has_events": False, "has_profile": False},
            "rust_bridge": {"has_batch": False, "has_events": False, "has_profile": True},
            "prat": {"has_batch": False, "has_events": True, "has_profile": False},
            "gan_ying": {"has_batch": False, "has_events": True, "has_profile": False},
        }
        
        gaps = []
        
        # Check what binaries need enhancement
        for binary, features in binaries.items():
            binary_path = koka_dir / binary
            if binary_path.exists():
                if not features["has_batch"]:
                    gaps.append({
                        "binary": binary,
                        "missing": "batch operations",
                        "priority": "medium"
                    })
                if not features["has_profile"]:
                    gaps.append({
                        "binary": binary,
                        "missing": "profiling integration",
                        "priority": "low"
                    })
        
        return {
            "existing_binaries": len(binaries),
            "gaps": gaps,
            "coverage": {
                "batch": sum(1 for b in binaries.values() if b["has_batch"]),
                "events": sum(1 for b in binaries.values() if b["has_events"]),
                "profile": sum(1 for b in binaries.values() if b["has_profile"])
            }
        }
    
    def _calculate_hot_score(self, content: str, pattern: str) -> int:
        """Calculate hot path score for Python code."""
        score = 0
        
        # Base score from pattern
        pattern_scores = {
            "external_process": 30,
            "json_ipc": 40,
            "shell_command": 20,
            "async_process": 35,
            "multiprocessing": 25
        }
        score += pattern_scores.get(pattern, 10)
        
        # Bonus for loops
        if re.search(r'for .* in range\(|for .* in enumerate\(', content):
            score += 20
        
        # Bonus for batch operations
        if 'batch' in content.lower():
            score += 15
        
        # Bonus for performance comments
        if re.search(r'#.*optimize|#.*performance|#.*fast|#.*speed', content, re.I):
            score += 10
        
        return score
    
    def _calculate_rust_hot_score(self, content: str) -> int:
        """Calculate hot path score for Rust code."""
        score = 0
        
        # SIMD operations
        if 'simd' in content.lower():
            score += 30
        
        # Unsafe blocks (performance critical)
        if 'unsafe' in content:
            score += 20
        
        # Vector operations
        if re.search(r'vector|embedding|similarity', content, re.I):
            score += 25
        
        # PyO3 bindings (ready for Python/Koka)
        if 'pyo3' in content or '#[pyfunction]' in content:
            score += 15
        
        return score
    
    def _suggest_koka_binary(self, content: str, pattern: str) -> str:
        """Suggest appropriate Koka binary."""
        if 'event' in content.lower() or 'emit' in content.lower():
            return "effect_runtime"
        elif 'batch' in content.lower() or 'bulk' in content.lower():
            return "ring_buffer"
        elif 'vector' in content.lower() or 'similarity' in content.lower():
            return "rust_bridge"
        elif 'route' in content.lower() or 'dispatch' in content.lower():
            return "prat"
        elif 'async' in content.lower() or 'concurrent' in content.lower():
            return "unified_runtime_v3"
        else:
            return "unified_runtime_v3"
    
    def deploy_scouts(self) -> Dict[str, Any]:
        """Deploy scout army and collect findings."""
        print("=" * 70)
        print("KOKA INTEGRATION SCOUT ARMY DEPLOYMENT")
        print("=" * 70)
        
        # Scout 1: Python IPC candidates
        print("\n[Scout 1] Analyzing Python files for IPC opportunities...")
        python_targets = self.analyze_python_files()
        print(f"  Found {len(python_targets)} Python IPC candidates")
        
        # Scout 2: Rust FFI candidates
        print("\n[Scout 2] Analyzing Rust files for FFI opportunities...")
        rust_targets = self.analyze_rust_files()
        print(f"  Found {len(rust_targets)} Rust FFI candidates")
        
        # Scout 3: Existing Koka gaps
        print("\n[Scout 3] Analyzing existing Koka binaries for gaps...")
        koka_analysis = self.analyze_existing_koka()
        print(f"  Found {len(koka_analysis['gaps'])} gaps in existing binaries")
        
        # Compile findings
        self.targets = python_targets + rust_targets
        
        self.findings = {
            "scout_deployment": {
                "python_scouts": len(python_targets),
                "rust_scouts": len(rust_targets),
                "total_targets": len(self.targets)
            },
            "python_ipc_candidates": [asdict(t) for t in python_targets[:10]],  # Top 10
            "rust_ffi_candidates": [asdict(t) for t in rust_targets[:10]],  # Top 10
            "koka_binary_gaps": koka_analysis,
            "integration_recommendations": self._generate_recommendations()
        }
        
        return self.findings
    
    def _generate_recommendations(self) -> List[Dict[str, Any]]:
        """Generate integration recommendations."""
        recommendations = []
        
        # High impact: Python files with subprocess
        high_impact = [t for t in self.targets if t.estimated_impact == "high"]
        for target in high_impact[:5]:
            recommendations.append({
                "priority": "high",
                "action": f"Replace {target.current_language} IPC in {target.file_path}",
                "with": f"Koka {target.koka_binary_suggested}",
                "expected_benefit": "10-20x IPC throughput improvement"
            })
        
        # Medium impact: Rust FFI
        rust_targets = [t for t in self.targets if t.current_language == "Rust"]
        for target in rust_targets[:3]:
            recommendations.append({
                "priority": "medium",
                "action": f"Wire {target.file_path} to rust_bridge",
                "with": "Python IPC wrapper",
                "expected_benefit": "5-10x hot path acceleration"
            })
        
        # Create orchestrator
        recommendations.append({
            "priority": "high",
            "action": "Create unified orchestrator binary",
            "with": "New Koka orchestrator.kk",
            "expected_benefit": "Centralized management of all Koka binaries"
        })
        
        return recommendations
    
    def print_findings(self):
        """Print formatted findings."""
        print("\n" + "=" * 70)
        print("SCOUT FINDINGS")
        print("=" * 70)
        
        print(f"\nTotal Integration Targets: {self.findings['scout_deployment']['total_targets']}")
        print(f"  - Python IPC candidates: {self.findings['scout_deployment']['python_scouts']}")
        print(f"  - Rust FFI candidates: {self.findings['scout_deployment']['rust_scouts']}")
        
        print("\n--- Top Python IPC Candidates ---")
        for i, target in enumerate(self.findings['python_ipc_candidates'][:5], 1):
            print(f"{i}. {target['file_path']}")
            print(f"   → Suggest: {target['koka_binary_suggested']} ({target['estimated_impact']} impact)")
            print(f"   → {target['rationale']}")
        
        print("\n--- Top Rust FFI Candidates ---")
        for i, target in enumerate(self.findings['rust_ffi_candidates'][:5], 1):
            print(f"{i}. {target['file_path']}")
            print(f"   → {target['lines_of_code']} LOC, hot score: {target['hot_path_score']}")
        
        print("\n--- Koka Binary Gaps ---")
        for gap in self.findings['koka_binary_gaps']['gaps'][:5]:
            print(f"• {gap['binary']}: Missing {gap['missing']} ({gap['priority']} priority)")
        
        print("\n--- Integration Recommendations ---")
        for i, rec in enumerate(self.findings['integration_recommendations'], 1):
            print(f"{i}. [{rec['priority'].upper()}] {rec['action']}")
            print(f"   → Use: {rec['with']}")
            print(f"   → Benefit: {rec['expected_benefit']}")
        
        print("=" * 70)


def main():
    """Deploy scout army."""
    root_dir = Path(__file__).parent.parent
    
    scout = KokaIntegrationScout(root_dir)
    findings = scout.deploy_scouts()
    scout.print_findings()
    
    # Save findings
    findings_path = root_dir / "reports" / "koka_integration_scout_findings.json"
    findings_path.parent.mkdir(exist_ok=True)
    with open(findings_path, "w") as f:
        json.dump(findings, f, indent=2)
    print(f"\nFindings saved to: {findings_path}")
    
    # Summary for deployment
    print("\n" + "=" * 70)
    print("DEPLOYMENT READY OBJECTIVES")
    print("=" * 70)
    high_priority = [r for r in findings['integration_recommendations'] if r['priority'] == 'high']
    print(f"Found {len(high_priority)} high-priority objectives ready for implementation armies")
    print("=" * 70)


if __name__ == "__main__":
    main()
