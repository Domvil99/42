# tests_ft_printf

Directorio de pruebas manuales para validar `42/C/ft_printf`.

## Objetivo
- Comparar comportamiento de `ft_printf` contra `printf`.
- Validar salida y valor de retorno.
- Ejecutar casos de obligatorio y bonus por separado.

## Orden de validacion (global)
1. Confirmar scope de entrega segun la spec `.txt`.
2. Ejecutar tests funcionales (este directorio es fase funcional).
3. Validar memoria/estabilidad (por ejemplo con valgrind).
4. Ejecutar Norminette al final como cierre.

## Uso sugerido
- Guardar aqui harnesses de prueba (`test_*.c`).
- Compilar contra `42/C/ft_printf/libftprintf.a` y, si aplica,
  `42/C/ft_printf/libft/libft.a`.
