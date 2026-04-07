# 03 - Errores, Memoria y Buenas Practicas

## Que son segfault, bus error, double free, etc.

- segfault: acceso a memoria invalida (puntero invalido/NULL).
- bus error: acceso no valido por alineacion o direccionamiento.
- double free: liberar dos veces el mismo bloque.
- invalid free: liberar memoria no reservada dinamicamente.

## Como evitarlos

1. Inicializar punteros.
2. Validar entradas.
3. Comprobar retornos de funciones criticas.
4. Definir ownership claro de memoria.
5. No liberar dos veces el mismo recurso.

## Como solucionarlos si aparecen

1. Reproducir caso minimo.
2. Revisar traza y ultimo cambio.
3. Usar valgrind/gdb.
4. Corregir ownership y rutas de error.
5. Reprobar el caso y regresion.

## Como detectarlos

- pruebas funcionales repetibles,
- valgrind,
- ejecucion con entradas invalidas,
- revisiones de rutas de salida temprana.

## Que son fugas de memoria

Memoria reservada con malloc que nunca se libera y queda perdida.

## Como detectarlas a tiempo

1. valgrind en casos cortos y largos,
2. revisar rutas de error,
3. revisar clean-up al finalizar.

## Como evitarlas

1. Definir quien libera cada bloque.
2. Centralizar liberaciones cuando sea posible.
3. Liberar antes de cada return de error.

## Buenas practicas recomendadas

1. Funciones pequenas con responsabilidad unica.
2. Manejo de errores uniforme.
3. Nombres claros para estado y recursos.
4. Validacion temprana de parametros.
5. Tests de sanidad despues de cada cambio.

## Change Log

- 2026-04-05: modulo de errores y memoria.
