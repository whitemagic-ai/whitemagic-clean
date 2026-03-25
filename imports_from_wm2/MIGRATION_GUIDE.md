# WM2 Migration Guide

## Base Class Usage

### For Engines
```python
from wm2.core import BaseEngine

class MyEngine(BaseEngine):
    def __init__(self, name: str):
        super().__init__(name=name)
        # Your initialization
    
    def get_stats(self):
        return {
            **super().get_stats(),
            "custom_metric": self.custom_value,
        }
```

### For Managers
```python
from wm2.core import BaseManager

class MyManager(BaseManager):
    def __init__(self, name: str):
        super().__init__(name=name)
        self.initialized = False
    
    def initialize(self):
        # Your initialization logic
        self.initialized = True
```

### For Handlers
```python
from wm2.core import BaseHandler

class MyHandler(BaseHandler):
    def handle(self, request):
        # Your handling logic
        pass
```

## Serialization

Use unified serialization:
```python
from wm2.core import serialize, serialize_stats

# Automatic serialization
data = serialize(my_object)

# Stats serialization
stats = serialize_stats(my_component)
```

## Lifecycle Management

```python
from wm2.core import FileBackedLifecycle

class MyComponent(FileBackedLifecycle):
    def __init__(self, path):
        super().__init__(path)
        self._load()
    
    def _restore_from_dict(self, data):
        # Restore state from dict
        pass
    
    def _to_dict(self):
        # Convert state to dict
        return {"key": "value"}
```

## Top Priority Modules

1. scripts/deploy_grand_army.py
2. whitemagic/cli/cli_app.py
3. whitemagic/core/memory/sqlite_backend.py
4. whitemagic/core/fusions.py
5. scripts/deploy_shadow_clones.py
6. whitemagic/optimization/rust_accelerators.py
7. whitemagic/core/memory/constellations.py
8. scripts/grand_evolution_campaign.py
9. scripts/codebase_census.py
10. scripts/execute_grand_campaign.py
