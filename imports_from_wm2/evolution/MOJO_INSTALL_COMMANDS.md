# Mojo Installation Commands

Run these commands in your terminal:

## Quick Install (All-in-One)

```bash
# Run the install script
cd /home/lucas/Desktop/WM2/evolution
./INSTALL_MOJO.sh
```

## Manual Step-by-Step

### 1. Install Modular CLI
```bash
curl -s https://get.modular.com | sh -
```

### 2. Add to PATH (temporary, for current session)
```bash
export MODULAR_HOME="$HOME/.modular"
export PATH="$MODULAR_HOME/pkg/packages.modular.com_mojo/bin:$PATH"
```

### 3. Install Mojo
```bash
modular install mojo
```

### 4. Verify Installation
```bash
mojo --version
```

### 5. Make Permanent (add to ~/.bashrc)
```bash
echo 'export MODULAR_HOME="$HOME/.modular"' >> ~/.bashrc
echo 'export PATH="$MODULAR_HOME/pkg/packages.modular.com_mojo/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

## Test Mojo

After installation, test with:

```bash
cd /home/lucas/Desktop/WM2/evolution/mojo_acceleration
mojo build fitness_accelerator.mojo
./fitness_accelerator
```

## Troubleshooting

If `modular` command not found after install:
```bash
# Check if installed
ls -la ~/.modular

# Manually add to PATH
export PATH="$HOME/.modular/bin:$PATH"
```

If Mojo requires authentication:
```bash
modular auth
# Follow prompts to authenticate
```

---

**Note**: Mojo may require a Modular account. If prompted, create one at https://www.modular.com/
