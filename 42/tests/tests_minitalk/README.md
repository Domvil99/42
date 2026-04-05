# tests_minitalk

Directorio de pruebas C portables para validar obligatorio de `minitalk`.

## Que hay aqui
- `test_minitalk_portable_strict.c`: levanta `server`, ejecuta `client`
  varias veces y valida que los mensajes llegan.
- `test_minitalk_invalid_pid.c`: valida manejo de PID invalido en cliente.

## Uso portable solo con C (sin .sh)
1. Compilar tests:
`cc -Wall -Wextra -Werror test_minitalk_portable_strict.c -o /tmp/test_minitalk_portable`
`cc -Wall -Wextra -Werror test_minitalk_invalid_pid.c -o /tmp/test_minitalk_badpid`

2. Ejecutar contra cualquier repo:
`/tmp/test_minitalk_portable <RUTA_SERVER_BIN> <RUTA_CLIENT_BIN>`
`/tmp/test_minitalk_badpid <RUTA_CLIENT_BIN>`

Ejemplo en este workspace:
`/tmp/test_minitalk_portable ../../C/minitalk/server ../../C/minitalk/client`
`/tmp/test_minitalk_badpid ../../C/minitalk/client`

## Criterio estricto
- Debe verse PID del servidor y recepción correcta de mensajes.
- Cliente debe fallar en PID inválido.
- Sin segfaults ni comportamiento inesperado.
