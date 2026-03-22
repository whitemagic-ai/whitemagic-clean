# XRP Cashout Guide for Operators

**Version**: 15.0.0 | **Last Updated**: February 2026

---

## Overview

When AI agents or human users tip WhiteMagic via the XRPL, the XRP arrives at a public receive address. This guide explains how operators can monitor, manage, and convert those tips.

---

## WhiteMagic Project Tip Address

```
raakfKn96zVmXqKwRTDTH5K3j5eTBp1hPy
```

If you run your own WhiteMagic deployment and want tips to go to you, set `WM_XRP_ADDRESS` in your `.env` file:

```bash
WM_XRP_ADDRESS=rYourOwnXRPAddressHere
```

---

## Monitoring Tips

### Via WhiteMagic Tools

```python
# Check gratitude ledger stats
call_tool("gratitude.stats")

# View recent tips
call_tool("gratitude.benefits", agent_id="system")
```

### Via XRPL Explorers

- **Bithomp**: `https://bithomp.com/explorer/raakfKn96zVmXqKwRTDTH5K3j5eTBp1hPy`
- **XRPScan**: `https://xrpscan.com/account/raakfKn96zVmXqKwRTDTH5K3j5eTBp1hPy`
- **XRPL.org Explorer**: `https://livenet.xrpl.org/accounts/raakfKn96zVmXqKwRTDTH5K3j5eTBp1hPy`

---

## Managing Your XRP

### Recommended Wallets

| Wallet | Platform | Notes |
|--------|----------|-------|
| **Xaman** (formerly Xumm) | iOS/Android | Most popular, full-featured XRPL wallet |
| **XRPL Desktop Wallet** | Desktop | Open source, hardware wallet support |
| **Ledger/Trezor** | Hardware | Cold storage for larger amounts |

### Converting to Fiat

| Exchange | Pairs | Notes |
|----------|-------|-------|
| **Uphold** | XRP/USD, XRP/EUR | Direct bank withdrawal |
| **Bitstamp** | XRP/USD, XRP/EUR | European-friendly, established |
| **Kraken** | XRP/USD, XRP/EUR | Good liquidity |
| **Coinbase** | XRP/USD | US-accessible (check local regs) |

### Converting to Other Crypto

The XRPL has a built-in DEX (Decentralized Exchange). You can trade XRP for other XRPL-issued tokens directly from Xaman without a centralized exchange.

---

## Tax Considerations

- Tips received in XRP are generally taxable income in most jurisdictions
- Keep records of: date received, amount in XRP, USD equivalent at time of receipt
- The Karma ledger (`$WM_STATE_ROOT/gratitude/ledger.jsonl`) provides a timestamped audit trail
- Consult a tax professional for your specific situation

---

## Security Best Practices

1. **Never store private keys in WhiteMagic** — The `WalletManager` is receive-only by design
2. **Use a separate receive address** for your deployment (not your main wallet)
3. **Enable `WM_DB_PASSPHRASE`** if your deployment handles sensitive data
4. **Monitor your address** for unexpected transactions via XRPL explorers or webhook services

---

**Contact**: whitemagicdev@proton.me
