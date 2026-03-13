# push_swap Validation Guide

## 1. Estrategia de Validación (Orden obligatorio)

1. Validar comportamiento contra subject.
2. Validar memoria/estabilidad.
3. Ejecutar Norminette al final.

## 2. Tests Funcionales Base

### 2.1 Sin argumentos

```bash
./push_swap
```

Esperado: sin salida.

### 2.2 Casos mínimos

```bash
./push_swap 2 1
./push_swap 2 1 3
./push_swap 3 2 1
```

Esperado: salida de instrucciones válidas y orden final correcto.

### 2.3 Entradas inválidas

```bash
./push_swap 1 a 3
./push_swap 1 1 2
./push_swap 2147483648
./push_swap +
```

Esperado: `Error` en stderr.

## 3. Validación con checker externo (mandatory)

Si tienes `checker_OS`:

```bash
ARG="3 2 5 1 4"
./push_swap $ARG | ./checker_OS $ARG
```

Esperado: `OK`.

## 4. Benchmarks de rendimiento

### 4.1 100 números

```bash
ARG=$(python3 -c "import random;print(' '.join(map(str, random.sample(range(-10000,10000),100))))")
./push_swap $ARG | wc -l
```

Objetivo de referencia del subject: < 700.

### 4.2 500 números

```bash
ARG=$(python3 -c "import random;print(' '.join(map(str, random.sample(range(-100000,100000),500))))")
./push_swap $ARG | wc -l
```

Objetivo de referencia del subject: <= 5500.

## 5. Validación de memoria y estabilidad

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 a 2
```

Esperado: sin leaks, sin invalid reads/writes.

## 6. Norminette (cierre)

```bash
norminette *.c *.h
```

En VS Code puedes usar:

- Task `Normi Autofix: Active File`
- Task `Normi Check: Project All`

## 7. Casos límite obligatorios

1. Ya ordenado: `./push_swap 1 2 3 4`.
2. Reverso total: `./push_swap 5 4 3 2 1`.
3. Mixto con negativos: `./push_swap -3 10 0 -1 2`.
4. Cifra extrema válida: `INT_MIN`, `INT_MAX`.
5. String única con múltiples espacios.

## 8. Validación del bonus checker (proyecto push_swap)

Nota de alcance:

- `42/C/push_swap` incluye checker bonus.
- `42/C/push_swap_mandatory` es mandatory-only y no debe incluir checker.

### 8.1 Flujo válido

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Esperado: `OK`.

### 8.2 Instrucción inválida

```bash
echo "xx" | ./checker 1 2 3
```

Esperado: `Error`.

## 9. Matriz de evidencia recomendada

Guardar por iteración:

- Commit/hash.
- Resultado funcional (OK/KO/Error).
- Conteo de operaciones 100/500.
- Resultado valgrind/asan.
- Resultado norminette.

## Change Log

- 2026-03-13: guía inicial de validación funcional, memoria y rendimiento.
- 2026-03-13: actualización de alcance para bonus activo en `push_swap` y variante `push_swap_mandatory`.
