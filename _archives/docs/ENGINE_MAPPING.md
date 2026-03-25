# Engine-Gana Integration Map

## Philosophy
Each of the 28 Gana tools corresponds to a specific **Core Engine** (Python) or **Polyglot Module** (Rust/Zig/Haskell/Julia). This map defines the routing logic for the `TriEngineWrapper`.

## The Eastern Quadrant (Azure Dragon) - Initiation
| Gana | Mansion | Engine / Module | Role |
| :--- | :--- | :--- | :--- |
| **Horn** (Jiao) | Initiation | `SessionEngine` (Python) | Start/Manage Sessions |
| **Neck** (Kang) | Stability | `MemoryManager` (Python/Rust) | Context Retrieval |
| **Root** (Di) | Health | `SystemMonitor` (Python) | Health Checks |
| **Room** (Fang) | Locks | `DharmaEngine` (Python) | Resource Permissions |
| **Heart** (Xin) | Context | `HeartGana` (Python) | Emotional Context |
| **Tail** (Wei) | Acceleration | `whitemagic-rs` (Rust) | SIMD/Parallel Tasks |
| **Basket** (Ji) | Separation | `whitemagic-rs` (Rust) | Data Filtering/Sifting |

## The Southern Quadrant (Vermilion Bird) - Expansion
| Gana | Mansion | Engine / Module | Role |
| :--- | :--- | :--- | :--- |
| **Well** (Jing) | Source | `KaizenEngine` (Python) | Self-Improvement |
| **Ghost** (Gui) | Accumulation | `SearchEngine` (Rust) | Deep Retrieval |
| **Willow** (Liu) | Resilience | `AntiFragility` (Python) | Error Recovery |
| **Star** (Xing) | Governance | `Haskell/WuXing` | Strategic Balance |
| **Net** (Zhang) | Connection | `GraphEngine` (Rust) | Knowledge Graph |
| **Wings** (Yi) | Deployment | `Deployer` (Python) | Code Execution |
| **Chariot** (Zhen) | Mobility | `Archaeology` (Python) | File System Ops |

## The Western Quadrant (White Tiger) - Harvesting
| Gana | Mansion | Engine / Module | Role |
| :--- | :--- | :--- | :--- |
| **Legs** (Kui) | Balance | `Haskell/IChing` | Divination/Balance |
| **Bond** (Lou) | Harvest | `GardenManager` (Python) | Outcome Collection |
| **Stomach** (Wei) | Digestion | `VectorDB` (Rust) | Embedding Storage |
| **Mao** (Pleiades) | Focus | `AttentionMech` (Python) | Task Prioritization |
| **Net** (Bi) | Filter | `BoundaryEngine` (Python) | Safety/Ethics |
| **Beak** (Zui) | Precision | `Validator` (Python) | Code/Test Verification |
| **Three** (Shen) | Rejuvenation | `Julia/GanYing` | Resonance/Echo |

## The Northern Quadrant (Black Tortoise) - Conservation
| Gana | Mansion | Engine / Module | Role |
| :--- | :--- | :--- | :--- |
| **Well** (Jing) | Purity | `CleanCode` (Python) | Linter/Formatter |
| **Ghost** (Gui) | Ancestors | `ArchiveManager` (Python) | Backup/Restore |
| **Willow** (Liu) | Flexibility | `Adapter` (Python) | API Translation |
| **Star** (Xing) | Guidance | `NurturingEngine` (Python) | User Profiles |
| **Wall** (Bi) | Boundary | `BoundaryEngine` (Python) | Limits/Cost |
| **House** (Shi) | Shelter | `Container` (Docker/K8s) | Environment |
| **Wall** (Bi) | Defense | `SecurityEngine` (Python) | Auth/Encryption |

## Integration Priorities (Phase 12)
1.  **Rust**: Link `Tail` and `Ghost` to `whitemagic-rs` for speed.
2.  **Julia**: Link `Three Stars` to `gan_ying.jl` for resonance.
3.  **Zig**: Link `Genome` (if applicable) to `whitemagic-zig`.
4.  **Haskell**: Link `Legs` to `haskell-binary` for I Ching.
