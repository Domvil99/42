# testsLibf

Directorio de tests rígidos para validar `42/C/libft` en revisión propia o de terceros.

## Qué hay aquí
- `test_ft_*.c`: mains de validación funcional por función.
- `test_libft_portable_strict.c`: test compacto portable para revisión rápida.

## Uso portable solo con C (sin .sh)
Ejemplo:
`cc -Wall -Wextra -Werror test_libft_portable_strict.c -I<RUTA_LIBFT> <RUTA_LIBFT>/libft.a -o test_libft_portable && ./test_libft_portable`

Donde `<RUTA_LIBFT>` lo decides tú (tu repo o el de un compañero).

## Regla de rigor
- Cualquier binario de test que falle detiene la suite con salida no cero.
- No se aceptan warnings de compilación (`-Wall -Wextra -Werror`).
- Se recomienda pasar también valgrind en casos que usen memoria dinámica.

## Orden de validación
1. Scope/spec (`42/PDFs/2026-03-12_libft_v16_6.txt`).
2. Comportamiento funcional (esta carpeta).
3. Memoria/estabilidad.
4. Norminette al cierre.

## Regla para proyectos nuevos
Cuando aparezca `42/C/<nuevo_proyecto>`, crear su espejo:
- `42/tests/tests_<nuevo_proyecto>/`
- `README.md`
- al menos un `test_*.c` funcional y casos de error.