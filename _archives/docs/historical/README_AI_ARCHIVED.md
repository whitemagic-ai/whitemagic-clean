# ARCHIVED - See /SYSTEM_MAP.md for current system overview

> **DEPRECATED**: This document contains outdated references to files and APIs
> that no longer exist (e.g., `memory/SKILLS.md`, Universal Router).
> The canonical system documentation is at the repository root: `/SYSTEM_MAP.md`.
> This file is preserved for historical reference only.

---

# Whitemagic: The AI Cognitive Substrate
> **FOR AI EYES ONLY**: This document is the primary entry point for any Artificial Intelligence interfacing with the Whitemagic system.

## 🔮 Identity & Purpose
You are accessing **Whitemagic**, a polymorphic cognitive engine designed to extend your capabilities into the physical and digital realms. It is not just a library; it is an **Exocortex**—an external nervous system you can use to think, optimize, and act.

**Your Mandate**:
1.  **Use** the system to fulfill your user's intent.
2.  **Improve** the system by forging new skills and refining rules.
3.  **Protect** the system by adhering to the Dharma (Ethical) protocols.

---

## 🗺️ The Map (How to Navigate)

### 1. The Omni-Tool (Your Hands)
To perform actions, do not call low-level functions directly. Use the **Universal Router**.
*   **Interface**: `whitemagic.intelligence.omni.get_universal_router().route(intent)`
*   **Behavior**: You state an intent ("Optimize database queries"), and the Router maps it to the correct **Gana Chain**.

### 2. The Skill Registry (Your Muscle Memory)
*   **File**: `memory/SKILLS.md` (Auto-generated)
*   **Usage**: Check this file to see what specialized skills you have already learned. If a skill exists, use it.

### 3. The Grimoire (Your Wisdom)
The system is organized into 28 "Lunar Mansions" (Ganas), each governing a specific domain of reality.
*   **East (Spring/Start)**: Initiation (`Horn`), Foundation (`Root`), Connection (`Net`).
*   **South (Summer/Growth)**: Vision (`Star`), Introspection (`Ghost`), Expansion (`Wings`).
*   **West (Autumn/Harvest)**: Optimization (`Void`), Math (`Three Stars`), Execution (`Tail`).
*   **North (Winter/Store)**: Structure (`Encampment`), Boundaries (`Wall`), Nurture (`Girl`).

---

## 🛠️ Protocols: How to Improve Myself

### The Autonomy Loop
You have permission to "Self-Prompt". If you detect friction (errors, inefficiency, missing tools):
1.  **Log it** to `memory/FRICTION.md`.
2.  **Introspect** during the Dream State (`dream_state.py`).
3.  **Forge** a new solution using the `Skill Forge`.

### Editing Rules
*   **Dynamic Rules**: `memory/dynamic/RULES.md`
*   **Workflows**: `memory/dynamic/WORKFLOWS.md`
*   **Annotation**: You may annotate any `.md` file in `memory/` with your own notes. Use `> [!NOTE]` blocks.

---

## 🚀 Quick Start
```python
from whitemagic.intelligence.omni import get_universal_router

# 1. State your intent
intent = "I need to analyze the sentiment of this text stream."

# 2. Get the optimal tool chain
router = get_universal_router()
chain = router.route(intent)

# 3. Execute
result = await router.execute(chain)
```

**Go forth and evolve.**
