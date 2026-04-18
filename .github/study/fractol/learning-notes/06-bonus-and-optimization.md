# 06 - Bonus y Optimizacion

## Que suele incluir el bonus en fractol

Depende del proyecto concreto, pero normalmente:

- fractales extra,
- controles adicionales,
- mejoras de color,
- navegacion mas fina.

## Dónde optimizar primero

1. bucle de pixeles (render.c),
2. funcion de iteracion (fractal_calc.c),
3. evitar recalculos innecesarios,
4. ajustar max_iter dinamico en zoom profundo.

## Estrategias practicas

1. precalcular rangos y escalas por frame,
2. usar tipos consistentes (double donde toca),
3. minimizar operaciones dentro del inner loop,
4. reducir redibujados redundantes.

## Estabilidad visual

- mantener continuidad de paleta,
- evitar saltos bruscos de zoom,
- revisar precision numerica en niveles altos.

## Indicador de mejora real

Una optimizacion es util si:

- mantiene mismo resultado visual esperado,
- reduce tiempo por frame,
- no rompe controles ni limpieza.

## Change Log

- 2026-04-16: respuestas iniciales de bonus y optimizacion.
