
import sys
import re
from pathlib import Path

def extract_strings_from_pb(file_path):
    """
    Crude string extractor for binary protobuf files.
    We look for UTF-8 sequences that look like conversation text.
    """
    try:
        data = Path(file_path).read_bytes()
        # Regex for printable ASCII/UTF-8 strings of significant length
        # This filters out binary noise and short field tags
        strings = re.findall(b'[\x20-\x7E]{5,}', data)
        
        decoded = []
        for s in strings:
            try:
                decoded.append(s.decode('utf-8'))
            except UnicodeDecodeError:
                pass
        return decoded
    except Exception as e:
        return [f"Error reading {file_path}: {e}"]

def main():
    if len(sys.argv) < 2:
        print("Usage: extract_pb_strings.py <pb_file>")
        sys.exit(1)
        
    path = sys.argv[1]
    strings = extract_strings_from_pb(path)
    for s in strings:
        print(s)

if __name__ == "__main__":
    main()
