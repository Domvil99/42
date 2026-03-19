# push_swap Case Studies

## 1. Caso 2 numeros

Entrada:

```text
2 1
```

Flujo:

1. `size == 2`.
2. `index(top) > index(next)`.
3. `op_sa`.

Salida observada:

```text
sa
```

## 2. Caso 3 numeros en reverso

Entrada:

```text
3 2 1
```

Normalizacion esperada:

- `3 -> 2`
- `2 -> 1`
- `1 -> 0`

Topologia inicial en `a`:

- `2 1 0`

Regla de `sort_three` que aplica:

- `f > s && s > t`

Secuencia:

1. `sa`
2. `rra`

Salida observada:

```text
sa
rra
```

Estado final:

- `a`: `0 1 2` (ordenado)
- `b`: vacia

## 3. Caso 5 numeros (traza manual completa)

Entrada:

```text
4 1 5 2 3
```

Indices:

- `4->3, 1->0, 5->4, 2->1, 3->2`
- estado inicial `a`: `3 0 4 1 2`

Paso A: extraer minimos hasta dejar 3 nodos

1. minimo actual `0` en posicion 1 (size 5) -> conviene `ra` una vez.
2. `pb` manda `0` a `b`.
3. nuevo minimo `1` en `a` (segun estado) -> rotar corto y `pb`.

Paso B: ordenar trio restante en `a` con `sort_three`.

Paso C: reintegrar `b` con `pa` dos veces.

Invariante:

- Al terminar, `b` vacia y `a` ascendente por `index`.

## 4. Caso 100 numeros (comportamiento de chunk)

Contexto:

- En este rango se ejecuta `sort_chunk`.
- `chunk_size = 14`.

Fase 1 (A->B):

- Se hace barrido por ventana `current..current+chunk`.
- Muy pequenos (`<= current`) se empujan y luego `rb` para enterrarlos.
- Ventana media (`<= current+chunk`) se empuja directo.
- Fuera de ventana: `ra` para buscar candidato.

Fase 2 (B->A):

- Se recupera siempre el maximo de `b`.
- Se elige `rb` o `rrb` por menor distancia.
- `pa` reconstruye `a` en orden.

Muestra real (2026-03-14):

- `OPS100=594`.

Lectura tecnica:

- Cumple objetivo alto de subject (<700).
- Indica que chunk para 100 esta bien calibrado en esta version.

## 5. Caso 500 numeros (comportamiento de chunk)

Contexto:

- Tambien ejecuta `sort_chunk` por el corte `<=500`.
- `chunk_size = 30`.

Efecto esperado:

- Mas fases que en 100.
- Coste mayor en rotaciones de busqueda y recuperacion de maximos.

Muestra real (2026-03-14):

- `OPS500=4961`.

Lectura tecnica:

- Cumple objetivo alto de subject (<=5500).
- Margen razonable para variaciones de muestra.

## 6. Caso invalido por overflow

Entrada:

```text
2147483648
```

Flujo:

1. `is_valid_number` la acepta lexicalmente.
2. `ps_atol` detecta overflow contra `INT_MAX`.
3. Parse falla y se imprime `Error`.

Resultado esperado:

- Sin instrucciones de sort.
- Error controlado.

## 7. Caso invalido por token no numerico

Entrada:

```text
1 a 2
```

Flujo:

1. `is_valid_number("a") == 0`.
2. `fill_array` retorna -1.
3. setup imprime `Error`.

Salida observada:

```text
Error
```

## 8. Caso ya ordenado

Entrada:

```text
1 2 3
```

Flujo:

1. `is_sorted_stack(a) == 1`.
2. dispatch retorna sin operaciones.

Salida observada:

- vacia.

## 9. Caso memoria (estabilidad)

Comando:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
```

Resumen observado:

- 0 bytes in use at exit.
- 0 errors.

## 10. Mini ejercicios de repaso activo

- Traza a mano `5 1 4 2 3` indicando cada op.
- Explica por que en chunk se hace `pb + rb` para indices pequenos.
- Describe una pasada completa de bit 0 en radix.
- Justifica por que `find_pos_of_index` no rompe si no encuentra target.

## Change Log

- 2026-03-14: casos mandatory completos con trazas de 2/3/5,
  comportamiento de 100/500, errores y memoria.
