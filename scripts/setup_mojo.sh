#!/bin/bash
# Mojo Setup Commands for WhiteMagic
# Run these in order - the last step requires sudo

set -e

echo "=== Step 1: Install Modular CLI (requires sudo) ==="
echo "Run: curl -s https://get.modular.com | sh -s -- -y"
echo ""
echo "=== Step 2: Install Magic (Mojo package manager) ==="
echo "Run: modular install magic"
echo ""
echo "=== Step 3: Initialize pixi environment ==="
echo "Run: cd /home/lucas/Desktop/whitemagicdev && magic init whitemagic-mojo"
echo ""
echo "=== Step 4: Install Mojo ==="
echo "Run: magic add max/mojo"
echo ""
echo "=== Step 5: Verify Mojo works ==="
echo "Run: mojo --version"
echo ""
echo "=== All commands ready! Start with Step 1 (requires sudo). ==="
