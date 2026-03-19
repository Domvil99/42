# push_swap Study Report

## 1. Vision del proyecto

La meta no es solo ordenar enteros, sino hacerlo con un set cerrado de operaciones sobre dos stacks enlazados y con control estricto de errores.

## 2. Alcance exacto de este informe

- Proyecto cubierto: `42/C/push_swap`.
- Alcance del proyecto: `push_swap` (mandatory).
- Cobertura tecnica: parsing, data model, operaciones, dispatch de algoritmos,
  small sort, chunk sort, radix, memoria, build y validacion.
- Cobertura pedagogica: ruta de lectura, preguntas de defensa, trazas manuales,
  errores tipicos y criterios de calidad.

## 3. Subject y reglas obligatorias

Referencia de especificacion:

- `42/PDFs/2026-03-13_push_swap_actualizado.txt`

Reglas que gobiernan mandatory:

- Ejecutable esperado: `push_swap`.
- Operaciones permitidas: `sa sb ss pa pb ra rb rr rra rrb rrr`.
- Sin variables globales.
- Compilacion con `-Wall -Wextra -Werror`.
- Entrada invalida: `Error\n` en stderr.
- Entrada vacia: salida vacia, fin limpio.

## 4. Arquitectura mental completa

Pipeline real implementado:

1. Leer argumentos (`argc/argv`).
2. Parsear a array de int (`parse_numbers`).
3. Validar formato numerico, overflow y duplicados.
4. Construir stack `a` (lista enlazada).
5. Asignar indice normalizado por ranking (`0..n-1`).
6. Elegir algoritmo por tamano (`sort_dispatch`).
7. Emitir instrucciones.
8. Liberar memoria (`arr`, `a`, `b`).

## 5. Contrato de entrada y salida

Entrada soportada:

- Formato multi-arg: `./push_swap 3 2 1`
- Formato string unica: `./push_swap "3 2 1"`

Salida del programa:

- Secuencia de operaciones, una por linea.
- O nada, si ya esta ordenado o no hay datos.
- `Error` por entrada invalida.

## 6. Estrategia de ordenacion por escala

- `n <= 1`: no hacer nada.
- `n == 2`: swap si estan invertidos.
- `n == 3`: `sort_three` con tabla de casos.
- `4 <= n <= 5`: `sort_five` (extraer minimos a `b`, ordenar 3, reintegrar).
- `6 <= n <= 500`: `sort_chunk`.
- `n > 500`: `sort_radix`.

Decision clave: se usa `sort_chunk` en rango medio porque reduce operaciones
respecto a radix puro en este codigo para casos tipicos de 100 y 500.

## 7. Datos y complejidad

Estructura principal:

```c
typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;
```

Resumen de costes en la implementacion actual:

- Duplicados: O(n^2).
- Asignacion de indices: O(n^2) (bubble sort + busqueda lineal por nodo).
- `sort_three` / `sort_five`: coste pequeno y acotado.
- `sort_chunk`: dependiente de distribucion y chunk size.
- `sort_radix`: O(n * bits), con `bits ~= log2(n)`.

## 8. Evidencia real capturada (2026-03-14)

Build:

- `make` en `42/C/push_swap`: OK.

Funcional:

- `./push_swap 2 1` -> `sa`
- `./push_swap 3 2 1` -> `sa` + `rra`
- `./push_swap 1 2 3` -> salida vacia
- `./push_swap 1 a 2` -> `Error`

Rendimiento (muestra unica de referencia):

- 100 enteros aleatorios: `OPS100=594`
- 500 enteros aleatorios: `OPS500=4961`

Memoria:

- Valgrind (caso `3 2 1`):
  - `in use at exit: 0 bytes in 0 blocks`
  - `ERROR SUMMARY: 0 errors`

## 9. Como leer este paquete completo

Orden recomendado para entender todo:

1. `foundations-nodes-lists.md`: base de estructuras, nodos y listas.
2. `push_swap.md` (este archivo): marco global.
3. `implementation.md`: anatomia exacta archivo por archivo.
4. `case-studies.md`: trazas manuales paso a paso.
5. `validation.md`: como verificar funcional, memoria y norma.
6. `defense.md`: como justificar decisiones en oral.
7. `dictionary.md`: glosario de terminos del modulo mandatory.

## 10. Checklist de comprension total

Puedes decir que entiendes el proyecto cuando puedes:

- Explicar por que se normaliza a indices.
- Dibujar mentalmente cada operacion sobre `a` y `b`.
- Justificar por que `sort_dispatch` elige cada estrategia.
- Reproducir al menos una traza de 3, 5, 100 y 500.
- Defender coste y trade-offs sin mirar codigo.
- Probar errores de parsing y leer su salida esperada.

## Change Log

- 2026-03-14: version inicial completa del informe dedicated para
  `push_swap` con evidencia real de build/funcional/rendimiento/memoria.
- 2026-03-16: actualizado orden de lectura para arrancar desde fundamentos de
  nodos/listas antes del analisis de implementacion.
