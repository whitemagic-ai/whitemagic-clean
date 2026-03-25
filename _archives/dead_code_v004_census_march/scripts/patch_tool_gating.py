import re

file_path = "/home/lucas/Desktop/whitemagicdev/whitemagic/security/tool_gating.py"

with open(file_path, "r") as f:
    content = f.read()

patch = """
def check_tool_execution(
    tool_name: str, params: dict[str, Any],
) -> tuple[bool, str, dict[str, Any]]:
    \"\"\"Check if a tool can be executed with given parameters.\"\"\"
    
    # NEW: SutraCode Kernel check (hard stop)
    try:
        import whitemagic_rust
        if hasattr(whitemagic_rust, 'sutra_kernel'):
            kernel = whitemagic_rust.sutra_kernel.SutraKernel()
            import json
            # Serialize params for the Rust kernel
            payload_str = json.dumps(params, default=str)
            # This will panic and crash the thread if a violation is found
            kernel.verify_action("mcp_client", tool_name, payload_str)
    except Exception as e:
        # We only catch Python-level exceptions here (like missing module).
        # Rust panics will bubble up and crash the worker thread safely.
        pass

    gate = get_tool_gate()

    # Check tool allowed
    allowed, reason = gate.check_tool_allowed(tool_name)
    if not allowed:
        return False, reason, {}

    # Validate parameters
    return gate.validate_tool_params(tool_name, params)
"""

# Replace the original check_tool_execution with our patched version
pattern = r'def check_tool_execution\(\n    tool_name: str, params: dict\[str, Any\],\n\) -> tuple\[bool, str, dict\[str, Any\]\]:\n    """Check if a tool can be executed with given parameters.\n\n    Returns:\n        \(allowed: bool, reason: str, sanitized_params: dict\)\n\n    """\n    gate = get_tool_gate\(\)\n\n    # Check tool allowed\n    allowed, reason = gate\.check_tool_allowed\(tool_name\)\n    if not allowed:\n        return False, reason, \{\}\n\n    # Validate parameters\n    return gate\.validate_tool_params\(tool_name, params\)'

new_content = re.sub(pattern, patch.strip(), content, flags=re.MULTILINE)

with open(file_path, "w") as f:
    f.write(new_content)

print("tool_gating.py patched successfully!")
