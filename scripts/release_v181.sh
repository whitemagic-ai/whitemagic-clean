#!/bin/bash
# v20.0.0 Release Script - Run when git repository is available

set -e

echo "=================================="
echo "WhiteMagic v20.0.0 Release Script"
echo "=================================="
echo ""

# Check if we're in a git repo
if [ ! -d ".git" ]; then
    echo "Error: Not a git repository"
    echo "Looking for git repository..."
    
    # Try to find git repo
    if [ -d "$HOME/windsurf/whitemagicdev/.git" ]; then
        cd "$HOME/windsurf/whitemagicdev"
        echo "Found repo at: $HOME/windsurf/whitemagicdev"
    elif [ -d "/home/lucas/Desktop/whitemagicpublic/.git" ]; then
        echo "Found public repo - copying files..."
        # Copy release files to public repo
        cp /home/lucas/Desktop/whitemagicdev/RELEASE_NOTES.md /home/lucas/Desktop/whitemagicpublic/
        cp /home/lucas/Desktop/whitemagicdev/VERSION /home/lucas/Desktop/whitemagicpublic/
        cd /home/lucas/Desktop/whitemagicpublic
    else
        echo "Error: Cannot find git repository"
        exit 1
    fi
fi

echo "Git repository: $(pwd)"
echo "Current branch: $(git branch --show-current)"
echo ""

# Check version
echo "Version: $(cat VERSION)"
echo ""

# Stage all changes
echo "Staging changes..."
git add -A

# Show status
echo ""
echo "Changes to commit:"
git status --short

# Commit
echo ""
echo "Creating commit..."
git commit -m "v20.0.0: The Polyglot Singularity - Universal Version Unification"

# Create tag
echo ""
echo "Creating tag v20.0.0..."
git tag -a v20.0.0 -m "v20.0.0 Release: The Polyglot Singularity

- Universal Version Unification across 11 languages
- GitHub Workflow Overhaul for manual/automated releases
- Core Stability & Version Drift Resolution
- Accelerated Recall & Persistent Polyglot Backends

All systems synchronized, health: 1.0"

# Push
echo ""
echo "Pushing to origin..."
git push origin main
git push origin v20.0.0

echo ""
echo "=================================="
echo "v20.0.0 Released Successfully!"
echo "=================================="
echo ""
echo "Next steps:"
echo "1. Deploy Elixir supervisor with FAST lane pools"
echo "2. Start Julia persistent server"
echo "3. Monitor performance metrics"
echo ""
