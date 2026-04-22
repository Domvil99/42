# fractol Defense Guide

Banco de preguntas para defensa tecnica.

## 1. Preguntas base

1. Que diferencia matematica hay entre Mandelbrot y Julia?
Respuesta: En Mandelbrot, z empieza en 0 y c cambia por cada pixel. En Julia,
z empieza en el pixel y c es una constante fija elegida por argumentos.
2. Como se mapea un pixel al plano complejo?
Respuesta: Se convierte (x, y) del rango de pantalla a los rangos reales e
imaginarios de view (min_re, max_re, min_im, max_im).
3. Que significa escape-time y por que modulo > 2?
Respuesta: Escape-time cuenta iteraciones hasta escapar o llegar a max_iter.
En codigo se usa |z|^2 <= 4.0; cuando falla esa condicion, el punto escapo.
4. Como funciona el zoom centrado en cursor?
Respuesta: Se toma la posicion compleja del cursor como centro, se reduce o
amplia el rango visible y luego se redibuja todo el frame.
5. Como controlas cierre limpio de recursos?
Respuesta: Toda salida pasa por destroy_and_exit: destruir imagen, destruir
ventana, destruir display MLX y liberar mlx.

## 2. Preguntas de profundidad

1. Por que aumentar max_iter mejora detalle y sube costo?
Respuesta: Mejora detalle en bordes porque evalua mas iteraciones por pixel,
pero incrementa costo total de CPU al repetir mas calculos.
2. Como evitarias artefactos de color en zonas de borde?
Respuesta: Usaria paleta continua o smooth coloring y ajustaria max_iter para
evitar bandas bruscas en transiciones de borde.
3. Que optimizaciones aplicarias si el render va lento?
Respuesta: Optimizar inner loop, precalcular valores por frame, evitar
recalculos repetidos y, en version avanzada, paralelizar por filas.
4. Que parte del pipeline consume mas CPU y por que?
Respuesta: El calculo iterativo por pixel en fractal_calc, porque se ejecuta
ancho * alto * max_iter en el peor caso.

## 3. Errores comunes en defensa

1. confundir punto inicial de z en Mandelbrot vs Julia,
Correccion: Mandelbrot usa z0 = 0. Julia usa z0 = pixel y c fijo.
2. no justificar el umbral de escape,
Correccion: explicar que el codigo usa |z|^2 <= 4.0, equivalente a |z| <= 2.
3. explicar zoom sin mencionar recalculo de view bounds,
Correccion: todo zoom correcto requiere recalcular min/max reales e
imaginarios y renderizar de nuevo.
4. no diferenciar buffer de imagen y ventana.
Correccion: primero se escribe en buffer de imagen y luego se vuelca a la
ventana con mlx_put_image_to_window.

## 4. Mini simulacion oral

- 3 preguntas cortas (30-45s),
- 2 preguntas profundas (2 min).

Guion corto recomendado:

1. Corta Mandelbrot vs Julia:
"Mandelbrot usa c variable por pixel y z inicial 0. Julia usa c fija y z
inicial por pixel."

2. Corta mapeo pixel:
"Transformo coordenadas de pantalla a rango complejo usando view bounds
actuales."

3. Corta escape-time:
"Itero z = z^2 + c hasta escape o max_iter; el numero de iteraciones define
el color."

4. Profunda rendimiento:
"El cuello de botella es el loop de iteraciones por pixel; por eso optimizo
inner loop y valores constantes por frame."

5. Profunda estabilidad visual:
"Para evitar bandas, uso transicion de color suave y recalculo consistente en
cada zoom."

Criterios:
- precision,
- orden de explicacion,
- referencia al codigo real.

## Change Log

- 2026-04-16: guia inicial de defensa para fractol.
- 2026-04-18: respuestas agregadas en el mismo archivo para preguntas base,
  profundidad y mini simulacion oral.
