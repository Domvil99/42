*Este proyecto ha sido creado como parte del curriculo de 42 por saospina.*

## Descripcion

fractol es un explorador de fractales con MiniLibX. En esta fase mandatory
incluye Mandelbrot y Julia, renderizados con imagen en memoria y control de
zoom por rueda del raton.

## Instrucciones

Compilar:

make

Ejecutar Mandelbrot:

./fractol mandelbrot

Ejecutar Julia (ejemplo):

./fractol julia -0.7 0.27015

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./fractol mandelbrot

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./fractol mandelbrot


Controles:

- ESC: cerrar
- Click en la cruz: cerrar
- Rueda del raton: zoom in/out
- C: cambiar paleta

## Recursos

- MiniLibX Linux: minilibx-linux/minilibx-linux
- Subject: 42/PDFs/2026-04-14_fract'ol.txt
- Referencias:
  - https://harm-smits.github.io/42docs/libs/minilibx
  - https://en.wikipedia.org/wiki/Mandelbrot_set
  - https://en.wikipedia.org/wiki/Julia_set

Uso de IA en este proyecto:

- Estructuracion inicial modular de archivos.
- Checklist de validacion tecnica por fases (scope, funcional, memoria y norma).
