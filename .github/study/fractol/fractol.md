# fractol Study Report

Nota de estado (2026-04-16): proyecto fractol marcado como terminado por el usuario.
Este reporte sirve como base de estudio tecnico y preparacion de defensa.

## 1. Vision del proyecto

fractol es un renderizador de fractales en MiniLibX.
En mandatory, el foco es dibujar Mandelbrot y Julia de forma interactiva.

Objetivo de aprendizaje:

- entender mapeo pixel -> plano complejo,
- dominar escape-time algorithm,
- construir render en buffer de imagen,
- manejar eventos de zoom y paleta.

## 2. Subject y reglas clave

Referencia canonica:
- 42/PDFs/2026-04-14_fract'ol.txt

Reglas operativas clave:

- ejecutable obligatorio: fractol,
- argumentos validos: mandelbrot o julia <re> <im>,
- cierre limpio con ESC y cruz de ventana,
- uso de MiniLibX,
- sin crashes ni leaks.

## 3. Arquitectura mental completa

Pipeline de ejecucion:

1. parsear argumentos,
2. inicializar app y recursos MLX,
3. configurar vista inicial y parametros,
4. renderizar frame completo,
5. registrar hooks de teclado/raton,
6. entrar en loop de eventos.

## 4. Mapa de archivos

- main.c: entrypoint y hooks.
- parse_args.c: validacion de CLI.
- init.c: init MLX, ventana e imagen.
- render.c: bucle de pixeles y put_image.
- fractal_calc.c: iteraciones y color.
- events.c: teclado, raton, cierre.
- utils.c: parse numerico y utilidades.
- fractol.h: structs y prototipos.

## 5. Riesgos tecnicos principales

1. mapeo incorrecto del plano complejo,
2. zoom descentrado o inestable,
3. costo alto por pixel con iteraciones elevadas,
4. errores de liberacion de recursos MLX.

## 6. Constantes y defaults reales

Valores actuales en el codigo de /fractol:

- WIDTH = 900
- HEIGHT = 700
- MAX_ITER inicial = 80
- view inicial:
	- min_re = -2.0
	- max_re = 2.0
	- min_im = -1.6
	- max_im = 1.6
- palette_shift inicial = 0
- escape interno: (z.re^2 + z.im^2) <= 4.0

Colorizacion actual (fractal_calc.c):

- r = (iter * 9 + shift) % 255
- g = (iter * 7 + shift * 2) % 255
- b = (iter * 13 + shift * 3) % 255

## 7. Ruta de lectura recomendada

1. fractol.md (este archivo)
2. implementation.md
3. validation.md
4. defense.md
5. dictionary.md
6. study-session-01.md

## Change Log

- 2026-04-16: creacion inicial del reporte de estudio para fractol.
- 2026-04-18: agregado bloque de constantes/defaults reales y detalle exacto
	de escape y colorizacion segun codigo actual.
