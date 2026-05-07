# fractol Reference

## Build order

1. make -C libft full
2. make fractol (mandatory)
3. make bonus

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
- C: cambiar paleta
- CLI invalida: mostrar ayuda y terminar correctamente

## Notes

- Sin variables globales.
- Render obligatorio mediante imagen MiniLibX.
- Color por profundidad de iteracion.
- Validaciones locales ya ejecutadas:
  - `make fclean && make`: OK
  - `make bonus`: OK
  - CLI invalida en mandatory y bonus: ayuda correcta + `exit=1`
  - Valgrind en CLI invalida mandatory/bonus: `ERROR SUMMARY: 0 errors`
  - Norminette `*.c`/`*.h`: OK sin `Error:`
- Validacion grafica completa requiere entorno con display X11 activo.
