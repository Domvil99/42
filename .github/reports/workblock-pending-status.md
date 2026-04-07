# Workblock Pending Status

Date: 2026-04-07
Block: Minitalk libft full build + API rename ft_

## Repo entrega C (42/C/)

Pending changes:
- `42/C/minitalk/Makefile`
- `42/C/minitalk/minitalk.h`
- `42/C/minitalk/minitalk_bonus.h`
- `42/C/minitalk/bonus_utils.c`
- `42/C/minitalk/client.c`
- `42/C/minitalk/client_bonus.c`
- `42/C/minitalk/parse_utils.c`
- `42/C/minitalk/server.c`
- `42/C/minitalk/server_bonus.c`
- `42/C/minitalk/signals_utils.c`

## Repo workspace Raiz

Pending changes:
- `.github/project-history.md`
- `.github/reports/workblock-pending-status.md`
- `.github/tracking/projects/minitalk/minitalk-functions.md`
- `.github/tracking/projects/minitalk/minitalk-reference.md`

## Closure

- Scope: corregir build de libft para compilar todo el arbol integrado
	(mandatory -> bonus), renombrar API `mt_` a `ft_` y mantener estabilidad.
- Validation:
	- build `make` y `make bonus`: OK.
	- verificacion de objetos en `libft`: OK (`ALL_C_HAVE_O`).
	- smoke bonus real (`server_bonus`/`client_bonus`) con ASCII + UTF-8: OK.
	- tests C portables mandatory (`tests_minitalk`): OK.
	- norminette `*.c` y `*.h`: OK sin `Error:` (solo notices de global state).
- Delivery repo commit: pending.
- Workspace repo commit: pending.

