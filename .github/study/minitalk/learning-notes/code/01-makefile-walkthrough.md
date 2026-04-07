# Code 01 - Makefile Walkthrough

Archivo analizado:
- 42/C/minitalk/Makefile

## Lectura por bloques

1. Variables base
- CC, CFLAGS, RM.

2. Nombres de ejecutables
- server/client mandatory,
- server_bonus/client_bonus bonus.

3. Dependencias de libreria
- LIBFT_A = libft/libft.a.
- target para construir libft: $(MAKE) -C libft.

4. Agrupacion de fuentes y objetos
- comunes, server, client,
- bonus server/client/utils.

5. Targets principales
- all: construye mandatory.
- bonus: construye bonus.
- clean/fclean/re: limpieza y recompilacion.

## Ejemplo de ejecucion real

make
- genera libft si hace falta,
- compila objetos,
- enlaza server y client.

make bonus
- reutiliza comunes,
- compila objetos bonus,
- enlaza server_bonus y client_bonus.

## Relink en este Makefile

Como comprobar:
1. make
2. make
3. make bonus
4. make bonus

Esperado:
- segunda ejecucion de cada comando no deberia relinkar si no hubo cambios.

## Nota de auditoria

El subject pide archivos bonus en _bonus.c/_bonus.h.
En este proyecto existe utils_bonus.c con sufijo `_bonus` en nombre.
La separacion mandatory/bonus queda alineada con el subject.

## Change Log

- 2026-04-05: analisis inicial del Makefile.
