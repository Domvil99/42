# 02 - Build y Makefile

## Como compila el proyecto

Objetivos principales:

- make -> genera fractol,
- make bonus -> genera fractol_bonus.

## Dependencias del Makefile

1. libft (local),
2. minilibx-linux (local).

## Orden de compilacion observado

1. compilar libft,
2. compilar mlx,
3. compilar objetos de fractol,
4. enlazar binario final.

## Que significa relink

Relink es volver a enlazar el ejecutable aunque no cambie nada relevante.

Impacto:
- compila mas lento,
- dificulta incremental build limpio.

## Como evitar relink

1. declarar dependencias correctas por objeto,
2. no forzar reglas all/re sin necesidad,
3. no tocar timestamps de forma artificial,
4. mantener clean/fclean separados.

## Comandos utiles

- make
- make bonus
- make clean
- make fclean
- make re

## Change Log

- 2026-04-16: respuestas iniciales de build y Makefile.
