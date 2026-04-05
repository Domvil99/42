# Workblock Pending Status

Date: 2026-04-05
Block: Minitalk bonus completion (ACK + UTF-8)

## Repo entrega C (42/C/)

Pending changes:
- `42/C/minitalk/Makefile`
- `42/C/minitalk/README.md`
- `42/C/minitalk/bonus_utils.c`
- `42/C/minitalk/client_bonus.c`
- `42/C/minitalk/minitalk_bonus.h`
- `42/C/minitalk/server_bonus.c`

## Repo workspace Raiz

Pending changes:
- `.github/project-history.md`
- `.github/projects-index.md`
- `.github/reports/workblock-pending-status.md`
- `.github/tracking/projects/minitalk/minitalk-functions.md`
- `.github/tracking/projects/minitalk/minitalk-progress.md`
- `.github/tracking/projects/minitalk/minitalk-reference.md`

## Closure

- Scope: completar bonus separado de `minitalk` con protocolo ACK por bit,
	soporte de bytes UTF-8 y sin regresion en mandatory.
- Validation:
	- build `make` y `make bonus`: OK.
	- smoke bonus real (`server_bonus`/`client_bonus`) con ASCII + UTF-8: OK.
	- tests C portables mandatory (`tests_minitalk`): OK.
	- norminette `*.c` y `*.h`: OK sin `Error:` (solo notices de global state).
- Delivery repo commit: pending.
- Workspace repo commit: pending.

