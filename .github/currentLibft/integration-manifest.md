# Integration Manifest - currentLibft

Last Updated: 2026-03-20
Consolidation Version: 1.0

## Overview

Consolidated index of modules integrated into `42/C/currentLibft/libft`.

## Module Summary

| Module | Source | Functions | Status | Public Entry Point | Path |
|---|---|---:|---|---|---|
| libft part 1 | 42 base | 23 | completed | `libft.h` API | `42/C/currentLibft/libft/` |
| libft part 2 | 42 base | 11 | completed | `libft.h` API | `42/C/currentLibft/libft/` |
| libft bonus | 42 base | 9 | completed | `libft_bonus.h` API | `42/C/currentLibft/libft/` |
| ft_printf | integrated child | 17 source files | completed | `int ft_printf(const char *format, ...)` | `42/C/currentLibft/libft/ft_printf/` |
| get_next_line | integrated child | 4 source files | completed | `char *get_next_line(int fd)` | `42/C/currentLibft/libft/get_next_line/` |

## Function Count Aggregate

- libft (official): 43 functions total (23 + 11 + 9)
- ft_printf (integrated): 17 source files
- get_next_line (integrated): 4 source files

## Public Entry Points

### libft

- Header: `42/C/currentLibft/libft/libft.h`
- Bonus Header: `42/C/currentLibft/libft/libft_bonus.h`

### ft_printf

- Header: `42/C/currentLibft/libft/ft_printf/ft_printf.h`
- Bonus Header: `42/C/currentLibft/libft/ft_printf/ft_printf_bonus.h`
- Entry: `int ft_printf(const char *format, ...)`

### get_next_line

- Header: `42/C/currentLibft/libft/get_next_line/get_next_line.h`
- Bonus Header: `42/C/currentLibft/libft/get_next_line/get_next_line_bonus.h`
- Entry: `char *get_next_line(int fd)`

## Integration Gate

- Build gate: `make` and `make bonus` in `42/C/currentLibft`
- Module parity gate: base libft files synchronized against `42/C/libft`
- Final style gate: norminette on impacted modules when applicable

## Notes

- Nested child `libft` directories inside integrated modules are forbidden.
- `currentLibft/libft` keeps base parity with `42/C/libft` while preserving
  integrated child modules (`ft_printf`, `get_next_line`).
