# push_swap Dictionary

Glosario técnico de `push_swap` para repaso rápido y defensa.

## Entradas

### Stack
- Definición: estructura LIFO (Last In, First Out).
- Mini ejemplo: `pb` toma el top de `a` y lo coloca como top de `b`.

### Top
- Definición: primer nodo visible de una pila enlazada.
- Mini ejemplo: en `sa`, se intercambian los dos nodos del top.

### Operation set
- Definición: conjunto cerrado de instrucciones permitidas por el subject.
- Mini ejemplo: `sa`, `pb`, `ra`, `rra`.

### Normalization by index
- Definición: mapear cada valor a su posición ordenada global.
- Mini ejemplo: `-42 -> 0`, `10 -> 1`, `500 -> 2`.

### Radix sort (bitwise)
- Definición: clasificación por bits de menor a mayor peso.
- Mini ejemplo: bit 0 decide entre `pb` (0) y `ra` (1).

### Small sort
- Definición: estrategias manuales para tamaños pequeños (2/3/5).
- Mini ejemplo: para 3 elementos, tabla de casos en `sort_three`.

### Invariant
- Definición: propiedad que debe mantenerse siempre durante el algoritmo.
- Mini ejemplo: no perder nodos al mover entre `a` y `b`.

### Parsing
- Definición: proceso de leer y validar argumentos de entrada.
- Mini ejemplo: aceptar `"3 2 1"` y `3 2 1`.

### Overflow
- Definición: valor fuera del rango representable por `int`.
- Mini ejemplo: `2147483648` debe producir `Error`.

### Duplicate
- Definición: número repetido no permitido por el subject.
- Mini ejemplo: `1 2 3 2`.

### Stability (runtime)
- Definición: ausencia de crashes y comportamientos indefinidos.
- Mini ejemplo: operaciones sobre stack vacía no deben segfaultear.

### Benchmark
- Definición: métrica de rendimiento en número de operaciones.
- Mini ejemplo: contar líneas con `wc -l` para 100/500 entradas.

### Checker
- Definición: programa bonus que verifica secuencia de instrucciones.
- Mini ejemplo: lee stdin y devuelve `OK`, `KO` o `Error`.

### Relink
- Definición: relink innecesario cuando no hubo cambios de dependencias.
- Mini ejemplo: `make` consecutivo no debería reconstruir el binario.

### Teardown
- Definición: fase final de liberación de memoria y cierre limpio.
- Mini ejemplo: `free(arr)`, `free_stack(&a)`, `free_stack(&b)`.

## Change Log

- 2026-03-13: versión inicial de diccionario específico de push_swap.
