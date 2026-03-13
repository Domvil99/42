# push_swap Implementation Guide

## 1. Arquitectura Real del Código Actual

Ruta base: `42/C/push_swap/`.

### 1.1 Módulos

- `main.c`: orquestación general.
- `parse.c`, `parse_utils.c`: parsing + validación.
- `stack_build.c`, `stack_utils.c`: construcción y utilidades de stack.
- `ops_*.c`: primitivas del lenguaje de operaciones.
- `sort_small.c`: lógica para tamaños pequeños.
- `sort_radix.c`: estrategia para tamaños grandes.
- `free_utils.c`: utilidades de liberación y error.

### 1.2 Flujo de ejecución

1. `main` llama `setup_stacks`.
2. `parse_numbers` produce array de enteros.
3. `build_stack` crea lista enlazada.
4. `assign_indices` normaliza valores a ranking [0..n-1].
5. `sort_dispatch` selecciona algoritmo.
6. Se liberan `arr`, `a`, `b`.

## 2. Estructura de Datos

```c
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
} t_node;
```

### 2.1 Rol de cada campo

- `value`: entero original de entrada.
- `index`: posición en orden ascendente global.
- `next`: enlace al siguiente nodo.

Beneficio de `index`:

- Radix trabaja sobre rango compacto no negativo.
- Evita complicaciones de signos en ordenación por bits.

## 3. Parsing y Validación

### 3.1 Modos de entrada soportados

- Argumentos separados: `./push_swap 3 2 1`.
- String única: `./push_swap "3 2 1"`.

### 3.2 Validaciones activas

- `is_valid_number`: formato entero opcionalmente con signo.
- `ps_atol`: conversión con control de overflow int.
- `has_duplicates`: rechazo de repetidos.

### 3.3 Política de error

- Si hay fallo: `Error\n` a stderr y salida con código de error.

## 4. Primitivas de Operación

Cada operación tiene protección para stacks vacíos o de tamaño insuficiente.

### 4.1 Swap

- `op_sa`, `op_sb`, `op_ss`.
- Intercambian top 2 cuando aplica.

### 4.2 Push

- `op_pa`, `op_pb`.
- Mueven nodo top de una pila a otra.

### 4.3 Rotate

- `op_ra`, `op_rb`, `op_rr`.
- Primer nodo pasa al final.

### 4.4 Reverse rotate

- `op_rra`, `op_rrb`, `op_rrr`.
- Último nodo pasa al inicio.

## 5. Estrategias Algorítmicas Implementadas

### 5.1 sort_three

Tabla condicional de casos por comparación entre `f`, `s`, `t` (índices).

### 5.2 sort_five

- Encontrar mínimo.
- Elegir rotación óptima (`ra` vs `rra`) según posición.
- Enviar mínimo a `b`.
- Repetir hasta dejar 3 en `a`.
- Ordenar 3 y recuperar `b`.

### 5.3 sort_radix

- Calcular `bits` necesarios para `n - 1`.
- Por cada bit:
  - bit = 1: `ra`.
  - bit = 0: `pb`.
- Restaurar `b` con `pa`.

## 6. Complejidad Realista

- Duplicados: O(n^2) en parse actual.
- Ranking (find_pos lineal por nodo): O(n^2).
- Radix principal: O(n * log n) en iteraciones de bit.

Para `n = 500`, el coste de radix domina y suele ser competitivo.

## 7. Gestión de Memoria

### 7.1 Reservas principales

- Array de enteros (`malloc`).
- Nodos de stack (`new_node`).
- Array temporal para ordenado (`assign_indices`).
- Tabla de tokens de `ft_split` en modo string única.

### 7.2 Liberación

- `free(arr)` en flujo normal y en fallos específicos.
- `free_stack(&a)` y `free_stack(&b)`.
- `free_strtab(split)` tras parse.

## 8. Riesgos Técnicos y Mejora

1. `has_duplicates` O(n^2): puede optimizarse con ordenado previo/hash.
2. `find_pos` lineal por nodo: se puede acelerar con mapeo si se permite.
3. Falta bonus checker en estado actual.
4. Falta regla `bonus` en Makefile actual.

## 9. Checklist de calidad por módulo

### Parsing

- Rechaza vacíos, signos sin dígitos, overflow, repetidos.

### Operaciones

- No rompen punteros en tamaños 0/1.

### Sorting

- Emite solo instrucciones válidas.
- Deja `a` ordenada y `b` vacía.

### Memoria

- Sin leaks en éxito ni en fallo.

## 10. Evidencia Ejecutada (Checkpoint 1)

Fecha: 2026-03-13

Comandos de verificación ejecutados en `42/C/push_swap`:

- Build: `make`.
- Caso válido 2 elementos: `./push_swap 2 1`.
- Caso ya ordenado: `./push_swap 1 2 3`.
- Error por token inválido: `./push_swap 1 a 3`.
- Error por duplicado: `./push_swap 1 2 1`.
- Error por overflow: `./push_swap 2147483648`.
- String única válida: `./push_swap "3 2 1"`.
- String única con duplicado: `./push_swap "10 4 10"`.
- Sin argumentos: `./push_swap`.

Resultados observados:

- Build completado correctamente.
- Comportamiento correcto en casos válidos y en entrada ya ordenada.
- `Error` emitido correctamente en alpha/duplicado/overflow.
- Parse de string única validado tanto en éxito como en rechazo.
- Sin argumentos no genera salida.

## Change Log

- 2026-03-13: mapeo técnico inicial basado en implementación actual.
- 2026-03-13: agregado bloque de evidencia real para Checkpoint 1.
