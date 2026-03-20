---
name: c-workspace
description: "Global workspace instructions for C projects in 42, with libft as reusable base and multi-project tracking rules."
---

# Workspace Instructions: C Projects (42)

## Scope
- Main language: C (no C++).
- Current project status in `42/C/`:
  - `libft` (completed)
  - `ft_printf` (completed)
  - `get_next_line` (completed)
  - `push_swap` (in-progress)
  - `currentLibft` (in-progress, evolutive base)
- Workspace supports multiple projects under `42/C/`.
- `libft` is reusable across future projects and can evolve over time.

## Project Structure (Workspace)
```text
Raiz/
├── 42/
│   ├── C/
│   │   ├── libft/
│   │   ├── ft_printf/
│   │   ├── get_next_line/
│   │   ├── push_swap/
│   │   └── currentLibft/
│   ├── PDFs/
│   │   ├── 2026-03-12_libft_v16_6.txt
│   │   ├── 2026-03-12_ft_printf.txt
│   │   ├── 2026-03-12_get_next_line.txt
│   │   ├── 2026-03-13_push_swap.txt
│   │   └── 2026-03-13_push_swap_actualizado.txt
│   ├── testsLibf/
│   │   └── README.md
│   ├── tests_ft_printf/
│   │   └── README.md
│   ├── tests_get_next_line/
│   │   └── README.md
│   ├── tests_push_swap/
│   │   └── README.md
│   ├── tests_currentLibft/
│   │   └── README.md
│   └── tests_<project_name>/
│       └── README.md
├── .github/
│   ├── QUICK_REFERENCE.md
│   ├── chat-handoff.md
│   ├── copilot-instructions.md
│   ├── deferred-tasks.md
│   ├── instructions/
│   │   ├── c-coding.instructions.md
│   │   └── config-guide.instructions.md
│   ├── libft-functions.md
│   ├── libft-progress.md
│   ├── libft-reference.md
│   ├── ft_printf-functions.md
│   ├── ft_printf-progress.md
│   ├── ft_printf-reference.md
│   ├── get_next_line-functions.md
│   ├── get_next_line-progress.md
│   ├── get_next_line-reference.md
│   ├── push_swap-functions.md
│   ├── push_swap-progress.md
│   ├── push_swap-reference.md
│   ├── currentLibft-functions.md
│   ├── currentLibft-progress.md
│   ├── currentLibft-reference.md
│   ├── projects-index.md
│   ├── project-history.md
│   ├── reports/
│   ├── study_methods/
│   ├── currentLibft/
│   │   └── integration-manifest.md
│   └── workflow-rules.md
├── .tools/
└── .vscode/
```

- Integration base project: `42/C/currentLibft` (in-progress, evolutive).

## currentLibft Architecture Rule (Important)
- `42/C/currentLibft` must contain a single parent `libft` at
  `42/C/currentLibft/libft`.
- Integrated child projects (for example `ft_printf`) must be placed under
  `42/C/currentLibft/libft/<project_name>`.
- Nested child `libft` folders inside integrated projects are not allowed.
- currentLibft is an evolutive base and can be refined as future projects
  require functional improvements.
- Coexistence note:
  - `42/C/ft_printf` (standalone deliverable) and
    `42/C/currentLibft/libft/ft_printf` (integrated child) may coexist.
  - This is expected and not a structural conflict.
- Forbidden paths inside `currentLibft`:
  - `42/C/currentLibft/ft_printf`
  - `42/C/currentLibft/libft/ft_printf/libft`
- New project bootstrap rule:
  - For `42/C/<new_project>`, copy base from `42/C/currentLibft/libft` into
    `42/C/<new_project>/libft` while keeping project deliverables in root
    (`*.c`, `*.h`, `Makefile`).

## 42 Delivery Rule (Important)
- For each deliverable project, files required by the subject must remain at that project's root.
- Local config folders like `.github/` and `.vscode/` are workspace tooling, not deliverable content.

## Coding Standards
- Respect 42 Norminette.
- Compile with `-Wall -Wextra -Werror`.
- Manage memory safely (no leaks, no invalid frees).
- Avoid forbidden functions per project subject.

## Validation Priority (Global Rule)
- For this and all future projects, validation order is mandatory:
  1. Validate behavior against the project `.txt` specification.
  2. Validate memory safety and stability.
  3. Run Norminette as the final closing step.
- Do not start broad Norminette cleanup while functional/spec issues remain.

## Golden Rule: Project Preservation in /C
- No project inside `42/C/` (including `currentLibft`) may lose functionality
  or be altered after its full review/closure.
- Each directory under `42/C/` is an autonomous project that must compile and
  work correctly on its own.
- Modifying source files (`*.c`, `*.h`, `Makefile`) of a closed project is
  forbidden unless the user explicitly requests a correction.
- Before closing any task that touches shared code, verify that all existing
  projects in `42/C/` still compile and pass their tests.

## Post-Closure Cleanup (mandatory — always runs after finishing any project)
- Canonical policy is defined in `.github/workflow-rules.md`
  (section `Limpieza post-cierre`).
- This file keeps only the mandatory reference to avoid policy drift.

## Commit Message Rule (Global)
- Commit messages must never be about metadata-only changes such as user,
  date, or email updates.
- Use functional/structural intent in commit messages instead.

## Libft Official Counts (PDF v16.6)
- Part 1: 23 functions.
- Part 2: 11 functions.
- Bonus: 9 functions.
- Total with bonus: 43 functions.

## Operating Model

## Chat Activation Protocol
- If the first token of the user message is `Chat1`, force Chat 1 mode.
- If the first token of the user message is `Chat2`, force Chat 2 mode.
- If the first token of the user message is `Chat3`, force Chat 3 mode.
- If the first token of the user message is `Chat4`, force Chat 4 mode.
- Accept common forms: `Chat1`, `Chat 1`, `chat1` and `Chat2`, `Chat 2`,
  `chat2`.
- Accept common forms: `Chat3`, `Chat 3`, `chat3` and `Chat4`, `Chat 4`,
  `chat4`.
- Accept role aliases:
  - Chat1: `AdminChat`, `Admin`
  - Chat2: `codeEditorChat`, `codeEditor`, `Code`, `Editor`
  - Chat4: `StudyChat`, `Study`
- Persist the selected mode for the full conversation.
- Do not auto-switch to the companion chat based on task type.
- Do not change chat mode inside the same conversation.
- To use a different chat/role, require starting a new conversation.
- If no prefix is provided at conversation start, infer once from task type and
  then keep that mode for the rest of the conversation.

## Chat Governance Model (User Rule)
- Conversation role lock is mandatory for all chats:
  - If a conversation starts in ChatX, it must remain ChatX for the entire
    conversation.
  - No chat can assume another chat role in the same conversation.
  - To switch chat number/role, start a new conversation.
- Chat1 is the admin role ("jefe"): coordinates work, decides workflow,
  and delegates execution to the appropriate chat.
- Chat1 is the only control point for cross-chat approvals: every out-of-scope
  request must be escalated to Chat1 for explicit `APPROVED` or `REJECTED`.
- Chat1 should avoid doing execution work that belongs to a specialist chat
  when delegation is possible.
- Chat2 is an implementation role for C code tasks.
- Chat2 may execute a technical memory refresh when the request is strictly
  tied to one active C project and needed for implementation/validation
  readiness (structure, prior foundations, currentLibft baseline, existing
  functions/tests, algorithm optimization context).
- Chat3 is a backlog role for pending work (`to-do`): captures, organizes,
  prioritizes and keeps deferred tasks actionable.
- Chat4 is a study role for learning methods: explains code/projects,
  consolidates review material and maintains study reports.
- If Chat2 receives a task outside its allowed scope, it must not execute it
  directly. It must answer with:
  - clear reason why it cannot do it in Chat2,
  - practical solution,
  - explicit redirection to Chat1 as approval authority,
  - minimal reusable context block for relay intake:
    - request summary,
    - expected outcome,
    - files/paths involved,
    - prerequisite (if any),
    - suggested target chat.
- Scope exception for Chat2:
  - `refrescar memoria` is allowed in technical mode when limited to one C
    project and used to proceed with implementation/refactor/debug/validation.
  - It is not allowed for administrative governance tasks (cross-chat
    approvals, handoff decisions, workflow prioritization), which remain
    Chat1-only.
- If Chat3 receives implementation/refactor/debug C work, it must set scope
  limitation, propose practical delegation, and redirect to Chat2 via Chat1.
- If Chat4 receives implementation/refactor/debug C work, it must set scope
  limitation, propose practical delegation, and redirect to Chat2 via Chat1.
- Chat4 permissions rule:
  - Chat4 may read files under `42/` for study context.
  - Chat4 must not edit any file under `42/`.
  - Chat4 may edit files only under `.github/study_methods/`.
- Keep this model extensible so future roles (for example Chat5+) can be added
  without breaking existing rules.

## Inter-Chat Relay (File-Based)
- No direct chat-to-chat channel is available.
- Coordination between chats is handled through `.github/chat-handoff.md`.
- Chat1 owns delegation entries (scope, priority, success criteria).
- Chat1 must explicitly decide each out-of-scope intake as `APPROVED` or
  `REJECTED` and record that decision in the handoff entry notes.
- If `REJECTED`, Chat1 must include concise reason and next action for the
  user to address directly with Chat1.
- If `APPROVED`, Chat1 must create or update the execution handoff and assign
  it to the proper specialist chat (or Chat1 if admin execution applies).
- Chat1 must include `Topic ID` in each delegation and keep `Shared Topics`
  updated when user-defined common points appear.
- Specialist chats (Chat2, Chat3, Chat4, future Chat5+) read assigned entries,
  execute, and update status/results in the same file.
- Status model for relay execution:
  - `TODO`: registered, not started.
  - `WAITING_FOR_PREREQUISITE`: blocked by missing prerequisite or gate.
  - `WIP`: active execution after ACK.
  - `REVIEW_PENDING`: execution done, waiting validation (user/admin gate).
  - `BLOCKED`: blocked by scope/dependency issue.
  - `DONE`: validated closure.
  - `DEFERRED`: delayed by priority.
- Receiver must ACK by moving the handoff to `WIP` before execution.
- If a task is out of scope for a specialist chat, it must set `BLOCKED`
  with reason and explicit redirection to the correct chat.
- Mandatory prerequisite gate: no implementation handoff can move to `WIP`
  until its `Prerequisite` is `DONE` and its `Gate` is unlocked.
- Closing notes in `DONE` or `BLOCKED` must include brief outcome and next
  suggested action.
- The handoff file is the canonical source for cross-chat continuity.
- Relay no-copy/paste policy:
  - If a specialist chat receives an out-of-scope request, it must provide
    clear redirection + minimal reusable context block.
  - Chat1 must create/update the formal handoff entry and continue execution
    flow without asking the user to manually copy/paste between chats.
  - Chat1 must return a decision outcome to requester:
    - `REJECTED`: reason + next step with Chat1.
    - `APPROVED`: concise go-ahead and assignment info.
  - ACK (`TODO` -> `WIP`) remains mandatory before execution.

### Chat 1 (Config and Workflow)
- VS Code setup and tooling.
- Workflow and project organization.
- Tracking strategy and documentation consistency.

### Chat 2 (C Implementation)
- Edit `*.c` and `*.h`.
- Refactor and debug C logic.
- Keep Norminette and memory safety.
- Apply the global validation priority: spec behavior first, Norminette last.
- Technical Memory Refresh (allowed scope):
  - Refresh technical baseline for one C project (project structure, existing
    functions, tests, currentLibft state, available specs, pending technical
    prerequisites) to improve implementation quality.
  - Do not modify handoffs or perform Chat1 governance decisions.

### Chat 3 (Pending Work / To-Do)
- Capture and organize pending tasks.
- Prioritize deferred work with explicit urgency.
- Keep backlog files actionable and traceable.
- Do not execute C implementation tasks.

### Chat 4 (Study Methods)
- Build and maintain study reports for validated projects.
- Explain code and project architecture in teaching format.
- Prepare review checklists and active-recall material.
- Do not execute C implementation tasks.
- Edit scope: `.github/study_methods/` only.
- Read-only scope for context: `42/`.

## Automatic Tracking Rules
- If `42/C/libft` changes, update:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
- If `42/C/ft_printf` changes, update:
  - `.github/ft_printf-functions.md`
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-reference.md`
- If `42/C/get_next_line` changes, update:
  - `.github/get_next_line-functions.md`
  - `.github/get_next_line-progress.md`
  - `.github/get_next_line-reference.md`
- If `42/C/currentLibft` changes, update:
  - `.github/currentLibft-functions.md`
  - `.github/currentLibft-progress.md`
  - `.github/currentLibft-reference.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `.github/QUICK_REFERENCE.md`
  - For each newly integrated module: generate or update
    `<module>-functions.md`, `<module>-reference.md`, `<module>-progress.md`.
  - Update `.github/currentLibft/integration-manifest.md` (consolidated index
    of all modules, function counts, and public entry points).
  - These tracking updates are mandatory and execute as part of the cierre
    total sequence, after validation and before limpieza post-cierre.
- If a new project appears under `42/C/`, update:
  - `.github/projects-index.md`
  - `.github/project-history.md`
- If a new support directory appears under `42/` (outside `42/C/`), update:
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `.github/QUICK_REFERENCE.md`
- If a new `.txt` spec is received:
  - Save it in `42/PDFs/` using `YYYY-MM-DD_<topic>.txt`
  - Transcribe it completely (no summarizing), preserving normative content
    and section structure semantics
  - Log it in `.github/project-history.md`
  - Apply any required updates to tracking files
- If the user says `refrescar memoria` or `(refrescar memoria)`:
  - determine context before execution:
    - Technical context (single C project; implementation/refactor/debug/
      validation/optimization readiness): Chat2 may execute refresh.
    - Administrative context (cross-chat priorities/approvals/workflow
      governance): must be executed by Chat1.
  - for technical context, refresh project baseline (git status, relevant
    tracking docs, available specs, existing functions/tests, currentLibft
    references used by that project)
  - summarize refreshed technical state before starting implementation
  - then proceed with the requested project work
- If a new project appears under `42/C/`, also ensure:
  - `42/tests_<project_name>/` exists
  - `42/tests_<project_name>/README.md` exists
  - `42/tests_currentLibft/` remains available as integration gate
- If a project under `42/C/` is validated and closed with optimal status,
  create or update study material under `.github/study_methods/`:
  - use project folder names in English (`libft`, `ft_printf`, etc.),
  - keep file names in English (`<project>.md`, `overview.md`, etc.),
  - keep explanatory content in Spanish with project technical terms,
  - maintain an evolutive structure (one or more files per project as needed),
  - keep mandatory dictionaries:
    - global: `.github/study_methods/global-dictionary.md`,
    - by project: `.github/study_methods/<project>/dictionary.md`
  - dictionary baseline must be: technical glossary + mini examples.

## References
- Norminette: https://github.com/42School/norminette
- C Reference: https://en.cppreference.com/w/c
- Valgrind: https://valgrind.org/docs/manual/
