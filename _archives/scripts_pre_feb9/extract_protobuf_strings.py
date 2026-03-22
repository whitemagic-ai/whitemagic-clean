
import sys
import os

def read_varint(data, offset):
    """Read a varint from data starting at offset."""
    value = 0
    shift = 0
    while True:
        if offset >= len(data):
            raise IndexError("Varint read out of bounds")
        byte = data[offset]
        offset += 1
        value |= (byte & 0x7F) << shift
        if not (byte & 0x80):
            break
        shift += 7
    return value, offset

def extract_strings(file_path):
    print(f"--- Extracting strings from {os.path.basename(file_path)} ---")
    with open(file_path, 'rb') as f:
        data = f.read()

    offset = 0
    extracted = []
    
    while offset < len(data):
        try:
            # Read Tag (Key)
            tag, new_offset = read_varint(data, offset)
            wire_type = tag & 0x07
            field_number = tag >> 3
            
            offset = new_offset
            
            if wire_type == 0: # Varint
                _, offset = read_varint(data, offset)
            elif wire_type == 1: # 64-bit
                offset += 8
            elif wire_type == 5: # 32-bit
                offset += 4
            elif wire_type == 2: # Length Delimited (String/Bytes/Message)
                length, offset = read_varint(data, offset)
                
                if offset + length > len(data):
                    # print(f"Warning: Length {length} exceeds file size at offset {offset}")
                    break
                    
                payload = data[offset:offset+length]
                
                # Recursively try to parse? No, just check if it's text.
                try:
                    # Heuristic: If it decodes to UTF-8 and looks like text
                    text = payload.decode('utf-8')
                    # Filter for chat-like content
                    if len(text) > 10 and any(c.isprintable() for c in text):
                         # Further clean up: remove excessive control chars
                         clean_text = "".join(c for c in text if c.isprintable() or c in "\n\t")
                         if len(clean_text) > 5:
                             print(f"[{field_number}]: {clean_text[:100]}..." if len(clean_text) > 100 else f"[{field_number}]: {clean_text}")
                             extracted.append(clean_text)
                except UnicodeDecodeError:
                    # It might be a nested message. We just skip it for now.
                    # Or we could recurse, but let's keep it simple.
                    pass
                
                offset += length
            elif wire_type == 3 or wire_type == 4: # Groups (deprecated)
                pass # Hard to skip without parsing
            else:
                # print(f"Unknown wire type {wire_type} at offset {offset}")
                offset += 1 # Try to recover?
                
        except Exception:
            # print(f"Error parse loop: {e}")
            break
            
    return extracted

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 extract_protobuf_strings.py <pb_file>")
        sys.exit(1)
    extract_strings(sys.argv[1])
