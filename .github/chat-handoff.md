# Chat Handoff Log

## Purpose
Registro de coordinacion entre Chat1 (admin) y chats especialistas
(Chat2 y futuros Chat3+). Este archivo permite pasar contexto, tareas,
bloqueos y resultados sin perder continuidad.

## Status
- `TODO`: tarea registrada, aun no iniciada.
- `WIP`: tarea en ejecucion por el chat asignado.
- `BLOCKED`: bloqueada por dependencia o fuera de alcance.
- `DONE`: completada y validada por el chat ejecutor.
- `DEFERRED`: aplazada por prioridad.

## Entry Template
| Date | ID | From -> To | Status | Task | Files | Notes |
|---|---|---|---|---|---|---|
| YYYY-MM-DD | H-000 | Chat1 -> Chat2 | TODO | Short action | `path/a`, `path/b` | Context + success criteria |

## Active Handoffs
| Date | ID | From -> To | Status | Task | Files | Notes |
|---|---|---|---|---|---|---|
| 2026-03-11 | H-003 | Chat2 -> Chat1 | TODO | Auditoria de migracion a nueva base `ft_printf_new_base` antes de switch en `42/C/ft_printf` | `42/C/ft_printf_new_base/`, `42/C/ft_printf/`, `.github/project-history.md`, `.github/ft_printf-progress.md` | Revisar estrategia por diff, riesgos de tracking y criterio de cierre; incluir validacion del directorio de pruebas `42/tests_ft_printf/`. |

## Closed Handoffs
| Date | ID | From -> To | Status | Task | Files | Notes |
|---|---|---|---|---|---|---|
| 2026-03-11 | H-000 | Chat1 -> Chat2 | DONE | Implementar base de automatizacion Norminette | `.vscode/tasks.json`, `.vscode/keybindings.json`, `.tools/normi-autofix.sh` | Flujo operativo activo con filtro de `INVALID_HEADER` |
| 2026-03-11 | H-001 | Chat1 -> Chat2 | DONE | Validar optimizacion Norminette en `print_hex_bonus.c` | `42/C/ft_printf/print_hex_bonus.c`, `.vscode/tasks.json`, `.tools/normi-autofix.sh` | Resultado reportado: solo `INVALID_HEADER` en norminette, `make bonus` OK, comparativa bonus sin diffs |
| 2026-03-11 | H-002 | Chat1 -> Chat2 | DONE | Revalidar baseline de Norminette y actualizar tracking `.md` | `42/C/ft_printf/print_hex_bonus.c`, `.github/ft_printf-functions.md`, `.github/ft_printf-progress.md`, `.github/ft_printf-reference.md`, `.github/project-history.md` | Verificado: `print_hex_bonus.c` solo `INVALID_HEADER`, build `make`/`make bonus` OK, deuda accionable actual 286 |

## Operating Rules
1. Chat1 crea y prioriza entradas; chats especialistas actualizan progreso.
2. Cada cambio de estado debe mantener una nota breve accionable.
3. Si una tarea esta fuera de alcance, marcar `BLOCKED` con motivo y
   redireccion explicita al chat correcto.
4. Al cerrar una tarea, mover o reflejar el estado final en `Closed Handoffs`.
5. Este archivo es el puente oficial de coordinacion inter-chat del workspace.