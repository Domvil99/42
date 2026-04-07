# minitalk Validation Guide

Orden recomendado de validacion:

1. comportamiento segun subject,
2. estabilidad/memoria,
3. norma al cierre.

## 1. Build

```bash
cd 42/C/minitalk
make
make bonus
```

Esperado:

- genera `server`, `client`, `server_bonus`, `client_bonus`.

## 2. Funcional mandatory

Caso base:

```bash
# terminal A
./server

# terminal B
./client <PID_SERVER> "Hola"
```

Esperado:

- servidor imprime `Hola` y salto de linea.

Casos de error:

- PID invalido: debe fallar con mensaje de error.
- argumentos faltantes: debe mostrar uso correcto.

## 3. Funcional bonus

```bash
# terminal A
./server_bonus

# terminal B
./client_bonus <PID_SERVER> "Mensaje con ACK"
```

Esperado:

- envio estable, sin perdida de caracteres.

## 4. Clientes consecutivos

Probar 2 terminales cliente sobre mismo servidor sin reiniciar.

Esperado:

- servidor procesa ambos mensajes en orden de llegada,
- no requiere reinicio entre clientes.

## 5. Unicode (bonus)

```bash
./client_bonus <PID_SERVER> "Hola ñ €"
```

Esperado:

- se transmiten bytes UTF-8 completos,
- no se rompe stream por caracteres multibyte.

## 6. Estabilidad y memoria

Revisar con valgrind en cliente y servidor con ejecucion corta.

Objetivo:

- sin leaks,
- sin invalid read/write,
- sin crashes al finalizar.

## 7. Norma (paso final)

Ejecutar norminette al final sobre todos los `.c` y `.h` del proyecto.

## Checklist rapido

- [ ] mandatory envia/recibe mensaje completo
- [ ] bonus confirma por ACK
- [ ] errores de argumentos controlados
- [ ] servidor acepta clientes consecutivos
- [ ] sin leaks/crashes
- [ ] norma limpia al cierre

## Change Log

- 2026-04-05: guia inicial de validacion para `minitalk`.
