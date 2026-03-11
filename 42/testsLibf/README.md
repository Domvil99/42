# Tests Directory

Este directorio es para programas de prueba de la librería libft.

## Uso recomendado (según PDF del proyecto):
- Crea archivos .c para probar funciones individuales.
- Compila con: `gcc -Wall -Wextra -Werror -L. -lft test_file.c -o test`
- Ejecuta: `./test`
- Verifica leaks: `valgrind ./test`

## Orden de validacion (global)
1. Confirmar scope de entrega segun la spec `.txt`.
2. Ejecutar tests funcionales de `libft` (fase funcional).
3. Verificar memoria y estabilidad.
4. Ejecutar Norminette al final como cierre.

## Ejemplo de test básico:
```c
#include "../libft.h"
#include <stdio.h>

int main() {
    char *str = ft_strdup("Hola");
    printf("%s\n", str);
    free(str);
    return 0;
}
```

Recuerda: Los tests no se entregan, pero ayudan en evaluaciones.