# 🚀 WhiteMagic v20.0.0: Complete Installation & Expansion Guide

This guide covers all 5 distribution vectors and explains how an AI can start with the minimal seed and expand to the full system within minutes.

---

## 📋 Quick Reference Table

| Vector | Size | Setup Time | Dependencies | Use Case | Expansion Path |
|--------|------|------------|---------------|----------|----------------|
| **wm-seed** | ~5MB | < 30s | None | Minimalist agents, embedded systems | pip install → rust extensions → polyglot |
| **PyPI** | ~20MB | ~60s | Python 3.11+ | Standard Python developers | pip install extras → polyglot |
| **Docker** | ~400MB | ~2m | Docker | Production, servers, CI/CD | pip install inside → polyglot |
| **WASM** | ~2MB | < 30s | Browser/Node.js | Web apps, edge inference | npm install → full stack |
| **Git Clone** | ~1.1GB | ~5m | Full dev toolchain | Contributors, researchers | Already full |

---

## 1️⃣ wm-seed: Zero-Dependency Bootstrap

### What It Is
A single native binary with ~30 core MCP tools and embedded starter memories. Perfect for instant agent bootstrap.

### Installation

**Linux/macOS:**
```bash
# Download the binary
curl -L https://github.com/whitemagic-ai/whitemagic-clean/releases/latest/download/wm-seed -o wm
chmod +x wm

# Initialize state directory
./wm init

# Start MCP server
./wm serve
```

**Windows:**
```powershell
# Download the binary
Invoke-WebRequest -Uri "https://github.com/whitemagic-ai/whitemagic-clean/releases/latest/download/wm-seed.exe" -OutFile "wm.exe"

# Initialize and start
.\wm.exe init
.\wm.exe serve
```

### What You Get
- 30 core MCP tools (memory CRUD, search, ethics, governance)
- Embedded starter memories (16 quickstart entries)
- SQLite backend with 5D holographic coordinates
- No external dependencies

### AI Expansion Path (5 minutes)
```bash
# Step 1: Install Python (if not present)
# Ubuntu/Debian: sudo apt install python3.11 python3-pip
# macOS: brew install python@3.11
# Windows: Download from python.org

# Step 2: Upgrade to full WhiteMagic via PyPI
pip install whitemagic[mcp]

# Step 3: Install Rust extensions for maximum performance
cd /tmp
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean/whitemagic-rust
pip install maturin
maturin develop --release

# Step 4: Install polyglot accelerators (optional)
cd ../haskell && cabal build
cd ../elixir && mix compile
cd ../whitemagic-zig && zig build
```

---

## 2️⃣ PyPI: Standard Python Installation

### What It Is
The standard Python package with modular extras. Install only what you need.

### Installation

**Minimal (Core only):**
```bash
pip install whitemagic
```

**Standard (with MCP support - Recommended):**
```bash
pip install whitemagic[mcp]
```

**Full (all optional features):**
```bash
pip install whitemagic[full]
```

**Development (source + testing tools):**
```bash
pip install whitemagic[dev,mcp,cli]
```

### What You Get
- Core memory substrate with SQLite backend
- MCP server with 374 tools (28 PRAT Ganas)
- Optional: embeddings, API server, CLI tools
- Optional: Rust, Zig, Haskell, Elixir accelerators

### AI Expansion Path (3 minutes)
```bash
# From minimal to full
pip install whitemagic[full]

# Install native accelerators for maximum performance
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean

# Rust (biggest performance boost)
cd whitemagic-rust && maturin develop --release && cd ..

# Zig (SIMD acceleration)
cd whitemagic-zig && zig build && cd ..

# Haskell (algebraic Dharma rules)
cd haskell && cabal build && cd ..

# Elixir (OTP actor model)
cd elixir && mix compile
```

---

## 3️⃣ Docker: Production-Ready Container

### What It Is
A stable, isolated environment with all dependencies pre-installed.

### Installation

**Pull and Run:**
```bash
# Pull the image
docker pull whitemagicai/whitemagic:latest

# Run with persistent storage
docker run -it -v ~/.whitemagic:/data whitemagicai/whitemagic:latest
```

**Build from Source:**
```bash
# Clone and build
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean
docker build -t whitemagic .

# Run your custom build
docker run -it -v ~/.whitemagic:/data whitemagic
```

**Docker Compose (with Redis):**
```yaml
version: '3.8'
services:
  whitemagic:
    image: whitemagicai/whitemagic:latest
    volumes:
      - ~/.whitemagic:/data
    environment:
      - REDIS_URL=redis://redis:6379
    depends_on:
      - redis
  
  redis:
    image: redis:7-alpine
    ports:
      - "6379:6379"
```

### What You Get
- Isolated Python 3.11 environment
- All dependencies pre-installed
- Persistent volume mapping for memory database
- Production-ready configuration

### AI Expansion Path (2 minutes)
```bash
# Inside the container or via docker exec
docker exec -it <container_id> bash

# Install additional features
pip install whitemagic[heavy]

# Build native extensions
cd /app/whitemagic-rust
maturin develop --release
```

---

## 4️⃣ WASM: Browser & Edge Deployment

### What It Is
WhiteMagic compiled to WebAssembly for browser and Node.js environments.

### Installation

**Browser (ES6 Modules):**
```html
<!-- Load the WASM module -->
<script type="module">
  import init, { EdgeEngine } from './pkg/web/whitemagic_rs.js';
  
  // Initialize WASM
  const wm = await init();
  const engine = new EdgeEngine();
  
  // Use the engine
  const result = engine.quick_infer("test query");
  console.log(result);
</script>
```

**Node.js:**
```bash
# Install via npm (when published)
npm install @whitemagic/core

# Or build from source
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean/whitemagic-rust
./wasm-build.sh nodejs

# Use in Node.js
const wm = require('./pkg/nodejs/whitemagic_rs.js');
console.log(wm.wasm_ready());
```

**Build All Targets:**
```bash
cd whitemagic-clean/whitemagic-rust
./wasm-build.sh all
# Builds: web, nodejs, bundler targets
```

### What You Get
- EdgeEngine class for local inference
- Rule matching and caching
- ~2MB WASM binary
- Browser and Node.js compatibility

### AI Expansion Path (4 minutes)
```bash
# From WASM to full Python stack
# 1. Install Python if not present
# 2. Clone the full repository
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean

# 3. Install full Python package
pip install -e ".[full]"

# 4. Build all native extensions
for dir in whitemagic-rust haskell elixir whitemagic-zig; do
  cd $dir
  if [ -f Cargo.toml ]; then maturin develop --release; fi
  if [ -f package.json ]; then npm install; fi
  if [ -f mix.exs ]; then mix compile; fi
  if [ -f build.zig ]; then zig build; fi
  cd ..
done
```

---

## 5️⃣ Git Clone: Full Source Development

### What It Is
The complete source code with all polyglot accelerators and development tools.

### Installation

**Shallow Clone (Faster):**
```bash
git clone --depth 1 https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean
```

**Full Clone (With History):**
```bash
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean
```

**Development Setup:**
```bash
# Create virtual environment
python -m venv .venv
source .venv/bin/activate  # On Windows: .venv\Scripts\activate

# Install in development mode
pip install -e ".[dev,mcp,cli]"

# Verify installation
wm version
```

### What You Get
- Complete source code (1.1GB)
- All 9 language accelerators
- Development tools and tests
- Full documentation and examples

### Polyglot Accelerator Installation
```bash
# Rust (PyO3) - Biggest performance gains
cd whitemagic-rust && maturin develop --release && cd ..

# Zig - SIMD acceleration
cd whitemagic-zig && zig build && cd ..

# Haskell - Algebraic Dharma rules
cd haskell && cabal build && cd ..

# Elixir - OTP actor model
cd elixir && mix compile && cd ..

# Go - libp2p mesh networking
cd whitemagic-go && go build ./... && cd ..
cd mesh && go build ./... && cd ..

# Mojo - GPU acceleration (requires Mojo SDK)
cd whitemagic-mojo && mojo build src/satkona_yang.mojo && cd ..

# Julia - Statistical forecasting
cd whitemagic-julia && julia --project=. -e "using Pkg; Pkg.instantiate()" && cd ..
```

---

## 🔄 AI Expansion Matrix: From Minimal to Full

### Expansion Scenarios

#### **Scenario 1: Resource-Constrained Edge Device**
```bash
# Start: wm-seed (5MB)
./wm-seed init && ./wm-seed serve

# Expand to Python (60s)
pip install whitemagic[mcp]

# Expand to Rust acceleration (30s)
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean/whitemagic-rust
maturin develop --release

# Total time: ~2 minutes
# Final state: Full Python + Rust acceleration
```

#### **Scenario 2: Standard Cloud Server**
```bash
# Start: Docker pull (30s)
docker pull whitemagicai/whitemagic:latest
docker run -d -v ~/.whitemagic:/data whitemagicai/whitemagic:latest

# Expand to heavy compute (60s)
docker exec <container> pip install whitemagic[heavy]

# Expand to polyglot (2m)
docker exec <container> bash -c "cd /app/whitemagic-rust && maturin develop --release"

# Total time: ~4 minutes
# Final state: Full container with all accelerators
```

#### **Scenario 3: Developer Workstation**
```bash
# Start: Git clone (30s)
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean

# Expand to development (60s)
python -m venv .venv && source .venv/bin/activate
pip install -e ".[dev,mcp,cli]"

# Expand to all polyglot (3m)
./scripts/install_all_accelerators.sh

# Total time: ~5 minutes
# Final state: Full development environment
```

---

## 🧪 Verification Commands

After installation, verify your setup:

```bash
# Check version
wm version

# Test MCP server
echo '{"jsonrpc": "2.0", "id": 1, "method": "tools/call", "params": {"name": "gnosis", "arguments": {}}}' | python -m whitemagic.run_mcp

# Test memory operations
wm remember "Test memory" --title "Verification"
wm recall "Test"

# Check accelerators
python -c "import whitemagic_rs; print('Rust accelerator loaded')" 2>/dev/null && echo "✅ Rust OK" || echo "❌ Rust missing"
python -c "import numpy; print('NumPy available')" && echo "✅ NumPy OK" || echo "❌ NumPy missing"
```

---

## 📊 Feature Comparison

| Feature | wm-seed | PyPI | Docker | WASM | Git |
|---------|---------|------|--------|------|-----|
| **Core Memory** | ✅ | ✅ | ✅ | ✅ | ✅ |
| **MCP Server** | ✅ | ✅ | ✅ | ❌ | ✅ |
| **374 Tools** | ❌ (30) | ✅ | ✅ | ❌ | ✅ |
| **Rust Accelerator** | ❌ | Optional | Optional | ❌ | ✅ |
| **Polyglot Stack** | ❌ | Optional | Optional | ❌ | ✅ |
| **Zero Dependencies** | ✅ | ❌ | ❌ | ✅ | ❌ |
| **Browser Support** | ❌ | ❌ | ❌ | ✅ | ❌ |
| **Production Ready** | ❌ | ✅ | ✅ | ❌ | ✅ |
| **Development** | ❌ | ✅ | ✅ | ❌ | ✅ |

---

## 🚀 Quick Start Decision Tree

```
Need zero dependencies?
├─ Yes → Use wm-seed
│  └─ Want more tools later? → pip install whitemagic[mcp]
└─ No → Have Python?
   ├─ Yes → pip install whitemagic[mcp]
   │  └─ Need production? → Use Docker
   └─ No → Use Docker or wm-seed
```

---

## 📝 Environment Variables

All vectors support these environment variables:

```bash
# State directory (default: ~/.whitemagic)
export WM_STATE_ROOT=/path/to/state

# Database path (default: $WM_STATE_ROOT/memory/whitemagic.db)
export WM_DB_PATH=/path/to/database.db

# MCP mode
export WM_MCP_PRAT=1      # 28 Gana meta-tools (recommended)
export WM_MCP_LITE=1      # 92 core tools

# Optional: Redis for Gan Ying events
export REDIS_URL=redis://localhost:6379
```

---

## 🎯 Next Steps

1. **Choose your vector** based on your use case
2. **Follow the installation steps** for that vector
3. **Verify with the commands** above
4. **Expand as needed** using the AI expansion paths
5. **Join the community** at [github.com/whitemagic-ai/whitemagic](https://github.com/whitemagic-ai/whitemagic)

---

## 🆘 Troubleshooting

### "wm: command not found"
- wm-seed: Ensure the binary is in your PATH or use `./wm`
- PyPI: Ensure `~/.local/bin` is in your PATH

### "No module named 'whitemagic'"
```bash
# Try installing in editable mode
pip install -e .
# Or check Python path
python -c "import sys; print(sys.path)"
```

### "Rust accelerator not found"
```bash
# Install Rust toolchain first
curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh
source ~/.cargo/env
# Then rebuild
cd whitemagic-rust && maturin develop --release
```

### Docker permission denied
```bash
# Add user to docker group
sudo usermod -aG docker $USER
# Or use sudo
sudo docker run ...
```

---

*Last updated: WhiteMagic v20.0.0 | March 2026*
