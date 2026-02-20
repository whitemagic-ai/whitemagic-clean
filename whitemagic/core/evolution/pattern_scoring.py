"""Pattern Scoring System - Phase 3D

Cross-validation and confidence scoring for discovered patterns.
Implements multi-source validation and longevity-based weighting.
"""

from dataclasses import dataclass
from typing import Dict, List, Any, Set
from collections import defaultdict
import logging

logger = logging.getLogger(__name__)


@dataclass
class ScoredPattern:
    """A pattern with comprehensive confidence scoring."""
    pattern_id: str
    pattern_type: str
    sources: List[str]  # Which galaxies/repos it appears in
    cross_validation_score: float  # 0-1, based on multiple sources
    outcome_score: float  # 0-1, based on measured improvements
    frequency_score: float  # 0-1, based on occurrence count
    longevity_score: float  # 0-1, based on time in production
    final_confidence: float  # Weighted combination
    metadata: Dict[str, Any]
    
    def __repr__(self) -> str:
        return (
            f"ScoredPattern(id={self.pattern_id}, "
            f"confidence={self.final_confidence:.2%}, "
            f"sources={len(self.sources)})"
        )


class PatternScorer:
    """Scores patterns based on cross-validation, outcomes, frequency, and longevity."""
    
    def __init__(
        self,
        cross_validation_weight: float = 0.4,
        outcome_weight: float = 0.3,
        frequency_weight: float = 0.2,
        longevity_weight: float = 0.1,
    ):
        """Initialize with configurable weights (must sum to 1.0)."""
        total = cross_validation_weight + outcome_weight + frequency_weight + longevity_weight
        if abs(total - 1.0) > 0.01:
            raise ValueError(f"Weights must sum to 1.0, got {total}")
        
        self.cross_validation_weight = cross_validation_weight
        self.outcome_weight = outcome_weight
        self.frequency_weight = frequency_weight
        self.longevity_weight = longevity_weight
        
        logger.info(
            f"PatternScorer initialized: CV={cross_validation_weight:.1%}, "
            f"Outcome={outcome_weight:.1%}, Freq={frequency_weight:.1%}, "
            f"Long={longevity_weight:.1%}"
        )
    
    def score_galaxy_patterns(
        self,
        semantic_clusters: List[Any],
        access_patterns: List[Any],
        cache_patterns: List[Any],
    ) -> List[ScoredPattern]:
        """Score patterns from galaxy mining results."""
        scored = []
        
        # Group semantic clusters by tags to find cross-validated patterns
        tag_clusters = defaultdict(list)
        for cluster in semantic_clusters:
            for tag in cluster.common_tags:
                tag_clusters[tag].append(cluster)
        
        # Score semantic clusters
        for tag, clusters in tag_clusters.items():
            if len(clusters) < 1:
                continue
            
            # Cross-validation: appears in multiple clusters
            cv_score = min(len(clusters) / 5.0, 1.0)  # Max at 5 sources
            
            # Frequency: total size across clusters
            total_size = sum(c.size for c in clusters)
            freq_score = min(total_size / 100.0, 1.0)  # Max at 100 memories
            
            # Importance as proxy for outcome
            avg_importance = sum(c.avg_importance for c in clusters) / len(clusters)
            outcome_score = min(avg_importance / 1.0, 1.0)  # Normalize to 1.0
            
            # Longevity: assume clusters are from archives (high longevity)
            longevity_score = 0.8  # Archives are proven over time
            
            final_confidence = (
                self.cross_validation_weight * cv_score +
                self.outcome_weight * outcome_score +
                self.frequency_weight * freq_score +
                self.longevity_weight * longevity_score
            )
            
            scored.append(ScoredPattern(
                pattern_id=f"semantic_{tag}",
                pattern_type="semantic_cluster",
                sources=[f"cluster_{i}" for i in range(len(clusters))],
                cross_validation_score=cv_score,
                outcome_score=outcome_score,
                frequency_score=freq_score,
                longevity_score=longevity_score,
                final_confidence=final_confidence,
                metadata={
                    "tag": tag,
                    "cluster_count": len(clusters),
                    "total_size": total_size,
                    "avg_importance": avg_importance,
                }
            ))
        
        # Score access patterns
        for i, (source, pattern) in enumerate(access_patterns):
            cv_score = 0.5  # Single source, moderate confidence
            freq_score = min(pattern.frequency / 10.0, 1.0)
            outcome_score = pattern.confidence
            longevity_score = 0.7  # Archive data
            
            final_confidence = (
                self.cross_validation_weight * cv_score +
                self.outcome_weight * outcome_score +
                self.frequency_weight * freq_score +
                self.longevity_weight * longevity_score
            )
            
            scored.append(ScoredPattern(
                pattern_id=pattern.pattern_id,
                pattern_type="access_pattern",
                sources=[source],
                cross_validation_score=cv_score,
                outcome_score=outcome_score,
                frequency_score=freq_score,
                longevity_score=longevity_score,
                final_confidence=final_confidence,
                metadata={
                    "frequency": pattern.frequency,
                    "memory_count": len(pattern.memory_ids),
                }
            ))
        
        # Score cache patterns
        for i, (source, pattern) in enumerate(cache_patterns):
            cv_score = 0.6  # Cache candidates have higher initial confidence
            freq_score = min(pattern.frequency / 10.0, 1.0)
            outcome_score = pattern.confidence
            longevity_score = 0.7
            
            final_confidence = (
                self.cross_validation_weight * cv_score +
                self.outcome_weight * outcome_score +
                self.frequency_weight * freq_score +
                self.longevity_weight * longevity_score
            )
            
            scored.append(ScoredPattern(
                pattern_id=pattern.pattern_id,
                pattern_type="cache_candidate",
                sources=[source],
                cross_validation_score=cv_score,
                outcome_score=outcome_score,
                frequency_score=freq_score,
                longevity_score=longevity_score,
                final_confidence=final_confidence,
                metadata={
                    "frequency": pattern.frequency,
                    "memory_count": len(pattern.memory_ids),
                }
            ))
        
        return scored
    
    def score_geneseed_patterns(
        self,
        optimization_patterns: List[Any],
    ) -> List[ScoredPattern]:
        """Score patterns from geneseed (git history) mining."""
        scored = []
        
        # Group by pattern type to find cross-validated patterns
        type_patterns = defaultdict(list)
        for pattern in optimization_patterns:
            type_patterns[pattern.pattern_type].append(pattern)
        
        for pattern in optimization_patterns:
            # Cross-validation: how many similar patterns exist
            similar_count = len([
                p for p in type_patterns[pattern.pattern_type]
                if p.author == pattern.author or 
                   any(f in pattern.files_changed for f in p.files_changed)
            ])
            cv_score = min(similar_count / 5.0, 1.0)
            
            # Outcome: use pattern's built-in confidence
            outcome_score = pattern.confidence
            
            # Frequency: based on change size (moderate is best)
            total_changes = pattern.lines_added + pattern.lines_removed
            if total_changes < 10:
                freq_score = 0.3
            elif total_changes < 100:
                freq_score = 1.0
            elif total_changes < 500:
                freq_score = 0.8
            else:
                freq_score = 0.5
            
            # Longevity: based on commit age
            longevity_score = min(pattern.longevity_days / 365.0, 1.0)
            
            final_confidence = (
                self.cross_validation_weight * cv_score +
                self.outcome_weight * outcome_score +
                self.frequency_weight * freq_score +
                self.longevity_weight * longevity_score
            )
            
            scored.append(ScoredPattern(
                pattern_id=pattern.pattern_id,
                pattern_type=f"geneseed_{pattern.pattern_type}",
                sources=[pattern.commit_hash[:8]],
                cross_validation_score=cv_score,
                outcome_score=outcome_score,
                frequency_score=freq_score,
                longevity_score=longevity_score,
                final_confidence=final_confidence,
                metadata={
                    "commit_hash": pattern.commit_hash,
                    "commit_message": pattern.commit_message,
                    "author": pattern.author,
                    "timestamp": pattern.timestamp,
                    "files_changed": pattern.files_changed,
                    "lines_added": pattern.lines_added,
                    "lines_removed": pattern.lines_removed,
                    "longevity_days": pattern.longevity_days,
                }
            ))
        
        return scored
    
    def cross_validate_patterns(
        self,
        galaxy_patterns: List[ScoredPattern],
        geneseed_patterns: List[ScoredPattern],
    ) -> List[ScoredPattern]:
        """Cross-validate patterns between galaxy and geneseed sources."""
        # Find patterns that appear in both sources
        galaxy_tags = {p.metadata.get('tag') for p in galaxy_patterns if 'tag' in p.metadata}
        geneseed_messages = {
            p.metadata.get('commit_message', '').lower() 
            for p in geneseed_patterns
        }
        
        cross_validated = []
        
        for gp in galaxy_patterns:
            tag = gp.metadata.get('tag', '')
            # Check if this tag appears in geneseed commit messages
            matches = sum(1 for msg in geneseed_messages if tag.lower() in msg)
            
            if matches > 0:
                # Boost confidence for cross-validated patterns
                boosted = ScoredPattern(
                    pattern_id=gp.pattern_id,
                    pattern_type=gp.pattern_type,
                    sources=gp.sources + [f"geneseed_match_{i}" for i in range(matches)],
                    cross_validation_score=min(gp.cross_validation_score + 0.2, 1.0),
                    outcome_score=gp.outcome_score,
                    frequency_score=gp.frequency_score,
                    longevity_score=gp.longevity_score,
                    final_confidence=min(gp.final_confidence + 0.15, 1.0),
                    metadata={**gp.metadata, "cross_validated": True, "geneseed_matches": matches}
                )
                cross_validated.append(boosted)
            else:
                cross_validated.append(gp)
        
        # Add geneseed patterns
        cross_validated.extend(geneseed_patterns)
        
        return cross_validated
    
    def filter_by_confidence(
        self,
        patterns: List[ScoredPattern],
        min_confidence: float = 0.5,
    ) -> List[ScoredPattern]:
        """Filter patterns by minimum confidence threshold."""
        return [p for p in patterns if p.final_confidence >= min_confidence]
    
    def get_top_patterns(
        self,
        patterns: List[ScoredPattern],
        top_n: int = 20,
    ) -> List[ScoredPattern]:
        """Get top N patterns by confidence."""
        return sorted(patterns, key=lambda p: p.final_confidence, reverse=True)[:top_n]
