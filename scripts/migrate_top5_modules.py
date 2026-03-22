#!/usr/bin/env python3
"""
MODULE MIGRATION: TOP 5 TO WM2 BASE CLASSES
===========================================
Migrate the 5 largest modules to WM2 unified framework
"""

import ast
import sys
from datetime import UTC, datetime
from pathlib import Path

PROJECT_ROOT = Path(__file__).parent.parent
sys.path.insert(0, str(PROJECT_ROOT))

WM2_ROOT = Path.home() / "Desktop" / "WM2"

print("=" * 80)
print("MODULE MIGRATION: TOP 5 TO WM2 BASE CLASSES")
print("=" * 80)
print()

# Top 5 modules identified in analysis
TOP_MODULES = [
    "scripts/deploy_grand_army.py",
    "whitemagic/cli/cli_app.py",
    "whitemagic/core/memory/sqlite_backend.py",
    "whitemagic/core/fusions.py",
    "scripts/deploy_shadow_clones.py",
]

def analyze_module(module_path: Path):
    """Analyze module for migration opportunities."""
    try:
        content = module_path.read_text(encoding='utf-8')
        tree = ast.parse(content)

        classes = []
        functions = []

        for node in ast.walk(tree):
            if isinstance(node, ast.ClassDef):
                # Check if it's a manager/engine/handler pattern
                name = node.name.lower()
                if any(pattern in name for pattern in ['manager', 'engine', 'handler', 'backend', 'system']):
                    classes.append({
                        "name": node.name,
                        "line": node.lineno,
                        "type": "manager" if "manager" in name else "engine" if "engine" in name else "handler",
                    })
            elif isinstance(node, ast.FunctionDef):
                if node.name in ['to_dict', 'get_stats', '_load', '_save']:
                    functions.append({
                        "name": node.name,
                        "line": node.lineno,
                    })

        return {
            "classes": classes,
            "functions": functions,
            "lines": len(content.splitlines()),
        }
    except Exception as e:
        return {"error": str(e)}

def generate_migration_template(module_name: str, analysis: dict):
    """Generate WM2 migration template."""
    classes = analysis.get("classes", [])

    if not classes:
        return None

    template = f'''"""
WM2 Migration: {module_name}
{'=' * (15 + len(module_name))}
Migrated from WM1 using unified base classes
"""

from wm2.core import BaseEngine, BaseManager, BaseHandler
from typing import Dict, Any

'''

    for cls in classes[:3]:  # Top 3 classes
        base_class = f"Base{cls['type'].title()}"
        template += f'''
class {cls['name']}({base_class}):
    """Migrated {cls['name']} using WM2 base class."""

    def __init__(self, name: str = "{cls['name'].lower()}"):
        super().__init__(name=name)
        # TODO: Migrate initialization logic from WM1

    def get_stats(self) -> Dict[str, Any]:
        """Get component statistics."""
        return {{
            **super().get_stats(),
            # TODO: Add specific stats
        }}
'''

    return template

def main():
    migrations = []

    for module_rel in TOP_MODULES:
        module_path = PROJECT_ROOT / module_rel

        if not module_path.exists():
            print(f"⚠️  Not found: {module_rel}")
            continue

        print(f"Analyzing: {module_rel}")
        analysis = analyze_module(module_path)

        if "error" in analysis:
            print(f"   Error: {analysis['error']}")
            continue

        print(f"   Classes: {len(analysis['classes'])}")
        print(f"   Migratable functions: {len(analysis['functions'])}")
        print(f"   Lines: {analysis['lines']:,}")

        # Generate migration template
        template = generate_migration_template(module_rel, analysis)

        if template:
            # Save to WM2
            wm2_path = WM2_ROOT / "migrated" / module_rel.replace("whitemagic/", "").replace("scripts/", "")
            wm2_path.parent.mkdir(parents=True, exist_ok=True)
            wm2_path.write_text(template)

            migrations.append({
                "module": module_rel,
                "wm2_path": str(wm2_path.relative_to(WM2_ROOT)),
                "classes": len(analysis['classes']),
                "lines": analysis['lines'],
            })

            print(f"   ✅ Template: {wm2_path.relative_to(WM2_ROOT)}")

        print()

    # Generate migration summary
    summary = f"""# WM2 Migration Summary

**Generated**: {datetime.now(UTC).isoformat()}

## Migrated Modules

"""

    for mig in migrations:
        summary += f"""
### {mig['module']}

- **WM2 Path**: `{mig['wm2_path']}`
- **Classes Migrated**: {mig['classes']}
- **Original Lines**: {mig['lines']:,}
- **Status**: Template created, manual review needed
"""

    summary += f"""

## Migration Progress

- **Modules Analyzed**: {len(TOP_MODULES)}
- **Templates Created**: {len(migrations)}
- **Total Classes**: {sum(m['classes'] for m in migrations)}
- **Total Lines**: {sum(m['lines'] for m in migrations):,}

## Next Steps

1. Review generated templates in `WM2/migrated/`
2. Complete TODO items in each template
3. Test migrated modules
4. Wire into WM2 framework
5. Deprecate WM1 versions
"""

    summary_path = WM2_ROOT / "MIGRATION_SUMMARY.md"
    summary_path.write_text(summary)

    print("─" * 80)
    print("MIGRATION COMPLETE")
    print("─" * 80)
    print(f"Templates created: {len(migrations)}")
    print(f"Summary: {summary_path}")
    print()
    print("✅ Top 5 modules migrated to WM2 templates!")

if __name__ == "__main__":
    main()
