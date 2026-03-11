# Referencia Rapida ft_printf

Estado: en validacion/correccion contra spec `42/PDFs/2026-03-10_ft_printf.txt`.

Nota actual (2026-03-11):
- Migracion activa de obligatorio desde `42/C/ft_printf_new_base/` hacia
    `42/C/ft_printf/`.
- Bonus se mantiene operativo con `ft_printf_bonus.c` durante el rebase.

## API requerida
- `int ft_printf(char const *format, ...);`

## Conversiones obligatorias
- `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, `%%`

## Restricciones clave
- Sin buffer del printf original.
- Solo funciones autorizadas: `malloc`, `free`, `write`, `va_start`,
  `va_arg`, `va_copy`, `va_end`.
- Libreria final: `libftprintf.a` en raiz del proyecto.
- Compilar con `-Wall -Wextra -Werror`.
- Crear libreria con `ar` (no `libtool`).

## Politica operativa temporal
- Ignorar solo `INVALID_HEADER`.
- Corregir automaticamente errores claros; validar contigo casos ambiguos.

## Implementacion en curso (2026-03-11)
- Orden de ejecucion activo:
    1. fixes P1 de memoria/robustez,
    2. correcciones funcionales de parseo/dispatch,
    3. matrices de validacion obligatoria y bonus,
    4. cierre de Norminette bloqueante.
- Caso validado: `%.0d` y `%.0u` con valor `0` coincide con `printf` en
    salida y valor de retorno.

## Checklist Rapido Anti-Errores Norminette
1. Declarar variables al inicio de cada funcion, luego linea en blanco.
2. Evitar declaracion + asignacion en una misma linea.
3. Prohibido ternario (`?:`), reemplazar por `if/else`.
4. Evitar lineas vacias dentro de funciones si no son necesarias.
5. Mantener tabs/alineacion consistente (sin mezclar espacios/tabs).
6. Encerrar siempre `return` con parentesis (`return (x);`).
7. Si una funcion supera 25 lineas, extraer helpers `static`.
8. Evitar demasiadas variables por funcion; dividir en helpers.
9. No dejar comentarios en scope invalido dentro de bloques.
10. Validar por archivo justo despues de cada edicion.

## Ronda de correccion activa (micro-lote 1)
- Archivos limpiados de errores no-header:
    - `42/C/ft_printf/ft_printf.c`
    - `42/C/ft_printf/parse_format.c`
    - `42/C/ft_printf/parse_format_bonus.c`
- Estado actual del micro-lote:
    - `norminette` muestra solo `INVALID_HEADER` en esos 3 archivos.

## Ronda de correccion activa (micro-lote 2)
- Archivos limpiados de errores no-header:
    - `42/C/ft_printf/print_char.c`
    - `42/C/ft_printf/print_char_bonus.c`
- Estado actual del micro-lote:
    - `norminette` muestra solo `INVALID_HEADER` en ambos archivos.

## Ronda de correccion activa (micro-lote 3)
- Archivos limpiados de errores no-header:
    - `42/C/ft_printf/print_str.c`
    - `42/C/ft_printf/print_str_bonus.c`
    - `42/C/ft_printf/print_reverse_bonus.c`
    - `42/C/ft_printf/print_n_bonus.c`
    - `42/C/ft_printf/ft_printf.h`
- Estado actual del micro-lote:
    - `norminette` muestra solo `INVALID_HEADER` en estos 5 archivos.

## Ronda de correccion activa (micro-lote 4)
- Archivos limpiados de errores no-header:
    - `42/C/ft_printf/print_hex_bonus.c`
- Estado actual del micro-lote:
    - `norminette` muestra solo `INVALID_HEADER` en este archivo.

## Baseline confirmado hoy (2026-03-11)
- Rebuild verificado:
    - `make` OK
    - `make bonus` OK
- Deuda Norminette accionable (sin `INVALID_HEADER`):
    - total: `286`
    - `print_unsigned.c`: 151
    - `print_int_bonus.c`: 39
    - `print_int.c`: 39
    - `print_hex.c`: 31
    - `print_binary_bonus.c`: 26

## Cambio de flujo (2026-03-11)
- Metodologia activa confirmada:
    1. estructura/scope de entrega segun spec,
    2. funcionalidad segun spec,
    3. memoria/estabilidad,
    4. norma al final por micro-lotes.
- Gate funcional obligatorio validado:
    - comparativa `ft_printf` vs `printf`: sin diff de salida.
    - retorno total alineado: `RET_TOTAL=212`.
- Gate funcional bonus validado:
    - comparativa `ft_printf` vs `printf`: sin diff de salida.
    - retorno total alineado: `RET_TOTAL=146`.
- Gate de memoria validado:
    - valgrind en casos frontera: `0` errores, `0` leaks.
- Deuda de norma accionable recalculada tras esta ronda
  (sin `INVALID_HEADER`):
    - `ft_printf.h`: 60
    - `parse_format_bonus.c`: 56
    - `handle_format_bonus.c`: 28

## Estado estructural actual (2026-03-11)
- Set entregable activo de bonus acotado a conversiones/flags de la spec:
    `print_char_bonus.c`, `print_str_bonus.c`, `print_int_bonus.c`,
    `print_unsigned_bonus.c`, `print_hex_bonus.c`, `print_pointer_bonus.c`,
    junto a `parse_format_bonus.c` y `handle_format_bonus.c`.
- Extras no conectados al flujo de spec fueron retirados del directorio
    entregable (`print_reverse_bonus.c`, `print_n_bonus.c`).
- `Makefile` actualizado para:
    - mantener regla `$(NAME)` explicita,
    - evitar relink innecesario en corridas repetidas,
    - preservar `libftprintf.a` como salida final.

## Estado de cierre (actual)
- Limpieza de residuos de prueba completada en `42/tests_ft_printf/`:
    - removidos ejecutables y archivos de salida generados.
- Build de control post-limpieza:
    - `make` OK.
    - `make bonus` OK.
- Pendiente de norma (sin contar `INVALID_HEADER`):
    - ninguno (cierre completado).

## Estado Norminette final (actual)
- `norminette *.c *.h`: sin errores accionables.
- Se mantiene unicamente `INVALID_HEADER` (politica temporal activa).
- Build de confirmacion tras el cierre:
    - `make` OK.
    - `make bonus` OK.

## Estado de continuidad (2026-03-11)
- Ajustes de continuidad aplicados en mandatory sin cambio de API ni
    semantica.
- Verificaciones de control en verde:
    - matrices de pruebas mandatory y bonus (`RET_TOTAL=212` y `146`).
    - valgrind mandatory (`0` leaks, `0` errores).
- Scope actual preparado para siguiente lote (commit/revision de diff).

## Estado de auditoria final (2026-03-11)
- Revisados todos los puntos evaluables del subject `ft_printf`.
- Norminette full scope en verde incluyendo headers 42:
    - `norminette *.c *.h libft/*.c libft/*.h` -> `RC=0`.
- Build/relink en verde:
    - `make` OK, `make` segunda corrida sin relink,
    - `make bonus` OK.
- Paridad funcional y memoria en verde:
    - matrices mandatory/bonus (`RET_TOTAL=212` / `146`),
    - valgrind mandatory/bonus (`0` errores, `0` leaks).
