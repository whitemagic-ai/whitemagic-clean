
import os
import re
import json
import sys
from pathlib import Path
from typing import List, Dict

# Config
MIN_STRING_LENGTH = 8
CHAT_KEYWORDS = [
    "user", "assistant", "model", "prompt", "completion", 
    "Windsurf", "Cascade", "chat", "history", "CORTEX", "LLAMA", 
    "STEP", "token", "payload"
]

def extract_strings_from_binary(file_path: Path) -> List[str]:
    """Extract printable strings from a binary file."""
    with open(file_path, 'rb') as f:
        content = f.read()
        
    # Regex for printable ASCII/UTF-8 strings (include tab/newline)
    # Reduced length to 8 to catch short keys like "role"
    pattern = re.compile(rb'[\x09\x20-\x7E]{8,}')
    
    strings = []
    for match in pattern.finditer(content):
        try:
            decoded = match.group().decode('utf-8', errors='ignore')
            # Filter out pure garbage (e.g. "       ")
            if decoded.strip():
                strings.append(decoded)
        except Exception:
            pass
            
    return strings

def parse_chat_fragment(text: str) -> Dict:
    """Attempt to parse a string as a chat fragment."""
    score = 0
    
    # Keyword scoring
    for kw in CHAT_KEYWORDS:
        if kw in text:
            score += 1
            
    # Structure scoring
    if text.startswith('{') or text.startswith('['):
        score += 1
    if '"' in text and ':' in text: # JSON-like key:value
        score += 1
    if len(text) > 50: # Longer text is more likely content
        score += 1
        
    return {
        "text": text,
        "score": score
    }

def scan_directory(input_dir: Path, output_file: Path):
    print(f"Scanning {input_dir} for LevelDB files...")
    
    all_fragments = []
    
    # Walk through directory
    for root, dirs, files in os.walk(input_dir):
        for file in files:
            if file.endswith('.ldb') or file.endswith('.log'):
                path = Path(root) / file
                print(f"Processing {file}...")
                
                strings = extract_strings_from_binary(path)
                for s in strings:
                    fragment = parse_chat_fragment(s)
                    if fragment['score'] > 2:
                        all_fragments.append(fragment)

    print(f"Found {len(all_fragments)} potential chat fragments.")
    
    # Sort by likely relevance (score)
    all_fragments.sort(key=lambda x: x['score'], reverse=True)
    
    # Deduplicate
    unique_fragments = []
    seen = set()
    for f in all_fragments:
        if f['text'] not in seen:
            unique_fragments.append(f)
            seen.add(f['text'])
            
    print(f"Reduced to {len(unique_fragments)} unique fragments.")
    
    # Save
    with open(output_file, 'w') as f:
        json.dump(unique_fragments, f, indent=2)
        
    print(f"Saved artifacts to {output_file}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 extract_leveldb_chat.py <input_dir> [output_file]")
        sys.exit(1)
        
    input_path = Path(sys.argv[1])
    output_path = Path(sys.argv[2]) if len(sys.argv) > 2 else Path("recovered_chat_fragments.json")
    
    scan_directory(input_path, output_path)
