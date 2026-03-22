
import sys
import re

def inspect_pb(filepath):
    try:
        with open(filepath, 'rb') as f:
            data = f.read()
            
        print(f"--- File: {filepath} ---")
        print(f"Total size: {len(data)} bytes")
        print("\n--- First 200 bytes (Hex) ---")
        print(data[:200].hex(' '))
        
        print("\n--- Strings Extraction (heuristic) ---")
        # Find printable strings > 4 chars
        strings = re.findall(rb'[ -~]{5,}', data)
        for i, s in enumerate(strings[:20]):
            try:
                print(f"{i}: {s.decode('utf-8')}")
            except:
                pass
                
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        inspect_pb(sys.argv[1])
