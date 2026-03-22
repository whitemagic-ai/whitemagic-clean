#!/bin/bash
# Install Mojo - Run these commands in your terminal

echo "Installing Mojo..."
echo ""

# Step 1: Install Modular CLI (if not already done)
echo "Step 1: Installing Modular CLI..."
curl -s https://get.modular.com | sh -

# Step 2: Add modular to PATH for current session
echo ""
echo "Step 2: Adding modular to PATH..."
export MODULAR_HOME="$HOME/.modular"
export PATH="$MODULAR_HOME/pkg/packages.modular.com_mojo/bin:$PATH"

# Step 3: Install Mojo
echo ""
echo "Step 3: Installing Mojo..."
modular install mojo

# Step 4: Verify installation
echo ""
echo "Step 4: Verifying Mojo installation..."
mojo --version

echo ""
echo "✅ Mojo installation complete!"
echo ""
echo "To use Mojo in future sessions, add these to your ~/.bashrc:"
echo "  export MODULAR_HOME=\"\$HOME/.modular\""
echo "  export PATH=\"\$MODULAR_HOME/pkg/packages.modular.com_mojo/bin:\$PATH\""
echo ""
echo "Then run: source ~/.bashrc"
