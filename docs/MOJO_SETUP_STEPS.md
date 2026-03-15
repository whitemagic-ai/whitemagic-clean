# Mojo Setup - Step-by-Step Instructions

**Status**: Pixi installed ✅, Modular repo cloned ✅  
**Next**: Complete Mojo installation

---

## ✅ Completed Steps

1. **Pixi installed** → `/home/lucas/.pixi/bin/pixi`
2. **Modular repo cloned** → `~/Desktop/whitemagicdev/modular/`

---

## 🔥 Next Steps for Lucas

### Step 1: Add Pixi to PATH

```bash
# Add to your ~/.bashrc or ~/.zshrc
echo 'export PATH="$HOME/.pixi/bin:$PATH"' >> ~/.bashrc

# Reload shell
source ~/.bashrc

# Verify pixi is in PATH
pixi --version
```

### Step 2: Navigate to Modular Directory

```bash
cd ~/Desktop/whitemagicdev/modular
```

### Step 3: Initialize Pixi Environment

```bash
pi
```

**What this does**:
- Reads `pixi.toml` or `pyproject.toml` from the modular repo
- Creates `.pixi/` environment directory
- Installs Mojo and all dependencies
- May take 5-10 minutes depending on download speed

**Expected output**:
```
✔ Project in /home/lucas/Desktop/whitemagicdev/modular is ready to use!
```

### Step 4: Activate Pixi Shell

```bash
pixi shell
```

**What this does**:
- Activates the pixi environment
- Makes `mojo` command available
- You'll see your prompt change to indicate pixi environment is active

### Step 5: Verify Mojo Installation

```bash
mojo --version
```

**Expected output**:
```
mojo 24.x.x (or similar version number)
```

### Step 6: Test Mojo Compilation

```bash
# Create a simple test file
echo 'fn main():
    print("Hello from Mojo!")' > test.mojo

# Compile and run
mojo test.mojo
```

**Expected output**:
```
Hello from Mojo!
```

### Step 7: Compile WhiteMagic Mojo Files

```bash
cd ~/Desktop/whitemagicdev/whitemagic-mojo

# Check what Mojo files exist
ls -la src/

# Compile main file (if it exists)
mojo build src/main.mojo -o bin/whitemagic_mojo

# Or compile specific files
mojo build src/coordinate_encoder.mojo -o bin/coordinate_encoder_mojo
```

### Step 8: Verify PolyglotRouter Detection

```bash
cd ~/Desktop/whitemagicdev

# Activate WhiteMagic venv
source .venv/bin/activate

# Test detection
python3 -c "from whitemagic.optimization.polyglot_router import PolyglotRouter; r = PolyglotRouter(); print(f'Mojo: {r._mojo_available}')"
```

**Expected output**:
```
🔥 Mojo acceleration available - High-performance compute enabled
Mojo: True
```

---

## 🚨 Potential Issues & Solutions

### Issue 1: "pixi: command not found" after adding to PATH

**Solution**:
```bash
# Manually source bashrc
source ~/.bashrc

# Or restart terminal
```

### Issue 2: "No pixi.toml or pyproject.toml found"

**Solution**:
The modular repo should have configuration files. Check:
```bash
cd ~/Desktop/whitemagicdev/modular
ls -la | grep -E "pixi|pyproject"
```

If missing, you may need to use modular CLI directly:
```bash
# Install modular CLI if needed
curl -s https://get.modular.com | sh -

# Then install mojo
modular install mojo
```

### Issue 3: Authentication required

**Solution**:
Follow the prompts during `pixi install`. You may need to:
- Create a Modular account
- Authenticate via browser
- Accept terms of service

### Issue 4: Mojo binaries not in expected location

**Solution**:
After compilation, check where binaries are:
```bash
find ~/Desktop/whitemagicdev/whitemagic-mojo -name "*.mojo" -o -name "*_mojo"
```

Update PolyglotRouter if needed to point to correct location.

---

## 📋 Checklist

Run these commands in order and let me know the results:

- [ ] `echo 'export PATH="$HOME/.pixi/bin:$PATH"' >> ~/.bashrc && source ~/.bashrc`
- [ ] `pixi --version`
- [ ] `cd ~/Desktop/whitemagicdev/modular`
- [ ] `pixi install`
- [ ] `pixi shell`
- [ ] `mojo --version`
- [ ] `cd ~/Desktop/whitemagicdev/whitemagic-mojo && ls -la src/`
- [ ] `mojo build src/main.mojo -o bin/whitemagic_mojo` (or similar)
- [ ] `cd ~/Desktop/whitemagicdev && source .venv/bin/activate`
- [ ] `python3 -c "from whitemagic.optimization.polyglot_router import PolyglotRouter; r = PolyglotRouter(); print(f'Mojo: {r._mojo_available}')"`

---

## ✅ When Complete

Once Mojo is working, you should see:

```bash
python3 -c "from whitemagic.optimization.polyglot_router import PolyglotRouter; r = PolyglotRouter(); print(f'✅ POLYGLOT STATUS: Rust={r._rust_available}, Zig={r._zig_available}, Mojo={r._mojo_available}')"
```

**Expected output**:
```
🦀 Rust bridge available - 10-100x speedup enabled
⚡ Zig determinism available - Low-level systems speedup enabled
🔥 Mojo acceleration available - High-performance compute enabled
✅ POLYGLOT STATUS: Rust=True, Zig=True, Mojo=True
```

**Then we can begin Front Two!** 🚀
