import json
import collections

BLACKBOARD = {
    "total_files_scanned": 0,
    "interesting_files": [],
    "languages": collections.Counter(),
    "directories": collections.Counter(),
}

with open("/home/lucas/Desktop/whitemagicdev/scout_results.jsonl", "r") as f:
    for line in f:
        line = line.strip()
        if not line: continue
        
        try:
            payload = json.loads(line)
            
            if payload.get("type") == "file_scout":
                BLACKBOARD["total_files_scanned"] += 1
                path = payload.get("path", "")
                
                if not path:
                    continue
                    
                ext = path.split('.')[-1] if '.' in path else 'unknown'
                BLACKBOARD["languages"][ext] += 1
                
                parts = path.split('/')
                base_dir = '/'.join(parts[:5]) if len(parts) >= 5 else path
                BLACKBOARD["directories"][base_dir] += 1
                
                if payload.get("interesting"):
                    BLACKBOARD["interesting_files"].append({
                        "path": path,
                        "size": payload.get("size", 0),
                        "score": payload.get("score", 0)
                    })
        except Exception:
            pass

report_path = "/home/lucas/Desktop/whitemagicdev/reports/SCOUT_SWARM_INTELLIGENCE.md"
print(f"Writing Intelligence Report to {report_path}...")

with open(report_path, "w") as f:
    f.write("# Scout Swarm Intelligence Report\\n\\n")
    f.write(f"**Highly Interesting Target Files Identified:** {BLACKBOARD['total_files_scanned']}\\n\\n")
    
    f.write("## Target Ecosystem Breakdown\\n")
    for dir_path, count in BLACKBOARD["directories"].most_common(20):
        f.write(f"- `{dir_path}`: {count} interesting files\\n")
        
    f.write("\\n## Language Distribution of Interesting Files\\n")
    for ext, count in BLACKBOARD["languages"].most_common(20):
        f.write(f"- `.{ext}`: {count} files\\n")
        
    f.write("\\n## Top 100 Most Relevant Files (Sorted by Heuristic Score)\\n")
    
    sorted_files = sorted(BLACKBOARD["interesting_files"], key=lambda x: (x.get("score", 0), x.get("size", 0)), reverse=True)
    seen = set()
    count = 0
    for file_obj in sorted_files:
        if file_obj['path'] in seen:
            continue
        seen.add(file_obj['path'])
        size_kb = file_obj["size"] / 1024
        score = file_obj.get("score", 0)
        f.write(f"{count+1}. `{file_obj['path']}` (Score: {score}, {size_kb:.2f} KB)\\n")
        count += 1
        if count >= 100:
            break
            
print(f"Done. Processed {BLACKBOARD['total_files_scanned']} interesting files.")
