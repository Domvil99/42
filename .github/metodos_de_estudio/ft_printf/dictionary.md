# ft_printf Dictionary

Glosario tecnico de `ft_printf` para consolidar parser y salida.

## Entradas

### Format specifier
- Definicion: conversion indicada por `%` para imprimir un tipo concreto.
- Mini ejemplo: `%d` para entero con signo, `%x` para hexadecimal minuscula.

### Variadic arguments
- Definicion: lista de argumentos variable gestionada con `stdarg.h`.
- Mini ejemplo: `va_start(args, format)` y luego `va_arg(args, int)`.

### Parser state
- Definicion: punto del recorrido de `format` y accion asociada.
- Mini ejemplo: al ver `%`, cambiar a modo parseo de especificador.

### Return count
- Definicion: numero total de caracteres impresos por la funcion.
- Mini ejemplo: `ft_printf("A%d", 7)` retorna `2`.

### Conversion dispatcher
- Definicion: selector que deriva cada specifier a su handler.
- Mini ejemplo: `%p` llama a rutina de puntero con prefijo `0x`.

### Hex alphabet
- Definicion: conjunto de digitos para base 16 en lower/upper.
- Mini ejemplo: `%X` usa `ABCDEF`, `%x` usa `abcdef`.

### Null string policy
- Definicion: comportamiento al imprimir string `NULL`.
- Mini ejemplo: imprimir `(null)` y contar 6 caracteres.

### Parity test
- Definicion: comparacion de salida y retorno contra `printf` real.
- Mini ejemplo: matriz mandatory/bonus con `RET_TOTAL` igual a referencia.
