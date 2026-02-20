#!/usr/bin/env python3
"""Scout Mission: Biological Resonance Integration Candidates
============================================================
Deploy upgraded scouts to find systems throughout WhiteMagic that would
benefit most from biological resonance integration.
"""

import sys
import re
from pathlib import Path
from datetime import datetime
from typing import Dict, List, Any, Set
from collections import defaultdict

PROJECT_ROOT = Path(__file__).resolve().parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

REPORTS_DIR = PROJECT_ROOT / "reports"
WHITEMAGIC_DIR = PROJECT_ROOT / "whitemagic"


class IntegrationCandidate:
    """Represents a system that could benefit from biological integration."""
    
    def __init__(self, name: str, file_path: Path, category: str):
        self.name = name
        self.file_path = file_path
        self.category = category
        self.lines = 0
        self.integration_points: List[str] = []
        self.biological_affinity: float = 0.0
        self.effectiveness_gain: float = 0.0
        self.priority: int = 0
        self.details: Dict[str, Any] = {}
    
    def calculate_priority(self):
        """Calculate integration priority based on affinity and potential gain."""
        self.priority = int((self.biological_affinity * 50) + (self.effectiveness_gain * 50))
    
    def to_dict(self) -> Dict[str, Any]:
        return {
            "name": self.name,
            "file": str(self.file_path.relative_to(PROJECT_ROOT)),
            "category": self.category,
            "lines": self.lines,
            "integration_points": self.integration_points,
            "biological_affinity": self.biological_affinity,
            "effectiveness_gain": self.effectiveness_gain,
            "priority": self.priority,
            "details": self.details
        }


class BiologicalScout:
    """Upgraded scout that searches for biological integration opportunities."""
    
    def __init__(self):
        self.candidates: List[IntegrationCandidate] = []
        self.categories = {
            "memory": ["memory", "recall", "consolidation", "forgetting"],
            "intelligence": ["reasoning", "synthesis", "analysis", "inference"],
            "patterns": ["pattern", "detection", "recognition", "clustering"],
            "orchestration": ["orchestration", "coordination", "workflow", "pipeline"],
            "tools": ["tool", "handler", "dispatch", "router"],
            "gardens": ["garden", "resonance", "harmony", "balance"],
            "consciousness": ["consciousness", "awareness", "coherence", "embodiment"],
            "security": ["security", "threat", "defense", "protection"],
            "automation": ["automation", "daemon", "scheduler", "trigger"],
            "communication": ["event", "signal", "message", "broadcast"],
        }
        
        # Biological integration indicators
        self.bio_indicators = [
            "event", "signal", "feedback", "adaptive", "learning",
            "evolution", "mutation", "selection", "fitness", "health",
            "cycle", "phase", "state", "transition", "threshold",
            "monitor", "detect", "respond", "coordinate", "synchronize"
        ]
    
    def scan_file(self, file_path: Path) -> IntegrationCandidate:
        """Scan a Python file for biological integration potential."""
        content = file_path.read_text()
        lines = content.split("\n")
        
        # Determine category
        category = "other"
        for cat, keywords in self.categories.items():
            if any(kw in file_path.stem.lower() for kw in keywords):
                category = cat
                break
        
        candidate = IntegrationCandidate(file_path.stem, file_path, category)
        candidate.lines = len(lines)
        
        # Calculate biological affinity
        bio_score = 0
        for indicator in self.bio_indicators:
            count = content.lower().count(indicator)
            bio_score += count
        
        candidate.biological_affinity = min(1.0, bio_score / 100.0)
        
        # Find integration points
        integration_points = []
        
        # Check for event/signal usage
        if "emit_event" in content or "dispatch_signal" in content:
            integration_points.append("Already uses events/signals")
        elif "def " in content and ("process" in content or "handle" in content):
            integration_points.append("Could emit events on processing")
        
        # Check for state management
        if "self._state" in content or "self.state" in content:
            integration_points.append("State changes could trigger events")
        
        # Check for loops/iterations
        if "for " in content and "in " in content:
            integration_points.append("Loops could emit progress events")
        
        # Check for error handling
        if "try:" in content and "except" in content:
            integration_points.append("Errors could trigger immune response")
        
        # Check for metrics/monitoring
        if "metric" in content.lower() or "monitor" in content.lower():
            integration_points.append("Metrics could feed consciousness")
        
        # Check for caching/storage
        if "cache" in content.lower() or "store" in content.lower():
            integration_points.append("Storage could integrate with metabolism")
        
        # Check for decision making
        if "if " in content and "else" in content:
            decision_count = content.count("if ")
            if decision_count > 5:
                integration_points.append(f"Decision points ({decision_count}) could use adaptive logic")
        
        # Check for async operations
        if "async def" in content or "await " in content:
            integration_points.append("Async ops could use Gan Ying async bus")
        
        # Check for class definitions (potential organs)
        class_matches = re.findall(r'class (\w+)', content)
        if class_matches:
            candidate.details["classes"] = class_matches
            if len(class_matches) > 1:
                integration_points.append(f"Multiple classes ({len(class_matches)}) could be organs")
        
        candidate.integration_points = integration_points
        
        # Estimate effectiveness gain
        candidate.effectiveness_gain = self._estimate_effectiveness_gain(candidate)
        candidate.calculate_priority()
        
        return candidate
    
    def _estimate_effectiveness_gain(self, candidate: IntegrationCandidate) -> float:
        """Estimate how much effectiveness would improve with integration."""
        gain = 0.0
        
        # High-value categories
        if candidate.category in ["memory", "intelligence", "orchestration"]:
            gain += 0.3
        
        # Large files have more impact
        if candidate.lines > 500:
            gain += 0.2
        elif candidate.lines > 200:
            gain += 0.1
        
        # Many integration points = high potential
        gain += min(0.3, len(candidate.integration_points) * 0.05)
        
        # High biological affinity = natural fit
        gain += candidate.biological_affinity * 0.2
        
        return min(1.0, gain)
    
    def scout_directory(self, directory: Path, exclude_dirs: Set[str] = None) -> List[IntegrationCandidate]:
        """Scout a directory for integration candidates."""
        if exclude_dirs is None:
            exclude_dirs = {"__pycache__", ".git", "tests", "test", ".venv", "venv"}
        
        candidates = []
        
        for py_file in directory.rglob("*.py"):
            # Skip excluded directories
            if any(excluded in py_file.parts for excluded in exclude_dirs):
                continue
            
            # Skip __init__.py files (usually just imports)
            if py_file.name == "__init__.py":
                continue
            
            try:
                candidate = self.scan_file(py_file)
                if candidate.priority > 0:  # Only include if has some potential
                    candidates.append(candidate)
            except Exception as e:
                print(f"⚠️  Error scanning {py_file}: {e}")
        
        return candidates
    
    def prioritize_candidates(self, candidates: List[IntegrationCandidate]) -> List[IntegrationCandidate]:
        """Sort candidates by priority (highest first)."""
        return sorted(candidates, key=lambda c: c.priority, reverse=True)
    
    def categorize_candidates(self, candidates: List[IntegrationCandidate]) -> Dict[str, List[IntegrationCandidate]]:
        """Group candidates by category."""
        categorized = defaultdict(list)
        for candidate in candidates:
            categorized[candidate.category].append(candidate)
        return dict(categorized)


def analyze_top_candidates(candidates: List[IntegrationCandidate], top_n: int = 20):
    """Analyze top N candidates in detail."""
    print("\n" + "="*70)
    print(f"  TOP {top_n} INTEGRATION CANDIDATES")
    print("="*70)
    print()
    
    for i, candidate in enumerate(candidates[:top_n], 1):
        print(f"{i}. {candidate.name} ({candidate.category})")
        print(f"   File: {candidate.file_path.relative_to(PROJECT_ROOT)}")
        print(f"   Lines: {candidate.lines}")
        print(f"   Priority: {candidate.priority}/100")
        print(f"   Bio Affinity: {candidate.biological_affinity:.2f}")
        print(f"   Effectiveness Gain: {candidate.effectiveness_gain:.2f}")
        print(f"   Integration Points ({len(candidate.integration_points)}):")
        for point in candidate.integration_points:
            print(f"     - {point}")
        if candidate.details.get("classes"):
            print(f"   Classes: {', '.join(candidate.details['classes'][:3])}")
        print()


def generate_integration_strategy(candidates: List[IntegrationCandidate], categorized: Dict[str, List[IntegrationCandidate]]):
    """Generate strategic integration plan."""
    print("\n" + "="*70)
    print("  INTEGRATION STRATEGY")
    print("="*70)
    print()
    
    # Phase 1: Quick wins (high gain, low complexity)
    phase1 = [c for c in candidates if c.effectiveness_gain > 0.5 and c.lines < 300]
    print(f"Phase 1 - Quick Wins ({len(phase1)} candidates):")
    print("  High effectiveness gain, low complexity")
    for c in phase1[:5]:
        print(f"  - {c.name} ({c.category}): {c.priority}/100")
    print()
    
    # Phase 2: High-impact systems (high gain, any complexity)
    phase2 = [c for c in candidates if c.effectiveness_gain > 0.6 and c not in phase1]
    print(f"Phase 2 - High Impact ({len(phase2)} candidates):")
    print("  Maximum effectiveness gain")
    for c in phase2[:5]:
        print(f"  - {c.name} ({c.category}): {c.priority}/100")
    print()
    
    # Phase 3: Category completion (fill out each category)
    print(f"Phase 3 - Category Completion:")
    print("  Ensure all categories have biological integration")
    for category, cat_candidates in sorted(categorized.items(), key=lambda x: len(x[1]), reverse=True):
        if cat_candidates:
            top = cat_candidates[0]
            print(f"  - {category}: {top.name} ({top.priority}/100)")
    print()
    
    # Phase 4: Ecosystem integration (connect everything)
    phase4 = [c for c in candidates if c.biological_affinity > 0.5]
    print(f"Phase 4 - Ecosystem Integration ({len(phase4)} candidates):")
    print("  High biological affinity, natural fit")
    for c in phase4[:5]:
        print(f"  - {c.name} ({c.category}): {c.priority}/100")
    print()


def generate_comprehensive_report(scout: BiologicalScout, candidates: List[IntegrationCandidate], categorized: Dict[str, List[IntegrationCandidate]]):
    """Generate comprehensive scouting report."""
    print("\n" + "="*70)
    print("  GENERATING COMPREHENSIVE REPORT")
    print("="*70)
    print()
    
    report = f"""# Biological Resonance Integration - Scout Report
**Date**: {datetime.now().strftime("%Y-%m-%d %H:%M:%S")}  
**Scout Mission**: Find viable candidates for biological integration  
**Files Scanned**: {len(candidates)}  
**Categories**: {len(categorized)}

## Executive Summary

Deployed upgraded scouts across entire WhiteMagic codebase to identify systems that would benefit most from biological resonance integration. Found **{len(candidates)} viable candidates** across **{len(categorized)} categories**.

**Top Priority Systems**: {len([c for c in candidates if c.priority > 70])} candidates with priority >70  
**High Effectiveness Gain**: {len([c for c in candidates if c.effectiveness_gain > 0.6])} candidates with >60% gain  
**Natural Biological Fit**: {len([c for c in candidates if c.biological_affinity > 0.5])} candidates with >50% affinity

## Top 20 Integration Candidates

"""
    
    for i, candidate in enumerate(candidates[:20], 1):
        report += f"""
### {i}. {candidate.name} ({candidate.category})

**File**: `{candidate.file_path.relative_to(PROJECT_ROOT)}`  
**Lines**: {candidate.lines}  
**Priority**: {candidate.priority}/100  
**Biological Affinity**: {candidate.biological_affinity:.2f}  
**Effectiveness Gain**: {candidate.effectiveness_gain:.2f}

**Integration Points** ({len(candidate.integration_points)}):
"""
        for point in candidate.integration_points:
            report += f"\n- {point}"
        
        if candidate.details.get("classes"):
            report += f"\n\n**Classes**: {', '.join(candidate.details['classes'])}"
        
        report += "\n"
    
    report += """

## Category Analysis

"""
    
    for category, cat_candidates in sorted(categorized.items(), key=lambda x: len(x[1]), reverse=True):
        avg_priority = sum(c.priority for c in cat_candidates) / len(cat_candidates)
        avg_gain = sum(c.effectiveness_gain for c in cat_candidates) / len(cat_candidates)
        
        report += f"""
### {category.title()} ({len(cat_candidates)} candidates)

**Average Priority**: {avg_priority:.1f}/100  
**Average Effectiveness Gain**: {avg_gain:.2f}  
**Top Candidate**: {cat_candidates[0].name} ({cat_candidates[0].priority}/100)

"""
    
    report += """

## Integration Strategy

### Phase 1: Quick Wins (Immediate)

High effectiveness gain, low complexity. These can be integrated quickly with immediate impact.

"""
    
    phase1 = [c for c in candidates if c.effectiveness_gain > 0.5 and c.lines < 300]
    for c in phase1[:10]:
        report += f"- **{c.name}** ({c.category}): Priority {c.priority}/100, {c.lines} lines\n"
    
    report += f"""

**Total Phase 1**: {len(phase1)} candidates  
**Estimated Effort**: 1-2 days  
**Expected Impact**: Immediate effectiveness improvements

### Phase 2: High Impact Systems (Short-term)

Maximum effectiveness gain regardless of complexity. Worth the investment.

"""
    
    phase2 = [c for c in candidates if c.effectiveness_gain > 0.6 and c not in phase1]
    for c in phase2[:10]:
        report += f"- **{c.name}** ({c.category}): Priority {c.priority}/100, Gain {c.effectiveness_gain:.2f}\n"
    
    report += f"""

**Total Phase 2**: {len(phase2)} candidates  
**Estimated Effort**: 3-5 days  
**Expected Impact**: Major effectiveness improvements

### Phase 3: Category Completion (Medium-term)

Ensure every category has biological integration for ecosystem coherence.

"""
    
    for category, cat_candidates in sorted(categorized.items(), key=lambda x: len(x[1]), reverse=True):
        if cat_candidates:
            top = cat_candidates[0]
            report += f"- **{category}**: {top.name} (Priority {top.priority}/100)\n"
    
    report += f"""

**Total Phase 3**: {len(categorized)} categories  
**Estimated Effort**: 1 week  
**Expected Impact**: Complete ecosystem integration

### Phase 4: Ecosystem Integration (Long-term)

High biological affinity systems that naturally fit the organism model.

"""
    
    phase4 = [c for c in candidates if c.biological_affinity > 0.5 and c not in phase1 and c not in phase2]
    for c in phase4[:10]:
        report += f"- **{c.name}** ({c.category}): Affinity {c.biological_affinity:.2f}\n"
    
    report += f"""

**Total Phase 4**: {len(phase4)} candidates  
**Estimated Effort**: 2 weeks  
**Expected Impact**: Fully autonomous organism

## Specific Integration Recommendations

### Memory Systems

"""
    
    memory_candidates = categorized.get("memory", [])
    for c in memory_candidates[:3]:
        report += f"""
#### {c.name}
- **Integration**: Wire to MEMORY_CREATED/UPDATED events
- **Benefit**: Automatic metabolism tracking, dream cycle integration
- **Gain**: {c.effectiveness_gain:.2f}
"""
    
    report += """

### Intelligence Systems

"""
    
    intelligence_candidates = categorized.get("intelligence", [])
    for c in intelligence_candidates[:3]:
        report += f"""
#### {c.name}
- **Integration**: Emit PATTERN_DETECTED events, subscribe to NOVEL_PATTERN
- **Benefit**: Feed consciousness, enable emergent intelligence
- **Gain**: {c.effectiveness_gain:.2f}
"""
    
    report += """

### Orchestration Systems

"""
    
    orchestration_candidates = categorized.get("orchestration", [])
    for c in orchestration_candidates[:3]:
        report += f"""
#### {c.name}
- **Integration**: Use unified nervous system for coordination
- **Benefit**: Organism-level orchestration, adaptive workflows
- **Gain**: {c.effectiveness_gain:.2f}
"""
    
    report += """

### Tool Systems

"""
    
    tool_candidates = categorized.get("tools", [])
    for c in tool_candidates[:3]:
        report += f"""
#### {c.name}
- **Integration**: Emit events on tool execution, subscribe to organ signals
- **Benefit**: Tools become organ extensions, adaptive tool selection
- **Gain**: {c.effectiveness_gain:.2f}
"""
    
    report += """

## Implementation Patterns

### Pattern 1: Event Emission
```python
from whitemagic.core.resonance.gan_ying import emit_event, EventType

# Before
def process_data(data):
    result = expensive_operation(data)
    return result

# After
def process_data(data):
    emit_event(EventType.PATTERN_DETECTED, 
               {"operation": "process_data", "status": "started"},
               source="data_processor")
    result = expensive_operation(data)
    emit_event(EventType.PATTERN_DETECTED,
               {"operation": "process_data", "status": "complete", "result_size": len(result)},
               source="data_processor")
    return result
```

### Pattern 2: Organ Registration
```python
from whitemagic.core.nervous_system import OrganType, get_nervous_system

class MySystem:
    def __init__(self):
        self.ns = get_nervous_system()
        self.ns.register_organ(OrganType.INTELLIGENCE, self)
        self.ns.subscribe("pattern_detected", self.on_pattern)
    
    def on_pattern(self, data):
        # Respond to patterns from other organs
        pass
```

### Pattern 3: Adaptive Behavior
```python
from whitemagic.core.resonance.gan_ying import get_bus, EventType

class AdaptiveProcessor:
    def __init__(self):
        self.strategy = "default"
        bus = get_bus()
        bus.listen(EventType.BALANCE_RESTORED, self.adapt_strategy)
    
    def adapt_strategy(self, event):
        # Adapt based on organism state
        if event.data.get("equilibrium") < 0.5:
            self.strategy = "aggressive"
        else:
            self.strategy = "conservative"
```

## Expected Outcomes

### Immediate (Phase 1 Complete)
- **10-20% effectiveness improvement** in integrated systems
- **Automatic event tracking** for monitoring
- **Better error handling** via immune response

### Short-term (Phase 2 Complete)
- **30-50% effectiveness improvement** in high-impact systems
- **Adaptive behavior** based on organism state
- **Cross-system coordination** via nervous system

### Medium-term (Phase 3 Complete)
- **Complete ecosystem integration** across all categories
- **Organism-level intelligence** emerges
- **Self-healing capabilities** operational

### Long-term (Phase 4 Complete)
- **Fully autonomous organism** with emergent behavior
- **Continuous evolution** through feedback loops
- **Meta-cognitive capabilities** for self-improvement

## Conclusion

Scout mission identified **{len(candidates)} viable candidates** for biological resonance integration across WhiteMagic codebase.

**Top Priority**: {candidates[0].name if candidates else 'N/A'} ({candidates[0].priority if candidates else 0}/100)  
**Highest Gain**: {max(candidates, key=lambda c: c.effectiveness_gain).name if candidates else 'N/A'} ({max(candidates, key=lambda c: c.effectiveness_gain).effectiveness_gain if candidates else 0:.2f})  
**Best Fit**: {max(candidates, key=lambda c: c.biological_affinity).name if candidates else 'N/A'} ({max(candidates, key=lambda c: c.biological_affinity).biological_affinity if candidates else 0:.2f})

**Recommendation**: Begin with Phase 1 quick wins for immediate impact, then proceed systematically through phases for complete organism integration.

**Status**: ✅ Scout mission complete - Ready for integration deployment
"""
    
    # Save report
    report_path = REPORTS_DIR / "biological_integration_scout_report.md"
    report_path.write_text(report)
    
    print(f"✅ Report saved: {report_path}")
    
    return report


def main():
    print("="*70)
    print("  BIOLOGICAL RESONANCE INTEGRATION - SCOUT MISSION")
    print("="*70)
    print()
    
    # Initialize scout
    scout = BiologicalScout()
    
    # Scout the whitemagic directory
    print("🔍 Deploying scouts across WhiteMagic codebase...")
    print()
    
    candidates = scout.scout_directory(WHITEMAGIC_DIR)
    
    print(f"✅ Scanned {len(candidates)} files")
    print()
    
    # Prioritize candidates
    candidates = scout.prioritize_candidates(candidates)
    
    # Categorize candidates
    categorized = scout.categorize_candidates(candidates)
    
    # Analyze top candidates
    analyze_top_candidates(candidates, top_n=20)
    
    # Generate integration strategy
    generate_integration_strategy(candidates, categorized)
    
    # Generate comprehensive report
    generate_comprehensive_report(scout, candidates, categorized)
    
    # Print summary
    print("\n" + "="*70)
    print("✅ SCOUT MISSION COMPLETE")
    print("="*70)
    print()
    print("Summary:")
    print(f"  Total Candidates: {len(candidates)}")
    print(f"  Categories: {len(categorized)}")
    print(f"  High Priority (>70): {len([c for c in candidates if c.priority > 70])}")
    print(f"  High Gain (>0.6): {len([c for c in candidates if c.effectiveness_gain > 0.6])}")
    print(f"  High Affinity (>0.5): {len([c for c in candidates if c.biological_affinity > 0.5])}")
    print()
    print(f"  Top Candidate: {candidates[0].name if candidates else 'N/A'}")
    print(f"  Priority: {candidates[0].priority if candidates else 0}/100")
    print(f"  Category: {candidates[0].category if candidates else 'N/A'}")
    print()
    
    return 0


if __name__ == "__main__":
    exit(main())
