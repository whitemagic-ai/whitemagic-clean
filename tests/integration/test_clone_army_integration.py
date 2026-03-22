"""Integration tests for PSR-005 Clone Army (PSR-014)."""

import pytest

def test_rust_bridge_available():
    import whitemagic_rust
    assert whitemagic_rust is not None

@pytest.mark.skipif(not hasattr(__import__("whitemagic_rust"), "MassiveDeployer"), reason="MassiveDeployer not available in whitemagic_rust")
def test_clone_army_deploy_collect():
    import whitemagic_rust
    deployer = whitemagic_rust.MassiveDeployer(4)
    tasks = [
        whitemagic_rust.CampaignTask(f"camp_{i}", "test", f"file_{i}.py", "python", "rust", 1, 1, "10x")
        for i in range(10)
    ]
    result = deployer.deploy_campaign("test-integration", tasks, 500)
    assert result.tasks_completed == 10
    assert result.clones_deployed == 500
    assert result.success_rate == 1.0

@pytest.mark.skipif(not hasattr(__import__("whitemagic_rust"), "MassiveDeployer"), reason="MassiveDeployer not available in whitemagic_rust")
def test_massive_deployer_throughput():
    import whitemagic_rust
    deployer = whitemagic_rust.MassiveDeployer(8)
    tasks = [
        whitemagic_rust.CampaignTask("camp", "migrate", f"file_{i}.py", "python", "rust", 1, 1, "10x")
        for i in range(1000)
    ]
    result = deployer.deploy_campaign("throughput-test", tasks, 100_000)
    assert result.tasks_completed == 1000
    assert result.throughput > 1_000_000, f"Throughput too low: {result.throughput:.0f} clones/sec"
