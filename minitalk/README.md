*Este proyecto ha sido creado como parte del curriculo de 42 por saospina.*

# minitalk

## Descripcion
`minitalk` implementa un canal de comunicacion cliente-servidor usando solo
senales UNIX (`SIGUSR1` y `SIGUSR2`).

- `server` imprime su PID al iniciar.
- `client` recibe PID + string y la transmite bit a bit.
- El servidor reconstruye bytes y muestra el mensaje cuando recibe `\0`.

La implementacion mantiene separacion estricta entre obligatorio y bonus.

Bonus implementado:
- `server_bonus` responde ACK por cada bit recibido.
- `client_bonus` espera ACK por bit para evitar perdida de senales.
- El flujo transmite bytes UTF-8 completos (mensajes Unicode incluidos).

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

### Compilar bonus
`make bonus`

### Ejecutar bonus
1. `./server_bonus`
2. En otra terminal: `./client_bonus <PID_DEL_SERVER> "mensaje"`

## Recursos
- `signal(2)` / `sigaction(2)` / `kill(2)` / `pause(2)`
- Linux man-pages project: https://man7.org/linux/man-pages/

## Uso de IA
Se utilizo IA para:
- estructurar plan tecnico y orden de validacion,
- acelerar redaccion de documentacion y comandos de prueba,
- revisar consistencia de manejo de errores y edge cases.

Toda la logica final fue validada localmente con compilacion y pruebas de
comunicacion real entre `client` y `server`.
