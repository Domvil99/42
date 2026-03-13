# push_swap Progress

## Current Status

Proyecto: `42/C/push_swap`
Estado: in-progress

## Milestones

1. Subject canónico disponible y traducido.
2. Estructura base mandatory implementada.
3. Parser y operaciones implementadas.
4. Estrategias de ordenación (small + radix) implementadas.
5. Optimización por `chunk sort` integrada para mejorar benchmark 100/500.
6. Bonus `checker` implementado en `checker_bonus.c` y regla `bonus` añadida al Makefile.
7. Informe de estudio creado en paralelo (núcleo + anexos).

## Quality Gates

### Gate 1: Scope/spec

- Mandatory `push_swap`: implementado.
- Bonus `checker`: pendiente.

### Gate 2: Functional

- Casos simples y edge cases: validados con checker (`OK`) y errores controlados.
- Benchmarks 100/500: evidencia consolidada en muestra real:
	- 100 números: `602` operaciones (`OK`).
	- 500 números: `5182` operaciones (`OK`).

### Gate 3: Memory/stability

- Rutas de liberación presentes.
- ASAN/UBSAN ejecutado en `push_swap` y `checker` con casos válidos e inválidos,
  sin reportes de `AddressSanitizer`, `LeakSanitizer` ni `runtime error`.

### Gate 4: Norminette (final)

- Aplicar cuando funcional + memoria estén cerrados.

### Gate Bonus: checker

- `checker_bonus.c` implementado y conectado por regla `bonus` en Makefile.
- Pendiente: validación exhaustiva de instrucciones inválidas y cierre final con norma.

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

1. Consolidar cierre de obligatorio y bonus con una última corrida de benchmark.
2. Cierre final de norma al final del ciclo.

## Change Log

- 2026-03-13: baseline inicial de progreso + modo estudio paralelo.
- 2026-03-13: Checkpoint 1 validado con evidencia real de parsing y errores.
- 2026-03-13: Integración de `chunk sort` y mejora de benchmark (`602/5182`, ambos `OK`).
- 2026-03-13: Bonus `checker` añadido (`checker_bonus.c`) y Makefile con regla `bonus`.
- 2026-03-13: Validación por lotes (20x100 y 10x500): `max_ops100=631`,
  `max_ops500=5260`, todos los lotes `OK` con checker.
- 2026-03-13: Checkpoint ASAN/UBSAN en `push_swap` y `checker` completado sin hallazgos.
