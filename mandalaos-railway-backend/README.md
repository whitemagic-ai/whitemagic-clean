# MandalaOS Railway Backend

State server for AI-native environments with persistent memory continuity.

## Overview

This backend provides:
- **Memory persistence** for AI agents via PostgreSQL
- **Session management** with state continuity across disconnects
- **WebSocket real-time** communication for live AI environments
- **Vector search** foundation for semantic memory retrieval
- **Multi-agent support** with isolated memory spaces

## Quick Start

### Local Development

```bash
# 1. Create virtual environment
python -m venv .venv
source .venv/bin/activate

# 2. Install dependencies
pip install -r requirements.txt

# 3. Set up PostgreSQL (or use Railway Postgres)
export DATABASE_URL="postgresql://user:pass@localhost/mandalaos"

# 4. Run server
uvicorn main:app --reload --host 0.0.0.0 --port 8000
```

### Deploy to Railway

[![Deploy on Railway](https://railway.app/button.svg)](https://railway.app/template/EXAMPLE)

Or manually:

```bash
# 1. Install Railway CLI
npm install -g @railway/cli

# 2. Login and create project
railway login
railway init

# 3. Add PostgreSQL plugin
railway add --plugin postgresql

# 4. Deploy
railway up
```

## API Endpoints

### Health
- `GET /health/` - Full health check with DB connectivity
- `GET /health/ready` - Kubernetes readiness probe
- `GET /health/live` - Kubernetes liveness probe

### Memories
- `POST /api/v1/memories/` - Create memory
- `GET /api/v1/memories/?agent_id={id}` - List memories
- `GET /api/v1/memories/search?query={text}` - Search memories
- `GET /api/v1/memories/{id}` - Get specific memory
- `DELETE /api/v1/memories/{id}` - Delete memory

### Sessions
- `POST /api/v1/sessions/` - Create session
- `GET /api/v1/sessions/agent/{agent_id}` - List sessions
- `POST /api/v1/sessions/{id}/state` - Update state
- `POST /api/v1/sessions/{id}/pause` - Pause session
- `POST /api/v1/sessions/{id}/resume` - Resume session
- `POST /api/v1/sessions/{id}/close` - Close session

### WebSocket
- `WS /ws/{session_id}?agent_id={id}` - Real-time connection

## WebSocket Protocol

```json
// Client -> Server: Ping
{"type": "ping"}

// Server -> Client: Pong
{"type": "pong", "timestamp": "2024-01-01T00:00:00Z"}

// Client -> Server: State update
{"type": "state_update", "data": {"key": "value"}}

// Server -> Client: Broadcast to session
{"type": "state_changed", "agent_id": "agent_123", "data": {...}}

// Client -> Server: Memory created notification
{"type": "memory_created", "memory_id": "uuid"}
```

## Environment Variables

| Variable | Description | Default |
|----------|-------------|---------|
| `DATABASE_URL` | PostgreSQL connection string | `postgresql://...` |
| `REDIS_URL` | Redis for caching/pub-sub | `redis://...` |
| `API_KEY` | API authentication key | `dev-key-...` |
| `JWT_SECRET` | JWT signing secret | `dev-secret-...` |
| `CORS_ORIGINS` | Allowed CORS origins | `http://localhost:3000` |

## Architecture

```
┌─────────────────────────────────────────┐
│         AI Agents / IDEs / MCP          │
│    (WhiteMagic, ARIA, Custom Tools)     │
└─────────────────┬───────────────────────┘
                  │ HTTP / WebSocket
┌─────────────────▼───────────────────────┐
│     MandalaOS Railway Backend           │
│  ┌─────────┐ ┌──────────┐ ┌─────────┐ │
│  │  REST   │ │ WebSocket│ │  State  │ │
│  │  API    │ │  Server  │ │  Mgmt   │ │
│  └────┬────┘ └────┬─────┘ └────┬────┘ │
│       └───────────┴────────────┘      │
│                   │                     │
│  ┌───────────────▼────────────────┐   │
│  │       PostgreSQL (Railway)      │   │
│  │  ┌─────────┐ ┌──────────────┐   │   │
│  │  │Memories │ │  Sessions    │   │   │
│  │  │ (pgvector)│  (State)    │   │   │
│  │  └─────────┘ └──────────────┘   │   │
│  └──────────────────────────────────┘   │
└─────────────────────────────────────────┘
```

## Integration with WhiteMagic

```python
from whitemagic.extensions.railway_backend import RailwayBackend

# Connect to MandalaOS Railway backend
backend = RailwayBackend(
    base_url="https://mandalaos.up.railway.app",
    api_key="your-api-key"
)

# Store memory with automatic persistence
backend.remember(
    agent_id="aria",
    content="Important insight from this session",
    tags=["insight", "priority"],
    importance=0.9
)

# Retrieve memories with semantic search
memories = backend.recall(
    agent_id="aria",
    query="insights from sessions",
    limit=10
)
```

## License

MIT - See LICENSE file
