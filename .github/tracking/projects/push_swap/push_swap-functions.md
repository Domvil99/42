# push_swap Functions Map

## Scope

Mapa funcional del proyecto `42/C/push_swap` para seguimiento técnico y estudio.

## 1. Core Flow

- `push_swap.c`
  - `main`
  - `setup_stacks` (static)
  - `sort_dispatch` (static)

Estado: implementado.

## 2. Parsing

- `parse.c`
  - `parse_numbers`
  - `parse_single_string` (static)
  - `fill_array` (static)
  - `has_duplicates` (static)
- `parse_utils.c`
  - `is_valid_number`
  - `ps_atol`

Estado: implementado.

## 3. Stack Construction

- `stack_build.c`
  - `build_stack`
  - `assign_indices`
  - `sort_array` (static)
  - `find_pos` (static)
- `stack_utils.c`
  - `new_node`
  - `add_back_node`
  - `stack_size`
  - `is_sorted_stack`

Estado: implementado.

## 4. Primitive Operations

- `ops_swap.c`: `op_sa`, `op_sb`, `op_ss`
- `ops_push.c`: `op_pa`, `op_pb`
- `ops_rotate.c`: `op_ra`, `op_rb`, `op_rr`
- `ops_reverse_rotate.c`: `op_rra`, `op_rrb`, `op_rrr`

Estado: implementado.

## 5. Sorting Strategies

- `sort_small.c`
  - `sort_three`
  - `sort_five`
  - helpers internos de mínimo
- `sort_radix.c`
  - `sort_radix`

Estado: implementado.

## 6. Error and Free

- `free_utils.c`
  - `print_error`
  - `free_stack`
  - `free_strtab`

Estado: implementado.

## 7. Libft Functions Used (only used)

### 7.1 `ft_split`

- Ubicación de uso: `parse.c`.
- Rol: tokenizar entrada cuando el programa recibe una sola string.
- Contrato esperado:
  - Entrada válida: string + delimitador `' '`.
  - Salida: tabla `char **` terminada en `NULL`.
  - Falla de memoria: devuelve `NULL`.
- Riesgos si falla integración:
  - Tokenización incompleta.
  - Leaks si no se libera la tabla.
- Mitigación aplicada:
  - `free_strtab(split)` en rutas de éxito y error.

### 7.2 `ft_memcpy`

- Ubicación de uso: `stack_build.c`.
- Rol: copiar array de enteros original para ordenar copia y generar índices.
- Contrato esperado:
  - `dst` y `src` válidos.
  - tamaño en bytes correcto: `sizeof(int) * count`.
- Riesgos si se usa mal:
  - Corrupción de memoria por tamaño incorrecto.
- Mitigación aplicada:
  - Reserva exacta de `sorted` y copia con tamaño derivado de `count`.

## 8. Not Used by push_swap

No se documentan funciones de libft que no se usan en este proyecto.

## 9. currentLibft Integration Surface

Estado actual de `42/C/push_swap/libft` alineado con base canónica:

- libft base completa: 43 funciones (23 + 11 + 9 bonus listas).
- `libft_bonus.h` presente y compilado.
- Módulos hijos integrados disponibles en el árbol local:
  - `libft/ft_printf` con mandatory + bonus source files.
  - `libft/get_next_line` con mandatory + bonus source files.

Disponibilidad no implica uso directo en algoritmo `push_swap`; el objetivo es
tener una base reusable completa para proyectos que permitan `libft`.

## 10. Pending Functional Gaps

- Ningún gap funcional abierto registrado en el alcance actual.

## Change Log

- 2026-04-05: actualizado mapa con superficie integrada de currentLibft
  (base completa + módulos hijos con bonus disponibles).
- 2026-03-13: baseline inicial de mapa funcional de push_swap.
