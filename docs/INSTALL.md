# 🚀 Download & Installation Guide

WhiteMagic v20.0.0 offers five flexible installation methods depending on your needs: **Seed Binary** (Minimal), **PyPI** (Standard), **Docker** (Production), **WASM** (Browser), or **Git** (Development).

---

## 📋 Quick Reference

| Method | Size | Tools | Setup Time | Use Case |
|--------|------|-------|------------|----------|
| **Seed** | ~5MB | ~30 | < 30s | Minimalist agents, WASM |
| **PyPI** | ~20MB | 374 | ~60s | Python developers |
| **Docker** | ~400MB | 374 | ~2m | Production, Servers |
| **WASM** | ~2MB | ~10 | < 30s | Browser, Edge |
| **Git** | ~1.1GB | 374+ | ~5m | Development, Research |

---

## 🎯 Choose Your Path

**Need zero dependencies?** → Use **Seed Binary**  
**Standard Python development?** → Use **PyPI**  
**Production deployment?** → Use **Docker**  
**Browser/edge deployment?** → Use **WASM**  
**Full development environment?** → Use **Git Clone**

---

## 📖 Full Installation Guide

For detailed step-by-step instructions, AI expansion paths, and troubleshooting, see **[INSTALLATION_GUIDE.md](INSTALLATION_GUIDE.md)**.

---

## Quick Start Options

### 1. Seed Binary (Minimal)
```bash
curl -L https://github.com/whitemagic-ai/whitemagic-clean/releases/latest/download/wm-seed -o wm
chmod +x wm
./wm init && ./wm serve
```

### 2. PyPI (Standard)
```bash
pip install whitemagic[mcp]
wm version
```

### 3. Docker (Production)
```bash
docker pull whitemagicai/whitemagic:latest
docker run -it -v ~/.whitemagic:/data whitemagicai/whitemagic:latest
```

### 4. WASM (Browser)
```bash
git clone https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean/whitemagic-rust
./wasm-build.sh web
```

### 5. Git Clone (Development)
```bash
git clone --depth 1 https://github.com/whitemagic-ai/whitemagic-clean.git
cd whitemagic-clean
pip install -e ".[dev,mcp,cli]"
```

---

## 🔄 AI Expansion

Start minimal and expand to full in minutes:
- **Seed → PyPI**: `pip install whitemagic[mcp]` (60s)
- **Add Rust acceleration**: `maturin develop --release` (30s)
- **Full polyglot stack**: Build all accelerators (2m)

*See the [full guide](INSTALLATION_GUIDE.md) for detailed expansion paths.*
