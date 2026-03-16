# push_swap_mandatory Dictionary

Glosario tecnico del modulo mandatory con ejemplos cortos.

## Entradas

### Stack
- Definicion: estructura LIFO sobre lista enlazada.
- Mini ejemplo: `pb` mueve top de `a` a top de `b`.

### Top
- Definicion: primer nodo de una pila.
- Mini ejemplo: `sa` intercambia top y segundo.

### Operation set
- Definicion: conjunto cerrado de instrucciones permitidas por subject.
- Mini ejemplo: `sa`, `pb`, `ra`, `rra`.

### Normalization by index
- Definicion: mapear cada valor a su ranking ascendente.
- Mini ejemplo: `-5 -> 0`, `7 -> 1`, `30 -> 2`.

### Dispatch
- Definicion: seleccion de estrategia por tamano de entrada.
- Mini ejemplo: `size <= 5` usa `sort_five`.

### Chunk window
- Definicion: rango `current..current+chunk` usado para decidir push/rotate.
- Mini ejemplo: en 100 elementos, chunk inicial es 14.

### Current frontier
- Definicion: indice maximo ya procesado en fase A->B de chunk.
- Mini ejemplo: cuando `(*a)->index <= current`, hace `pb` y `rb`.

### Max recovery
- Definicion: fase B->A que recupera siempre el mayor indice visible.
- Mini ejemplo: buscar max, girar corto (`rb/rrb`) y `pa`.

### Radix pass
- Definicion: una iteracion completa sobre un bit especifico.
- Mini ejemplo: bit 0 separa elementos por paridad del index.

### Invariant
- Definicion: propiedad que debe mantenerse siempre.
- Mini ejemplo: no perder nodos y terminar con `b` vacia.

### Overflow
- Definicion: valor fuera de rango de `int`.
- Mini ejemplo: `2147483648`.

### Duplicate
- Definicion: repeticion de valor en entrada.
- Mini ejemplo: `1 2 1`.

### Teardown
- Definicion: limpieza final de recursos.
- Mini ejemplo: `free(arr)`, `free_stack(&a)`, `free_stack(&b)`.

### Mandatory-only scope
- Definicion: proyecto sin checker bonus ni target `bonus`.
- Mini ejemplo: Makefile de este modulo solo construye `push_swap`.

### Benchmark
- Definicion: medida de operaciones para 100/500 entradas.
- Mini ejemplo: contar lineas con `wc -l`.

## Change Log

- 2026-03-14: glosario inicial especifico para push_swap_mandatory.
