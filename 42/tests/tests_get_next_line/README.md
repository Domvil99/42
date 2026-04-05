# tests_get_next_line

Directorio de pruebas rígidas para validar `42/C/get_next_line`.

## Qué hay aquí
- `test_gnl_mandatory_strict.c`: casos de líneas normales, línea vacía, EOF e fd inválido.
- `test_gnl_bonus_multifd_strict.c`: alternancia real entre dos file descriptors.

## Uso portable solo con C (sin .sh)
Mandatory:
`cc -Wall -Wextra -Werror -DBUFFER_SIZE=42 test_gnl_mandatory_strict.c <RUTA_GNL>/get_next_line.c <RUTA_GNL>/get_next_line_utils.c -I<RUTA_GNL> -o test_gnl_mandatory && ./test_gnl_mandatory`

Bonus:
`cc -Wall -Wextra -Werror -DBUFFER_SIZE=42 test_gnl_bonus_multifd_strict.c <RUTA_GNL>/get_next_line_bonus.c <RUTA_GNL>/get_next_line_utils_bonus.c -I<RUTA_GNL> -o test_gnl_bonus && ./test_gnl_bonus`

## Criterio estricto
- Mandatory: `BUFFER_SIZE=1`, `42`, `1024`.
- Bonus: `BUFFER_SIZE=1`, `42` con multi-fd intercalado.
- Falla inmediata ante cualquier desvío de contenido o EOF.

## Orden de validación
1. Scope/spec (`42/PDFs/2026-03-12_get_next_line.txt`).
2. Funcional (esta carpeta).
3. Memoria/estabilidad.
4. Norminette al cierre.

## Regla para proyectos nuevos
Mantener siempre una suite strict reproducible en C y al menos:
- un test funcional principal,
- un test de errores/casos límite,
- validación con más de una configuración relevante.
