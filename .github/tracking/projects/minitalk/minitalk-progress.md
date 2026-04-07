# minitalk Progress

## Current Status

Proyecto: `42/C/minitalk`
Estado: completed
Fase activa: mandatory + bonus implementados y validados

## Milestones

1. Spec canonic guardada en `42/PDFs/2026-04-05_minitalk.txt`.
2. Bootstrap del proyecto `42/C/minitalk` completado.
3. Integracion de `libft` desde `42/C/currentLibft/libft` completada.
4. Mandatory `server`/`client` implementado.
5. Bonus separado en `*_bonus.c/h` implementado (ACK + bytes UTF-8).
6. Tests C portables creados en `42/tests/tests_minitalk`.
7. Cadena de build ajustada para compilar toda la `libft` integrada
	(root + `ft_printf` + `get_next_line`, mandatory -> bonus).
8. API interna renombrada de `mt_` a `ft_` para consistencia de naming.

## Quality Gates

### Gate 1: Scope/spec

- Ejecutables obligatorios `server` y `client`: OK.
- Comunicacion exclusivamente con `SIGUSR1` y `SIGUSR2`: OK.
- Bonus separado y no mezclado con obligatorio: OK.

### Gate 2: Functional

- Build obligatorio (`make`): OK.
- Build de `libft` completa (todos los `*.c` -> `*.o`): OK.
- Smoke real servidor/cliente con mensaje: OK.
- Build bonus (`make bonus`): OK.
- Smoke real bonus con ASCII y UTF-8: OK.
- ACK por bit validado en ejecucion real: OK.

### Gate 3: Memory/stability

- Sin cierres inesperados en pruebas smoke obligatorias.
- Corrida formal con sanitizers (`address,undefined`) en flujo real: OK.

### Gate 4: Norminette (final)

- Barrido final `*.c` y `*.h`: OK (sin `Error:`).

## Next Technical Steps

1. Mantener regresion tests y checklist de cierre al siguiente bloque.
