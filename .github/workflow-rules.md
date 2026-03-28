# Workflow Rules (Chat1, Chat2, Chat3 and Chat4)

Purpose: keep updates consistent and automatic across projects.

## Chat Role Lock (Global)

Conversation chat mode is immutable:

1. If a conversation starts as ChatX, it must stay ChatX until that
	conversation ends.
2. No chat can assume another chat role in the same conversation.
3. To switch to another chat role/number, start a new conversation.

Official aliases:

- Chat1 = `AdminChat` / `Admin`
- Chat2 = `codeEditorChat` / `codeEditor` / `Code` / `Editor`
- Chat4 = `StudyChat` / `Study`
- Chat3 = pending alias specification

## Dual Git Operation

- Delivery repo root: `42/C/`.
- Workspace repo root: `Raiz/`.
- Regla operativa:
	- cambios en codigo entregable (`42/C/<project>`): commitear en `42/C/`.
	- cambios de tracking/tooling (`.github`, `.vscode`, `42/PDFs`, `42/tests/tests_*`):
		commitear en `Raiz/`.
- Verificacion obligatoria antes de commit:
	- `git rev-parse --show-toplevel`.


## Protocolo de cierre de proyectos 42

### Cierre total (validación completa, cierre completo, etc.)
Activado por cualquier frase relacionada con cierre completo, validación total, cierre de oro, etc.
Secuencia obligatoria:
1. Validar funcionamiento según el .txt
2. Verificar memoria y estabilidad
3. Ejecutar Norminette
4. git add, commit, push
5. Actualizar todos los .md y README
6. Dejar evidencia de cierre en README y tracking
7. Ejecutar limpieza post-cierre (ver sección abajo) — siempre como paso final

### Cierre express (auditoría express)
Solo permitido tras cierre total exitoso y sin cambios funcionales
Revisión rápida, mínima batería
Actualizar README y tracking con nota de auditoría express

## Regla de oro: preservación de proyectos en /C

Ningún proyecto dentro de `42/C/` (incluyendo `currentLibft`) puede perder
su funcionamiento ni verse alterado por cambios posteriores a su revisión
completa. Cada directorio bajo `42/C/` es un proyecto autónomo que debe
compilar y funcionar correctamente por separado.

- Está prohibido modificar archivos fuente (`*.c`, `*.h`, `Makefile`) de un
  proyecto ya cerrado salvo corrección explícita solicitada por el usuario.
- Antes de cerrar cualquier tarea que toque código compartido, verificar que
  todos los proyectos existentes en `42/C/` siguen compilando y pasando sus
  pruebas.

## Limpieza post-cierre (obligatoria al finalizar un proyecto)

Al completar un cierre total de cualquier proyecto en `42/C/`:

1. Eliminar archivos temporales y binarios generados fuera del proyecto
   (ejecutables en `/tmp`, archivos `.o` huérfanos, etc.).
2. Ejecutar `make clean` o `make fclean` dentro del proyecto para dejar solo
   fuentes y Makefile.
3. Verificar que no quedan scripts o archivos de pruebas fuera de
   `42/tests/tests_<project_name>/`.
4. Confirmar `git status` limpio en ambos repositorios (`42/C/` y `Raiz/`).
5. Registrar la limpieza en `.github/project-history.md`.
6. Hacer `git add`, `commit` y `push` final para dejar todo versionado.

Esta rutina nunca debe eliminar ni modificar archivos fuente, Makefiles ni
configuraciones esenciales de ningún proyecto.

## Commit Message Policy (Active)

- Los mensajes de commit deben describir intencion funcional/estructural.
- Prohibido usar mensajes sobre cambios de metadatos (usuario, fecha, correo).
- Formato recomendado: `tipo(scope): accion concreta`.


## Inter-Chat Handoff File

- Official relay file: `.github/chat-handoff.md`
- Chat1 registers delegations (owner chat, objective, scope, priority).
- Specialist chats (`Chat2`, `Chat3`, `Chat4`) update progress and final
  status in the same entry.
- Allowed status values: `TODO`, `WAITING_FOR_PREREQUISITE`, `WIP`,
  `REVIEW_PENDING`, `BLOCKED`, `DONE`, `DEFERRED`.
- If out of scope, specialist chat must set `BLOCKED` and add redirection.
- All out-of-scope requests must be escalated to Chat1 for explicit
  `APPROVED` or `REJECTED` decision before any reassignment or execution.
- Every handoff must include a shared topic identifier (`Topic ID`) to keep
	traceability across related tasks.
- Receiver must ACK by moving entry to `WIP` with a short acceptance note
	before execution.
- No implementation handoff can move to `WIP` if prerequisite gate is pending.
- If a handoff requires user/admin validation, use `REVIEW_PENDING` until
  approval is explicitly recorded, then move to `DONE`.
- Scope by specialist chat:
	- `Chat2`: C implementation, refactor and debugging.
	- `Chat3`: pending work (`to-do`), prioritization and backlog hygiene.
	- `Chat4`: study methods, project explanations and review reports.
	  - edit allowed only in `.github/study/`
	  - read-only access allowed in `42/`
	  - edit forbidden in `42/`

## Continuous Communication Optimization (Chat1)

Chat1 applies this loop automatically in every conversation:

1. Detect shared user themes and register/update them in
	`.github/chat-handoff.md` under `Shared Topics`.
2. Detect out-of-scope intake from specialist chats, convert it into formal
	handoff intake, and decide `APPROVED` or `REJECTED`.
3. Normalize handoff entries to include `Topic`, scope, closure criteria,
	decision, prerequisite gate, and explicit next action.
4. Enforce prerequisite unlock + ACK before execution starts.
5. On completion, block, or rejection, record one-line outcome and lesson.
6. If a recurring friction appears, update workflow docs in the workspace repo
	to prevent repetition in future cycles.

Definition of optimal communication flow:

1. Shared theme is explicit (`Topic ID`).
2. Ownership is explicit (`From -> To`).
3. Decision is explicit (`APPROVED`/`REJECTED`).
4. Status transition is explicit (`TODO` -> `WAITING_FOR_PREREQUISITE` ->
	`WIP` -> `REVIEW_PENDING` -> `DONE/BLOCKED`).
5. Handoff note is actionable (what/where/how to close).
6. Closure leaves reusable context for next tasks.

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

1. `.github/tracking/projects/libft/libft-functions.md`
2. `.github/tracking/projects/libft/libft-progress.md`
3. `.github/tracking/projects/libft/libft-reference.md`

When files in `42/C/ft_printf` change (`*.c`, `*.h`, `Makefile`), update:

1. `.github/tracking/projects/ft_printf/ft_printf-functions.md`
2. `.github/tracking/projects/ft_printf/ft_printf-progress.md`
3. `.github/tracking/projects/ft_printf/ft_printf-reference.md`

When files in `42/C/get_next_line` change (`*.c`, `*.h`, `Makefile`), update:

1. `.github/tracking/projects/get_next_line/get_next_line-functions.md`
2. `.github/tracking/projects/get_next_line/get_next_line-progress.md`
3. `.github/tracking/projects/get_next_line/get_next_line-reference.md`

Note (2026-03-11): ft_printf tracking is in closure state.
Future updates should be recorded in `.github/project-history.md` with a new
dated block before reopening detailed tracking files.

When `42/C/currentLibft` is updated (new module integrated, functions added
or modified):

1. Generate or update `<module>-functions.md`, `<module>-reference.md` and
   `<module>-progress.md` for each newly integrated module.
2. Update `.github/tracking/projects/currentLibft/integration-manifest.md` with the consolidated
   index of all modules, function counts and public entry points.
3. Update `.github/projects-index.md` and `.github/project-history.md`.
4. These tracking updates are part of the cierre total sequence (after
   validation, Norminette, and git workflow) and must execute before the
   limpieza post-cierre.

## Multi-Project Trigger

When a new project is added under `42/C/`, update:

1. `.github/projects-index.md`
2. `.github/project-history.md`

When files in `42/C/currentLibft` change (`*.c`, `*.h`, `Makefile`), update:

1. `.github/projects-index.md`
2. `.github/project-history.md`
3. `.github/QUICK_REFERENCE.md`

Rule for `currentLibft` architecture:

1. Keep exactly one parent `libft` in `42/C/currentLibft/libft`.
2. Integrated child projects (example: `ft_printf`) must live under
	`42/C/currentLibft/libft/<project_name>`.
3. Do not allow nested child `libft` folders inside integrated projects.
4. Coexistence is valid and expected between:
	- standalone project: `42/C/ft_printf`
	- integrated copy: `42/C/currentLibft/libft/ft_printf`
	They serve different purposes and are not a duplication conflict.
5. Explicitly forbidden inside `currentLibft`:
	- `42/C/currentLibft/ft_printf`
	- `42/C/currentLibft/libft/ft_printf/libft`

Bootstrap rule for new projects using the base:

1. Create `42/C/<project_name>/` with project deliverables at root.
2. Copy base library from `42/C/currentLibft/libft` to
	`42/C/<project_name>/libft`.
3. Keep project root semantics intact (`*.c`, `*.h`, `Makefile` for project).
4. Do not move parent `libft` out of `currentLibft`; treat it as canonical base.

When a support directory is added under `42/` (outside `42/C/`), update:

1. `.github/projects-index.md`
2. `.github/project-history.md`
3. `.github/QUICK_REFERENCE.md`

When study structure changes under `.github/study/`, update:

1. `.github/project-history.md`
2. `.github/QUICK_REFERENCE.md`
3. `.github/study/overview.md` (si cambia estructura canonica)

Study structure rule:

1. Use English names for project folders (`libft`, `ft_printf`, etc.).
2. Use English file names (`<project>.md`, `overview.md`, etc.).
3. Keep explanatory content in Spanish with project technical terminology.
4. Treat study content as evolutive and update it on future revalidations.
5. Keep mandatory dictionaries:
	- global dictionary: `.github/study/global-dictionary.md`
	- project dictionary: `.github/study/<project>/dictionary.md`
6. Dictionary baseline format: technical glossary + mini examples.

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

1. Determine refresh scope before execution:
	- Technical variant (single C project for implementation/refactor/debug/
	  validation/optimization): Chat2 may execute.
	- Administrative variant (cross-chat approvals, handoffs, prioritization,
	  workflow governance): only Chat1 may execute.
2. For technical variant, refresh project baseline:
	- project structure and active scope
	- existing functions/tests and relevant specs in `42/PDFs/`
	- currentLibft references usable for the target project
	- git status relevant to that project scope
3. Summarize refreshed technical state in concise bullets.
4. Continue directly with technical implementation steps.
5. If scope is ambiguous or multi-project governance-related, escalate to Chat1.

## Technical Memory Refresh Variant (Chat2)

Definition:
- Technical refresh by Chat2 is allowed only to improve execution quality inside
	one active C project.
- It does not include governance decisions or inter-chat coordination.

Boundaries:
1. Allowed: technical baseline reconstruction, function/test/spec review,
	currentLibft reference checks, pre-validation context.
2. Not allowed: handoff approvals/rejections, cross-chat priority decisions,
	global workflow governance changes.
3. Safety rule: if in doubt, redirect to Chat1 with concise intake context.

## Definitive Closure Trigger

When the user says `haz el cierre definitivo`:

1. Execute full closure of the active project before any integration to libft.
2. Mandatory sequence:
	- scope/structure vs project `.txt`,
	- functional behavior,
	- memory/stability,
	- Norminette as final step.
3. Ensure project root is clean from temporary build artifacts (`*.o`, test binaries).
4. Update tracking to closure state:
	- `.github/projects-index.md` (project status to `completed` when applicable),
	- `.github/project-history.md` (dated closure block with evidence summary),
	- `42/tests/tests_<project_name>/README.md` (closure evidence/status).
5. Only after closure is explicitly complete, proceed to optional integration into
	`42/C/currentLibft/libft`.

## Naming Convention for Imported Specs

Use: `YYYY-MM-DD_<topic>.txt`
Example: `2026-03-12_libft_v16_6.txt`

## 30-Second Ops Checklist

1. Classify change: `project`, `support-dir`, `spec-txt`.
2. Update required tracking docs for that class only.
3. Validate docs routes:
	 - `rg -n "42/PDFs|42/C/libft|42/C/ft_printf" .github`
4. Confirm git root before commit:
	 - `git rev-parse --show-toplevel`
5. Validate commit message policy before commit:
	 - no references to user/date/email metadata changes
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
	- Task: `Normi Check: Active File`
	- Shortcut: `Ctrl+Alt+Shift+N`, then `Ctrl+Alt+Shift+C`
- Validation policy remains:
	- Do not ignore `INVALID_HEADER`.
	- Treat all `Error:` lines as actionable.
- For full project scan in ft_printf:
    - Task: `Normi Check: ft_printf All`
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

1. Ensure test folder exists: `42/tests/tests_<project_name>/`
2. Ensure `42/tests/tests_<project_name>/README.md` exists with run instructions
3. Keep `42/tests/tests_currentLibft/` as permanent integration gate
4. Update:
   - `.github/projects-index.md`
   - `.github/project-history.md`
   - `.github/QUICK_REFERENCE.md`

## End-of-Block Pending Snapshot Rule

- Before moving to the next topic/project, create or update a pending-status
	file for the current block under `.github/reports/`.
- The snapshot must include pending state split by repository:
	- delivery repo (`42/C/`)
	- workspace repo (`Raiz/`)
- Remove completed items from that file on every update; keep only real
	outstanding work.

## Inter-Chat Essential Report Rule

- Maintain `.github/reports/inter-chat-essential.md` as canonical operational
	report for communication quality between chats.
- Chat1 updates this report proactively when:
	1. a coordination friction appears,
	2. a repeated friction is detected,
	3. a communication improvement is validated,
	4. Chat2 (or future chats) requests a communication/process adjustment.
- Every logged item should reference `Topic ID` and/or `H-xxx` when available.
- Keep only actionable open items in the active improvement table.

## Out-of-Scope Relay Rule (No Copy/Paste)

When a specialist chat receives an out-of-scope request:

1. The specialist chat must return:
	- concrete scope limitation reason,
	- practical solution,
	- explicit redirection to the correct chat,
	- minimal reusable context block.
2. Chat1 must convert that context into a formal handoff entry in
	`.github/chat-handoff.md` with `Topic ID`, success criteria, files and next
	action.
3. User should not be required to manually copy/paste context between chats.
4. ACK flow remains mandatory (`TODO` -> `WIP`) before execution.
5. Closure must be recorded as `DONE`/`BLOCKED` with short outcome and next
	suggested action.

## Chat2 Validation Intake Rule

When Chat2 (or a future specialist chat) reports validations, Chat1 must
ingest results using this canonical minimal block inside the active handoff
note and, if relevant, in `.github/reports/inter-chat-essential.md`:

1. Scope: project/path validated.
2. Command: exact command/task used.
3. Key output: only decisive lines (error summary or success gate).
4. Decision: `accept`, `needs follow-up`, or `ignore-noise`.

Noise filter policy:

1. Ignore duplicated non-actionable logs already covered by a prior decision.
2. Ignore outputs without scope/command traceability.
3. Escalate only actionable deltas that change project status or next action.