# currentLibft Functions Map

## Scope

Indice funcional consolidado de `42/C/currentLibft/libft`.

## Base libft

- Parte 1: 23 funciones.
- Parte 2: 11 funciones.
- Bonus listas: 9 funciones.
- Total oficial base: 43 funciones.

Headers base:
- `42/C/currentLibft/libft/libft.h`
- `42/C/currentLibft/libft/libft_bonus.h`

## Child Modules Integrated

- `ft_printf`
  - Path: `42/C/currentLibft/libft/ft_printf/`
  - Entry point: `int ft_printf(const char *format, ...)`
  - Estado: completed (integrado)

- `get_next_line`
  - Path: `42/C/currentLibft/libft/get_next_line/`
  - Entry point: `char *get_next_line(int fd)`
  - Estado: completed (integrado)

## Integration Constraints

- No se permite `libft` anidada dentro de modulos hijos.
- La base `currentLibft/libft` mantiene paridad funcional de la libft base
  y agrega modulos integrados en subdirectorios hijos.

## Source of Truth

- `.github/tracking/projects/currentLibft/integration-manifest.md`

## Change Log

- 2026-03-20: tracking inicial generado.
