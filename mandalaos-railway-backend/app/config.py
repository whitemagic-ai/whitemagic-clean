"""Configuration for MandalaOS Railway Backend."""

import os
from typing import List

from pydantic_settings import BaseSettings


class Settings(BaseSettings):
    """Application settings."""
    
    # Database
    DATABASE_URL: str = os.getenv(
        "DATABASE_URL",
        "postgresql://user:pass@localhost/mandalaos"
    )
    
    # Redis (for caching and pub/sub)
    REDIS_URL: str = os.getenv(
        "REDIS_URL",
        "redis://localhost:6379/0"
    )
    
    # Security
    API_KEY: str = os.getenv("API_KEY", "dev-key-change-in-production")
    JWT_SECRET: str = os.getenv("JWT_SECRET", "dev-secret-change-in-production")
    
    # CORS
    CORS_ORIGINS: List[str] = [
        "http://localhost:3000",
        "http://localhost:8080",
        "https://*.railway.app",
    ]
    
    # Embeddings
    EMBEDDING_DIM: int = 384
    EMBEDDING_MODEL: str = "BAAI/bge-small-en-v1.5"
    
    # WebSocket
    WS_HEARTBEAT_INTERVAL: int = 30  # seconds
    
    class Config:
        env_file = ".env"


settings = Settings()
