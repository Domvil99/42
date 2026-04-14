# Workblock Pending Status

Date: 2026-04-15
Block: currentLibft full-contract hardening + replica mandatory alignment

## Repo entrega C (42/C/)

Pending changes:
- `42/C/currentLibft/libft/Makefile`
- `42/C/currentLibft/libft/ft_printf/Makefile`
- `42/C/currentLibft/libft/get_next_line/Makefile`
- `42/C/fract'ol/Makefile`
- `42/C/fract'ol/README.md`
- Makefile y snapshot local de libft del proyecto réplica mandatory

## Repo workspace Raiz

Pending changes:
- `.github/tracking/projects/currentLibft/currentLibft-functions.md`
- `.github/tracking/projects/currentLibft/currentLibft-progress.md`
- `.github/tracking/projects/currentLibft/currentLibft-reference.md`
- `.github/tracking/projects/currentLibft/integration-manifest.md`
- `.github/projects-index.md`
- `.github/QUICK_REFERENCE.md`
- `.github/project-history.md`
- `.github/reports/workblock-pending-status.md`

## Closure

- Scope: aplicar contrato unificado para que currentLibft compile/limpie todo
  el arbol integrado por defecto y alinear proyectos consumidores a ese flujo.
- Validation target:
  - `make`, `make clean`, `make fclean`, `make full` OK en currentLibft/libft.
  - mandatory del proyecto réplica compilando tras `make -C libft full`.
  - política activa sin `chmod` automático en Makefiles.
  - barrida `.md` sin registro explícito de rutas descartadas.
- Delivery repo commit: pending.
- Workspace repo commit: pending.

