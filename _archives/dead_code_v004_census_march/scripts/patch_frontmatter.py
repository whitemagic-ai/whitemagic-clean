import os
import re

files_to_patch = {
    "/home/lucas/Desktop/whitemagicdev/campaigns/S023_koka_hot_path_activation.md": r"priority: P1",
    "/home/lucas/Desktop/whitemagicdev/campaigns/P001_MandalaOS_Kernel.md": r"priority: P0"
}

for filepath, search_pattern in files_to_patch.items():
    if not os.path.exists(filepath):
        print(f"File not found: {filepath}")
        continue
        
    with open(filepath, "r") as f:
        content = f.read()
        
    if "priority: 1" in content or "priority: 0" in content:
        print(f"Already patched: {filepath}")
        continue
        
    new_content = re.sub(search_pattern, search_pattern.replace("P", ""), content)
    
    with open(filepath, "w") as f:
        f.write(new_content)
        
    print(f"Patched: {filepath}")
