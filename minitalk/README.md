*Este proyecto ha sido creado como parte del curriculo de 42 por saospina.*

# minitalk

## Descripcion
`minitalk` implementa un canal de comunicacion cliente-servidor usando solo
senales UNIX (`SIGUSR1` y `SIGUSR2`).

- `server` imprime su PID al iniciar.
- `client` recibe PID + string y la transmite bit a bit.
- El servidor reconstruye bytes y muestra el mensaje cuando recibe `\0`.

En esta fase se entrega obligatorio completo y se deja bonus en esqueleto
separado para evolucion posterior.

## Instrucciones
### Compilar obligatorio
`make`

### Ejecutar obligatorio
1. `./server`
2. En otra terminal: `./client <PID_DEL_SERVER> "mensaje"`

### Limpiar
- `make clean`
- `make fclean`
- `make re`

### Compilar skeleton bonus (sin logica bonus activa)
`make bonus`

Genera `server_bonus` y `client_bonus` como placeholders separados.

## Recursos
- `signal(2)` / `sigaction(2)` / `kill(2)` / `pause(2)`
- 42 subject: `42/PDFs/2026-04-05_minitalk.txt`
- Linux man-pages project: https://man7.org/linux/man-pages/

## Uso de IA
Se utilizo IA para:
- estructurar plan tecnico y orden de validacion,
- acelerar redaccion de documentacion y comandos de prueba,
- revisar consistencia de manejo de errores y edge cases.

Toda la logica final fue validada localmente con compilacion y pruebas de
comunicacion real entre `client` y `server`.
