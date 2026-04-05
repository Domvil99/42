*This project has been created as part of the 42 curriculum by saospina.*

## Description

`push_swap` es un proyecto de ordenacion en el que el objetivo es
ordenar la pila `a` usando un conjunto limitado de operaciones sobre pilas
(`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`).

El objetivo no es solo ordenar correctamente, sino tambien minimizar la
cantidad de operaciones. Las entradas deben validarse de forma estricta
(tokens invalidos, duplicados y overflow/underflow de enteros deben devolver
`Error` en stderr).

Esta version mandatory compila unicamente el programa `push_swap`.

## Instructions

### 1. Compile

Desde la raiz del proyecto:

```bash
cd 42/C/push_swap
make
```

Reconstruir desde cero:

```bash
make fclean && make
```

### 2. Run

Uso basico:

```bash
./push_swap 2 1 3
./push_swap "3 2 1"
```

Sin argumentos no debe producir salida:

```bash
./push_swap
```

Una entrada invalida debe imprimir `Error` en stderr:

```bash
./push_swap 1 a 2
./push_swap 1 1 2
./push_swap 2147483648
```

### 3. Validate sorting result

Este proyecto mandatory no incluye checker. Puedes validar operaciones con un
checker externo compatible:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Salida esperada: `OK`.

### 4. Benchmark targets (subject updated)

Para el nivel maximo de validacion:

- 100 numeros aleatorios: menos de 700 operaciones.
- 500 numeros aleatorios: no mas de 5500 operaciones.

Ejemplos rapidos de comprobacion:

```bash
ARG=$(python3 -c "import random;print(' '.join(map(str, random.sample(range(-10000,10000),100))))")
./push_swap $ARG | wc -l

ARG=$(python3 -c "import random;print(' '.join(map(str, random.sample(range(-100000,100000),500))))")
./push_swap $ARG | wc -l
```

## Resources

### Classical references

- Subject del proyecto 42 (actualizado): `42/PDFs/2026-03-13_push_swap_actualizado.txt`
- Referencia del lenguaje C: https://en.cppreference.com/w/c
- Documentacion de Valgrind: https://valgrind.org/docs/manual/
- 42 Norminette: https://github.com/42School/norminette

### AI usage transparency

La asistencia de IA se uso para:

- Explicar temas de alta complejidad (estrategia de algoritmo y enfoque de validacion).
- Ayudar a analizar y resolver errores durante desarrollo y pruebas.
- Estructurar checklists de validacion y flujo de revision.

La IA no se uso para saltar restricciones del proyecto, y la implementacion
final, las decisiones de depuracion y los resultados de validacion se
verificaron manualmente.
