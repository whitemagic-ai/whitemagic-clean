"""Database models for MandalaOS Railway Backend."""

import uuid
from datetime import datetime
from typing import List, Optional

from app.database import Base
from sqlalchemy import JSON, Column, DateTime, Float, ForeignKey, Index, String, Text
from sqlalchemy.dialects.postgresql import ARRAY, FLOAT, UUID


class Memory(Base):
    """Memory model for AI agent persistence."""

    __tablename__ = "memories"

    id = Column(UUID(as_uuid=True), primary_key=True, default=uuid.uuid4)
    agent_id = Column(String(255), nullable=False, index=True)
    session_id = Column(String(255), nullable=True, index=True)

    # Content
    title = Column(String(500), nullable=True)
    content = Column(Text, nullable=False)
    content_type = Column(String(50), default="text")  # text, code, json, etc.

    # Vector embedding for semantic search
    embedding = Column(ARRAY(FLOAT), nullable=True)

    # Metadata
    tags = Column(ARRAY(String), default=list)
    importance = Column(Float, default=0.5)
    metadata = Column(JSON, default=dict)

    # Timestamps
    created_at = Column(DateTime, default=datetime.utcnow)
    updated_at = Column(DateTime, default=datetime.utcnow, onupdate=datetime.utcnow)
    expires_at = Column(DateTime, nullable=True)

    # Indexes
    __table_args__ = (
        Index("ix_memories_agent_created", "agent_id", "created_at"),
        Index("ix_memories_embedding", "embedding", postgresql_using="ivfflat"),
    )


class Session(Base):
    """Agent session for continuity."""

    __tablename__ = "sessions"

    id = Column(String(255), primary_key=True)
    agent_id = Column(String(255), nullable=False, index=True)

    # Session state
    state = Column(JSON, default=dict)
    context_window = Column(JSON, default=list)  # Recent memory IDs

    # Status
    is_active = Column(String(20), default="active")  # active, paused, closed

    # Timestamps
    created_at = Column(DateTime, default=datetime.utcnow)
    last_activity = Column(DateTime, default=datetime.utcnow)

    # WebSocket connection tracking
    websocket_connections = Column(JSON, default=list)


class Agent(Base):
    """Registered AI agent."""

    __tablename__ = "agents"

    id = Column(String(255), primary_key=True)
    name = Column(String(255), nullable=False)
    agent_type = Column(String(50), default="assistant")  # assistant, autonomous, hybrid

    # Configuration
    config = Column(JSON, default=dict)
    capabilities = Column(ARRAY(String), default=list)

    # Statistics
    total_memories = Column(Float, default=0)
    total_sessions = Column(Float, default=0)

    # Timestamps
    created_at = Column(DateTime, default=datetime.utcnow)
    last_seen = Column(DateTime, default=datetime.utcnow)
