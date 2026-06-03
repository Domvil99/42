# Projects Index

Purpose: central index for all projects under `42/` and their relation with `42/C/libft`.

## Active Projects

| Project | Path | Status | Uses libft | Notes |
|---|---|---|---|---|
| libft | 42/C/libft | completed | base | Core library reused by future C projects |
| ft_printf | 42/C/ft_printf | completed | yes | Standalone deliverable project (coexists by design with integrated copy inside currentLibft); libft mirror synced with libft1 on 2026-03-12 |
| get_next_line | 42/C/get_next_line | completed | no | Standalone deliverable; also integrated into currentLibft as child module |
| push_swap | 42/C/push_swap | completed | yes | Proyecto standalone con estrategias small/chunk/radix |
| minitalk | 42/C/minitalk | completed | yes | Comunicacion cliente-servidor por SIGUSR1/SIGUSR2; mandatory y bonus (ACK + UTF-8) implementados |
| fract'ol | 42/C/fract'ol | completed | yes | Proyecto grafico MiniLibX: build mandatory/bonus, CLI, valgrind CLI y norminette OK; smoke visual interactivo X11 validado |
| minishell | 42/C/minishell | in-progress | yes | Shell implementation with builtins, command execution, pipes and redirections |
| currentLibft | 42/C/currentLibft | in-progress | base | Integrated base: libft + ft_printf + get_next_line under `currentLibft/libft/`; base libft parity synced with libft1 on 2026-03-12 |
| tests | 42/tests | in-progress | no | Contenedor unificado de carpetas de pruebas por proyecto |
| testsLibf | 42/tests/testsLibf | completed | yes | Manual test programs for libft validation (maintained for regression) |
| tests_ft_printf | 42/tests/tests_ft_printf | completed | yes | Manual test harnesses for ft_printf validation (maintained for regression) |
| tests_get_next_line | 42/tests/tests_get_next_line | completed | no | Manual test harnesses for get_next_line validation (maintained for regression) |
| tests_minitalk | 42/tests/tests_minitalk | in-progress | no | Pruebas C portables para validar obligatorio de minitalk en repos propios o de pares |
| tests_currentLibft | 42/tests/tests_currentLibft | in-progress | yes | Integration gate for currentLibft build/link/norminette checks |
| tests_push_swap | 42/tests/tests_push_swap | in-progress | yes | Espacio de pruebas para push_swap |
| tests_fractol | 42/tests/tests_fractol | in-progress | yes | Checklist y pruebas manuales para fract'ol mandatory |
| tests_minishell | 42/tests/tests_minishell | planned | no | Espacio de pruebas para minishell |

## Libft Variants Reference

Para seguimiento tecnico, el workspace mantiene tres variantes activas:

| Alias | Ruta | Proposito | Status |
|---|---|---|---|
| libft1 (base) | 42/C/libft | Proyecto historico, referencia de cierre | completed |
| libft2 (mirror) | 42/C/ft_printf/libft | Mirror integrado en ft_printf | completed |
| current (evolutiva) | 42/C/currentLibft/libft | Base integrada con ft_printf + get_next_line | in-progress |

Regla de sincronizacion: libft1 y libft2 comparten base de headers y
funcionalidad; current replica la base de libft1 e integra modulos hijos.

Regla de bootstrap activa (2026-04-15): cada nuevo proyecto que use libft
debe copiar snapshot local desde `42/C/currentLibft/libft` a
`42/C/<project>/libft` y compilar esa libft local completa antes del target
mandatory del proyecto.

## Update Rules

1. Add one row when a new project directory is created.
2. Keep `Status` as one of: planned, in-progress, paused, completed.
3. Set `Uses libft` to: yes, no, partial, base.
4. If a project depends on old project assets, note it in `Notes`.

## Directory Convention

- Main C projects: `42/C/<project_name>/`
- Per-project tests: `42/tests/tests_<project_name>/`
- Current libft integration tests: `42/tests/tests_currentLibft/` (mandatory gate)
- Shared test folders: `42/tests/<tests_name>/` (example: `42/tests/testsLibf/`)
- Project tracking docs: `.github/tracking/projects/<project>/`
- Study docs: `.github/study/<project>/` and `.github/study/overview.md`
- Governance anchors and workspace indexes: `.github/`
- Incoming source instructions (.txt/.pdf exports): `42/PDFs/`

## Git Convention

- Default delivery repo root: `42/C/`
- Workspace repo root (tracking/config/tooling): `Raiz/`
- New deliverable projects must be created under `42/C/<project_name>/` and
	versioned in the `42/C/` repo by default.
