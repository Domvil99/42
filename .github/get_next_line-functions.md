# get_next_line Functions Map

## Scope

Mapa funcional del proyecto `42/C/get_next_line` y su variante bonus.

## Mandatory Files and Symbols

- `get_next_line.c`
  - `get_next_line`
  - `extract_line` (static)
  - `update_stash` (static)
  - `read_and_append` (static)
- `get_next_line_utils.c`
  - `ft_strlen`
  - `ft_strchr`
  - `ft_strjoin`
  - `ft_substr`
  - `ft_strdup`

Estado: implementado en el entregable standalone.

## Bonus Files and Symbols

- `get_next_line_bonus.c`
  - `get_next_line`
  - helpers static de flujo bonus por fd
- `get_next_line_utils_bonus.c`
  - helpers de soporte para bonus

Estado: implementado en el entregable standalone.

## API Publica (headers)

- `get_next_line.h`
  - `char *get_next_line(int fd);`
  - utilidades string para ensamblado de linea
- `get_next_line_bonus.h`
  - `char *get_next_line(int fd);`
  - soporte multi-fd con limite `OPEN_MAX`

## Notes

- Este proyecto coexiste como standalone en `42/C/get_next_line` y como modulo
  integrado en `42/C/currentLibft/libft/get_next_line`.
- La base canónica de requisitos para tracking es
  `42/PDFs/2026-03-12_get_next_line.txt`.

## Change Log

- 2026-03-20: tracking inicial generado para cobertura documental completa.
