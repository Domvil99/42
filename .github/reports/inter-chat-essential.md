# Inter-Chat Essential Report

Purpose: central operational report for communication quality between Chat1,
Chat2, and future specialist chats.

## Usage Rules
- Update this file when a communication friction appears, repeats, or is fixed.
- Chat1 owns this report; specialist chats can request additions.
- Keep entries short, actionable, and tied to `Topic ID` / `H-xxx` when possible.

## Current Baseline (2026-03-11)
- Relay file in use: `.github/chat-handoff.md`.
- Mandatory fields active: `Topic`, `From -> To`, `Prerequisite`, `Gate`,
  `Decision`, `Status`, `Task`, `Files`, `Notes`.
- Mandatory ACK active: receiver moves `TODO` to `WIP` with acceptance note.
- Shared themes active via `Shared Topics` and `Topic ID` reuse.

## Active Monitoring
- Handoff latency: time from `TODO` to `WIP` ACK.
- Scope clarity: blocked tasks caused by unclear delegation.
- Closure quality: `DONE/BLOCKED` notes with outcome + next action.
- Theme continuity: correct reuse of `Topic ID` for related tasks.
- Decision quality: every out-of-scope intake closed with `APPROVED` or
    `REJECTED` by Chat1.
- Prerequisite integrity: no implementation in `WIP` while prerequisite/gate
    is pending.

## Open Improvements
| Date | Priority | Source | Topic ID | Need | Proposed action | Status |
|---|---|---|---|---|---|---|
| 2026-03-13 | high | User | T-004 | Evitar inicio de implementacion sin aprobacion previa del `.txt` | Activar gates obligatorios + script de auditoria de prerequisitos | DONE |


## Confirmed Improvements
| Date | Topic ID | Change | Impact | Evidence |
|---|---|---|---|---|
| 2026-03-13 | T-004 | Nuevo flujo de aprobacion/rechazo por Chat1 + estados `WAITING_FOR_PREREQUISITE` y `REVIEW_PENDING` + gate obligatorio antes de `WIP` | Elimina bypass entre chats y evita que implementacion arranque sin prerequisito validado | `.github/chat-handoff.md`, `.github/workflow-rules.md`, `.github/copilot-instructions.md` |
| 2026-03-12 | T-003 | Relay sin copy/paste manual: protocolo operativo de redireccion + handoff formal por Chat1 | Reduce friccion del usuario en cambios de chat y mantiene continuidad sin perder contexto | `.github/chat-handoff.md`, `.github/workflow-rules.md`, `.github/copilot-instructions.md` |
| 2026-03-11 | T-003 | Cambios inesperados atribuidos a validacion legitima de Chat2 y aceptados en continuidad | Reduce falsas detecciones de conflicto y evita bloquear ejecucion por ruido operativo | `.github/chat-handoff.md`, `.github/reports/workblock-pending-status.md` |
| 2026-03-11 | T-003 | Intake canonico de validaciones aplicado en ronda real (H-006) | Integracion consistente de resultados de Chat2 con filtro anti-ruido y decision explicita | `.github/chat-handoff.md`, `.github/reports/inter-chat-essential.md`, `.github/workflow-rules.md` |
| 2026-03-11 | T-003 | Validacion de plantilla viva en ciclo real (H-005) | Flujo `TODO -> WIP(ACK) -> DONE/BLOCKED` consolidado y reutilizable | `.github/chat-handoff.md`, `.github/reports/inter-chat-essential.md` |
| 2026-03-11 | T-003 | Handoff con `Topic ID` + `Shared Topics` + ACK obligatorio | Mayor trazabilidad y menos ambiguedad en delegacion | `.github/chat-handoff.md`, `.github/workflow-rules.md` |

## Requests From Specialist Chats
| Date | Requested by | Topic ID | Request | Decision | Status |
|---|---|---|---|---|---|
| 2026-03-13 | Chat2 | T-006 | Definir politica canonica de traduccion/consolidacion de specs y ejecutar push_swap sin copy/paste | approved by Chat1 | DONE |
| 2026-03-13 | Chat1 | T-004 | Endurecer relay con decision formal Chat1 + gates de prerequisito + auditoria automatica | accepted | DONE |
| 2026-03-12 | Chat2 | T-003 | Establecer mecanismo de traspaso a Chat1 para solicitudes fuera de alcance, sin exigir copy/paste del usuario | accepted | DONE |

## Out-of-Scope Decision Audit
| Date | Handoff ID | Topic ID | Intake by | Chat1 decision | Outcome rule | Evidence |
|---|---|---|---|---|---|---|
| 2026-03-13 | H-008 | T-004 | Chat2 | APPROVED | Traduccion validada por usuario; cierre en `DONE`; desbloqueo de H-009/H-011 | `.github/chat-handoff.md` |
| 2026-03-13 | H-009 | T-004 | Chat1 | APPROVED | `WAITING_FOR_PREREQUISITE` hasta `H-008:DONE` | `.github/chat-handoff.md` |
| 2026-03-13 | H-010 | T-005 | Chat2 | REJECTED | Fuera de alcance; derivar ajuste de reglas a Chat1 | `.github/chat-handoff.md` |
| 2026-03-13 | H-011 | T-005 | Chat1 | APPROVED | No inicia hasta prerequisito `H-008:DONE` | `.github/chat-handoff.md` |
| 2026-03-13 | H-012 | T-006 | Chat2 | APPROVED | Consolidacion y traduccion completadas; validacion de usuario recibida; cierre en `DONE` | `.github/chat-handoff.md`, `.github/reports/pdfs-canonical-inventory.md` |

## Relay Protocol (No Copy/Paste)

1. Si un chat especialista detecta solicitud fuera de alcance, debe:
    - informar limitacion con motivo concreto,
    - proponer solucion practica,
    - emitir redireccion al chat correcto,
    - incluir bloque de contexto minimo reutilizable.
2. Chat1 toma ese bloque y crea/actualiza handoff formal en
    `.github/chat-handoff.md` con `Topic ID`, alcance, criterio de cierre,
    decision (`APPROVED`/`REJECTED`) y estado.
3. Chat1 responde al usuario con siguiente accion directa, sin pedir
    copy/paste manual entre chats.
4. Si la decision es `REJECTED`, reportar motivo corto y siguiente accion para
    tratarlo con Chat1.
5. Si la decision es `APPROVED`, el receptor confirma ACK moviendo a `WIP`
    solo si prerequisito/gate estan desbloqueados.
6. Al cierre, registrar `DONE/BLOCKED` con resultado breve y siguiente accion.
