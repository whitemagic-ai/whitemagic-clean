"""
Thought Scorer (G003)
=====================

Auto-scores Cognitive Episodes based on measurable outcomes.
"""

from typing import Dict, Any

def score_episode(metrics: Dict[str, Any]) -> float:
    """
    Calculate a score (-1.0 to 1.0) based on outcome metrics.
    
    Standard metrics keys:
    - success (bool): Did the task complete?
    - error_count (int): Number of errors encountered
    - tests_passed (bool): Did verification pass?
    - quality_score (float): 0.0-1.0 qualitative rating
    - efficiency (float): 0.0-1.0 resource usage score
    """
    
    base_score = 0.0
    
    # 1. Binary success/failure
    if metrics.get("success", False):
        base_score += 0.5
    else:
        base_score -= 0.5
        
    # 2. Test verification (high value)
    if metrics.get("tests_passed", False):
        base_score += 0.3
    elif metrics.get("tests_passed") is False: # Explicitly False, not None
        base_score -= 0.2
        
    # 3. Error penalty
    errors = metrics.get("error_count", 0)
    if errors > 0:
        base_score -= min(0.3, errors * 0.1)
        
    # 4. Quality bonus
    if "quality_score" in metrics:
        q = metrics["quality_score"]
        # Map 0.0-1.0 to -0.2 to +0.2
        base_score += (q - 0.5) * 0.4
        
    # Clamp to -1.0 to 1.0
    return max(-1.0, min(1.0, base_score))
