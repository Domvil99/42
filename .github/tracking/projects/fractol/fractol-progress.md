# fractol Progress

## Current Status

- Project: 42/C/fract'ol
- Stage: in-progress
- Scope: mandatory only

## Gates

1. Scope/spec
- [x] Subject importado en 42/PDFs/2026-04-14_fract'ol.txt
- [x] Estructura base de archivos mandatory creada
- [x] Integracion de libft desde currentLibft

2. Functional
- [x] Parseo CLI base implementado
- [x] Estructura de render y eventos implementada
- [ ] Build completo de fractol en entorno local
- [ ] Smoke test mandelbrot
- [ ] Smoke test julia

3. Memory/stability
- [ ] Verificacion de salida limpia por ESC
- [ ] Verificacion de salida limpia por cierre de ventana
- [ ] Verificacion de leaks

4. Norminette (final)
- [ ] Cabeceras 42 en archivos de fractol
- [ ] Barrido final norminette sin errores

## Known blocker

- MiniLibX no compila por dependencia de includes X11 ausentes en el sistema local.
