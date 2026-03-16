# push_swap_mandatory Validation Guide

## 1. Orden obligatorio de validacion

1. Validar comportamiento contra subject.
2. Validar memoria y estabilidad.
3. Ejecutar Norminette al final.

Este orden evita cerrar estilo cuando aun hay desvio funcional.

## 2. Build y smoke tests

Desde `42/C/push_swap_mandatory`:

```bash
make
./push_swap 2 1
./push_swap 3 2 1
./push_swap 1 2 3
```

Esperado:

- Build sin errores.
- Para `2 1`: salida no vacia (`sa`).
- Para `3 2 1`: secuencia valida (`sa` + `rra` observada).
- Para ya ordenado: salida vacia.

## 3. Matriz minima funcional (mandatory)

Casos validos:

```bash
./push_swap 2 1
./push_swap 4 1 5 2 3
./push_swap "3 2 1"
```

Casos invalidos:

```bash
./push_swap 1 a 2
./push_swap 1 1 2
./push_swap 2147483648
./push_swap +
./push_swap ""
```

Esperado en invalidos:

- `Error` en stderr.
- exit code de error.

## 4. Validacion con checker externo

Si dispones de checker externo:

```bash
ARG="3 2 5 1 4"
./push_swap $ARG | ./checker_linux $ARG
```

Esperado: `OK`.

Nota: este proyecto es mandatory-only; checker no vive en este arbol.

## 5. Rendimiento (benchmarks subject)

Referencia de subject:

- 100 numeros: objetivo alto `< 700`.
- 500 numeros: objetivo alto `<= 5500`.

Script corto de muestra:

```bash
ARG100=$(python3 -c "import random;print(' '.join(map(str, random.sample(range(-10000,10000),100))))")
./push_swap $ARG100 | wc -l

ARG500=$(python3 -c "import random;print(' '.join(map(str, random.sample(range(-100000,100000),500))))")
./push_swap $ARG500 | wc -l
```

Evidencia real registrada (2026-03-14):

- `OPS100=594`
- `OPS500=4961`

## 6. Memoria y estabilidad

Comando recomendado:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 1 a 2
```

Resultados esperados:

- `in use at exit: 0 bytes in 0 blocks`
- `ERROR SUMMARY: 0 errors`

Evidencia capturada en exito (2026-03-14):

- 0 bytes in use at exit.
- 0 errors.

## 7. Casos borde obligatorios

- Sin args: `./push_swap` -> salida vacia.
- Ya ordenado: `./push_swap 1 2 3 4` -> salida vacia.
- Reverso: `./push_swap 5 4 3 2 1` -> secuencia valida.
- Negativos y cero: `./push_swap -3 10 0 -1 2`.
- Limites de int: `-2147483648` y `2147483647`.

## 8. Cierre de norma

Desde el proyecto:

```bash
norminette *.c *.h
```

En VS Code tambien puedes usar tareas de check por archivo/proyecto.

## 9. Plantilla de evidencia por ronda

Para cada ronda de validacion guarda:

- fecha
- commit o hash de trabajo
- resultados funcionales
- ops en 100/500
- resumen de memoria
- estado de norminette

## 10. Criterio de "mandatory listo"

Un estado se considera listo cuando se cumple todo:

- Contracto del subject respetado.
- Errores invalidos bien manejados.
- Rendimiento dentro de objetivo de evaluacion.
- Memoria limpia.
- Norminette en verde.

## Change Log

- 2026-03-14: guia de validacion mandatory completa con evidencia real
  de build, funcional, benchmark y memoria.
