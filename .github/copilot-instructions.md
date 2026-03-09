---
name: c-workspace
description: "Global workspace instructions for C projects in 42, with libft as reusable base and multi-project tracking rules."
---

# Workspace Instructions: C Projects (42)

## Scope
- Main language: C (no C++).
- Current primary project: `42/C/libft`.
- Workspace supports multiple projects under `42/C/`.
- `libft` is reusable across future projects and can evolve over time.

## Project Structure (Workspace)
```text
Raiz/
├── 42/
│   ├── C/
│   │   └── libft/
│   ├── PDFs/
│   └── testsLibf/
├── .github/
│   ├── libft-functions.md
│   ├── libft-progress.md
│   ├── libft-reference.md
│   ├── projects-index.md
│   ├── project-history.md
│   └── workflow-rules.md
└── .vscode/
```

## 42 Delivery Rule (Important)
- For each deliverable project, files required by the subject must remain at that project's root.
- Local config folders like `.github/` and `.vscode/` are workspace tooling, not deliverable content.

## Coding Standards
- Respect 42 Norminette.
- Compile with `-Wall -Wextra -Werror`.
- Manage memory safely (no leaks, no invalid frees).
- Avoid forbidden functions per project subject.

## Libft Official Counts (PDF v16.6)
- Part 1: 23 functions.
- Part 2: 11 functions.
- Bonus: 9 functions.
- Total with bonus: 43 functions.

## Operating Model

## Chat Activation Protocol
- If the first token of the user message is `Chat1`, force Chat 1 mode.
- If the first token of the user message is `Chat2`, force Chat 2 mode.
- Accept common forms: `Chat1`, `Chat 1`, `chat1` and `Chat2`, `Chat 2`,
  `chat2`.
- Keep the selected mode for the current request unless the user explicitly
  changes it.
- If no prefix is provided, infer the mode from task type.

### Chat 1 (Config and Workflow)
- VS Code setup and tooling.
- Workflow and project organization.
- Tracking strategy and documentation consistency.

### Chat 2 (C Implementation)
- Edit `*.c` and `*.h`.
- Refactor and debug C logic.
- Keep Norminette and memory safety.

## Automatic Tracking Rules
- If `42/C/libft` changes, update:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
- If a new project appears under `42/C/`, update:
  - `.github/projects-index.md`
  - `.github/project-history.md`
- If a new support directory appears under `42/` (outside `42/C/`), update:
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `.github/QUICK_REFERENCE.md`
- If a new `.txt` spec is received:
  - Save it in `42/PDFs/` using `YYYY-MM-DD_<topic>.txt`
  - Log it in `.github/project-history.md`
  - Apply any required updates to tracking files

## References
- Norminette: https://github.com/42School/norminette
- C Reference: https://en.cppreference.com/w/c
- Valgrind: https://valgrind.org/docs/manual/
