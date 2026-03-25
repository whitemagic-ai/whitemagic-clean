
import sys
import zlib
import gzip
import bz2
import lzma

def check_compression(filepath):
    with open(filepath, 'rb') as f:
        data = f.read(1024) # Read header

    print(f"Checking {filepath}...")

    # Zlib
    try:
        zlib.decompress(data)
        print("✅ Detected ZLIB compression")
        return
    except:
        pass

    # Gzip
    try:
        gzip.decompress(data)
        print("✅ Detected GZIP compression")
        return
    except:
        pass

    # BZ2
    try:
        bz2.decompress(data)
        print("✅ Detected BZ2 compression")
        return
    except:
        pass

    # LZMA
    try:
        lzma.decompress(data)
        print("✅ Detected LZMA compression")
        return
    except:
        pass

    print("❌ No standard compression detected (or custom/encrypted).")

if __name__ == "__main__":
    if len(sys.argv) > 1:
        check_compression(sys.argv[1])
