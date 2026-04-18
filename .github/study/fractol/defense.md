# fractol Defense Guide

Banco de preguntas para defensa tecnica.

## 1. Preguntas base

1. Que diferencia matematica hay entre Mandelbrot y Julia?
2. Como se mapea un pixel al plano complejo?
3. Que significa escape-time y por que modulo > 2?
4. Como funciona el zoom centrado en cursor?
5. Como controlas cierre limpio de recursos?

## 2. Preguntas de profundidad

1. Por que aumentar max_iter mejora detalle y sube costo?
2. Como evitarias artefactos de color en zonas de borde?
3. Que optimizaciones aplicarias si el render va lento?
4. Que parte del pipeline consume mas CPU y por que?

## 3. Errores comunes en defensa

1. confundir punto inicial de z en Mandelbrot vs Julia,
2. no justificar el umbral de escape,
3. explicar zoom sin mencionar recalculo de view bounds,
4. no diferenciar buffer de imagen y ventana.

## 4. Mini simulacion oral

- 3 preguntas cortas (30-45s),
- 2 preguntas profundas (2 min).

Criterios:
- precision,
- orden de explicacion,
- referencia al codigo real.

## Change Log

- 2026-04-16: guia inicial de defensa para fractol.
