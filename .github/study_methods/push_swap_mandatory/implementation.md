# push_swap_mandatory Implementation Guide

## 1. Mapa real de archivos

Ruta base del modulo:

- `42/C/push_swap_mandatory`

Archivos y rol:

- `push_swap.c`: entrypoint, setup y dispatch.
- `push_swap.h`: modelo de datos y prototipos.
- `parse.c`: parsing en dos formatos + deteccion de duplicados.
- `parse_utils.c`: validez lexical y conversion con control de overflow.
- `stack_build.c`: build de lista y asignacion de indices.
- `stack_utils.c`: utilidades basicas de lista/stack.
- `ops_swap.c`: `sa/sb/ss`.
- `ops_push.c`: `pa/pb`.
- `ops_rotate.c`: `ra/rb/rr`.
- `ops_reverse_rotate.c`: `rra/rrb/rrr`.
- `sort_small.c`: `sort_three` y `sort_five`.
- `sort_chunk.c`: estrategia por chunks para tamano medio.
- `sort_radix.c`: estrategia bitwise para tamano grande.
- `free_utils.c`: manejo de errores y liberacion.
- `Makefile`: build mandatory-only + dependencia `libft/libft.a`.

## 2. Flujo de control exacto

### 2.1 main

`main` inicializa:

- `a = NULL`
- `b = NULL`
- `arr = NULL`

Luego ejecuta `setup_stacks` y segun retorno:

- `< 0`: error, return 1.
- `== 0`: no trabajo (0 o 1 elemento), return 0.
- `> 0`: ejecuta sort + cleanup final.

### 2.2 setup_stacks

Secuencia:

1. `parse_numbers(argc, argv, &arr)`.
2. Si parse falla (`<0`), imprime `Error`.
3. Si count `<=1`, libera `arr` y termina limpio.
4. `build_stack(arr, count)`.
5. `assign_indices(a, arr, count)`.
6. Si falla build/index, libera y reporta error.

### 2.3 sort_dispatch

Evalua `size = stack_size(*a)` y `is_sorted_stack(*a)`.

Branching:

- `size <= 1` o ya ordenado: return.
- `size == 2`: posible `op_sa`.
- `size == 3`: `sort_three`.
- `size <= 5`: `sort_five`.
- `size <= 500`: `sort_chunk`.
- else: `sort_radix`.

## 3. Parsing completo y validacion

## 3.1 parse_numbers

Soporta dos modos:

- `argc == 2`: `parse_single_string(argv[1], out)`.
- `argc > 2`: usa `&argv[1]` como tabla de tokens.

Si `argc == 1`, retorna 0 y no hay salida.

## 3.2 parse_single_string

Pasos:

1. Rechaza string nula o vacia.
2. Tokeniza con `ft_split(arg, ' ')`.
3. Cuenta tokens.
4. Reserva `arr`.
5. Llama `fill_array`.
6. Libera split siempre.

Control de errores consistente:

- Si falla split/reserva/validacion, retorna -1 y limpia memoria.

## 3.3 fill_array

Por cada token:

1. `is_valid_number` (solo signo opcional + digitos).
2. `ps_atol` con flag `ok`.
3. Guarda en `arr`.

Finaliza con `has_duplicates(arr, i)`.

## 3.4 parse_utils

- `is_valid_number`: rechaza `+`, `-`, vacios y alpha mix.
- `ps_atol`: acumula en `long`, revisa overflow en cada paso.
- `is_overflow`: compara contra `INT_MAX/INT_MIN` segun signo.

## 4. Data model e indexacion

## 4.1 value e index

Cada nodo mantiene:

- `value`: entero original.
- `index`: posicion en orden total ascendente.

Beneficio: el algoritmo trabaja con valores compactos y no negativos,
perfecto para logica bitwise.

## 4.2 assign_indices

Pasos exactos:

1. Reserva `sorted[count]`.
2. Copia `arr` con `ft_memcpy`.
3. Ordena `sorted` con bubble sort (`sort_array`).
4. Para cada nodo de `a`, busca su posicion (`find_pos`).
5. Asigna `tmp->index`.

Si algo falla, retorna 0 para que caller maneje cleanup.

## 5. Operaciones primitivas

Todas tienen bandera `print` para reutilizacion futura.

- `op_sa/op_sb/op_ss`: swap del top.
- `op_pa/op_pb`: mover top entre pilas.
- `op_ra/op_rb/op_rr`: rotate (head -> tail).
- `op_rra/op_rrb/op_rrr`: reverse rotate (tail -> head).

Todas validan estructura antes de tocar punteros.

## 6. sort_small.c

## 6.1 sort_three

Trabaja con `f,s,t` (indices de top, segundo, tercero) y cubre
las 5 configuraciones no ordenadas.

Patrones usados:

- `sa`
- `sa + rra`
- `ra`
- `sa + ra`
- `rra`

## 6.2 sort_five

Estrategia:

1. Mientras size `> 3`, mover minimo de `a` a `b`.
2. Para mover minimo, calcula posicion y elige `ra` o `rra` segun
   distancia minima al top.
3. Ordena los 3 restantes con `sort_three`.
4. Reintegra desde `b` con `pa`.

## 7. sort_chunk.c (6..500)

## 7.1 choose_chunk_size

Regla actual:

- `<=100` -> 14
- `<=500` -> 30
- `>500` -> 60

En mandatory, el dispatcher usa chunk hasta 500.

## 7.2 fase A->B por ventana

Variables:

- `chunk`: ventana actual.
- `current`: frontera de indices ya tratados.

Si `(*a)->index <= current`:

- `pb`, luego `rb` para dejar pequenos abajo en `b`.

Si `<= current + chunk`:

- `pb` y aumenta frontera.

Si no entra en ventana:

- `ra` para buscar candidato.

## 7.3 fase B->A ordenada

`push_back_sorted` repite:

1. Detecta max de `b`.
2. Calcula posicion.
3. Elige `rb` o `rrb` segun distancia minima.
4. Ejecuta `pa`.

Resultado: `a` termina en orden ascendente por indices.

## 8. sort_radix.c (>500)

## 8.1 calculo de bits

`bits` se calcula con:

- while `((size - 1) >> bits)` -> `bits++`

## 8.2 pasada por bit i

Para cada elemento de `a`:

- Si bit i es 1: `ra`.
- Si bit i es 0: `pb`.

Al final del bit:

- vaciar `b` con `pa`.

Despues del ultimo bit, `a` queda ordenada.

## 9. Gestion de memoria

Reservas principales:

- `arr` (parse).
- nodos `t_node`.
- `sorted` para indexacion.
- tabla de tokens de `ft_split`.

Liberaciones:

- `free(arr)` en salida normal y rutas tempranas.
- `free_stack(&a)` / `free_stack(&b)`.
- `free_strtab(split)`.

Evidencia de estabilidad (2026-03-14):

- Valgrind en `./push_swap 3 2 1` sin leaks ni invalid access.

## 10. Makefile mandatory-only

Puntos importantes:

- `NAME = push_swap`.
- Sin target `bonus`.
- Linka con `libft/libft.a`.
- `clean/fclean` propagan a `libft`.
- `%.o` depende de `push_swap.h`.

## 11. Trade-offs reales de esta implementacion

Fortalezas:

- Codigo modular y legible.
- Manejo de errores consistente.
- Buen rendimiento practico en 100 y 500.

Costes aceptados:

- Duplicados O(n^2).
- Indexacion O(n^2).
- `sort_chunk` usa varias rotaciones, sensible a distribucion.

## Change Log

- 2026-03-14: guia de implementacion mandatory completa y trazable,
  alineada con los archivos reales del proyecto.
