# 04 - Fractales y Render

## Como pasa un pixel a un punto complejo

Idea:

- x en [0, WIDTH) se mapea a [min_re, max_re],
- y en [0, HEIGHT) se mapea a [max_im, min_im] (segun eje vertical).

Formula general:

- re = min_re + x * (max_re - min_re) / (WIDTH - 1)
- im = max_im - y * (max_im - min_im) / (HEIGHT - 1)

## Iteracion de Mandelbrot

- z = 0 al inicio,
- repetir z = z^2 + c,
- parar cuando |z| > 2 o iter == max_iter.

## Iteracion de Julia

- z = punto del pixel,
- c = constante dada por usuario,
- misma regla de escape.

## Color por iteraciones

- iter bajo -> color exterior temprano,
- iter alto -> borde/interior,
- max_iter alcanzado -> color interior.

## Por que redibujar frame completo

Al cambiar zoom, centro, paleta o fractal, todos los pixeles pueden cambiar.
Por eso se recalcula todo el buffer.

## Change Log

- 2026-04-16: respuestas iniciales de render y matematica fractal.
