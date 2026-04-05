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

## 3. Bonus Skeleton (separado)

- `server_bonus.c`
  - `main` placeholder
- `client_bonus.c`
  - `main` placeholder
- `bonus_utils.c`
  - `mt_bonus_placeholder`
- `minitalk_bonus.h`
  - contrato base bonus

Estado: esqueleto compilable, sin logica bonus activa.

## 4. Libft Integration Surface

Base local copiada desde `42/C/currentLibft/libft` a `42/C/minitalk/libft`.

Funciones usadas en obligatorio:
- `ft_isdigit`
- `ft_strlen`
- `ft_putstr_fd`
- `ft_putnbr_fd`

## Pending Functional Gaps

- Bonus funcional (ACK por senal y soporte Unicode): pendiente por diseno.
