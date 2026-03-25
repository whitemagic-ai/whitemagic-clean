#!/bin/bash
# Windsurf Stability Wrapper
# Disables GPU acceleration and sets memory limits to prevent OOM crashes on Linux.

# Increase file descriptor limit
ulimit -n 1048576

# Set Electron/Chrome flags for stability
# --disable-gpu: Prevents many renderer crashes on Linux/NVIDIA/Wayland
# --disable-dev-shm-usage: Uses /tmp instead of /dev/shm (prevents crashes in low shm environments)
# --js-flags: Limits heap size to 4GB to prevent unbounded leaks from killing the system
export ELECTRON_EXTRA_LAUNCH_ARGS="--disable-gpu --disable-dev-shm-usage --js-flags='--max-old-space-size=4096'"

echo "Launching Windsurf with stability flags..."
/usr/bin/windsurf $ELECTRON_EXTRA_LAUNCH_ARGS "$@"
