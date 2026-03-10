# Workflow Rules (Chat1 and Chat2)

Purpose: keep updates consistent and automatic across projects.

## Dual Git Operation

- Delivery repo root: `42/C/`
- Workspace repo root: `Raiz/`
- Default commit target for project work: `42/C/`
- Workspace docs/tooling commits (`.github`, `.vscode`, `42/PDFs`, `42/testsLibf`): `Raiz/`

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
2. Add a line in `.github/project-history.md` with date and path.
3. Apply spec changes to related tracking docs.

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

## Naming Convention for Imported Specs

Use: `YYYY-MM-DD_<topic>.txt`
Example: `2026-03-08_primera_libft.txt`

## 30-Second Ops Checklist

1. Classify change: `project`, `support-dir`, `spec-txt`.
2. Update required tracking docs for that class only.
3. Validate docs routes:
	 - `rg -n "42/PDFs|42/C/libft" .github`
4. Confirm git root before commit:
	 - `git rev-parse --show-toplevel`
5. Add a dated block in `.github/project-history.md`.

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
