import json
import collections

wm_archive_files = []
dir_counts = collections.Counter()
ext_counts = collections.Counter()

with open("/home/lucas/Desktop/whitemagicdev/scout_results.jsonl", "r") as f:
    for line in f:
        line = line.strip()
        if not line: continue
        try:
            data = json.loads(line)
            path = data.get("path", "")
            if path.startswith("/home/lucas/Desktop/wm_archive/"):
                wm_archive_files.append(data)
                
                # Breakdown by top-level subdirectory inside wm_archive
                rel_path = path.replace("/home/lucas/Desktop/wm_archive/", "")
                parts = rel_path.split("/")
                if len(parts) > 1:
                    dir_counts[parts[0]] += 1
                else:
                    dir_counts["(root)"] += 1
                    
                ext = path.split('.')[-1] if '.' in path else 'unknown'
                ext_counts[ext] += 1
        except Exception:
            pass

wm_archive_files.sort(key=lambda x: (x.get("score", 0), x.get("size", 0)), reverse=True)

print(f"Total wm_archive interesting files: {len(wm_archive_files)}\n")

print("--- Top Subdirectories in wm_archive ---")
for d, count in dir_counts.most_common(10):
    print(f"{d}: {count} files")

print("\n--- Top Extensions in wm_archive ---")
for ext, count in ext_counts.most_common(5):
    print(f".{ext}: {count} files")

print("\n--- Top 30 Highest Scoring Files in wm_archive ---")
for i, f in enumerate(wm_archive_files[:30]):
    rel_path = f['path'].replace("/home/lucas/Desktop/wm_archive/", "")
    size_kb = f['size'] / 1024
    print(f"{i+1}. {rel_path} (Score: {f['score']}, Size: {size_kb:.1f} KB)")

