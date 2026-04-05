# push_swap Validation Guide

## 1. Orden obligatorio de validacion

1. Validar comportamiento contra subject.
2. Validar memoria y estabilidad.
3. Ejecutar Norminette al final.

Este orden evita cerrar estilo cuando aun hay desvio funcional.

En este modulo la validacion funcional se ejecuta en dos capas:

1. Mandatory (`push_swap`).
2. Bonus (`checker`) solo despues de mandatory estable.

## 2. Build y smoke tests

Desde `42/C/push_swap`:

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

## 3.1 Matriz minima funcional (bonus checker)

Compilacion bonus:

```bash
make bonus
```

Casos base:

```bash
printf "sa\n" | ./checker 2 1
printf "sa\n" | ./checker 1 2
printf "xx\n" | ./checker 2 1
```

Esperado:

- `OK` cuando `a` queda ordenada y `b` vacia.
- `KO` cuando no queda ordenado.
- `Error` en stderr para instruccion invalida.

## 4. Validacion cruzada con checker externo

Si dispones de checker externo:

```bash
ARG="3 2 5 1 4"
./push_swap $ARG | <checker_externo> $ARG
```

Esperado: `OK`.

Nota: ahora el proyecto incluye checker bonus propio; el checker externo sigue
siendo util para contraste durante defensa.

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

## 11. Criterio de "bonus listo"

- `make bonus` genera `checker` sin relink innecesario.
- Rutas `OK/KO/Error` validadas.
- Memoria limpia en rutas principales y de error.
- Norminette en verde incluyendo `*_bonus.c/h`.

## Change Log

- 2026-04-05: añadida capa de validacion bonus (`checker`) y criterio de
	aceptacion separado mandatory/bonus.
- 2026-03-14: guia de validacion mandatory completa con evidencia real
  de build, funcional, benchmark y memoria.
