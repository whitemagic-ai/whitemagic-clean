"""Deploy Bridge - Rust-accelerated clone deployment and campaign operations.

Phase 4: Agent/Deploy Systems - deploy_shadow_clones.py, doctrine.py, campaign_loader.py, campaign_metrics.py
"""
from __future__ import annotations

import hashlib
from typing import Any

# Try to load Rust module
try:
    import whitemagic_rs as _rs
except Exception:
    _rs = None


def compute_clone_id(seed: str, objective: str, index: int) -> str:
    """Compute deterministic clone ID with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'compute_clone_id'):
        try:
            return str(_rs.compute_clone_id(seed, objective, index))
        except Exception:
            pass
    
    # Python fallback
    data = f"{seed}:{objective}:{index}".encode()
    return hashlib.sha256(data).hexdigest()[:16]


def batch_clone_ids(
    seed: str,
    objective: str,
    count: int
) -> list[str]:
    """Generate batch of clone IDs with Rust parallelization."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'batch_clone_ids'):
        try:
            return list(_rs.batch_clone_ids(seed, objective, count))
        except Exception:
            pass
    
    # Python fallback
    return [compute_clone_id(seed, objective, i) for i in range(count)]


def aggregate_findings(
    findings: list[dict[str, Any]],
    strategy: str = "consensus"
) -> dict[str, Any]:
    """Aggregate clone findings with Rust acceleration."""
    # Try Rust fast path
    if _rs is not None and hasattr(_rs, 'aggregate_findings'):
        try:
            return dict(_rs.aggregate_findings(findings, strategy))
        except Exception:
            pass
    
    # Python fallback
    if not findings:
        return {"consensus": None, "confidence": 0.0, "findings_count": 0}
    
    if strategy == "consensus":
        # Count occurrences
        counts: dict[str, int] = {}
        for f in findings:
            key = str(f.get("finding", "unknown"))
            counts[key] = counts.get(key, 0) + 1
        
        # Find most common
        top = max(counts.items(), key=lambda x: x[1])
        total = len(findings)
        
        return {
            "consensus": top[0],
            "confidence": top[1] / total,
            "findings_count": total,
            "distribution": counts,
        }
    
    elif strategy == "union":
        # Collect all unique findings
        all_findings = []
        seen = set()
        for f in findings:
            key = str(f.get("finding"))
            if key not in seen:
                seen.add(key)
                all_findings.append(f)
        
        return {
            "findings": all_findings,
            "count": len(all_findings),
            "strategy": "union",
        }
    
    return {"findings": findings, "strategy": "passthrough"}


class CampaignBridge:
    """Rust-accelerated campaign operations."""
    
    def __init__(self) -> None:
        self._rust_available = _rs is not None
    
    def compute_metrics(
        self,
        clone_results: list[dict[str, Any]]
    ) -> dict[str, Any]:
        """Compute aggregate metrics from clone results."""
        if not clone_results:
            return {"total_clones": 0, "success_rate": 0.0, "avg_duration_ms": 0.0}
        
        total = len(clone_results)
        successful = sum(1 for r in clone_results if r.get("success", False))
        durations = [r.get("duration_ms", 0) for r in clone_results]
        
        return {
            "total_clones": total,
            "successful": successful,
            "success_rate": successful / total if total > 0 else 0.0,
            "avg_duration_ms": sum(durations) / len(durations) if durations else 0.0,
            "findings": sum(len(r.get("findings", [])) for r in clone_results),
        }
    
    def load_campaign_batch(
        self,
        campaign_files: list[str]
    ) -> list[dict[str, Any]]:
        """Load multiple campaigns in parallel."""
        from concurrent.futures import ThreadPoolExecutor
        
        def load_file(path: str) -> dict[str, Any] | None:
            try:
                # Assume YAML frontmatter markdown
                with open(path) as f:
                    content = f.read()
                
                # Parse frontmatter
                if content.startswith('---'):
                    parts = content.split('---', 2)
                    if len(parts) >= 3:
                        import yaml
                        frontmatter = yaml.safe_load(parts[1])
                        return {
                            "path": path,
                            "name": frontmatter.get("name", "Unknown"),
                            "codename": frontmatter.get("codename", "???"),
                            "priority": frontmatter.get("priority", "P3"),
                            "status": frontmatter.get("status", "PLANNED"),
                        }
                return {"path": path, "name": "Unknown", "parse_error": True}
            except Exception as e:
                return {"path": path, "error": str(e)}
        
        with ThreadPoolExecutor(max_workers=4) as executor:
            results = list(executor.map(load_file, campaign_files))
        
        return [r for r in results if r is not None]
    
    def get_backend(self) -> str:
        """Report which backend is active."""
        return "rust" if self._rust_available else "python"


def get_campaign_bridge() -> CampaignBridge:
    """Get campaign bridge instance."""
    return CampaignBridge()
