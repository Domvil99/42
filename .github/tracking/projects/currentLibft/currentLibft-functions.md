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
  - Source files: 17
  - Mandatory files: `ft_printf.c`, `print_char.c`, `print_string.c`,
    `print_pointer.c`, `print_decimal.c`, `print_unsigned.c`, `print_hex.c`,
    `utils.c`
  - Bonus files: `ft_printf_bonus.c`, `handle_format_bonus.c`,
    `parse_format_bonus.c`, `print_char_bonus.c`, `print_str_bonus.c`,
    `print_int_bonus.c`, `print_unsigned_bonus.c`, `print_hex_bonus.c`,
    `print_pointer_bonus.c`
  - Estado: completed (integrado)

- `get_next_line`
  - Path: `42/C/currentLibft/libft/get_next_line/`
  - Entry point: `char *get_next_line(int fd)`
  - Source files: 4
  - Mandatory files: `get_next_line.c`, `get_next_line_utils.c`
  - Bonus files: `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`
  - Header constants:
    - mandatory: `BUFFER_SIZE=1024`
    - bonus: `BUFFER_SIZE=42`, `OPEN_MAX=1024`
  - Estado: completed (integrado)

## Integration Constraints

- No se permite `libft` anidada dentro de modulos hijos.
- La base `currentLibft/libft` mantiene paridad funcional de la libft base
  y agrega modulos integrados en subdirectorios hijos.

## Build Contract (2026-04-15)

- `make` en `currentLibft/libft` ejecuta build integrado completo.
- Build completo = base mandatory + base bonus + internos (`ft_printf` y
  `get_next_line`) mandatory + bonus + empaquetado en una sola `libft.a`.
- `make clean` y `make fclean` ejecutan limpieza completa y eliminan residuos
  `.o` y `.a` del arbol integrado.
- El empaquetado de internos usa temporal aislado (`.pack_tmp`) para evitar
  generar `.o` de modulos internos en la raiz de `libft`.
- No se automatiza `chmod` en Makefiles; si se necesita, se ejecuta manualmente
  salvo exigencia explicita del subject.

## Source of Truth

- `.github/tracking/projects/currentLibft/integration-manifest.md`

## Change Log

- 2026-04-15: corregido `pack_internal` para mantener objetos internos fuera
  de la raiz de `libft`.
- 2026-04-15: contrato de build/clean unificado en `make/clean/fclean/full`.
- 2026-04-05: ampliado detalle de fuentes/APIs integradas para reutilizacion.
- 2026-03-20: tracking inicial generado.
