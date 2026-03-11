# Workflow Rules (Chat1 and Chat2)

Purpose: keep updates consistent and automatic across projects.

## Dual Git Operation

- Delivery repo root: `42/C/`
- Workspace repo root: `Raiz/`
- Default commit target for project work: `42/C/`
- Workspace docs/tooling commits (`.github`, `.vscode`, `42/PDFs`, `42/testsLibf`, `42/testsCurrentLibft`, `42/tests_<project_name>`): `Raiz/`

## Inter-Chat Handoff File

- Official relay file: `.github/chat-handoff.md`
- Chat1 registers delegations (owner chat, objective, scope, priority).
- Specialist chats update progress and final status in the same entry.
- Allowed status values: `TODO`, `WIP`, `BLOCKED`, `DONE`, `DEFERRED`.
- If out of scope, specialist chat must set `BLOCKED` and add redirection.

## Canonical Workspace Root Rule

- Default base path for all operations: `/home/domvil99/empresa/42/newLibft/Raiz`
- Windows/WSL equivalent reference: `\\wsl.localhost\Ubuntu\home\domvil99\empresa\42\newLibft\Raiz`
- Always normalize to the Linux path above before running commands.
- If a request includes another root, verify it first and only switch when the
	user explicitly confirms.
- Quick validation command:
	- `pwd && realpath /home/domvil99/empresa/42/newLibft/Raiz`

## Mandatory Update Trigger

When files in `42/C/libft` change (`*.c`, `*.h`, `Makefile`), update:

1. `.github/libft-functions.md`
2. `.github/libft-progress.md`
3. `.github/libft-reference.md`

When files in `42/C/ft_printf` change (`*.c`, `*.h`, `Makefile`), update:

1. `.github/ft_printf-functions.md`
2. `.github/ft_printf-progress.md`
3. `.github/ft_printf-reference.md`

Note (2026-03-11): ft_printf tracking is in closure state.
Future updates should be recorded in `.github/project-history.md` with a new
dated block before reopening detailed tracking files.

## Multi-Project Trigger

When a new project is added under `42/C/`, update:

1. `.github/projects-index.md`
2. `.github/project-history.md`

When a support directory is added under `42/` (outside `42/C/`), update:

1. `.github/projects-index.md`
2. `.github/project-history.md`
3. `.github/QUICK_REFERENCE.md`

## External Instruction Trigger

When a new `.txt` instruction is provided:

1. Save it under `42/PDFs/` with a clear name.
2. Transcribe the full content into workspace format without summarizing
	or dropping normative details.
3. Preserve section structure semantics (title, summary, index,
	chapters, requirements, bonus, delivery/evaluation).
4. Normalize encoding only when needed for legibility (do not alter
	functional meaning).
5. Add a line in `.github/project-history.md` with date and path.
6. Apply spec changes to related tracking docs.

## Deferred Task Trigger

When the user says `guardalo para despues`:

1. Add the deferred item to `.github/deferred-tasks.md`.
2. Set priority using one of:
	- `no importante`
	- `importante`
	- `super importante`
3. Add enough context so it can be resumed without ambiguity.
4. If the deferred item is not `super importante`, keep it for later and do
	not mention it unless the user explicitly asks for pending items.

## Memory Refresh Trigger

When the user says `refrescar memoria` or `(refrescar memoria)`:

1. Run a full context refresh before starting a new project:
	- current repo status (`Raiz/` and `42/C/`)
	- current project index/history state
	- current instruction/spec files available in `42/PDFs/`
	- active deferred tasks that could impact next work
2. Summarize the refreshed state in concise bullets (what is ready, what is
	pending, what is blocked).
3. Store a short session note with the refreshed baseline for the current
	conversation.
4. If new facts are confirmed, update repository memory with a short note.
5. Only after this refresh, continue with implementation steps.

## Naming Convention for Imported Specs

Use: `YYYY-MM-DD_<topic>.txt`
Example: `2026-03-08_primera_libft.txt`

## 30-Second Ops Checklist

1. Classify change: `project`, `support-dir`, `spec-txt`.
2. Update required tracking docs for that class only.
3. Validate docs routes:
	 - `rg -n "42/PDFs|42/C/libft|42/C/ft_printf" .github`
4. Confirm git root before commit:
	 - `git rev-parse --show-toplevel`
5. Add a dated block in `.github/project-history.md`.

## Review Priority (All Projects)

Mandatory order for any C deliverable project:

1. Validate deliverable structure/scope against the `.txt` subject
	(required files only, no out-of-scope extras in active project root).
2. Validate behavior against the project `.txt` specification.
3. Validate memory/stability (leaks and invalid accesses).
4. Run Norminette as the final closing step.

If functional validation is not green, do not start broad style-only cleanup.
If structure/scope is not green, stop and fix structure first.

## Norminette Automation Rule (VS Code)

- For single-file correction in C projects, prefer workspace automation:
	- Task: `Normi Autofix: Active File`
	- Shortcut: `Ctrl+Alt+Shift+N`, then `Ctrl+Alt+Shift+F`
- For quick diagnostics without header noise:
	- Task: `Normi Check: Active File (No Header)`
	- Shortcut: `Ctrl+Alt+Shift+N`, then `Ctrl+Alt+Shift+C`
- Validation policy remains:
	- Ignore only `INVALID_HEADER` temporarily.
	- Treat all other `Error:` lines as actionable.
- For full project scan in ft_printf:
    - Task: `Normi Check: ft_printf All (No Header)`
    - Shortcut: `Ctrl+Alt+Shift+N`, then `Ctrl+Alt+Shift+A`
	
## Project History Template

```md
## YYYY-MM-DD

- Change type: project | support-dir | spec-txt
- Paths changed:
	- `path/one`
	- `path/two`
- Tracking docs updated:
	- `.github/projects-index.md`
	- `.github/project-history.md`
	- `.github/QUICK_REFERENCE.md`
- Notes:
	- short summary
```
## Project Test Folder Trigger

When a new project is added under `42/C/<project_name>/`:

1. Ensure test folder exists: `42/tests_<project_name>/`
2. Ensure `42/tests_<project_name>/README.md` exists with run instructions
3. Keep `42/testsCurrentLibft/` as permanent integration gate
4. Update:
   - `.github/projects-index.md`
   - `.github/project-history.md`
   - `.github/QUICK_REFERENCE.md`