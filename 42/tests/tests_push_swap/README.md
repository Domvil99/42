# tests_push_swap

Directorio de pruebas rígidas para validar `42/C/push_swap` y su `checker`.

## Qué hay aquí
- `test_push_swap_portable_strict.c`: prueba portable con casos de error y
	casos funcionales pasando rutas de binarios por parámetro.

## Uso portable solo con C (sin .sh)
1. Compila el test:
`cc -Wall -Wextra -Werror test_push_swap_portable_strict.c -o test_push_swap_portable`
2. Ejecútalo pasando rutas del repo a evaluar:
`./test_push_swap_portable <RUTA_PUSH_SWAP_BIN> <RUTA_CHECKER_BIN>`

Ejemplo:
`./test_push_swap_portable /tmp/peer/push_swap/push_swap /tmp/peer/push_swap/checker`

## Criterio estricto
- Error handling: duplicados, tokens inválidos y formatos incorrectos.
- Correctitud: toda secuencia debe validar en `checker` con `OK`.
- Rendimiento mínimo:
	- para n=5, límite de 12 operaciones,
	- para n=100, techo de sanidad (falla si se dispara por encima de 7000).

## Orden de validación
1. Scope/spec (`42/PDFs/2026-03-13_push_swap_actualizado.txt`).
2. Funcional (esta carpeta).
3. Memoria/estabilidad.
4. Norminette al cierre.

## Regla para proyectos nuevos
Cada proyecto nuevo en `42/C/` debe incorporar tests C portables que
comprueben al menos: casos válidos, inválidos y stress básico.
