# Code 05 - Allowed Functions Audit

Referencia de subject:
- 42/PDFs/2026-04-05_minitalk.txt (Cap. III)

Funciones permitidas en mandatory segun subject:
- write
- ft_printf o equivalente propio
- signal
- sigemptyset
- sigaddset
- sigaction
- kill
- getpid
- malloc
- free
- pause
- sleep
- usleep
- exit

## Auditoria en el codigo actual

Usadas directamente en mandatory:
- write
- sigemptyset
- sigaction
- kill
- getpid
- pause
- usleep

Usadas via funciones propias/libft (equivalente permitido):
- ft_putstr_fd / ft_putnbr_fd / ft_strlen / ft_isdigit

No observadas en mandatory (pero permitidas):
- signal
- sigaddset
- malloc
- free
- sleep
- exit

## Bonus y funciones

En bonus se siguen usando funciones dentro del set permitido
(sigaction, sigemptyset, kill, pause, write, getpid, etc.).

No se detecta uso de funciones fuera del set permitido en los archivos
revisados de minitalk.

## Nota de metodologia

Esta auditoria es estatico-documental sobre los archivos fuente presentes.
Conviene complementarla con build y pruebas reales en tu entorno.

## Change Log

- 2026-04-05: auditoria inicial de funciones permitidas.
