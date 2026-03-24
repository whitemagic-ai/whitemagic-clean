from whitemagic.inference.bitnet_bridge import infer as bitnet_infer
from whitemagic.inference.local_llm import LocalLLM
from typing import Any

def bitnet_status(**kwargs: Any) -> dict[str, Any]:
    from whitemagic.inference.bitnet_bridge import is_available
    return {"available": is_available()}

def local_ml_infer(prompt: str, **kwargs: Any) -> dict[str, Any]:
    llm = LocalLLM()
    return {"result": llm.complete(prompt, **kwargs)}

def local_ml_status(**kwargs: Any) -> dict[str, Any]:
    llm = LocalLLM()
    return {"available": llm.is_available, "model": llm.model}

def run_local_inference(operation: str = "complete", **kwargs: Any) -> dict[str, Any]:
    llm = LocalLLM()
    if operation == "complete":
        return {"result": llm.complete(**kwargs)}
    elif operation == "chat":
        return {"result": llm.chat(**kwargs)}
    elif operation == "status":
        return local_ml_status()
    return {"error": f"Unknown operation: {operation}"}

__all__ = [
    "bitnet_infer",
    "bitnet_status",
    "local_ml_infer",
    "local_ml_status",
    "run_local_inference",
]
