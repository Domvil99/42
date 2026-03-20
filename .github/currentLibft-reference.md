# currentLibft Reference

## Purpose

Base evolutiva reusable para proyectos C en `42/C/`.

## Canonical Structure

- Root project: `42/C/currentLibft/`
- Parent libft: `42/C/currentLibft/libft/`
- Integrated children:
  - `42/C/currentLibft/libft/ft_printf/`
  - `42/C/currentLibft/libft/get_next_line/`

## Rules

- Prohibido: `42/C/currentLibft/ft_printf`
- Prohibido: `42/C/currentLibft/libft/ft_printf/libft`
- La integracion siempre cuelga de la libft padre unica.

## Entry Points

- Base API: `libft.h` y `libft_bonus.h`
- Integrated API:
  - `int ft_printf(const char *format, ...)`
  - `char *get_next_line(int fd)`

## Validation Order

1. Scope/spec
2. Functional
3. Memory/stability
4. Norminette final

## Quick Checks

```bash
cd 42/C/currentLibft
make && make bonus
```

## Change Log

- 2026-03-20: referencia inicial creada.
