# Code 03 - Mandatory Flow (.c)

Archivos analizados:
- 42/C/minitalk/client.c
- 42/C/minitalk/parse_utils.c
- 42/C/minitalk/signals_utils.c
- 42/C/minitalk/server.c

## Flujo de client.c

1. validate_args:
- exige argc == 3,
- valida PID con mt_parse_pid.

2. main:
- llama mt_send_message(server_pid, mensaje).
- si falla, imprime error y sale 1.

## Flujo de parse_utils.c

- mt_parse_pid:
  - valida solo digitos,
  - evita overflow con INT_MAX,
  - exige PID > 0.
- mt_write_error:
  - escribe en stderr.

## Flujo de signals_utils.c

- mt_send_char:
  - recorre bit 7 a 0,
  - envia SIGUSR1 (1) o SIGUSR2 (0),
  - hace usleep entre bits.
- mt_send_message:
  - envia todos los caracteres,
  - envia byte nulo final (\0).

## Flujo de server.c

- setup_signals:
  - registra handle_signal para SIGUSR1 y SIGUSR2.
- handle_signal:
  - actualiza estado por PID emisor,
  - setea bit en current_char cuando llega SIGUSR1,
  - al completar 8 bits imprime caracter o salto de linea si es \0.

## Conclusion tecnica

Mandatory usa temporizacion (usleep) para reducir colisiones, pero sin ACK
sigue existiendo riesgo teorico de perdida de senales bajo carga.

## Change Log

- 2026-04-05: analisis flujo mandatory.
