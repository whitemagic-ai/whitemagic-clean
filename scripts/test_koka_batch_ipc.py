import subprocess
import json
import time

def test_koka_batch():
    proc = subprocess.Popen(
        ['/home/lucas/Desktop/whitemagicdev/whitemagic-koka/batch_ipc'],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=True
    )
    
    # Read initialization line
    init_line = proc.stdout.readline()
    print("Init:", init_line.strip())
    
    # Test single
    proc.stdin.write('{"op":"ping"}\n')
    proc.stdin.flush()
    print("Single response:", proc.stdout.readline().strip())
    
    # Test batch
    batch_req = '{"mode":"sequential","request_id":"test-123","commands":[{"id":0,"op":"ping","payload":{}},{"id":1,"op":"ping","payload":{}}]}'
    proc.stdin.write(batch_req + '\n')
    proc.stdin.flush()
    
    start = time.time()
    response = proc.stdout.readline().strip()
    end = time.time()
    
    print("Batch response:", response)
    print(f"Time: {(end-start)*1000:.2f}ms")
    
    proc.stdin.write('quit\n')
    proc.stdin.flush()
    
test_koka_batch()
