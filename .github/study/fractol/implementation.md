# fractol Implementation Guide

Guia de lectura de codigo en orden funcional.

## 1. main.c

- inicia estructura app,
- parsea argumentos,
- inicializa recursos,
- configura hooks,
- entra en mlx_loop.

## 2. parse_args.c

- valida cantidad de argumentos,
- selecciona tipo de fractal,
- parsea parametros de julia (re, im).

## 3. init.c

- mlx_init,
- mlx_new_window,
- mlx_new_image y buffer,
- defaults de view y paleta.

Defaults reales actuales:

- view: [-2.0, 2.0] x [-1.6, 1.6]
- max_iter = 80
- palette_shift = 0

Manejo de error relevante:

- si falla ventana o imagen, se llama destroy_and_exit(app, 1)
- toda salida limpia pasa por una sola ruta de cleanup.

## 4. render.c

- doble loop y/x de toda la pantalla,
- mapea pixel a coordenada compleja,
- llama calculo de iteraciones,
- escribe color en buffer,
- pinta imagen en ventana.

## 5. fractal_calc.c

- mandelbrot_iter,
- julia_iter,
- color_from_iter.

Concepto clave:
- en codigo se usa (z.re^2 + z.im^2) <= 4.0; si no se cumple, hay escape.

Colorizacion real:

- r = (iter * 9 + shift) % 255
- g = (iter * 7 + shift * 2) % 255
- b = (iter * 13 + shift * 3) % 255

## 6. events.c

- ESC para cerrar,
- rueda para zoom,
- tecla de paleta,
- expose/redraw.

## 7. utils.c

- parse de double,
- mensajes de uso,
- helpers de conversion.

## Change Log

- 2026-04-16: guia inicial de implementacion de fractol.
- 2026-04-18: precisiones agregadas sobre defaults reales, ruta unica de
	cleanup, condicion exacta de escape y formula de color.
