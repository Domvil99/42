# Project History

Purpose: chronological log of important decisions, imports, and structure changes.

## Global Active Rules

Validation order for all projects:

1. structure/scope against `.txt`.
2. behavior against `.txt`.
3. memory/stability.
4. Norminette as final closing step.

## 2026-04-05

- Change type: integration-baseline-refresh
- Paths changed:
  - `.github/tracking/projects/currentLibft/`
  - `.github/study/currentLibft/`
  - `.github/tracking/projects/push_swap/`
- Tracking docs updated:
  - `.github/tracking/projects/currentLibft/currentLibft-functions.md`
  - `.github/tracking/projects/currentLibft/currentLibft-reference.md`
  - `.github/tracking/projects/currentLibft/currentLibft-progress.md`
  - `.github/tracking/projects/currentLibft/integration-manifest.md`
  - `.github/study/currentLibft/currentLibft.md`
  - `.github/study/currentLibft/dictionary.md`
  - `.github/tracking/projects/push_swap/push_swap-functions.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/tracking/projects/push_swap/push_swap-reference.md`
- Notes:
  - Se amplió la documentación de `currentLibft` con detalle de APIs
    integradas (`ft_printf` y `get_next_line`) y constantes de configuración.
  - Se sincronizó tracking de `push_swap` para reflejar la base `libft`
    integrada completa (mandatory + bonus disponibles en árbol local).
  - Validación técnica ejecutada en `42/C/push_swap`:
    - `make fclean && make`: OK
    - smoke tests obligatorios: OK
    - norminette en árbol impactado (`push_swap` + `libft` integrada): OK

## 2026-03-29

- Change type: docs-structure
- Paths changed:
  - `.github/tracking/projects/`
  - `.github/study/`
  - `.github/currentLibft/` (manifest moved)
  - `.github/study_methods/` (renamed to `.github/study/`)
- Tracking docs updated:
  - `.github/copilot-instructions.md`
  - `.github/workflow-rules.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/chat-handoff.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/project-history.md`
  - `.github/reports/workblock-pending-status.md`
- Notes:
  - Se aplicó reorganización híbrida de markdown por temática, manteniendo
    anclas canónicas en raíz de `.github`:
    - `.github/copilot-instructions.md`
    - `.github/workflow-rules.md`
    - `.github/chat-handoff.md`
    - `.github/projects-index.md`
    - `.github/project-history.md`
  - Triadas de tracking por proyecto movidas a
    `.github/tracking/projects/<project>/`.
  - `integration-manifest.md` de currentLibft movido a
    `.github/tracking/projects/currentLibft/integration-manifest.md`.
  - Limpieza post-migración: eliminada carpeta placeholder vacía
    `.github/currentLibft/` tras mover su contenido al tracking canónico.
  - Material de estudio consolidado en `.github/study/`.
  - Referencias cruzadas reescritas a nuevas rutas en documentación e
    instrucciones.

## 2026-03-28

- Change type: project-structure
- Paths changed:
  - `42/tests/`
  - `42/tests/testsLibf/`
  - `42/tests/tests_ft_printf/`
  - `42/tests/tests_get_next_line/`
  - `42/tests/tests_push_swap/`
  - `42/tests/tests_currentLibft/`
  - `42/testsLibf/` (migrated)
  - `42/tests_ft_printf/` (migrated)
  - `42/tests_get_next_line/` (migrated)
  - `42/tests_push_swap/` (migrated)
  - `42/tests_currentLibft/` (migrated)
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/copilot-instructions.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `.github/project-history.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
- Notes:
  - Se creó contenedor unificado `42/tests/` y se migraron las carpetas de
    pruebas manteniendo naming actual por proyecto (`testsLibf`,
    `tests_ft_printf`, `tests_get_next_line`, `tests_push_swap`,
    `tests_currentLibft`).
  - Se actualizaron rutas en markdown e instrucciones al nuevo esquema
    `42/tests/<tests_name>/`.
  - Ajustes funcionales aplicados por migración:
    - `42/tests/testsLibf/Makefile`: `LIBFT_DIR` actualizado a `../../C/libft`.
    - `42/tests/tests_ft_printf/Makefile`: `FT_PRINTF_DIR` actualizado a
      `../../C/ft_printf`.
    - Includes de tests actualizados a nuevas rutas relativas.
  - Validación post-migración:
    - `42/tests/testsLibf`: `make bonus && make run` OK.
    - `42/tests/tests_ft_printf`: matrices en verde
      (`RET_TOTAL=212` y `RET_TOTAL=146`).
    - `42/C/currentLibft`: `make fclean && make && make bonus` OK.
    - `42/C/push_swap`: smoke y errores esperados (`Error`) en verde.

## 2026-03-20

- Change type: workflow-docs
- Paths changed:
  - `.github/projects-index.md`
  - `.github/copilot-instructions.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
  - `.github/reports/workblock-pending-status.md`
- Notes:
  - Normalizacion de mapas de estructura y secciones de gobierno para
    reflejar el estado real de `42/C/`.
  - Eliminadas inconsistencias de alcance en `copilot-instructions` y
    secciones vacias en `workflow-rules`.
  - `workblock-pending-status` simplificado a snapshot actual con solo
    pendientes reales del bloque activo.

- Change type: docs-consistency
- Paths changed:
  - `.github/chat-handoff.md`
  - `.github/projects-index.md`
  - `.github/tracking/projects/get_next_line/get_next_line-functions.md`
  - `.github/tracking/projects/get_next_line/get_next_line-progress.md`
  - `.github/tracking/projects/get_next_line/get_next_line-reference.md`
  - `.github/tracking/projects/currentLibft/currentLibft-functions.md`
  - `.github/tracking/projects/currentLibft/currentLibft-progress.md`
  - `.github/tracking/projects/currentLibft/currentLibft-reference.md`
  - `.github/study/overview.md`
  - `.github/study/push_swap/push_swap.md`
  - `.github/study/get_next_line/get_next_line.md`
  - `.github/study/currentLibft/currentLibft.md`
  - `42/tests/testsLibf/README.md`
  - `42/tests/tests_currentLibft/README.md`
  - `42/tests/tests_ft_printf/README.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
- Notes:
  - Correccion de inconsistencias factuales en rutas, estado y cobertura de
    tracking de markdown respecto al workspace real.
  - Creado tracking faltante para `get_next_line` y `currentLibft`
    (functions/progress/reference).
  - README de tests alineados a specs canonicas y rutas reales de compilacion.

- Change type: docs-validation
- Paths changed:
  - `.github/copilot-instructions.md`
  - `.github/tracking/projects/currentLibft/integration-manifest.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/projects-index.md`
  - `.github/copilot-instructions.md`
- Notes:
  - Revision exhaustiva adicional de `.md` con foco en claridad canónica y
    metadata de actualización.
  - Pruebas ejecutadas y validadas:
    - `42/C/libft`: `make fclean && make && make bonus` + `42/tests/testsLibf`.
    - `42/C/ft_printf`: build mandatory/bonus + matrices
      (`RET_TOTAL=212` y `RET_TOTAL=146`).
    - `42/C/currentLibft`: `make fclean && make && make bonus`.
    - `42/C/push_swap`: smoke tests (`2 1`, `3 2 1`, ordenado sin salida)
      y errores esperados (`Error` en alpha/duplicado/overflow).

## 2026-03-19

- Change type: project-structure
- Paths changed:
  - `42/C/push_swap`
  - `42/tests/tests_push_swap`
  - `.github/study/push_swap`
  - `.github/study/push_swap/push_swap.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Notes:
  - Actualizacion estructural y documental del modulo `push_swap`.
  - Referencias en markdown alineadas con el estado vigente del proyecto.

- Change type: project-fix
- Paths changed:
  - `42/C/push_swap/parse.c`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
- Notes:
  - Fix aplicado en parsing para uso correcto de libft integrada:
    `ft_split` aplicado en `parse_single_string` para tokenizar argumentos.
  - Validacion posterior completa en `push_swap`:
    - build `make`: OK
    - funcional basico: OK (`2 1`, `3 2 1`, ordenado, invalido alpha)
    - memoria (Valgrind): 0 leaks, 0 errors
    - benchmark muestra: `OPS100=594`, `OPS500=5083`
    - Norminette final: OK en `*.c` y `*.h`
## 2026-03-15

- Change type: workflow-docs
- Paths changed:
  - `.github/instructions/config-guide.instructions.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
- Notes:
  - Normalizacion terminologica minima en Chat4:
    `metodos de estudio` -> `study methods`.
  - Verificacion de consistencia en `.github`:
    no se detectan referencias antiguas de ruta y se mantiene
    la ruta canonica `.github/study/`.

## 2026-03-14

- Change type: workflow
- Paths changed:
  - `.github/copilot-instructions.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/workflow-rules.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
- Notes:
  - Se oficializa el mapeo de aliases por chat:
    - Chat1 = AdminChat/Admin
    - Chat2 = codeEditorChat/codeEditor/Code/Editor
    - Chat4 = StudyChat/Study
  - Se activa regla global de inmutabilidad por conversación:
    si una conversación inicia en ChatX, debe permanecer en ChatX.
  - Queda prohibido cambiar de chat dentro de la misma conversación;
    para usar otro chat se debe abrir una conversación nueva.

- Change type: study
- Paths changed:
  - `.github/study/push_swap/push_swap.md`
  - `.github/study/push_swap/implementation.md`
  - `.github/study/push_swap/validation.md`
  - `.github/study/push_swap/defense.md`
  - `.github/study/push_swap/case-studies.md`
  - `.github/study/push_swap/dictionary.md`
  - `.github/study/overview.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/study/overview.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Notes:
  - Se crea paquete dedicado y completo de estudio para
    `push_swap` en modalidad dedicada.
  - El contenido incluye cobertura total de arquitectura, parsing,
    operaciones, algoritmos, validacion, defensa y glosario especifico.
  - Se incorporan evidencias reales ejecutadas en fecha 2026-03-14:
    build OK, casos funcionales, benchmark de muestra (`OPS100=594`,
    `OPS500=4961`) y memoria limpia en Valgrind.

## 2026-03-13

- Change type: project
- Paths changed:
  - `42/C/push_swap/Makefile`
  - `42/C/push_swap/push_swap.c`
  - `42/C/push_swap/push_swap.h`
  - `42/C/push_swap/parse.c`
  - `42/C/push_swap/parse_utils.c`
  - `42/C/push_swap/stack_build.c`
  - `42/C/push_swap/stack_utils.c`
  - `42/C/push_swap/ops_swap.c`
  - `42/C/push_swap/ops_push.c`
  - `42/C/push_swap/ops_rotate.c`
  - `42/C/push_swap/ops_reverse_rotate.c`
  - `42/C/push_swap/free_utils.c`
  - `42/C/push_swap/sort_small.c`
  - `42/C/push_swap/sort_chunk.c`
  - `42/C/push_swap/sort_radix.c`
  - `42/C/push_swap/libft/Makefile`
  - `42/C/push_swap/libft/ft_printf/Makefile`
  - `42/C/push_swap/libft/get_next_line/Makefile`
  - `42/tests/tests_push_swap/README.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/project-history.md`
- Notes:
  - Se crea `push_swap` como proyecto independiente solo mandatory.
  - Se define Makefile exclusivo del alcance actual del proyecto.
  - Verificacion final: compilacion de `push_swap` OK y Norminette top-level OK.

- Change type: validation-report
- Paths changed:
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/project-history.md`
- Notes:
  - Checkpoint 2 de `push_swap` ejecutado con validación por lotes y estabilidad.
  - Benchmark repetido con checker externo:
    - 20 muestras de 100 números -> `20/20 OK`, `max_ops100=631`.
    - 10 muestras de 500 números -> `10/10 OK`, `max_ops500=5260`.
  - Validación de errores en `push_swap`:
    - `duplicado`, `overflow` y `string vacía` -> `Error` + exit `1`.
  - ASAN/UBSAN en `push_swap` sin hallazgos.

- Change type: project
- Paths changed:
  - `42/C/push_swap/Makefile`
  - `42/C/push_swap/push_swap.c`
  - `42/C/push_swap/sort_chunk.c`
  - `42/C/push_swap/push_swap.h`
  - `.github/projects-index.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/project-history.md`
- Notes:
  - `push_swap` pasa a implementación técnica activa con ACK de Chat2 en H-009.
  - Se integra estrategia `chunk sort` para tamaños medios (`<=500`) manteniendo
    `small sort` y `radix` como soporte.
  - Evidencia funcional consolidada con checker externo:
    - caso base de control: `OK`,
    - errores críticos (`duplicado`, `overflow`, `string vacía`) -> `Error`.
  - Benchmark de muestra tras optimización:
    - 100 números: `602` operaciones (`OK`),
    - 500 números: `5182` operaciones (`OK`).

- Change type: validation-report
- Paths changed:
  - `.github/chat-handoff.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/study/push_swap/implementation.md`
  - `.github/study/push_swap/case-studies.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/chat-handoff.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/project-history.md`
- Notes:
  - Se ejecuta Checkpoint 1 de `push_swap` (parsing + validacion de errores)
    con evidencia real en terminal.
  - Handoff `H-013` pasa a `WIP` con ACK y prueba de sincronizacion activa
    entre implementacion y estudio incremental.
  - Se registran resultados verificados en material de estudio para evitar
    drift entre codigo y documentacion.

- Change type: study
- Paths changed:
  - `.github/study/push_swap/push_swap.md`
  - `.github/study/push_swap/implementation.md`
  - `.github/study/push_swap/validation.md`
  - `.github/study/push_swap/defense.md`
  - `.github/study/push_swap/case-studies.md`
  - `.github/study/push_swap/dictionary.md`
  - `.github/tracking/projects/push_swap/push_swap-functions.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/tracking/projects/push_swap/push_swap-reference.md`
  - `.github/chat-handoff.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/chat-handoff.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
  - `.github/tracking/projects/push_swap/push_swap-functions.md`
  - `.github/tracking/projects/push_swap/push_swap-progress.md`
  - `.github/tracking/projects/push_swap/push_swap-reference.md`
- Notes:
  - Se inicia informe de estudio integral de `push_swap` en modo paralelo a la
    implementacion activa, con estructura modular ampliable.
  - Se crean anexos de implementacion, validacion, defensa y casos de estudio
    para aprendizaje progresivo tipo humano.
  - Se documentan exclusivamente las funciones de libft usadas por `push_swap`:
    `ft_split` y `ft_memcpy`.
  - Se activa sincronizacion formal en handoff con `H-013` (Chat2) y `H-014`
    (Chat4) bajo `T-007` para mantener desarrollo + estudio en paralelo.

- Change type: workflow
- Paths changed:
  - `.github/copilot-instructions.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/workflow-rules.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/copilot-instructions.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/workflow-rules.md`
  - `.github/project-history.md`
- Notes:
  - Se habilita oficialmente variante tecnica de `refrescar memoria` en Chat2
    para un proyecto C activo.
  - Alcance permitido: estructura, bases previas, currentLibft utilizable,
    funciones/tests/specs para implementacion/validacion/optimizacion.
  - Limite mantenido: gobernanza cross-chat, decisiones `APPROVED/REJECTED` y
    priorizacion siguen siendo Chat1-only.
  - Regla de seguridad: contexto ambiguo o administrativo se escala a Chat1.

- Change type: closure
- Paths changed:
  - `.github/chat-handoff.md`
  - `.github/reports/pdfs-canonical-inventory.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/chat-handoff.md`
  - `.github/reports/pdfs-canonical-inventory.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/project-history.md`
- Notes:
  - Validacion explicita de usuario recibida: "la traduccion es la correcta".
  - H-008 y H-012 cerrados en `DONE`.
  - H-009 y H-011 desbloqueados y movidos a `TODO` para ACK de Chat2.
  - Inventario canonico de PDFs actualizado: push_swap en estado `DONE`.

- Change type: spec-import
- Paths changed:
  - `42/PDFs/2026-03-13_push_swap.txt`
  - `42/PDFs/2026-03-13_push_swap_actualizado.txt`
  - `.github/reports/pdfs-canonical-inventory.md`
  - `.github/chat-handoff.md`
- Tracking docs updated:
  - `.github/reports/pdfs-canonical-inventory.md`
  - `.github/chat-handoff.md`
  - `.github/project-history.md`
- Notes:
  - Source oficial del subject `push_swap` v10.0 recibido del usuario
    y guardado en `42/PDFs/2026-03-13_push_swap.txt`.
  - Traduccion completa al espanol generada en
    `42/PDFs/2026-03-13_push_swap_actualizado.txt`.
  - Prerequisito de H-008 cumplido. H-008 y H-012 pasados a
    `REVIEW_PENDING`. Pendiente aprobacion del usuario para cerrar
    y desbloquear H-009 y H-011.
  - Inventario canonico actualizado: `push_swap` pasa de `BLOCKED`
    a `REVIEW_PENDING`.

- Change type: workflow
- Paths changed:
  - `.github/chat-handoff.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/reports/pdfs-canonical-inventory.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/chat-handoff.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/reports/pdfs-canonical-inventory.md`
  - `.github/project-history.md`
- Notes:
  - Handoff `H-012` (`T-006`) accepted by Chat1 (`APPROVED`) and moved to
    `WIP` with ACK, per user instruction.
  - Execution performed together with `H-008`: canonical PDFs consolidation
    started and documented in `.github/reports/pdfs-canonical-inventory.md`.
  - `H-008` normalized to `WAITING_FOR_PREREQUISITE` due to missing source
    spec file for `push_swap` in workspace; unblock condition recorded.
  - Gate integrity revalidated with audit script (no `WIP` violations).

- Change type: validation-report
- Paths changed:
  - `.github/chat-handoff.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/reports/workblock-pending-status.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/reports/workblock-pending-status.md`
- Notes:
  - E2E relay test instantiated with two explicit scenarios:
    - `H-010`: `REJECTED` + `BLOCKED` for out-of-scope governance request.
    - `H-011`: `APPROVED` + `WAITING_FOR_PREREQUISITE` gated by `H-008:DONE`.
  - Prerequisite audit rerun with pass result:
    `OK: no WIP handoff violates prerequisite gates.`

- Change type: support-dir
- Paths changed:
  - `42/tests/tests_push_swap/README.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Notes:
  - Included support test directory `42/tests/tests_push_swap/` in workspace
    tracking as requested.
  - Registered initial README for push_swap test area and updated references
    so future validation flow is traceable.

- Change type: workflow
- Paths changed:
  - `.github/copilot-instructions.md`
  - `.github/workflow-rules.md`
  - `.github/chat-handoff.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/reports/workblock-pending-status.md`
  - `.tools/audit-handoff-prerequisites.sh`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/reports/workblock-pending-status.md`
- Notes:
  - Inter-chat relay upgraded to enforce Chat1 as single approval authority
    for out-of-scope requests with explicit decision `APPROVED`/`REJECTED`.
  - Handoff schema extended with `Prerequisite`, `Gate`, `Decision` and new
    statuses `WAITING_FOR_PREREQUISITE` + `REVIEW_PENDING`.
  - Hard gate activated: implementation cannot move to `WIP` until its
    prerequisite handoff is `DONE`.
  - Pilot flow initialized with `H-008` (translation path) and `H-009`
    (implementation path blocked by prerequisite).
  - Added audit script `.tools/audit-handoff-prerequisites.sh` and validated
    pass result (`OK: no WIP handoff violates prerequisite gates.`).

## 2026-03-12

- Change type: workflow
- Paths changed:
  - `.github/chat-handoff.md`
  - `.github/reports/inter-chat-essential.md`
  - `.github/workflow-rules.md`
  - `.github/copilot-instructions.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
- Notes:
  - Implemented inter-chat relay protocol to avoid manual user copy/paste when
    request arrives in a non-corresponding specialist chat.
  - Handoff `H-007` (`T-003`) moved from open state to `DONE` with ACK trace
    and closure criteria satisfied.
  - Governance now enforces specialist response format (scope reason,
    practical solution, explicit redirection, minimal context block) and
    Chat1 conversion to formal handoff for execution continuity.

- Change type: workflow
- Paths changed:
  - `.github/study/global-dictionary.md`
  - `.github/study/overview.md`
  - `.github/study/libft/dictionary.md`
  - `.github/study/ft_printf/dictionary.md`
  - `.github/study/get_next_line/dictionary.md`
  - `.github/study/currentLibft/currentLibft.md`
  - `.github/study/currentLibft/dictionary.md`
  - `.github/copilot-instructions.md`
  - `.github/workflow-rules.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/QUICK_REFERENCE.md`
- Notes:
  - Implemented mandatory study dictionary rule with two layers:
    - global dictionary at `.github/study/global-dictionary.md`,
    - project dictionary at `.github/study/<project>/dictionary.md`.
  - Added project dictionaries for `libft`, `ft_printf`, `get_next_line`
    and `currentLibft` using unified format (technical glossary + mini examples).
  - Created independent study module for `currentLibft` with:
    - `.github/study/currentLibft/currentLibft.md`,
    - `.github/study/currentLibft/dictionary.md`.
  - Updated governance/tracking docs to make the rule auditable in future
    study updates (`overview`, `workflow-rules`, `copilot-instructions`,
    `QUICK_REFERENCE`).

- Change type: validation-report
- Paths changed:
  - `.github/reports/currentLibft-validation-2026-03-12.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/project-history.md`
- Notes:
  - Full integrated validation executed for `42/C/currentLibft` using
    canonical updated specs for `libft`, `ft_printf`, and `get_next_line`.
  - Structural rule confirmed: single parent `libft` under `currentLibft`,
    with integrated grandchildren modules under `libft/<project_name>`.
  - Build flow validated end-to-end (`make`, relink check, `bonus`,
    `clean`, `fclean`, `re`) without errors.
  - Functional checks passed:
    - `ft_printf` mandatory and bonus matrices,
    - `get_next_line` mandatory (`BUFFER_SIZE=1,42,9999`) and
      bonus multi-fd.
  - Memory/stability checks with ASAN/UBSAN completed without runtime
    errors in representative runs.
  - Final Norminette scans in:
    - `42/C/currentLibft/libft`,
    - `42/C/currentLibft/libft/ft_printf`,
    - `42/C/currentLibft/libft/get_next_line`,
    all OK.
  - Final cleanup completed with no residual build artifacts in
    `42/C/currentLibft` and clean git status in both `Raiz` and `42/C`.
  - Semaforo final: all validation layers GREEN.

- Change type: project
- Paths changed:
  - `42/C/currentLibft/libft/libft.h`
  - `42/C/currentLibft/libft/libft_bonus.h`
  - `42/C/currentLibft/libft/.gitignore`
  - `42/C/ft_printf/libft/libft.h`
  - `42/C/ft_printf/libft/libft_bonus.h`
  - `.github/tracking/projects/currentLibft/integration-manifest.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/tracking/projects/currentLibft/integration-manifest.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `.github/project-history.md`
- Notes:
  - Base libft synchronization applied from `42/C/libft` to mirror roots:
    `42/C/currentLibft/libft` and `42/C/ft_printf/libft` for
    `*.c`, `*.h`, `Makefile`, `.gitignore`.
  - Scope preserved: integrated child modules under
    `42/C/currentLibft/libft/ft_printf` and
    `42/C/currentLibft/libft/get_next_line` were not moved or flattened.
  - Independence gate validated by build checks in `42/C` projects:
    `libft`, `ft_printf`, `get_next_line` (compile check), and `currentLibft`.
  - Objective achieved: maintain equal base libft files/functionality across
    projects while preserving autonomous project boundaries in `42/C/`.

- Change type: spec-txt
- Paths changed:
  - `42/PDFs/2026-03-12_get_next_line.txt`
  - `.github/project-history.md`
  - `42/tests/tests_get_next_line/README.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `42/tests/tests_get_next_line/README.md`
- Notes:
  - New corrected get_next_line baseline received and saved at
    `42/PDFs/2026-03-12_get_next_line.txt`.
  - Diff against prior working draft confirms normalization of index
    formatting with no functional normative
    drift in mandatory/bonus requirements.

- Change type: validation-report
- Paths changed:
  - `.github/project-history.md`
  - `.github/study/overview.md`
  - `.github/study/get_next_line/get_next_line.md`
  - `.github/QUICK_REFERENCE.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/QUICK_REFERENCE.md`
- Notes:
  - Full revalidation executed for `42/C/get_next_line` against updated
    baseline `42/PDFs/2026-03-12_get_next_line.txt`.
  - Mandatory behavior validated with `BUFFER_SIZE=1,42,9999` and stdin path.
  - Bonus behavior validated with multi-fd alternation (`BUFFER_SIZE=1,42`).
  - ASAN/UBSAN checks (`-fsanitize=address,undefined`) completed without
    runtime/leak reports.
  - Final norminette scan in `42/C/get_next_line/*.c` and
    `42/C/get_next_line/*.h` completed OK.
  - Study report initialized under
    `.github/study/get_next_line/get_next_line.md`.

- Change type: workflow
- Paths changed:
  - `.github/copilot-instructions.md`
  - `.github/chat-handoff.md`
  - `.github/workflow-rules.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/instructions/config-guide.instructions.md`
  - `.github/instructions/c-coding.instructions.md`
  - `.github/study/overview.md`
  - `.github/study/libft/libft.md`
  - `.github/study/ft_printf/ft_printf.md`
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
  - New study structure initialized at `.github/study/` with:
    - project folders in English (`libft`, `ft_printf`),
    - file names in English (`overview.md`, `<project>.md`),
    - explanatory content in Spanish with technical terminology.
  - Initial complete study reports created for validated projects:
    `libft` and `ft_printf`.

- Change type: spec-txt
- Paths changed:
  - `42/PDFs/2026-03-12_ft_printf.txt`
  - `.github/project-history.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
- Notes:
  - New corrected ft_printf baseline received and saved at
    `42/PDFs/2026-03-12_ft_printf.txt`.
  - Full validation executed for `42/C/ft_printf` against updated baseline:
    - `make fclean && make && make bonus` OK,
    - mandatory matrix in `42/tests/tests_ft_printf`: `RET_TOTAL=212` (parity with `printf`),
    - bonus matrix in `42/tests/tests_ft_printf`: `RET_TOTAL=146` (parity with `printf`),
    - ASAN/UBSAN run (`-fsanitize=address,undefined`) on both matrices: no runtime/leak reports,
    - final `norminette 42/C/ft_printf/*.c 42/C/ft_printf/*.h` OK.
  - libft parity audit executed between `42/C/libft` and `42/C/ft_printf/libft` headers:
    diff detected only in metadata `Updated` lines of `libft.h` and `libft_bonus.h`
    (no API/prototype/content drift).

- Change type: validation-report
- Paths changed:
  - `.github/project-history.md`
  - `.github/tracking/projects/libft/libft-progress.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/tracking/projects/libft/libft-progress.md`
- Notes:
  - Validacion integral de `libft1` ejecutada sobre `42/C/libft` usando
    baseline canonica `42/PDFs/2026-03-12_libft_v16_6.txt`.
  - Criterio aplicado: cierre estricto sin ignorar errores (incluye
    `INVALID_HEADER`).
  - Resultado global: GO (sin hallazgos criticos, altos, medios ni bajos).
  - Evidencias tecnicas:
    - repos `Raiz/` y `42/C/` limpios al iniciar validacion,
    - build obligatorio y bonus OK,
    - `make bonus` idempotente (sin relink),
    - `make run` en `42/tests/testsLibf` OK,
    - ASAN/UBSAN en `42/tests/testsLibf` OK,
    - barrido final `norminette` en `42/C/libft/*.c` y
      `42/C/libft/*.h` OK.
  - No se aplicaron cambios en codigo fuente de `42/C/libft`; el reporte
    persiste estado de validacion y trazabilidad de cierre.

- Change type: header-fix
- Paths changed:
  - `42/C/libft/libft.h`
  - `42/C/libft/libft_bonus.h`
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
  - `.github/project-history.md`
- Notes:
  - Final header adjustment in libft1 aligned with strict separation rule.
  - `libft.h` keeps mandatory + part2 only.
  - `libft_bonus.h` keeps bonus declarations (`t_list` + `ft_lst*`).
  - Full validation rerun after adjustment:
    - `make fclean && make && make bonus` ✅
    - `make run` in `42/tests/testsLibf` ✅
    - ASAN/UBSAN tests in `42/tests/testsLibf` ✅
    - final `norminette 42/C/libft/*.c 42/C/libft/*.h` ✅
  - Session closure prepared with clean environment and dual-repo commits.

- Change type: header-fix
- Paths changed:
  - `42/C/libft/libft.h`
  - `42/C/libft/libft_bonus.h`
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
  - `.github/project-history.md`
- Notes:
  - Header correction executed in libft1 according to corrected v16.6 spec.
  - `t_list` and `ft_lst*` declarations moved to `libft.h`.
  - `libft_bonus.h` kept as compatibility wrapper including `libft.h`.
  - Validation executed after change:
    - `make fclean && make && make bonus` in `42/C/libft` ✅
    - `make run` in `42/tests/testsLibf` ✅
    - final `norminette 42/C/libft/*.c 42/C/libft/*.h` ✅
  - Base ready to propagate same header fix to libft2 and current.

- Change type: spec-txt
- Paths changed:
  - `42/PDFs/2026-03-12_libft_v16_6.txt`
  - `.github/project-history.md`
  - `.github/tracking/projects/libft/libft-progress.md`
- Tracking docs updated:
  - `.github/project-history.md`
  - `.github/tracking/projects/libft/libft-progress.md`
- Notes:
  - New corrected Libft v16.6 baseline received and saved at
    `42/PDFs/2026-03-12_libft_v16_6.txt`.
  - Diff against previous non-canonical conversion
    confirmed missing normative points in old conversion.
  - Relevant normative deltas identified:
    - explicit prohibition of `restrict` in custom prototypes,
    - explicit prohibition of compiling with `-std=c99`,
    - explicit calloc behavior note for `nmemb == 0 || size == 0`,
    - explicit rule that bonus is evaluated only if mandatory part is perfect.
  - Full revalidation executed for `42/C/libft` against corrected spec:
    - `make fclean && make && make bonus` ✅
    - full tests run in `42/tests/testsLibf` (`make run`) ✅
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
  - `42/tests/tests_get_next_line/README.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `.github/projects-index.md`
  - `.github/project-history.md`
  - `42/tests/tests_get_next_line/README.md`
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
  - `42/tests/tests_get_next_line/README.md`
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
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
  - `.github/project-history.md`
- Tracking docs updated:
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
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
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
- Reorganized workspace structure:
  - moved `libft` to `C/libft`
  - created `42/PDFs`
- Saved official reference text as:
  - `42/PDFs/2026-03-12_libft_v16_6.txt`
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
  - `42/tests/testsLibf/` (manual test programs for libft)
- Route consistency review completed after structure changes under `42/`.
- Updated tracking docs to match current paths:
  - `.github/projects-index.md`
  - `.github/tracking/projects/libft/libft-progress.md`
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
    - `42/PDFs/2026-03-12_libft_v16_6.txt`
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
    - `.github/tracking/projects/libft/libft-progress.md`
    - `.github/tracking/projects/libft/libft-functions.md`
    - `.github/tracking/projects/libft/libft-reference.md`
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
    - `42/PDFs/2026-03-12_ft_printf.txt`
  - referencia base para validacion/correccion:
    - conversiones obligatorias `cspdiuxX%`
    - Makefile con `-Wall -Wextra -Werror` y sin relink
    - uso permitido de `libft`

- Nuevo proyecto detectado en `42/C/`:
  - `42/C/ft_printf/` (estado: in-progress, en revision y correccion)
  - actualizado:
    - `.github/projects-index.md`

- Se habilito tracking dedicado para `ft_printf`:
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`

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
    - `42/PDFs/2026-03-12_ft_printf.txt`
  - se limpiaron referencias de version anterior en tracking:
    - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
    - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
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
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `.github/tracking/projects/libft/libft-functions.md`
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/tracking/projects/libft/libft-reference.md`
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
    - `42/PDFs/2026-03-12_ft_printf.txt`
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
    - `42/C/ft_printf/handle_format_bonus.c`
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
    - `42/C/ft_printf/ft_printf.c`
    - `42/C/ft_printf/handle_format_bonus.c`
    - `42/C/ft_printf/print_decimal.c`
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
    - `42/C/ft_printf/ft_printf.c`
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
      `print_decimal.c` (39), `print_hex.c` (31), `print_binary_bonus.c` (26).
  - docs de tracking sincronizadas a este baseline:
    - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
    - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
    - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
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
    - `42/tests/tests_ft_printf/`
    - `42/tests/tests_ft_printf/README.md`
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
    - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
    - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
    - `.github/tracking/projects/ft_printf/ft_printf-functions.md`

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
  - en `42/tests/tests_ft_printf/` se eliminaron artefactos generados
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
    - agregado ignore de binarios locales en `42/tests/tests_ft_printf/.gitignore`.
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
  - `.github/tracking/projects/libft/libft-progress.md`
  - `.github/project-history.md`
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-functions.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `42/tests/testsLibf/README.md`
  - `42/tests/tests_ft_printf/README.md`

## 2026-03-11

- Cierre definitivo documental de `ft_printf` y sincronizacion de continuidad:
  - se promovio un bloque visible de cierre definitivo en tracking.
  - se archivaron secciones historicas de pendientes para evitar ambiguedad.
  - se cerro handoff explicito Chat2 -> Chat1 con confirmacion final (H-004).
  - se actualizaron estados de carpetas de tests a `completed` con nota de regresion.
- Archivos actualizados:
  - `.github/tracking/projects/ft_printf/ft_printf-progress.md`
  - `.github/tracking/projects/ft_printf/ft_printf-reference.md`
  - `.github/chat-handoff.md`
  - `.github/projects-index.md`
  - `.github/QUICK_REFERENCE.md`
  - `.github/workflow-rules.md`
  - `42/tests/tests_ft_printf/README.md`
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
  - `42/tests/tests_currentLibft/README.md`.
