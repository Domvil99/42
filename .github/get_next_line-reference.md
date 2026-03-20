# get_next_line Reference

## Deliverable Scope

Mandatory files:
- `get_next_line.c`
- `get_next_line_utils.c`
- `get_next_line.h`

Bonus files:
- `get_next_line_bonus.c`
- `get_next_line_utils_bonus.c`
- `get_next_line_bonus.h`

## Public API

- `char *get_next_line(int fd);`

## Contract

- Devuelve una linea por llamada, incluyendo `\n` cuando exista.
- Devuelve `NULL` al llegar a EOF sin contenido pendiente o ante error.
- Debe preservar residuo entre llamadas sin fugas de memoria.

## Allowed Functions

- `read`
- `malloc`
- `free`

## Forbidden and Constraints

- Sin `libft` externa.
- Sin `lseek`.
- Sin variables globales.
- Bonus: una sola variable estatica con soporte multi-fd.

## Canonical Spec

- `42/PDFs/2026-03-12_get_next_line.txt`

## Change Log

- 2026-03-20: referencia rapida inicial creada.
