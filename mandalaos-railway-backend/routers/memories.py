"""Memory API routes for MandalaOS Railway Backend."""

from uuid import UUID

from app.database import get_db
from fastapi import APIRouter, Depends, HTTPException, Query
from pydantic import BaseModel
from sqlalchemy import desc, select
from sqlalchemy.ext.asyncio import AsyncSession

from models import Memory

router = APIRouter()


class MemoryCreate(BaseModel):
    """Request model for creating a memory."""
    agent_id: str
    session_id: str | None = None
    title: str | None = None
    content: str
    content_type: str = "text"
    tags: list[str] = []
    importance: float = 0.5
    metadata: dict = {}


class MemoryResponse(BaseModel):
    """Response model for a memory."""
    id: UUID
    agent_id: str
    session_id: str | None
    title: str | None
    content: str
    content_type: str
    tags: list[str]
    importance: float
    metadata: dict
    created_at: str


@router.post("/", response_model=MemoryResponse)
async def create_memory(
    memory: MemoryCreate,
    db: AsyncSession = Depends(get_db)
) -> Memory:
    """Create a new memory for an agent."""
    db_memory = Memory(**memory.model_dump())
    db.add(db_memory)
    await db.flush()
    await db.refresh(db_memory)
    return db_memory


@router.get("/", response_model=list[MemoryResponse])
async def list_memories(
    agent_id: str,
    session_id: str | None = None,
    tag: str | None = None,
    limit: int = Query(20, ge=1, le=100),
    offset: int = Query(0, ge=0),
    db: AsyncSession = Depends(get_db)
) -> list[Memory]:
    """List memories for an agent, optionally filtered."""
    query = select(Memory).where(Memory.agent_id == agent_id)

    if session_id:
        query = query.where(Memory.session_id == session_id)
    if tag:
        query = query.where(Memory.tags.contains([tag]))

    query = query.order_by(desc(Memory.created_at)).offset(offset).limit(limit)

    result = await db.execute(query)
    return result.scalars().all()


@router.get("/search")
async def search_memories(
    agent_id: str,
    query: str,
    limit: int = Query(10, ge=1, le=50),
    db: AsyncSession = Depends(get_db)
) -> list[dict]:
    """Search memories by content (semantic search when embeddings available)."""
    # Simple text search for now; can be upgraded to vector search
    sql_query = select(Memory).where(
        Memory.agent_id == agent_id
    ).where(
        (Memory.content.ilike(f"%{query}%")) |
        (Memory.title.ilike(f"%{query}%"))
    ).limit(limit)

    result = await db.execute(sql_query)
    memories = result.scalars().all()

    return [
        {
            "id": str(m.id),
            "title": m.title,
            "content": m.content[:500],  # Truncate for response
            "score": 1.0,  # Placeholder for semantic score
            "created_at": m.created_at.isoformat() if m.created_at else None,
        }
        for m in memories
    ]


@router.get("/{memory_id}", response_model=MemoryResponse)
async def get_memory(
    memory_id: UUID,
    db: AsyncSession = Depends(get_db)
) -> Memory:
    """Get a specific memory by ID."""
    result = await db.execute(
        select(Memory).where(Memory.id == memory_id)
    )
    memory = result.scalar_one_or_none()

    if not memory:
        raise HTTPException(status_code=404, detail="Memory not found")

    return memory


@router.delete("/{memory_id}")
async def delete_memory(
    memory_id: UUID,
    db: AsyncSession = Depends(get_db)
) -> dict:
    """Delete a memory."""
    result = await db.execute(
        select(Memory).where(Memory.id == memory_id)
    )
    memory = result.scalar_one_or_none()

    if not memory:
        raise HTTPException(status_code=404, detail="Memory not found")

    await db.delete(memory)
    return {"deleted": True, "id": str(memory_id)}
