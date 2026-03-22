import json
import collections

whitemagicdev_files = []
dir_counts = collections.Counter()
ext_counts = collections.Counter()

with open("/home/lucas/Desktop/whitemagicdev/scout_results.jsonl", "r") as f:
    for line in f:
        line = line.strip()
        if not line: continue
        try:
            data = json.loads(line)
            path = data.get("path", "")
            if path.startswith("/home/lucas/Desktop/whitemagicdev/"):
                whitemagicdev_files.append(data)
                
                # Breakdown by top-level subdirectory inside whitemagicdev
                rel_path = path.replace("/home/lucas/Desktop/whitemagicdev/", "")
                parts = rel_path.split("/")
                if len(parts) > 1:
                    dir_counts[parts[0]] += 1
                else:
                    dir_counts["(root)"] += 1
                    
                ext = path.split('.')[-1] if '.' in path else 'unknown'
                ext_counts[ext] += 1
        except Exception:
            pass

# Sort by score (desc), then size (desc)
whitemagicdev_files.sort(key=lambda x: (x.get("score", 0), x.get("size", 0)), reverse=True)

print(f"Total whitemagicdev interesting files: {len(whitemagicdev_files)}\n")

print("--- Top Subdirectories in whitemagicdev ---")
for d, count in dir_counts.most_common(10):
    print(f"{d}: {count} files")

print("\n--- Top Extensions in whitemagicdev ---")
for ext, count in ext_counts.most_common(5):
    print(f".{ext}: {count} files")

print("\n--- Top 30 Highest Scoring Files in whitemagicdev ---")
for i, f in enumerate(whitemagicdev_files[:30]):
    rel_path = f['path'].replace("/home/lucas/Desktop/whitemagicdev/", "")
    size_kb = f['size'] / 1024
    print(f"{i+1}. {rel_path} (Score: {f['score']}, Size: {size_kb:.1f} KB)")

