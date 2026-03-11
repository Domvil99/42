# Projects Index

Purpose: central index for all projects under `42/` and their relation with `42/C/libft`.

## Active Projects

| Project | Path | Status | Uses libft | Notes |
|---|---|---|---|---|
| libft | 42/C/libft | completed | base | Core library reused by future C projects |
| ft_printf | 42/C/ft_printf | completed | yes | Subject audit + hardening + cleanup published (`2415cdf`, `79b2255`, `360f071`) |
| testsLibf | 42/testsLibf | in-progress | yes | Manual test programs for libft validation |
| tests_ft_printf | 42/tests_ft_printf | in-progress | yes | Manual test harnesses for ft_printf validation and regression checks |

## Update Rules

1. Add one row when a new project directory is created.
2. Keep `Status` as one of: planned, in-progress, paused, completed.
3. Set `Uses libft` to: yes, no, partial, base.
4. If a project depends on old project assets, note it in `Notes`.

## Directory Convention

- Main C projects: `42/C/<project_name>/`
- Per-project tests: `42/tests_<project_name>/`
- Current libft integration tests: `42/testsCurrentLibft/` (mandatory gate)
- Shared test folders: `42/<tests_name>/` (example: `42/testsLibf/`)
- Project reference docs: `.github/`
- Incoming source instructions (.txt/.pdf exports): `42/PDFs/`

## Git Convention

- Default delivery repo root: `42/C/`
- Workspace repo root (tracking/config/tooling): `Raiz/`
- New deliverable projects must be created under `42/C/<project_name>/` and
	versioned in the `42/C/` repo by default.
