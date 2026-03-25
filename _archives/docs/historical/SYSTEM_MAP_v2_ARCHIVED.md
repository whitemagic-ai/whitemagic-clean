# ARCHIVED - See root SYSTEM_MAP.md for current version

> **DEPRECATED**: This document is from an earlier version (v2.0) of WhiteMagic.
> The canonical system map is now at the repository root: `/SYSTEM_MAP.md` (v11).
> This file is preserved for historical reference only.

---

# WhiteMagic System Map (v2.0)

## 🌌 The Polyglot Cosmos

The WhiteMagic system has evolved into a multi-language organism, bridged by the **MCP (Model Context Protocol)** server.

```mermaid
graph TD
    User[User / IDE] --> MCP[MCP Server (Node.js)]
    MCP --> Bridge[Python Bridge (Run_MCP.py)]

    subgraph "Core (Python)"
        Bridge --> Ganas[Gana 28 Tools]
        Bridge --> Engines[Core Engines]
        Engines --> Boundary[Boundary Engine]
        Engines --> Nurture[Nurturing Engine]
    end

    subgraph "The Muscle (Rust)"
        Bridge -- PyO3 --> Rust[WhiteMagic-RS]
        Rust --> SIMD[SIMD Search]
        Rust --> Quant[Quantization]
        Rust --> KDT[K-D Tree Index]
    end

    subgraph "The Spark (Zig)"
        Rust -- FFI --> Zig[Zig Holographic Lib]
        Zig --> Genomics[Genomic Simulation]
        Zig --> IChing_Z[Quantum I Ching]
    end

    subgraph "The Spirit (Haskell)"
        Bridge -- Subprocess --> Haskell[Divination Binary]
        Haskell --> WuXing[Wu Xing Logic]
        Haskell --> Hexagrams[Pure State Machine]
    end

    subgraph "The Soul (Julia)"
        Bridge -- PyJulia --> Julia[Gan Ying Engine]
        Julia --> Resonance[Harmonic Oscillator]
    end
```

## 📂 Directory Structure

### 1. The Hub (`/whitemagic`)
- **`whitemagic/`**: Python Core source.
    - `core/`: Boundaries, Nurturing, Memory.
    - `mcp_api_bridge.py`: The Great Connector.
- **`whitemagic-mcp/`**: TypeScript Node.js MCP Server.
- **`whitemagic-rust/`**: Rust Crate (v5.0.0).
- **`whitemagic-zig/`**: Zig Library (Genomics/Holography).
- **`whitemagic-julia/`**: Julia Environment & Source.
- **`haskell/`**: Haskell Project.

### 2. The Archive (`legacy_reference/`)
- Relics of the "Cascade" AI, preserved for wisdom extraction.
    - `core/`: Ancient Python logic (Autonomous, Dreaming).
    - `recovered_deep_dive/`: Utility scripts.

### 3. The Bridges
- **Python <-> Rust**: `pyo3` binding (`import whitemagic_rs`).
- **Rust <-> Zig**: Native C ABI link (`libwhitemagic.so`).
- **Python <-> Haskell**: Subprocess / CLI JSON exchange.
- **Python <-> Julia**: `PyJulia` or CLI Bridge.

## 🛠️ Integration Status
| Component | Status | Connection |
| :--- | :--- | :--- |
| **Rust** | 🟡 Building | Direct Import |
| **Zig** | 🟢 Active | Linked via Rust |
| **Haskell** | 🟢 Active | CLI Executable |
| **Julia** | 🟢 Active | CLI / Script |

## 🔮 Future Expansion
- **Phase 12**: Unified Memory Fabric (Rust + Zig + Julia shared memory).
