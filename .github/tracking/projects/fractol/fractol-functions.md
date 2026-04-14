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

- Parseo CLI: implemented
- Render Mandelbrot: implemented (pendiente smoke visual en X11)
- Render Julia: implemented (pendiente smoke visual en X11)
- Zoom wheel: implemented (pendiente smoke visual en X11)
- Cierre limpio (ESC/cross): implemented (pendiente smoke visual en X11)
- Colores por profundidad: implemented

## Bonus Status

- Estructura bonus separada (`*_bonus.c` / `*_bonus.h`): implemented
- Build target `make bonus`: implemented
