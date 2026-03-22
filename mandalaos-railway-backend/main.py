"""MandalaOS Railway Backend — State Server for AI-Native Environments.

Provides persistent state, memory continuity, and real-time synchronization
for AI agents connecting via WhiteMagic MCP.

Features:
- Memory storage/retrieval with vector search
- WebSocket real-time updates
- Multi-agent session management
- PostgreSQL backend via Railway

Author: WhiteMagic Team
Version: 0.1.0
"""

from contextlib import asynccontextmanager
from typing import AsyncGenerator

from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

from app.config import settings
from app.database import init_db
from routers import memories, sessions, health, websocket


@asynccontextmanager
async def lifespan(app: FastAPI) -> AsyncGenerator:
    """Initialize database on startup."""
    await init_db()
    yield


app = FastAPI(
    title="MandalaOS Railway Backend",
    description="State server for AI-native environments with persistent memory",
    version="0.1.0",
    lifespan=lifespan,
)

# CORS for browser-based AI environments
app.add_middleware(
    CORSMiddleware,
    allow_origins=settings.CORS_ORIGINS,
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# Routers
app.include_router(health.router, prefix="/health", tags=["health"])
app.include_router(memories.router, prefix="/api/v1/memories", tags=["memories"])
app.include_router(sessions.router, prefix="/api/v1/sessions", tags=["sessions"])
app.include_router(websocket.router, prefix="/ws", tags=["websocket"])


@app.get("/")
async def root() -> dict:
    """Root endpoint."""
    return {
        "service": "MandalaOS Railway Backend",
        "version": "0.1.0",
        "status": "online",
        "docs": "/docs",
    }
