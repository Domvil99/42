# Deferred Tasks

Purpose: central list for items explicitly postponed with the phrase
`guardalo para despues`.

## Priority Levels

- `no importante`: nice-to-have, no impact on current delivery.
- `importante`: relevant improvement, should be done in a near iteration.
- `super importante`: high-risk or blocking item for quality/delivery.

## Rule

When the user says `guardalo para despues`, add one entry to this file using
this template.

If a task is not `super importante`, keep it deferred and do not mention it in
normal responses. Mention deferred items only when the user explicitly asks for
the pending list.

## Entry Template

```md
## YYYY-MM-DD

- Task: short description
- Priority: no importante | importante | super importante
- Context: file/path/area affected
- Reason deferred: why it is postponed now
- Suggested next action: first concrete step
- Status: pending
```

## Backlog

## 2026-03-09

- Task: Make Norminette path in `QUICK_REFERENCE.md` portable
- Priority: no importante
- Context: `.github/QUICK_REFERENCE.md` (currently uses absolute `WORKSPACE_ROOT` path)
- Reason deferred: requested to leave for later
- Suggested next action: replace absolute path with relative repo-safe command
- Status: pending
