# minitalk Implementation Guide

Guia tecnica archivo por archivo para entender el flujo real.

## 1. client.c

Responsabilidad:

- validar argumentos,
- parsear PID,
- iniciar envio del mensaje.

Puntos de estudio:

1. `validate_args`: corta temprano ante uso invalido.
2. `mt_parse_pid`: evita PID no numerico o fuera de rango.
3. `mt_send_message`: envio completo del string + `\0` final.

## 2. signals_utils.c

Responsabilidad:

- convertir cada caracter en 8 bits,
- mapear bit 1 -> `SIGUSR1`, bit 0 -> `SIGUSR2`.

Puntos de estudio:

1. orden de bits: 7 a 0 (MSB a LSB),
2. `kill(server_pid, sig)` por cada bit,
3. delay entre bits para reducir colisiones en mandatory.

## 3. server.c

Responsabilidad:

- recibir senales,
- reconstruir byte en estado persistente,
- imprimir caracteres en orden.

Puntos de estudio:

1. estado global minimo para handlers asincronos,
2. acumulacion de bits sobre `current_char`,
3. cierre de mensaje al recibir byte nulo (`\0`).

## 4. bonus: client_bonus.c + utils_bonus.c

Responsabilidad:

- enviar bit y esperar ACK antes de continuar.

Puntos de estudio:

1. flag `volatile sig_atomic_t` para ACK,
2. `pause()` en espera activa por confirmacion,
3. control de sincronizacion por cada bit enviado.

## 5. bonus: server_bonus.c

Responsabilidad:

- reconstruir igual que mandatory,
- responder ACK al cliente por cada bit.

Puntos de estudio:

1. `kill(info->si_pid, SIGUSR1)` tras procesar bit,
2. compatibilidad entre multiples clientes consecutivos,
3. reset de estado al finalizar mensaje.

## 6. parse_utils.c

Responsabilidad:

- parsear PID de forma segura,
- escribir errores en stderr.

Puntos de estudio:

1. validacion de digitos,
2. control de overflow (`INT_MAX`),
3. ruta de error centralizada.

## 7. Makefile

Responsabilidad:

- compilar mandatory y bonus,
- compilar libft local,
- evitar relink innecesario.

Objetivos de lectura:

1. targets `all`, `bonus`, `clean`, `fclean`, `re`,
2. separacion de objetos mandatory/bonus,
3. enlazado con `libft.a`.

## Flujo completo en una linea

`client` serializa bits -> `server` reconstruye bytes -> imprime mensaje ->
bonus agrega ACK para sincronizacion robusta.

## Change Log

- 2026-04-05: guia inicial de implementacion de `minitalk`.
