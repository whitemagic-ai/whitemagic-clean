
import sys
import os

# Add venv to path
# Add venv to path relative to this script
script_dir = os.path.dirname(os.path.abspath(__file__))
# Assuming scripts/ is inside staging/core_system/
venv_path = os.path.join(script_dir, "..", ".venv", "lib", "python3.12", "site-packages")
sys.path.insert(0, venv_path)

from google.protobuf.internal import decoder

def inspect(filepath):
    with open(filepath, 'rb') as f:
        data = f.read()
        
    print(f"Read {len(data)} bytes from {filepath}")
    
    # Python's protobuf library doesn't expose a simple "decode_raw" easily without a class.
    # However, we can try to use the internal decoder to just walk the tags.
    
    position = 0
    end = len(data)
    
    while position < end:
        try:
            (tag_bytes, position) = decoder._DecodeVarint(data, position)
            field_number = tag_bytes >> 3
            wire_type = tag_bytes & 0x07
            
            print(f"Field {field_number} (Wire {wire_type})")
            
            if wire_type == 0: # Varint
                (value, position) = decoder._DecodeVarint(data, position)
                print(f"  Varint: {value}")
            elif wire_type == 1: # 64-bit
                position += 8
                print("  64-bit value")
            elif wire_type == 2: # Length-delimited
                (length, position) = decoder._DecodeVarint(data, position)
                print(f"  Length-delimited: {length} bytes")
                # Peek content
                content = data[position:position+length]
                try:
                    s = content.decode('utf-8')
                    if s.isprintable() and len(s) > 2:
                        print(f"  String: {s[:100]}")
                except:
                    pass
                position += length
            elif wire_type == 5: # 32-bit
                position += 4
                print("  32-bit value")
            else:
                print(f"  Unknown wire type {wire_type}, aborting")
                break
        except Exception as e:
            print(f"Error: {e}")
            break

if __name__ == "__main__":
    inspect(sys.argv[1])
