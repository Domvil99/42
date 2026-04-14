# tests_fractol

Pruebas de validacion para fractol mandatory.

## Checklist rapido

- Compilacion: make, make re, make bonus, make fclean
- Render: ./fractol mandelbrot
- Render: ./fractol julia -0.7 0.27015
- Eventos: ESC, click cruz de ventana, zoom rueda
- Error handling: argumentos invalidos muestran ayuda y salen limpio
- Memoria: sin leaks en salida basica

Nota de entorno:

- Las pruebas de render/eventos requieren una sesion grafica X11 activa.
	En entorno headless solo puede validarse build + parseo CLI.
