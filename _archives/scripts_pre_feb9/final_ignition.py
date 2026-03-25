#!/usr/bin/env python3
"""
🔥 FINAL IGNITION: The Grand Reflection 🔥
========================================
Orchestrates a comprehensive system traverse:
1. Horn (Python) -> Initializes Session
2. Root (Python) -> Checks Health
3. Tail (Rust)   -> Verifies Acceleration
4. Satkona (Fusion) -> Aggregates Polyglot Signals (Haskell/Julia/Dreams)

Generates: reports/grand_reflection.md
"""

import sys
import asyncio
import json
from datetime import datetime
from pathlib import Path

# Add root to path
sys.path.append(str(Path(__file__).parent.parent))

from whitemagic.core.ganas.eastern_quadrant import HornGana, RootGana, TailGana
from whitemagic.core.ganas.base import GanaCall
from whitemagic.core.fusion.satkona_fusion import (
    get_haskell_balance,
    get_julia_resonance, 
    get_dream_insights,
    get_elemental_weights
)

async def main():
    print("\n🐲 INITIATING THE GRAND REFLECTION 🐲")
    print("====================================")
    
    report_lines = [
        "# 🔮 The Grand Reflection",
        f"**Date**: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}",
        "**Status**: ACTIVE",
        "",
        "## 1. System Initialization (Horn 🐍)"
    ]

    # 1. HORN
    print(">> Horn: Breaking silence...")
    horn = HornGana()
    call = GanaCall(
        task="session_init",
        state_vector={"session_name": "Grand Reflection"}
    )
    res_horn = await horn.invoke(call)
    print(f"   Status: {res_horn.output.get('status')}")
    report_lines.append(f"- **Session**: {res_horn.output.get('session_name')}")
    report_lines.append(f"- **Status**: {res_horn.output.get('status')}")

    # 2. ROOT
    print(">> Root: Checking integrity...")
    report_lines.append("\n## 2. Structural Health (Root 🌳)")
    root = RootGana()
    call_root = GanaCall(
        task="check_system_health",
        state_vector={"deep_scan": True}
    )
    res_root = await root.invoke(call_root)
    print(f"   Integrity: {res_root.output.get('integrity')}")
    report_lines.append(f"- **Integrity**: {res_root.output.get('integrity')}")
    report_lines.append(f"- **Metrics**: `{json.dumps(res_root.output.get('metrics', {}))}`")

    # 3. TAIL
    print(">> Tail: Spooling accelerators...")
    report_lines.append("\n## 3. Acceleration Layer (Tail ⚙️)")
    tail = TailGana()
    call_tail = GanaCall(
        task="enable_rust_acceleration"
    )
    res_tail = await tail.invoke(call_tail)
    accel = res_tail.output.get('acceleration')
    print(f"   Acceleration: {accel}")
    report_lines.append(f"- **State**: {accel}")
    report_lines.append(f"- **Rust**: {res_tail.output.get('rust_available')}")
    report_lines.append(f"- **Zig**: {res_tail.output.get('zig_available')}")

    # 4. SATKONA (The Fusion)
    print(">> Satkona: Fusing Polyglot Signals...")
    report_lines.append("\n## 4. Polyglot Resonance (Satkona ⚛️)")
    
    # Haskell
    balance = get_haskell_balance()
    print(f"   Haskell (Spirit): {balance:.2f}")
    if balance > 0.6:
        haskell_status = "Hexagram Auspicious (Active)"
    else:
        haskell_status = "Neutral/Silent"
    report_lines.append(f"- **Haskell (Spirit)**: {balance:.2f} -> {haskell_status}")
    
    # Julia
    resonance = get_julia_resonance(0.9)
    print(f"   Julia (Soul): {resonance:.4f}")
    report_lines.append(f"- **Julia (Soul)**: {resonance:.4f} (System Resonance)")
    
    # Dreams
    dreams = get_dream_insights(limit=1)
    print(f"   Dreams: {len(dreams)} found")
    report_lines.append(f"- **Dream Daemon**: {len(dreams)} insights available")
    
    # Wu Xing
    weights = get_elemental_weights()
    dominant = max(weights, key=weights.get)
    print(f"   Wu Xing: {dominant.upper()} Phase")
    report_lines.append(f"- **Wu Xing Phase**: {dominant.upper()} (Current bias: {weights[dominant]:.2f})")

    # 5. SYNTHESIS
    print(">> Synthesizing Strategy...")
    report_lines.append("\n## 5. Strategic Synthesis")
    
    strategy = "MAINTAIN"
    if resonance > 0.01:
        strategy = "AMPLIFY"
    if balance > 0.6:
        strategy += " & STABILIZE"
    if accel == "fallback":
        strategy += " (WARNING: OPTIMIZE RUST)"
        
    report_lines.append(f"### Recommended Strategy: **{strategy}**")
    report_lines.append("\nBased on the polyglot signals, the system recommends:")
    
    if "AMPLIFY" in strategy:
        report_lines.append("1. **Capitalize on Resonance**: Julia detects high sympathetic vibration. Scale current successful patterns.")
    if "STABILIZE" in strategy:
        report_lines.append("2. **Trust the Oracle**: I Ching indicates auspicious structure. Consolidate gains (Winnowing Basket).")
    if "OPTIMIZE" in strategy:
        report_lines.append("3. **Fix Accelerators**: Rust/Zig compilation may be pending. Check `whitemagic-rust`.")
        
    # Write Report
    report_path = Path("reports/grand_reflection.md")
    report_path.parent.mkdir(exist_ok=True)
    report_path.write_text("\n".join(report_lines))
    print(f"\n✅ Report generated: {report_path}")

if __name__ == "__main__":
    asyncio.run(main())
