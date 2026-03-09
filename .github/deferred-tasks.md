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

## 2026-03-09

- Task: Update canonical root path references after renaming directories in `empresa/42/newLibft/Raiz`
- Priority: super importante
- Context:
	- `.github/workflow-rules.md:14`
	- `.github/workflow-rules.md:15`
	- `.github/workflow-rules.md:20`
	- `.github/QUICK_REFERENCE.md:47`
	- `.github/QUICK_REFERENCE.md:49`
	- `.github/QUICK_REFERENCE.md:58`
	- `.github/QUICK_REFERENCE.md:141`
	- `.github/project-history.md:121`
	- `.github/project-history.md:123`
- Reason deferred: user will rename path later and requested to keep a precise checklist now
- Suggested next action: after renaming folders, replace Linux and WSL path strings in the files above and add a new dated note in `.github/project-history.md`
- Status: pending
