# 01 - Conceptos Basicos

## Que hace el ejecutable client y que hace server

- server:
  - arranca primero,
  - imprime su PID,
  - espera senales,
  - reconstruye bytes recibidos,
  - imprime el mensaje.
- client:
  - recibe PID del server + string,
  - valida argumentos,
  - envia la string bit a bit al server.

## Que es un servidor

En este proyecto, un servidor es el proceso que se queda escuchando
peticiones de clientes y procesa mensajes entrantes.

## Que es un PID

PID (Process ID) es el identificador numerico unico de un proceso activo.
El cliente necesita el PID del servidor para enviarle senales.

## Que es una variable global

Una variable global vive durante toda la ejecucion del programa y se puede
usar desde funciones del mismo archivo.

En minitalk, su uso esta justificado por el contexto asincrono de senales:
- server.c usa estado global para reconstruir bytes entre llamadas al handler.
- client_bonus.c usa flag global de ACK para sincronizar envio bit a bit.

El subject permite una variable global por programa (cliente y servidor),
siempre que se justifique.

## Que es un handler

Un handler es una funcion que se ejecuta automaticamente cuando llega una
senal.

En minitalk:

- `server.c` usa `handle_signal` para recibir bits y reconstruir caracteres.
- `client_bonus.c` usa `handle_ack` para confirmar que el servidor recibio
  un bit antes de enviar el siguiente.

Idea clave:

1. Tu no llamas al handler desde `main`.
2. El sistema operativo lo llama cuando ocurre el evento (la senal).
3. Por eso el handler debe ser simple y rapido.

## Que es ACK

ACK significa "acknowledgment" (confirmacion de recepcion).

En minitalk bonus:

1. El cliente envia un bit.
2. El servidor responde una senal de confirmacion (ACK).
3. El cliente solo entonces envia el siguiente bit.

Beneficio principal:

- reduce perdida de senales porque el envio queda sincronizado paso a paso.

## Buenas practicas basicas para este proyecto

1. Validar argumentos antes de iniciar logica de envio.
2. Validar PID y rangos numericos.
3. Comprobar retorno de llamadas criticas (`sigaction`, `kill`).
4. Mantener handlers simples.
5. Separar parseo, envio y recepcion en archivos distintos.

## Change Log

- 2026-04-05: respuestas basicas iniciales.
- 2026-04-07: agregada seccion "Que es un handler" con ejemplos del proyecto.
- 2026-04-07: agregada seccion "Que es ACK" orientada a flujo bonus.
