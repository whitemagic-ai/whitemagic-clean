import os
import re

def scrub_identities(root_dir: str):
    """
    Search and replace hardcoded paths and identities in the codebase.
    """
    # Define patterns to scrub
    patterns = {
        r"/home/[^/\\s]+/Desktop/whitemagic": "<REPO_ROOT>",
        r"/home/[^/\\s]+/Desktop/WHITE MAGIC": "<REPO_ROOT>",
        r"/home/[^/\\s]+/Desktop": "<DESKTOP>",
        r"/home/[^/\\s]+": "$HOME",
        r'"lucas",': '"creator",',
        r'"aria",': '"guide",',
    }
    
    # Files to ignore
    ignore_dirs = {'.venv', '.git', '__pycache__', 'target', '.cargo'}
    
    count = 0
    for dirpath, dirnames, filenames in os.walk(root_dir):
        # Filter directories
        dirnames[:] = [d for d in dirnames if d not in ignore_dirs]
        
        for filename in filenames:
            if filename.endswith(('.py', '.rs', '.go', '.ex', '.html', '.md', '.txt')):
                filepath = os.path.join(dirpath, filename)
                try:
                    with open(filepath, 'r', encoding='utf-8') as f:
                        content = f.read()
                    
                    new_content = content
                    for pattern, replacement in patterns.items():
                        new_content = re.sub(pattern, replacement, new_content)
                    
                    if new_content != content:
                        with open(filepath, 'w', encoding='utf-8') as f:
                            f.write(new_content)
                        print(f"✅ Scrubbed: {filepath}")
                        count += 1
                except Exception as e:
                    print(f"⚠️ Failed to scrub {filepath}: {e}")
                    
    print(f"✨ Identity scrubbing complete. {count} files sanitized.")

if __name__ == "__main__":
    import sys
    root = sys.argv[1] if len(sys.argv) > 1 else "."
    scrub_identities(root)
