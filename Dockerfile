# WhiteMagic v20 - Minimal Production Dockerfile
FROM python:3.11-slim-bookworm

# Install system deps
RUN apt-get update && apt-get install -y --no-install-recommends \
    libsqlite3-dev curl ca-certificates \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

# Copy requirements first for layer caching
COPY requirements.txt .
RUN pip install --no-cache-dir -r requirements.txt

# Copy application code
COPY whitemagic/ ./whitemagic/
COPY whitemagic-rust/ ./whitemagic-rust/

# Install Rust extension if available
RUN if [ -f whitemagic-rust/Cargo.toml ]; then \
    pip install maturin && \
    cd whitemagic-rust && \
    maturin build --release && \
    pip install target/wheels/*.whl; \
    fi

# Environment
ENV PYTHONPATH=/app
ENV WHITEMAGIC_DB_PATH=/data/whitemagic.db

# Create data volume
RUN mkdir -p /data

EXPOSE 8000

CMD ["python", "-m", "whitemagic.server"]
