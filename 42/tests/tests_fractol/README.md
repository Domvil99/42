# tests_fractol

Pruebas de validacion para fractol mandatory y bonus.

## Checklist rapido

- Mandatory:
	- Compilacion: `make fclean && make`
	- Render: `./fractol mandelbrot`
	- Render: `./fractol julia -0.7 0.27015`
	- Smoke no interactivo: `timeout 2s ./fractol mandelbrot` y
		`timeout 2s ./fractol julia -0.7 0.27015` (esperado `exit=124`)
	- Eventos: ESC, click cruz de ventana, zoom rueda
	- Error handling: argumentos invalidos muestran ayuda y salen con `exit=1`
- Bonus:
	- Compilacion: `make bonus`
	- Render: `./fractol_bonus mandelbrot`
	- Render: `./fractol_bonus julia -0.7 0.27015`
	- Smoke no interactivo: `timeout 2s ./fractol_bonus mandelbrot` y
		`timeout 2s ./fractol_bonus julia -0.7 0.27015` (esperado `exit=124`)
	- Eventos: ESC, click cruz de ventana, zoom rueda
	- Error handling: argumentos invalidos muestran ayuda y salen con `exit=1`
- Memoria:
	- Valgrind en ruta CLI invalida mandatory: `ERROR SUMMARY: 0 errors`
	- Valgrind en ruta CLI invalida bonus: `ERROR SUMMARY: 0 errors`

Nota de entorno:

- Las pruebas de render/eventos requieren una sesion grafica X11 activa.
	En entorno headless solo puede validarse build + parseo CLI + norminette +
	valgrind en rutas no graficas.
- En este entorno no se detectaron utilidades de automatizacion X11
	(`xvfb-run`/`xdotool`) para ejecutar validacion interactiva automatizada.
