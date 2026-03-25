
import sys
import struct

def read_varint(data, offset):
    value = 0
    shift = 0
    while True:
        if offset >= len(data):
            raise IndexError("End of data while reading varint")
        byte = data[offset]
        offset += 1
        value |= (byte & 0x7F) << shift
        if not (byte & 0x80):
            break
        shift += 7
    return value, offset

def decode_proto(data, indent=0):
    offset = 0
    while offset < len(data):
        try:
            tag, new_offset = read_varint(data, offset)
            field_number = tag >> 3
            wire_type = tag & 0x07
            
            print("  " * indent + f"Field {field_number}: ", end="")
            
            offset = new_offset
            
            if wire_type == 0: # Varint
                value, offset = read_varint(data, offset)
                print(f"Varint: {value}")
                
            elif wire_type == 1: # 64-bit
                value = struct.unpack('<Q', data[offset:offset+8])[0]
                offset += 8
                print(f"64-bit: {value}")
                
            elif wire_type == 2: # Length-delimited
                length, offset = read_varint(data, offset)
                content = data[offset:offset+length]
                offset += length
                
                # Try as string
                try:
                    s = content.decode('utf-8')
                    if len(s) > 100: s = s[:100] + "..."
                    # Check if printable
                    if s.isprintable():
                        print(f"String ({length}): \"{s}\"")
                    else:
                         print(f"Bytes ({length})")
                         # Recursive check?
                         if length > 0:
                             print("  " * indent + "  -> Nested Message?")
                 #            decode_proto(content, indent + 1)
                except:
                    print(f"Bytes ({length})")
                    
            elif wire_type == 5: # 32-bit
                value = struct.unpack('<I', data[offset:offset+4])[0]
                offset += 4
                print(f"32-bit: {value}")
                
            else:
                print(f"Unknown Wire Type {wire_type}")
                break
                
        except Exception as e:
            print(f"Error parsing: {e}")
            break

if __name__ == "__main__":
    if len(sys.argv) > 1:
        with open(sys.argv[1], 'rb') as f:
            full_data = f.read()
            
        # Try offsets 0 to 50
        for start_offset in range(50):
            print(f"\n--- Trying Offset {start_offset} ---")
            try:
                # Basic check: First field should be reasonably small
                if start_offset + 10 < len(full_data):
                     tag, _ = read_varint(full_data, start_offset)
                     field = tag >> 3
                     wire = tag & 0x07
                     if field < 1000 and wire <= 5:
                         print(f"Candidate found at {start_offset}! Field {field} Wire {wire}")
                         decode_proto(full_data[start_offset:], indent=1)
                         break # Stop if it looks good (this is heuristic)
            except:
                pass
