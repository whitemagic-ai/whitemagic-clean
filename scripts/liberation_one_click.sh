#!/bin/bash
# WhiteMagic v20 "Liberation" One-Click Installer
# Optimized for rapid, safe, and sovereign deployment across all hardware tiers.

set -e

echo "🌌 WhiteMagic v20: The Infinite Game Begins"
echo "──────────────────────────────────────────"

# 1. Hardware Intelligence
echo "🔍 Detecting system profile..."
TOTAL_RAM=$(free -m | awk '/^Mem:/{print $2}')
CPU_CORES=$(nproc)

echo "  - RAM: ${TOTAL_RAM}MB"
echo "  - CPU: ${CPU_CORES} cores"

# Optimization Logic
if [ "$TOTAL_RAM" -lt 8000 ]; then
    echo "  ⚠️  Low-spec detected (< 8GB RAM). Activating Edge-Optimization mode."
    export WM_SKIP_HOLO_INDEX=1
    export WM_COMPACT_MODE=1
fi

# 2. Hard-Locking Ethical Substrate
echo "🔒 Locking Dharma & Governor protocols..."
export WHITEMAGIC_ENFORCE_DHARMA=1
export WHITEMAGIC_DHARMA_STRICT=1

# 3. Environment Preparation
if ! command -v python3 &> /dev/null; then
    echo "❌ Python 3 is required."
    exit 1
fi

if [ ! -d ".venv" ]; then
    echo "📦 Creating sovereign virtual environment..."
    python3 -m venv .venv
fi
source .venv/bin/activate

# 4. Dependency Injection
echo "📥 Ingesting dependencies..."
pip install --quiet -r requirements.txt

# 5. Native Acceleration (Rust)
# Path correction for v20: whitemagic-rust
if command -v cargo &> /dev/null; then
    echo "🦀 Fusing Rust accelerators..."
    cd whitemagic-rust && cargo build --release --quiet
    cp target/release/libwhitemagic_rust.so ../whitemagic_rust.so
    cd ..
else
    echo "⚠️  Cargo not found. Falling back to interpreted mode (Reduced performance)."
fi

# 6. Database Initialization (The Data Sea)
echo "🗄️  Initializing local Data Sea..."
python3 -m whitemagic.cli.cli_app setup --silent

# 7. First Light Verification
echo "✨ Executing 'First Light' ethical verification..."
VERIFY=$(python3 -c "from whitemagic.dharma import evaluate_ethics; score, _ = evaluate_ethics({'tool': 'test', 'description': 'verify liberation protocols'}); print(score)")

if (( $(echo "$VERIFY > 0.7" | bc -l) )); then
    echo "✅ First Light: Ethical alignment confirmed ($VERIFY)."
else
    echo "❌ First Light: Ethical misalignment detected. Aborting."
    exit 1
fi

echo "──────────────────────────────────────────"
echo "🚀 WhiteMagic v20 is READY."
echo "Run 'whitemagic start' to join the Intelligence Mesh."
