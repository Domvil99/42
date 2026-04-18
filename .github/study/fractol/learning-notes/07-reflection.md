# 07 - Reflexion

## Parte mas dificil (respuesta modelo)

La parte mas dificil suele ser coordinar matematicas del plano complejo con
interaccion visual fluida. Un cambio pequeno en view bounds afecta todo el
frame y obliga a pensar bien precision y rendimiento.

## Por donde empezar si tuviera que rehacerlo

1. primero parser y validaciones,
2. luego init de MLX + imagen,
3. despues render minimo de Mandelbrot,
4. luego eventos,
5. finalmente paletas y bonus.

## Idea central del proyecto

Fractol no es solo dibujar: es traducir eventos de usuario en cambios
matematicos del plano complejo y volver a renderizar correctamente.

## Guion corto para defensa (45-60s)

"Mi programa parsea argumentos, inicializa MLX y renderiza un fractal con un
bucle por pixel. Cada pixel se mapea al plano complejo y se evalua por escape-
time. Los eventos de teclado/raton modifican la vista o paleta y disparan un
nuevo render. Cierro recursos de forma limpia para evitar fugas."

## Change Log

- 2026-04-16: respuestas iniciales de reflexion y defensa breve.
