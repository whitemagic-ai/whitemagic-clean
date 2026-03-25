# Mojo Correct Setup Instructions

**Issue**: The modular repo is source code, not an installable Python package. We need to use the Modular CLI directly.

---

## ✅ Correct Approach: Use Modular CLI

### Step 1: Check if Modular CLI is Already Installed

```bash
which modular
```

If it returns a path (like `/usr/local/bin/modular`), it's already installed from the earlier `curl -s https://get.modular.com | sh -` command.

### Step 2: Authenticate with Modular (if needed)

```bash
modular auth
```

This will open a browser for authentication. Follow the prompts to:
- Create a Modular account (or log in)
- Accept terms of service
- Complete authentication

### Step 3: Install Mojo

```bash
modular install mojo
```

**Expected output**:
```
✔ Mojo installed successfully
```

### Step 4: Add Mojo to PATH

The installer should do this automatically, but verify:

```bash
# Check if mojo is in PATH
which mojo

# If not found, add manually
echo 'export PATH="$HOME/.modular/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

### Step 5: Verify Mojo Installation

```bash
mojo --version
```

**Expected output**:
```
mojo 24.x.x (or similar)
```

### Step 6: Test Mojo Compilation

```bash
# Create test file
cd ~/Desktop/whitemagicdev
echo 'fn main():
    print("Hello from Mojo!")' > test_mojo.mojo

# Run it
mojo test_mojo.mojo
```

**Expected output**:
```
Hello from Mojo!
```

### Step 7: Compile WhiteMagic Mojo Files

```bash
cd ~/Desktop/whitemagicdev/whitemagic-mojo

# Check what exists
ls -la src/

# If main.mojo exists, compile it
mojo build src/main.mojo -o bin/whitemagic_mojo

# Or compile specific files
# mojo build src/coordinate_encoder.mojo -o bin/coordinate_encoder_mojo
```

### Step 8: Verify PolyglotRouter Detection

```bash
cd ~/Desktop/whitemagicdev
source .venv/bin/activate

python3 -c "from whitemagic.optimization.polyglot_router import PolyglotRouter; r = PolyglotRouter(); print(f'✅ POLYGLOT STATUS:'); print(f'   Rust: {r._rust_available}'); print(f'   Zig:  {r._zig_available}'); print(f'   Mojo: {r._mojo_available}')"
```

---

## 🚨 Alternative: Skip Mojo for Now

If Mojo installation is problematic, we can proceed without it:

**Current Status**:
- ✅ Rust: Working (10-100× speedup)
- ✅ Zig: Working (low-level optimization)
- ✅ Koka: Installed (effect-based orchestration)
- ⏳ Mojo: Optional (tensor operations)

**We can start Front Two with Rust + Zig**, which gives us:
- Real subprocess execution
- Compilation and testing
- Benchmarking
- 10-100× speedups on hot paths

Mojo is primarily for tensor/ML operations, which we're not using heavily yet.

---

## 📋 Quick Checklist

Try these commands in order:

```bash
# 1. Check modular CLI
which modular

# 2. If not found, install it
curl -s https://get.modular.com | sh -

# 3. Authenticate
modular auth

# 4. Install Mojo
modular install mojo

# 5. Verify
mojo --version

# 6. Test
cd ~/Desktop/whitemagicdev
echo 'fn main():
    print("Hello from Mojo!")' > test_mojo.mojo
mojo test_mojo.mojo

# 7. Check PolyglotRouter
source .venv/bin/activate
python3 -c "from whitemagic.optimization.polyglot_router import PolyglotRouter; r = PolyglotRouter(); print(f'Rust: {r._rust_available}, Zig: {r._zig_available}, Mojo: {r._mojo_available}')"
```

---

## 🎯 Decision Point

**Option A**: Continue with Mojo setup (follow steps above)  
**Option B**: Skip Mojo and start Front Two with Rust + Zig now

**Recommendation**: Try Option A quickly. If it takes more than 10 minutes, go with Option B and add Mojo later.

We have enough polyglot power to start deploying campaigns! 🚀
