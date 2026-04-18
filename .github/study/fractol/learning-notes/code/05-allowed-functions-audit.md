# Code 05 - Allowed Functions Audit

Objetivo:
- comprobar que el proyecto usa funciones alineadas con reglas del subject,
- detectar usos de librerias externas fuera de lo esperado.

## Fuentes previstas por proyecto

- libc basica permitida por 42,
- libft local,
- MiniLibX para ventana/imagen/eventos,
- math library para calculos.

## Checklist de auditoria

1. revisar includes de cada .c,
2. listar llamadas a API MLX,
3. listar llamadas de sistema relevantes (si aplica),
4. confirmar que no hay funciones prohibidas por subject.

## Resultado esperado

- mandatory y bonus se apoyan en libft + MLX,
- sin atajos fuera de las reglas del proyecto.

## Change Log

- 2026-04-16: plantilla de auditoria inicial para fractol.
