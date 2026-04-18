# fractol Validation Guide

Orden recomendado:

1. comportamiento segun subject,
2. estabilidad/memoria,
3. norma al cierre.

## 1. Build

- make
- make bonus

Esperado:
- fractol y fractol_bonus generados.

## 2. Ejecucion basica

- ./fractol mandelbrot
- ./fractol julia -0.7 0.27015

Esperado:
- ventana abre,
- render visible,
- sin cierre inesperado.

## 3. Controles

- ESC cierra limpio,
- cruz de ventana cierra limpio,
- rueda aplica zoom,
- tecla C rota paleta.

## 4. Robustez de argumentos

Casos invalidos:
- sin args,
- fractal no soportado,
- julia sin 2 parametros,
- numeros mal formados.

Esperado:
- mensaje de uso/error,
- salida controlada.

## 5. Memoria y recursos

- valgrind en ejecuciones cortas,
- comprobar liberacion de imagen/ventana/contexto,
- verificar ausencia de leaks propios.

## 6. Norma

- ejecutar norminette en .c y .h al final.

## Change Log

- 2026-04-16: guia inicial de validacion para fractol.
