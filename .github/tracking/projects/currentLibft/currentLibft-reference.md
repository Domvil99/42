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

API complementaria disponible por headers integrados:
- `ft_printf.h` (handlers mandatory)
- `ft_printf_bonus.h` (handlers + parsing bonus)
- `get_next_line.h` (entrada + helpers mandatory)
- `get_next_line_bonus.h` (entrada + helpers bonus multi-fd)

Configuracion relevante para reutilizacion:
- get_next_line mandatory: `BUFFER_SIZE=1024`
- get_next_line bonus: `BUFFER_SIZE=42`, `OPEN_MAX=1024`
- Build base libft:
  - `make` => build completo integrado (base + internos)
  - `make clean` / `make fclean` => limpieza completa integrada
  - `make full` => alias explicito de build completo

Politica operativa:
- No usar `chmod` automatico en Makefiles. Si se requiere, ejecutar manualmente
  salvo que el subject lo exija de forma explicita.
- Durante integracion de modulos internos, los `.o` extraidos para empaquetado
  deben vivir solo en temporal aislado y no en la raiz de `libft`.

## Validation Order

1. Scope/spec
2. Functional
3. Memory/stability
4. Norminette final

## Quick Checks

```bash
cd 42/C/currentLibft/libft
make && make clean && make fclean && make full
```

Chequeo recomendado de headers integrados:

```bash
cd 42/C/currentLibft/libft
ls ft_printf/*.h get_next_line/*.h libft*.h
```

## Change Log

- 2026-04-15: agregada regla de ubicacion de objetos internos en empaquetado.
- 2026-04-15: referencia alineada a contrato de build completo por defecto.
- 2026-04-05: ampliada referencia de API integrada y configuraciones runtime.
- 2026-03-20: referencia inicial creada.
