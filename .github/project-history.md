# Project History

Purpose: chronological log of important decisions, imports, and structure changes.

## Global Active Rules

  1. structure/scope against `.txt`,
  2. behavior against `.txt`,
  3. memory/stability,
  4. Norminette as final closing step.
  but are superseded by this active rule.

## 2026-03-12

- Change type: workflow
- Paths changed:
  - `.github/copilot-instructions.md`
  - `.github/chat-handoff.md`
  - `.github/workflow-rules.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/metodos_de_estudio/overview.md`
  - `.github/metodos_de_estudio/libft/libft.md`
  - `.github/metodos_de_estudio/ft_printf/ft_printf.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/QUICK_REFERENCE.md`
- Notes:
  - Chat governance expanded with explicit roles for Chat3 and Chat4.
  - Chat activation now supports `Chat3`/`Chat 3`/`chat3` and
    `Chat4`/`Chat 4`/`chat4`.
  - Inter-chat relay standardized for Chat2, Chat3 and Chat4 with
    explicit delegation routes from Chat1.
  - New study structure initialized at `.github/metodos_de_estudio/` with:
    - project folders in English (`libft`, `ft_printf`),
    - file names in English (`overview.md`, `<project>.md`),
    - explanatory content in Spanish with technical terminology.
  - Initial complete study reports created for validated projects:
    `libft` and `ft_printf`.

- Change type: spec-txt
- Paths changed:
  - `42/PDFs/2026-03-12_ft_printf_actualizado.txt`
  - `.github/project-history.md`
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-reference.md`
  - `.github/ft_printf-functions.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-reference.md`
  - `.github/ft_printf-functions.md`
- Notes:
  - New corrected ft_printf baseline received and saved at
    `42/PDFs/2026-03-12_ft_printf_actualizado.txt`.
  - Full validation executed for `42/C/ft_printf` against updated baseline:
    - `make fclean && make && make bonus` OK,
    - mandatory matrix in `42/tests_ft_printf`: `RET_TOTAL=212` (parity with `printf`),
    - bonus matrix in `42/tests_ft_printf`: `RET_TOTAL=146` (parity with `printf`),
    - ASAN/UBSAN run (`-fsanitize=address,undefined`) on both matrices: no runtime/leak reports,
    - final `norminette 42/C/ft_printf/*.c 42/C/ft_printf/*.h` OK.
  - libft parity audit executed between `42/C/libft` and `42/C/ft_printf/libft` headers:
    diff detected only in metadata `Updated` lines of `libft.h` and `libft_bonus.h`
    (no API/prototype/content drift).

- Change type: validation-report
- Paths changed:
  - `.github/project-history.md`
  - `.github/libft-progress.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/libft-progress.md`
- Notes:
  - Validacion integral de `libft1` ejecutada sobre `42/C/libft` usando
    baseline canonica `42/PDFs/2026-03-12_libft_v16_6_actualizado.txt`.
  - Criterio aplicado: cierre estricto sin ignorar errores (incluye
    `INVALID_HEADER`).
  - Resultado global: GO (sin hallazgos criticos, altos, medios ni bajos).
  - Evidencias tecnicas:
    - repos `Raiz/` y `42/C/` limpios al iniciar validacion,
    - build obligatorio y bonus OK,
    - `make bonus` idempotente (sin relink),
    - `make run` en `42/testsLibf` OK,
    - ASAN/UBSAN en `42/testsLibf` OK,
    - barrido final `norminette` en `42/C/libft/*.c` y
      `42/C/libft/*.h` OK.
  - No se aplicaron cambios en codigo fuente de `42/C/libft`; el reporte
    persiste estado de validacion y trazabilidad de cierre.

- Change type: header-fix
- Paths changed:
  - `42/C/libft/libft.h`
  - `42/C/libft/libft_bonus.h`
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/project-history.md`
- Notes:
  - Final header adjustment in libft1 aligned with strict separation rule.
  - `libft.h` keeps mandatory + part2 only.
  - `libft_bonus.h` keeps bonus declarations (`t_list` + `ft_lst*`).
  - Full validation rerun after adjustment:
    - `make fclean && make && make bonus` ✅
    - `make run` in `42/testsLibf` ✅
    - ASAN/UBSAN tests in `42/testsLibf` ✅
    - final `norminette 42/C/libft/*.c 42/C/libft/*.h` ✅
  - Session closure prepared with clean environment and dual-repo commits.

- Change type: header-fix
- Paths changed:
  - `42/C/libft/libft.h`
  - `42/C/libft/libft_bonus.h`
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/project-history.md`
- Notes:
  - Header correction executed in libft1 according to corrected v16.6 spec.
  - `t_list` and `ft_lst*` declarations moved to `libft.h`.
  - `libft_bonus.h` kept as compatibility wrapper including `libft.h`.
  - Validation executed after change:
    - `make fclean && make && make bonus` in `42/C/libft` ✅
    - `make run` in `42/testsLibf` ✅
    - final `norminette 42/C/libft/*.c 42/C/libft/*.h` ✅
  - Base ready to propagate same header fix to libft2 and current.

- Change type: spec-txt
- Paths changed:
  - `42/PDFs/2026-03-12_libft_v16_6_actualizado.txt`
  - `.github/project-history.md`
  - `.github/libft-progress.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/libft-progress.md`
- Notes:
  - New corrected Libft v16.6 baseline received and saved at
    `42/PDFs/2026-03-12_libft_v16_6_actualizado.txt`.
  - Diff against old baseline `42/PDFs/2026-03-08_primera_libft.txt`
    confirmed missing normative points in old conversion.
  - Relevant normative deltas identified:
    - explicit prohibition of `restrict` in custom prototypes,
    - explicit prohibition of compiling with `-std=c99`,
    - explicit calloc behavior note for `nmemb == 0 || size == 0`,
    - explicit rule that bonus is evaluated only if mandatory part is perfect.
  - Full revalidation executed for `42/C/libft` against corrected spec:
    - `make fclean && make && make bonus` ✅
    - full tests run in `42/testsLibf` (`make run`) ✅
    - ASAN/UBSAN tests run (`-fsanitize=address,undefined`) ✅
    - `norminette 42/C/libft/*.c 42/C/libft/*.h` ✅
  - Critical anomaly detected:
    - spec indicates list structure declaration in `libft.h` for bonus,
      but current implementation keeps bonus API in `libft_bonus.h`.
  - Propagation risk confirmed:
    - same header split pattern exists in `42/C/ft_printf/libft` and
      `42/C/currentLibft/libft`.

## get_next_line
Último cierre total: 12 de marzo de 2026
Validación funcional, memoria y Norminette completadas
Protocolo de cierre total aplicado
Evidencia registrada en README de tests
Integrado en currentLibft/libft/get_next_line: 12 de marzo de 2026
- Compilación mandatory y bonus OK
- Pruebas funcionales (BUFFER_SIZE=1,42,9999) + bonus multi-fd OK
- ASAN/UBSAN sin errores
- Norminette 6/6 archivos OK
- Resto de currentLibft (libft + ft_printf) sin regresiones

## Protocolo de cierre
Cierre total: validación completa, cierre de oro, cierre completo, etc.
Cierre express: auditoría express, revisión rápida

## 2026-03-12

  - `42/C/get_next_line/get_next_line.c`
  - `42/C/get_next_line/get_next_line.h`
  - `42/C/get_next_line/get_next_line_utils.c`
  - `42/C/get_next_line/get_next_line_bonus.c`
  - `42/C/get_next_line/get_next_line_bonus.h`
  - `42/C/get_next_line/get_next_line_utils_bonus.c`
  - `42/tests_get_next_line/README.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `42/tests_get_next_line/README.md`
  - Definitive closure completed for `42/C/get_next_line` before libft integration.
  - Scope/structure validated against `42/PDFs/2026-03-12_get_next_line.txt`.
  - Mandatory and bonus compile clean with `-Wall -Wextra -Werror`.
  - Norminette final scan on all `*.c` and `*.h`: OK.
  - Functional checks completed:
    - mandatory with BUFFER_SIZE=1, 42, 9999,
    - bonus multi-fd alternating reads with BUFFER_SIZE=42 and 1.
  - Memory/stability checks with `-fsanitize=address,undefined`: no runtime issues observed.
  - Naming collision rule applied in codebase for helper functions: `ft_` prefix.
  - Integration to `42/C/currentLibft/libft` remains as a separate next step.

- Change type: spec-txt
- Paths changed:
  - `42/PDFs/2026-03-12_get_next_line.txt`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
- Notes:
  - Full transcription imported from provided source text for Get Next Line.
  - Transcription policy applied: no summary and no normative detail omission.
  - Source text replaced by user with corrected version; current file content is the active baseline.
  - Updated baseline includes the revised chapter structure:
    III Parte obligatoria, IV Parte bonus, V Entrega y evaluación.
  - Canonical spec path for next validation cycle:
    `42/PDFs/2026-03-12_get_next_line.txt`.

- Change type: project
- Paths changed:
  - `42/C/get_next_line`
  - `42/tests_get_next_line/README.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/project-history.md`
- Notes:
  - New deliverable project detected at `42/C/get_next_line`.
  - Validation and closure sequence pending: scope/spec -> behavior -> memory -> Norminette.
  - Integration into canonical libft (`42/C/currentLibft/libft`) remains deferred until standalone closure is complete.

- Change type: project
- Paths changed:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/project-history.md`
- Notes:
  - currentLibft base promoted to official canonical libft for future projects.
  - Canonical path for bootstrap and continuity: `42/C/currentLibft/libft`.
  - `42/C/libft` preserved as historical reference and closure traceability.
  - Future modular growth rule confirmed for canonical libft:
    integrate `ft_printf`, `get_next_line`, and following approved modules
    inside the same evolutive base.

## 2026-03-11

- Change type: project
- Paths changed:
  - `42/C/currentLibft/Makefile`
  - `42/C/currentLibft/libft/ft_printf/Makefile`
  - `42/C/currentLibft/libft/ft_printf/ft_printf.h`
  - `42/C/currentLibft/libft/ft_printf/ft_printf_bonus.h`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `.github/copilot-instructions.md`
- Notes:
  - Start implementation of currentLibft sync for direct ft_printf equivalents.
  - Human-like timestamp policy enforced for edited new-integration Makefiles
    (non-exact seconds, no `:00` pattern).
  - Legacy-equivalent headers synchronized with ft_printf root metadata for
    `Created`/`Updated` where applicable.
  - Commit message policy activated: no commit message may be about username,
    date, or email metadata changes.
  - Mirror Makefile normalization completed in:
    - `42/C/libft/Makefile`
    - `42/C/ft_printf/libft/Makefile`
    - `42/C/currentLibft/libft/Makefile`
    using consistent 42 header and human timestamps for this edit block.
  - Architecture clarification validated:
    - `currentLibft` keeps only one first-level child `libft`.
    - Integrated child path is `42/C/currentLibft/libft/ft_printf`.
    - Standalone `42/C/ft_printf` is allowed to coexist and is not a
      structural conflict.
    - Forbidden inside `currentLibft`: `currentLibft/ft_printf` and
      `currentLibft/libft/ft_printf/libft`.
  - New project bootstrap standardized:
    - copy base from `42/C/currentLibft/libft` to
      `42/C/<new_project>/libft`.
    - keep deliverable files of `<new_project>` in project root.
  - Inter-chat communication protocol hardened and synchronized in docs:
    - `Topic ID` is now mandatory in each handoff entry.
    - `Shared Topics` table tracks user-defined common points across tasks.
    - Receiver ACK (`WIP` + acceptance note) is mandatory before execution.
    - Closure notes must include brief outcome and next suggested action.
    - Synced docs:
      - `.github/chat-handoff.md`
      - `.github/workflow-rules.md`
      - `.github/QUICK_REFERENCE.md`
      - `.github/copilot-instructions.md`
      - `.github/instructions/config-guide.instructions.md`
      - `.github/instructions/c-coding.instructions.md`
  - Inter-chat essential reporting activated:
    - new canonical communication report:
      - `.github/reports/inter-chat-essential.md`
    - workflow and quick reference linked to this report for continuous
      improvement cycles and specialist-chat requests.

## 2026-03-08

- Created base tracking docs:
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
- Reorganized workspace structure:
  - moved `libft` to `C/libft`
  - created `42/PDFs`
- Saved official reference text as:
  - `42/PDFs/2026-03-08_primera_libft.txt`
- Corrected official function counts from the PDF:
  - Part 1: 23
  - Part 2: 11
  - Bonus: 9
  - Total: 43
- Standardized workspace automation rules:
  - updated `.github/copilot-instructions.md`
  - updated `.github/instructions/config-guide.instructions.md`
  - updated `.github/instructions/c-coding.instructions.md`
  - added global tracking for multi-project growth
- Renamed and reorganized directories:
  - root workspace directory kept as `Raiz/`
  - `C/` renamed to `42/`
  - `projects/` renamed to `C/`
  - `libft` moved to `42/C/libft`
  - imported specs path set to `42/PDFs/`

## 2026-03-09

- Adopted dual repository model:
  - delivery repo root: `42/C/`
  - workspace repo root: `Raiz/`
- Initialized git in `42/C/` for deliverable projects (default commit/push flow).
- Initialized git in `Raiz/` for tracking/docs/tooling.
- Added workspace `.gitignore` to keep repo separation:
  - ignore `42/C/` from `Raiz` repo
  - ignore local venv caches under `.tools/`
- Updated docs to reflect dual git operation:
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/projects-index.md`

- Added deferred task backlog and trigger rule:
  - created `.github/deferred-tasks.md`
  - added rule for phrase `guardalo para despues` in:
    - `.github/workflow-rules.md`
    - `.github/instructions/config-guide.instructions.md`
  - corrected Norminette tip to reference `$NORMI` in:
    - `.github/QUICK_REFERENCE.md`

- Updated deferred task policy:
  - if item is not `super importante`, keep it deferred and do not mention it
    unless the user explicitly asks for the pending list.

- Added tests support directory:
  - `42/testsLibf/` (manual test programs for libft)
- Route consistency review completed after structure changes under `42/`.
- Updated tracking docs to match current paths:
  - `.github/projects-index.md`
  - `.github/libft-progress.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/instructions/config-guide.instructions.md`
- Added fast tracking operations docs:
  - added `Tracking 30s Checklist` and copy/paste template in
    `.github/QUICK_REFERENCE.md`
  - added `30-Second Ops Checklist` and history template in
    `.github/workflow-rules.md`
  - linked checklist usage from
    `.github/instructions/config-guide.instructions.md`

- Full review and implementation update for `42/C/libft`:
  - cleaned duplicated or malformed commented test blocks in:
    - `42/C/libft/ft_strtrim.c`
    - `42/C/libft/ft_calloc.c`
    - `42/C/libft/ft_striteri.c`
    - `42/C/libft/ft_split.c`
    - `42/C/libft/ft_itoa.c`
    - `42/C/libft/ft_substr.c`
    - `42/C/libft/ft_strjoin.c`
  - implemented all bonus list functions:
    - `42/C/libft/ft_lstnew_bonus.c`
    - `42/C/libft/ft_lstadd_front_bonus.c`
    - `42/C/libft/ft_lstsize_bonus.c`
    - `42/C/libft/ft_lstlast_bonus.c`
    - `42/C/libft/ft_lstadd_back_bonus.c`
    - `42/C/libft/ft_lstdelone_bonus.c`
    - `42/C/libft/ft_lstclear_bonus.c`
    - `42/C/libft/ft_lstiter_bonus.c`
    - `42/C/libft/ft_lstmap_bonus.c`
  - updated `42/C/libft/Makefile` adding `bonus` rule and bonus objects.
  - updated bonus declarations in:
    - `42/C/libft/libft.h`
    - `42/C/libft/libft_bonus.h`
  - verified build with:
    - `make clean && make && make bonus`

- Follow-up cleanup pass on `42/C/libft`:
  - normalized duplicate commented test mains in:
    - `42/C/libft/ft_atoi.c`
    - `42/C/libft/ft_putchar_fd.c`
    - `42/C/libft/ft_putendl_fd.c`
    - `42/C/libft/ft_putnbr_fd.c`
    - `42/C/libft/ft_putstr_fd.c`
    - `42/C/libft/ft_strdup.c`
    - `42/C/libft/ft_strlcat.c`
    - `42/C/libft/ft_strlcpy.c`
    - `42/C/libft/ft_strnstr.c`
    - `42/C/libft/ft_strrchr.c`
    - `42/C/libft/ft_toupper.c`
  - kept one commented `main` per `ft_*.c` file.
  - re-verified `make` and `make bonus`.

- Added canonical workspace root rule to prevent path conflicts:
  - validated Linux root path:
    - `/home/domvil99/empresa/42/newLibft/Raiz`
  - documented Windows/WSL equivalent:
    - `\\wsl.localhost\Ubuntu\home\domvil99\empresa\42\newLibft\Raiz`
  - updated:
    - `.github/workflow-rules.md`
    - `.github/QUICK_REFERENCE.md`

- Added deferred super-important checklist for future directory rename affecting
  canonical path segment `empresa/42/newLibft/Raiz`:
  - recorded exact file/line targets in:
    - `.github/deferred-tasks.md`

- Final estilo/validación pass en `42/C/libft` (sin tocar política de header):
  - corregidos errores no-header de Norminette en archivos núcleo,
    incluyendo `ft_atoi.c`, `ft_itoa.c`, `ft_memchr.c`, `ft_memcmp.c`,
    `ft_memcpy.c`, `ft_memmove.c`, `ft_memset.c`, `ft_putendl_fd.c`,
    `ft_putnbr_fd.c`, `ft_putstr_fd.c`, `ft_split.c`, `ft_striteri.c`,
    `ft_strrchr.c`, `ft_strtrim.c`, `ft_toupper.c` y `libft.h`.
  - revalidado flujo solicitado por el usuario en ese momento
    (registro historico, hoy supersedido por regla global functional-first):
    - paso 2: `norminette` con foco en errores no-header
    - paso 1: `make clean && make && make bonus` ✅

- Revalidación posterior a cambios recientes en `42/C/libft`:
  - revisados archivos modificados:
    - `42/C/libft/ft_memcpy.c`
    - `42/C/libft/ft_lstdelone_bonus.c`
    - `42/C/libft/ft_lstmap_bonus.c`
  - resultado de control de calidad:
    - `norminette` sin errores adicionales fuera de `INVALID_HEADER`
    - `make clean && make && make bonus` ✅

- Auditoría completa de cumplimiento contra la especificación:
  - referencia usada:
    - `42/PDFs/2026-03-08_primera_libft.txt`
  - verificaciones ejecutadas en `42/C/libft`:
    - `make fclean && make && make bonus` ✅
    - `norminette *.c *.h` revisado con exclusión temporal de
      `INVALID_HEADER` por decisión del usuario
    - control de `main` por archivo: 43/43 archivos `*.c` con una sola
      ocurrencia de `int main(void)`
  - resultado:
    - librería funcional y compilable conforme al flujo pedido,
      pendiente únicamente de cabeceras Norminette por política temporal.

- Hardening de cumplimiento en `Makefile` y headers de `libft`:
  - archivos actualizados:
    - `42/C/libft/.gitignore`
    - `42/C/libft/Makefile`
    - `42/C/libft/libft.h`
    - `42/C/libft/libft_bonus.h`
    - `42/C/libft/ft_lstnew_bonus.c`
    - `42/C/libft/ft_lstadd_front_bonus.c`
    - `42/C/libft/ft_lstsize_bonus.c`
    - `42/C/libft/ft_lstlast_bonus.c`
    - `42/C/libft/ft_lstadd_back_bonus.c`
    - `42/C/libft/ft_lstdelone_bonus.c`
    - `42/C/libft/ft_lstclear_bonus.c`
    - `42/C/libft/ft_lstiter_bonus.c`
    - `42/C/libft/ft_lstmap_bonus.c`
  - cambios clave:
    - separación de API bonus desde `libft.h` hacia `libft_bonus.h`.
    - `*_bonus.c` usando `#include "libft_bonus.h"`.
    - regla `bonus` con marcador `.bonus` para evitar relink innecesario.
  - verificación final:
    - `make fclean && make && make bonus` ✅
    - `make bonus` repetido sin reconstrucción innecesaria ✅
    - compilación externa con `libft.h` + `libft_bonus.h` (`OK_HEADER_FLOW`) ✅

- Sync de tracking docs de workspace:
  - actualizado mapa de estructura real en:
    - `.github/QUICK_REFERENCE.md`
    - `.github/copilot-instructions.md`
  - corregidas rutas del checklist de validación en:
    - `.github/QUICK_REFERENCE.md`
    - `.github/workflow-rules.md`
  - comando normalizado:
    - `rg -n "42/PDFs|42/C/libft" .github`

- Cierre total operativo de `libft`:
  - validaciones ejecutadas en `42/C/libft`:
    - `make fclean && make && make bonus` ✅
    - `norminette *.c *.h` revisado: solo `INVALID_HEADER` ✅
    - smoke test externo de headers/biblioteca (`OK_HEADER_FLOW`) ✅
  - docs de cierre actualizadas:
    - `.github/libft-progress.md`
    - `.github/libft-functions.md`
    - `.github/libft-reference.md`
    - `.github/projects-index.md`
  - estado consolidado:
    - `libft` marcado como `completed`.
    - workspace listo para iniciar siguiente proyecto en `42/C/<project_name>/`.

- Nueva regla operativa de refresco de contexto:
  - trigger aceptado: `refrescar memoria` y `(refrescar memoria)`.
  - comportamiento definido:
    - refrescar estado git (`Raiz/` y `42/C/`), tracking docs, specs en
      `42/PDFs/` y pendientes diferidos.
    - resumir baseline actualizado antes de cualquier nueva implementación.
  - docs actualizadas:
    - `.github/workflow-rules.md`
    - `.github/instructions/config-guide.instructions.md`
    - `.github/copilot-instructions.md`

## 2026-03-10

- Onboarding de especificacion `ft_printf`:
  - spec agregada en:
    - `42/PDFs/2026-03-10_ft_printf.txt`
  - referencia base para validacion/correccion:
    - conversiones obligatorias `cspdiuxX%`
    - Makefile con `-Wall -Wextra -Werror` y sin relink
    - uso permitido de `libft`

- Nuevo proyecto detectado en `42/C/`:
  - `42/C/ft_printf/` (estado: in-progress, en revision y correccion)
  - actualizado:
    - `.github/projects-index.md`

- Se habilito tracking dedicado para `ft_printf`:
  - `.github/ft_printf-functions.md`
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-reference.md`

- Se actualizaron reglas/instrucciones para escalar a siguientes proyectos:
  - `.github/copilot-instructions.md`
  - `.github/workflow-rules.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/QUICK_REFERENCE.md`

## 2026-03-11

- Normalizacion global de headers 42 en proyectos C activos:
  - `42/C/ft_printf/*.c`, `42/C/ft_printf/*.h`
  - `42/C/ft_printf/libft/*.{c,h}`
  - `42/C/libft/*.{c,h}` (sincronizado desde `42/C/ft_printf/libft`)
- Alineacion estandar de cabeceras aplicada a 80 columnas.
- Autor/correo unificado en `ft_printf` y su `libft` integrada:
  - `By: saospina <saospina@student.42.fr>`
- Fechas bonus de `ft_printf` fijadas por politica acordada:
  - `Created: 2026/03/11 07:48:38`
  - `Updated: 2026/03/11 15:53:48`
- Se retiro la excepcion operativa de `INVALID_HEADER` en:
  - `.vscode/tasks.json`
  - `.vscode/keybindings.json`
  - `.tools/normi-autofix.sh`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
- Validacion de cierre sin filtros:
  - `norminette *.c *.h` en `42/C/ft_printf` ✅
  - `norminette *.c *.h` en `42/C/libft` ✅

- Correccion de especificacion `ft_printf`:
  - se elimino la version previa importada por error y se reemplazo por el
    `.txt` correcto compartido por el usuario.
  - archivo final mantenido:
    - `42/PDFs/2026-03-10_ft_printf.txt`
  - se limpiaron referencias de version anterior en tracking:
    - `.github/ft_printf-progress.md`
    - `.github/ft_printf-functions.md`
    - `.github/projects-index.md`

## 2026-03-11

- Cierre completo de `ft_printf` contra subject:
  - compliance funcional, memoria, build/no-relink y Norminette en verde.
  - matriz mandatory (`RET_TOTAL=212`) y bonus (`RET_TOTAL=146`) en paridad.

- Commits de cierre registrados:
  - repo `42/C/`:
    - `2415cdf` `ft_printf: finalize subject compliance and full validation`
  - repo `Raiz/`:
    - `7cf296d` `docs(ft_printf): record full subject audit and validation status`

- Sincronizacion de tracking global actualizada en:
  - `.github/ft_printf-functions.md`
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-reference.md`
  - `.github/libft-functions.md`
  - `.github/libft-progress.md`
  - `.github/libft-reference.md`
  - `.github/projects-index.md`

- Estado pendiente detectado en repo de entrega (`42/C/`):
  - lote no commiteado en `42/C/libft/*.c` (42 archivos), orientado a
    limpieza de comentarios de pruebas y ajustes menores de formato.
  - no se detecta delta pendiente en `libft.h` / `libft_bonus.h`.

- Cierre del lote pendiente de `libft`:
  - commit en `42/C/`: `bfe932d`
    (`libft: clean legacy commented test blocks and normalize eof`).
  - working tree de `42/C` queda sin cambios tracked pendientes en `libft`.

## 2026-03-11

- Retranscripcion completa de especificacion `ft_printf`:
  - se regenero el contenido de:
    - `42/PDFs/2026-03-10_ft_printf.txt`
  - criterio aplicado:
    - sin resumen, sin recortes, preservando semantica de secciones
      (titulo, resumen, indice, capitulos, requisitos, bonus,
      entrega/evaluacion)

- Regla permanente anti-resumen para specs `.txt`:
  - actualizadas reglas de importacion en:
    - `.github/copilot-instructions.md`
    - `.github/workflow-rules.md`
    - `.github/instructions/config-guide.instructions.md`
    - `.github/QUICK_REFERENCE.md`

- Inicio de implementacion de optimizacion Norminette en `ft_printf`:
  - baseline completo ejecutado sobre `42/C/ft_printf`.
  - estrategia activada: micro-lotes (`editar -> norminette archivo`).
  - micro-lote 1 completado en:
    - `42/C/ft_printf/ft_printf.c`
    - `42/C/ft_printf/parse_format.c`
    - `42/C/ft_printf/parse_format_bonus.c`
  - resultado del lote:
    - en esos archivos, solo `INVALID_HEADER`.
  - build verificado tras cambios:
    - `make bonus` OK en `42/C/ft_printf`.

- Continuacion de optimizacion Norminette en `ft_printf`:
  - micro-lote 2 aplicado en:
    - `42/C/ft_printf/print_char.c`
    - `42/C/ft_printf/print_char_bonus.c`
  - resultado del lote:
    - en ambos archivos, solo `INVALID_HEADER`.
  - revalidacion de build:
    - `make bonus` OK tras los cambios.

- Blindaje de `ft_printf` en Makefile y headers contra enunciado oficial:
  - `ft_printf.h` separado de API bonus.
  - creado `42/C/ft_printf/ft_printf_bonus.h`.
  - migrados includes bonus a `ft_printf_bonus.h`.
  - validada la regla de orden: compilar `libft` primero y luego
    archivado final de `ft_printf`.
  - revalidacion final completa:
    - `make` / `make bonus` OK + no-relink.
    - `norminette *.c *.h libft/*.c libft/*.h` -> `RC=0`.
    - matrices mandatory/bonus -> `RET_TOTAL=212` / `146`.
    - valgrind mandatory/bonus -> `0` leaks, `0` errores.

- Inicio de implementacion `ft_printf` (ciclo 1):
  - cambios en codigo:
    - `42/C/ft_printf/handle_format.c`
    - `42/C/ft_printf/handle_format_bonus.c`
    - `42/C/ft_printf/print_int.c`
    - `42/C/ft_printf/print_int_bonus.c`
    - `42/C/ft_printf/print_unsigned_bonus.c`
  - ajustes aplicados:
    - fix de avance de indice en dispatch para evitar salto de caracteres
      post-conversion.
    - hardening de memoria en casos `.0` con `0` y guardas de `malloc`
      en rutas afectadas.
  - validacion inicial:
    - `make` y `make bonus` OK.
    - smoke comparativo `%.0d`/`%.0u` alineado con `printf` (output + return).
    - valgrind smoke sin leaks/errores.

- Continuacion implementacion `ft_printf` (ciclo 2):
  - cambios en codigo:
    - `42/C/ft_printf/print_pointer.c`
    - `42/C/ft_printf/print_pointer_bonus.c`
    - `42/C/ft_printf/Makefile`
  - ajustes aplicados:
    - `%p` con puntero `NULL` alineado con `printf` (`(nil)`) en obligatorio y
      bonus.
    - `Makefile` robustecido para recrear `libftprintf.a` en `all` y `bonus`,
      evitando mezcla de objetos entre modos.
  - validacion:
    - matriz obligatoria comparada contra `printf`: sin diffs de output ni
      return total.
    - matriz bonus oficial comparada contra `printf`: sin diffs de output ni
      return total.

- Continuacion implementacion `ft_printf` (ciclo 3):
  - cambios en codigo:
    - `42/C/ft_printf/handle_format.c`
    - `42/C/ft_printf/handle_format_bonus.c`
  - objetivo:
    - limpieza incremental de Norminette en dispatchers sin alterar
      comportamiento funcional.
  - resultado:
    - en ambos archivos, unico hallazgo restante: `INVALID_HEADER`.
    - `make` y `make bonus` OK tras refactor.
    - matrices obligatoria y bonus se mantienen en paridad con `printf`.

- Habilitacion de coordinacion inter-chat por archivo puente:
  - objetivo:
    - permitir comunicacion operativa entre Chat1 y chats especialistas
      (Chat2 y futuros Chat3+) sin canal directo interno.
  - archivo canonico creado:
    - `.github/chat-handoff.md`
  - reglas y guias actualizadas:
    - `.github/copilot-instructions.md`
    - `.github/instructions/config-guide.instructions.md`
    - `.github/instructions/c-coding.instructions.md`
    - `.github/workflow-rules.md`
    - `.github/QUICK_REFERENCE.md`
  - politica de estado definida:
    - `TODO`, `WIP`, `BLOCKED`, `DONE`, `DEFERRED`.
  - resultado:
    - Chat1 delega y prioriza; chat especialista ejecuta y reporta en la
      misma entrada, manteniendo trazabilidad continua.

- Revalidacion de progreso `ft_printf` y tracking actualizado:
  - verificacion puntual en archivo foco:
    - `42/C/ft_printf/print_hex_bonus.c` mantiene solo `INVALID_HEADER`.
  - estado de compilacion actualizado:
    - `make` OK.
    - `make bonus` OK.
  - snapshot de deuda Norminette accionable (sin `INVALID_HEADER`):
    - total `286` errores.
    - distribucion: `print_unsigned.c` (151), `print_int_bonus.c` (39),
      `print_int.c` (39), `print_hex.c` (31), `print_binary_bonus.c` (26).
  - docs de tracking sincronizadas a este baseline:
    - `.github/ft_printf-functions.md`
    - `.github/ft_printf-progress.md`
    - `.github/ft_printf-reference.md`
    - `.github/chat-handoff.md`

- Inicio de migracion a nueva base de `ft_printf`:
  - nueva fuente obligatoria agregada en:
    - `42/C/ft_printf_new_base/`
  - decision de migracion:
    - mantener destino final en `42/C/ft_printf/`
    - aplicar switch por diff para preservar trazabilidad y bonus.
  - cambios iniciales aplicados en `42/C/ft_printf`:
    - entrypoint obligatorio nuevo: `ft_printf.c`
    - entrypoint bonus desacoplado: `ft_printf_bonus.c`
    - obligatorio reorganizado: `print_char.c`, `print_string.c`,
      `print_decimal.c`, `print_unsigned.c`, `print_hex.c`,
      `print_pointer.c`, `utils.c`
    - `Makefile` actualizado para `SRC` obligatorio nuevo y `BONUS_SRC`
      con `ft_printf_bonus.c`.
  - validacion inicial post-switch:
    - `make fclean && make` OK.
    - `make bonus` OK.
    - smoke obligatorio base (`cspdiuxX%`) alineado con `printf`.

- Nuevo directorio de soporte para pruebas de `ft_printf`:
  - creado:
    - `42/tests_ft_printf/`
    - `42/tests_ft_printf/README.md`
  - tracking actualizado por regla `support-dir`:
    - `.github/projects-index.md`
    - `.github/project-history.md`
    - `.github/QUICK_REFERENCE.md`

- Auditoria solicitada a Chat1 via handoff activo:
  - entrada activa agregada:
    - `H-003` en `.github/chat-handoff.md`
  - alcance:
    - auditoria de estrategia de migracion por diff y criterio de cierre.

- Regla global reforzada por solicitud de usuario (todos los proyectos):
  - orden obligatorio de revision:
    1. funcionalidad contra `.txt`,
    2. memoria/estabilidad,
    3. norminette al final como cierre.
  - docs de gobierno actualizadas:
    - `.github/copilot-instructions.md`
    - `.github/instructions/config-guide.instructions.md`
    - `.github/instructions/c-coding.instructions.md`
    - `.github/workflow-rules.md`
    - `.github/QUICK_REFERENCE.md`

- Ejecucion funcional-first aplicada en `ft_printf`:
  - gates completados antes de nueva limpieza de norma:
    - obligatorio: comparativa contra `printf` sin diff de salida,
      `RET_TOTAL=212`.
    - bonus: comparativa contra `printf` sin diff de salida,
      `RET_TOTAL=146`.
    - memoria: valgrind en casos frontera con `0` leaks y `0` errores.
  - ajuste puntual posterior de estilo:
    - `42/C/ft_printf/print_binary_bonus.c` (cierre de
      `BRACE_SHOULD_EOL`, quedando solo `INVALID_HEADER`).
  - snapshot de deuda Norminette accionable recalculado (sin
    `INVALID_HEADER`):
    - `42/C/ft_printf/ft_printf.h` (60)
    - `42/C/ft_printf/parse_format_bonus.c` (56)
    - `42/C/ft_printf/handle_format_bonus.c` (28)
  - tracking sincronizado:
    - `.github/ft_printf-progress.md`
    - `.github/ft_printf-reference.md`
    - `.github/ft_printf-functions.md`

- Estructura/scope-first reforzado y ejecutado en `ft_printf`:
  - decision aplicada: validar estructura de entrega antes de norma para
    evitar retrabajo en archivos que luego se eliminan/reescriben.
  - cambios en entrega (`42/C/ft_printf`):
    - `Makefile` ajustado con regla explicita `$(NAME)` y flujo sin relink
      innecesario (`all`/`bonus` con copia condicional a `libftprintf.a`).
    - eliminados extras fuera de alcance activo de la spec:
      - `print_reverse_bonus.c`
      - `print_n_bonus.c`
      - `print_binary_bonus.c` (no presente en baseline final).
  - validacion posterior:
    - `make` OK y segunda corrida sin relink (`Nothing to be done for all`).
    - `make bonus` OK y segunda corrida sin relink.
    - matrices mandatory/bonus en paridad con `printf`
      (`RET_TOTAL=212` y `RET_TOTAL=146`).
    - valgrind frontera: `0` leaks y `0` errores.
  - docs de gobierno reforzadas para evitar recurrencia:
    - `.github/workflow-rules.md`
    - `.github/instructions/config-guide.instructions.md`
    - `.github/instructions/c-coding.instructions.md`

- Limpieza de residuos de pruebas y snapshot de cierre parcial:
  - en `42/tests_ft_printf/` se eliminaron artefactos generados
    (`*.out`, `*.err`, ejecutables) para mantener el directorio de tests
    en estado fuente.
  - verificacion post-limpieza en `42/C/ft_printf`:
    - `make` OK
    - `make bonus` OK
  - estado Norminette accionable actual (ignorando `INVALID_HEADER`):
    - `42/C/ft_printf/ft_printf.h`
    - `42/C/ft_printf/parse_format_bonus.c`
    - `42/C/ft_printf/handle_format_bonus.c`

- Cierre de norma accionable en `ft_printf`:
  - micro-lote final aplicado sobre:
    - `42/C/ft_printf/ft_printf.h`
    - `42/C/ft_printf/parse_format_bonus.c`
    - `42/C/ft_printf/handle_format_bonus.c`
  - resultado de validacion:
    - `norminette *.c *.h` sin errores accionables (solo `INVALID_HEADER`).
    - `make` OK.
    - `make bonus` OK.

- Cierre final de sesion `ft_printf` (higiene + publicacion):
  - limpieza final aplicada en entrega:
    - eliminado staging `42/C/ft_printf_new_base/` del scope tracked.
    - agregado ignore de artefactos locales en `42/C/ft_printf/.gitignore`.
  - limpieza final aplicada en workspace de tests:
    - agregado ignore de binarios locales en `42/tests_ft_printf/.gitignore`.
  - commits de cierre en `42/C/`:
    - `79b2255` `ft_printf: harden headers and keep makefile/spec compliance`
    - `360f071` `chore(ft_printf): ignore local build artifacts and drop staging base`
  - commits de cierre en `Raiz/`:
    - `9ecbda6` `docs(ft_printf): record makefile/header hardening and final checks`
    - `b7bdcda` `chore(tests): ignore local ft_printf test binaries`
  - publicacion remota completada:
    - `42/C` -> `main` actualizado `2bdbff1..360f071`
    - `Raiz` -> `main` actualizado `e23e537..b7bdcda`

## Log Rules

1. Add one dated block per relevant change set.
2. Log structural changes first, then function/spec changes.
3. Reference exact file paths for every important edit.

## 2026-03-11

- Sync documental de consistencia global (functional-first):
  - se armonizaron docs de tracking y README de tests para mantener
    el orden canonico: scope/spec -> funcionalidad -> memoria -> Norminette.
- Archivos actualizados:
  - `.github/libft-progress.md`
  - `.github/project-history.md`
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-functions.md`
  - `.github/ft_printf-reference.md`
  - `42/testsLibf/README.md`
  - `42/tests_ft_printf/README.md`

## 2026-03-11

- Cierre definitivo documental de `ft_printf` y sincronizacion de continuidad:
  - se promovio un bloque visible de cierre definitivo en tracking.
  - se archivaron secciones historicas de pendientes para evitar ambiguedad.
  - se cerro handoff explicito Chat2 -> Chat1 con confirmacion final (H-004).
  - se actualizaron estados de carpetas de tests a `completed` con nota de regresion.
- Archivos actualizados:
  - `.github/ft_printf-progress.md`
  - `.github/ft_printf-reference.md`
  - `.github/chat-handoff.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `42/tests_ft_printf/README.md`
  - `.github/project-history.md`

## 2026-03-11

- Inicio de `42/C/currentLibft` como base evolutiva para futuros proyectos C.
- Estructura integrada aplicada:
  - `42/C/currentLibft/libft`
  - `42/C/currentLibft/libft/ft_printf`
- Regla de arquitectura formalizada:
  - una sola `libft` padre dentro de `currentLibft`.
  - proyectos hijos integrados (como `ft_printf`) no pueden incluir
    una `libft` hija propia dentro de su subarbol.
- Ajustes tecnicos de integracion inicial:
  - `ft_printf` integrado apunta a la `libft` padre de `currentLibft`
    via headers y Makefile.
  - Makefile raiz en `currentLibft` para orquestar `make`/`bonus`.
- Gate de pruebas creado para continuidad:
  - `42/tests_currentLibft/README.md`.
