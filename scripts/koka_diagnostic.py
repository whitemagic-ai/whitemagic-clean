import logging

from whitemagic.core.acceleration.koka_bridge import get_koka_runtime

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger("koka_diag")

def test_koka():
    print("🔍 Testing Koka Bridge Transactions...")
    try:
        koka = get_koka_runtime()
        print("🚀 Starting Koka Runtime...")

        tx_id = koka.begin_transaction()
        print(f"✅ Begin Transaction OK: ID={tx_id}")

        if tx_id:
            success = koka.commit_transaction(tx_id)
            print(f"✅ Commit Transaction OK: {success}")
        else:
            print("❌ No Transaction ID returned")

    except Exception as e:
        print(f"❌ Koka Diagnostic Failed: {e}")
        import traceback
        traceback.print_exc()

if __name__ == "__main__":
    test_koka()
