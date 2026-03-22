
import sys
import json
import blackboxprotobuf

def decode(filepath):
    with open(filepath, 'rb') as f:
        data = f.read()

    print(f"Decoding {len(data)} bytes from {filepath}...")
    try:
        # Decode the message
        # message is a dict, typedef is a dict descriptor
        message, typedef = blackboxprotobuf.decode_message(data)
        
        print("\n--- Structure Found ---")
        print(json.dumps(message, indent=2, default=str)[:2000] + "...") # Print first 2k chars
        
        print("\n--- Type Definition ---")
        print(json.dumps(typedef, indent=2)[:1000] + "...")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    filepath = sys.argv[1]
    with open(filepath, 'rb') as f:
        full_data = f.read()
        
    for offset in range(100):
        try:
            # print(f"Trying offset {offset}...")
            message, typedef = blackboxprotobuf.decode_message(full_data[offset:])
            print(f"\n✅ SUCCESS at offset {offset}!")
            print(json.dumps(message, indent=2, default=str)[:2000])
            break
        except Exception:
            # print(f"Offset {offset} failed: {e}")
            pass
    else:
        print("❌ Could not decode at any offset 0-100.")
