# minitalk Functions Map

## Scope

Mapa funcional del proyecto `42/C/minitalk` para seguimiento tecnico.

## 1. Mandatory Binaries

- `server`
  - `main` (arranque + setup senales + loop `pause`)
  - `handle_signal` (reconstruccion de byte con SIGUSR1/SIGUSR2)
  - `reset_state` (limpieza del estado global del servidor)
  - `setup_signals` (registro `sigaction`)

- `client`
  - `main` (parseo args + envio de mensaje)
  - `validate_args` (validacion de argc/PID)

Estado: implementado.

## 2. Shared Utilities

- `parse_utils.c`
  - `ft_parse_pid`
  - `ft_write_error`

- `signals_utils.c`
  - `ft_sigcomm_send_byte`
  - `ft_sigcomm_send_string`

Estado: implementado.

## 3. Bonus (separado)

- `server_bonus.c`
  - `main` (arranque + setup senales + loop `pause`)
  - `handle_signal` (reconstruccion de byte + ACK por bit)
  - `reset_state` (limpieza del estado global del servidor bonus)
  - `setup_signals` (registro `sigaction`)
- `client_bonus.c`
  - `main` (parseo args + setup handler ACK + envio de mensaje)
  - `validate_args` (validacion de argc/PID)
  - `handle_ack` (marca ACK recibido)
  - `setup_ack_handler` (registro `sigaction` para ACK)
- `bonus_utils.c`
  - `ft_sigcomm_send_byte_ack` (envio de byte con ACK por bit)
  - `ft_sigcomm_send_string_ack` (envio de string + terminador `\0`)
- `minitalk_bonus.h`
  - contrato de envio bonus

Estado: implementado.

## 4. Libft Integration Surface

Base local copiada desde `42/C/currentLibft/libft` a `42/C/minitalk/libft`.

Funciones usadas en obligatorio:
- `ft_isdigit`
- `ft_putstr_fd`
- `ft_putnbr_fd`

Funciones usadas en bonus:
- `ft_isdigit`
- `ft_putstr_fd`
- `ft_putnbr_fd`

## 5. Build Chain Notes

- `make` en minitalk fuerza compilacion de `libft/` completa en orden:
  mandatory -> bonus.
- Se compilan tambien modulos integrados en `libft/ft_printf` y
  `libft/get_next_line` (mandatory -> bonus).
- Resultado verificado: todos los `*.c` de la libft integrada generan `*.o`.

## Pending Functional Gaps

- Sin gaps funcionales abiertos en alcance mandatory+bonus.
