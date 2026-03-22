import os
import sys
from unittest.mock import MagicMock

# Mocking modules to avoid full system dependency during test
sys.modules['whitemagic_rs'] = MagicMock()

def test_ssrf_protection():
    os.environ["WM_ALLOW_LOCAL_BRAIN"] = "false"
    from whitemagic.brain import validate_url
    assert validate_url("https://google.com")
    assert not validate_url("http://127.0.0.1:8000")
    assert not validate_url("http://localhost:11434")
    print("✅ SSRF validate_url passed")

def test_wisdom_url_protection():
    from whitemagic.intelligence.wisdom.auto_ingester import validate_wisdom_url
    assert validate_wisdom_url("https://sacred-texts.com/tao/taote.htm")
    assert not validate_wisdom_url("https://malicious.com/ssrf")
    print("✅ Wisdom URL protection passed")

if __name__ == "__main__":
    test_ssrf_protection()
    test_wisdom_url_protection()
    print("\n✨ WAVE 4 VERIFICATIONS PASSED ✨")
