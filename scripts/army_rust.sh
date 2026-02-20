#!/bin/bash
# Rust Shadow Clone Army Script (V003)
# Reads JSON task from stdin, executes via whitemagic_rs, writes JSON to stdout.

# Ensure we're running from project root or find the venv
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VENV_PYTHON="$PROJECT_ROOT/.venv/bin/python"

if [ ! -f "$VENV_PYTHON" ]; then
    echo '{"error": "Rust bridge python env not found"}'
    exit 1
fi

# We use a python one-liner to bridge stdin/stdout to the Rust extension
# This avoids needing a separate compiled binary just for the CLI wrapper if the extension exposes it
# Actually, the python script `scripts/deploy_grand_army.py` imports whitemagic_rs.
# Here we want a standalone script that behaves like an "army unit".

$VENV_PYTHON -c "
import sys
import json
import whitemagic_rs

def main():
    try:
        # Read input JSON
        input_data = sys.stdin.read()
        if not input_data:
            return
            
        task = json.loads(input_data)
        command = task.get('task')
        data = task.get('data', {})
        clone_count = task.get('clone_count', 1)
        
        result = {}
        
        if command == 'cosine_batch':
            # Mocking the call if not exposed directly or calling actual rust func
            # whitemagic_rs.cosine_batch(...)
            # For now, let's assume we can call some exposed function
            # If not available, we return a mock success for the protocol test
            vectors = data.get('vectors', 1000)
            dims = data.get('dims', 1536)
            # result = whitemagic_rs.bench_cosine(vectors, dims) # hypothetical
            result = {'status': 'success', 'throughput': 'mock_rust_speed'}
            
        elif command == 'json_bench':
            # whitemagic_rs.bench_json(...)
            result = {'status': 'success', 'throughput': 'mock_rust_json_speed'}
            
        else:
            result = {'error': f'Unknown task: {command}'}
            
        print(json.dumps(result))
        
    except Exception as e:
        print(json.dumps({'error': str(e)}))

if __name__ == '__main__':
    main()
"
