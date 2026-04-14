# fractol Functions

## Scope

Proyecto grafico mandatory con MiniLibX para exploracion de fractales.
Incluye Mandelbrot y Julia, zoom por rueda y cierre limpio.

## Modules

- fractol.h: tipos, constantes y prototipos.
- main.c: entrada y registro de eventos.
- init.c: inicializacion grafica y cleanup.
- parse_args.c: parseo CLI de mandelbrot/julia.
- fractal_calc.c: iteraciones de Mandelbrot y Julia.
- render.c: dibujo por imagen y zoom del viewport.
- events.c: handlers de teclado/raton/close/expose.
- utils.c: utilidades de parseo numerico y mensaje de uso.

## Mandatory Status

- Parseo CLI: in-progress
- Render Mandelbrot: in-progress
- Render Julia: in-progress
- Zoom wheel: in-progress
- Cierre limpio (ESC/cross): in-progress
- Colores por profundidad: in-progress
