# Integration Manifest - currentLibft

Last Updated: 2026-04-15
Consolidation Version: 1.2

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

## API Detail (Integrated Modules)

### ft_printf mandatory header (`ft_printf.h`)

- `int ft_printf(const char *format, ...)`
- `int print_char(int c)`
- `int print_string(char *s)`
- `int print_pointer(unsigned long long ptr)`
- `int print_decimal(int n)`
- `int print_unsigned(unsigned int n)`
- `int print_hex(unsigned int n, const char format)`
- `int print_percent(void)`
- `int ft_putnbr_base(unsigned long long nbr, char *base)`

### ft_printf bonus header (`ft_printf_bonus.h`)

- `int ft_printf(const char *format, ...)`
- `int handle_format(const char *format, va_list args, int *i)`
- `int parse_format(const char *format, t_format *f)`
- `int print_char(va_list args, t_format f)`
- `int print_str(va_list args, t_format f)`
- `int print_int(va_list args, t_format f)`
- `int print_unsigned(va_list args, t_format f)`
- `int print_hex(va_list args, t_format f)`
- `int print_pointer(va_list args, t_format f)`

### get_next_line mandatory header (`get_next_line.h`)

- `char *get_next_line(int fd)`
- `size_t ft_strlen(const char *s)`
- `char *ft_strchr(const char *s, int c)`
- `char *ft_strjoin(char *s1, char *s2)`
- `char *ft_substr(char *s, unsigned int start, size_t len)`
- `char *ft_strdup(const char *s)`

### get_next_line bonus header (`get_next_line_bonus.h`)

- `char *get_next_line(int fd)`
- `char *ft_strjoin(char *s1, char *s2)`
- `char *ft_strchr(const char *s, int c)`
- `size_t ft_strlen(const char *s)`
- `char *ft_substr(char *s, unsigned int start, size_t len)`

### Runtime compile-time constants

- get_next_line mandatory: `BUFFER_SIZE=1024` (default in header)
- get_next_line bonus: `BUFFER_SIZE=42`, `OPEN_MAX=1024`

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

- Build gate:
  - `make`, `make clean`, `make fclean`, `make full` in
    `42/C/currentLibft/libft`
  - `libft.a` consolidada con base + internos (`ft_printf`, `get_next_line`)
- Module parity gate: base libft files synchronized against `42/C/libft`
- Final style gate: norminette on impacted modules when applicable

## Build Policy Snapshot

- `make` ejecuta build integrado completo por defecto.
- `clean` y `fclean` limpian todo el arbol integrado (`.o` y `.a`).
- El empaquetado de modulos internos usa temporal y evita dejar `.o` en la
  raiz de `libft`.
- No se automatiza `chmod` en Makefiles.

## Notes

- Nested child `libft` directories inside integrated modules are forbidden.
- `currentLibft/libft` keeps base parity with `42/C/libft` while preserving
  integrated child modules (`ft_printf`, `get_next_line`).
