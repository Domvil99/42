# Global Study Dictionary

Objetivo: unificar terminos transversales de los proyectos `libft`,
`ft_printf`, `get_next_line` y `currentLibft`.

## Formato recomendado

- Termino
- Definicion
- Mini ejemplo de uso

## Entradas

### API contract
- Definicion: acuerdo explicito de parametros, retorno y efectos laterales.
- Mini ejemplo: `ft_split` debe devolver `NULL` si falla una reserva y liberar
  memoria parcial antes de salir.

### Undefined behavior
- Definicion: comportamiento no definido por el estandar de C.
- Mini ejemplo: leer fuera de limites de un buffer en una copia de memoria.

### Leak
- Definicion: memoria reservada que ya no tiene referencia util para liberarse.
- Mini ejemplo: en `get_next_line`, reasignar `stash` sin liberar el bloque
  previo.

### Segmentation fault
- Definicion: acceso invalido a memoria protegido por el sistema.
- Mini ejemplo: desreferenciar un puntero `NULL` en una funcion auxiliar.

### Static helper
- Definicion: funcion auxiliar limitada al archivo actual (`static`).
- Mini ejemplo: parser interno en `ft_printf` no exportado en headers.

### Deterministic test
- Definicion: prueba con salida reproducible y comparable entre ejecuciones.
- Mini ejemplo: comparar `printf` real vs `ft_printf` con matriz fija.

### Idempotent build step
- Definicion: paso de build que repetido no cambia el resultado final.
- Mini ejemplo: ejecutar `make bonus` dos veces sin relink innecesario.

### Scope gate
- Definicion: validacion de que solo hay archivos permitidos por el subject.
- Mini ejemplo: revisar raiz del proyecto antes de cerrar para evitar extras.

### Regression
- Definicion: perdida de comportamiento correcto tras un cambio nuevo.
- Mini ejemplo: arreglar bonus y romper mandatory por no revalidar ambos.

### Canonical base
- Definicion: fuente principal de referencia para nuevos proyectos.
- Mini ejemplo: usar `42/C/currentLibft/libft` como base oficial evolutiva.
