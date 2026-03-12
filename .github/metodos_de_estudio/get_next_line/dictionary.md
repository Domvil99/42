# get_next_line Dictionary

Glosario tecnico de `get_next_line` para lectura incremental por lineas.

## Entradas

### BUFFER_SIZE
- Definicion: tamano de lectura por llamada a `read`.
- Mini ejemplo: compilar con `-DBUFFER_SIZE=42` para pruebas estables.

### Stash
- Definicion: buffer persistente que guarda sobrante entre llamadas.
- Mini ejemplo: despues de extraer una linea, el resto queda en `stash`.

### Line extraction
- Definicion: separacion hasta `\n` o fin de archivo.
- Mini ejemplo: devolver `"hola\n"` y conservar bytes restantes.

### EOF flush
- Definicion: devolucion final de contenido aunque no termine en `\n`.
- Mini ejemplo: ultimo bloque `"fin"` debe salir antes de retornar `NULL`.

### Multi-fd support
- Definicion: estado independiente para multiples file descriptors.
- Mini ejemplo: alternar lectura entre `fd1` y `fd2` sin mezclar lineas.

### Read guard
- Definicion: validacion de `fd`, `BUFFER_SIZE` y resultado de `read`.
- Mini ejemplo: si `fd < 0`, retornar `NULL` sin tocar estado interno.

### Join strategy
- Definicion: concatenacion segura de bloques parciales.
- Mini ejemplo: anexar bloque nuevo a `stash` y liberar temporal previo.

### Leak-safe cleanup
- Definicion: liberacion total cuando hay error o cierre de flujo.
- Mini ejemplo: liberar `stash[fd]` al detectar `read` con error.
