# WhiteMagic v21 - Minimal Production Dockerfile
FROM python:3.11-slim-bookworm

# Install system deps + Rust
RUN apt-get update && apt-get install -y --no-install-recommends \
    libsqlite3-dev curl ca-certificates build-essential \
    && rm -rf /var/lib/apt/lists/* \
    && curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh -s -- -y --default-toolchain stable

ENV PATH="/root/.cargo/bin:${PATH}"

WORKDIR /app

# Copy pyproject.toml first for layer caching
COPY pyproject.toml .
COPY README.md .
COPY LICENSE .
COPY VERSION .

# Install the package with all core dependencies
RUN pip install --no-cache-dir -e . && \
    pip install --no-cache-dir maturin

# Copy application code
COPY whitemagic/ ./whitemagic/
COPY whitemagic-rust/ ./whitemagic-rust/

# Build and install Rust extension if available (optional - Python fallbacks exist)
RUN if [ -f whitemagic-rust/Cargo.toml ] && command -v clang >/dev/null 2>&1; then \
    cd whitemagic-rust && \
    maturin build --release && \
    pip install target/wheels/*.whl && \
    cd .. ; \
    else \
    echo "Rust extension skipped - Python fallbacks will be used"; \
    fi

# Environment
ENV PYTHONPATH=/app
ENV WHITEMAGIC_DB_PATH=/data/whitemagic.db

# Create data volume
RUN mkdir -p /data

EXPOSE 8000

# Default to MCP stdio server (most common use case)
CMD ["python", "-m", "whitemagic.run_mcp_lean"]
