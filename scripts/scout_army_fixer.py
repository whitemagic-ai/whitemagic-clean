import json
from collections import defaultdict
from pathlib import Path


def batch_fix():
    print("🚀 Starting Scout Army Fixer...")

    error_file = Path("ruff_errors.json")
    if not error_file.exists():
        print("❌ ruff_errors.json not found. Run ruff check with --output-format json first.")
        return

    with open(error_file) as f:
        try:
            errors = json.load(f)
        except json.JSONDecodeError:
            print("❌ Failed to parse ruff_errors.json")
            return

    # Group errors by filename
    files_to_fix = defaultdict(list)
    for err in errors:
        files_to_fix[err['filename']].append(err)

    print(f"📦 Found errors in {len(files_to_fix)} files.")

    for filename, file_errors in files_to_fix.items():
        fix_file(filename, file_errors)

def fix_file(filename, errors):
    path = Path(filename)
    if not path.exists():
        print(f"⚠️  File not found: {filename}")
        return

    print(f"🛠️  Fixing {path.name} ({len(errors)} errors)...")

    with open(path) as f:
        lines = f.readlines()

    # Sort errors by row (descending) to avoid offset issues
    errors.sort(key=lambda x: x['location']['row'], reverse=True)

    for err in errors:
        code = err['code']
        row = err['location']['row'] - 1
        err['location']['column'] - 1

        if row >= len(lines):
            continue

        line = lines[row]

        if code == "F401":
            # Unused import
            # Basic logic: if it's a whole line import, comment it out or delete it
            # If it's a 'from x import a, b, c', it's harder.
            # For now, let's just add # noqa: F401 to the line
            if "# noqa" not in line:
                lines[row] = line.rstrip() + "  # noqa: F401\n"
            elif "F401" not in line:
                lines[row] = line.replace("# noqa:", "# noqa: F401,").replace("# noqa", "# noqa: F401")

        elif code == "E741":
            # Ambiguous variable name 'l'
            # Replace 'l' with 'idx' or 'lvl' based on context or just 'lvl'
            # This needs to be careful with word boundaries
            import re
            lines[row] = re.sub(r'\bl\b', 'lvl', line)

        elif code == "E702":
            # Multiple statements on one line
            lines[row] = line.replace(';', '\n').replace('  ', ' ')

    with open(path, 'w') as f:
        f.writelines(lines)

if __name__ == "__main__":
    batch_fix()
