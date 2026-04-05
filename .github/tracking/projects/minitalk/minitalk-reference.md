# minitalk Reference

## 1. Deliverable Scope

Mandatory:
- `server`
- `client`
- `Makefile`, `*.h`, `*.c`, `libft/`

Bonus (en esta fase):
- skeleton separado (`server_bonus`, `client_bonus`, `*_bonus.c/h`).

## 2. Input/Output Contract

Server:
- Imprime su PID al iniciar.
- Muestra mensajes recibidos al reconstruir bytes hasta `\0`.

Client:
- Recibe `<server_pid> <message>`.
- Envia cada byte bit a bit usando solo `SIGUSR1` y `SIGUSR2`.

## 3. Bit Protocol (mandatory)

- `SIGUSR1` representa bit `1`.
- `SIGUSR2` representa bit `0`.
- Orden de envio: MSB -> LSB (bit 7 a bit 0).
- Terminador de mensaje: byte `\0`.

## 4. Makefile Reference

Targets requeridos:
- `all` -> `server` + `client`
- `bonus` -> `server_bonus` + `client_bonus` (placeholder)
- `clean`, `fclean`, `re`

## 5. Validation Commands

```bash
cd 42/C/minitalk
make
./server
./client <PID> "hola"
make bonus
```

Tests portables (sin scripts):

```bash
cd 42/tests/tests_minitalk
cc -Wall -Wextra -Werror test_minitalk_portable_strict.c -o /tmp/test_minitalk_portable
cc -Wall -Wextra -Werror test_minitalk_invalid_pid.c -o /tmp/test_minitalk_badpid
/tmp/test_minitalk_portable ../../C/minitalk/server ../../C/minitalk/client
/tmp/test_minitalk_badpid ../../C/minitalk/client
```

## 6. Common Failure Patterns

1. Envio demasiado rapido y perdida de senales.
2. Parseo de PID invalido sin error explicito.
3. No enviar `\0` final y dejar servidor sin flush de mensaje.
4. Mezclar obligatorio y bonus en mismos archivos.
