# tests_ft_printf

Directorio de pruebas manuales para validar `42/C/ft_printf`.

Status: completed (2026-03-11).

## Objetivo
- Comparar comportamiento de `ft_printf` contra `printf`.
- Validar salida y valor de retorno.
- Ejecutar casos de obligatorio y bonus por separado.

## Orden de validacion (global)
1. Confirmar scope de entrega segun la spec `42/PDFs/2026-03-12_ft_printf.txt`.
2. Ejecutar tests funcionales (este directorio es fase funcional).
3. Validar memoria/estabilidad (por ejemplo con valgrind).
4. Ejecutar Norminette al final como cierre.

## Uso sugerido
- Guardar aqui harnesses de prueba (`test_*.c`).
- Compilar contra `42/C/ft_printf/libftprintf.a` y, si aplica,
  `42/C/ft_printf/libft/libft.a`.

## Estado tecnico (2026-03-11)
- Suite de validacion finalizada para cierre de entrega.
- Mandatory: `RET_TOTAL=212` en paridad con `printf`.
- Bonus: `RET_TOTAL=146` en paridad con `printf`.
- Valgrind: `0` leaks y `0` errores en casos frontera.
- Los harnesses se mantienen para regresion y refactor futuro.
