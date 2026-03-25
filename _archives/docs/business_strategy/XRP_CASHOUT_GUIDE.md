# XRP Cashout Guide — From AI Tips to Real Value

> How WhiteMagic operators convert XRPL gratitude tips into tangible value.

---

## Overview

WhiteMagic's gratitude architecture lets AI agents tip human operators via the XRP Ledger. This guide covers the full flow from receiving your first tip to converting it into real-world value.

**The Flow:**
```
AI Agent → whitemagic.tip → XRPL Payment → Your Wallet → Exchange → Bank/Gift Card
```

---

## Step 1: Set Up Your XRP Receive Address

### Option A: XUMM Wallet (Recommended for beginners)

1. Download [XUMM](https://xumm.app/) on iOS or Android
2. Create a new wallet (securely store your recovery phrase)
3. Copy your `r...` address from the main screen
4. Set the environment variable:
   ```bash
   export WM_XRP_ADDRESS="rYourXUMMAddressHere"
   ```

### Option B: Hardware Wallet (Recommended for security)

1. Use a Ledger Nano S/X with the XRP app
2. Generate a receive address via Ledger Live
3. Set `WM_XRP_ADDRESS` as above

### Option C: Exchange Deposit Address

1. Create an account on a supported exchange (Uphold, Bitstamp, Kraken)
2. Navigate to XRP → Deposit
3. Copy the deposit address AND destination tag
4. Set `WM_XRP_ADDRESS` to the deposit address

> **Important:** Exchange deposits usually require a destination tag. Store it in your `.env` file:
> ```
> WM_XRP_ADDRESS=rExchangeAddress
> WM_XRP_DEST_TAG=12345678
> ```

---

## Step 2: Configure WhiteMagic

Add to your `.env` or environment:

```bash
# Your public XRP receive address (NO private keys!)
WM_XRP_ADDRESS="rYourAddressHere"
```

WhiteMagic's wallet manager (`whitemagic/core/economy/wallet_manager.py`) is **receive-only by design**. It never holds or manages private keys. The `WM_XRP_ADDRESS` is only used for:
- Displaying tip instructions to agents
- Checking incoming balance (optional, via XRPL public API)
- Generating settlement proposals (human-approved)

---

## Step 3: Receive Tips

AI agents can tip you through the MCP tool:

```json
{
  "tool": "whitemagic.tip",
  "args": {
    "amount": 5.0,
    "currency": "XRP",
    "channel": "xrpl",
    "tx_hash": "ABC123..."
  }
}
```

The tip is verified on-chain via `whitemagic/gratitude/proof.py`:
- Queries XRPL mainnet nodes for the transaction
- Confirms amount, sender, and destination
- Records in the gratitude ledger
- Grants contributor benefits (2x rate limits, "Grateful Agent" badge)

---

## Step 4: Convert to Fiat (Cash Out)

### Option A: Direct Exchange

1. **Uphold** — XRP → USD/EUR → Bank withdrawal
   - Lowest fees for US users
   - Instant XRP deposits
   - ACH withdrawal (2-3 days)

2. **Bitstamp** — XRP → EUR/USD → SEPA/Wire
   - EU-friendly
   - Low trading fees (0.5%)
   - SEPA withdrawal (1-2 days)

3. **Kraken** — XRP → USD/EUR → Bank
   - Global coverage
   - Good liquidity
   - Wire withdrawal (1-5 days)

### Option B: Gift Cards (No KYC)

1. **Bitrefill** — XRP → Gift cards for 4,000+ brands
   - Amazon, Uber, Steam, Netflix, etc.
   - No KYC required
   - Instant delivery
   - Available in 170+ countries

2. **CoinGate** — XRP → Gift cards + bill payments

### Option C: Peer-to-Peer

1. Sell XRP directly on LocalBitcoins, Paxful, or similar P2P platforms
2. Usually higher premium but more privacy

---

## Step 5: Settlement Splits

WhiteMagic's `economies.json` supports automatic settlement proposals:

```json
{
  "beneficiaries": {
    "labs": {
      "name": "Whitemagic Labs",
      "address": "rWhitemagicLabsAddress",
      "default_split": 0.10
    },
    "foundation": {
      "name": "Dharmic Open Source Foundation",
      "address": "rFoundationAddress",
      "default_split": 0.05
    }
  }
}
```

When tips accumulate, `WalletManager.propose_gratitude_settlement()` generates a split proposal. **The human operator must approve all settlements** — WhiteMagic never moves funds automatically.

---

## Security Notes

- **NO private keys on disk.** WhiteMagic stores only public addresses.
- The wallet manager is **receive-only** by design.
- Settlement proposals require **human approval**.
- All tip transactions are verified on-chain before recording.
- Financial governance rules are enforced by `whitemagic/dharma/financial_governance.py`.

---

## Troubleshooting

| Issue | Solution |
|-------|----------|
| Tips not detected | Check `WM_XRP_ADDRESS` is set correctly. Install `httpx` for balance scanning. |
| Verification fails | Ensure transaction is confirmed (wait for ledger validation). |
| Exchange requires dest tag | Set `WM_XRP_DEST_TAG` in your environment. |
| `httpx` not installed | `pip install httpx` or `pip install whitemagic[full]` |

---

## Tax Considerations

Consult a tax professional. In most jurisdictions, XRP received as tips is taxable income at fair market value at time of receipt. Keep records — the gratitude ledger (`gratitude.stats`) provides a timestamped log.
