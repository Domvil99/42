# Funciones y Componentes ft_printf

## Nucleo detectado (baseline)
- `ft_printf.c`
- `parse_format.c`
- `handle_format.c`
- `print_char.c`
- `print_str.c`
- `print_int.c`
- `print_unsigned.c`
- `print_hex.c`
- `print_pointer.c`

## Bonus detectado (baseline)
- `parse_format_bonus.c`
- `handle_format_bonus.c`
- `print_char_bonus.c`
- `print_str_bonus.c`
- `print_int_bonus.c`
- `print_unsigned_bonus.c`
- `print_hex_bonus.c`
- `print_pointer_bonus.c`

## Estado
- Baseline importado para revision.
- Revalidacion por baseline corregida (2026-03-12):
	- spec activa migrada a `42/PDFs/2026-03-12_ft_printf_actualizado.txt`.
	- build mandatory/bonus OK.
	- matrices mandatory/bonus en paridad con `printf`
	  (`RET_TOTAL=212` y `RET_TOTAL=146`).
	- ASAN/UBSAN sin hallazgos en matrices.
	- `norminette *.c *.h` en `42/C/ft_printf` OK.
	- chequeo de paridad de headers entre `42/C/libft` y
	  `42/C/ft_printf/libft`: solo diferencias de timestamp `Updated`.
- Estado de headers (2026-03-11): bloque 42 validado en todo `ft_printf/*.c`,
  `ft_printf/*.h` y `ft_printf/libft/*.{c,h}` con alineacion de columnas.
- Politica de validacion actual: no se aplican excepciones a `INVALID_HEADER`.
- Nota de sincronizacion (2026-03-11): `ft_printf/libft` fue alineado con
	`42/C/libft` para mantener headers equivalentes entre mirrors.
- Reorganizacion mandatory aplicada en `42/C/ft_printf/`:
		- `ft_printf.c` (dispatcher obligatorio simplificado)
		- `print_char.c`, `print_string.c`, `print_decimal.c`,
		  `print_unsigned.c`, `print_hex.c`, `print_pointer.c`, `utils.c`
	- Bonus desacoplado de entrypoint obligatorio mediante:
		- `ft_printf_bonus.c` (usa flujo bonus existente).
	- `Makefile` actualizado:
		- `SRC` obligatorio nuevo.
		- `BONUS_SRC` ahora usa `ft_printf_bonus.c`.
- Implementacion iniciada (2026-03-11):
	- `handle_format.c`: corregido avance de indice de parseo para no saltar
		caracteres tras conversion.
	- `handle_format_bonus.c`: mismo ajuste de indice en flujo bonus.
	- `print_int.c` y `print_int_bonus.c`: correccion de manejo de memoria en
		caso `precision == 0 && n == 0` (`NULL` seguro en lugar de literal),
		guardas de `malloc` fallido y `free` seguro.
	- `print_unsigned_bonus.c`: guardas de `malloc`, caso `.0` con `0` seguro
		y `free` seguro.
	- `print_pointer.c` y `print_pointer_bonus.c`: `%p` con `NULL` alineado con
		`printf` (`(nil)`) y conteo de retorno consistente.
	- `Makefile`: recreacion explicita de `libftprintf.a` en `all` y `bonus`
		para evitar colisiones de simbolos obligatorio/bonus.
- Estado de cumplimiento consolidado:
	- scope de entrega acotado a la spec activa (`cspdiuxX%` + flags bonus).
	- gates funcional y de memoria validados antes de norma.
	- cierre de build y Norminette documentado en el tracking del proyecto.

- Ronda Norminette (micro-lote 1) completada:
	- `ft_printf.c`: ajuste de formato y estructura para norma.
	- `parse_format.c`: refactor a helpers (`parse_flags`,
	  `parse_width_precision`) para eliminar errores de linea/estructura.
	- `parse_format_bonus.c`: refactor equivalente, reduciendo funciones por
	  archivo y limpiando errores de formato.
	- estado del lote: solo `INVALID_HEADER` en estos tres archivos.

- Ronda Norminette (micro-lote 2) completada:
	- `print_char.c` y `print_char_bonus.c` refactorizados sin ternarios,
	  sin declaracion+asignacion en linea y con estructura valida.
	- estado del lote: solo `INVALID_HEADER` en ambos archivos.

- Ronda Norminette (micro-lote 3) completada:
	- `print_str.c` y `print_str_bonus.c`: helpers `static` para padding,
	  eliminacion de ternarios y ajuste de estructura para limite de lineas.
	- `print_reverse_bonus.c`: refactor completo a helpers `static`
	  (`write_padding`/`write_reverse`) para cumplir limite de lineas y
	  variables por funcion.
	- `print_n_bonus.c` y `ft_printf.h`: correcciones menores de formato
	  (declaracion/asignacion, `return`, tabulacion de prototipo).
	- estado del lote: solo `INVALID_HEADER` en estos archivos.

- Ronda Norminette (micro-lote 4) completada:
	- `print_hex_bonus.c`: refactor a helpers `static` para eliminar
	  `TERNARY_FBIDDEN`, `DECL_ASSIGN_LINE`, `TOO_MANY_VARS_FUNC` y
	  `TOO_MANY_LINES` sin cambiar la logica de salida.
	- estado del lote: solo `INVALID_HEADER` en `print_hex_bonus.c`.

- Revalidacion puntual posterior (2026-03-11):
	- `print_hex_bonus.c`: se confirma estado estable con unico hallazgo
	  `INVALID_HEADER`.
	- build del proyecto tras verificacion:
		- `make` OK.
		- `make bonus` OK.
	- deuda Norminette accionable restante del proyecto: 286 errores
	  distribuidos en `print_unsigned.c`, `print_int.c`,
	  `print_int_bonus.c`, `print_hex.c`, `print_binary_bonus.c`.

- Actualizacion funcional-first (2026-03-11):
	- se ejecuto gate funcional obligatorio completo con paridad contra
	  `printf` (salida sin diff, `RET_TOTAL=212`).
	- se ejecuto gate funcional bonus completo con paridad contra `printf`
	  (salida sin diff, `RET_TOTAL=146`).
	- se ejecuto gate de memoria (valgrind) en casos frontera con
	  resultado `0` leaks y `0` errores.
	- ajuste puntual de estilo en `print_binary_bonus.c` para cerrar
	  `BRACE_SHOULD_EOL` tras pasar gates funcionales.
	- snapshot de deuda Norminette accionable actual (sin `INVALID_HEADER`):
		- `ft_printf.h` (60)
		- `parse_format_bonus.c` (56)
		- `handle_format_bonus.c` (28)

- Cierre de estructura/scope antes de norma (2026-03-11):
	- eliminados archivos bonus fuera de alcance de spec y no conectados al
	  flujo activo:
		- `print_reverse_bonus.c`
		- `print_n_bonus.c`
		- `print_binary_bonus.c` (ya no presente en baseline actual)
	- `Makefile` ajustado para cumplimiento estricto del subject:
		- regla explicita `$(NAME)` restaurada.
		- no-relink mantenido en `all`/`bonus` con artefactos internos
		  (`.mandatory.a` / `.bonus.a`) y copia condicional a `libftprintf.a`.
		- regla explicita para construir `$(LIBFT)` cuando sea dependencia.
	- revalidacion post-ajuste:
		- `make` segunda corrida: `Nothing to be done for 'all'.`
		- `make bonus` segunda corrida: sin relink.
		- matrices mandatory/bonus: paridad mantenida (`212` / `146`).
		- valgrind frontera: `0` leaks, `0` errores.

- Cierre de artefactos de test (2026-03-11):
	- limpieza aplicada en `42/tests_ft_printf/` para retirar binarios y
	  outputs temporales de comparativas.
	- estado funcional/build preservado tras limpieza:
		- `make` OK.
		- `make bonus` OK.
	- snapshot de norma accionable restante (sin `INVALID_HEADER`):
		- `ft_printf.h`
		- `parse_format_bonus.c`
		- `handle_format_bonus.c`

- Cierre final de norma accionable (2026-03-11):
	- `ft_printf.h`: ajuste final de alineacion en structs de formato.
	- `parse_format_bonus.c`: normalizacion final de tabulacion/alineacion.
	- `handle_format_bonus.c`: alineacion final de declaraciones locales.
	- resultado: barrido `norminette *.c *.h` sin errores accionables;
	  solo `INVALID_HEADER` por politica temporal.
	- `make` y `make bonus` se mantienen en verde tras el lote final.

- Estabilizacion post-pegado `new_base` (2026-03-11, tramo continuo):
	- mandatory revisado sin cambio de firmas ni semantica en:
	  `ft_printf.c`, `print_char.c`, `print_decimal.c`,
	  `print_unsigned.c`, `print_pointer.c`.
	- ajuste mecanico de formato para norma:
	  newline de cierre de archivo y normalizacion de bloque condicional en
	  `ft_printf.h`.
	- validacion ejecutada tras ajustes:
	  `make` OK, `make bonus` OK, matrices mandatory/bonus en verde,
	  valgrind mandatory sin leaks/errores.

- Cierre de auditoria integral (2026-03-11):
	- normalizacion de header 42 aplicada a todos los entregables del
	  proyecto (`ft_printf/*.c`, `ft_printf/*.h`, `ft_printf/libft/*.c`,
	  `ft_printf/libft/*.h`).
	- `norminette` full scope en verde (`RC=0`).
	- matriz funcional y memoria revalidadas sin regresion.

- Cierre de version para entrega (2026-03-11):
	- commit de proyecto en `42/C/`: `2415cdf`.
	- commit de tracking en `Raiz/`: `7cf296d`.
	- estado funcional consolidado para evaluacion final del proyecto.

- Publicacion final de cierre (2026-03-11):
	- commits adicionales en `42/C/`:
		- `79b2255` (`ft_printf: harden headers and keep makefile/spec compliance`)
		- `360f071` (`chore(ft_printf): ignore local build artifacts and drop staging base`)
	- commits adicionales en `Raiz/`:
		- `9ecbda6` (`docs(ft_printf): record makefile/header hardening and final checks`)
		- `b7bdcda` (`chore(tests): ignore local ft_printf test binaries`)
	- pushes remotos completados en ambos repos (`main -> main`).

- Blindaje Makefile/headers segun spec (2026-03-11):
	- `ft_printf.h` desacoplado de declaraciones bonus.
	- nuevo `ft_printf_bonus.h` agregado para tipos y prototipos bonus.
	- `*_bonus.c` migrados a `#include "ft_printf_bonus.h"`.
	- comprobado flujo de compilacion previo de `libft` desde `Makefile`.
	- revalidado: build mandatory/bonus, no-relink, norma completa,
	  matrices (`212`/`146`) y valgrind (0 errores, 0 leaks).
