# fractol Progress

## Current Status

- Project: 42/C/fract'ol
- Stage: in-progress
- Scope: mandatory + bonus base integrada

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
- [x] Smoke test CLI sin argumentos / argumentos invalidos

3. Memory/stability
- [ ] Verificacion de salida limpia por ESC (sesion grafica)
- [ ] Verificacion de salida limpia por cierre de ventana (sesion grafica)
- [ ] Verificacion de leaks en sesion grafica

4. Norminette (final)
- [x] Cabeceras 42 en archivos de fractol
- [x] Barrido final norminette sin errores (`Error:`)

## Known blocker

- Validacion grafica interactiva depende de sesion X11 activa; en entorno
	headless solo se puede cerrar la validacion de build/CLI/norminette.
