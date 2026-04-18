# 05 - Events e Interaccion

## Que eventos maneja fractol

Segun README y estructura del proyecto:

- ESC para salir,
- cierre de ventana (cruz),
- rueda del raton para zoom,
- tecla C para cambio de paleta.

## Como funciona el zoom conceptualmente

1. detectas evento de rueda,
2. calculas factor (zoom in/out),
3. ajustas view bounds alrededor del punto objetivo,
4. relanzas render completo.

## Por que puede sentirse brusco el zoom

- factor de zoom demasiado alto,
- no mantener centro relativo al cursor,
- max_iter fijo sin adaptacion.

## Cambio de paleta

No cambia geometria del fractal; solo cambia el mapeo iteracion -> color.

## Cierre limpio por evento

Tanto ESC como cruz deben terminar en la misma ruta de limpieza para evitar
leaks o comportamientos inconsistentes.

## Change Log

- 2026-04-16: respuestas iniciales de eventos e interaccion.
