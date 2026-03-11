# Progreso General ft_printf

## Estado Actual
- Proyecto detectado en `42/C/ft_printf`.
- Nueva base de referencia detectada en `42/C/ft_printf_new_base`.
- Especificacion registrada: `42/PDFs/2026-03-10_ft_printf.txt`.
- Objetivo actual: validacion completa + correccion de errores.
- Politica temporal: ignorar solo `INVALID_HEADER`.
- Implementacion activa iniciada el `2026-03-11`.

## Cobertura Objetivo
- Obligatorio: conversiones `cspdiuxX%`.
- Bonus: flags indicadas en especificacion (si estan implementadas).

## Validacion Planeada
1. Validacion de estructura/scope de entrega contra la spec `.txt`.
2. Comparativas funcionales contra `printf` para obligatorio y bonus.
3. Verificacion de leaks/seguridad de memoria.
4. Build de cierre (`make` y `make bonus`, sin relink innecesario).
5. Norminette (`*.c *.h`) como paso final de cierre.

## Notas
- Durante esta fase, Chat2 trabaja solo dentro de `42/C/ft_printf`.
- Se usa la `libft` integrada en `ft_printf` hasta cierre del proyecto.

## Avance 2026-03-11
1. Build obligatorio y bonus verificados tras cambios (`make` y `make bonus`).
2. Fix funcional aplicado en parser/dispatcher:
	- ya no se salta el caracter posterior a la conversion.
3. Fixes de memoria aplicados en rutas `int`/`unsigned` (bonus incluido) para
	evitar frees invalidos en el caso `.0` con `0`.
4. Smoke test de comparacion (`%.0d` y `%.0u`) alineado con `printf`
	en salida y return value.
5. Valgrind smoke: `0` leaks y `0` errores en el caso validado.
6. Correccion `%p` con puntero `NULL`:
	- salida alineada con `printf` usando `(nil)`.
	- valor de retorno alineado tras correccion.
7. Matriz obligatoria actual (23 casos) y matriz bonus oficial (13 casos):
	- output: sin diferencias contra `printf`.
	- return total: sin diferencias contra `printf`.
8. Hardening de build:
	- `Makefile` ahora recrea `libftprintf.a` en `all` y `bonus` para evitar
	  mezcla de simbolos entre builds.
9. Limpieza incremental de Norminette en dispatchers:
	- `handle_format.c` y `handle_format_bonus.c` quedaron con unico hallazgo
	  `INVALID_HEADER` (politica temporal permitida).
10. Revalidacion post-refactor:
	- `make` + `make bonus` OK.
	- matrices obligatoria y bonus siguen sin diferencias contra `printf`.

## Pendiente inmediato (registro historico)
1. Extender matriz funcional a todas las conversiones obligatorias.
2. Barrido bonus de flags `-0.` + width + `# +` y espacio.
3. Cierre de bloqueantes Norminette (exceptuando `INVALID_HEADER`).

## Avance Norminette por rondas (2026-03-11)
1. Baseline completo ejecutado en `42/C/ft_printf`:
	- Se detectan categorias dominantes: `DECL_ASSIGN_LINE`,
	  `TERNARY_FBIDDEN`, `EMPTY_LINE_FUNCTION`, `TOO_MANY_LINES`,
	  `TOO_MANY_VARS_FUNC`, tabulacion/alineacion.
2. Micro-lote 1 aplicado (estrategia incremental):
	- Archivos: `ft_printf.c`, `parse_format.c`, `parse_format_bonus.c`.
	- Resultado: en esos archivos quedan solo hallazgos `INVALID_HEADER`.
3. Revalidacion de build tras el lote:
	- `make bonus` OK en `42/C/ft_printf`.
4. Micro-lote 2 aplicado (par normal/bonus):
	- Archivos: `print_char.c`, `print_char_bonus.c`.
	- Resultado: en ambos quedan solo hallazgos `INVALID_HEADER`.
5. Micro-lote 3 aplicado (normal + bonus + header):
	- Archivos: `print_str.c`, `print_str_bonus.c`, `print_reverse_bonus.c`,
	  `print_n_bonus.c`, `ft_printf.h`.
	- Resultado: en todos los archivos del lote quedan solo hallazgos
	  `INVALID_HEADER`.
6. Snapshot de deuda Norminette restante (sin `INVALID_HEADER`):
	- `print_unsigned.c` (151)
	- `print_unsigned_bonus.c` (39)
	- `print_int.c` (39)
	- `print_int_bonus.c` (39)
	- `print_hex.c` (31)
	- `print_binary_bonus.c` (26)
	- `print_pointer.c` (23)
	- `print_pointer_bonus.c` (23)
7. Micro-lote 4 completado:
	- Archivo: `print_hex_bonus.c`.
	- Resultado por archivo: solo `INVALID_HEADER`.
	- Validacion del flujo: `Normi Autofix` + `Normi Check (No Header)` OK.
	- Comparativa: `norminette` crudo muestra solo `INVALID_HEADER`.
8. Revalidacion de compilacion tras micro-lote 4:
	- `make` OK.
	- `make bonus` OK.

## Snapshot validado (2026-03-11)
1. Verificacion puntual del archivo foco:
	- `norminette print_hex_bonus.c` => solo `INVALID_HEADER`.
2. Rebuild actualizado:
	- `make` OK.
	- `make bonus` OK.
3. Deuda Norminette accionable actual (sin `INVALID_HEADER`):
	- total: `286` errores.
	- distribucion por archivo:
		- `print_unsigned.c` (151)
		- `print_int_bonus.c` (39)
		- `print_int.c` (39)
		- `print_hex.c` (31)
		- `print_binary_bonus.c` (26)

## Pendiente inmediato (actualizado, registro historico)
1. Micro-lote 5: `print_binary_bonus.c` (26).
2. Micro-lote 6: `print_hex.c` (31).
3. Micro-lote 7: `print_int.c` + `print_int_bonus.c` (39 + 39).
4. Micro-lote 8: `print_unsigned.c` (151).

## Migracion base obligatoria (2026-03-11)
1. Switch inicial aplicado en obligatorio usando semantica de
	`42/C/ft_printf_new_base`.
2. Build validado:
	- `make fclean && make` OK.
	- `make bonus` OK con entrypoint separado `ft_printf_bonus.c`.
3. Smoke obligatorio esencial validado (`cspdiuxX%` en formato simple):
	- output y retorno alineados con `printf` en caso de prueba base.
4. Infra de pruebas creada:
	- `42/tests_ft_printf/README.md`.

## Actualizacion metodologia (2026-03-11)
1. Cambio operativo aplicado por solicitud del usuario:
	- priorizar validacion funcional y memoria antes de abrir nuevos lotes
	  de limpieza Norminette.
2. Gates ejecutados en esta ronda:
	- obligatorio: build + matriz mandatory en verde.
	- comparativa contra `printf` (mandatory): sin diff en salida y mismo
	  `RET_TOTAL=212`.
	- memoria: valgrind en casos frontera (`%.0d`, `%.0u`, `%p NULL`,
	  width/precision y flags bonus) con `0` leaks y `0` errores.
	- bonus: comparativa contra `printf` sin diff en salida y mismo
	  `RET_TOTAL=146`.
3. Micro-ajuste de norma post-gate funcional:
	- `print_binary_bonus.c` corregido para cerrar
	  `BRACE_SHOULD_EOL` (queda solo `INVALID_HEADER` en el archivo).
4. Snapshot accionable de norma recalculado (sin `INVALID_HEADER`):
	- `ft_printf.h` (60)
	- `parse_format_bonus.c` (56)
	- `handle_format_bonus.c` (28)

## Gate de estructura previo a norma (2026-03-11)
1. Limpieza de scope entregable aplicada en `42/C/ft_printf`:
	- removidos extras no usados y fuera de alcance activo de spec:
		- `print_reverse_bonus.c`
		- `print_n_bonus.c`
		- `print_binary_bonus.c` (no presente ya en baseline final)
2. Ajuste de `Makefile` para cumplimiento del subject sin relink innecesario:
	- regla explicita `$(NAME)`.
	- `all` y `bonus` operan sobre artefactos internos y actualizan
	  `libftprintf.a` solo si cambia contenido.
	- regla explicita de dependencia para `$(LIBFT)`.
3. Revalidacion post-estructura:
	- `make` OK; segunda corrida: `Nothing to be done for 'all'.`
	- `make bonus` OK; segunda corrida sin relink.
	- mandatory vs `printf`: sin diff; `RET_TOTAL=212`.
	- bonus vs `printf`: sin diff; `RET_TOTAL=146`.
	- valgrind frontera: `0` leaks y `0` errores.

## Cierre tecnico actual (2026-03-11)
1. Limpieza de artefactos de prueba en `42/tests_ft_printf/`:
	- eliminados binarios y outputs generados (`*.out`, `*.err`, ejecutables).
	- set de pruebas queda en archivos fuente y `Makefile`/`README.md`.
2. Revalidacion de build post-limpieza:
	- `make` OK.
	- `make bonus` OK.
3. Snapshot Norminette actual (ignorando solo `INVALID_HEADER`):
	- `42/C/ft_printf/ft_printf.h` (alineacion de declaraciones).
	- `42/C/ft_printf/parse_format_bonus.c` (alineacion/tabulacion).
	- `42/C/ft_printf/handle_format_bonus.c` (alineacion de declaraciones).

## Cierre de norma accionable (2026-03-11)
1. Micro-lote final aplicado en:
	- `42/C/ft_printf/ft_printf.h`
	- `42/C/ft_printf/parse_format_bonus.c`
	- `42/C/ft_printf/handle_format_bonus.c`
2. Resultado:
	- `norminette *.c *.h` sin errores accionables.
	- estado restante: solo `INVALID_HEADER` (politica temporal).
3. Revalidacion post-ajuste:
	- `make` OK.
	- `make bonus` OK.

## Continuidad de implementacion (2026-03-11)
1. Mandatory estabilizado tras pegado del usuario (sin cambiar firmas):
	- revisados `ft_printf.c`, `print_char.c`, `print_decimal.c`,
	  `print_unsigned.c`, `print_pointer.c`.
2. Ajustes mecanicos aplicados:
	- cierre de linea final en archivos mandatory afectados.
	- normalizacion de bloque condicional `# ifndef FT_PRINTF_BONUS` en
	  `ft_printf.h`.
3. Revalidacion funcional y memoria:
	- `42/tests_ft_printf/test_mandatory_matrix`: `RET_TOTAL=212`.
	- `42/tests_ft_printf/test_bonus_matrix`: `RET_TOTAL=146`.
	- valgrind sobre matriz mandatory: `0` leaks, `0` errores.
4. Estado de norma tras esta ronda:
	- sin hallazgos accionables adicionales en los archivos tocados.
	- politica temporal de `INVALID_HEADER` se mantiene sin cambios.

## Auditoria final contra subject (2026-03-11)
1. Verificacion de spec fuente:
	- `42/PDFs/2026-03-10_ft_printf.txt` y el `.txt` recibido en chat
	  coinciden en requisitos normativos.
2. Makefile y build:
	- `make` y `make bonus` OK.
	- no relink verificado en segunda corrida (`make`: "Nothing to be done").
	- `ar` usado para generar librerias (`libft.a`, `.mandatory.a`, `.bonus.a`
	  y copia a `libftprintf.a`).
3. Cumplimiento de funciones autorizadas:
	- barrido de llamadas prohibidas en `ft_printf/*.c` sin hallazgos.
4. Norminette full scope:
	- se normalizaron headers 42 en `ft_printf/*.c`, `ft_printf/*.h`,
	  `ft_printf/libft/*.c`, `ft_printf/libft/*.h`.
	- resultado actual: `norminette *.c *.h libft/*.c libft/*.h` -> `RC=0`.
5. Validacion funcional y memoria final:
	- mandatory matrix: `RET_TOTAL=212`.
	- bonus matrix: `RET_TOTAL=146`.
	- valgrind mandatory y bonus: `0` leaks, `0` errores.

## Cierre de entrega y tracking (2026-03-11)
1. Commit de entrega en repo `42/C/`:
	- `2415cdf` -> `ft_printf: finalize subject compliance and full validation`.
2. Commit de tracking en repo `Raiz/`:
	- `7cf296d` -> `docs(ft_printf): record full subject audit and validation status`.
3. Estado final del proyecto `ft_printf`:
	- validado contra subject,
	- listo para entrega (sin bloqueantes tecnicos abiertos).

## Blindaje de Makefile y headers (2026-03-11)
1. Objetivo aplicado:
	- cumplir de forma estricta el enunciado en `*Makefile` y `*.h`,
	  incluyendo separacion mandatory/bonus y orden de compilacion de `libft`.
2. Cambios estructurales:
	- `ft_printf.h` ahora mantiene solo contrato/soporte mandatory.
	- nuevo `ft_printf_bonus.h` para tipos/prototipos bonus.
	- fuentes bonus migradas a incluir `ft_printf_bonus.h`.
3. Verificacion de reglas Makefile:
	- `make` y `make bonus` en verde.
	- segunda corrida sin relink innecesario.
	- confirmada dependencia efectiva de `$(LIBFT)` antes de archivado final.
4. Revalidacion final post-cambio:
	- `norminette *.c *.h libft/*.c libft/*.h` -> `RC=0`.
	- matrices mandatory/bonus -> `RET_TOTAL=212` / `146`.
	- valgrind mandatory/bonus -> `0` errores, `0` leaks.
