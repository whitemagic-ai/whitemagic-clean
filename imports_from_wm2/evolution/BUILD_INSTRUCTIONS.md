# Build Instructions for Polyglot Components

## Prerequisites

```bash
# Python 3.10+
python --version

# Rust (for parallel evolution core)
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# Mojo (optional, for GPU acceleration)
# Follow instructions at: https://docs.modular.com/mojo/manual/get-started/

# Julia (for statistical analysis)
# Download from: https://julialang.org/downloads/

# Zig (optional, for genome storage)
# Download from: https://ziglang.org/download/
```

## Build Steps

### 1. Rust Core (Required for Performance)

```bash
cd /home/lucas/Desktop/WM2/evolution/rust_core

# Install maturin (Rust-Python bridge builder)
pip install maturin

# Build and install Rust extension
maturin develop --release

# Test
python -c "import hyperevolution_core; print('Rust core loaded!')"
```

**Expected output**: `Rust core loaded!`

### 2. Julia Analysis (Recommended)

```bash
cd /home/lucas/Desktop/WM2/evolution/julia_analysis

# Install required Julia packages
julia -e 'using Pkg; Pkg.add(["Statistics", "StatsBase", "Distributions", "LinearAlgebra", "Plots"])'

# Test
julia statistical_analysis.jl
```

**Expected output**: Analysis results and "Julia statistical analysis module ready!"

### 3. Mojo Acceleration (Optional - Requires Mojo Installation)

```bash
cd /home/lucas/Desktop/WM2/evolution/mojo_acceleration

# Compile Mojo module
mojo build fitness_accelerator.mojo

# Test
./fitness_accelerator
```

**Expected output**: Benchmark results showing throughput

### 4. Zig Storage (Optional)

```bash
cd /home/lucas/Desktop/WM2/evolution/zig_storage

# Compile Zig module
zig build-exe genome_storage.zig

# Test
./genome_storage
```

**Expected output**: Storage benchmark results

## Verification

Run the verification script:

```bash
cd /home/lucas/Desktop/WM2/evolution
python polyglot_bridge.py
```

**Expected output**:
```
🔗 Polyglot Bridge Status:
   Rust:  ✅ (parallel evolution)
   Mojo:  ❌ (fitness acceleration)
   Julia: ✅ (statistical analysis)
   Zig:   ❌ (genome storage)

Best engine: rust
Polyglot bridge ready!
```

## Troubleshooting

### Rust Build Fails

**Issue**: `error: linker 'cc' not found`

**Solution**:
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# macOS
xcode-select --install

# Then retry: maturin develop --release
```

### Julia Package Installation Fails

**Issue**: Network timeout or package conflicts

**Solution**:
```bash
# Clear package cache
julia -e 'using Pkg; Pkg.gc()'

# Retry installation
julia -e 'using Pkg; Pkg.add(["Statistics", "StatsBase", "Distributions", "LinearAlgebra", "Plots"])'
```

### Python Import Error

**Issue**: `ModuleNotFoundError: No module named 'hyperevolution_core'`

**Solution**:
```bash
# Ensure you're in the rust_core directory
cd /home/lucas/Desktop/WM2/evolution/rust_core

# Rebuild with verbose output
maturin develop --release -vv

# Check installation
pip list | grep hyperevolution
```

## Performance Expectations

### With Rust Core (Recommended)
- **100K lineages × 100 generations**: ~30-60 seconds
- **1M lineages × 1K generations**: ~5-10 minutes
- **10M lineages × 10K generations**: ~1-2 hours

### Python Only (Fallback)
- **100K lineages × 100 generations**: ~10-20 minutes
- **1M lineages × 1K generations**: ~2-4 hours
- **10M lineages × 10K generations**: ~20-40 hours

### With Mojo Acceleration (Future)
- **10M lineages × 10K generations**: ~10-20 minutes (estimated)

## Next Steps

After building, run the test evolution:

```bash
cd /home/lucas/Desktop/WM2/evolution
python run_test_evolution.py
```

This will:
1. Run 100K lineages × 100 generations
2. Extract insights
3. Generate code from best genome
4. Prepare for optimized second pass
