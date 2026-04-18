# Code 03 - Mandatory Flow (.c)

Archivos analizados:
- 42/C/fract'ol/main.c
- 42/C/fract'ol/parse_args.c
- 42/C/fract'ol/init.c
- 42/C/fract'ol/render.c
- 42/C/fract'ol/fractal_calc.c
- 42/C/fract'ol/events.c
- 42/C/fract'ol/utils.c

## Flujo de alto nivel

1. main valida args y decide fractal,
2. init prepara MLX y buffer,
3. render recorre pixeles,
4. fractal_calc devuelve iteraciones/color,
5. events recibe input y relanza render,
6. salida limpia por ruta comun.

## Conclusión tecnica

La calidad final depende de tres cosas: mapeo correcto, iteracion correcta y
control de eventos sin romper limpieza.

## Change Log

- 2026-04-16: analisis inicial del flujo mandatory.
