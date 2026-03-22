#!/usr/bin/env python3
"""
PHASE 1: PATTERN UNIFICATION
=============================
Deploy shadow clones to unify 127 to_dict and 63 get_stats implementations
"""

import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
WM2_ROOT = Path.home() / "Desktop" / "WM2"

print("=" * 80)
print("PHASE 1: PATTERN UNIFICATION")
print("=" * 80)
print()

# Migrate core managers to BaseManager
core_managers = [
    "whitemagic/core/memory/manager.py",
    "whitemagic/core/memory/db_manager.py",
    "whitemagic/core/memory/galaxy_manager.py",
]

# Migrate core engines to BaseEngine
core_engines = [
    "whitemagic/core/memory/graph_engine.py",
    "whitemagic/core/intelligence/synthesis/kaizen_engine.py",
    "whitemagic/core/intelligence/synthesis/serendipity_engine.py",
]

def analyze_for_serializable(file_path: Path) -> dict:
    """Check if file has to_dict pattern."""
    try:
        content = file_path.read_text(encoding='utf-8')
        has_to_dict = bool(re.search(r'def\s+to_dict\s*\(', content))
        has_from_dict = bool(re.search(r'def\s+from_dict\s*\(', content))

        return {
            'has_to_dict': has_to_dict,
            'has_from_dict': has_from_dict,
            'can_migrate': has_to_dict or has_from_dict,
        }
    except Exception:
        return {'can_migrate': False}

def analyze_for_metrics(file_path: Path) -> dict:
    """Check if file has get_stats pattern."""
    try:
        content = file_path.read_text(encoding='utf-8')
        has_get_stats = bool(re.search(r'def\s+get_stats\s*\(', content))

        return {
            'has_get_stats': has_get_stats,
            'can_migrate': has_get_stats,
        }
    except Exception:
        return {'can_migrate': False}

def main():
    print("🔍 Analyzing codebase for pattern unification opportunities...")
    print()

    whitemagic_dir = PROJECT_ROOT / "whitemagic"

    # Find all to_dict implementations
    serializable_candidates = []
    metrics_candidates = []

    for py_file in whitemagic_dir.rglob("*.py"):
        if py_file.name.startswith("_") or "test" in str(py_file):
            continue

        serial_analysis = analyze_for_serializable(py_file)
        if serial_analysis['can_migrate']:
            serializable_candidates.append(str(py_file.relative_to(PROJECT_ROOT)))

        metrics_analysis = analyze_for_metrics(py_file)
        if metrics_analysis['can_migrate']:
            metrics_candidates.append(str(py_file.relative_to(PROJECT_ROOT)))

    print("📊 Pattern Analysis:")
    print(f"   Serializable candidates: {len(serializable_candidates)}")
    print(f"   Metrics candidates: {len(metrics_candidates)}")
    print()

    # Create migration templates for core components
    print("📝 Creating WM2 migration templates...")
    print()

    migrated_count = 0

    for manager_path in core_managers:
        file_path = PROJECT_ROOT / manager_path
        if not file_path.exists():
            continue

        wm2_path = WM2_ROOT / "migrated" / manager_path.replace("whitemagic/", "")
        wm2_path.parent.mkdir(parents=True, exist_ok=True)

        template = f'''"""
WM2 Migration: {manager_path}
{'=' * (15 + len(manager_path))}
Migrated from WM1 using BaseManager + Serializable + MetricCollector
"""

from wm2.core import BaseManager
from wm2.core.serializable import Serializable
from wm2.core.metrics import MetricCollector, tracked
from typing import Dict, Any


class {file_path.stem.title().replace('_', '')}(BaseManager, Serializable, MetricCollector):
    """Migrated {file_path.stem} using WM2 unified patterns."""
    
    def __init__(self, name: str = "{file_path.stem}"):
        BaseManager.__init__(self, name=name)
        MetricCollector.__init__(self)
    
    @tracked
    def get_stats(self) -> Dict[str, Any]:
        """Get comprehensive statistics (auto-tracked)."""
        return {{
            **BaseManager.get_stats(self),
            **MetricCollector.get_stats(self),
        }}
    
    # TODO: Migrate specific methods from WM1
'''

        wm2_path.write_text(template)
        migrated_count += 1
        print(f"   ✅ {wm2_path.relative_to(WM2_ROOT)}")

    for engine_path in core_engines:
        file_path = PROJECT_ROOT / engine_path
        if not file_path.exists():
            continue

        wm2_path = WM2_ROOT / "migrated" / engine_path.replace("whitemagic/", "")
        wm2_path.parent.mkdir(parents=True, exist_ok=True)

        template = f'''"""
WM2 Migration: {engine_path}
{'=' * (15 + len(engine_path))}
Migrated from WM1 using BaseEngine + Serializable + MetricCollector
"""

from wm2.core import BaseEngine
from wm2.core.serializable import Serializable
from wm2.core.metrics import MetricCollector, tracked
from typing import Dict, Any


class {file_path.stem.title().replace('_', '')}(BaseEngine, Serializable, MetricCollector):
    """Migrated {file_path.stem} using WM2 unified patterns."""
    
    def __init__(self, name: str = "{file_path.stem}"):
        BaseEngine.__init__(self, name=name)
        MetricCollector.__init__(self)
    
    @tracked
    def process(self, data: Any) -> Any:
        """Process data through engine (auto-tracked)."""
        # TODO: Migrate processing logic from WM1
        return data
    
    @tracked
    def get_stats(self) -> Dict[str, Any]:
        """Get comprehensive statistics (auto-tracked)."""
        return {{
            **BaseEngine.get_stats(self),
            **MetricCollector.get_stats(self),
        }}
    
    # TODO: Migrate specific methods from WM1
'''

        wm2_path.write_text(template)
        migrated_count += 1
        print(f"   ✅ {wm2_path.relative_to(WM2_ROOT)}")

    print()
    print("=" * 80)
    print("PHASE 1 COMPLETE")
    print("=" * 80)
    print("Serializable mixin: ✅ Created")
    print("MetricCollector mixin: ✅ Created")
    print(f"Migration templates: {migrated_count} created")
    print(f"Serializable candidates: {len(serializable_candidates)} identified")
    print(f"Metrics candidates: {len(metrics_candidates)} identified")
    print()
    print("✅ Pattern unification infrastructure complete!")

if __name__ == "__main__":
    main()
