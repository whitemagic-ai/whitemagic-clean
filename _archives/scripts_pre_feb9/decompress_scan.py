
import gzip
import zlib
import sys
import os
import re

def extract_strings(content):
    # Regex for printable text (len > 5)
    pattern = re.compile(rb'[\x20-\x7E]{5,}')
    found = []
    for match in pattern.finditer(content):
        try:
            text = match.group().decode('utf-8')
            found.append(text)
        except:
            pass
    return found

def probe_file(file_path):
    print(f"--- Probing {os.path.basename(file_path)} ---")
    with open(file_path, 'rb') as f:
        data = f.read()
    
    # Method 1: Raw Strings
    raw_strings = extract_strings(data)
    print(f"Raw: {len(raw_strings)} strings found.")
    
    # Method 2: Gzip
    try:
        decompressed_gz = gzip.decompress(data)
        gz_strings = extract_strings(decompressed_gz)
        print(f"GZIP: Success! Found {len(gz_strings)} strings.")
        return gz_strings
    except:
        print("GZIP: Failed")
        
    # Method 3: Zlib
    try:
        decompressed_zlib = zlib.decompress(data)
        zlib_strings = extract_strings(decompressed_zlib)
        print(f"ZLIB: Success! Found {len(zlib_strings)} strings.")
        return zlib_strings
    except:
        print("ZLIB: Failed")
    
    # Method 4: Snappy (if installed? no, assume not)
    # We'll just return raw if nothing else worked, maybe it's custom encoding.
    return raw_strings

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 decompress_scan.py <file>")
        sys.exit(1)
        
    strings = probe_file(sys.argv[1])
    
    # Print sample
    print("\n--- SAMPLE CONTENT ---")
    for s in strings[:100]:
        print(s)
