#!/usr/bin/env python3
"""
Auto-generate API_REFERENCE.md from TOOL_REGISTRY.

Usage:
    python scripts/generate_api_docs.py              # stdout
    python scripts/generate_api_docs.py -o docs/API_REFERENCE.md  # file
"""

from __future__ import annotations
import argparse
import sys
import os
from collections import defaultdict
from datetime import datetime

sys.path.insert(0, os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from whitemagic.tools.registry import TOOL_REGISTRY


def generate_docs() -> str:
    by_cat: dict[str, list] = defaultdict(list)
    for t in TOOL_REGISTRY:
        by_cat[t.category.value].append(t)

    lines = [
        "# WhiteMagic API Reference",
        "",
        f"> Auto-generated on {datetime.now().strftime('%Y-%m-%d %H:%M')} — "
        f"**{len(TOOL_REGISTRY)} tools** across **{len(by_cat)} categories**",
        "",
        "## Table of Contents",
        "",
    ]

    # TOC
    for cat in sorted(by_cat.keys()):
        tools = by_cat[cat]
        lines.append(f"- **{cat.upper()}** ({len(tools)} tools)")

    lines.append("")

    # Per-category sections
    for cat in sorted(by_cat.keys()):
        tools = sorted(by_cat[cat], key=lambda t: t.name)
        lines.append(f"## {cat.upper()}")
        lines.append("")

        for t in tools:
            lines.append(f"### `{t.name}`")
            lines.append("")
            lines.append(f"**Safety**: `{t.safety.value}` | **Category**: `{cat}`")

            if t.gana:
                lines.append(f"**Mandala**: {t.gana} / {t.garden} / {t.quadrant} / {t.element}")

            lines.append("")
            lines.append(t.description[:500])
            lines.append("")

            # Parameters
            props = t.input_schema.get("properties", {})
            required = set(t.input_schema.get("required", []))
            if props:
                lines.append("| Parameter | Type | Required | Description |")
                lines.append("|-----------|------|----------|-------------|")
                for pname, pschema in props.items():
                    ptype = pschema.get("type", "any")
                    if "enum" in pschema:
                        ptype = " \\| ".join(f"`{v}`" for v in pschema["enum"])
                    req = "Yes" if pname in required else "No"
                    desc = pschema.get("description", "")
                    lines.append(f"| `{pname}` | {ptype} | {req} | {desc} |")
                lines.append("")

            lines.append("---")
            lines.append("")

    return "\n".join(lines)


def main():
    parser = argparse.ArgumentParser(description="Generate API docs from TOOL_REGISTRY")
    parser.add_argument("-o", "--output", help="Output file path")
    args = parser.parse_args()

    docs = generate_docs()
    if args.output:
        os.makedirs(os.path.dirname(args.output) or ".", exist_ok=True)
        with open(args.output, "w") as f:
            f.write(docs)
        print(f"Wrote {len(docs)} bytes to {args.output}")
    else:
        print(docs)


if __name__ == "__main__":
    main()
