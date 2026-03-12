# get_next_line Study Report

## 1. Vision del Proyecto

`get_next_line` entrena lectura incremental sobre file descriptors sin cargar
el archivo completo en memoria. El foco real no es solo devolver lineas, sino
controlar estado entre llamadas usando variables estaticas de forma segura.

Objetivos clave:

- lectura por bloques con `read`,
- ensamblado de linea hasta `\n` o EOF,
- conservacion del residuo para la siguiente llamada,
- gestion de memoria sin leaks,
- comportamiento estable para distintos `BUFFER_SIZE`.

## 2. Requisitos Criticos del Subject

1. Prototipo obligatorio:
   `char *get_next_line(int fd);`
2. Archivos mandatory:
   - `get_next_line.c`
   - `get_next_line_utils.c`
   - `get_next_line.h`
3. Solo funciones autorizadas:
   `read`, `malloc`, `free`.
4. Prohibido:
   - `libft`,
   - `lseek`,
   - variables globales.
5. La linea devuelta incluye `\n` si existe en la entrada.
6. Bonus:
   - una sola variable estatica,
   - soporte multi-fd simultaneo,
   - archivos `_bonus.c/.h` separados.

## 3. Arquitectura Mental Recomendada

Modelo de flujo por llamada:

1. Validar `fd` y `BUFFER_SIZE`.
2. Cargar/buscar estado residual (stash).
3. Leer y concatenar hasta encontrar `\n` o EOF.
4. Cortar la linea a devolver.
5. Guardar resto para la siguiente llamada.
6. Liberar memoria no necesaria.

En bonus, este flujo se repite por descriptor, manteniendo un stash por fd.

## 4. Errores Clasicos y Como Evitarlos

1. **Leak al final de archivo**:
   no liberar stash cuando ya no queda nada util.
2. **Double free en rutas de error**:
   ownership ambiguo de buffers intermedios.
3. **Perdida de caracteres entre llamadas**:
   cortar mal la cadena al separar linea/resto.
4. **Loop infinito**:
   no salir cuando `read` devuelve 0 y no hay nueva data.
5. **Comportamiento inconsistente por BUFFER_SIZE extremo**:
   no probar con 1 y valores altos.

## 5. Estrategia de Validacion

Orden profesional:

1. Alineacion con spec.
2. Funcionalidad mandatory.
3. Funcionalidad bonus multi-fd.
4. Memoria y estabilidad.
5. Norminette final.

Cobertura minima recomendada:

- `BUFFER_SIZE=1`, `42`, `9999`.
- archivo con varias lineas,
- archivo con ultima linea sin `\n`,
- linea vacia intermedia,
- lectura desde `stdin`,
- alternancia de fds en bonus.

## 6. Checklist de Defensa Tecnica

Debes poder explicar con claridad:

1. Como se conserva el estado entre llamadas.
2. Como detectas y devuelves exactamente una linea por llamada.
3. Que ocurre al llegar a EOF.
4. Como manejas `fd` invalido y errores de `read`.
5. Como evitas leaks y frees invalidos.
6. Como se aísla el estado por fd en bonus.

## 7. Repaso Activo

### Preguntas rapidas

1. Por que una variable estatica ayuda en este proyecto?
2. Que diferencia hay entre devolver `NULL` por error y por fin de lectura?
3. Que falla aparece tipicamente con `BUFFER_SIZE=1`?
4. Que estructura mental usas para separar linea y resto?

### Mini retos

1. Simula tres llamadas consecutivas sobre un archivo con:
   `hola\nadios\nfin`.
2. Diseña un caso que rompa una implementacion con split incorrecto del stash.
3. Explica como depurar un leak detectado al final de EOF.

## 8. Evolucion Continua

Actualizar este reporte cuando:

- cambie la baseline del subject,
- aparezca un caso borde nuevo,
- se detecte una regresion durante integracion en `currentLibft`,
- se mejore la estrategia de pruebas o depuracion.

## Change Log

- 2026-03-12: version inicial completa para `get_next_line` tras revalidacion
  con baseline corregida.
