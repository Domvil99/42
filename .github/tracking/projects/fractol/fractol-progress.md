# fractol Progress

## Current Status

- Project: 42/C/fract'ol
- Stage: in-progress
- Scope: mandatory + bonus base integrada (cierre tecnico parcial completado)

## Gates

1. Scope/spec
- [x] Subject importado en 42/PDFs/2026-04-14_fract'ol.txt
- [x] Estructura base de archivos mandatory creada
- [x] Integracion de libft desde currentLibft

2. Functional
- [x] Parseo CLI base implementado
- [x] Estructura de render y eventos implementada
- [x] Build completo de fractol en entorno local (`make`, `make re`, `make bonus`)
- [ ] Smoke test mandelbrot con display X11 activo
- [ ] Smoke test julia con display X11 activo
- [x] Smoke test CLI sin argumentos / argumentos invalidos (mandatory + bonus)

3. Memory/stability
- [x] Valgrind en rutas CLI invalidas (mandatory + bonus) sin errores
- [ ] Verificacion de salida limpia por ESC (sesion grafica)
- [ ] Verificacion de salida limpia por cierre de ventana (sesion grafica)
- [ ] Verificacion de leaks en sesion grafica

4. Norminette (final)
- [x] Cabeceras 42 en archivos de fractol
- [x] Barrido final norminette sin errores (`Error:`) en mandatory + bonus

## Latest validation snapshot

- Mandatory:
	- Build: OK (`make fclean && make`)
	- CLI errores: OK (salida de ayuda + `exit=1`)
	- Smoke arranque con args validos: OK (`timeout` -> `exit=124`, sin stderr)
	- Valgrind en CLI invalida: OK (`ERROR SUMMARY: 0 errors`)
- Bonus:
	- Build: OK (`make bonus`)
	- CLI errores: OK (salida de ayuda + `exit=1`)
	- Smoke arranque con args validos: OK (`timeout` -> `exit=124`, sin stderr)
	- Valgrind en CLI invalida: OK (`ERROR SUMMARY: 0 errors`)
- Norminette:
	- Barrido de `*.c` y `*.h`: OK, sin lineas `Error:`

## Known blocker

- Validacion grafica interactiva depende de sesion X11 activa; en entorno
	headless solo se puede cerrar la validacion de build/CLI/norminette.
- En este entorno no hay utilidades de automatizacion X11 detectadas
	(`xvfb-run`/`xdotool`) para forzar eventos ESC/cierre de ventana.
