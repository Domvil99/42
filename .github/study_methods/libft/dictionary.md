# libft Dictionary

Glosario tecnico de `libft` para repaso rapido.

## Entradas

### Prototype parity
- Definicion: coincidencia exacta de firma respecto a la funcion esperada.
- Mini ejemplo: `ft_memcpy(void *dst, const void *src, size_t n)`.

### NUL terminator
- Definicion: byte `\0` que marca el final de una cadena en C.
- Mini ejemplo: `ft_strdup` reserva `len + 1` y escribe terminador al final.

### Safe allocation
- Definicion: reserva validada antes de usar punteros resultantes.
- Mini ejemplo: `ft_substr` retorna `NULL` si `malloc` falla.

### Overflow guard
- Definicion: control para evitar desbordamiento en calculos de tamano.
- Mini ejemplo: en `ft_calloc`, validar multiplicacion antes de reservar.

### Linked list node
- Definicion: estructura `t_list` con `content` y `next`.
- Mini ejemplo: `ft_lstnew` crea nodo con `next = NULL`.

### Ownership transfer
- Definicion: quien es responsable de liberar memoria tras una operacion.
- Mini ejemplo: `ft_lstmap` crea nueva lista; el caller debe liberarla luego.

### Defensive null check
- Definicion: salida controlada cuando punteros de entrada son `NULL`.
- Mini ejemplo: `ft_putstr_fd` no escribe nada si `s == NULL`.

### Boundary condition
- Definicion: caso limite de entrada minima o maxima.
- Mini ejemplo: `ft_strlcpy` con `dstsize == 0` no copia pero retorna longitud.
