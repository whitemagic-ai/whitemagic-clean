#!/usr/bin/env python3
"""Minimal test for Rust ONNX embedder crash"""
import sys

sys.path.insert(0, '.')

import pyarrow as pa

from whitemagic_rs import arrow_onnx_embed, onnx_embedder_info

print("ONNX Info:", onnx_embedder_info())

# Test with tiny batch
texts = ["hello world", "test sentence"]
schema = pa.schema([("text", pa.string())])

with pa.BufferOutputStream() as stream:
    with pa.ipc.new_file(stream, schema) as writer:
        batch = pa.record_batch([pa.array(texts, type=pa.string())], names=["text"])
        writer.write_batch(batch)
    arrow_bytes = stream.getvalue().to_pybytes()

print(f"Input bytes: {len(arrow_bytes)}")
print("Calling arrow_onnx_embed...")

try:
    result = arrow_onnx_embed(arrow_bytes, "models/bge-small-en-v1.5.onnx", False)
    print(f"Success! Output bytes: {len(result)}")

    # Convert list to bytes if needed
    if isinstance(result, list):
        result = bytes(result)

    # Decode
    import io
    with pa.ipc.open_file(io.BytesIO(result)) as reader:
        result_batch = reader.read_all()
        print(f"Rows: {result_batch.num_rows}")
        print(f"Schema: {result_batch.schema}")
        print(f"Sample embedding length: {len(result_batch.column(0)[0])}")
except Exception as e:
    print(f"ERROR: {e}")
    import traceback
    traceback.print_exc()
