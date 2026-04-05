# tests_currentLibft

Integration gate rígido para `42/C/currentLibft`.

## Qué hay aquí
- `test_current_libft_link_strict.c`: valida enlace y uso real de símbolos
	de `libft` + `ft_printf` integrados.

## Uso portable solo con C (sin .sh)
`cc -Wall -Wextra -Werror test_current_libft_link_strict.c -I<RUTA_CURRENT_LIBFT>/libft -I<RUTA_CURRENT_LIBFT>/libft/ft_printf <RUTA_CURRENT_LIBFT>/libft/ft_printf/libftprintf.a <RUTA_CURRENT_LIBFT>/libft/libft.a -o test_current_libft && ./test_current_libft`

## Criterio estricto
- El build de integración debe reconstruir de cero sin errores.
- El binario de prueba debe enlazar y ejecutar correctamente.
- Falla inmediata si una API base no responde como se espera.

## Regla para futuras integraciones
Cada módulo nuevo integrado en `42/C/currentLibft/libft/<modulo>` debe traer:
- al menos un test de enlace en esta carpeta,
- validación mínima de una función crítica del módulo,
- actualización de este README con su cobertura.
