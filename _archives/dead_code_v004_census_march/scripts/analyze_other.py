import json
import collections

other_files = []
dir_counts = collections.Counter()
ext_counts = collections.Counter()

target_dirs = [
    "/home/lucas/Desktop/whitemagicpublic/",
    "/home/lucas/Desktop/aria-crystallized/",
    "/home/lucas/Desktop/WM2/",
    "/home/lucas/Desktop/wmfrontend/"
]

with open("/home/lucas/Desktop/whitemagicdev/scout_results.jsonl", "r") as f:
    for line in f:
        line = line.strip()
        if not line: continue
        try:
            data = json.loads(line)
            path = data.get("path", "")
            
            is_other = False
            for td in target_dirs:
                if path.startswith(td):
                    is_other = True
                    break
            
            if is_other:
                other_files.append(data)
                
                # Breakdown by top-level root
                root_dir = ""
                for td in target_dirs:
                    if path.startswith(td):
                        root_dir = td
                        break
                
                rel_path = path.replace(root_dir, "")
                parts = rel_path.split("/")
                if len(parts) > 1:
                    dir_counts[root_dir + parts[0]] += 1
                else:
                    dir_counts[root_dir + "(root)"] += 1
                    
                ext = path.split('.')[-1] if '.' in path else 'unknown'
                ext_counts[ext] += 1
        except Exception:
            pass

other_files.sort(key=lambda x: (x.get("score", 0), x.get("size", 0)), reverse=True)

print(f"Total other interesting files: {len(other_files)}\n")

print("--- Top Directories in Other Repos ---")
for d, count in dir_counts.most_common(10):
    print(f"{d}: {count} files")

print("\n--- Top Extensions in Other Repos ---")
for ext, count in ext_counts.most_common(5):
    print(f".{ext}: {count} files")

print("\n--- Top 30 Highest Scoring Files in Other Repos ---")
for i, f in enumerate(other_files[:30]):
    size_kb = f['size'] / 1024
    print(f"{i+1}. {f['path']} (Score: {f['score']}, Size: {size_kb:.1f} KB)")

