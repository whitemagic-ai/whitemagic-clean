import datetime
import json
import re
from pathlib import Path

# Paths
ROOT = Path("/home/lucas/Desktop/whitemagicdev")
FRONTEND_WEB = Path("/home/lucas/Desktop/wmfrontend/web")
FRONTEND_INDEX = FRONTEND_WEB / "index.html"
VERSION_FILE = ROOT / "VERSION"
LLMS_TXT = FRONTEND_WEB / "llms.txt"
SKILL_MD = FRONTEND_WEB / "skill.md"
AGENT_JSON = FRONTEND_WEB / ".well-known" / "agent.json"

# Extra docs
README_MD = ROOT / "README.md"
SYSTEM_MAP = ROOT / "SYSTEM_MAP.md"
AI_PRIMARY = ROOT / "AI_PRIMARY.md"

def read_version():
    return VERSION_FILE.read_text().strip()

def get_census_stats():
    census_md = ROOT / "reports" / "great_census.md"
    stats = {}
    if census_md.exists():
        content = census_md.read_text()
        py_match = re.search(r'\|\s*\*\*Python\*\*\s*\|\s*\*\*(\d+)\*\*\s*\|\s*\*\*([0-9,]+)\*\*', content)
        if py_match: stats["Python"] = py_match.group(2)

        for lang in ["Rust", "Zig", "Go", "Haskell", "Elixir", "TypeScript", "Mojo", "Julia", "Koka"]:
            match = re.search(r'\|\s*' + lang + r'\s*\|\s*\d+\s*\|\s*([0-9,]+)\s*\|', content)
            if match: stats[lang] = match.group(1)

        gt_match = re.search(r'\|\s*\*\*Grand total\*\*\s*\|\s*\*\*([\d,]+) files, ([0-9,]+) LOC\*\*', content)
        if gt_match:
            stats["total_files"] = gt_match.group(1)
            stats["total_loc"] = gt_match.group(2)
    return stats

def update_file_version_and_stats(filepath, version, stats=None):
    if not filepath.exists():
        return
    content = filepath.read_text()

    # Generic version bumps for v15.8 -> v18.1
    content = re.sub(r'v15\.8\.0', f'v{version}', content)
    content = re.sub(r'v15\.8', f'v{version[:4]}', content)

    today = datetime.datetime.now().strftime("%Y.%m.%d")
    content = re.sub(r'BUILD 2026\.\d+\.\d+', f'BUILD {today}', content)

    if stats and filepath.name == "index.html":
        for lang in ["Python", "Rust", "Zig", "Go", "Haskell", "Elixir", "TypeScript", "Mojo", "Julia", "Koka"]:
            if lang in stats:
                content = re.sub(rf'<div class="tilt-card lang-card"><h3>{lang} <span class="lang-pct">.*?</span></h3>', f'<div class="tilt-card lang-card"><h3>{lang} <span class="lang-pct">{stats[lang]} LOC</span></h3>', content)

    # For markdown files, update mentions of tools and LOC
    if stats and filepath.suffix == '.md':
        content = re.sub(r'\b11 languages\b', '11 languages', content)
        if 'total_loc' in stats:
            loc_millions = round(int(stats['total_loc'].replace(',', '')) / 1000000, 2)
            content = re.sub(r'\b[0-9\.]+M\+? LOC\b', f'{loc_millions}M LOC', content)
            content = re.sub(r'\b[0-9,]+ lines of code\b', f"{stats['total_loc']} lines of code", content)

    filepath.write_text(content)
    print(f"Updated {filepath}")

def update_agent_json(version):
    if not AGENT_JSON.exists(): return
    data = json.loads(AGENT_JSON.read_text())
    data["version"] = version
    AGENT_JSON.write_text(json.dumps(data, indent=2))
    print(f"Updated {AGENT_JSON}")

if __name__ == "__main__":
    version = read_version()
    print(f"Current version: {version}")
    stats = get_census_stats()

    for f in [FRONTEND_INDEX, LLMS_TXT, SKILL_MD, README_MD, SYSTEM_MAP, AI_PRIMARY]:
        update_file_version_and_stats(f, version, stats)

    update_agent_json(version)
    print("All core documentation updated to match current state.")
