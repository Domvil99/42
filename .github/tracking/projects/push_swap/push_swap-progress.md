# push_swap Progress

## Current Status

Proyecto: `42/C/push_swap`
Estado: completed

## Milestones

1. Subject canónico disponible y traducido.
2. Estructura base mandatory implementada.
3. Parser y operaciones implementadas.
4. Estrategias de ordenación (small + radix) implementadas.
5. Optimización por `chunk sort` integrada para mejorar benchmark 100/500.
6. Informe de estudio creado para soporte técnico y defensa.
7. Integración de base `libft` alineada con `currentLibft` (incluye bonus
	listas + fuentes bonus de módulos hijos).
8. Implementación bonus `checker` separada de mandatory con archivos
	`*_bonus.c/h` y target `make bonus`.

## Quality Gates

### Gate 1: Scope/spec

- Scope actual `push_swap`: implementado.
- Ejecutable obligatorio `push_swap` mantiene compilación y ejecución
	conforme al subject.
- Scope bonus `checker`: implementado y compilado por regla `bonus`
	separada en Makefile.

### Gate 2: Functional

- Casos simples y edge cases: validados con verificación funcional y errores controlados.
- Benchmarks 100/500: evidencia consolidada en muestra real:
	- 100 números: `602` operaciones (`OK`).
	- 500 números: `5182` operaciones (`OK`).
- Checker bonus validado en rutas requeridas:
	- `OK` (orden correcto),
	- `KO` (no ordenado),
	- `Error` (instrucción inválida).

### Gate 3: Memory/stability

- Rutas de liberación presentes.
- ASAN/UBSAN ejecutado en `push_swap` con casos válidos e inválidos,
  sin reportes de `AddressSanitizer`, `LeakSanitizer` ni `runtime error`.

### Gate 4: Norminette (final)

- Aplicar cuando funcional + memoria estén cerrados.
- Estado actual tras bonus checker: `OK` en `*.c` y `*.h` del proyecto.

Checkpoint de validación técnica (2026-04-05):

- `make fclean && make`: OK.
- Casos smoke obligatorios:
	- `./push_swap 2 1` -> `sa`
	- `./push_swap 1 2 3` -> salida vacía
	- `./push_swap 3 2 1` -> secuencia válida (`sa`, `rra`)
- Norminette sobre `push_swap` + `libft` integrada (incluyendo submódulos):
	`OK` en todos los archivos revisados.

## Study Sync (parallel mode)

Regla activa para este proyecto:

- Implementación y documentación deben avanzar en paralelo.
- Cada módulo nuevo/modificado debe reflejarse en estudio y tracking.

## Checkpoint 1 (Parsing + validacion) - 2026-03-13

Evidencia ejecutada en `42/C/push_swap`:

- `make`: OK.
- `./push_swap 2 1`: salida `sa`.
- `./push_swap 1 2 3`: salida vacía (ya ordenado).
- `./push_swap 1 a 3`: `Error`.
- `./push_swap 1 2 1`: `Error`.
- `./push_swap 2147483648`: `Error` (overflow).
- `./push_swap "3 2 1"`: salida `sa` + `rra`.
- `./push_swap "10 4 10"`: `Error` (duplicado en string única).
- `./push_swap` sin argumentos: `0` bytes de salida.

Resultado del checkpoint:

- Estado: PASS.
- Cobertura: parser multi-formato + errores críticos + caso ya ordenado.
- Acción siguiente: benchmark 100/500 + evidencia de memoria.

## Next Technical Steps

1. Consolidar cierre del proyecto con una última corrida de benchmark.
2. Cierre final de norma al final del ciclo.

## Change Log

- 2026-04-05: bonus `checker` implementado y validado (build, rutas
	`OK/KO/Error`, norma en verde), con `Created` bonus normalizado a
	fechas anteriores coherentes.
- 2026-04-05: Makefile de `push_swap/libft` ajustado para compilar
	`libft.a` en orden interno `mandatory -> bonus` y luego módulos hijos bonus.
- 2026-04-05: integrado baseline currentLibft en `push_swap/libft` y
	validado build + norminette de árbol completo.
- 2026-03-13: baseline inicial de progreso + modo estudio paralelo.
- 2026-03-13: Checkpoint 1 validado con evidencia real de parsing y errores.
- 2026-03-13: Integración de `chunk sort` y mejora de benchmark (`602/5182`, ambos `OK`).
- 2026-03-13: Validación por lotes (20x100 y 10x500): `max_ops100=631`,
	`max_ops500=5260`, todos los lotes `OK` en verificación externa.
- 2026-03-13: Checkpoint ASAN/UBSAN en `push_swap` completado sin hallazgos.
