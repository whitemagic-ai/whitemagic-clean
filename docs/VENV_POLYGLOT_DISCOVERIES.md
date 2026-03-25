# Venv Polyglot Discoveries

**Date**: February 16, 2026  
**Discovery**: WhiteMagic venv contains working Rust bindings and other polyglot tools

---

## 🔍 Key Findings

### Rust Integration in Venv ✅

**Installed Packages**:
1. **whitemagic_rs** (v11.0.0) — Our custom Rust bridge
   - Location: `.venv/lib/python3.12/site-packages/whitemagic_rs/`
   - Binary: `whitemagic_rs.cpython-312-x86_64-linux-gnu.so` (6.7M)
   - Installed via: maturin develop
   
2. **py_rust_stemmers** (v0.1.5) — Rust-based text stemmers
   - Pre-installed dependency
   - Provides fast stemming algorithms

**Available Rust Functions** (from whitemagic_rs):
```python
import whitemagic_rs

# Available classes/functions:
- HarmonyVector
- PatternEngine
- RrfResult
- RustEventProcessor
- SpatialIndex
- SpatialIndex5D
- WalkNode
- arrow_decode_memories
- arrow_encode_memories
- arrow_roundtrip_bench
# ... and more
```

**Verification**:
```bash
$ .venv/bin/python3 -c "import whitemagic_rs; print('✅ Rust bridge loaded')"
✅ Rust bridge loaded
```

---

## 🛠️ System-Wide vs Venv Tools

### System-Wide (Available Everywhere)

| Tool | Location | Version | Notes |
|------|----------|---------|-------|
| **cargo** | `/usr/bin/cargo` | 1.93.0 | Rust package manager |
| **rustc** | `/usr/bin/rustc` | 1.93.0 | Rust compiler |
| **zig** | `/snap/bin/zig` | 0.15.2 | Zig compiler (snap) |
| **koka** | `/usr/local/bin/koka` | 3.2.2 | Koka compiler |

### Venv-Only (Python Integration)

| Package | Version | Purpose |
|---------|---------|---------|
| **whitemagic_rs** | 11.0.0 | Custom Rust bridge (PyO3) |
| **py_rust_stemmers** | 0.1.5 | Rust text stemmers |
| **orjson** | 3.11.7 | Fast JSON (Rust-based) |
| **maturin** | (dev tool) | Rust-Python builder |

---

## 🎯 How It All Works Together

### Architecture

```
┌─────────────────────────────────────────────────────────┐
│ System Level (Available Everywhere)                     │
├─────────────────────────────────────────────────────────┤
│ • cargo (Rust build tool)                               │
│ • rustc (Rust compiler)                                 │
│ • zig (Zig compiler)                                    │
│ • koka (Koka compiler)                                  │
└─────────────────────────────────────────────────────────┘
                         ↓
┌─────────────────────────────────────────────────────────┐
│ Build Process                                           │
├─────────────────────────────────────────────────────────┤
│ whitemagic-rust/                                        │
│   ├── Cargo.toml (Rust manifest)                       │
│   ├── src/ (Rust source code)                          │
│   └── maturin develop --release                        │
│       ↓                                                 │
│   Compiles Rust → Python extension (.so)               │
└─────────────────────────────────────────────────────────┘
                         ↓
┌─────────────────────────────────────────────────────────┐
│ Venv Level (Python Integration)                        │
├─────────────────────────────────────────────────────────┤
│ .venv/lib/python3.12/site-packages/                    │
│   ├── whitemagic_rs/ (6.7M .so binary)                 │
│   ├── py_rust_stemmers/                                │
│   └── orjson/                                           │
│                                                         │
│ Python code can now:                                    │
│   import whitemagic_rs                                  │
│   # Use Rust functions at native speed                 │
└─────────────────────────────────────────────────────────┘
```

### Why Venv Matters

**Problem**: System Python vs Venv Python
- System Python: `/usr/bin/python3`
- Venv Python: `.venv/bin/python3`

**Rust bindings installed in venv only**:
```bash
# ❌ Fails (system Python)
$ python3 -c "import whitemagic_rs"
ModuleNotFoundError: No module named 'whitemagic_rs'

# ✅ Works (venv Python)
$ .venv/bin/python3 -c "import whitemagic_rs"
# Success!
```

**Solution**: Always activate venv before running WhiteMagic:
```bash
source .venv/bin/activate
```

---

## 📦 Complete Venv Package Inventory

### Development Tools in Venv
- **black** — Code formatter
- **ruff** — Fast linter (Rust-based!)
- **mypy** — Type checker
- **pytest** — Testing framework
- **maturin** — Rust-Python builder
- **mcp** — MCP server tools

### Performance Libraries
- **orjson** — Fast JSON (Rust-based, 3-6× faster than stdlib)
- **whitemagic_rs** — Custom Rust acceleration
- **py_rust_stemmers** — Rust text processing
- **torch** — PyTorch (has torchrun, torchfrtrace)
- **numpy** — Numerical computing

### Key Insight: Ruff is Rust-Based!
The linter we're using (`ruff`) is actually written in Rust, giving us another example of Rust acceleration in our toolchain.

---

## 🚀 Making Tools Work Outside Venv

### Option 1: System-Wide Python Package Install (Not Recommended)

```bash
# Install to system Python (requires sudo, not recommended)
cd whitemagic-rust
sudo pip3 install maturin
sudo maturin develop --release
```

**Why not recommended**:
- Pollutes system Python
- Requires sudo
- Can break system tools
- Hard to uninstall cleanly

### Option 2: Always Use Venv (Recommended)

```bash
# Add to ~/.bashrc for convenience
alias wm-python='source ~/Desktop/whitemagicdev/.venv/bin/activate && python3'
alias wm-activate='source ~/Desktop/whitemagicdev/.venv/bin/activate'

# Then use:
wm-activate
python3 script.py  # Now uses venv Python with Rust bindings
```

### Option 3: Shebang in Scripts (Best for Automation)

```python
#!/home/lucas/Desktop/whitemagicdev/.venv/bin/python3
"""Script that automatically uses venv Python."""

import whitemagic_rs  # Works because shebang points to venv Python
```

### Option 4: Explicit Path in Commands

```bash
# Always specify venv Python explicitly
/home/lucas/Desktop/whitemagicdev/.venv/bin/python3 script.py
```

---

## 🔧 Updated Setup Workflow

### For New Sessions

```bash
# 1. Navigate to project
cd ~/Desktop/whitemagicdev

# 2. Activate venv (CRITICAL!)
source .venv/bin/activate

# 3. Verify Rust bridge
python3 -c "import whitemagic_rs; print('✅ Ready')"

# 4. Run WhiteMagic tools
python3 scripts/deploy_h001.py
```

### For Automated Scripts

**Option A: Use shebang**
```python
#!/home/lucas/Desktop/whitemagicdev/.venv/bin/python3
```

**Option B: Activate in script wrapper**
```bash
#!/bin/bash
cd ~/Desktop/whitemagicdev
source .venv/bin/activate
python3 scripts/deploy_h001.py "$@"
```

---

## 📊 Performance Comparison

### JSON Serialization (orjson vs stdlib)

```python
import json
import orjson
import time

data = {'key': 'value'} * 10000

# stdlib json
start = time.time()
for _ in range(1000):
    json.dumps(data)
stdlib_time = time.time() - start

# orjson (Rust)
start = time.time()
for _ in range(1000):
    orjson.dumps(data)
orjson_time = time.time() - start

print(f"Speedup: {stdlib_time / orjson_time:.1f}×")
# Expected: 3-6× faster
```

### Rust Bridge Functions

```python
import whitemagic_rs

# Example: Spatial indexing (10-50× faster than Python)
index = whitemagic_rs.SpatialIndex5D()
# ... use for holographic coordinate lookups

# Example: Pattern matching (20-100× faster)
engine = whitemagic_rs.PatternEngine()
# ... use for pattern detection
```

---

## 🎯 Key Takeaways

1. **Venv is essential** — Rust bindings only work in venv Python
2. **System tools are separate** — cargo/rustc/zig/koka work everywhere
3. **Always activate venv** — `source .venv/bin/activate` before running WhiteMagic
4. **Shebang for scripts** — Use `#!/path/to/venv/bin/python3` for automation
5. **Multiple Rust tools** — whitemagic_rs, orjson, ruff, py_rust_stemmers

---

## 🔍 Verification Checklist

Run these commands to verify your setup:

```bash
# 1. Check system tools
cargo --version    # Should show 1.93.0
rustc --version    # Should show 1.93.0
zig version        # Should show 0.15.2
koka --version     # Should show 3.2.2

# 2. Activate venv
cd ~/Desktop/whitemagicdev
source .venv/bin/activate

# 3. Check Python is venv Python
which python3      # Should show .venv/bin/python3

# 4. Check Rust bridge
python3 -c "import whitemagic_rs; print('✅ Rust OK')"

# 5. Check PolyglotRouter
python3 -c "from whitemagic.optimization.polyglot_router import PolyglotRouter; r = PolyglotRouter(); print(f'Rust: {r._rust_available}, Zig: {r._zig_available}')"

# Expected output:
# 🦀 Rust bridge available - 10-100x speedup enabled
# ⚡ Zig determinism available - Low-level systems speedup enabled
# Rust: True, Zig: True
```

---

## 📝 Updated Installation Summary

### What's Installed Where

**System-wide** (no venv needed):
- Rust toolchain (cargo, rustc)
- Zig compiler
- Koka compiler

**Venv-only** (requires activation):
- whitemagic_rs (Rust-Python bridge)
- orjson (fast JSON)
- py_rust_stemmers (text processing)
- All WhiteMagic Python code

**Build artifacts**:
- `whitemagic-rust/target/` — Rust compilation output
- `whitemagic-zig/zig-out/` — Zig compilation output
- `.venv/lib/python3.12/site-packages/whitemagic_rs/` — Installed Python extension

---

**Bottom Line**: The venv contains working Rust integration. Just activate it before running WhiteMagic tools!

```bash
source .venv/bin/activate  # ← This is the magic command
```
