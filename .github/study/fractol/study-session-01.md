# Sesion 01 - Inicio Guiado de fractol

Objetivo: dominar el flujo obligatorio de fractol sin asumir base previa de fractales.
Duracion sugerida: 70-90 minutos.

## Material

1. fractol.md
2. implementation.md
3. dictionary.md
4. validation.md
5. defense.md

## Bloques

### Bloque A (20 min) - Modelo mental

1. diferenciar Mandelbrot vs Julia,
2. entender pixel -> complejo,
3. entender iteracion y escape.

Resultado esperado:
- explicar como sale un color desde un pixel.

### Bloque B (20 min) - Flujo de codigo

1. leer main.c y parse_args.c,
2. seguir init.c,
3. ubicar render principal.

Resultado esperado:
- trazar camino desde argv hasta primer frame.

### Bloque C (20 min) - Render y eventos

1. leer render.c y fractal_calc.c,
2. leer events.c,
3. entender zoom + paleta.

Resultado esperado:
- explicar por que cada accion redibuja todo.

### Bloque D (10 min) - Validacion

1. repasar casos validos/invalidos,
2. repasar cierre limpio,
3. repasar controles del usuario.

### Bloque E (5 min) - Cierre

Escribir 3 lineas:
1. concepto mas claro,
2. duda activa,
3. siguiente paso.

## Mini checklist

- [ ] entiendo diferencia Mandelbrot/Julia
- [ ] entiendo mapeo pixel -> complejo
- [ ] entiendo escape-time
- [ ] entiendo zoom y redibujado

## Change Log

- 2026-04-16: sesion inicial de estudio para fractol.
