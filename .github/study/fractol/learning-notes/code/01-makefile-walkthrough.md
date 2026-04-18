# Code 01 - Makefile Walkthrough

Archivo analizado:
- 42/C/fract'ol/Makefile

## Objetivos

- all -> fractol
- bonus -> fractol_bonus

## Dependencias clave

- LIBFT: compila con `make -C libft full`
- MLX: compila con `make -C minilibx-linux/minilibx-linux`

## Flags importantes

- CFLAGS: -Wall -Wextra -Werror
- MLX_FLAGS: X11 + math + zlib

## Observacion tecnica

El Makefile separa mandatory y bonus por listas de fuentes distintas,
lo cual facilita mantenimiento y validacion independiente.

## Change Log

- 2026-04-16: analisis inicial del Makefile de fractol.
