# Campaign Doctrine Files

Campaign markdown files that drive the Grand Army deployment system.
Each `.md` file defines a campaign with YAML frontmatter, objectives,
no-compromise victory conditions, targets, and strategy.

## Format

```markdown
---
name: Campaign Name
codename: IL001
army: alpha|beta|gamma
type: security_scan|batch_transform|fix_and_verify|dedup|discovery|stress_test
priority: 1
clone_count: 10000
strategies: [adversarial, analytical, chain_of_thought]
category: security|infrastructure|intelligence|optimization
phase: immediate|foundation|infrastructure|intelligence
source: "Origin document or operation"
column_size: 50000
---

# Campaign Name

## Objective
What must be accomplished. No compromise.

## Victory Conditions
- [ ] Every condition MUST be met for victory
- [ ] No shortcuts, stubs, or incomplete work
- [ ] Thorough and complete — or it's not done

## Targets
| File | Line | Type |
|------|------|------|
| path/to/file.py | 42 | description |

## Strategy
1. Numbered steps for execution
2. Each step is actionable

## Verification
How to confirm complete, no-compromise victory.
```

## Naming Convention

- `IL###` — Iron Lotus follow-up campaigns (from Operation Iron Lotus intelligence)
- `F###` — Foundation campaigns (prerequisites for other work)
- `C##` — Campaigns from strategic planning docs
- `I###` — Intelligence/polish campaigns

## Priority Levels

- P1: Critical — execute immediately (Iron Lotus HIGH findings)
- P2: High — execute next (foundation work)
- P3: Medium — execute after foundation
- P4: Low — polish and optimization

## Army Assignment Guide

- **Alpha (10K)**: Consensus voting, classification, assessment. Best at 2.3 findings/1K clones.
- **Beta (50-100K)**: Map-reduce batch processing. Best for comprehensive scanning.
- **Gamma (100K+)**: Brute-force coverage. Use multi-column (50K each) for efficiency.

## Historical Note

The 50K-100K sweet spot mirrors ancient Chinese military doctrine from the
Spring and Autumn period (771-476 BC), where the "Three Armies" standard
of ~37,500-75,000 men represented the maximum a major state could effectively
command, supply, and coordinate on a single battlefield.
