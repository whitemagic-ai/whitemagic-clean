#!/bin/bash
# Koka build script for v17

set -e

echo "Building Koka modules..."
koka --target=js --output=dist/js ffi/python_bridge.kk
koka --target=c --output=dist/c ffi/python_bridge.kk

echo "Build complete!"
