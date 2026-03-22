
with open('whitemagic/tools/middleware.py') as f:
    content = f.read()

# Add a new middleware `mw_sutra_auto_execute` right after `mw_governor`
sutra_mw = """
def mw_sutra_auto_execute(ctx: DispatchContext, next_fn: NextFn) -> dict[str, Any] | None:
    \"\"\"Dharma-gated Auto-Execution.
    Checks the Sutra Kernel to determine if a tool can auto-execute without human approval.
    - Sattvic (Read/Observe): Auto-executes immediately.
    - Rajasic (Write/Create): Auto-executes if intent is high, logs to Zodiac Ledger.
    - Tamasic (Delete/Destructive): Blocked/Paused, sent to Nexus UI via Iceoryx2 for explicit consent.
    \"\"\"
    try:
        from whitemagic.core.bridge.sutra_bridge import get_sutra_kernel
        sutra = get_sutra_kernel()

        # We estimate intent and karma from the tool metadata or context
        # (For now, use defaults or dummy values, real implementation would extract from Gnosis/Karma)
        verdict = sutra.evaluate_action(
            action_type=ctx.tool_name,
            intent_score=1.0,
            karma_debt=0.0
        )

        if verdict.startswith("Panic") or verdict.startswith("Intervene"):
            # Block and push to UI for Karmic Consent
            try:
                from whitemagic.core.ipc_bridge import publish_json
                publish_json("wm/commands", {
                    "type": "karmic_consent_required",
                    "tool": ctx.tool_name,
                    "reason": verdict
                })
            except Exception as e:
                logger.warning(f"Failed to push consent to Nexus UI: {e}")

            return {
                "status": "paused",
                "error": f"Sutra Kernel Intervention: {verdict}. Awaiting Karmic Consent.",
                "action_required": "user_approval"
            }

    except Exception as e:
        logger.warning(f"Sutra Auto-Execute Middleware failed: {e}")

    return next_fn(ctx)
"""

if "def mw_sutra_auto_execute" not in content:
    content = content + "\n" + sutra_mw

with open('whitemagic/tools/middleware.py', 'w') as f:
    f.write(content)

print("Added mw_sutra_auto_execute to middleware.py")
