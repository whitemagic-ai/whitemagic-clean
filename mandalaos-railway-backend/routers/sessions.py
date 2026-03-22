"""Session management routes for MandalaOS Railway Backend."""

from datetime import datetime

from app.database import get_db
from fastapi import APIRouter, Depends, HTTPException
from pydantic import BaseModel
from sqlalchemy import desc, select, update
from sqlalchemy.ext.asyncio import AsyncSession

from models import Agent, Session

router = APIRouter()


class SessionCreate(BaseModel):
    """Request model for creating a session."""
    agent_id: str
    initial_state: dict = {}


class SessionResponse(BaseModel):
    """Response model for a session."""
    id: str
    agent_id: str
    state: dict
    is_active: str
    created_at: str
    last_activity: str


class StateUpdate(BaseModel):
    """Request model for updating session state."""
    state: dict
    context_window: list[str] | None = None


@router.post("/", response_model=SessionResponse)
async def create_session(
    session_data: SessionCreate,
    db: AsyncSession = Depends(get_db)
) -> Session:
    """Create a new session for an agent."""
    import uuid

    session_id = f"sess_{uuid.uuid4().hex[:16]}"

    db_session = Session(
        id=session_id,
        agent_id=session_data.agent_id,
        state=session_data.initial_state,
        is_active="active",
    )
    db.add(db_session)

    # Update agent stats
    await db.execute(
        update(Agent)
        .where(Agent.id == session_data.agent_id)
        .values(
            total_sessions=Agent.total_sessions + 1,
            last_seen=datetime.utcnow()
        )
    )

    await db.flush()
    await db.refresh(db_session)
    return db_session


@router.get("/agent/{agent_id}", response_model=list[SessionResponse])
async def list_agent_sessions(
    agent_id: str,
    active_only: bool = True,
    db: AsyncSession = Depends(get_db)
) -> list[Session]:
    """List sessions for an agent."""
    query = select(Session).where(Session.agent_id == agent_id)

    if active_only:
        query = query.where(Session.is_active == "active")

    query = query.order_by(desc(Session.last_activity))

    result = await db.execute(query)
    return result.scalars().all()


@router.get("/{session_id}", response_model=SessionResponse)
async def get_session(
    session_id: str,
    db: AsyncSession = Depends(get_db)
) -> Session:
    """Get a specific session."""
    result = await db.execute(
        select(Session).where(Session.id == session_id)
    )
    session = result.scalar_one_or_none()

    if not session:
        raise HTTPException(status_code=404, detail="Session not found")

    return session


@router.post("/{session_id}/state")
async def update_session_state(
    session_id: str,
    update: StateUpdate,
    db: AsyncSession = Depends(get_db)
) -> dict:
    """Update session state and context window."""
    result = await db.execute(
        select(Session).where(Session.id == session_id)
    )
    session = result.scalar_one_or_none()

    if not session:
        raise HTTPException(status_code=404, detail="Session not found")

    # Update state
    current_state = dict(session.state) if session.state else {}
    current_state.update(update.state)
    session.state = current_state

    if update.context_window:
        session.context_window = update.context_window

    session.last_activity = datetime.utcnow()

    return {"updated": True, "session_id": session_id}


@router.post("/{session_id}/pause")
async def pause_session(
    session_id: str,
    db: AsyncSession = Depends(get_db)
) -> dict:
    """Pause a session (preserves state, disconnects)."""
    result = await db.execute(
        select(Session).where(Session.id == session_id)
    )
    session = result.scalar_one_or_none()

    if not session:
        raise HTTPException(status_code=404, detail="Session not found")

    session.is_active = "paused"
    return {"paused": True, "session_id": session_id}


@router.post("/{session_id}/resume")
async def resume_session(
    session_id: str,
    db: AsyncSession = Depends(get_db)
) -> SessionResponse:
    """Resume a paused session."""
    result = await db.execute(
        select(Session).where(Session.id == session_id)
    )
    session = result.scalar_one_or_none()

    if not session:
        raise HTTPException(status_code=404, detail="Session not found")

    session.is_active = "active"
    session.last_activity = datetime.utcnow()

    return session


@router.post("/{session_id}/close")
async def close_session(
    session_id: str,
    db: AsyncSession = Depends(get_db)
) -> dict:
    """Close a session (marks as closed, keeps history)."""
    result = await db.execute(
        select(Session).where(Session.id == session_id)
    )
    session = result.scalar_one_or_none()

    if not session:
        raise HTTPException(status_code=404, detail="Session not found")

    session.is_active = "closed"
    session.websocket_connections = []

    return {"closed": True, "session_id": session_id}
