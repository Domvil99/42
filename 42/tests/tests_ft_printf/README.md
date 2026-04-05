# tests_ft_printf

Directorio de pruebas rígidas para validar `42/C/ft_printf`.

## Qué hay aquí
- `test_mandatory_matrix.c` y `test_bonus_matrix.c`: pruebas de `ft_printf`.
- `test_mandatory_ref.c` y `test_bonus_ref.c`: referencias con `printf`.
- `Makefile`: compila bins mandatory/bonus.

## Uso portable solo con C (sin .sh)
Mandatory:
`cc -Wall -Wextra -Werror test_mandatory_matrix.c -I<RUTA_FT_PRINTF> <RUTA_FT_PRINTF>/libftprintf.a <RUTA_FT_PRINTF>/libft/libft.a -o test_mandatory_matrix && ./test_mandatory_matrix`

Bonus:
`cc -Wall -Wextra -Werror test_bonus_matrix.c -I<RUTA_FT_PRINTF> <RUTA_FT_PRINTF>/libftprintf.a <RUTA_FT_PRINTF>/libft/libft.a -o test_bonus_matrix && ./test_bonus_matrix`

Referencia libc:
`cc -Wall -Wextra -Werror test_mandatory_ref.c -o test_mandatory_ref && ./test_mandatory_ref`

## Criterio estricto
- La suite falla si hay cualquier diferencia con `printf` en:
    - salida estándar,
    - total de caracteres retornado (`RET_TOTAL`).
- Se construye con `-Wall -Wextra -Werror`.

## Orden de validación
1. Scope/spec (`42/PDFs/2026-03-12_ft_printf.txt`).
2. Funcional (esta carpeta).
3. Memoria/estabilidad.
4. Norminette al cierre.

## Regla para proyectos nuevos
Todo proyecto nuevo en `42/C/` debe tener su suite equivalente en `42/tests/`
con tests C portables y comparación contra comportamiento esperado.
