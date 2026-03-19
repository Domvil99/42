# push_swap Defense Guide

## 1. Preguntas tecnicas criticas (con respuesta)

## 1.1 Por que usar dos stacks enlazados

Porque el subject no evalua ordenacion libre, evalua ordenacion bajo un
lenguaje de operaciones limitado. Las dos pilas son el modelo obligatorio.

## 1.2 Por que normalizar a index

`index` compacta el dominio a `0..n-1` y simplifica comparaciones y bitwise.
Sin index, radix y los umbrales del chunk se vuelven menos estables por signo
y magnitud.

## 1.3 Por que dispatch por tamano

No existe un algoritmo unico ideal para todos los rangos.

- Para 2/3/5, tablas cortas minimizan pasos.
- Para 6..500, chunk reduce coste practico en este codigo.
- Para >500, radix mantiene comportamiento predecible por bits.

## 1.4 Como garantizas robustez de parse

La ruta de parse valida:

- formato numerico (`is_valid_number`)
- overflow (`ps_atol`)
- repetidos (`has_duplicates`)

Cualquier fallo retorna error y se imprime `Error`.

## 1.5 Como sabes que no hay fugas

Por rutas de cleanup (`free`, `free_stack`, `free_strtab`) y evidencia con
Valgrind (0 bytes en salida, 0 errores en muestra ejecutada).

## 2. Defensa de decisiones del codigo actual

## 2.1 Decision: usar linked list y no array in-place

Ventaja:

- Push/rotate se expresan naturalmente en nodos y punteros.

Coste:

- Algunas busquedas (posicion/maximo) son lineales.

## 2.2 Decision: chunk size fijo por rango

Ventaja:

- Simplicidad y estabilidad de comportamiento.

Coste:

- No es un ajuste dinamico por distribucion real.

Valor actual:

- `14` para <=100
- `30` para <=500

## 2.3 Decision: bubble para sorted auxiliar

Ventaja:

- Implementacion corta y clara bajo restricciones 42.

Coste:

- O(n^2), aunque aceptable para tamano de entrada del proyecto.

## 3. Preguntas de evaluador para practicar

- Que pasa si entrada es `""`, `"   "`, `+`, `--1`.
- Diferencia semantica entre `ra` y `rra`.
- Como decides entre `rb` y `rrb` al recuperar maximos de `b`.
- Que invariante mantiene radix al final de cada bit.
- Como validar salida con herramientas externas cuando se necesite verificación adicional.

## 4. Mini guion oral (2-3 min)

1. Contexto: ordenar con operaciones limitadas.
2. Modelo: dos stacks + nodo con `value/index`.
3. Pipeline: parse -> build -> index -> dispatch -> cleanup.
4. Algoritmos por rango: small/chunk/radix.
5. Cierre: validacion funcional, memoria limpia y norma final.

## 5. Anti-patrones al defender

- Decir "funciona" sin evidencia.
- No justificar decisiones de diseño y complejidad.
- No saber justificar complejidad.
- Omitir casos invalidos de parse.
- No explicar la razon del `index`.

## 6. Checklist previo a evaluacion

- Puedo explicar cada archivo sin abrir codigo.
- Puedo justificar por que el dispatch corta en 500.
- Puedo trazar a mano un caso de 3 y otro de 5.
- Puedo explicar una pasada de radix por bit.
- Puedo citar evidencia real de rendimiento y memoria.

## Change Log

- 2026-03-14: guia de defensa mandatory dedicada con respuestas,
  trade-offs y guion oral.
