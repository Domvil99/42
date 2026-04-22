# 01 - Conceptos Basicos

## Que es fractol en una frase

Es un programa grafico que dibuja fractales (Mandelbrot/Julia) y permite
interactuar con zoom y paletas en tiempo real.

## Que es un fractal

Un fractal es una figura que muestra detalle complejo y patrones repetitivos
cuando haces zoom.

## Diferencia entre Mandelbrot y Julia

- Mandelbrot:
  - cada pixel define c,
  - z empieza en 0.
- Julia:
  - cada pixel define z inicial,
  - c es constante (pasada por argumentos).

## Que es el plano complejo

Es un plano 2D:

- eje horizontal = parte real,
- eje vertical = parte imaginaria.

Cada pixel de pantalla se traduce a un punto de ese plano.

## Que es escape-time

Es contar cuantas iteraciones aguanta un punto antes de escapar.

- Si escapa pronto: color de exterior.
- Si no escapa en max_iter: interior (normalmente negro o color fijo).

## Por que el umbral de escape suele ser 2

En este sistema iterativo, si |z| > 2, el valor crecera sin limite en
iteraciones siguientes.

Nota tecnica del codigo real:

- En implementacion se comprueba (z.re * z.re + z.im * z.im) <= 4.0.
- Es equivalente matematicamente a comprobar |z| <= 2.

## Buenas practicas basicas

1. separar parseo, init, calculo y eventos,
2. evitar logica pesada dentro de hooks,
3. redibujar solo cuando haya cambio real de estado,
4. proteger todos los retornos de MLX.

## Change Log

- 2026-04-16: respuestas basicas iniciales para fractol.
