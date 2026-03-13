# push_swap Case Studies

## 1. Caso básico: 2 números

Entrada:

```text
2 1
```

Ejecución esperada:

- Detecta `size == 2`.
- Compara índices.
- Emite `sa`.

Ejecución verificada (2026-03-13):

- Salida observada: `sa`.

## 2. Caso 3 números (reverso)

Entrada:

```text
3 2 1
```

Trazado conceptual:

1. Índices esperados: 2, 1, 0.
2. En `sort_three`: cae en caso `f > s && s > t`.
3. Emite `sa` + `rra`.
4. Resultado ordenado ascendente.

## 3. Caso 5 números

Entrada:

```text
4 1 5 2 3
```

Trazado conceptual:

1. Buscar mínimo y acercarlo al top con `ra` o `rra`.
2. `pb` para enviarlo a `b`.
3. Repetir hasta dejar 3 en `a`.
4. Ordenar 3 con `sort_three`.
5. `pa` hasta vaciar `b`.

## 4. Caso radix pequeño

Entrada:

```text
7 3 5 1 4 2 6 0
```

Trazado por bit 0:

- Bit 0 = 0 -> `pb`.
- Bit 0 = 1 -> `ra`.
- Al final del ciclo, `pa` hasta vaciar `b`.

Trazado por bits siguientes:

- Repetir para bit 1, bit 2...
- Invariante: tras cada bit, todos los elementos vuelven a `a`.

## 5. Caso inválido crítico

Entrada:

```text
1 2 2147483648
```

Resultado esperado:

- `ps_atol` marca overflow.
- Se imprime `Error` en stderr.
- No se emiten operaciones.

Ejecución verificada (2026-03-13):

- Salida observada: `Error`.

## 6. Caso de duplicados ocultos en string única

Entrada:

```text
"10 4 10"
```

Resultado esperado:

- `ft_split` tokeniza.
- `has_duplicates` detecta repetido.
- `Error`.

Ejecución verificada (2026-03-13):

- Salida observada: `Error`.

## 7. Caso ya ordenado

Entrada:

```text
1 2 3 4 5
```

Resultado esperado:

- `is_sorted_stack` devuelve verdadero.
- No se imprime ninguna operación.

Ejecución verificada (2026-03-13):

- Salida observada: 0 bytes.

## 8. Caso de stress para benchmark

Entrada:

- 100 y 500 enteros aleatorios sin repetición.

Objetivo:

- Medir `wc -l` sobre salida.
- Registrar si cumple límites de evaluación del subject.

## Change Log

- 2026-03-13: casos iniciales para estudio guiado y trazas manuales.
- 2026-03-13: agregadas verificaciones ejecutadas para casos 2, 5, 6 y 7.
