#!/usr/bin/env python3
"""Find Python modules with no external importers (dead code candidates).

Handles:
  - Standard import / from-import statements
  - __init__.py re-exports (from .module import ...)
  - Dynamic importlib.import_module("...") calls
  - LazyHandler("module_name", ...) dispatch table references
  - registry_defs/ and tests/ references

Writes report to /tmp/wm_dead_modules.txt
"""
import os
import re
from collections import defaultdict

REPORT = "/tmp/wm_dead_modules.txt"
PKG = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "whitemagic")
IGNORE = {"__pycache__", "_archived"}

# ── Collect all .py source files (excluding __init__.py) ──
files = []
init_files = []
for root, dirs, fnames in os.walk(PKG):
    dirs[:] = [d for d in dirs if d not in IGNORE]
    for f in fnames:
        if f.endswith(".py"):
            fp = os.path.join(root, f)
            if f == "__init__.py":
                init_files.append(fp)
            else:
                files.append(fp)

# ── Read all file contents ──
texts = {}
for fp in files + init_files:
    with open(fp) as fh:
        texts[fp] = fh.read()

# ── Build the full text corpus (package + tests + scripts) ──
all_text = "\n".join(texts.values())
_PROJECT_ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
for extra_dir in [os.path.join(_PROJECT_ROOT, "tests"),
                  os.path.join(_PROJECT_ROOT, "scripts")]:
    if os.path.isdir(extra_dir):
        for root, dirs, fnames in os.walk(extra_dir):
            dirs[:] = [d for d in dirs if d not in IGNORE]
            for f in fnames:
                if f.endswith(".py"):
                    try:
                        with open(os.path.join(root, f)) as fh:
                            all_text += "\n" + fh.read()
                    except Exception:
                        pass

# ── Build set of referenced module names using multiple strategies ──
referenced = set()

# Strategy 1: substring match (original — catches most imports)
# Strategy 2: __init__.py re-exports (from .foo import bar)
RE_INIT_REEXPORT = re.compile(r"from\s+\.(\w+)\s+import")
for init_fp in init_files:
    for m in RE_INIT_REEXPORT.finditer(texts[init_fp]):
        referenced.add(m.group(1))

# Strategy 3: importlib.import_module("whitemagic.foo.bar") → "bar"
RE_IMPORTLIB = re.compile(r'import_module\(\s*["\']([^"\']+)["\']\s*\)')
for m in RE_IMPORTLIB.finditer(all_text):
    parts = m.group(1).split(".")
    for part in parts:
        referenced.add(part)

# Strategy 4: LazyHandler("module_name", "func_name") in dispatch table
RE_LAZY = re.compile(r'LazyHandler\(\s*["\'](\w+)["\']')
for m in RE_LAZY.finditer(all_text):
    referenced.add(m.group(1))

# Strategy 5: dotted path references like "whitemagic.gardens.browser"
RE_DOTTED = re.compile(r'whitemagic\.[\w.]+')
for m in RE_DOTTED.finditer(all_text):
    parts = m.group(0).split(".")
    for part in parts:
        referenced.add(part)

# Strategy 6: pkgutil auto-discovery — if a package __init__.py uses pkgutil
# to iterate submodules, all .py files in that package are considered referenced.
for init_fp in init_files:
    content = texts[init_fp]
    if "pkgutil" in content and ("iter_modules" in content or "walk_packages" in content):
        pkg_dir = os.path.dirname(init_fp)
        for f in os.listdir(pkg_dir):
            if f.endswith(".py") and f != "__init__.py":
                referenced.add(f.replace(".py", ""))

# ── Detect dead modules ──
lines = []
lines.append(f"Collected {len(files)} source files\n")

dead = []
for fp in files:
    base = os.path.basename(fp).replace(".py", "")
    if base.startswith("test_") or base.startswith("verify_"):
        continue
    if "/handlers/" in fp:
        continue

    # Check explicit reference set first
    if base in referenced:
        continue

    # Fallback: substring count (catches references as dict keys, strings, etc.)
    count_total = all_text.count(base)
    count_own = texts[fp].count(base)
    if count_total - count_own <= 1:
        loc = texts[fp].count("\n") + 1
        rel = fp.replace(PKG + os.sep, "")
        cat = rel.split("/")[0] if "/" in rel else "root"
        dead.append((loc, rel, cat))

dead.sort(reverse=True)
total_loc = sum(x[0] for x in dead)

cats = defaultdict(list)
for loc, fp, cat in dead:
    cats[cat].append((loc, fp))

lines.append(f"{len(dead)} dead modules, {total_loc} LOC\n")
for cat in sorted(cats, key=lambda c: -sum(x[0] for x in cats[c])):
    items = cats[cat]
    cat_loc = sum(x[0] for x in items)
    lines.append(f"=== {cat}/ ({len(items)} files, {cat_loc} LOC) ===")
    for loc, fp in sorted(items, reverse=True)[:6]:
        lines.append(f"  {loc:5d}  {fp}")
    if len(items) > 6:
        lines.append(f"  ... +{len(items)-6} more")
    lines.append("")

with open(REPORT, "w") as f:
    f.write("\n".join(lines))

print(f"Report: {REPORT}")
print(f"  {len(files)} source files scanned")
print(f"  {len(dead)} dead modules, {total_loc} LOC")
