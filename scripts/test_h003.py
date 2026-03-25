#!/usr/bin/env python3
"""Test H003 Rust ONNX Embedder"""
import sys
sys.path.insert(0, '/home/lucas/Desktop/whitemagicdev')

import subprocess
from pathlib import Path

try:
    import pyarrow as pa
    HAS_PYARROW = True
except ImportError:
    HAS_PYARROW = False
    print("ERROR: pyarrow not available")
    sys.exit(1)

# Path to binary
BINARY = Path('/home/lucas/Desktop/whitemagicdev/whitemagic-rust/target/release/h003-onnx-embedder')

# Create test input with proper Arrow IPC
test_texts = ["This is a test sentence for embedding."]

# Create Arrow record batch
batch = pa.record_batch([pa.array(test_texts)], names=["text"])

# Serialize to IPC
sink = pa.BufferOutputStream()
with pa.ipc.new_stream(sink, batch.schema) as writer:
    writer.write_batch(batch)

ipc_bytes = sink.getvalue().to_pybytes()

print(f"Input: {len(ipc_bytes)} bytes Arrow IPC")
print(f"Texts: {test_texts}")

# Run binary
result = subprocess.run(
    [str(BINARY)],
    input=ipc_bytes,
    capture_output=True,
    timeout=30,
)

print(f"\nReturn code: {result.returncode}")
print(f"Stdout: {result.stdout[:200]}")
print(f"Stderr: {result.stderr.decode('utf-8', errors='replace')[:500]}")
