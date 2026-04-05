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
  - `mt_parse_pid`
  - `mt_write_error`

- `signals_utils.c`
  - `mt_send_char`
  - `mt_send_message`

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
  - `mt_bonus_send_char` (envio de byte con sincronizacion ACK por bit)
  - `mt_bonus_send_message` (envio de string + terminador `\0`)
- `minitalk_bonus.h`
  - contrato de envio bonus

Estado: implementado.

## 4. Libft Integration Surface

Base local copiada desde `42/C/currentLibft/libft` a `42/C/minitalk/libft`.

Funciones usadas en obligatorio:
- `ft_isdigit`
- `ft_strlen`
- `ft_putstr_fd`
- `ft_putnbr_fd`

Funciones usadas en bonus:
- `ft_isdigit`
- `ft_putstr_fd`
- `ft_putnbr_fd`

## Pending Functional Gaps

- Sin gaps funcionales abiertos en alcance mandatory+bonus.
