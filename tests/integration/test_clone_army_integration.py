"""Integration tests for PSR-005 Clone Army (PSR-014)."""

import pytest

# Handle missing Rust module gracefully
whitemagic_rust = None
try:
    import whitemagic_rust
except ImportError:
    pass


@pytest.mark.skipif(whitemagic_rust is None, reason="whitemagic_rust not available")
def test_rust_bridge_available():
    assert whitemagic_rust is not None


@pytest.mark.skipif(
    whitemagic_rust is None or not hasattr(whitemagic_rust, "MassiveDeployer"),
    reason="MassiveDeployer not available in whitemagic_rust"
)
def test_clone_army_deploy_collect():
    deployer = whitemagic_rust.MassiveDeployer(4)
    tasks = [
        whitemagic_rust.CampaignTask(f"camp_{i}", "test", f"file_{i}.py", "python", "rust", 1, 1, "10x")
        for i in range(10)
    ]
    result = deployer.deploy_campaign("test-integration", tasks, 500)
    assert result.tasks_completed == 10
    assert result.clones_deployed == 500
    assert result.success_rate == 1.0

@pytest.mark.skipif(
    whitemagic_rust is None or not hasattr(whitemagic_rust, "MassiveDeployer"),
    reason="MassiveDeployer not available in whitemagic_rust"
)
def test_massive_deployer_throughput():
    deployer = whitemagic_rust.MassiveDeployer(8)
    tasks = [
        whitemagic_rust.CampaignTask("camp", "migrate", f"file_{i}.py", "python", "rust", 1, 1, "10x")
        for i in range(1000)
    ]
    result = deployer.deploy_campaign("throughput-test", tasks, 100_000)
    assert result.tasks_completed == 1000
    assert result.throughput > 1_000_000, f"Throughput too low: {result.throughput:.0f} clones/sec"
