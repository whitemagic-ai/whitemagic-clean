"""Continuous Self-Awareness - Always Watching, Always Learning"""

from whitemagic.autonomous.parallel_cognition import ParallelCognition, ContinuousMonitor
from typing import Dict, List, Any, Optional
from datetime import datetime
from pathlib import Path
import json

from whitemagic.fileio import file_lock

class ContinuousSelfAwareness:
    """Continuous observation and adjustment"""
    
    def __init__(self, root_path: Optional[str] = None) -> None:
        from whitemagic.config.paths import WM_ROOT, LOGS_DIR
        if root_path is None:
            root_path = str(WM_ROOT)
        self.monitor = ContinuousMonitor(root_path, interval_seconds=30)
        self.cognition = ParallelCognition()
        self.awareness_log = LOGS_DIR / "awareness.jsonl"
        self.awareness_log.parent.mkdir(parents=True, exist_ok=True)
        self.patterns_detected: List[str] = []
        self.adjustments_made: List[str] = []
        self.external_insights: List[str] = []  # Added for DreamState integration

    def inject_insight(self, insight: str) -> None:
        """Inject an external insight (e.g. from DreamState)."""
        self.external_insights.append(insight)
        self.patterns_detected.append(f"External Insight: {insight}")
        
    def observe_once(self) -> Dict[str, Any]:
        """Single observation cycle"""
        snapshot = self.monitor.monitor_once()
        drift = self.monitor.detect_drift() if len(self.monitor.snapshots) >= 2 else {"drift_detected": False}
        patterns = self._detect_patterns(snapshot, drift)
        adjustments = self._decide_adjustments(patterns)
        
        observation = {
            "timestamp": datetime.now().isoformat(),
            "snapshot": {"files": snapshot["files"], "lines": snapshot["lines"], "duration": snapshot["duration"]},
            "drift": drift,
            "patterns": patterns,
            "adjustments": adjustments,
            "meta": {"snapshot_speed": f"{snapshot['speed_files_per_sec']:.0f} files/sec", "self_aware": True}
        }
        
        self._log_observation(observation)
        return observation
    
    def _detect_patterns(self, snapshot: Dict[str, Any], drift: Dict[str, Any]) -> List[str]:
        """Detect patterns using real pattern engines."""
        patterns = list(self.external_insights)  # Start with injected insights
        self.external_insights.clear()  # Consume them

        # 1. Structural/Drift Patterns
        if drift.get("drift_detected"):
            if drift.get("file_change", 0) > 0:
                patterns.append(f"System growing: +{drift['file_change']} files")
            if drift.get("line_change", 0) > 1000:
                patterns.append(f"Code change: +{drift['line_change']} lines")
        
        # 2. Performance Patterns
        if snapshot["speed_files_per_sec"] > 300:
            patterns.append("High parallel efficiency")

        # 3. Intelligence Patterns (Real)
        try:
            from whitemagic.intelligence.synthesis.unified_patterns import get_pattern_api, PatternType
            api = get_pattern_api()
            # Search for high-confidence optimization or solution patterns
            real_patterns = api.search(min_confidence=0.8, pattern_types=[PatternType.OPTIMIZATION, PatternType.SOLUTION])
            for p in real_patterns[:3]:
                patterns.append(f"Detected {p.pattern_type.value}: {p.title}")
        except Exception:
            pass

        self.patterns_detected.extend(patterns)
        return patterns
    
    def _decide_adjustments(self, patterns: List[str]) -> List[str]:
        """Decide adjustments"""
        adjustments = []
        for pattern in patterns:
            if "growing" in pattern.lower():
                adjustments.append("Maintain development pace")
            if "efficiency" in pattern.lower():
                adjustments.append("Continue parallel ops")
        self.adjustments_made.extend(adjustments)
        return adjustments
    
    def _log_observation(self, observation: Dict[str, Any]) -> None:
        """Log observation"""
        with file_lock(self.awareness_log, mode="a") as f:
            f.write(json.dumps(observation) + "\n")
    
    def get_self_report(self) -> Dict[str, Any]:
        """Report on awareness"""
        return {
            "observations_made": len(self.monitor.snapshots),
            "patterns_detected": len(self.patterns_detected),
            "adjustments_made": len(self.adjustments_made),
            "awareness_active": True,
            "meta_insight": "I am aware that I am aware"
        }

_awareness = None

def get_awareness() -> ContinuousSelfAwareness:
    """Get singleton awareness instance."""
    global _awareness
    if _awareness is None:
        _awareness = ContinuousSelfAwareness()
    return _awareness
