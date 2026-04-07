# Code 02 - Headers y Tipos

Archivos analizados:
- 42/C/minitalk/minitalk.h
- 42/C/minitalk/minitalk_bonus.h

## minitalk.h

Define:
- includes necesarios,
- macros de protocolo:
  - MT_SIG_ONE = SIGUSR1
  - MT_SIG_ZERO = SIGUSR2
  - MT_BIT_DELAY_US = 900
- tipo t_server_state para ensamblar bytes:
  - current_char,
  - bit_index,
  - active_client.
- prototipos mandatory:
  - parse PID,
  - send char,
  - send message,
  - write error.

## minitalk_bonus.h

Extiende mandatory con prototipos bonus:
- mt_bonus_send_char,
- mt_bonus_send_message,
con flag volatile sig_atomic_t para ACK.

## Justificacion didactica del estado global

t_server_state global en server/server_bonus permite mantener estado entre
llamadas del signal handler.
Sin esto, no se podria reconstruir un byte completo a partir de 8 senales.

## Change Log

- 2026-04-05: lectura de headers y tipos.
