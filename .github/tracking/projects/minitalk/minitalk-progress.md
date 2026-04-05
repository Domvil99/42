# minitalk Progress

## Current Status

Proyecto: `42/C/minitalk`
Estado: in-progress
Fase activa: obligatorio implementado + validacion completa

## Milestones

1. Spec canonic guardada en `42/PDFs/2026-04-05_minitalk.txt`.
2. Bootstrap del proyecto `42/C/minitalk` completado.
3. Integracion de `libft` desde `42/C/currentLibft/libft` completada.
4. Mandatory `server`/`client` implementado.
5. Skeleton bonus separado en `*_bonus.c/h` implementado.
6. Tests C portables creados en `42/tests/tests_minitalk`.

## Quality Gates

### Gate 1: Scope/spec

- Ejecutables obligatorios `server` y `client`: OK.
- Comunicacion exclusivamente con `SIGUSR1` y `SIGUSR2`: OK.
- Bonus separado y no mezclado con obligatorio: OK (skeleton).

### Gate 2: Functional

- Build obligatorio (`make`): OK.
- Smoke real servidor/cliente con mensaje: OK.
- Build bonus skeleton (`make bonus`): OK.

### Gate 3: Memory/stability

- Sin cierres inesperados en pruebas smoke obligatorias.
- Corrida formal con sanitizers (`address,undefined`) en flujo real: OK.

### Gate 4: Norminette (final)

- Barrido final `*.c` y `*.h`: OK (sin `Error:`).

## Next Technical Steps

1. Preparar commit de entrega en repo `42/C/`.
2. Preparar commit de tracking/spec/tests en repo `Raiz/`.
