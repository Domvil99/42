# Code 04 - Bonus Flow (.c)

Archivos analizados:
- 42/C/minitalk/client_bonus.c
- 42/C/minitalk/bonus_utils.c
- 42/C/minitalk/server_bonus.c

## Flujo de client_bonus.c

1. validate_args:
- misma validacion de PID que mandatory.

2. setup_ack_handler:
- registra handler para ACK (`SIGUSR1`).

3. handle_ack:
- cuando llega SIGUSR1, activa flag global de ACK.

4. main:
- llama mt_bonus_send_message con puntero a flag ACK.

## Flujo de bonus_utils.c

- mt_bonus_send_char:
  1. limpia flag ACK,
  2. envia un bit,
  3. espera ACK con pause(),
  4. repite para 8 bits.

- mt_bonus_send_message:
  - envia string + byte nulo final.

## Flujo de server_bonus.c

- handle_signal:
  1. reconstruye bit igual que mandatory,
  2. envia ACK al cliente con kill(info->si_pid, SIGUSR1),
  3. al completar 8 bits imprime caracter o salto de linea (si \0).

## Conclusion tecnica

Bonus agrega sincronizacion bit a bit y hace el canal mucho mas robusto frente
a perdida de senales.

## Change Log

- 2026-04-05: analisis flujo bonus.
