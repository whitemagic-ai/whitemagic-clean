#!/bin/bash
# Run focused benchmark with optimizations applied

echo "Applying Ollama optimizations..."

# Set Ollama environment variables for better performance
export OLLAMA_NUM_PARALLEL=1
export OLLAMA_MAX_LOADED_MODELS=1
export OLLAMA_FLASH_ATTENTION=true

echo "✅ Ollama optimizations applied"
echo ""
echo "Note: CPU is in powersave mode (2.0GHz vs 3.6GHz max)"
echo "For 1.5-2x speedup, run: sudo cpupower frequency-set -g performance"
echo ""
echo "Starting focused benchmark..."
echo ""

# Run the focused benchmark
PYTHONPATH=/home/lucas/Desktop/whitemagicdev python3 scripts/focused_llm_benchmark.py
