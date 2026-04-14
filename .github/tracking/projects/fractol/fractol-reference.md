# fractol Reference

## Build order

1. make -C libft all
2. make -C libft bonus
3. make fractol mandatory
4. (future) make bonus

## Fractal formulas

- Mandelbrot:
  - z0 = 0
  - z(n + 1) = z(n)^2 + c
- Julia:
  - z0 = pixel mapped to complex plane
  - z(n + 1) = z(n)^2 + c (constant c from CLI)

## Mandatory controls

- ESC: cerrar programa
- Window close (X): cerrar programa
- Mouse wheel up/down: zoom in/out
- CLI invalida: mostrar ayuda y terminar correctamente

## Notes

- Sin variables globales.
- Render obligatorio mediante imagen MiniLibX.
- Color por profundidad de iteracion.
