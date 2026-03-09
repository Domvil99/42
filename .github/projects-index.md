# Projects Index

Purpose: central index for all projects under `42/` and their relation with `42/C/libft`.

## Active Projects

| Project | Path | Status | Uses libft | Notes |
|---|---|---|---|---|
| libft | 42/C/libft | in-progress | base | Core library reused by future C projects |
| testsLibf | 42/testsLibf | in-progress | yes | Manual test programs for libft validation |

## Update Rules

1. Add one row when a new project directory is created.
2. Keep `Status` as one of: planned, in-progress, paused, completed.
3. Set `Uses libft` to: yes, no, partial, base.
4. If a project depends on old project assets, note it in `Notes`.

## Directory Convention

- Main C projects: `42/C/<project_name>/`
- Shared test folders: `42/<tests_name>/` (example: `42/testsLibf/`)
- Project reference docs: `.github/`
- Incoming source instructions (.txt/.pdf exports): `42/PDFs/`
