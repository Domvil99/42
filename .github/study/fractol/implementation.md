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
- si modulo(z) > 2, se considera escape.

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
